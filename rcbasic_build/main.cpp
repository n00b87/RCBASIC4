#include <iostream>
#include <stack>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <string>
#include "tokenizer.h"
#include "parser.h"
#include "rc_builtin.h"
#include "rc_vm_asm.h"
#include "file_directory.h"
#include "env_resolve.h"
#include "identifier.h"

using namespace std;


struct rc_src
{
    string filename = "";
    uint64_t line_number = 1;
    uint64_t line_position = 0;
    bool eof_reached = false;
    uint64_t dbg_inc_index = 0;
};

stack<rc_src> rcbasic_program;
fstream rcbasic_file;

vector<string> inc_once;

bool rcbasic_build_debug = false;
uint64_t rcbasic_user_var_start = 0;

vector<string> inc_files;

void rcbasic_init()
{
    //init built-in types here
    init_embedded_types();

    //init built-in functions here

    block_state.push(BLOCK_STATE_MAIN);
    current_block_state = BLOCK_STATE_MAIN;

    current_scope = "main";
    vm_asm.push_back(".code");

    init_embedded_functions();

    init_embedded_variables();

    //cout << "numid_count = " << num_id_count << endl;
    //cout << "strid_count = " << str_id_count << endl << endl;

    block_state.push(BLOCK_STATE_MAIN);
    current_block_state = BLOCK_STATE_MAIN;
    isInFunctionScope = false;

    current_scope = "main";
    vm_asm.push_back(".code");
}

void rcbasic_dev_init()
{
    //create_type("empty");

    //init built-in functions here

    block_state.push(BLOCK_STATE_MAIN);
    current_block_state = BLOCK_STATE_MAIN;

    current_scope = "main";
    vm_asm.push_back(".code");

    cout << "numid_count = " << num_id_count << endl;
    cout << "strid_count = " << str_id_count << endl << endl;

    block_state.push(BLOCK_STATE_MAIN);
    current_block_state = BLOCK_STATE_MAIN;
    isInFunctionScope = false;

    current_scope = "main";
    vm_asm.push_back(".code");
}

bool rcbasic_loadProgram(string src_file)
{
    rc_src rc_program;
    rc_program.filename = src_file;
    rc_program.line_number = 1;
    rc_program.line_position;
    rc_program.dbg_inc_index = inc_files.size();
    rcbasic_file.open(src_file.c_str(), fstream::in);
    if(rcbasic_file.is_open())
    {
        rcbasic_program.push(rc_program);
        inc_files.push_back(src_file);
        return true;
    }
    return false;
}

bool rc_preprocessor()
{
    rc_src inc_file;
    if(tmp_token.size()>0)
    {
        if(tmp_token[0].compare("<include>")==0)
        {
            if(tmp_token.size() != 2)
            {
                rc_setError("Expected string literal or flag in INCLUDE");
                return false;
            }

            //cout << "tmp_token[1] == " << tmp_token[1] << endl;

            if(tmp_token[1].compare("<once>")==0)
            {
                tmp_token.clear();
                inc_once.push_back(rcbasic_program.top().filename);
                return true;
            }

            if(tmp_token[1].substr(0,8).compare("<string>")!=0)
            {
                rc_setError("Expected include file as string constant");
                return false;
            }

            tmp_token[1] = resolveEnvironmentVariables(tmp_token[1]);

            inc_file.filename = tmp_token[1].substr(8);
            inc_file.filename = rc_absFilePath(inc_file.filename);

            for(int i = 0; i < inc_once.size(); i++)
            {
                if(inc_once[i].compare(inc_file.filename)==0)
                {
                    tmp_token.clear();
                    //cout << "DEBUG INC_ONCE: " << inc_file.filename << " can only be included once" << endl;
                    return true;
                }
            }

            //cout << "\nDEBUG INCLUDE ABS_PATH:" << inc_file.filename << endl << endl;
            inc_file.line_number = 0;
            inc_file.line_position = 0;
            inc_file.dbg_inc_index = inc_files.size();
            rcbasic_file.close();
            rcbasic_file.open(inc_file.filename.c_str(), fstream::in);
            if(!rcbasic_file.is_open())
            {
                rc_setError("Could not open " + inc_file.filename);
                return false;
            }

            //increase current file line number before pushing next file on stack
            rcbasic_program.top().line_number++;

            rcbasic_program.push(inc_file);
            inc_files.push_back(inc_file.filename);
            tmp_token.clear();
            return true;
        }
    }
    return true;
}



bool rc_eval(string line)
{
    //adding an extra character to line to avoid a memory leak
    line += "  ";


    ERROR_MSG = "";
    clearRegs();
    clearTokens();
    byref_type_exception.clear();

    if(line.compare("#var")==0)
    {
        output_vars();
        return true;
    }

    //cout << "get tokens" << endl;
    if(!tokens(line))
    {
        //cout << "Error1: " << rc_getError() << endl;
        return false;
    }

    //current_Debug
    //cout << "-------BEFORE PP START TOKENS--------" << endl;
    //output_tokens();

    //cout << "get preprocessor" << endl;
    if(!rc_preprocessor())
    {
        return false;
    }

    //cout << "-------AFTER PP START TOKENS--------" << endl;
    //output_tokens(); cout << endl;

    //cout << "check rule" << endl;
    //cout << "token: " << token[0] << endl;

    int i = 0;

    int dim_scope = 0;
    bool is_dim_expr = false;
    string dim_token = "";

    for(i = 0; i < tmp_token.size(); i++)
    {
        if(tmp_token[i].compare("<dim>")==0 || tmp_token[i].compare("<redim>")==0)
        {
            dim_token = tmp_token[i];
            dim_scope = 0;
            is_dim_expr = true;
            continue;
        }

        if(tmp_token[i].compare("<par>")==0 || tmp_token[i].compare("<square>")==0)
            dim_scope++;

        if(tmp_token[i].compare("</par>")==0 || tmp_token[i].compare("</square>")==0)
            dim_scope--;

        if(is_dim_expr==true && dim_scope==0 && tmp_token[i].compare("<comma>")==0)
        {
            tmp_token[i] = "<:>";
            tmp_token.insert(tmp_token.begin()+ (i+1), dim_token);
        }

        if(tmp_token[i].compare("<:>")==0)
            is_dim_expr = false;
    }

    i = 0;

    while( i < tmp_token.size())
    {
        token.clear();

        for(; i < tmp_token.size(); i++)
        {
            //cout << "start tmp_token loop :: ";
            //cout << "i = " << i << "     tmp_token_size = " << tmp_token.size() << endl;
            if(tmp_token[i].compare("<:>")==0)
                break;
            //else if(!Array_Macros(i))
            //{
            //    cout << "ERROR:" << rc_getError() << endl;
            //    return false;
            //}
            //cout << "### tmp_token[" << i << "] = ";
            //cout << tmp_token[i] << endl;
            token.push_back(tmp_token[i]);
        }
        i++;

        //cout << "start rule" << endl;

        if(!check_rule())
        {
            //cout << "ERROR:" << rc_getError() << endl;
            return false;
        }
    }

    if(byref_type_exception.size() > 0)
    {
        for(int i = 0; i < byref_type_exception.size(); i++)
        {
            //cout << "type exception: [" << byref_type_exception[i].tk_reg << "]  exception_status = " << byref_type_exception[i].exception_used << endl;

            if(!byref_type_exception[i].exception_used)
            {
                rc_setError(byref_type_exception[i].error_log);
                return false;
            }
        }
    }

    return true;

    //if(!eval_expression())
    //    cout << "Error2: " << rc_getError() << endl;
    //cout << endl << endl << "----TOKENS-----" << endl;
    //output_tokens();

    //cout << endl << "VM CODE" << endl << endl;
    //debug_output_VMASM();

    //cout << "F_Error: " << rc_getError() << endl;
}

bool rc_eval_embedded(string line)
{
    //adding an extra character to line to avoid a memory leak
    line += "   ";


    ERROR_MSG = "";
    clearRegs();
    clearTokens();
    if(line.compare("#var")==0)
    {
        output_vars();
    }

    if(!tokens(line))
    {
        cout << "Error1: " << rc_getError() << endl;
        return false;
    }

    if(!rc_preprocessor())
    {
        return false;
    }

    if(tmp_token.size()==0)
        return true;
    //cout << "-------START TOKENS--------" << endl;
    //output_tokens();

    token.clear();
    for(int i = 0; i < tmp_token.size(); i++)
        token.push_back(tmp_token[i]);

    if(!check_rule_embedded())
    {
        cout << "---ERROR:" << rc_getError() << endl;
        output_tokens();
        cout << endl;
        return false;
    }

    return true;

    //if(!eval_expression())
    //    cout << "Error2: " << rc_getError() << endl;
    //cout << endl << endl << "----TOKENS-----" << endl;
    //output_tokens();

    //cout << endl << "VM CODE" << endl << endl;
    //debug_output_VMASM();

    //cout << "F_Error: " << rc_getError() << endl;
}

rc_src rc_last_line;

bool rc_getline(string &line)
{
    line = "";

    getline(rcbasic_file, line);

    if(!rcbasic_file.eof())
    {
        return true;
    }
    else if(!rcbasic_program.top().eof_reached)
    {
        //cout << "setting negative line in " << rcbasic_program.top().filename << " at line " << rcbasic_program.top().line_number << endl;
        rcbasic_program.top().eof_reached = true; // end of file
        return true;
    }
    else
    {
        rcbasic_file.close();

        while(rcbasic_program.size()>0)
        {
            //cout << "debug STACK: " << rcbasic_program.top().filename << " -- " << rcbasic_program.top().line_number << ":" << rcbasic_program.top().line_position << endl;
            if(rcbasic_program.top().eof_reached)
            {
                //cout << "popping " << rcbasic_program.top().filename << endl;
                rcbasic_program.pop();
                //cout << "new size = " << rcbasic_program.size() << endl;
            }
            else
            {
                //cout << "reopening " << rcbasic_program.top().filename << " at line " << rcbasic_program.top().line_number << ":" << rcbasic_program.top().line_position << endl;
                rcbasic_file.open(rcbasic_program.top().filename.c_str(), fstream::in);
                if(!rcbasic_file.is_open())
                {
                    cout << "Could not open " << rcbasic_program.top().filename << endl;
                    return false;
                }
                rcbasic_file.seekg(rcbasic_program.top().line_position);
                getline(rcbasic_file, line);
                return true;
            }
        }
        return false;
    }
}

bool rcbasic_compile()
{
    int current_file = 0;
    string line = "";
    fstream f;

    string rc_asm_file = "main.rc_asm";
    string rc_str_data = "main_str_data.sdata";

    if(is_file_exist(rc_asm_file.c_str()))
    {
        if(remove(rc_asm_file.c_str())!=0)
        {
            cout << "Could not clear asm file" << endl;
            return false;
        }
    }

    if(is_file_exist(rc_str_data.c_str()))
    {
        if(remove(rc_str_data.c_str())!=0)
        {
            cout << "Could not clear sdata file" << endl;
            return false;
        }
    }

    while( rc_getline(line) )
    {
        if(rcbasic_build_debug)
        {
            vm_asm.push_back("dbg uint=0 uint=" + rc_uint64ToString(rcbasic_program.top().dbg_inc_index) + " uint=" + rc_uint64ToString(rcbasic_program.top().line_number));
        }
        //cout << "line " << rcbasic_program.top().line_number << ": " << rcbasic_file.tellg() << " -> " << line << endl;
        if(!rcbasic_program.top().eof_reached)
            rcbasic_program.top().line_position = rcbasic_file.tellg();
        //vm_asm.push_back("mov n0 " + rc_intToString(rcbasic_program.top().line_number));
        //vm_asm.push_back("print n0");
        if(!rc_eval(line))
        {
            cout << "Error on Line " << rcbasic_program.top().line_number << " in " << rcbasic_program.top().filename << ": " << rc_getError() << endl;
            //output_tokens();
            cout << endl;
            return false;
        }
        rcbasic_program.top().line_number++;
//        if(rcbasic_program.top().line_number % 500 == 0)
//        {
//            f.open(rc_asm_file.c_str(), fstream::app);
//            for(int i = 0; i < vm_asm.vm_code.size(); i++)
//                f << vm_asm.vm_code[i] << endl;
//            f.close();
//            vm_asm.clear();
//
//            f.open(rc_str_data.c_str(), fstream::app | fstream::binary);
//            for(int i = 0; i < data_segment.size(); i++)
//                f.put(data_segment[i]);
//            f.close();
//            data_segment.clear();
//        }
    }

    if(rcbasic_build_debug)
    {
        vm_asm.push_back("dbg uint=0 uint=0 uint=0"); //I just need to call this at the end so it will output the last line messages
    }
    vm_asm.push_back("end");

    f.open(rc_asm_file.c_str(), fstream::app);
    for(int i = 0; i < vm_asm.vm_code.size(); i++)
        f << vm_asm.vm_code[i] << endl;
    f.close();
    vm_asm.clear();

    f.open(rc_str_data.c_str(), fstream::app | fstream::binary);
    for(int i = 0; i < data_segment.size(); i++)
        f.put(data_segment[i]);
    f.close();
    data_segment.clear();

    return true;

    //f.open("tst_var_output.txt", fstream::out | fstream::trunc);

    //for(int i = 0; i < id.size(); i++)
    //    f << id[i].name << " -> " << id[i].vec_pos << endl;
    //f.close();

    //cout << endl << "VM Code" << endl << "---------------------" << endl;
    //debug_output_VMASM();
}

struct rc_dev_case_functions
{
	std::string code;
	bool case_exception = false;
};

void rcbasic_export_dev()
{
	std::vector<rc_dev_case_functions> rt_case_functions;
	std::string input_line = "";

	std::vector<std::string> builtin_fn;
	std::vector<std::string> builtin_types;
	std::vector<std::string> builtin_var;


	std::string builtin_temp = "";
	fstream rt_builtin_temp_file("intern_inc/rc_builtin_template.h", fstream::in);
	while(!rt_builtin_temp_file.eof())
	{
		getline(rt_builtin_temp_file, input_line);
		builtin_temp += input_line + "\n";
	}
	rt_builtin_temp_file.close();

	fstream rt_case_file("intern_inc/switch_cases.h", fstream::in);

	if(!rt_case_file.is_open())
		return;

	while(!rt_case_file.eof())
	{
		getline(rt_case_file, input_line);
		if(input_line.substr(0,1).compare("#")==0)
		{
			std::string case_exception_file = input_line.substr(1);
			fstream cf(case_exception_file, fstream::in);
			input_line = "";
			std::string cf_contents = "";
			while(!cf.eof())
			{
				getline(cf, input_line);
				if(input_line.compare("") != 0)
					cf_contents += "\t" + input_line + "\n";
			}
			cf.close();

			rc_dev_case_functions obj;
			obj.case_exception = true;
			obj.code = cf_contents;
			rt_case_functions.push_back(obj);
		}
		else if(input_line.compare("") != 0)
		{
			rc_dev_case_functions obj;
			obj.case_exception = false;
			obj.code = input_line;
			rt_case_functions.push_back(obj);
		}
	}

	rt_case_file.close();

	//std::cout << "id_size ( " << rt_case_functions.size() << " ~ " << id[i].vmFunctionIndex << " ) " << std::endl << std::endl;
	//return;


    string fn_line = "";
    fstream f("rcbasic_dev.txt", fstream::out | fstream::trunc);
    fstream f2("rcbasic_dev2.txt", fstream::out | fstream::trunc);
    fstream f3("rcbasic_dev3.txt", fstream::out | fstream::trunc);
    fstream f4("rcbasic_dev4.txt", fstream::out | fstream::trunc);

    if(!f.is_open())
        return;
    string output_line = "";
    for(int i = 0; i < id.size(); i++)
    {
        fn_line = "#define FN_" + id[i].name + " " + rc_intToString(id[i].vmFunctionIndex);

        output_line = "embed_function(\"" + id[i].name +"\", ";
        switch(id[i].type)
        {
            case ID_TYPE_FN_NUM:
                output_line += "ID_TYPE_FN_NUM);";
                f2 << fn_line << endl;
                f3 << "case FN_" << id[i].name << ": //Number Function" << endl;
                if(rt_case_functions[id[i].vmFunctionIndex].case_exception)
					f3 << rt_case_functions[id[i].vmFunctionIndex].code << endl;
				else
					f3 << "\t" << " rc_push_num(" << rt_case_functions[id[i].vmFunctionIndex].code << ");" << endl;
                f3 << "\tbreak;" << endl;
                break;
            case ID_TYPE_FN_STR:
                output_line += "ID_TYPE_FN_STR);";
                f2 << fn_line << endl;
                f3 << "case FN_" << id[i].name << ": //String Function" << endl;
                if(rt_case_functions[id[i].vmFunctionIndex].case_exception)
					f3 << rt_case_functions[id[i].vmFunctionIndex].code << endl;
				else
					f3 << "\t" << " rc_push_str(" << rt_case_functions[id[i].vmFunctionIndex].code << ");" << endl;
                f3 << "\tbreak;" << endl;
                break;
            case ID_TYPE_FN_USER:
                output_line += "ID_TYPE_FN_USER);";
                f2 << fn_line << endl;
                f3 << "case FN_" << id[i].name << ": //UDT Function" << endl;
                if(rt_case_functions[id[i].vmFunctionIndex].case_exception)
					f3 << rt_case_functions[id[i].vmFunctionIndex].code << endl;
				else
					f3 << "\t" << " rc_push_usr(" << rt_case_functions[id[i].vmFunctionIndex].code << ");" << endl;
                f3 << "\tbreak;" << endl;
                break;
            case ID_TYPE_SUB:
                output_line += "ID_TYPE_SUB);";
                f2 << fn_line << endl;
                f3 << "case FN_" << id[i].name << ": //Sub Procedure" << endl;
                if(rt_case_functions[id[i].vmFunctionIndex].case_exception)
					f3 << rt_case_functions[id[i].vmFunctionIndex].code << endl;
                else
					f3 << "\t" << rt_case_functions[id[i].vmFunctionIndex].code << ";" << endl;
                f3 << "\tbreak;" << endl;
                break;
            default:
                continue;
        }
        f << output_line << endl;
        builtin_fn.push_back(output_line);

        output_line = "";
        string fn_arg_utype = "";

        for(int n = 0; n < id[i].num_args; n++)
        {
            fn_line = "#define " + StringToUpper(id[i].name + "_" + id[i].fn_arg[n]) + " ";

            output_line = "add_embedded_arg(\"" + id[i].fn_arg[n] + "\", ";
            switch(id[i].fn_arg_type[n])
            {
                case ID_TYPE_NUM:
                    output_line += "ID_TYPE_NUM);";
                    //fn_line += "num_var[" + rc_intToString(id[i].fn_arg_vec[n]) + "].nid_value[0].value[0]";
                    fn_line += "num_var[" + rc_intToString(id[i].fn_arg_vec[n]) + "].nref[0].value[ num_var[" + rc_intToString(id[i].fn_arg_vec[n]) + "].byref_offset ]";
                    break;
                case ID_TYPE_BYREF_NUM:
                    output_line += "ID_TYPE_BYREF_NUM);";
                    fn_line += "num_var[" + rc_intToString(id[i].fn_arg_vec[n]) + "].nref[0].value[ num_var[" + rc_intToString(id[i].fn_arg_vec[n]) + "].byref_offset ]";
                    break;
                case ID_TYPE_STR:
                    output_line += "ID_TYPE_STR);";
                    fn_line += "str_var[" + rc_intToString(id[i].fn_arg_vec[n]) + "].sref[0].value[ str_var[" + rc_intToString(id[i].fn_arg_vec[n]) + "].byref_offset ]";
                    break;
                case ID_TYPE_BYREF_STR:
                    output_line += "ID_TYPE_BYREF_STR);";
                    fn_line += "str_var[" + rc_intToString(id[i].fn_arg_vec[n]) + "].sref[0].value[ str_var[" + rc_intToString(id[i].fn_arg_vec[n]) + "].byref_offset ]";
                    break;
                case ID_TYPE_USER:
                    //fn_arg_utype = "";
                    //if(id[i].fn_arg_utype[n] >= 0)
                    //    fn_arg_utype = utype[id[i].fn_arg_utype[n]].name;
                    output_line += "ID_TYPE_USER, " + rc_intToString(id[i].fn_arg_utype[n]) + ");";
                    fn_line += "usr_var[" + rc_intToString(id[i].fn_arg_vec[n]) + "].var_ref->uid_value[0]";
                    break;
                case ID_TYPE_BYREF_USER:
                    //fn_arg_utype = "";
                    //if(id[i].fn_arg_utype[n] >= 0)
                    //    fn_arg_utype = utype[id[i].fn_arg_utype[n]].name;
                    output_line += "ID_TYPE_BYREF_USER, " + rc_intToString(id[i].fn_arg_utype[n]) + ");";
                    fn_line += "usr_var[" + rc_intToString(id[i].fn_arg_vec[n]) + "].var_ref";
                    break;
            }
            f2 << fn_line << endl;
            f << output_line << endl; //I am generating the dev file for debug purposes only
            builtin_fn.push_back(output_line);
        }

    }

    for(int i = 0; i < utype.size(); i++)
    {
        output_line = "create_type(\"" + utype[i].name + "\");";

        f4 << output_line << endl;
        builtin_types.push_back(output_line);

        for(int n = 0; n < utype[i].num_members; n++)
        {
            output_line = "vm_asm.push_back(\"mov n0 " + rc_intToString(utype[i].member_dim[n].dim_size[0]) + "\");";
            f4 << output_line << endl;
            builtin_types.push_back(output_line);

            output_line = "vm_asm.push_back(\"mov n1 " + rc_intToString(utype[i].member_dim[n].dim_size[1]) + "\");";
            f4 << output_line << endl;
            builtin_types.push_back(output_line);

            output_line = "vm_asm.push_back(\"mov n2 " + rc_intToString(utype[i].member_dim[n].dim_size[2]) + "\");";
            f4 << output_line << endl;
            builtin_types.push_back(output_line);

            int ut_index = utype[i].member_utype_index[n];
            string member_utype_name = "";

            if(ut_index >= 0)
                member_utype_name = utype[ut_index].name;
            else if(utype[i].member_type[n] == ID_TYPE_USER)
            {
                cout << "ERROR CREATING TYPE" << endl;
                f.close();
                f2.close();
                f3.close();
                f4.close();
                return;
            }


            output_line = "add_type_member(\"" + utype[i].member_name[n] + "\", " + rc_intToString(utype[i].member_type[n]) + ", \"" + member_utype_name + "\", " +
                                            rc_intToString(utype[i].member_dim_count[n]) + ", \"n0\", \"n1\", \"n2\");";
            f4 << output_line << endl;
            builtin_types.push_back(output_line);
        }
    }

    f.close();
    f2.close();
    f3.close();
    f4.close();

    //Generate rc_builtin.h
    fstream rt_builtin_gen_file("rc_builtin.h", fstream::out | fstream::trunc);
    rt_builtin_gen_file << "#ifndef RC_BUILTIN_H_INCLUDED" << endl;
	rt_builtin_gen_file << "#define RC_BUILTIN_H_INCLUDED" << endl;
	rt_builtin_gen_file << "#include \"identifier.h\"" << endl;
	rt_builtin_gen_file << endl;

	rt_builtin_gen_file << "void init_embedded_functions()" << endl;
	rt_builtin_gen_file << "{" << endl;
	for(int i = 0; i < builtin_fn.size(); i++)
		rt_builtin_gen_file << "\t" << builtin_fn[i] << endl;
	rt_builtin_gen_file << "}" << endl;
	rt_builtin_gen_file << endl;

	rt_builtin_gen_file << "void init_embedded_types()" << endl;
	rt_builtin_gen_file << "{" << endl;
	for(int i = 0; i < builtin_types.size(); i++)
		rt_builtin_gen_file << "\t" << builtin_types[i] << endl;
	rt_builtin_gen_file << "}" << endl;
	rt_builtin_gen_file << endl;


	rt_builtin_gen_file << "void init_embedded_variables()" << endl;
	rt_builtin_gen_file << "{" << endl;
	for(int i = 0; i < builtin_var.size(); i++)
		rt_builtin_gen_file << "\t" << builtin_var[i] << endl;
	rt_builtin_gen_file << "}" << endl;
	rt_builtin_gen_file << endl;

    rt_builtin_gen_file << "#endif // RC_BUILTIN_H_INCLUDED" << endl;
    rt_builtin_gen_file.close();


    //Generate rc_defines.h
    fstream rt_defines_gen_file("../rcbasic_runtime/rc_defines.h", fstream::out | fstream::trunc);
    fstream dev_defines_file("rcbasic_dev2.txt", fstream::in);
    input_line = "";

    rt_defines_gen_file << "#ifndef RC_DEFINES_H_INCLUDED" << endl;
	rt_defines_gen_file << "#define RC_DEFINES_H_INCLUDED" << endl;
	rt_defines_gen_file << endl;

    while(!dev_defines_file.eof())
	{
		getline(dev_defines_file, input_line);
		rt_defines_gen_file << input_line << endl;
	}

	rt_defines_gen_file << endl;
	rt_defines_gen_file << "#endif // RC_DEFINES_H_INCLUDED" << endl;

	dev_defines_file.close();
	rt_defines_gen_file.close();


	//Generate RCBasic to C++ function map cases
	fstream dev_case_file("rcbasic_dev3.txt", fstream::in);
	fstream rt_switch_case_file("../rcbasic_runtime/rc_func130_cases.h", fstream::out | fstream::trunc);

	input_line = "";

	while(!dev_case_file.eof())
	{
		getline(dev_case_file, input_line);
		rt_switch_case_file << input_line << endl;
	}

	dev_case_file.close();
	rt_switch_case_file.close();



    cout << "rcbasic_dev file was created" << endl;
}

bool rcbasic_embedded()
{
    int current_file = 0;
    string line = "";

    while( rc_getline(line) )
    {
        cout << "line " << rcbasic_program.top().line_number << ": " << rcbasic_file.tellg() << " -> " << line << endl;
        //rcbasic_program.top().line_position = rcbasic_file.tellg();
        if(!rcbasic_program.top().eof_reached)
            rcbasic_program.top().line_position = rcbasic_file.tellg();

        if(!rc_eval_embedded(line))
        {
            cout << "Error on Line " << rcbasic_program.top().line_number << ": " << rc_getError() << endl;
            return false;
        }
        rcbasic_program.top().line_number++;
    }

    cout << endl << "VM Code" << endl << "---------------------" << endl;
    debug_output_VMASM();
    return true;
}

void rcbasic_clean()
{
    if(rcbasic_file.is_open())
        rcbasic_file.close();

}

//a file with functions to add to rcbasic
void rcbasic_dev(string dev_input_file)
{
    rcbasic_dev_init();

    if(rcbasic_loadProgram(dev_input_file))
    {
        if(!rcbasic_embedded())
		{
			std::cout << "ERROR: Failed to compose embedded args" << std::endl;
			return;
		}
        rcbasic_export_dev();
        rcbasic_clean();
    }
}

void rcbasic_output_debug_info()
{
    fstream f("rcbasic.dbgs", fstream::out | fstream::trunc);

    for(int i = rcbasic_user_var_start; i < id.size(); i++)
    {
        switch(id[i].type)
        {
            case ID_TYPE_NUM:
                f << "N " << id[i].scope << " " << id[i].name << " " << id[i].vec_pos << "\n";
                break;
            case ID_TYPE_ARR_NUM:
                f << "AN " << id[i].scope << " " << id[i].name << " " << id[i].vec_pos << "\n";
                break;
            case ID_TYPE_BYREF_NUM:
                f << "BN " << id[i].scope << " " << id[i].name << " " << id[i].vec_pos << "\n";
                break;
            case ID_TYPE_STR:
                f << "S " << id[i].scope << " " << id[i].name << " " << id[i].vec_pos << "\n";
                break;
            case ID_TYPE_ARR_STR:
                f << "AS " << id[i].scope << " " << id[i].name << " " << id[i].vec_pos << "\n";
                break;
            case ID_TYPE_BYREF_STR:
                f << "BS " << id[i].scope << " " << id[i].name << " " << id[i].vec_pos << "\n";
                break;
            case ID_TYPE_USER:
                f << "U " << id[i].scope << " " << id[i].name << " " << id[i].vec_pos << "\n";
                break;
            case ID_TYPE_BYREF_USER:
                f << "BU " << id[i].scope << " " << id[i].name << " " << id[i].vec_pos << "\n";
                break;
            case ID_TYPE_USER_NUM:
                f << "UN " << id[i].scope << " " << id[i].name << " " << id[i].vec_pos << "\n";
                break;
            case ID_TYPE_USER_NUM_ARRAY:
                f << "UNA " << id[i].scope << " " << id[i].name << " " << id[i].vec_pos << "\n";
                break;
            case ID_TYPE_USER_STR:
                f << "US " << id[i].scope << " " << id[i].name << " " << id[i].vec_pos << "\n";
                break;
            case ID_TYPE_USER_STR_ARRAY:
                f << "USA " << id[i].scope << " " << id[i].name << " " << id[i].vec_pos << "\n";
                break;
        }
    }

    f.close();

    f.open("rcbasic.dbgi", fstream::out | fstream::trunc);

    for(int i = 0; i < inc_files.size(); i++)
    {
        f << inc_files[i] << "\n";
    }

    f.close();
}

int main(int argc, char * argv[])
{
	string line = "";

    //rcbasic_dev("embedded_functions.bas"); rcbasic_output_debug_info(); return 0;

    string rc_filename = "";// = "tst.bas";

    bool clean_after_build = true;

    //DEBUG START
    //rc_filename = "/home/n00b/projects/bu/constraint_demo/main.bas";
	//rc_filename = "/home/n00b/projects/rcbasic_alpha3/test_project/main.bas";
    //DEBUG END

    //enable_presets = true;

    if(argc > 1)
        rc_filename = argv[1];

    string cmd_arg = "";
    for(int i = 1; i < argc; i++)
    {
        cmd_arg = (string)argv[i];

        if(cmd_arg.substr(0,1).compare("-") != 0)
            rc_filename = cmd_arg;

        if(cmd_arg.compare("--debug")==0)
        {
            //cout << "DEBUG MODE" << endl;
            rcbasic_build_debug = true;
        }
        else if(cmd_arg.compare("--no-presets")==0)
        {
            //cout << "DISABLE PRESETS" << endl;
            enable_presets = false;
        }
        else if(cmd_arg.compare("--no-clean")==0)
        {
            clean_after_build = false;
        }
    }

    if(rc_filename.compare("--version")==0)
    {
        cout << "RCBASIC Compiler v4.0" << endl;
        return 0;
    }

    //rc_filename = "tst.bas";

    cout << "Source: " << rc_filename << endl;

    string cbc_file = rcbasic_build_debug ? "debug.cbc" : rc_filename.substr(0, rc_filename.find_last_of(".")) + ".cbc";
    if(is_file_exist(cbc_file.c_str()))
        remove(cbc_file.c_str());

    if(is_file_exist("rcbasic.dbgs"))
        remove("rcbasic.dbgs");

    if(is_file_exist("rcbasic.dbgi"))
        remove("rcbasic.dbgi");

    if(rc_filename.compare("")==0)
        return 0;

    rcbasic_init();

    rcbasic_user_var_start = id.size();

    if(rc_filename.find_first_of(".") == string::npos)
    {
        cout << "file must have extension" << endl;
        return 0;
    }

    //if(rcbasic_loadProgram("tst.bas"))
    if(rcbasic_loadProgram(rc_filename))
    {
        if(!rcbasic_compile())
        {
            cout << "Compile Failed" << endl;
            rcbasic_clean();
            return 0;
        }
        else if(current_block_state != BLOCK_STATE_MAIN)
        {
            switch(current_block_state)
            {
            case BLOCK_STATE_DO:
                cout << "Compile Error: Failed to close DO loop" << endl;
                break;
            case BLOCK_STATE_WHILE:
                cout << "Compile Error: Failed to close WHILE loop" << endl;
                break;
            case BLOCK_STATE_FOR:
                cout << "Compile Error: Failed to close FOR loop" << endl;
                break;
            case BLOCK_STATE_FUNCTION:
                cout << "Compile Error: Failed to close FUNCTION" << endl;
                break;
            case BLOCK_STATE_SUB:
                cout << "Compile Error: Failed to close SUB" << endl;
                break;
            case BLOCK_STATE_SELECT:
                cout << "Compile Error: Failed to close SELECT" << endl;
                break;
            case BLOCK_STATE_IF:
                cout << "Compile Error: Failed to close IF" << endl;
                break;
            case BLOCK_STATE_TYPE:
                cout << "Compile Error: Failed to close TYPE" << endl;
                break;
            }
            cout << "Compile Failed" << endl;
            return 0;
        }
        else
            rcbasic_clean();

        //Debug
        //return 0;

        //for(int i = 0; i < vm_asm.label.size(); i++)
        //    cout << vm_asm.label[i].label_name << " = " << vm_asm.label[i].label_address << endl;

        //cout << "for_loop = " << max_for_count << endl;
        //cout << "max_n = " << max_n_reg << endl;
        //cout << "max_s = " << max_s_reg << endl;
        //cout << "n_stack_size = " << vm_asm.max_n_stack_count << endl;
        //cout << "s_stack_size = " << vm_asm.max_s_stack_count << endl;

        //n_count
        //s_count
        //n_stack_count
        //s_stack_count
        //loop_stack_count
        //numID_count
        //strID_count
        //label_count
        //labels

        if(rcbasic_build_debug)
            rcbasic_output_debug_info();

        rcbasic_output_debug_info();

        fstream f("main.rc_data", fstream::trunc | fstream::out);
        f << max_n_reg << endl;
        f << max_s_reg << endl;
        f << max_u_reg << endl;
        f << vm_asm.max_n_stack_count << endl;
        f << vm_asm.max_s_stack_count << endl;
        f << vm_asm.max_u_stack_count << endl;
        f << max_for_count << endl;
        f << num_id_count << endl;
        f << str_id_count << endl;
        f << usr_id_count << endl;
        f << vm_asm.label.size() << endl;
        for(int i = 0; i < vm_asm.label.size(); i++)
            f << vm_asm.label[i].label_name << " " << vm_asm.label[i].label_address << " " << vm_asm.label[i].label_segment << endl;
        f.close();

        rc_cbc_assembler::rc_assemble(cbc_file, clean_after_build);
    }
    else
    {
        cout << "Could not load program" << endl;
        return 0;
    }

    cout << endl << "Compiled Successfully" << endl << endl << endl; //skip 3 lines so that start of program is not right below this line

    return 0;

    while(getline(cin, line))
    {
        rc_eval(line);
    }
    return 0;
}
