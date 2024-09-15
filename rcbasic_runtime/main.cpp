//#define RCBASIC_DEBUG 1

#include "rc_os_defines.h"

#ifdef RC_WEB
#include <emscripten.h>
#endif

#ifdef RC_IOS
#define RC_GETCWD
#include <sys/param.h>
#endif

#ifdef RC_MAC
#define RC_GETCWD
#include <sys/param.h>
#endif

#ifdef RC_ANDROID
#define RC_GETCWD
#endif

#ifdef RC_WINDOWS
#include<windows.h>
#define _UNICODE
#endif // RC_WINDOWS


#ifdef RC_ANDROID
    #include <jni.h>
    #include <sys/param.h>
    #include <algorithm>
    #define LOGI(...) ((void)__android_log_print(ANDROID_LOG_ERROR, "native-activity", __VA_ARGS__))
#endif // RC_ANDROID

#include <iostream>
#include <inttypes.h>
#include <fstream>
#ifdef RC_ANDROID
	#include "SDL.h"
#else
	#include <SDL2/SDL.h>
#endif
#include <math.h>
#include <vector>
#include <stack>
#include <limits>
#include <iomanip>
#include "rc_defines.h"
#include "rc_stdlib.h"
#include "rc_gfx.h"
#include "rc_matrix.h"
#include "rc_geometry.h"
#include <irrtheora.h>


#define LESS_FLAG 0
#define LESS_EQUAL_FLAG 1
#define GREATER_FLAG 2
#define GREATER_EQUAL_FLAG 3
#define EQUAL_FLAG 4
#define NOT_EQUAL_FLAG 5

#define CODE_SEGMENT 0
#define DATA_SEGMENT 1

#define RC_UDT_TYPE_NUM 0
#define RC_UDT_TYPE_STR 1
#define RC_UDT_TYPE_USR 2


bool CMP_FLAG_EQUAL = false;
bool CMP_FLAG_LESS = false;
bool CMP_FLAG_LESS_EQUAL = false;
bool CMP_FLAG_GREATER = false;
bool CMP_FLAG_GREATER_EQUAL = false;
bool CMP_FLAG_NOT_EQUAL = false;

std::string rcbasic_runtime_path = "";

struct n_value
{
    vector<double> value;
    void * ref_parent; // This will be set by the obj_get instructions (ie. obj_get and obj_usr_get)
};

struct s_value
{
    vector<std::string> value;
    void * ref_parent; // This will be set by the obj_get instructions (ie. obj_get and obj_usr_get)
};

struct rc_vm_n
{
    double value;
    n_value * r; //reference
    uint64_t r_index;

    #ifdef RCBASIC_DEBUG
    uint64_t dbg_var_index;
    #endif // RCBASIC_DEBUG
};

struct rc_vm_s
{
    std::string value;
    s_value * r;
    uint64_t r_index;

    #ifdef RCBASIC_DEBUG
    uint64_t dbg_var_index;
    #endif // RCBASIC_DEBUG
};

struct rc_numId
{
    n_value nid_value;
    int dimensions;
    uint64_t dim[3];
    uint64_t byref_offset;

    n_value * nref;

    #ifdef RCBASIC_DEBUG
    bool is_debug_var;
    uint64_t dbg_var_index;
    #endif // RCBASIC_DEBUG
};

struct rc_strId
{
    s_value sid_value;
    int dimensions;
    uint64_t dim[3];
    uint64_t byref_offset;

    s_value * sref;

    #ifdef RCBASIC_DEBUG
    bool is_debug_var;
    uint64_t dbg_var_index;
    #endif // RCBASIC_DEBUG
};

struct rc_udtFieldSize
{
    uint64_t dim[3];
};

struct rc_udtDefinition
{
    int num_fields;
    vector<int> field_type; // 0 - num, 1 - str, 2 - UDT
    vector<int> field_type_index; //if field type is UDT
    vector<int> field_dimensions;
    vector<rc_udtFieldSize> field_size;
};

vector<rc_udtDefinition> rc_types;

struct rc_usrId
{
    vector<rc_numId> num_var;
    vector<rc_strId> str_var;
    vector<rc_usrId> uid_value;
    int dimensions;
    uint64_t dim[3];
    uint64_t byref_offset;
    int udt_index; //index of the type definition in rc_types

    rc_usrId * var_ref;
    uint64_t var_ref_index;

    rc_usrId* byref_ptr;

    bool preset_init = false;

    #ifdef RCBASIC_DEBUG
    bool is_debug_var;
    uint64_t dbg_var_index;
    #endif // RCBASIC_DEBUG
};

struct rc_loop
{
    rc_numId * counter;
    double f_end;
    double f_step;
    bool isNegative;
    uint64_t counter_offset;
    #ifdef RCBASIC_DEBUG
    uint64_t counter_dim[3];
    #endif // RCBASIC_DEBUG
};

uint64_t for_offset_index[3];
int for_offset_dimensions = 0;

union rc_double
{
    double f;
    unsigned char data[sizeof(double)];
};

union rc_int
{
    uint64_t i;
    unsigned char data[sizeof(uint64_t)];
};

struct addr_entry
{
    uint64_t ptr_id;
    void * ptr_addr;
    int type;
};

stack<addr_entry> byref_addr_table;
stack<uint64_t> byref_var_byref_offset;

uint64_t n_count = 0;
uint64_t s_count = 0;
uint64_t u_count = 0;
uint64_t n_stack_size = 0;
uint64_t s_stack_size = 0;
uint64_t u_stack_size = 0;
uint64_t loop_stack_size = 0;
uint64_t numID_count = 0;
uint64_t strID_count = 0;
uint64_t usrID_count = 0;
uint64_t code_segment_size = 0;
uint64_t data_segment_size = 0;

struct n_obj_struct
{
    n_value * obj_val;
    uint64_t index;

    #ifdef RCBASIC_DEBUG
    uint64_t nid;
    #endif // RCBASIC_DEBUG
};

struct s_obj_struct
{
    s_value * obj_val;
    uint64_t index;

    #ifdef RCBASIC_DEBUG
    uint64_t sid;
    #endif // RCBASIC_DEBUG
};

struct u_obj_struct
{
    rc_usrId * obj_ref;

    rc_numId * num_ref;
    rc_strId * str_ref;

    uint64_t index;
};

n_obj_struct num_object;
s_obj_struct str_object;
u_obj_struct usr_object;

rc_vm_n * vm_n;
rc_vm_s * vm_s;
rc_usrId * vm_u;

stack<rc_vm_n>  n_stack;
stack<rc_vm_s> s_stack;
stack<rc_usrId> u_stack;
stack<rc_loop> loop_stack;

int current_n_stack_count = 0;
int current_s_stack_count = 0;
int current_u_stack_count = 0;
int current_loop_stack_count = 0;

rc_numId * num_var;
rc_strId * str_var;
rc_usrId * usr_var;

unsigned char ** segment;

int current_segment = CODE_SEGMENT;
uint64_t current_address = 0;

stack<uint64_t> gosub_return_addr;

rc_int readint_val;
rc_double readdouble_val;

vector<uint64_t> arr_ref_id(2);

bool redim_toplevel_flag = false;

int rcbasic_exit_code = 0;

#ifdef RCBASIC_DEBUG
#define RCBASIC_DEBUG_VAR_NUM 0
#define RCBASIC_DEBUG_VAR_ARR_NUM 1
#define RCBASIC_DEBUG_VAR_BYREF_NUM 2
#define RCBASIC_DEBUG_VAR_STR 3
#define RCBASIC_DEBUG_VAR_ARR_STR 4
#define RCBASIC_DEBUG_VAR_BYREF_STR 5

#define RCBASIC_DEBUG_ACCESS_GET 0
#define RCBASIC_DEBUG_ACCESS_SET 1

struct rcbasic_debug_access_status
{
    int type;
    int dimensions;
    int dim[3];
    double num_val;
    std::string str_val;
    int reg;
    bool is_error = false;
};

struct rcbasic_debug_vars
{
    int type;
    std::string scope;
    std::string name;
    int index;
    vector<rcbasic_debug_access_status> usage_data;
};

vector<rcbasic_debug_vars> dbg_vars;
vector<std::string> dbg_files;

uint64_t current_src_line = 1;
uint64_t current_src_file = 0;

#define DBG_DIV_BY_ZERO "Divide By Zero"
#define DBG_NEGATIVE_INDEX "Negative Array Index"
#define DBG_INDEX_EXCEEDS_SIZE "Array Index is Greater than Array Size"
#define DBG_DIM_LEQ_ZERO "Array Size must be greater than Zero"
#define DBG_REDIM_LEQ_ZERO "Array Size must be greater than Zero"

bool dbg_error_found = false;
std::string dbg_error_message = "";


void loadDebugData(std::string sym_file, std::string inc_file)
{
    fstream f(sym_file, fstream::in);

    std::string f_line;

    std::string type_str = "";
    rcbasic_debug_vars tmp;

    while(!f.eof())
    {
        getline(f, f_line);

        type_str = f_line.substr(0, f_line.find_first_of(" "));

        if(type_str.compare("N")==0)
        {
            tmp.type = RCBASIC_DEBUG_VAR_NUM;
        }
        else if(type_str.compare("AN")==0)
        {
            tmp.type = RCBASIC_DEBUG_VAR_ARR_NUM;
        }
        else if(type_str.compare("BN")==0)
        {
            tmp.type = RCBASIC_DEBUG_VAR_BYREF_NUM;
        }
        else if(type_str.compare("S")==0)
        {
            tmp.type = RCBASIC_DEBUG_VAR_STR;
        }
        else if(type_str.compare("AS")==0)
        {
            tmp.type = RCBASIC_DEBUG_VAR_ARR_STR;
        }
        else if(type_str.compare("BS")==0)
        {
            tmp.type = RCBASIC_DEBUG_VAR_BYREF_STR;
        }

        f_line = f_line.substr(f_line.find_first_of(" ")+1);
        tmp.scope = f_line.substr(0, f_line.find_first_of(" "));

        f_line = f_line.substr(f_line.find_first_of(" ")+1);
        tmp.name = f_line.substr(0, f_line.find_first_of(" "));

        f_line = f_line.substr(f_line.find_first_of(" ")+1);
        tmp.index = atoi(f_line.c_str());

        switch(tmp.type)
        {
            case RCBASIC_DEBUG_VAR_NUM:
            case RCBASIC_DEBUG_VAR_ARR_NUM:
            case RCBASIC_DEBUG_VAR_BYREF_NUM:
                num_var[tmp.index].dbg_var_index = dbg_vars.size();
                num_var[tmp.index].is_debug_var = true;
                break;
            case RCBASIC_DEBUG_VAR_STR:
            case RCBASIC_DEBUG_VAR_ARR_STR:
            case RCBASIC_DEBUG_VAR_BYREF_STR:
                str_var[tmp.index].dbg_var_index = dbg_vars.size();
                str_var[tmp.index].is_debug_var = true;
                break;
        }

        dbg_vars.push_back(tmp);
    }

    f.close();

    f.open(inc_file, fstream::in);

    while(!f.eof())
    {
        getline(f, f_line);
        if(f_line.find_first_not_of(" ")!=std::string::npos)
            dbg_files.push_back(f_line);
    }

    f.close();
}

std::string dbg_format_string(std::string dbg_str_val)
{
    std::string rtn = dbg_str_val;
    rtn = rc_intern_replace(rtn, "\n", "\\n");
    rtn = rc_intern_replace(rtn, "\r", "\\r");
    rtn = rc_intern_replace(rtn, "\t", "\\t");
    return rtn;
}

void output_debug_message()
{
    //cout << "output debug messages" << endl;

    if(rc_intern_fileExist("rcbasic_dbg.sp") && (!dbg_error_found))
    {
        //if(rc_intern_fileExist("rcbasic.dbgm"))
        //    rc_intern_fileDelete("rcbasic.dbgm");

        /*if(rc_intern_fileExist("rcbasic_dbg.rt"))
        {
            while(rc_intern_fileExist("rcbasic_dbg.rt"))
            {
                rc_intern_fileDelete("rcbasic_dbg.rt"); //keep trying to delete file
            }

            fstream f("rcbasic_dbg.cl", fstream::out); //generate this file to let the client know it has ownership
            f.close();
        }*/
        for(int i = 0; i < dbg_vars.size(); i++)
        {
            dbg_vars[i].usage_data.clear();
        }
        return;
    }


    fstream f("rcbasic.dbgm", fstream::out | fstream::trunc);

    f << "SRC " << dbg_files[current_src_file] << endl;
    f << "LN " << current_src_line << endl;

    for(int i = 0; i < dbg_vars.size(); i++)
    {
        for(int usage = 0; usage < dbg_vars[i].usage_data.size(); usage++)
        {
            f << ((dbg_vars[i].type < RCBASIC_DEBUG_VAR_STR) ? "N" : "S") << " "
              << i << " " << dbg_vars[i].usage_data[usage].type << " "
              << (dbg_vars[i].usage_data[usage].is_error ? "E" : "G") << " "
              << dbg_vars[i].usage_data[usage].dimensions << " "
              << dbg_vars[i].usage_data[usage].dim[0] << " "
              << dbg_vars[i].usage_data[usage].dim[1] << " "
              << dbg_vars[i].usage_data[usage].dim[2] << " "
              << ((dbg_vars[i].type < RCBASIC_DEBUG_VAR_STR) ? "VAL=" + rc_intern_str(dbg_vars[i].usage_data[usage].num_val) : "VAL=" + dbg_format_string(dbg_vars[i].usage_data[usage].str_val))
              << endl;
        }
        dbg_vars[i].usage_data.clear();
        //f << ((dbg_vars[i].type==0) ? " N " : " S ") << dbg_vars[i].name << " " << ((dbg_vars[i].type==0) ? num_var[dbg_vars[i].index].
    }

    if(dbg_error_found)
    {
        f << "E " << dbg_error_message << endl;
    }

    f.close();



    f.open("rcbasic_dbg.cl", fstream::out); //generate this file to let the client know it has ownership
    f.close();

    while(!rc_intern_fileExist("rcbasic_dbg.rt")){} //wait for client to generate this file so we know its done reading the previous output

    while(rc_intern_fileExist("rcbasic_dbg.rt"))
    {
        rc_intern_fileDelete("rcbasic_dbg.rt"); //keep trying to delete file
    }

}

#endif // RCBASIC_DEBUG

//needed by internal functions so i am declaring it here
void lval_151(int n1);
void lval_152(uint64_t nid);
void lval_153(uint64_t lval_addr);
void lval_154(int s1);
void lval_155(uint64_t sid);
void pop_ptr_137(uint64_t n);

uint64_t rcbasic_readInt()
{
    uint64_t i;
    SDL_RWread(rc_fstream[0], &i, sizeof(uint64_t), 1);
    return i;
}


bool rcbasic_load(std::string filename)
{
    char rc[5];

    rc_fstream[0] = SDL_RWFromFile(filename.c_str(), "rb");

    if(!rc_fstream[0])
    {
        filename += ".cbc";
        rc_fstream[0] = SDL_RWFromFile(filename.c_str(), "rb");
        if(!rc_fstream[0])
            return false;
    }

    SDL_RWread(rc_fstream[0], rc, 5, 1);

    if(! (rc[0]=='R' && rc[1] =='C' && rc[2]=='4') )
    {
        std::string rcs = rc;
        cout << "This program was not built for this version of the runtime: " << rcs << endl;
        return false;
    }

    //--------- type definition header -------------------
    uint64_t num_types = rcbasic_readInt();

    rc_udtDefinition utype;
    rc_udtFieldSize null_size;

    for(int i = 0; i < num_types; i++)
    {
        utype.num_fields = rcbasic_readInt();

        //clear field vectors
        utype.field_type.clear();
        utype.field_type_index.clear();
        utype.field_dimensions.clear();
        utype.field_size.clear();

        for(int members = 0; members < utype.num_fields; members++)
        {
            utype.field_type.push_back(rcbasic_readInt());
            utype.field_type_index.push_back(rcbasic_readInt());
            utype.field_dimensions.push_back(rcbasic_readInt());
            utype.field_size.push_back(null_size);
        }

        //debug
        //cout << "Type #" << i << endl;
        //for(int n = 0; n < utype.num_fields; n++)
        //    cout << "   Field #" << n << ": " << utype.field_type[n] << ", " << utype.field_type_index[n] << ", " << utype.field_dimensions[n] << endl;
        //cout << endl;

        rc_types.push_back(utype);
    }

    // -------- end type definition header ---------------

    n_count = rcbasic_readInt();
    s_count = rcbasic_readInt();
    u_count = rcbasic_readInt();

    n_stack_size = rcbasic_readInt();
    s_stack_size = rcbasic_readInt();
    u_stack_size = rcbasic_readInt();

    loop_stack_size = rcbasic_readInt();

    numID_count = rcbasic_readInt();
    strID_count = rcbasic_readInt();
    usrID_count = rcbasic_readInt();

    code_segment_size = rcbasic_readInt();
    data_segment_size = rcbasic_readInt();

    vm_n = new rc_vm_n[n_count];
    vm_s = new rc_vm_s[s_count];
    vm_u = new rc_usrId[u_count];


    num_var = new rc_numId[numID_count];
    for(int i = 0; i < numID_count; i++)
    {
        //num_var[i].nid_value = new n_value;
        num_var[i].nid_value.value.resize(1);
        num_var[i].dimensions = 0;
        num_var[i].byref_offset = 0;
        num_var[i].nref = &num_var[i].nid_value;

        #ifdef RCBASIC_DEBUG
        num_var[i].is_debug_var = false;
        #endif // RCBASIC_DEBUG
    }

    str_var = new rc_strId[strID_count];
    for(int i = 0; i < strID_count; i++)
    {
        //str_var[i].sid_value = new s_value;
        str_var[i].sid_value.value.resize(1);
        str_var[i].dimensions = 0;
        str_var[i].byref_offset = 0;
        str_var[i].sref = &str_var[i].sid_value;

        #ifdef RCBASIC_DEBUG
        str_var[i].is_debug_var = false;
        #endif // RCBASIC_DEBUG
    }

    //cout << "usrID_count = " << usrID_count << endl;
    usr_var = new rc_usrId[usrID_count]; // this will have all of its members allocated by the dim_type instructions


    segment = new unsigned char*[2];
    segment[CODE_SEGMENT] = new unsigned char[code_segment_size];
    segment[DATA_SEGMENT] = new unsigned char[data_segment_size];

    SDL_RWread(rc_fstream[0], segment[CODE_SEGMENT], code_segment_size, 1);
    SDL_RWread(rc_fstream[0], segment[DATA_SEGMENT], data_segment_size, 1);

    SDL_RWclose(rc_fstream[0]);

    rc_fstream[0] = NULL;

    //cout << "DEBUG: Program has been loaded" << endl;

    return true;
}

uint64_t readInt()
{
    for(int i = 0; i < sizeof(uint64_t); i++)
    {
        readint_val.data[i] = segment[current_segment][current_address];
        current_address++;
    }
    return readint_val.i;
}

double readDouble()
{
    for(int i = 0; i < sizeof(double); i++)
    {
        readdouble_val.data[i] = segment[current_segment][current_address];
        current_address++;
    }
    return readdouble_val.f;
}

void dbg_1(uint32_t dbg_fn, uint64_t arg1, uint64_t arg2)
{
    #ifdef RCBASIC_DEBUG
    output_debug_message();

    switch(dbg_fn)
    {
        case 0:
            current_src_file = arg1;
            current_src_line = arg2;
            break;
    }
    #endif // RCBASIC_DEBUG
}

void mov_32(int n1, int n2)
{
    vm_n[n1].value = vm_n[n2].value;
}

void mov_33(int n1, double val)
{
    vm_n[n1].value = val;
    //cout << "n" << n1 << " = " << vm_n[n1].value << endl;
}

void mov_34(int n1, uint64_t nid)
{
    uint64_t byref_offset = num_var[nid].byref_offset;
    vm_n[n1].value = num_var[nid].nref[0].value[byref_offset];
    vm_n[n1].r = num_var[nid].nref;
    vm_n[n1].r_index = byref_offset;

    #ifdef RCBASIC_DEBUG
    if(!num_var[nid].is_debug_var)
        return;
    rcbasic_debug_access_status tmp_stat;
    tmp_stat.type = RCBASIC_DEBUG_ACCESS_GET;
    tmp_stat.dimensions = num_var[nid].dimensions;
    tmp_stat.dim[0] = byref_offset;
    tmp_stat.num_val = vm_n[n1].value;
    dbg_vars[num_var[nid].dbg_var_index].usage_data.push_back(tmp_stat);
    #endif // RCBASIC_DEBUG

    //cout << "n" << n1 << " = " << vm_n[n1].value << endl;
}

void mov_35(uint64_t nid, int n1)
{
    uint64_t byref_offset = num_var[nid].byref_offset;
    num_var[nid].nref[0].value[byref_offset] = vm_n[n1].value;

    #ifdef RCBASIC_DEBUG
    if(!num_var[nid].is_debug_var)
        return;
    rcbasic_debug_access_status tmp_stat;
    tmp_stat.type = RCBASIC_DEBUG_ACCESS_SET;
    tmp_stat.dimensions = num_var[nid].dimensions;
    tmp_stat.dim[0] = byref_offset;
    tmp_stat.num_val = vm_n[n1].value;
    dbg_vars[num_var[nid].dbg_var_index].usage_data.push_back(tmp_stat);
    #endif // RCBASIC_DEBUG

    //cout << "n" << n1 << " = " << vm_n[n1].value << endl;
    //cout << "nvar[" << nid << "] = " << num_var[nid].nid_value[0].value[0] << endl;
}

void movS_36(int s1, int s2)
{
    vm_s[s1].value = vm_s[s2].value;
}

void movS_37(int s1, uint64_t str_addr)
{
    vm_s[s1].value.clear();
    char c = segment[DATA_SEGMENT][str_addr];
    uint64_t i = str_addr;
    while(c != '\0')
    {
        vm_s[s1].value.push_back(c);
        i++;
        c = segment[DATA_SEGMENT][i];
    }
}

void movS_38(int s1, uint64_t sid)
{
    uint64_t byref_offset = str_var[sid].byref_offset;
    vm_s[s1].value = str_var[sid].sref[0].value[byref_offset];
    vm_s[s1].r = str_var[sid].sref;
    vm_s[s1].r_index = byref_offset;

    #ifdef RCBASIC_DEBUG
    if(!str_var[sid].is_debug_var)
        return;
    rcbasic_debug_access_status tmp_stat;
    tmp_stat.type = RCBASIC_DEBUG_ACCESS_GET;
    tmp_stat.dimensions = str_var[sid].dimensions;
    tmp_stat.dim[0] = byref_offset;
    tmp_stat.str_val = vm_s[s1].value;
    dbg_vars[str_var[sid].dbg_var_index].usage_data.push_back(tmp_stat);
    #endif // RCBASIC_DEBUG
}

void movS_39(uint64_t sid, int s1)
{
    uint64_t byref_offset = str_var[sid].byref_offset;
    str_var[sid].sref[0].value[byref_offset] = vm_s[s1].value;

    #ifdef RCBASIC_DEBUG
    if(!str_var[sid].is_debug_var)
        return;
    rcbasic_debug_access_status tmp_stat;
    tmp_stat.type = RCBASIC_DEBUG_ACCESS_SET;
    tmp_stat.dimensions = str_var[sid].dimensions;
    tmp_stat.dim[0] = byref_offset;
    tmp_stat.str_val = vm_s[s1].value;
    dbg_vars[str_var[sid].dbg_var_index].usage_data.push_back(tmp_stat);
    #endif // RCBASIC_DEBUG
}

void mov_r_40(int n1, int n2)
{
    vm_n[n1].r[0].value[ vm_n[n1].r_index ] = vm_n[n2].value;

    #ifdef RCBASIC_DEBUG
    for(int i = 0; i < dbg_vars[vm_n[n1].dbg_var_index].usage_data.size(); i++)
    {
        if(dbg_vars[vm_n[n1].dbg_var_index].usage_data[i].reg==n1)
        {
            dbg_vars[vm_n[n1].dbg_var_index].usage_data[i].type = RCBASIC_DEBUG_ACCESS_SET;
            dbg_vars[vm_n[n1].dbg_var_index].usage_data[i].str_val = vm_n[n2].value;
            break;
        }
    }
    #endif // RCBASIC_DEBUG
}

void mov_rS_41(int s1, int s2)
{
    vm_s[s1].r[0].value[ vm_s[s1].r_index ] = vm_s[s2].value;

    #ifdef RCBASIC_DEBUG
    for(int i = 0; i < dbg_vars[vm_s[s1].dbg_var_index].usage_data.size(); i++)
    {
        if(dbg_vars[vm_s[s1].dbg_var_index].usage_data[i].reg==s1)
        {
            dbg_vars[vm_s[s1].dbg_var_index].usage_data[i].type = RCBASIC_DEBUG_ACCESS_SET;
            dbg_vars[vm_s[s1].dbg_var_index].usage_data[i].str_val = vm_s[s2].value;
            break;
        }
    }
    #endif // RCBASIC_DEBUG
}

void mov_type_42(int u1, int u2)
{
    vm_u[u1].var_ref[0] = vm_u[u2];
    vm_u[u1].var_ref_index = 0;

    //if(u2 == 3)
    //{
    //    cout << "\nSetting value = " << vm_u[u1].var_ref[0].num_var[0].nid_value.value[0] << endl << endl;
    //}
}

void addS_43(int s1, int s2)
{
    vm_s[s1].value += vm_s[s2].value;
}

void add_44(int n1, int n2)
{
    vm_n[n1].value += vm_n[n2].value;
}

void sub_45(int n1, int n2)
{
    vm_n[n1].value -= vm_n[n2].value;
}

void mul_46(int n1, int n2)
{
    vm_n[n1].value *= vm_n[n2].value;
}

void div_47(int n1, int n2)
{
    #ifdef RCBASIC_DEBUG
    if(vm_n[n2].value == 0)
    {
        dbg_error_found = true;
        dbg_error_message = DBG_DIV_BY_ZERO;
        return;
    }
    #endif // RCBASIC_DEBUG
    vm_n[n1].value /= vm_n[n2].value;
}

void pow_48(int n1, int n2)
{
    vm_n[n1].value = pow(vm_n[n1].value, vm_n[n2].value);
}

void mod_49(int n1, int n2)
{
    vm_n[n1].value = (int64_t)(vm_n[n1].value) % (int64_t)(vm_n[n2].value);
}

void shl_50(int n1, int n2)
{
    vm_n[n1].value = (int64_t)(vm_n[n1].value) << (int64_t)(vm_n[n2].value);
}

void shr_51(int n1, int n2)
{
    vm_n[n1].value = (int64_t)(vm_n[n1].value) >> (int64_t)(vm_n[n2].value);
}

void and_52(int n1, int n2)
{
    vm_n[n1].value = (int64_t)(vm_n[n1].value) && (int64_t)(vm_n[n2].value);
}

void or_53(int n1, int n2)
{
    vm_n[n1].value = (int64_t)(vm_n[n1].value) || (int64_t)(vm_n[n2].value);
}

void xor_54(int n1, int n2)
{
    vm_n[n1].value = !((int64_t)(vm_n[n1].value)) != !((int64_t)(vm_n[n2].value));
}

void not_55(int n1)
{
    vm_n[n1].value = !((int64_t)vm_n[n1].value);
}

void cmp_56(int n1, int n2)
{
    CMP_FLAG_EQUAL = (vm_n[n1].value == vm_n[n2].value);
    CMP_FLAG_GREATER = (vm_n[n1].value > vm_n[n2].value);
    CMP_FLAG_GREATER_EQUAL = (vm_n[n1].value >= vm_n[n2].value);
    CMP_FLAG_LESS = (vm_n[n1].value < vm_n[n2].value);
    CMP_FLAG_LESS_EQUAL = (vm_n[n1].value <= vm_n[n2].value);
    CMP_FLAG_NOT_EQUAL = (vm_n[n1].value != vm_n[n2].value);
}

void cmpS_57(int s1, int s2)
{
    int str_cmp = vm_s[s1].value.compare(vm_s[s2].value);
    CMP_FLAG_EQUAL = (str_cmp==0);
    CMP_FLAG_NOT_EQUAL = (str_cmp!=0);
    CMP_FLAG_GREATER = (str_cmp>0);
    CMP_FLAG_GREATER_EQUAL = (CMP_FLAG_EQUAL || CMP_FLAG_GREATER);
    CMP_FLAG_LESS = (str_cmp<0);
    CMP_FLAG_LESS_EQUAL = (CMP_FLAG_EQUAL || CMP_FLAG_LESS);
}

void cmp_u_58(int n1, int n2)
{
}

void jmp_59(int n1)
{
    current_address = (uint64_t)vm_n[n1].value;
}

void jmp_60(uint64_t jmp_addr)
{
    current_address = jmp_addr;
}

void je_61(int n1)
{
    if(CMP_FLAG_EQUAL)
        current_address = (uint64_t)vm_n[n1].value;
}

void je_62(uint64_t jmp_addr)
{
    if(CMP_FLAG_EQUAL)
        current_address = jmp_addr;
}

void jne_63(int n1)
{
    if(CMP_FLAG_NOT_EQUAL)
        current_address = (uint64_t)vm_n[n1].value;
}

void jne_64(uint64_t jmp_addr)
{
    if(CMP_FLAG_NOT_EQUAL)
        current_address = jmp_addr;
}

void jg_65(int n1)
{
    if(CMP_FLAG_GREATER)
        current_address = (uint64_t)vm_n[n1].value;
}

void jg_66(uint64_t jmp_addr)
{
    if(CMP_FLAG_GREATER)
        current_address = jmp_addr;
}

void jge_67(int n1)
{
    if(CMP_FLAG_GREATER_EQUAL)
        current_address = (uint64_t)vm_n[n1].value;
}

void jge_68(uint64_t jmp_addr)
{
    if(CMP_FLAG_GREATER_EQUAL)
        current_address = jmp_addr;
}

void jl_69(int n1)
{
    if(CMP_FLAG_LESS)
        current_address = (uint64_t)vm_n[n1].value;
}

void jl_70(uint64_t jmp_addr)
{
    if(CMP_FLAG_LESS)
        current_address = jmp_addr;
}

void jle_71(int n1)
{
    if(CMP_FLAG_LESS_EQUAL)
        current_address = (uint64_t)vm_n[n1].value;
}

void jle_72(uint64_t jmp_addr)
{
    if(CMP_FLAG_LESS_EQUAL)
        current_address = jmp_addr;
}

void obj_num_73(uint64_t nid)
{
    num_object.obj_val = num_var[nid].nref;
    uint64_t byref_offset = num_var[nid].byref_offset;
    num_object.index = byref_offset;

    #ifdef RCBASIC_DEBUG
    if(!num_var[nid].is_debug_var)
        return;

    uint64_t num_var_size = 1;
    switch(num_var[nid].dimensions)
    {
        case 3:
            num_var_size *= num_var[nid].dim[2];
        case 2:
            num_var_size *= num_var[nid].dim[1];
        case 1:
            num_var_size *= num_var[nid].dim[0];
    }

    num_object.nid = nid;
    rcbasic_debug_access_status tmp_stat;
    tmp_stat.type = RCBASIC_DEBUG_ACCESS_GET;
    tmp_stat.dimensions = num_var[nid].dimensions;

    if(num_object.index >= num_var_size && dbg_vars[num_var[nid].dbg_var_index].type != RCBASIC_DEBUG_VAR_BYREF_NUM)
    {
        dbg_error_found = true;
        dbg_error_message = DBG_INDEX_EXCEEDS_SIZE;
        tmp_stat.is_error = true;
    }
    else
        tmp_stat.num_val = num_var[nid].nid_value[0].value[num_object.index];
    dbg_vars[num_var[nid].dbg_var_index].usage_data.push_back(tmp_stat);
    #endif // RCBASIC_DEBUG
}

void obj_num1_74(uint64_t nid, int n1)
{
    num_object.obj_val = num_var[nid].nref;
    uint64_t byref_offset = num_var[nid].byref_offset;
    num_object.index = (uint64_t)vm_n[n1].value + byref_offset;
    //cout << "obj_num index = " << num_object.index << endl;

    #ifdef RCBASIC_DEBUG
    if(!num_var[nid].is_debug_var)
        return;

    uint64_t num_var_size = 1;
    switch(num_var[nid].dimensions)
    {
        case 3:
            num_var_size *= num_var[nid].dim[2];
        case 2:
            num_var_size *= num_var[nid].dim[1];
        case 1:
            num_var_size *= num_var[nid].dim[0];
    }

    num_object.nid = nid;
    rcbasic_debug_access_status tmp_stat;
    tmp_stat.type = RCBASIC_DEBUG_ACCESS_GET;
    tmp_stat.dimensions = num_var[nid].dimensions;
    tmp_stat.dim[0] = vm_n[n1].value;

    if(num_object.index >= num_var_size && dbg_vars[num_var[nid].dbg_var_index].type != RCBASIC_DEBUG_VAR_BYREF_NUM)
    {
        dbg_error_found = true;
        dbg_error_message = DBG_INDEX_EXCEEDS_SIZE;
        tmp_stat.is_error = true;
    }
    else
        tmp_stat.num_val = num_var[nid].nid_value[0].value[num_object.index];
    dbg_vars[num_var[nid].dbg_var_index].usage_data.push_back(tmp_stat);
    #endif // RCBASIC_DEBUG
}

void obj_num2_75(uint64_t nid, int n1, int n2)
{
    uint64_t arr_pos = (uint64_t)vm_n[n1].value * num_var[nid].dim[1] + (uint64_t)vm_n[n2].value;
    num_object.obj_val = num_var[nid].nref;
    uint64_t byref_offset = num_var[nid].byref_offset;
    num_object.index = arr_pos + byref_offset;

    #ifdef RCBASIC_DEBUG
    if(!num_var[nid].is_debug_var)
        return;

    uint64_t num_var_size = 1;
    switch(num_var[nid].dimensions)
    {
        case 3:
            num_var_size *= num_var[nid].dim[2];
        case 2:
            num_var_size *= num_var[nid].dim[1];
        case 1:
            num_var_size *= num_var[nid].dim[0];
    }

    num_object.nid = nid;
    rcbasic_debug_access_status tmp_stat;
    tmp_stat.type = RCBASIC_DEBUG_ACCESS_GET;
    tmp_stat.dimensions = num_var[nid].dimensions;
    tmp_stat.dim[0] = vm_n[n1].value;
    tmp_stat.dim[1] = vm_n[n2].value;

    if(num_object.index >= num_var_size && dbg_vars[num_var[nid].dbg_var_index].type != RCBASIC_DEBUG_VAR_BYREF_NUM)
    {
        dbg_error_found = true;
        dbg_error_message = DBG_INDEX_EXCEEDS_SIZE;
        tmp_stat.is_error = true;
    }
    else
        tmp_stat.num_val = num_var[nid].nid_value[0].value[num_object.index];
    dbg_vars[num_var[nid].dbg_var_index].usage_data.push_back(tmp_stat);
    #endif // RCBASIC_DEBUG
}

void obj_num3_76(uint64_t nid, int n1, int n2, int n3)
{
    uint64_t arr_pos = ( (uint64_t)vm_n[n1].value * num_var[nid].dim[1] * num_var[nid].dim[2] ) + ((uint64_t)vm_n[n2].value * num_var[nid].dim[2]) + (uint64_t)vm_n[n3].value;
    num_object.obj_val = num_var[nid].nref;
    uint64_t byref_offset = num_var[nid].byref_offset;
    num_object.index = arr_pos + byref_offset;

    #ifdef RCBASIC_DEBUG
    if(!num_var[nid].is_debug_var)
        return;

    uint64_t num_var_size = 1;
    switch(num_var[nid].dimensions)
    {
        case 3:
            num_var_size *= num_var[nid].dim[2];
        case 2:
            num_var_size *= num_var[nid].dim[1];
        case 1:
            num_var_size *= num_var[nid].dim[0];
    }

    num_object.nid = nid;
    rcbasic_debug_access_status tmp_stat;
    tmp_stat.type = RCBASIC_DEBUG_ACCESS_GET;
    tmp_stat.dimensions = num_var[nid].dimensions;
    tmp_stat.dim[0] = vm_n[n1].value;
    tmp_stat.dim[1] = vm_n[n2].value;
    tmp_stat.dim[2] = vm_n[n3].value;

    if(num_object.index >= num_var_size && dbg_vars[num_var[nid].dbg_var_index].type != RCBASIC_DEBUG_VAR_BYREF_NUM)
    {
        dbg_error_found = true;
        dbg_error_message = DBG_INDEX_EXCEEDS_SIZE;
        tmp_stat.is_error = true;
    }
    else
        tmp_stat.num_val = num_var[nid].nid_value[0].value[num_object.index];
    dbg_vars[num_var[nid].dbg_var_index].usage_data.push_back(tmp_stat);
    #endif // RCBASIC_DEBUG
}

void obj_str_77(uint64_t sid)
{
    str_object.obj_val = str_var[sid].sref;
    uint64_t byref_offset = str_var[sid].byref_offset;
    str_object.index = byref_offset;

    #ifdef RCBASIC_DEBUG
    if(!str_var[sid].is_debug_var)
        return;

     uint64_t str_var_size = 1;
    switch(str_var[sid].dimensions)
    {
        case 3:
            str_var_size *= str_var[sid].dim[2];
        case 2:
            str_var_size *= str_var[sid].dim[1];
        case 1:
            str_var_size *= str_var[sid].dim[0];
    }

    str_object.sid = sid;
    rcbasic_debug_access_status tmp_stat;
    tmp_stat.type = RCBASIC_DEBUG_ACCESS_GET;
    tmp_stat.dimensions = str_var[sid].dimensions;
    tmp_stat.dim[0] = byref_offset;
    if(str_object.index >= str_var_size && dbg_vars[str_var[sid].dbg_var_index].type != RCBASIC_DEBUG_VAR_BYREF_STR)
    {
        dbg_error_found = true;
        dbg_error_message = DBG_INDEX_EXCEEDS_SIZE;
        tmp_stat.is_error = true;
    }
    else
        tmp_stat.str_val = str_var[sid].sid_value[0].value[str_object.index];
    dbg_vars[str_var[sid].dbg_var_index].usage_data.push_back(tmp_stat);
    #endif // RCBASIC_DEBUG
}

void obj_str1_78(uint64_t sid, int n1)
{
    str_object.obj_val = str_var[sid].sref;
    uint64_t byref_offset = str_var[sid].byref_offset;
    str_object.index = (uint64_t)vm_n[n1].value + byref_offset;

    #ifdef RCBASIC_DEBUG
    if(!str_var[sid].is_debug_var)
        return;

    uint64_t str_var_size = 1;
    switch(str_var[sid].dimensions)
    {
        case 3:
            str_var_size *= str_var[sid].dim[2];
        case 2:
            str_var_size *= str_var[sid].dim[1];
        case 1:
            str_var_size *= str_var[sid].dim[0];
    }
    str_object.sid = sid;
    rcbasic_debug_access_status tmp_stat;
    tmp_stat.type = RCBASIC_DEBUG_ACCESS_GET;
    tmp_stat.dimensions = str_var[sid].dimensions;
    tmp_stat.dim[0] = vm_n[n1].value;
    if(str_object.index >= str_var_size && dbg_vars[str_var[sid].dbg_var_index].type != RCBASIC_DEBUG_VAR_BYREF_STR)
    {
        dbg_error_found = true;
        dbg_error_message = DBG_INDEX_EXCEEDS_SIZE;
        tmp_stat.is_error = true;
    }
    else
        tmp_stat.str_val = str_var[sid].sid_value[0].value[str_object.index];
    dbg_vars[str_var[sid].dbg_var_index].usage_data.push_back(tmp_stat);
    #endif // RCBASIC_DEBUG
}

void obj_str2_79(uint64_t sid, int n1, int n2)
{
    uint64_t arr_pos = (uint64_t)vm_n[n1].value * str_var[sid].dim[1] + (uint64_t)vm_n[n2].value;
    str_object.obj_val = str_var[sid].sref;
    uint64_t byref_offset = str_var[sid].byref_offset;
    str_object.index = arr_pos + byref_offset;

    #ifdef RCBASIC_DEBUG
    if(!str_var[sid].is_debug_var)
        return;

    uint64_t str_var_size = 1;
    switch(str_var[sid].dimensions)
    {
        case 3:
            str_var_size *= str_var[sid].dim[2];
        case 2:
            str_var_size *= str_var[sid].dim[1];
        case 1:
            str_var_size *= str_var[sid].dim[0];
    }

    str_object.sid = sid;
    rcbasic_debug_access_status tmp_stat;
    tmp_stat.type = RCBASIC_DEBUG_ACCESS_GET;
    tmp_stat.dimensions = str_var[sid].dimensions;
    tmp_stat.dim[0] = vm_n[n1].value;
    tmp_stat.dim[1] = vm_n[n2].value;

    if(str_object.index >= str_var_size && dbg_vars[str_var[sid].dbg_var_index].type != RCBASIC_DEBUG_VAR_BYREF_STR)
    {
        dbg_error_found = true;
        dbg_error_message = DBG_INDEX_EXCEEDS_SIZE;
        tmp_stat.is_error = true;
    }
    else
        tmp_stat.str_val = str_var[sid].sid_value[0].value[str_object.index];
    dbg_vars[str_var[sid].dbg_var_index].usage_data.push_back(tmp_stat);
    #endif // RCBASIC_DEBUG
}

void obj_str3_80(uint64_t sid, int n1, int n2, int n3)
{
    uint64_t arr_pos = ( (uint64_t)vm_n[n1].value * str_var[sid].dim[1] * str_var[sid].dim[2] ) + ((uint64_t)vm_n[n2].value * str_var[sid].dim[2]) + (uint64_t)vm_n[n3].value;
    str_object.obj_val = str_var[sid].sref;
    uint64_t byref_offset = str_var[sid].byref_offset;
    str_object.index = arr_pos + byref_offset;

    #ifdef RCBASIC_DEBUG
    if(!str_var[sid].is_debug_var)
        return;

    uint64_t str_var_size = 1;
    switch(str_var[sid].dimensions)
    {
        case 3:
            str_var_size *= str_var[sid].dim[2];
        case 2:
            str_var_size *= str_var[sid].dim[1];
        case 1:
            str_var_size *= str_var[sid].dim[0];
    }

    str_object.sid = sid;
    rcbasic_debug_access_status tmp_stat;
    tmp_stat.type = RCBASIC_DEBUG_ACCESS_GET;
    tmp_stat.dimensions = str_var[sid].dimensions;
    tmp_stat.dim[0] = vm_n[n1].value;
    tmp_stat.dim[1] = vm_n[n2].value;
    tmp_stat.dim[2] = vm_n[n3].value;

    if(str_object.index >= str_var_size && dbg_vars[str_var[sid].dbg_var_index].type != RCBASIC_DEBUG_VAR_BYREF_STR)
    {
        dbg_error_found = true;
        dbg_error_message = DBG_INDEX_EXCEEDS_SIZE;
        tmp_stat.is_error = true;
    }
    else
        tmp_stat.str_val = str_var[sid].sid_value[0].value[str_object.index];
    dbg_vars[str_var[sid].dbg_var_index].usage_data.push_back(tmp_stat);
    #endif // RCBASIC_DEBUG
}

void obj_usr_81(uint64_t uid)
{
    //cout << "obj_usr " << uid << ":  size = " << usr_object.obj_ref->uid_value[uid].uid_value.size() << endl;
    usr_object.index = 0;

    rc_usrId* tmp_usr_id = &usr_object.obj_ref->uid_value[uid];

    usr_object.obj_ref = &usr_object.obj_ref->uid_value[uid].uid_value[0];

    usr_object.obj_ref->byref_ptr = tmp_usr_id;
    //usr_object.obj_ref->byref_ptr = &usr_object.obj_ref->uid_value[uid];
}

void obj_usr1_82(uint64_t uid, int n1)
{
    //cout << "obj_usr2 " << uid << " " << (uint64_t)vm_n[n1].value << " " << (uint64_t)vm_n[n2].value << ":  size = " << usr_object.obj_ref->uid_value.size() << endl;
    //rc_usrId* tmp_usr_id = &usr_object.obj_ref->uid_value[uid];
    //usr_object.index = (uint64_t)vm_n[n1].value;;
    //cout << "\n\nuid =" << uid << ",  index = (" << usr_object.index << ")  old_index = " << usr_object.index << endl << endl;
    //cout << "\n\nusr index = " << usr_object.obj_ref->uid_value[uid].uid_value[usr_object.index].str_var.size() << endl << endl;


    //cout << "obj_usr1 " << uid << " " << (uint64_t)vm_n[n1].value << endl;
    //cout << "  ---dbg[uid]: " << usr_object.obj_ref->uid_value[uid].uid_value[1].num_var[0].nid_value.value[0] << endl;
    //cout << "  ---dbg[str]: " << usr_object.obj_ref->uid_value[uid].uid_value[0].str_var.size() << endl;
    usr_object.index = (uint64_t)vm_n[n1].value;

    rc_usrId* tmp_usr_id = &usr_object.obj_ref->uid_value[uid];

    usr_object.obj_ref = &usr_object.obj_ref->uid_value[uid].uid_value[usr_object.index];

    usr_object.obj_ref->byref_ptr = tmp_usr_id;
    //usr_object.obj_ref->byref_ptr = &usr_object.obj_ref->uid_value[uid];
}

void obj_usr2_83(uint64_t uid, int n1, int n2)
{
    //cout << "obj_usr2 " << uid << " " << (uint64_t)vm_n[n1].value << " " << (uint64_t)vm_n[n2].value << ":  size = " << usr_object.obj_ref->uid_value.size() << endl;
    //rc_usrId* tmp_usr_id =  &usr_object.obj_ref->uid_value[uid];
    //usr_object.index = (uint64_t)vm_n[n1].value * usr_object.obj_ref->uid_value[uid].dim[1] + (uint64_t)vm_n[n2].value;
    //cout << "\n\nuid =" << uid << ",  index = (" << usr_object.index << ")  old_index = " << usr_object.index << endl << endl;
    //cout << "\n\nusr index = " << usr_object.obj_ref->uid_value[uid].uid_value.size() << endl << endl;

    usr_object.index = (uint64_t)vm_n[n1].value * usr_object.obj_ref->uid_value[uid].dim[1] + (uint64_t)vm_n[n2].value;

    rc_usrId* tmp_usr_id = &usr_object.obj_ref->uid_value[uid];

    usr_object.obj_ref = &usr_object.obj_ref->uid_value[uid].uid_value[usr_object.index];

    usr_object.obj_ref->byref_ptr = tmp_usr_id;
    //usr_object.obj_ref->byref_ptr = &usr_object.obj_ref->uid_value[uid];
}

void obj_usr3_84(uint64_t uid, int n1, int n2, int n3)
{
    //rc_usrId* tmp_usr_id =  &usr_object.obj_ref->uid_value[uid];

    //cout << "obj_usr3 " << uid << " " << (uint64_t)vm_n[n1].value << " " << (uint64_t)vm_n[n2].value << " " << (uint64_t)vm_n[n3].value <<  endl;
    usr_object.index = ( (uint64_t)vm_n[n1].value * usr_object.obj_ref->uid_value[uid].dim[1] * usr_object.obj_ref->uid_value[uid].dim[2] ) + ((uint64_t)vm_n[n2].value * usr_object.obj_ref->uid_value[uid].dim[2]) + (uint64_t)vm_n[n3].value;;

    //----test
    rc_usrId* tmp_usr_id = &usr_object.obj_ref->uid_value[uid];
    //------------------------------------------

    usr_object.obj_ref = &usr_object.obj_ref->uid_value[uid].uid_value[usr_object.index];

    usr_object.obj_ref->byref_ptr = tmp_usr_id;

    //usr_object.obj_ref->byref_ptr = &usr_object.obj_ref->uid_value[uid];
}

void obj_get_85(int n1)
{
    //cout << "var index = " << num_object.index << endl;
    //cout << "store in n" << n1 << endl;
    vm_n[n1].value = num_object.obj_val[0].value[num_object.index];
    //cout  << "t1" << endl;
    vm_n[n1].r = num_object.obj_val;
    //cout << "t2" << endl;
    vm_n[n1].r_index = num_object.index;
    //cout << "t3" << endl;

    num_object.obj_val->ref_parent = num_object.obj_val;

    #ifdef RCBASIC_DEBUG
    if(!num_var[num_object.nid].is_debug_var)
        return;

    int usage_size = dbg_vars[num_var[num_object.nid].dbg_var_index].usage_data.size();
    dbg_vars[num_var[num_object.nid].dbg_var_index].usage_data[usage_size-1].reg = n1;
    vm_n[n1].dbg_var_index = num_var[num_object.nid].dbg_var_index;
    #endif // RCBASIC_DEBUG
}

void obj_getS_86(int s1)
{
    vm_s[s1].value = str_object.obj_val[0].value[str_object.index];
    vm_s[s1].r = str_object.obj_val;
    vm_s[s1].r_index = str_object.index;

    str_object.obj_val->ref_parent = str_object.obj_val;

    #ifdef RCBASIC_DEBUG
    if(!str_var[str_object.sid].is_debug_var)
        return;

    int usage_size = dbg_vars[str_var[str_object.sid].dbg_var_index].usage_data.size();
    dbg_vars[str_var[str_object.sid].dbg_var_index].usage_data[usage_size-1].reg = s1;
    vm_s[s1].dbg_var_index = str_var[str_object.sid].dbg_var_index;
    #endif // RCBASIC_DEBUG
}

void obj_set_87(int n1)
{
}

void obj_setS_88(int s1)
{
}

void clear_obj_89()
{
}

bool rc_dim_type(rc_usrId* parent, uint64_t udt_index, int num_dim, uint64_t d1, uint64_t d2, uint64_t d3, uint64_t start_index = 0)
{
    uint64_t dim_size = 0;
    switch(num_dim)
    {
        case 0:
            dim_size = 1;
            break;
        case 1:
            dim_size = d1;
            break;
        case 2:
            dim_size = d1 * d2;
            break;
        case 3:
            dim_size = d1 * d2 * d3;
            break;
    }

    parent->dimensions = num_dim;
    parent->dim[0] = d1;
    parent->dim[1] = d2;
    parent->dim[2] = d3;

    parent->byref_offset = 0;
    parent->uid_value.resize(dim_size);

    parent->var_ref = parent;
    parent->var_ref_index = 0;

    rc_usrId* p_obj;

    uint64_t field_size = 0;

    //cout << "starting field: " << udt_index << " " << num_dim << " " << d1 << " " << d2 << " " << d3 << ": " << parent->uid_value.size() << endl;

    for(uint64_t i = start_index; i < dim_size; i++)
    {
        p_obj = &parent->uid_value[i];

        for(int field = 0; field < rc_types[udt_index].num_fields; field++)
        {
            field_size = 1;
            switch(rc_types[udt_index].field_dimensions[field])
            {
                case 3:
                    field_size *= rc_types[udt_index].field_size[field].dim[2];
                case 2:
                    field_size *= rc_types[udt_index].field_size[field].dim[1];
                case 1:
                    field_size *= rc_types[udt_index].field_size[field].dim[0];
                    break;
            }

            switch(rc_types[udt_index].field_type[field])
            {
                case RC_UDT_TYPE_NUM:
                    {
                        rc_numId tmp_num_var;
                        //tmp_num_var.nid_value = new n_value;
                        tmp_num_var.nid_value.value.resize(field_size);
                        tmp_num_var.dimensions =  rc_types[udt_index].field_dimensions[field];
                        tmp_num_var.dim[0] = rc_types[udt_index].field_size[field].dim[0];
                        tmp_num_var.dim[1] = rc_types[udt_index].field_size[field].dim[1];
                        tmp_num_var.dim[2] = rc_types[udt_index].field_size[field].dim[2];
                        p_obj->num_var.push_back(tmp_num_var);
                        uint64_t nv_index = p_obj->num_var.size()-1;
                        p_obj->num_var[nv_index].nref = &p_obj->num_var[nv_index].nid_value;
                    }
                    break;
                case RC_UDT_TYPE_STR:
                    {
                        rc_strId tmp_str_var;
                        //tmp_str_var.sid_value = new s_value;
                        tmp_str_var.sid_value.value.resize(field_size);
                        tmp_str_var.dimensions =  rc_types[udt_index].field_dimensions[field];
                        tmp_str_var.dim[0] = rc_types[udt_index].field_size[field].dim[0];
                        tmp_str_var.dim[1] = rc_types[udt_index].field_size[field].dim[1];
                        tmp_str_var.dim[2] = rc_types[udt_index].field_size[field].dim[2];
                        p_obj->str_var.push_back(tmp_str_var);
                        uint64_t sv_index = p_obj->str_var.size()-1;
                        p_obj->str_var[sv_index].sref = &p_obj->str_var[sv_index].sid_value;
                    }
                    break;
                case RC_UDT_TYPE_USR:
                    {
                        //WIP: p_obj is just going to get resized everytime this is called. So instead I need to create a type object to add and run rc_dim_type on that
                        rc_usrId usr_field;
                        rc_dim_type(&usr_field, rc_types[udt_index].field_type_index[field], rc_types[udt_index].field_dimensions[field],
                                    rc_types[udt_index].field_size[field].dim[0],
                                    rc_types[udt_index].field_size[field].dim[1],
                                    rc_types[udt_index].field_size[field].dim[2]);
                        p_obj->uid_value.push_back(usr_field);
                    }
                    break;
            }
        }
    }
    return true;
}

bool rc_free_type(rc_usrId* parent)
{
    uint64_t dim_size = parent->uid_value.size();


    rc_usrId* p_obj;

    uint64_t field_size = 0;

    for(uint64_t i = 0; i < dim_size; i++)
    {
        p_obj = &parent->uid_value[i];

        for(uint64_t n_field = 0; n_field < p_obj->num_var.size(); n_field++)
        {
            p_obj->num_var[n_field].nid_value.value.clear();
            p_obj->num_var[n_field].nid_value.value.shrink_to_fit();
            //delete p_obj->num_var[n_field].nid_value;
        }

        for(uint64_t s_field = 0; s_field < p_obj->str_var.size(); s_field++)
        {
            p_obj->str_var[s_field].sid_value.value.clear();
            p_obj->str_var[s_field].sid_value.value.shrink_to_fit();
            //delete p_obj->str_var[s_field].sid_value;
        }

        for(uint64_t u_field = 0; u_field < p_obj->uid_value.size(); u_field++)
        {
            rc_free_type(&p_obj->uid_value[u_field]);
            p_obj->uid_value[u_field].uid_value.clear();
            p_obj->uid_value[u_field].uid_value.shrink_to_fit();
        }
    }

    parent->uid_value.clear();
    parent->uid_value.shrink_to_fit();

    return true;
}

void dim_type_90(uint64_t uid, uint64_t udt_index)
{
    //cout << "DimType " << uid << " " << udt_index << endl;
    rc_free_type(&usr_var[uid]);
    //cout << "Freed memory" << endl;
    rc_dim_type( &usr_var[uid], udt_index, 0, 0, 0, 0 );
    //cout << "DimType End" << endl;
}

void dim_type1_91(uint64_t uid, uint64_t udt_index, int n1)
{
    //cout << "DimType1 " << uid << " " << udt_index << " " << (uint64_t)vm_n[n1].value << endl;
    rc_free_type(&usr_var[uid]);
    rc_dim_type( &usr_var[uid], udt_index, 1, (uint64_t)vm_n[n1].value, 0, 0 );
    //cout << "DimType End" << endl;
}

void dim_type2_92(uint64_t uid, uint64_t udt_index, int n1, int n2)
{
    //cout << "DimType2 " << uid << " " << udt_index << " " << (uint64_t)vm_n[n1].value << " " << (uint64_t)vm_n[n2].value << endl;
    rc_free_type(&usr_var[uid]);
    rc_dim_type( &usr_var[uid], udt_index, 2, (uint64_t)vm_n[n1].value, (uint64_t)vm_n[n2].value, 0 );
    //cout << "DimType End" << endl;
}

void dim_type3_93(uint64_t uid, uint64_t udt_index, int n1, int n2, int n3)
{
    //cout << "DimType3 " << uid << " " << udt_index << " " << (uint64_t)vm_n[n1].value << " " << (uint64_t)vm_n[n2].value << " " << (uint64_t)vm_n[n3].value << endl;
    rc_free_type(&usr_var[uid]);
    rc_dim_type( &usr_var[uid], udt_index, 3, (uint64_t)vm_n[n1].value, (uint64_t)vm_n[n2].value, (uint64_t)vm_n[n3].value );
    //cout << "DimType End" << endl;
}

void dim_num1_94(uint64_t nid, int n1)
{
    #ifdef RCBASIC_DEBUG
        if(vm_n[n1].value <= 0)
        {
            dbg_error_found = true;
            dbg_error_message = DBG_DIM_LEQ_ZERO;
            return;
        }
    #endif // RCBASIC_DEBUG
    num_var[nid].nid_value.value.resize((uint64_t)vm_n[n1].value);
    num_var[nid].nref = &num_var[nid].nid_value;
    num_var[nid].dimensions = 1;
    num_var[nid].dim[0] = (uint64_t)vm_n[n1].value;
    num_var[nid].dim[1] = 0;
    num_var[nid].dim[2] = 0;
}

void dim_num2_95(uint64_t nid, int n1, int n2)
{
    #ifdef RCBASIC_DEBUG
        if(vm_n[n1].value <= 0 || vm_n[n2].value <= 0)
        {
            dbg_error_found = true;
            dbg_error_message = DBG_DIM_LEQ_ZERO;
            return;
        }
    #endif // RCBASIC_DEBUG
    num_var[nid].nid_value.value.resize((uint64_t)vm_n[n1].value * (uint64_t)vm_n[n2].value);
    num_var[nid].nref = &num_var[nid].nid_value;
    num_var[nid].dimensions = 2;
    num_var[nid].dim[0] = (uint64_t)vm_n[n1].value;
    num_var[nid].dim[1] = (uint64_t)vm_n[n2].value;
    num_var[nid].dim[2] = 0;
}

void dim_num3_96(uint64_t nid, int n1, int n2, int n3)
{
    #ifdef RCBASIC_DEBUG
        if(vm_n[n1].value <= 0 || vm_n[n2].value <= 0 || vm_n[n3].value <= 0)
        {
            dbg_error_found = true;
            dbg_error_message = DBG_DIM_LEQ_ZERO;
            return;
        }
    #endif // RCBASIC_DEBUG
    num_var[nid].nid_value.value.resize((uint64_t)vm_n[n1].value * (uint64_t)vm_n[n2].value * (uint64_t)vm_n[n3].value);
    num_var[nid].nref = &num_var[nid].nid_value;
    num_var[nid].dimensions = 3;
    num_var[nid].dim[0] = (uint64_t)vm_n[n1].value;
    num_var[nid].dim[1] = (uint64_t)vm_n[n2].value;
    num_var[nid].dim[2] = (uint64_t)vm_n[n3].value;
}

void dim_str1_97(uint64_t sid, int n1)
{
    #ifdef RCBASIC_DEBUG
        if(vm_n[n1].value <= 0)
        {
            dbg_error_found = true;
            dbg_error_message = DBG_DIM_LEQ_ZERO;
            return;
        }
    #endif // RCBASIC_DEBUG
    str_var[sid].sid_value.value.resize((uint64_t)vm_n[n1].value);
    str_var[sid].sref = &str_var[sid].sid_value;
    str_var[sid].dimensions = 1;
    str_var[sid].dim[0] = (uint64_t)vm_n[n1].value;
    str_var[sid].dim[1] = 0;
    str_var[sid].dim[2] = 0;
}

void dim_str2_98(uint64_t sid, int n1, int n2)
{
    #ifdef RCBASIC_DEBUG
        if(vm_n[n1].value <= 0 || vm_n[n2].value <= 0)
        {
            dbg_error_found = true;
            dbg_error_message = DBG_DIM_LEQ_ZERO;
            return;
        }
    #endif // RCBASIC_DEBUG
    str_var[sid].sid_value.value.resize((uint64_t)vm_n[n1].value * (uint64_t)vm_n[n2].value);
    str_var[sid].sref = &str_var[sid].sid_value;
    str_var[sid].dimensions = 2;
    str_var[sid].dim[0] = (uint64_t)vm_n[n1].value;
    str_var[sid].dim[1] = (uint64_t)vm_n[n2].value;
    str_var[sid].dim[2] = 0;
}

void dim_str3_99(uint64_t sid, int n1, int n2, int n3)
{
    #ifdef RCBASIC_DEBUG
        if(vm_n[n1].value <= 0 || vm_n[n2].value <= 0 || vm_n[n3].value <= 0)
        {
            dbg_error_found = true;
            dbg_error_message = DBG_DIM_LEQ_ZERO;
            return;
        }
    #endif // RCBASIC_DEBUG
    str_var[sid].sid_value.value.resize((uint64_t)vm_n[n1].value * (uint64_t)vm_n[n2].value * (uint64_t)vm_n[n3].value);
    str_var[sid].sref = &str_var[sid].sid_value;
    str_var[sid].dimensions = 3;
    str_var[sid].dim[0] = (uint64_t)vm_n[n1].value;
    str_var[sid].dim[1] = (uint64_t)vm_n[n2].value;
    str_var[sid].dim[2] = (uint64_t)vm_n[n3].value;
}

void delete_100(uint64_t nid)
{
    num_var[nid].nid_value.value.clear();
    num_var[nid].nid_value.value.shrink_to_fit();
    num_var[nid].dimensions = 0;
    num_var[nid].dim[0] = 0;
    num_var[nid].dim[1] = 0;
    num_var[nid].dim[2] = 0;
}

void deleteS_101(uint64_t sid)
{
    str_var[sid].sid_value.value.clear();
    str_var[sid].sid_value.value.shrink_to_fit();
    str_var[sid].dimensions = 0;
    str_var[sid].dim[0] = 0;
    str_var[sid].dim[1] = 0;
    str_var[sid].dim[2] = 0;
}

void push_102(int n1)
{
    //n_stack[current_n_stack_count] = vm_n[n1].value;
    //current_n_stack_count++;
    n_stack.push(vm_n[n1]);
}

void push_103(uint64_t nid)
{
    //n_stack[current_n_stack_count] = num_var[nid].value[0];
    //current_n_stack_count++;
    rc_vm_n n;
    uint64_t byref_offset = num_var[nid].byref_offset;
    n.value = num_var[nid].nref[0].value[byref_offset];
    n.r_index = byref_offset;
    n_stack.push(n);
}

void pushS_104(int s1)
{
    //s_stack[current_s_stack_count] = vm_s[s1].value;
    //current_s_stack_count++;
    s_stack.push(vm_s[s1]);
}

void pushS_105(uint64_t sid)
{
    //s_stack[current_s_stack_count] = str_var[sid].value[0];
    //current_s_stack_count++;
    rc_vm_s s;
    uint64_t byref_offset = str_var[sid].byref_offset;
    s.value = str_var[sid].sref[0].value[byref_offset];
    s.r_index = byref_offset;
    s_stack.push(s);
}

void push_emptyS_106()
{
    rc_vm_s s_empty;
    s_empty.value = "";
    //s_stack[current_s_stack_count] = "";
    //current_s_stack_count++;
    s_stack.push(s_empty);
}

void pop_107(int n1)
{
    //current_n_stack_count--;
    //vm_n[n1].value = n_stack[current_n_stack_count];
    vm_n[n1].value = n_stack.top().value;
    vm_n[n1].r = n_stack.top().r;
    vm_n[n1].r_index = n_stack.top().r_index;
    n_stack.pop();
}

void pop_108(uint64_t nid)
{
    //current_n_stack_count--;
    //num_var[nid].value[0] = n_stack[current_n_stack_count];
    uint64_t byref_offset = n_stack.top().r_index;
    num_var[nid].nref[0].value[byref_offset] = n_stack.top().value;
    num_var[nid].byref_offset = byref_offset;
    n_stack.pop();
}

void popS_109(int s1)
{
    //current_s_stack_count--;
    //vm_s[s1].value = s_stack[current_s_stack_count];
    vm_s[s1].value = s_stack.top().value;
    vm_s[s1].r = s_stack.top().r;
    vm_s[s1].r_index = s_stack.top().r_index;
    s_stack.pop();
}

void popS_110(uint64_t sid)
{
    //current_s_stack_count--;
    //str_var[sid].value[0] = s_stack[current_s_stack_count];
    uint64_t byref_offset = s_stack.top().r_index;
    str_var[sid].sref[0].value[byref_offset] = s_stack.top().value;
    str_var[sid].byref_offset = byref_offset;
    s_stack.pop();
}

void get_stack_size_111(int n1)
{
    vm_n[n1].value = n_stack.size();
}

void get_stack_sizeS_112(int n1)
{
    vm_n[n1].value = s_stack.size();
}

void clear_stack_113()
{
    //current_n_stack_count = 0;
    n_stack.empty();
}

void clear_stackS_114()
{
    //current_s_stack_count = 0;
    s_stack.empty();
}

void while_115(int n1, uint64_t jmp_addr)
{
    if(vm_n[n1].value == 0)
        current_address = jmp_addr;
    //rc_events();
}

void wend_116(uint64_t jmp_addr)
{
    current_address = jmp_addr;
}

void for_117(uint64_t nid, int n1, int n2, int n3)
{
    rc_loop for_loop;
    for_loop.counter = &num_var[nid];
    for_loop.f_end = vm_n[n2].value;
    for_loop.f_step = vm_n[n3].value;

    switch(for_offset_dimensions)
    {
        case 1:
            for_loop.counter_offset = for_offset_index[0];
            break;
        case 2:
            for_loop.counter_offset = for_offset_index[0] * num_var[nid].dim[1] + for_offset_index[1];
            break;
        case 3:
            for_loop.counter_offset = ( for_offset_index[0] * num_var[nid].dim[1] * num_var[nid].dim[2] ) + (for_offset_index[1] * num_var[nid].dim[2]) + for_offset_index[2];
            break;
        default:
            for_loop.counter_offset = 0;
    }

    uint64_t byref_offset = num_var[nid].byref_offset;

    #ifdef RCBASIC_DEBUG
        uint64_t nv_size = 1;
        uint64_t dbg_index = num_var[nid].dbg_var_index;
        rcbasic_debug_access_status tmp_stat;
        for_loop.counter_dim[0] = for_offset_index[0];
        for_loop.counter_dim[1] = for_offset_index[1];
        for_loop.counter_dim[2] = for_offset_index[2];

        switch(num_var[nid].dimensions)
        {
            case 3: nv_size *= num_var[nid].dim[2];
            case 2: nv_size *= num_var[nid].dim[1];
            case 1: nv_size *= num_var[nid].dim[0];
            break;
        }

        if(num_var[nid].is_debug_var)
        {
            tmp_stat.dimensions = num_var[nid].dimensions;
            tmp_stat.dim[0] = for_offset_index[0];
            tmp_stat.dim[1] = for_offset_index[1];
            tmp_stat.dim[2] = for_offset_index[2];
            tmp_stat.num_val = vm_n[n1].value;
            tmp_stat.reg = -1;
            tmp_stat.type = RCBASIC_DEBUG_ACCESS_SET;
        }

        if((byref_offset + for_loop.counter_offset) >= nv_size && num_var[nid].is_debug_var)
        {
            if(dbg_vars[num_var[nid].dbg_var_index].type != RCBASIC_DEBUG_VAR_BYREF_NUM)
            {
                dbg_error_found = true;
                dbg_error_message = DBG_INDEX_EXCEEDS_SIZE;

                if(num_var[nid].is_debug_var)
                    tmp_stat.is_error = true;

                dbg_vars[dbg_index].usage_data.push_back(tmp_stat);

                return;
            }
        }
        else
        {
            dbg_vars[dbg_index].usage_data.push_back(tmp_stat);
        }
    #endif // RCBASIC_DEBUG

    num_var[nid].nref[0].value[byref_offset + for_loop.counter_offset] = vm_n[n1].value;


    //These 3 lines reads the line value passed by the compiler
    //This line value is the address of the end of the loop
    unsigned rcbasic_cmd = segment[current_segment][current_address];
    current_address++;
    uint64_t for_end_addr = readInt();

    //cout << "next_addr: " << next_addr << endl;

    if( vm_n[n2].value < vm_n[n1].value )
    {
        for_loop.isNegative = true;

        if(for_loop.f_step > 0)
        {
            current_address = for_end_addr;
            return;
        }
    }
    else
    {
        for_loop.isNegative = false;

        if(for_loop.f_step < 0)
        {
            current_address = for_end_addr;
            return;
        }
    }


    loop_stack.push(for_loop);
    //current_loop_stack_count++;
    //cout << "nid = " << nid << " --> " << (uint64_t)(&num_var[nid].nid_value[0].value[0]) << endl;
    //cout << "nid_value = " << num_var[nid].nid_value[0].value[0] << endl;
    //cout << "id[10] = " << num_var[10].nid_value[0].value[0] << " --> " << (uint64_t)(&num_var[10].nid_value[0].value[0]) << endl;
    //cout << "id[11] = " << num_var[11].nid_value[0].value[0] << " --> " << (uint64_t)(&num_var[11].nid_value[0].value[0]) << endl;
    //cin.get();
}

void next_118(uint64_t f_addr)
{
    //int l_index = current_loop_stack_count-1;
    uint64_t byref_offset = loop_stack.top().counter[0].byref_offset + loop_stack.top().counter_offset;
    double next_step = loop_stack.top().counter[0].nref[0].value[byref_offset] + loop_stack.top().f_step;
    if(loop_stack.top().isNegative && next_step <= loop_stack.top().counter[0].nref[0].value[byref_offset] && next_step >= loop_stack.top().f_end)
    {
        loop_stack.top().counter[0].nref[0].value[byref_offset] += loop_stack.top().f_step;
        current_address = f_addr;

        #ifdef RCBASIC_DEBUG
        if(loop_stack.top().counter[0].is_debug_var)
        {
            rcbasic_debug_access_status tmp_stat;
            tmp_stat.dimensions = loop_stack.top().counter[0].dimensions;
            tmp_stat.dim[0] = loop_stack.top().counter_dim[0];
            tmp_stat.dim[1] = loop_stack.top().counter_dim[1];
            tmp_stat.dim[2] = loop_stack.top().counter_dim[2];
            tmp_stat.type = RCBASIC_DEBUG_ACCESS_SET;
            tmp_stat.num_val = loop_stack.top().counter[0].nid_value[0].value[byref_offset];
            dbg_vars[loop_stack.top().counter[0].dbg_var_index].usage_data.push_back(tmp_stat);
        }
        #endif // RCBASIC_DEBUG
    }
    else if( (!loop_stack.top().isNegative) && next_step >= loop_stack.top().counter[0].nref[0].value[byref_offset] && next_step <= loop_stack.top().f_end)
    {
        loop_stack.top().counter[0].nref[0].value[byref_offset] += loop_stack.top().f_step;
        current_address = f_addr;

        #ifdef RCBASIC_DEBUG
        if(loop_stack.top().counter[0].is_debug_var)
        {
            rcbasic_debug_access_status tmp_stat;
            tmp_stat.dimensions = loop_stack.top().counter[0].dimensions;
            tmp_stat.dim[0] = loop_stack.top().counter_dim[0];
            tmp_stat.dim[1] = loop_stack.top().counter_dim[1];
            tmp_stat.dim[2] = loop_stack.top().counter_dim[2];
            tmp_stat.type = RCBASIC_DEBUG_ACCESS_SET;
            tmp_stat.num_val = loop_stack.top().counter[0].nid_value[0].value[byref_offset];
            dbg_vars[loop_stack.top().counter[0].dbg_var_index].usage_data.push_back(tmp_stat);
        }
        #endif // RCBASIC_DEBUG
    }
    else
    {
        loop_stack.pop();
        //current_loop_stack_count--;
    }
    //cout << "id[10] = " << num_var[10].nid_value[0].value[0] << " --> " << (uint64_t)(&num_var[10].nid_value[0].value[0]) << endl;
    //cout << "id[11] = " << num_var[11].nid_value[0].value[0] << " --> " << (uint64_t)(&num_var[11].nid_value[0].value[0]) << endl;
    //cin.get();
    //there is no point in trying to poll events in a for loop so i disabled it
    //rc_events();
}

void do_119() //I realized that I didn't need this so its here so I can keep numbered order from my initial design
{
}

void loop_120(uint64_t jmp_addr) //not actually used
{
    current_address = jmp_addr;
    //rc_events();
}

void loop_while_121(int n1, uint64_t jmp_addr)
{
    if(vm_n[n1].value != 0)
        current_address = jmp_addr;
    //rc_events();
}

void loop_until_122(int n1, uint64_t jmp_addr)
{
    if(vm_n[n1].value == 0)
        current_address = jmp_addr;
    //rc_events();
}

void pop_loop_stack_123()
{
    loop_stack.pop();
}

void gosub_124(uint64_t sub_addr)
{
    //cout << "gosub" << endl;
    gosub_return_addr.push(current_segment);
    gosub_return_addr.push(current_address);
    current_segment = DATA_SEGMENT;
    current_address = sub_addr;
    //cout << "sub: " << sub_addr << endl;
}

void return_125()
{
    //cout << "\nvar 0 = " << num_var[0].value[0] << endl;
    //cout << "var1 = " << num_var[1].value[0] << endl;
    //cout << "current address = " << current_segment << " : " << current_address << endl;
    current_address = gosub_return_addr.top();
    gosub_return_addr.pop();
    current_segment = gosub_return_addr.top();
    gosub_return_addr.pop();
    //cout << "return to: " << current_segment << " : " << current_address << endl;
}

addr_entry byref_id;

#define BYREF_TYPE_NUM 0
#define BYREF_TYPE_STR 1
#define BYREF_TYPE_USR 2

void ptr_126(uint64_t nid, int n1)
{
    byref_id.ptr_id = nid;
    byref_id.ptr_addr = num_var[nid].nref;
    byref_id.type = BYREF_TYPE_NUM;
    byref_addr_table.push(byref_id);
    byref_var_byref_offset.push(num_var[nid].byref_offset);
    num_var[nid].nref = vm_n[n1].r;
    num_var[nid].byref_offset = vm_n[n1].r_index;
    num_var[nid].nid_value.ref_parent = vm_n[n1].r->ref_parent;
}

void ptrS_127(uint64_t sid, int s1)
{
    byref_id.ptr_id = sid;
    byref_id.ptr_addr = str_var[sid].sref;
    byref_id.type = BYREF_TYPE_STR;
    byref_addr_table.push(byref_id);
    byref_var_byref_offset.push(str_var[sid].byref_offset);
    str_var[sid].sref = vm_s[s1].r;
    str_var[sid].byref_offset = vm_s[s1].r_index;
    str_var[sid].sid_value.ref_parent = vm_s[s1].r->ref_parent;
}

void rc_print_num(double n)
{
    stringstream s;
    s << fixed << n;
    std::string s_out = s.str();
    int s_decimal = s_out.find_first_of(".");
    if(s_decimal != std::string::npos)
    {
        int trail_end = s_out.length();
        for(int i = s_decimal; i < s_out.length(); i++)
        {
            if(s_out[i] != '0')
                trail_end = i+1;
        }
        s_out = s_out.substr(0, trail_end);
        if(s_out.substr(s_out.length()-1,1).compare(".")==0)
            s_out = s_out.substr(0, s_out.length()-1);
    }
    cout << s_out;
}

void print_128(int n1)
{
    rc_print_num(vm_n[n1].value);
}

void printS_129(int s1)
{
    cout << vm_s[s1].value;
}

void rc_push_num(double n_val)
{
    rc_vm_n n;
    n.value = n_val;
    n_stack.push(n);
    //current_n_stack_count++;
}

void rc_push_str(std::string s_val)
{
    rc_vm_s s;
    s.value = s_val;
    s_stack.push(s);
    //current_s_stack_count++;
}

uint64_t rc_string_array_dim(rc_strId* s_var)
{
    rc_strId* s = (rc_strId*)s_var->sid_value.ref_parent;
    return s->dimensions;
}

uint64_t rc_string_array_size(rc_strId* s_var, int d_num)
{
    switch(d_num)
    {
        case 1:
            return s_var->dim[0];
            break;
        case 2:
            return s_var->dim[1];
            break;
        case 3:
            return s_var->dim[2];
            break;
    }
    return 0;
}

uint64_t rc_number_array_dim(rc_numId* n_var)
{
    rc_numId* n = (rc_numId*)n_var->nid_value.ref_parent;
    return n->dimensions;
}

uint64_t rc_type_array_dim(rc_usrId* u_var)
{
    return u_var->dimensions;
}

uint64_t rc_type_array_size(rc_usrId* u_var, int d_num)
{
    switch(d_num)
    {
        case 1:
            return u_var->dim[0];
            break;
        case 2:
            return u_var->dim[1];
            break;
        case 3:
            return u_var->dim[2];
            break;
    }
    return 0;
}

void rc_type_array_copy(rc_usrId* src, rc_usrId* dst)
{
    //cout << "Copy Type" << endl;
    rc_usrId* parent = dst;

    //cout << "freed up" << endl;

    //parent[0] = src[0];

    //cout << "done" << endl;

    //return;


    //cout << "db[1]" << endl;
    parent->dimensions = src->dimensions;
    //cout << "db[2]" << endl;
    parent->dim[0] = src->dim[0];
    parent->dim[1] = src->dim[1];
    parent->dim[2] = src->dim[2];
    //cout << "db[3]" << endl;

    parent->byref_offset = 0;
    //cout << "db[4]" << endl;
    parent->uid_value.resize(src->uid_value.size());
    //cout << "db[5]" << endl;

    parent->var_ref = parent;
    parent->var_ref_index = 0;



    rc_usrId* p_obj;

    uint64_t field_size = 0;

    rc_usrId* s_obj;
    //cout << "starting field: " << endl;

    for(uint64_t i = 0; i < src->uid_value.size(); i++)
    {
        s_obj = &src->uid_value[i];
        p_obj = &parent->uid_value[i];

        p_obj->byref_offset = 0;
        p_obj->byref_ptr = parent;
        p_obj->dim[0] = s_obj->dim[0];
        p_obj->dim[1] = s_obj->dim[1];
        p_obj->dim[2] = s_obj->dim[2];
        p_obj->dimensions = s_obj->dimensions;
        p_obj->preset_init = s_obj->preset_init;
        p_obj->udt_index = s_obj->udt_index;
        p_obj->var_ref = p_obj;
        p_obj->var_ref_index = 0;

        //cout << "num" << endl;
        p_obj->num_var.resize(s_obj->num_var.size());
        for(int nfield = 0; nfield < s_obj->num_var.size(); nfield++)
        {
            p_obj->num_var[nfield] = s_obj->num_var[nfield];
        }

        //cout << "str" << endl;
        p_obj->str_var.resize(s_obj->str_var.size());
        for(int sfield = 0; sfield < s_obj->str_var.size(); sfield++)
        {
            p_obj->str_var[sfield] = s_obj->str_var[sfield];
        }

        //cout << "copy uid field" << endl;
        p_obj->uid_value.resize(s_obj->uid_value.size());
        for(int ufield = 0; ufield < s_obj->uid_value.size(); ufield++)
        {
            rc_type_array_copy(s_obj, p_obj);
        }
    }

    //cout << "done" << endl;

}

void rc_type_array_fill(rc_usrId* src, rc_usrId* fdata)
{
    rc_usrId* p_obj;

    for(int i = 0; i < src->uid_value.size(); i++)
    {
        p_obj = &src->uid_value[i];
        p_obj[0] = fdata[0];
    }

}


uint64_t rc_number_array_size(rc_numId* n_var, int d_num)
{
    switch(d_num)
    {
        case 1:
            return n_var->dim[0];
            break;
        case 2:
            return n_var->dim[1];
            break;
        case 3:
            return n_var->dim[2];
            break;
    }
    return 0;
}

void rc_number_array_copy(rc_numId* n_var, rc_numId* d_var)
{
    uint64_t src_dim, src_dim_size[3];
    rc_numId* src = (rc_numId*)n_var->nid_value.ref_parent;
    src_dim = rc_number_array_dim( src );
    src_dim_size[0] = rc_number_array_size( src, 1);
    src_dim_size[1] = rc_number_array_size( src, 2);
    src_dim_size[2] = rc_number_array_size( src, 3);

    rc_numId* dst = (rc_numId*)d_var->nid_value.ref_parent;

    uint64_t total_size = 0;

    switch(src_dim)
    {
        case 1:
            total_size = src_dim_size[0];
            dst->nref[0].value.resize(total_size);
            //dst->dimensions = 1;
            dst->dim[0] = src_dim_size[0];
            dst->dim[1] = 0;
            dst->dim[2] = 0;
            break;
        case 2:
            total_size = src_dim_size[0] * src_dim_size[1];
            dst->nref[0].value.resize(total_size);
            //dst->dimensions = 2;
            dst->dim[0] = src_dim_size[0];
            dst->dim[1] = src_dim_size[1];
            dst->dim[2] = 0;
            break;
        case 3:
            total_size = src_dim_size[0] * src_dim_size[1] * src_dim_size[2];
            dst->nref[0].value.resize(total_size);
            //dst->dimensions = 3;
            dst->dim[0] = src_dim_size[0];
            dst->dim[1] = src_dim_size[1];
            dst->dim[2] = src_dim_size[2];
            break;
    }

    int si = n_var->byref_offset;
    int di = d_var->byref_offset;

    //cout << "debug: " << si << ", " << di << endl;

    for(; di < total_size; di++)
    {
        dst->nref[0].value[di] = src->nref[0].value[si];

        si++;
    }
}

void rc_string_array_copy(rc_strId* s_var, rc_strId* d_var)
{
    uint64_t src_dim, src_dim_size[3];
    rc_strId* src = (rc_strId*)s_var->sid_value.ref_parent;
    src_dim = rc_string_array_dim( src );
    src_dim_size[0] = rc_string_array_size( src, 1);
    src_dim_size[1] = rc_string_array_size( src, 2);
    src_dim_size[2] = rc_string_array_size( src, 3);

    rc_strId* dst = (rc_strId*)d_var->sid_value.ref_parent;

    uint64_t total_size = 0;

    switch(src_dim)
    {
        case 1:
            total_size = src_dim_size[0];
            dst->sref[0].value.resize(total_size);
            //dst->dimensions = 1;
            dst->dim[0] = src_dim_size[0];
            dst->dim[1] = 0;
            dst->dim[2] = 0;
            break;
        case 2:
            total_size = src_dim_size[0] * src_dim_size[1];
            dst->sref[0].value.resize(total_size);
            //dst->dimensions = 2;
            dst->dim[0] = src_dim_size[0];
            dst->dim[1] = src_dim_size[1];
            dst->dim[2] = 0;
            break;
        case 3:
            total_size = src_dim_size[0] * src_dim_size[1] * src_dim_size[2];
            dst->sref[0].value.resize(total_size);
            //dst->dimensions = 3;
            dst->dim[0] = src_dim_size[0];
            dst->dim[1] = src_dim_size[1];
            dst->dim[2] = src_dim_size[2];
            break;
    }

    int si = s_var->byref_offset;
    int di = d_var->byref_offset;

    //cout << "debug: " << si << ", " << di << endl;

    for(; di < total_size; di++)
    {
        dst->sref[0].value[di] = src->sref[0].value[si];

        si++;
    }
}

void rc_number_array_fill(rc_numId* n_var, double n)
{
    uint64_t src_dim, src_dim_size[3];
    rc_numId* src = (rc_numId*)n_var->nid_value.ref_parent;
    src_dim = rc_number_array_dim( src );
    src_dim_size[0] = rc_number_array_size( src, 1);
    src_dim_size[1] = rc_number_array_size( src, 2);
    src_dim_size[2] = rc_number_array_size( src, 3);

    uint64_t total_size = 0;

    switch(src_dim)
    {
        case 1:
            total_size = src_dim_size[0];
            break;
        case 2:
            total_size = src_dim_size[0] * src_dim_size[1];
            break;
        case 3:
            total_size = src_dim_size[0] * src_dim_size[1] * src_dim_size[2];
            break;
    }

    //cout << "cp 1: " << src->sid_value.value.size() << " " << s_var->byref_offset << endl;

    for(int i = n_var->byref_offset; i < total_size; i++)
    {
        src->nref[0].value[i] = n;
    }
}


void rc_string_array_fill(rc_strId* s_var, std::string s)
{
    uint64_t src_dim, src_dim_size[3];
    rc_strId* src = (rc_strId*)s_var->sid_value.ref_parent;
    src_dim = rc_string_array_dim( src );
    src_dim_size[0] = rc_string_array_size( src, 1);
    src_dim_size[1] = rc_string_array_size( src, 2);
    src_dim_size[2] = rc_string_array_size( src, 3);

    uint64_t total_size = 0;

    switch(src_dim)
    {
        case 1:
            total_size = src_dim_size[0];
            break;
        case 2:
            total_size = src_dim_size[0] * src_dim_size[1];
            break;
        case 3:
            total_size = src_dim_size[0] * src_dim_size[1] * src_dim_size[2];
            break;
    }

    //cout << "cp 1: " << src->sid_value.value.size() << " " << s_var->byref_offset << endl;

    for(int i = s_var->byref_offset; i < total_size; i++)
    {
        src->sref[0].value[i] = s;
    }
}

void func_130(uint64_t fn)
{
    //need to setup a switch statement for all buitlin fucntions here
    switch(fn)
    {
        #include "rc_func130_cases.h"
    }
}

void push_131(double num)
{
    rc_vm_n tmp_n;
    tmp_n.value = num;
    n_stack.push(tmp_n);
    //current_n_stack_count++;
}

void println_132()
{
    cout << endl;
}

void mov_133(int n1, int flag)
{
    switch(flag)
    {
        case LESS_FLAG:
            vm_n[n1].value = CMP_FLAG_LESS;
            break;
        case LESS_EQUAL_FLAG:
            vm_n[n1].value = CMP_FLAG_LESS_EQUAL;
            break;
        case GREATER_FLAG:
            vm_n[n1].value = CMP_FLAG_GREATER;
            break;
        case GREATER_EQUAL_FLAG:
            vm_n[n1].value = CMP_FLAG_GREATER_EQUAL;
            break;
        case EQUAL_FLAG:
            vm_n[n1].value = CMP_FLAG_EQUAL;
            break;
        case NOT_EQUAL_FLAG:
            vm_n[n1].value = CMP_FLAG_NOT_EQUAL;
            break;
    }
    //cout << "n" << n1 << " = " << vm_n[n1].value << endl;
}

void cmp_134(int n1, double num)
{
    CMP_FLAG_EQUAL = (vm_n[n1].value == num);
    CMP_FLAG_GREATER = (vm_n[n1].value > num);
    CMP_FLAG_GREATER_EQUAL = (vm_n[n1].value >= num);
    CMP_FLAG_LESS = (vm_n[n1].value < num);
    CMP_FLAG_LESS_EQUAL = (vm_n[n1].value <= num);
    CMP_FLAG_NOT_EQUAL = (vm_n[n1].value != num);
}

void mov_arr_135(int n1, uint64_t nid)
{
    arr_ref_id.push_back( nid );
    vm_n[n1].r = num_var[nid].nref;
}

void mov_arrS_136(int s1, uint64_t sid)
{
    arr_ref_id.push_back( sid );
    vm_s[s1].r = str_var[sid].sref;
}

void pop_ptr_137(uint64_t n)
{
    //cout << "pop_ptr " << n << endl;
    //cout << "b_stack_size = " << byref_addr_table.size() << endl;
    for(int i = 0; i < n; i++)
    {
        //cout << "byref i = " << i << endl;
        switch(byref_addr_table.top().type)
        {
            case BYREF_TYPE_NUM:
                num_var[byref_addr_table.top().ptr_id].nref = (n_value*)byref_addr_table.top().ptr_addr;
                num_var[byref_addr_table.top().ptr_id].byref_offset = byref_var_byref_offset.top();
                break;
            case BYREF_TYPE_STR:
                str_var[byref_addr_table.top().ptr_id].sref = (s_value*)byref_addr_table.top().ptr_addr;
                str_var[byref_addr_table.top().ptr_id].byref_offset = byref_var_byref_offset.top();
                break;
            case BYREF_TYPE_USR:
                usr_var[byref_addr_table.top().ptr_id].var_ref = (rc_usrId*)byref_addr_table.top().ptr_addr;
                usr_var[byref_addr_table.top().ptr_id].var_ref_index = byref_var_byref_offset.top();
                break;
        }
        byref_addr_table.pop();
        byref_var_byref_offset.pop();
    }
}

void preset_138(uint64_t nid)
{
    int nid_size = 1;
    switch(num_var[nid].dimensions)
    {
        case 3:
            nid_size *= num_var[nid].dim[2];
        case 2:
            nid_size *= num_var[nid].dim[1];
        case 1:
            nid_size *= num_var[nid].dim[0];
            break;
    }
    for(int i = 0; i < nid_size; i++)
        num_var[nid].nref[0].value[i] = 0;
}

void presetS_139(uint64_t sid)
{
    int sid_size = 1;
    switch(str_var[sid].dimensions)
    {
        case 3:
            sid_size *= str_var[sid].dim[2];
        case 2:
            sid_size *= str_var[sid].dim[1];
        case 1:
            sid_size *= str_var[sid].dim[0];
            break;
    }
    for(int i = 0; i < sid_size; i++)
        str_var[sid].sref[0].value[i] = "";
}

void redim_140(uint64_t nid, int n1)
{
    #ifdef RCBASIC_DEBUG
    if(vm_n[n1].value <= 0)
    {
        dbg_error_found = true;
        dbg_error_message = DBG_REDIM_LEQ_ZERO;
        return;
    }
    #endif // RCBASIC_DEBUG
    num_var[nid].nref[0].value.resize((uint64_t)vm_n[n1].value);
    num_var[nid].dimensions = 1;
    num_var[nid].dim[0] = (uint64_t)vm_n[n1].value;
    num_var[nid].dim[1] = 0;
    num_var[nid].dim[2] = 0;
}

void redim_141(uint64_t nid, int n1, int n2)
{
    #ifdef RCBASIC_DEBUG
    if(vm_n[n1].value <= 0 || vm_n[n2].value <= 0)
    {
        dbg_error_found = true;
        dbg_error_message = DBG_REDIM_LEQ_ZERO;
        return;
    }
    #endif // RCBASIC_DEBUG
    num_var[nid].nref[0].value.resize( (uint64_t)vm_n[n1].value * (uint64_t)vm_n[n2].value );
    num_var[nid].dimensions = 2;
    num_var[nid].dim[0] = (uint64_t)vm_n[n1].value;
    num_var[nid].dim[1] = (uint64_t)vm_n[n2].value;
    num_var[nid].dim[2] = 0;
}

void redim_142(uint64_t nid, int n1, int n2, int n3)
{
    #ifdef RCBASIC_DEBUG
    if(vm_n[n1].value <= 0 || vm_n[n2].value <= 0 || vm_n[n3].value <= 0)
    {
        dbg_error_found = true;
        dbg_error_message = DBG_REDIM_LEQ_ZERO;
        return;
    }
    #endif // RCBASIC_DEBUG
    num_var[nid].nref[0].value.resize( (uint64_t)vm_n[n1].value * (uint64_t)vm_n[n2].value * (uint64_t)vm_n[n3].value);
    num_var[nid].dimensions = 3;
    num_var[nid].dim[0] = (uint64_t)vm_n[n1].value;
    num_var[nid].dim[1] = (uint64_t)vm_n[n2].value;
    num_var[nid].dim[2] = (uint64_t)vm_n[n3].value;
}

void redimS_143(uint64_t sid, int n1)
{
    #ifdef RCBASIC_DEBUG
    if(vm_n[n1].value <= 0)
    {
        dbg_error_found = true;
        dbg_error_message = DBG_REDIM_LEQ_ZERO;
        return;
    }
    #endif // RCBASIC_DEBUG
    str_var[sid].sref[0].value.resize((uint64_t)vm_n[n1].value);
    str_var[sid].dimensions = 1;
    str_var[sid].dim[0] = (uint64_t)vm_n[n1].value;
    str_var[sid].dim[1] = 0;
    str_var[sid].dim[2] = 0;
}

void redimS_144(uint64_t sid, int n1, int n2)
{
    #ifdef RCBASIC_DEBUG
    if(vm_n[n1].value <= 0 || vm_n[n2].value <= 0)
    {
        dbg_error_found = true;
        dbg_error_message = DBG_REDIM_LEQ_ZERO;
        return;
    }
    #endif // RCBASIC_DEBUG
    str_var[sid].sref[0].value.resize( (uint64_t)vm_n[n1].value * (uint64_t)vm_n[n2].value );
    str_var[sid].dimensions = 2;
    str_var[sid].dim[0] = (uint64_t)vm_n[n1].value;
    str_var[sid].dim[1] = (uint64_t)vm_n[n2].value;
    str_var[sid].dim[2] = 0;
}

void redimS_145(uint64_t sid, int n1, int n2, int n3)
{
    #ifdef RCBASIC_DEBUG
    if(vm_n[n1].value <= 0 || vm_n[n2].value <= 0 || vm_n[n3].value <= 0)
    {
        dbg_error_found = true;
        dbg_error_message = DBG_REDIM_LEQ_ZERO;
        return;
    }
    #endif // RCBASIC_DEBUG
    str_var[sid].sref[0].value.resize( (uint64_t)vm_n[n1].value * (uint64_t)vm_n[n2].value * (uint64_t)vm_n[n3].value);
    str_var[sid].dimensions = 3;
    str_var[sid].dim[0] = (uint64_t)vm_n[n1].value;
    str_var[sid].dim[1] = (uint64_t)vm_n[n2].value;
    str_var[sid].dim[2] = (uint64_t)vm_n[n3].value;
}

void for_offset_arr1_146(int n1)
{
    for_offset_index[0] = vm_n[n1].value;
    for_offset_dimensions = 1;
}

void for_offset_arr2_147(int n1, int n2)
{
    for_offset_index[0] = vm_n[n1].value;
    for_offset_index[1] = vm_n[n2].value;
    for_offset_dimensions = 2;
}

void for_offset_arr3_148(int n1, int n2, int n3)
{
    for_offset_index[0] = vm_n[n1].value;
    for_offset_index[1] = vm_n[n2].value;
    for_offset_index[2] = vm_n[n3].value;
    for_offset_dimensions = 3;
}

void for_offset_0_149()
{
    for_offset_dimensions = 0;
}

void end_x_150(int n1)
{
    rcbasic_exit_code = (int)vm_n[n1].value;
}

void lval_151(int n1)
{
    //cout << "lval_151 = " << vm_n[n1].value << endl;
}

void lval_152(uint64_t nid)
{
    //cout << "lval_152 = " << num_var[nid].nid_value[0].value[0] << endl;
}

void lval_153(uint64_t lval_addr )
{
    //cout << "lval_153 = " << lval_addr << endl;
}

void lval_154(int s1)
{
    //cout << "lval_154 = " << vm_s[s1].value << endl;
}

void lval_155(uint64_t sid)
{
    //cout << "lval_155 = " << str_var[sid].sid_value[0].value[0] << endl;
}

void obj_usr_n_156(uint64_t nid)
{
    //cout << "obj_usr_n start" << endl;
    usr_object.num_ref = &usr_object.obj_ref->num_var[nid];
    usr_object.num_ref->nref = &usr_object.num_ref->nid_value;
    usr_object.index = 0;
    //cout << "obj_usr_n done" << endl;
}

void obj_usr_n1_157(uint64_t nid, int n1)
{
    usr_object.num_ref = &usr_object.obj_ref->num_var[nid];
    usr_object.num_ref->nref = &usr_object.num_ref->nid_value;
    usr_object.index = (uint64_t)vm_n[n1].value;
}

void obj_usr_n2_158(uint64_t nid, int n1, int n2)
{
    usr_object.num_ref = &usr_object.obj_ref->num_var[nid];
    usr_object.num_ref->nref = &usr_object.num_ref->nid_value;
    usr_object.index = (uint64_t)vm_n[n1].value * usr_object.num_ref->dim[1] + (uint64_t)vm_n[n2].value;
}

void obj_usr_n3_159(uint64_t nid, int n1, int n2, int n3)
{
    usr_object.num_ref = &usr_object.obj_ref->num_var[nid];
    usr_object.num_ref->nref = &usr_object.num_ref->nid_value;
    usr_object.index = ((uint64_t)vm_n[n1].value * usr_object.num_ref->dim[1] * usr_object.num_ref->dim[2]) + ( (uint64_t)vm_n[n2].value * usr_object.num_ref->dim[2]) + (uint64_t)vm_n[n3].value;
}


void obj_usr_s_160(uint64_t sid)
{
    usr_object.str_ref = &usr_object.obj_ref->str_var[sid];
    usr_object.str_ref->sref = &usr_object.str_ref->sid_value;
    usr_object.index = 0;
}

void obj_usr_s1_161(uint64_t sid, int n1)
{
    usr_object.str_ref = &usr_object.obj_ref->str_var[sid];
    usr_object.str_ref->sref = &usr_object.str_ref->sid_value;
    usr_object.index = (uint64_t)vm_n[n1].value;
}

void obj_usr_s2_162(uint64_t sid, int n1, int n2)
{
    usr_object.str_ref = &usr_object.obj_ref->str_var[sid];
    usr_object.str_ref->sref = &usr_object.str_ref->sid_value;
    usr_object.index = (uint64_t)vm_n[n1].value * usr_object.str_ref->dim[1] + (uint64_t)vm_n[n2].value;
}

void obj_usr_s3_163(uint64_t sid, int n1, int n2, int n3)
{
    usr_object.str_ref = &usr_object.obj_ref->str_var[sid];
    usr_object.str_ref->sref = &usr_object.str_ref->sid_value;
    usr_object.index = ((uint64_t)vm_n[n1].value * usr_object.str_ref->dim[1] * usr_object.str_ref->dim[2]) + ( (uint64_t)vm_n[n2].value * usr_object.str_ref->dim[2]) + (uint64_t)vm_n[n3].value;
}

void obj_usr_get_164(int n1)
{
    //cout << "obj_usr_get_N start" << endl;
    vm_n[n1].value = usr_object.num_ref->nref[0].value[usr_object.index];
    vm_n[n1].r = usr_object.num_ref->nref;
    vm_n[n1].r_index = usr_object.index;

    usr_object.num_ref->nid_value.ref_parent = usr_object.num_ref;
    //cout << "obj_usr_get_N done: " << vm_n[n1].r[0].value[vm_n[n1].r_index] << endl;
}

void obj_usr_get_165(int s1)
{
    vm_s[s1].value = usr_object.str_ref->sref[0].value[usr_object.index];
    vm_s[s1].r = usr_object.str_ref->sref;
    vm_s[s1].r_index = usr_object.index;

    usr_object.str_ref->sid_value.ref_parent = usr_object.str_ref;
    //cout << "obj_usr_get -- " << usr_object.str_ref->dimensions << " --> " << usr_object.str_ref->dim[0] << ", " << usr_object.str_ref->dim[1] << endl;
}

void obj_usr_get_166(int u1)
{
    //cout << "obj_usr_get start  u" << u1 << endl;
    //rc_usrId * tmp_usr_id = usr_object.obj_ref->byref_ptr;
    //cout << "tmp check = " << usr_object.obj_ref->byref_ptr->dimensions << endl;

    rc_free_type(&vm_u[u1]); //this should free any memory previously allocated in u1

    //cout << "tmp check[2] = " << usr_object.obj_ref->byref_ptr->dimensions << endl;

    //cout << "mem free: " << usr_object.obj_ref->dimensions << endl;
    vm_u[u1] = usr_object.obj_ref[0];
    //cout << "1: " << usr_object.obj_ref[0].uid_value.size() << endl;
    vm_u[u1].var_ref = usr_object.obj_ref;
    //cout << "2" << endl;
    vm_u[u1].var_ref_index = usr_object.index; //usr_object.index;

    //cout << "obj_usr_get end" << endl;

    //cout << "tmp check[3] = " << vm_u[u1].var_ref->byref_ptr->dimensions << endl;

    //cout << "bcheck = " << tmp_usr_id->dimensions << endl;
}

void uref_ptr_167(uint64_t uid, int u1)
{
    //cout << "<--------UREF-------> : " << uid << " " << u1 << endl;
    byref_id.ptr_id = uid;
    byref_id.ptr_addr = usr_var[uid].var_ref;
    byref_id.type = BYREF_TYPE_USR;
    byref_addr_table.push(byref_id);
    byref_var_byref_offset.push(usr_var[uid].var_ref_index);

    //cout << "start index = " << usr_var[uid].var_ref_index << endl;

    int i = vm_u[u1].var_ref_index;

    usr_var[uid].var_ref = vm_u[u1].var_ref->byref_ptr;
    usr_var[uid].var_ref_index = i; //vm_u[u1].var_ref_index;

    //int i = vm_u[u1].var_ref_index;
    //cout << "index = " << usr_var[uid].var_ref_index << endl;
    //cout << "uref end: " << usr_var[uid].var_ref->uid_value.size() << endl;
    //cout << "debug out = " << usr_var[uid].var_ref->uid_value[i].str_var[0].sid_value.value[3] << endl;
}

void mov_type_168(uint64_t uid, int u1)
{
    //cout << "mov_type " << uid << " " << u1 << endl;
    //cout << "dbg[var_ref] : " << vm_u[u1].var_ref[0].uid_value.size() << endl;
    rc_free_type(&usr_var[uid]);
    //usr_var[uid].uid_value.resize(1);
    //cout << "dbg[usr_var]: " << usr_var[uid].uid_value.size() << endl;
    usr_var[uid].uid_value.push_back(vm_u[u1]);
    usr_var[uid].var_ref = &usr_var[uid];
    usr_var[uid].var_ref_index = 0;
    //cout << "mov_type end" << endl;
}

void push_t_169(int u1)
{
    //cout << "push_t u" << u1 << " :: " << vm_u[u1].uid_value.size() << endl;
    u_stack.push(vm_u[u1]);
    //cout << "push_t end" << endl;
}

void push_t_170(uint64_t uid)
{
    u_stack.push(usr_var[uid]);
}

void pop_t_171(int u1)
{
    //cout << "pop_t u" << u1 << " :: " << vm_u[u1].uid_value.size() << endl;
    rc_free_type(&vm_u[u1]);
    vm_u[u1] = u_stack.top();
    //cout << "test: " << vm_u[u1].var_ref->uid_value.size() << endl;
    u_stack.pop();
}

void pop_t_172(uint64_t uid)
{
    //cout << "pop_T  USER" << endl;
    rc_free_type(usr_var[uid].var_ref);
    usr_var[uid].var_ref[0] = u_stack.top();
    u_stack.pop();
}

void push_t_null_173()
{
    //I will need to do something with this
}

void delete_t_174(uint64_t oid, uint64_t top_level_flag, uint64_t obj_type)
{
    //cout << "DEBUG: " << oid << ", " << top_level_flag << ", " << obj_type << endl;
    //cout << "Delete Object: " << usr_object.obj_ref->str_var[1].dim[0] << endl;
    if(top_level_flag == 0)
    {
        //cout << "[START] USR TL: " << usr_var[oid].uid_value[0].str_var.size() << endl;
        rc_free_type(&usr_var[oid]);
        //cout << "[END]   USR TL: " << usr_var[oid].uid_value[0].str_var.size() << endl;
    }
    else
    {
        switch(obj_type)
        {
            case 0:
                //cout << "DBG NDATA: " << usr_object.obj_ref->num_var[oid].dim[0] << endl;
                usr_object.obj_ref->num_var[oid].nid_value.value.clear();
                usr_object.obj_ref->num_var[oid].nid_value.value.shrink_to_fit();
                usr_object.obj_ref->num_var[oid].dimensions = 0;
                usr_object.obj_ref->num_var[oid].dim[0] = 0;
                usr_object.obj_ref->num_var[oid].dim[1] = 0;
                usr_object.obj_ref->num_var[oid].dim[2] = 0;
                break;

            case 1:
                //cout << "DBG SDATA: " << usr_object.obj_ref->str_var[oid].dim[0] << endl;
                usr_object.obj_ref->str_var[oid].sid_value.value.clear();
                usr_object.obj_ref->str_var[oid].sid_value.value.shrink_to_fit();
                usr_object.obj_ref->str_var[oid].dimensions = 0;
                usr_object.obj_ref->str_var[oid].dim[0] = 0;
                usr_object.obj_ref->str_var[oid].dim[1] = 0;
                usr_object.obj_ref->str_var[oid].dim[2] = 0;
                break;

            case 2:
                //cout << "DBG UDATA: " << usr_object.obj_ref->uid_value[oid].dim[0] << endl;
                rc_free_type(&usr_object.obj_ref->uid_value[oid]);
                break;
        }
    }
    //cout << "Done" << endl;
}

void dim_type_175(int u1, int udt_index)
{
    rc_free_type(&vm_u[u1]);
    rc_dim_type(&vm_u[u1], udt_index, 0, 0, 0, 0 );
}

void dim_type1_176(int u1, int udt_index, int n1)
{
    rc_free_type(&vm_u[u1]);
    rc_dim_type(&vm_u[u1], udt_index, 1, (uint64_t)vm_n[n1].value, 0, 0 );
}

void dim_type2_177(int u1, int udt_index, int n1, int n2)
{
    rc_free_type(&vm_u[u1]);
    rc_dim_type(&vm_u[u1], udt_index, 2, (uint64_t)vm_n[n1].value, (uint64_t)vm_n[n2].value, 0 );
}

void dim_type3_178(int u1, int udt_index, int n1, int n2, int n3)
{
    rc_free_type(&vm_u[u1]);
    rc_dim_type(&vm_u[u1], udt_index, 3, (uint64_t)vm_n[n1].value, (uint64_t)vm_n[n2].value, (uint64_t)vm_n[n3].value );
}

void dim_tfield_179(uint64_t udt_index, uint64_t field_type, uint64_t field_index, int num_dim, int n1, int n2, int n3)
{
    //cout << "DimTField " << udt_index << " " << field_type << " " << field_index << " " << num_dim << " " << (uint64_t)vm_n[n1].value << " " << (uint64_t)vm_n[n2].value << " " << (uint64_t)vm_n[n3].value << endl;
    rc_types[udt_index].field_dimensions[field_index] = num_dim;
    rc_types[udt_index].field_size[field_index].dim[0] = (uint64_t)vm_n[n1].value;
    rc_types[udt_index].field_size[field_index].dim[1] = (uint64_t)vm_n[n2].value;
    rc_types[udt_index].field_size[field_index].dim[2] = (uint64_t)vm_n[n3].value;
    //cout << "DimTField End" << endl;
}

void obj_usr_init_180(uint64_t uid)
{
    //cout << "obj_usr_init " << uid << endl;
    usr_object.index = 0;

    usr_object.index += usr_var[uid].var_ref_index;

    usr_object.obj_ref = &usr_var[uid].var_ref->uid_value[usr_object.index]; //need to switch to var_ref
    //cout << "obj_usr_init done: " << usr_object.obj_ref[0].uid_value.size() << endl;

    usr_object.obj_ref->byref_ptr = usr_var[uid].var_ref;
}

void obj_usr_init1_181(uint64_t uid, int n1)
{
    //cout << "obj_usr_init1 " << uid << endl;
    usr_object.index = (uint64_t)vm_n[n1].value;

    usr_object.index += usr_var[uid].var_ref_index;

    usr_object.obj_ref = &usr_var[uid].var_ref->uid_value[usr_object.index];

    usr_object.obj_ref->byref_ptr = usr_var[uid].var_ref;
}

void obj_usr_init2_182(uint64_t uid, int n1, int n2)
{
    //uint64_t d[3];
    //d[0] = usr_var[uid].dim[0];
    //d[1] = usr_var[uid].dim[1];
    //d[2] = usr_var[uid].dim[2];
    //cout << "obj_usr_init2: " << uid << "  --dim=[" << d[0] << ", " << d[1] << ", " << d[2] << "]" << endl;
    usr_object.index = (uint64_t)vm_n[n1].value * usr_var[uid].dim[1] + (uint64_t)vm_n[n2].value;

    usr_object.index += usr_var[uid].var_ref_index;

    usr_object.obj_ref = &usr_var[uid].var_ref->uid_value[usr_object.index];

    usr_object.obj_ref->byref_ptr = usr_var[uid].var_ref;

    //cout << "dimbr = " << uid << " " << n1 << " " << n2 << " " << usr_object.obj_ref->byref_ptr->dimensions << endl;
    //cout << "d2_dbg = " << usr_var[uid].var_ref->uid_value.size() << " --- " << usr_object.index << endl;
}

void obj_usr_init3_183(uint64_t uid, int n1, int n2, int n3)
{
    //cout << "obj_usr_init3 " << uid << endl;
    usr_object.index = ( (uint64_t)vm_n[n1].value * usr_var[uid].dim[1] * usr_var[uid].dim[2] ) + ((uint64_t)vm_n[n2].value * usr_var[uid].dim[2]) + (uint64_t)vm_n[n3].value;;

    usr_object.index += usr_var[uid].var_ref_index;

    usr_object.obj_ref = &usr_var[uid].var_ref->uid_value[usr_object.index];

    usr_object.obj_ref->byref_ptr = usr_var[uid].var_ref;
}


void obj_usr_init_184(int u1)
{
    //cout << "obj_usr_init u" << u1 << endl;
    usr_object.index = 0;
    usr_object.obj_ref = &vm_u[u1]; //need to switch to var_ref
    usr_object.obj_ref->var_ref = usr_object.obj_ref;
    //cout << "obj_usr_init done: " << usr_object.obj_ref->var_ref[0].uid_value.size() << " ~ " << vm_u[u1].uid_value.size() << endl;
}

void obj_usr_init1_185(int u1, int n1)
{
    //cout << "obj_usr_init1 u" << u1 << endl;
    usr_object.index = (uint64_t)vm_n[n1].value;
    usr_object.obj_ref = &vm_u[u1].var_ref->uid_value[usr_object.index];
}

void obj_usr_init2_186(int u1, int n1, int n2)
{
    uint64_t d[3];
    //cout << "obj_usr_init2: u" << u1 << "  --dim=[" << d[0] << ", " << d[1] << ", " << d[2] << "]" << endl;
    usr_object.index = (uint64_t)vm_n[n1].value * vm_u[u1].dim[1] + (uint64_t)vm_n[n2].value;
    usr_object.obj_ref = &vm_u[u1].var_ref->uid_value[usr_object.index];
}

void obj_usr_init3_187(int u1, int n1, int n2, int n3)
{
    //cout << "obj_usr_init3 u" << u1 << endl;
    usr_object.index = ( (uint64_t)vm_n[n1].value * vm_u[u1].dim[1] * vm_u[u1].dim[2] ) + ((uint64_t)vm_n[n2].value * vm_u[u1].dim[2]) + (uint64_t)vm_n[n3].value;;
    usr_object.obj_ref = &vm_u[u1].var_ref->uid_value[usr_object.index];
}





bool rc_preset_type(rc_usrId* parent)
{
    uint64_t dim_size = parent->uid_value.size();


    rc_usrId* p_obj;

    uint64_t field_size = 0;

    for(uint64_t i = 0; i < dim_size; i++)
    {
        p_obj = &parent->uid_value[i];

        for(uint64_t n_field = 0; n_field < p_obj->num_var.size(); n_field++)
        {
            for(uint64_t nv = 0; nv < p_obj->num_var[n_field].nid_value.value.size(); nv++)
                p_obj->num_var[n_field].nid_value.value[nv] = 0;
        }

        for(uint64_t s_field = 0; s_field < p_obj->str_var.size(); s_field++)
        {
            for(uint64_t sv = 0; sv < p_obj->str_var[s_field].sid_value.value.size(); sv++)
                p_obj->str_var[s_field].sid_value.value[sv] = "";
        }

        for(uint64_t u_field = 0; u_field < p_obj->uid_value.size(); u_field++)
        {
            rc_preset_type(&p_obj->uid_value[u_field]);
        }
    }

    return true;
}

void preset_t_188(uint64_t uid, uint64_t utype)
{
    //cout << "T0" << endl;
    if(!usr_var[uid].preset_init)
    {
        rc_free_type(&usr_var[uid]);
        dim_type_90(uid, utype);
        usr_var[uid].preset_init = true;
    }
    else
    {
        rc_preset_type(&usr_var[uid]);
    }
}

void preset_t1_189(uint64_t uid, uint64_t utype, int n1)
{
    //cout << "T1" << endl;
    if(!usr_var[uid].preset_init)
    {
        rc_free_type(&usr_var[uid]);
        dim_type1_91(uid, utype, n1);
        usr_var[uid].preset_init = true;
    }
    else
    {
        rc_preset_type(&usr_var[uid]);
    }
}

void preset_t2_190(uint64_t uid, uint64_t utype, int n1, int n2)
{
    //cout << "T2" << endl;
    if(!usr_var[uid].preset_init)
    {
        rc_free_type(&usr_var[uid]);
        dim_type2_92(uid, utype, n1, n2);
        usr_var[uid].preset_init = true;
    }
    else
    {
        rc_preset_type(&usr_var[uid]);
    }
}

void preset_t3_191(uint64_t uid, uint64_t utype, int n1, int n2, int n3)
{
    //cout << "T3" << endl;
    if(!usr_var[uid].preset_init)
    {
        rc_free_type(&usr_var[uid]);
        dim_type3_93(uid, utype, n1, n2, n3);
        usr_var[uid].preset_init = true;
    }
    else
    {
        rc_preset_type(&usr_var[uid]);
    }
}


void redim_type_192(int u1, int udt_index)
{
    // Currently unused
}

void redim_type1_193(int u1, int udt_index, int n1)
{
    // Currently unused
}

void redim_type2_194(int u1, int udt_index, int n1, int n2)
{
    // Currently unused
}

void redim_type3_195(int u1, int udt_index, int n1, int n2, int n3)
{
    // Currently unused
}


void redim_type_n_196(uint64_t nid)
{
    usr_object.obj_ref->num_var[nid].nid_value.value.resize(1);
    usr_object.obj_ref->num_var[nid].dimensions = 0;
    usr_object.obj_ref->num_var[nid].dim[0] = 0;
    usr_object.obj_ref->num_var[nid].dim[1] = 0;
    usr_object.obj_ref->num_var[nid].dim[2] = 0;
}

void redim_type_n1_197(uint64_t nid, int n1)
{
    usr_object.obj_ref->num_var[nid].nid_value.value.resize((uint64_t)vm_n[n1].value);
    usr_object.obj_ref->num_var[nid].dimensions = 1;
    usr_object.obj_ref->num_var[nid].dim[0] = (uint64_t)vm_n[n1].value;
    usr_object.obj_ref->num_var[nid].dim[1] = 0;
    usr_object.obj_ref->num_var[nid].dim[2] = 0;
}

void redim_type_n2_198(uint64_t nid, int n1, int n2)
{
    usr_object.obj_ref->num_var[nid].nid_value.value.resize((uint64_t)(vm_n[n1].value * vm_n[n2].value));
    usr_object.obj_ref->num_var[nid].dimensions = 2;
    usr_object.obj_ref->num_var[nid].dim[0] = (uint64_t)vm_n[n1].value;
    usr_object.obj_ref->num_var[nid].dim[1] = (uint64_t)vm_n[n2].value;
    usr_object.obj_ref->num_var[nid].dim[2] = 0;
}

void redim_type_n3_199(uint64_t nid, int n1, int n2, int n3)
{
    usr_object.obj_ref->num_var[nid].nid_value.value.resize((uint64_t)(vm_n[n1].value * vm_n[n2].value * vm_n[n3].value));
    usr_object.obj_ref->num_var[nid].dimensions = 3;
    usr_object.obj_ref->num_var[nid].dim[0] = (uint64_t)vm_n[n1].value;
    usr_object.obj_ref->num_var[nid].dim[1] = (uint64_t)vm_n[n2].value;
    usr_object.obj_ref->num_var[nid].dim[2] = (uint64_t)vm_n[n3].value;
}


void redim_type_s_200(uint64_t sid)
{
    usr_object.obj_ref->str_var[sid].sid_value.value.resize(1);
    usr_object.obj_ref->str_var[sid].dimensions = 0;
    usr_object.obj_ref->str_var[sid].dim[0] = 0;
    usr_object.obj_ref->str_var[sid].dim[1] = 0;
    usr_object.obj_ref->str_var[sid].dim[2] = 0;
}

void redim_type_s1_201(uint64_t sid, int n1)
{
    usr_object.obj_ref->str_var[sid].sid_value.value.resize((uint64_t)vm_n[n1].value);
    usr_object.obj_ref->str_var[sid].dimensions = 1;
    usr_object.obj_ref->str_var[sid].dim[0] = (uint64_t)vm_n[n1].value;
    usr_object.obj_ref->str_var[sid].dim[1] = 0;
    usr_object.obj_ref->str_var[sid].dim[2] = 0;
}

void redim_type_s2_202(uint64_t sid, int n1, int n2)
{
    usr_object.obj_ref->str_var[sid].sid_value.value.resize((uint64_t)(vm_n[n1].value * vm_n[n2].value));
    usr_object.obj_ref->str_var[sid].dimensions = 2;
    usr_object.obj_ref->str_var[sid].dim[0] = (uint64_t)vm_n[n1].value;
    usr_object.obj_ref->str_var[sid].dim[1] = (uint64_t)vm_n[n2].value;
    usr_object.obj_ref->str_var[sid].dim[2] = 0;
}

void redim_type_s3_203(uint64_t sid, int n1, int n2, int n3)
{
    usr_object.obj_ref->str_var[sid].sid_value.value.resize((uint64_t)(vm_n[n1].value * vm_n[n2].value * vm_n[n3].value));
    usr_object.obj_ref->str_var[sid].dimensions = 3;
    usr_object.obj_ref->str_var[sid].dim[0] = (uint64_t)vm_n[n1].value;
    usr_object.obj_ref->str_var[sid].dim[1] = (uint64_t)vm_n[n2].value;
    usr_object.obj_ref->str_var[sid].dim[2] = (uint64_t)vm_n[n3].value;
}

void redim_type_204(uint64_t uid, int udt_index)
{
    if(redim_toplevel_flag)
        rc_dim_type(&usr_var[uid], udt_index, 0, 0, 0, 0, 0);
    else
        rc_dim_type(&usr_object.obj_ref->uid_value[uid], udt_index, 0, 0, 0, 0, 0);

    redim_toplevel_flag = false;
}

void redim_type1_205(uint64_t uid, int udt_index, int n1)
{
    if(redim_toplevel_flag)
        rc_dim_type(&usr_var[uid], udt_index, 1, (uint64_t)vm_n[n1].value, 0, 0, usr_var[uid].uid_value.size());
    else
        rc_dim_type(&usr_object.obj_ref->uid_value[uid], udt_index, 1, (uint64_t)vm_n[n1].value, 0, 0, usr_object.obj_ref->uid_value[uid].uid_value.size());

    redim_toplevel_flag = false;
}

void redim_type2_206(uint64_t uid, int udt_index, int n1, int n2)
{
    if(redim_toplevel_flag)
        rc_dim_type(&usr_var[uid], udt_index, 2, (uint64_t)vm_n[n1].value, (uint64_t)vm_n[n2].value, 0, usr_var[uid].uid_value.size());
    else
        rc_dim_type(&usr_object.obj_ref->uid_value[uid], udt_index, 2, (uint64_t)vm_n[n1].value, (uint64_t)vm_n[n2].value, 0, usr_object.obj_ref->uid_value[uid].uid_value.size());

    //cout << "test tl: " << redim_toplevel_flag << " -- " << usr_var[uid].uid_value.size() << endl;

    redim_toplevel_flag = false;
}

void redim_type3_207(uint64_t uid, int udt_index, int n1, int n2, int n3)
{
    if(redim_toplevel_flag)
        rc_dim_type(&usr_var[uid], udt_index, 3, (uint64_t)vm_n[n1].value, (uint64_t)vm_n[n2].value, (uint64_t)vm_n[n3].value, usr_var[uid].uid_value.size());
    else
        rc_dim_type(&usr_object.obj_ref->uid_value[uid], udt_index, 3, (uint64_t)vm_n[n1].value, (uint64_t)vm_n[n2].value, (uint64_t)vm_n[n3].value, usr_object.obj_ref->uid_value[uid].uid_value.size());

    redim_toplevel_flag = false;
}

void redim_top_208()
{
    redim_toplevel_flag = true;
}


bool rcbasic_run()
{
    unsigned char rcbasic_cmd;
    double d[12];
    uint64_t i[12];
    bool end_of_program = false;
    while(!end_of_program)
    {
        #ifdef RCBASIC_DEBUG
        if(dbg_error_found)
        {
            output_debug_message();
            break;
        }
        #endif // RCBASIC_DEBUG

        rcbasic_cmd = segment[current_segment][current_address];
        current_address++;

        //cout << "n3 = " << vm_n[3].value << endl;
        //cout << "x = " << num_var[0].value[0] << endl;
        //cout << "\ncmd = " << (int)rcbasic_cmd << endl;

        switch(rcbasic_cmd)
        {
            case 0:
                end_of_program = true;
                rcbasic_exit_code = 0;
                break;
            case 1:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                dbg_1(i[0], i[1], i[2]);
                break;
            case 32:
                i[0] = readInt();
                i[1] = readInt();
                mov_32(i[0], i[1]);
                break;
            case 33:
                i[0] = readInt();
                d[0] = readDouble();
                mov_33(i[0], d[0]);
                break;
            case 34:
                i[0] = readInt();
                i[1] = readInt();
                mov_34(i[0], i[1]);
                break;
            case 35:
                i[0] = readInt();
                i[1] = readInt();
                //cout << "mov_35 x is " << i[0] << endl;
                //cout << "mov_35 is using n" << i[1] << endl;
                mov_35(i[0], i[1]);
                break;
            case 36:
                i[0] = readInt();
                i[1] = readInt();
                movS_36(i[0], i[1]);
                break;
            case 37:
                i[0] = readInt();
                i[1] = readInt();
                movS_37(i[0], i[1]);
                break;
            case 38:
                i[0] = readInt();
                i[1] = readInt();
                movS_38(i[0], i[1]);
                break;
            case 39:
                i[0] = readInt();
                i[1] = readInt();
                movS_39(i[0], i[1]);
                break;
            case 40:
                i[0] = readInt();
                i[1] = readInt();
                mov_r_40(i[0], i[1]);
                break;
            case 41:
                i[0] = readInt();
                i[1] = readInt();
                mov_rS_41(i[0], i[1]);
                break;
            case 42:
                i[0] = readInt();
                i[1] = readInt();
                mov_type_42(i[0], i[1]);
                break;
            case 43:
                i[0] = readInt();
                i[1] = readInt();
                addS_43(i[0], i[1]);
                break;
            case 44:
                i[0] = readInt();
                i[1] = readInt();
                add_44(i[0], i[1]);
                break;
            case 45:
                i[0] = readInt();
                i[1] = readInt();
                sub_45(i[0], i[1]);
                break;
            case 46:
                i[0] = readInt();
                i[1] = readInt();
                mul_46(i[0], i[1]);
                break;
            case 47:
                i[0] = readInt();
                i[1] = readInt();
                div_47(i[0], i[1]);
                break;
            case 48:
                i[0] = readInt();
                i[1] = readInt();
                pow_48(i[0], i[1]);
                break;
            case 49:
                i[0] = readInt();
                i[1] = readInt();
                mod_49(i[0], i[1]);
                break;
            case 50:
                i[0] = readInt();
                i[1] = readInt();
                shl_50(i[0], i[1]);
                break;
            case 51:
                i[0] = readInt();
                i[1] = readInt();
                shr_51(i[0], i[1]);
                break;
            case 52:
                i[0] = readInt();
                i[1] = readInt();
                and_52(i[0], i[1]);
                break;
            case 53:
                i[0] = readInt();
                i[1] = readInt();
                or_53(i[0], i[1]);
                break;
            case 54:
                i[0] = readInt();
                i[1] = readInt();
                xor_54(i[0], i[1]);
                break;
            case 55:
                i[0] = readInt();
                not_55(i[0]);
                break;
            case 56:
                i[0] = readInt();
                i[1] = readInt();
                cmp_56(i[0], i[1]);
                break;
            case 57:
                i[0] = readInt();
                i[1] = readInt();
                cmpS_57(i[0], i[1]);
                break;
            case 58:
                i[0] = readInt();
                i[1] = readInt();
                cmp_u_58(i[0], i[1]);
                break;
            case 59:
                i[0] = readInt();
                jmp_59(i[0]);
                break;
            case 60:
                i[0] = readInt();
                jmp_60(i[0]);
                break;
            case 61:
                i[0] = readInt();
                je_61(i[0]);
                break;
            case 62:
                i[0] = readInt();
                je_62(i[0]);
                break;
            case 63:
                i[0] = readInt();
                jne_63(i[0]);
                break;
            case 64:
                i[0] = readInt();
                jne_64(i[0]);
                break;
            case 65:
                i[0] = readInt();
                jg_65(i[0]);
                break;
            case 66:
                i[0] = readInt();
                jg_66(i[0]);
                break;
            case 67:
                i[0] = readInt();
                jge_67(i[0]);
                break;
            case 68:
                i[0] = readInt();
                jge_68(i[0]);
                break;
            case 69:
                i[0] = readInt();
                jl_69(i[0]);
                break;
            case 70:
                i[0] = readInt();
                jl_70(i[0]);
                break;
            case 71:
                i[0] = readInt();
                jle_71(i[0]);
                break;
            case 72:
                i[0] = readInt();
                jle_72(i[0]);
                break;
            case 73:
                i[0] = readInt();
                obj_num_73(i[0]);
                break;
            case 74:
                i[0] = readInt();
                i[1] = readInt();
                obj_num1_74(i[0], i[1]);
                break;
            case 75:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                obj_num2_75(i[0], i[1], i[2]);
                break;
            case 76:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                i[3] = readInt();
                obj_num3_76(i[0], i[1], i[2], i[3]);
                break;
            case 77:
                i[0] = readInt();
                obj_str_77(i[0]);
                break;
            case 78:
                i[0] = readInt();
                i[1] = readInt();
                obj_str1_78(i[0], i[1]);
                break;
            case 79:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                obj_str2_79(i[0], i[1], i[2]);
                break;
            case 80:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                i[3] = readInt();
                obj_str3_80(i[0], i[1], i[2], i[3]);
                break;
            case 81:
                i[0] = readInt();
                obj_usr_81(i[0]);
                break;
            case 82:
                i[0] = readInt();
                i[1] = readInt();
                obj_usr1_82(i[0], i[1]);
                break;
            case 83:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                obj_usr2_83(i[0], i[1], i[2]);
                break;
            case 84:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                i[3] = readInt();
                obj_usr3_84(i[0], i[1], i[2], i[3]);
                break;
            case 85:
                i[0] = readInt();
                obj_get_85(i[0]);
                break;
            case 86:
                i[0] = readInt();
                obj_getS_86(i[0]);
                break;
            case 87:
                i[0] = readInt();
                obj_set_87(i[0]);
                break;
            case 88:
                i[0] = readInt();
                obj_setS_88(i[0]);
                break;
            case 89:
                clear_obj_89();
                break;
            case 90:
                i[0] = readInt();
                i[1] = readInt();
                dim_type_90(i[0], i[1]);
                break;
            case 91:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                dim_type1_91(i[0], i[1], i[2]);
                break;
            case 92:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                i[3] = readInt();
                dim_type2_92(i[0], i[1], i[2], i[3]);
                break;
            case 93:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                i[3] = readInt();
                i[4] = readInt();
                dim_type3_93(i[0], i[1], i[2], i[3], i[4]);
                break;
            case 94:
                i[0] = readInt();
                i[1] = readInt();
                dim_num1_94(i[0], i[1]);
                break;
            case 95:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                dim_num2_95(i[0], i[1], i[2]);
                break;
            case 96:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                i[3] = readInt();
                dim_num3_96(i[0], i[1], i[2], i[3]);
                break;
            case 97:
                i[0] = readInt();
                i[1] = readInt();
                dim_str1_97(i[0], i[1]);
                break;
            case 98:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                dim_str2_98(i[0], i[1], i[2]);
                break;
            case 99:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                i[3] = readInt();
                dim_str3_99(i[0], i[1], i[2], i[3]);
                break;
            case 100:
                i[0] = readInt();
                delete_100(i[0]);
                break;
            case 101:
                i[0] = readInt();
                deleteS_101(i[0]);
                break;
            case 102:
                i[0] = readInt();
                push_102(i[0]);
                break;
            case 103:
                i[0] = readInt();
                push_103(i[0]);
                break;
            case 104:
                i[0] = readInt();
                pushS_104(i[0]);
                break;
            case 105:
                i[0] = readInt();
                pushS_105(i[0]);
                break;
            case 106:
                push_emptyS_106();
                break;
            case 107:
                i[0] = readInt();
                pop_107(i[0]);
                break;
            case 108:
                i[0] = readInt();
                pop_108(i[0]);
                break;
            case 109:
                i[0] = readInt();
                popS_109(i[0]);
                break;
            case 110:
                i[0] = readInt();
                popS_110(i[0]);
                break;
            case 111:
                i[0] = readInt();
                get_stack_size_111(i[0]);
                break;
            case 112:
                i[0] = readInt();
                get_stack_sizeS_112(i[0]);
                break;
            case 113:
                clear_stack_113();
                break;
            case 114:
                clear_stackS_114();
                break;
            case 115:
                i[0] = readInt();
                i[1] = readInt();
                while_115(i[0], i[1]);
                break;
            case 116:
                i[0] = readInt();
                wend_116(i[0]);
                break;
            case 117:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                i[3] = readInt();
                //cout << "step = " << vm_n[i[3]].value << endl;
                //cout << "for counter = " << vm_n[i[1]].value << " to " << vm_n[i[2]].value << " step " << vm_n[i[3]].value << endl;
                for_117(i[0], i[1], i[2], i[3]);
                //cout << "for info: " << current_segment << " " << current_address << endl << endl;
                //cout << "for counter = " << vm_n[i[1]].value << " to " << vm_n[i[2]].value << " step " << vm_n[i[3]].value << endl;
                break;
            case 118:
                i[0] = readInt();
                next_118(i[0]);
                //cout << endl << "next to: " << i[0] << endl;
                break;
            case 119:
                //do  not really needed, so
                break;
            case 120:
                i[0] = readInt();
                loop_120(i[0]);
                break;
            case 121:
                i[0] = readInt();
                i[1] = readInt();
                loop_while_121(i[0], i[1]);
                break;
            case 122:
                i[0] = readInt();
                i[1] = readInt();
                loop_until_122(i[0], i[1]);
                break;
            case 123:
                pop_loop_stack_123();
                break;
            case 124:
                i[0] = readInt();
                gosub_124(i[0]);
                break;
            case 125:
                return_125();
                break;
            case 126:
                i[0] = readInt();
                i[1] = readInt();
                ptr_126(i[0], i[1]);
                break;
            case 127:
                i[0] = readInt();
                i[1] = readInt();
                ptrS_127(i[0], i[1]);
                break;
            case 128:
                i[0] = readInt();
                print_128(i[0]);
                break;
            case 129:
                i[0] = readInt();
                printS_129(i[0]);
                break;
            case 130:
                i[0] = readInt();
                //cout << "func " << i[0] << endl;
                func_130(i[0]);
                break;
            case 131:
                d[0] = readDouble();
                push_131(d[0]);
                break;
            case 132:
                println_132();
                break;
            case 133:
                i[0] = readInt();
                i[1] = readInt();
                mov_133(i[0], i[1]);
                break;
            case 134:
                i[0] = readInt();
                d[0] = readDouble();
                cmp_134(i[0], d[0]);
                break;
            case 135:
                i[0] = readInt();
                i[1] = readInt();
                mov_arr_135(i[0], i[1]);
                break;
            case 136:
                i[0] = readInt();
                i[1] = readInt();
                mov_arrS_136(i[0], i[1]);
                break;
            case 137:
                i[0] = readInt();
                pop_ptr_137(i[0]);
                break;
            case 138:
                i[0] = readInt();
                preset_138(i[0]);
                break;
            case 139:
                i[0] = readInt();
                presetS_139(i[0]);
                break;
            case 140:
                i[0] = readInt();
                i[1] = readInt();
                redim_140(i[0], i[1]);
                break;
            case 141:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                redim_141(i[0], i[1], i[2]);
                break;
            case 142:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                i[3] = readInt();
                redim_142(i[0], i[1], i[2], i[3]);
                break;
            case 143:
                i[0] = readInt();
                i[1] = readInt();
                redimS_143(i[0], i[1]);
                break;
            case 144:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                redimS_144(i[0], i[1], i[2]);
                break;
            case 145:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                i[3] = readInt();
                redimS_145(i[0], i[1], i[2], i[3]);
                break;
            case 146:
                i[0] = readInt();
                for_offset_arr1_146(i[0]);
                break;
            case 147:
                i[0] = readInt();
                i[1] = readInt();
                for_offset_arr2_147(i[0], i[1]);
                break;
            case 148:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                for_offset_arr3_148(i[0], i[1], i[2]);
                break;
            case 149:
                for_offset_0_149();
                break;
            case 150:
                i[0] = readInt();
                end_x_150(i[0]);
                end_of_program = true;
                break;
            case 151:
                //lval
                break;
            case 152:
                //lval
                break;
            case 153:
                //lval
                break;
            case 154:
                //lval
                break;
            case 155:
                //lval
                break;
            case 156:
                i[0] = readInt();
                obj_usr_n_156(i[0]);
                break;
            case 157:
                i[0] = readInt();
                i[1] = readInt();
                obj_usr_n1_157(i[0], i[1]);
                break;
            case 158:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                obj_usr_n2_158(i[0], i[1], i[2]);
                break;
            case 159:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                i[3] = readInt();
                obj_usr_n3_159(i[0], i[1], i[2], i[3]);
                break;
            case 160:
                i[0] = readInt();
                obj_usr_s_160(i[0]);
                break;
            case 161:
                i[0] = readInt();
                i[1] = readInt();
                obj_usr_s1_161(i[0], i[1]);
                break;
            case 162:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                obj_usr_s2_162(i[0], i[1], i[2]);
                break;
            case 163:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                i[3] = readInt();
                obj_usr_s3_163(i[0], i[1], i[2], i[3]);
                break;
            case 164:
                i[0] = readInt();
                obj_usr_get_164(i[0]);
                break;
            case 165:
                i[0] = readInt();
                obj_usr_get_165(i[0]);
                break;
            case 166:
                i[0] = readInt();
                obj_usr_get_166(i[0]);
                break;
            case 167:
                i[0] = readInt();
                i[1] = readInt();
                uref_ptr_167(i[0], i[1]);
                break;
            case 168:
                i[0] = readInt();
                i[1] = readInt();
                mov_type_168(i[0], i[1]);
                break;
            case 169:
                i[0] = readInt();
                push_t_169(i[0]);
                break;
            case 170:
                i[0] = readInt();
                push_t_170(i[0]);
                break;
            case 171:
                i[0] = readInt();
                pop_t_171(i[0]);
                break;
            case 172:
                i[0] = readInt();
                pop_t_172(i[0]);
                break;
            case 173:
                push_t_null_173();
                break;
            case 174:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                delete_t_174(i[0], i[1], i[2]);
                break;
            case 175:
                i[0] = readInt();
                i[1] = readInt();
                dim_type_175(i[0], i[1]);
                break;
            case 176:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                dim_type1_176(i[0], i[1], i[2]);
                break;
            case 177:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                i[3] = readInt();
                dim_type2_177(i[0], i[1], i[2], i[3]);
                break;
            case 178:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                i[3] = readInt();
                i[4] = readInt();
                dim_type3_178(i[0], i[1], i[2], i[3], i[4]);
                break;
            case 179:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                i[3] = readInt();
                i[4] = readInt();
                i[5] = readInt();
                i[6] = readInt();
                dim_tfield_179(i[0], i[1], i[2], i[3], i[4], i[5], i[6]);
                break;
            case 180:
                i[0] = readInt();
                obj_usr_init_180(i[0]);
                break;
            case 181:
                i[0] = readInt();
                i[1] = readInt();
                obj_usr_init1_181(i[0], i[1]);
                break;
            case 182:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                obj_usr_init2_182(i[0], i[1], i[2]);
                break;
            case 183:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                i[3] = readInt();
                obj_usr_init3_183(i[0], i[1], i[2], i[3]);
                break;
            case 184:
                i[0] = readInt();
                obj_usr_init_184(i[0]);
                break;
            case 185:
                i[0] = readInt();
                i[1] = readInt();
                obj_usr_init1_185(i[0], i[1]);
                break;
            case 186:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                obj_usr_init2_186(i[0], i[1], i[2]);
                break;
            case 187:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                i[3] = readInt();
                obj_usr_init3_187(i[0], i[1], i[2], i[3]);
                break;
            case 188:
                i[0] = readInt();
                i[1] = readInt();
                preset_t_188(i[0], i[1]);
                break;
            case 189:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                preset_t1_189(i[0], i[1], i[2]);
                break;
            case 190:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                i[3] = readInt();
                preset_t2_190(i[0], i[1], i[2], i[3]);
                break;
            case 191:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                i[3] = readInt();
                i[4] = readInt();
                preset_t3_191(i[0], i[1], i[2], i[3], i[4]);
                break;
            case 192:
                i[0] = readInt();
                i[1] = readInt();
                redim_type_192(i[0], i[1]);
                break;
            case 193:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                redim_type1_193(i[0], i[1], i[2]);
                break;
            case 194:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                i[3] = readInt();
                redim_type2_194(i[0], i[1], i[2], i[3]);
                break;
            case 195:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                i[3] = readInt();
                i[4] = readInt();
                redim_type3_195(i[0], i[1], i[2], i[3], i[4]);
                break;
            case 196:
                i[0] = readInt();
                redim_type_n_196(i[0]);
                break;
            case 197:
                i[0] = readInt();
                i[1] = readInt();
                redim_type_n1_197(i[0], i[1]);
                break;
            case 198:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                redim_type_n2_198(i[0], i[1], i[2]);
                break;
            case 199:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                i[3] = readInt();
                redim_type_n3_199(i[0], i[1], i[2], i[3]);
                break;
            case 200:
                i[0] = readInt();
                redim_type_s_200(i[0]);
                break;
            case 201:
                i[0] = readInt();
                i[1] = readInt();
                redim_type_s1_201(i[0], i[1]);
                break;
            case 202:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                redim_type_s2_202(i[0], i[1], i[2]);
                break;
            case 203:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                i[3] = readInt();
                redim_type_s3_203(i[0], i[1], i[2], i[3]);
                break;
            case 204:
                i[0] = readInt();
                i[1] = readInt();
                redim_type_204(i[0], i[1]);
                break;
            case 205:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                redim_type1_205(i[0], i[1], i[2]);
                break;
            case 206:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                i[3] = readInt();
                redim_type2_206(i[0], i[1], i[2], i[3]);
                break;
            case 207:
                i[0] = readInt();
                i[1] = readInt();
                i[2] = readInt();
                i[3] = readInt();
                i[4] = readInt();
                redim_type3_207(i[0], i[1], i[2], i[3], i[4]);
                break;
            case 208:
                redim_top_208();
                break;
            default:
                cout << "invalid cmd: " << rcbasic_cmd << endl;
                rcbasic_exit_code = 1;
                return 0;
        }
    }
    return 1;
}

void rcbasic_init()
{
    for(int i = 0; i < RC_MAX_FILES; i++)
        rc_fstream[i] = NULL;
    rc_media_init();
    arr_ref_id.clear();
}

void rcbasic_clean()
{
    rc_media_quit();
    byref_addr_table.empty();
    loop_stack.empty();
    n_stack.empty();
    s_stack.empty();
    gosub_return_addr.empty();
}

void rcbasic_test()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window * win = SDL_CreateWindow("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer * ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_PRESENTVSYNC);
    SDL_Rect src;
    src.x = 50;
    src.y = 50;
    src.w = 100;
    src.h = 100;
    SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
    SDL_RenderFillRect(ren, &src);
    SDL_RenderPresent(ren);
    SDL_Delay(5000);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
}

int main(int argc, char * argv[])
{
    //rcbasic_test();
    //return 0;

    if(argc > 0)
        rcbasic_runtime_path = argv[0];

    //cout << "RCBASIC RUNTIME START" << endl;
    #ifdef RC_WINDOWS
        TCHAR buf[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buf);
        rc_dir_path = buf;
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #else
		#ifdef RC_GETCWD
			char buf[2048];
			getcwd(buf, 2048);
			rc_dir_path = (std::string)buf;
		#else
			rc_dir_path = get_current_dir_name();
		#endif
    #endif // RC_WINDOWS

    std::string rc_filename = "main.cbc";

    if(argc > 1)
        rc_filename = argv[1];
    else
        #ifdef RC_WINDOWS
        {
            //rc_filename = argv[0];
            //rc_filename = rc_filename.substr(0, rc_filename.length()-3) + "cbc";
        }
        #else
        {
            //rc_filename = argv[0];
            //rc_filename += ".cbc";
        }
        #endif // RC_WINDOWS

    if(rc_filename.compare("--version")==0)
    {
        cout << "RCBASIC Runtime v4.0a" << endl;
        return 0;
    }

    #ifdef RCBASIC_DEBUG
    rc_filename = "debug.cbc";
    #endif // RCBASIC_DEBUG

    //DEBUG START
    //rc_filename = "/home/n00b/Projects/RCBASIC3/rcbasic_build/tst.cbc";
    //DEBUG END

    if(argc >1)
    {
        rc_cmd_count = argc - 1;
        rc_cmd_args = new std::string[rc_cmd_count];
        for(int i = 1; i < argc; i++)
            rc_cmd_args[i-1] = argv[i];
    }

    rcbasic_init();
    rc_initSubprocessSystem();

    if(rc_filename.length()>=4)
    {
        if(rc_filename.substr(rc_filename.length()-4, 4).compare(".cbc")!=0)
            rc_filename += ".cbc";
    }
    else
    {
        rc_filename += ".cbc";
    }

#ifdef RC_ANDROID
    rc_filename = "main.cbc";
#endif

#ifdef RC_IOS
    if( rc_intern_dirChange("assets")!=0)
    {
        cout << "could not set path" << endl;
        return 0;
    }
    rc_filename = "main.cbc";
#endif

    //cout << "starting: " << rc_filename << endl;

    #ifdef RC_WEB
        rc_filename = "main.cbc";
    #endif

    if(rcbasic_load(rc_filename))
    {
        #ifdef RCBASIC_DEBUG
        loadDebugData("rcbasic.dbgs", "rcbasic.dbgi");
        #endif // RCBASIC_DEBUG

        //cout << "n_count = " << n_count << endl;
        //cout << "s_count = " << s_count << endl;
        //cout << "n_stack_size = " << n_stack_size << endl;
        //cout << "s_stack_size = " << s_stack_size << endl;
        //cout << "loop_stack_size = " << loop_stack_size << endl;
        //cout << "numID_count = " << numID_count << endl;
        //cout << "strID_count = " << strID_count << endl;
        //cout << "code_segment_size = " << code_segment_size << endl;
        //cout << "data_segment_size = " << data_segment_size << endl;
        //cout << "last code = " << (int)segment[CODE_SEGMENT][code_segment_size-1] << endl;
        //cout << "last data = " << (int)segment[DATA_SEGMENT][data_segment_size-1] << endl << endl;

        rcbasic_run();
    }
    else
        cout << "++Could not load rcbasic program" << endl;

    rc_cleanSubprocessSystem();
    rcbasic_clean();

    exit(rcbasic_exit_code);
    //cout << "Hello world!" << endl;
    return 0;
}
