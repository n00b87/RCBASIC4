#ifndef RC_DEFINES_H_INCLUDED
#define RC_DEFINES_H_INCLUDED

#define FN_FPrint 0
#define FPRINT_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Input$ 1
#define INPUT$_PROMPT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_ArrayDim 2
#define ARRAYDIM_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_StringArrayDim 3
#define STRINGARRAYDIM_ID$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_NumberArrayDim 4
#define NUMBERARRAYDIM_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ArraySize 5
#define ARRAYSIZE_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ARRAYSIZE_ARRAY_DIM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_StringArraySize 6
#define STRINGARRAYSIZE_ID$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define STRINGARRAYSIZE_ARRAY_DIM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumberArraySize 7
#define NUMBERARRAYSIZE_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define NUMBERARRAYSIZE_ARRAY_DIM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_NumberArrayCopy 8
#define NUMBERARRAYCOPY_SRC num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define NUMBERARRAYCOPY_DST num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_StringArrayCopy 9
#define STRINGARRAYCOPY_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define STRINGARRAYCOPY_DST$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_ArrayCopy 10
#define ARRAYCOPY_SRC num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ARRAYCOPY_DST num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_NumberArrayFill 11
#define NUMBERARRAYFILL_SRC num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define NUMBERARRAYFILL_FDATA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_StringArrayFill 12
#define STRINGARRAYFILL_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define STRINGARRAYFILL_FDATA$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_ArrayFill 13
#define ARRAYFILL_SRC num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ARRAYFILL_FDATA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_TypeArrayDim 14
#define TYPEARRAYDIM_ID usr_var[0].var_ref
#define FN_TypeArraySize 15
#define TYPEARRAYSIZE_ID usr_var[0].var_ref
#define TYPEARRAYSIZE_ARRAY_DIM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TypeArrayCopy 16
#define TYPEARRAYCOPY_SRC usr_var[0].var_ref
#define TYPEARRAYCOPY_DST usr_var[1].var_ref
#define FN_TypeArrayFill 17
#define TYPEARRAYFILL_SRC usr_var[0].var_ref
#define TYPEARRAYFILL_FDATA usr_var[1].var_ref->uid_value[0]
#define FN_Abs 18
#define ABS_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Acos 19
#define ACOS_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_AndBit 20
#define ANDBIT_A num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ANDBIT_B num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_Asin 21
#define ASIN_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Atan 22
#define ATAN_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Bin$ 23
#define BIN$_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CInt32 24
#define CINT32_I num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CInt64 25
#define CINT64_I num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Cos 26
#define COS_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Degrees 27
#define DEGREES_R num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Exp 28
#define EXP_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Frac 29
#define FRAC_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Hex$ 30
#define HEX$_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_HexVal 31
#define HEXVAL_N$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Int 32
#define INT_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Log 33
#define LOG_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Max 34
#define MAX_A num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define MAX_B num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_Min 35
#define MIN_A num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define MIN_B num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_OrBit 36
#define ORBIT_A num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ORBIT_B num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_Radians 37
#define RADIANS_D num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Randomize 38
#define RANDOMIZE_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Rand 39
#define RAND_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Round 40
#define ROUND_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Sign 41
#define SIGN_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Sin 42
#define SIN_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Sqrt 43
#define SQRT_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Tan 44
#define TAN_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_XOrBit 45
#define XORBIT_A num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define XORBIT_B num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetLineIntersection 46
#define GETLINEINTERSECTION_P0_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETLINEINTERSECTION_P0_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETLINEINTERSECTION_P1_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETLINEINTERSECTION_P1_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETLINEINTERSECTION_P2_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETLINEINTERSECTION_P2_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETLINEINTERSECTION_P3_X num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define GETLINEINTERSECTION_P3_Y num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define GETLINEINTERSECTION_I_X num_var[8].nref[0].value[ num_var[8].byref_offset ]
#define GETLINEINTERSECTION_I_Y num_var[9].nref[0].value[ num_var[9].byref_offset ]
#define FN_Interpolate 47
#define INTERPOLATE_MIN_A num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define INTERPOLATE_MAX_A num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define INTERPOLATE_MID_A num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define INTERPOLATE_MIN_B num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define INTERPOLATE_MAX_B num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_ATan2 48
#define ATAN2_Y num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ATAN2_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_PointInQuad 49
#define POINTINQUAD_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define POINTINQUAD_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define POINTINQUAD_X1 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define POINTINQUAD_Y1 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define POINTINQUAD_X2 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define POINTINQUAD_Y2 num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define POINTINQUAD_X3 num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define POINTINQUAD_Y3 num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define POINTINQUAD_X4 num_var[8].nref[0].value[ num_var[8].byref_offset ]
#define POINTINQUAD_Y4 num_var[9].nref[0].value[ num_var[9].byref_offset ]
#define FN_PointInTri 50
#define POINTINTRI_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define POINTINTRI_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define POINTINTRI_X1 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define POINTINTRI_Y1 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define POINTINTRI_X2 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define POINTINTRI_Y2 num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define POINTINTRI_X3 num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define POINTINTRI_Y3 num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define FN_Distance2D 51
#define DISTANCE2D_X1 num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DISTANCE2D_Y1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DISTANCE2D_X2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DISTANCE2D_Y2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_Distance3D 52
#define DISTANCE3D_X1 num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DISTANCE3D_Y1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DISTANCE3D_Z1 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DISTANCE3D_X2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DISTANCE3D_Y2 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define DISTANCE3D_Z2 num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_GetCircleLineIntersection 53
#define GETCIRCLELINEINTERSECTION_CIRCLE_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCIRCLELINEINTERSECTION_CIRCLE_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCIRCLELINEINTERSECTION_RADIUS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETCIRCLELINEINTERSECTION_X1 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETCIRCLELINEINTERSECTION_Y1 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETCIRCLELINEINTERSECTION_X2 num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETCIRCLELINEINTERSECTION_Y2 num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define GETCIRCLELINEINTERSECTION_IX1 num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define GETCIRCLELINEINTERSECTION_IY1 num_var[8].nref[0].value[ num_var[8].byref_offset ]
#define GETCIRCLELINEINTERSECTION_IX2 num_var[9].nref[0].value[ num_var[9].byref_offset ]
#define GETCIRCLELINEINTERSECTION_IY2 num_var[10].nref[0].value[ num_var[10].byref_offset ]
#define FN_GetLinePlaneIntersection 54
#define GETLINEPLANEINTERSECTION_LINE_POINT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETLINEPLANEINTERSECTION_LINE_DIRECTION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETLINEPLANEINTERSECTION_PLANE_POINT_1 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETLINEPLANEINTERSECTION_PLANE_POINT_2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETLINEPLANEINTERSECTION_PLANE_POINT_3 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETLINEPLANEINTERSECTION_INTERSECTION num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_Asc 55
#define ASC_C$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Chr$ 56
#define CHR$_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Insert$ 57
#define INSERT$_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define INSERT$_TGT$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define INSERT$_POS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_InStr 58
#define INSTR_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define INSTR_SUBSTR$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_Lcase$ 59
#define LCASE$_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Left$ 60
#define LEFT$_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define LEFT$_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Length 61
#define LENGTH_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Len 62
#define LEN_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Ltrim$ 63
#define LTRIM$_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Mid$ 64
#define MID$_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define MID$_START num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define MID$_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ReplaceSubstr$ 65
#define REPLACESUBSTR$_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define REPLACESUBSTR$_RPC$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define REPLACESUBSTR$_POS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Replace$ 66
#define REPLACE$_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define REPLACE$_TGT$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define REPLACE$_RPC$ str_var[2].sref[0].value[ str_var[2].byref_offset ]
#define FN_Reverse$ 67
#define REVERSE$_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Right$ 68
#define RIGHT$_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define RIGHT$_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Rtrim$ 69
#define RTRIM$_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_StringFill$ 70
#define STRINGFILL$_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define STRINGFILL$_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Str$ 71
#define STR$_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Str_F$ 72
#define STR_F$_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Str_S$ 73
#define STR_S$_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Tally 74
#define TALLY_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define TALLY_SUBSTR$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_Trim$ 75
#define TRIM$_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Ucase$ 76
#define UCASE$_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Val 77
#define VAL_N$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Size 78
#define SIZE_S$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_BufferFromString 79
#define BUFFERFROMSTRING_S$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define BUFFERFROMSTRING_BUFFER num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_StringFromBuffer$ 80
#define STRINGFROMBUFFER$_BUFFER num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define STRINGFROMBUFFER$_BUFFER_SIZE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_CreateStack_N 81
#define FN_CreateStack_S 82
#define FN_ClearStack_N 83
#define CLEARSTACK_N_NUM_STACK num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ClearStack_S 84
#define CLEARSTACK_S_STR_STACK num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteStack_N 85
#define DELETESTACK_N_NUM_STACK num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteStack_S 86
#define DELETESTACK_S_STR_STACK num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Push_N 87
#define PUSH_N_NUM_STACK num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define PUSH_N_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_Pop_N 88
#define POP_N_NUM_STACK num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Push_S 89
#define PUSH_S_STR_STACK num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define PUSH_S_S$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Pop_S$ 90
#define POP_S$_STR_STACK num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Stack_Size_N 91
#define STACK_SIZE_N_NUM_STACK num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Stack_Size_S 92
#define STACK_SIZE_S_STR_STACK num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Stack_N_Exists 93
#define STACK_N_EXISTS_NUM_STACK num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Stack_S_Exists 94
#define STACK_S_EXISTS_STR_STACK num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_OpenFile 95
#define OPENFILE_FILENAME$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define OPENFILE_MODE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CloseFile 96
#define CLOSEFILE_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ReadByte 97
#define READBYTE_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_WriteByte 98
#define WRITEBYTE_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WRITEBYTE_BYTE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ReadLine$ 99
#define READLINE$_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Write 100
#define WRITE_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WRITE_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_WriteLine 101
#define WRITELINE_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WRITELINE_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_CopyFile 102
#define COPYFILE_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define COPYFILE_DST$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_RemoveFile 103
#define REMOVEFILE_FILENAME$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_FileExists 104
#define FILEEXISTS_FILENAME$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_MoveFile 105
#define MOVEFILE_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define MOVEFILE_DST$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_RenameFile 106
#define RENAMEFILE_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define RENAMEFILE_DST$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_FileLength 107
#define FILELENGTH_FILENAME$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Tell 108
#define TELL_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Seek 109
#define SEEK_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SEEK_POS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_EOF 110
#define EOF_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_WriteByteBuffer 111
#define WRITEBYTEBUFFER_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WRITEBYTEBUFFER_BUF num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define WRITEBYTEBUFFER_BUF_SIZE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ReadByteBuffer 112
#define READBYTEBUFFER_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define READBYTEBUFFER_BUF num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define READBYTEBUFFER_BUF_SIZE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ChangeDir 113
#define CHANGEDIR_P$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_DirExists 114
#define DIREXISTS_P$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_DirFirst$ 115
#define FN_Dir$ 116
#define FN_DirNext$ 117
#define FN_MakeDir 118
#define MAKEDIR_P$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_RemoveDir 119
#define REMOVEDIR_P$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Date$ 120
#define FN_Easter$ 121
#define EASTER$_YEAR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Ticks 122
#define FN_Time$ 123
#define FN_Timer 124
#define FN_Wait 125
#define WAIT_M_SEC num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_OpenWindow 126
#define OPENWINDOW_TITLE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define OPENWINDOW_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define OPENWINDOW_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define OPENWINDOW_FULLSCREEN num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define OPENWINDOW_VSYNC num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_OpenWindowEx 127
#define OPENWINDOWEX_TITLE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define OPENWINDOWEX_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define OPENWINDOWEX_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define OPENWINDOWEX_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define OPENWINDOWEX_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define OPENWINDOWEX_MODE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define OPENWINDOWEX_AA num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define OPENWINDOWEX_STENCIL_BUFFER num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define OPENWINDOWEX_VSYNC num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define FN_CloseWindow 128
#define FN_RaiseWindow 129
#define FN_Update 130
#define FN_Cls 131
#define FN_SetClearColor 132
#define SETCLEARCOLOR_C num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ShowWindow 133
#define FN_HideWindow 134
#define FN_SetWindowTitle 135
#define SETWINDOWTITLE_TITLE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_WindowTitle$ 136
#define FN_SetWindowPosition 137
#define SETWINDOWPOSITION_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWINDOWPOSITION_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWindowPosition 138
#define GETWINDOWPOSITION_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWINDOWPOSITION_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetWindowSize 139
#define SETWINDOWSIZE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWINDOWSIZE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWindowSize 140
#define GETWINDOWSIZE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWINDOWSIZE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetWindowMinSize 141
#define SETWINDOWMINSIZE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWINDOWMINSIZE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWindowMinSize 142
#define GETWINDOWMINSIZE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWINDOWMINSIZE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetWindowMaxSize 143
#define SETWINDOWMAXSIZE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWINDOWMAXSIZE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWindowMaxSize 144
#define GETWINDOWMAXSIZE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWINDOWMAXSIZE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_WindowIsFullscreen 145
#define FN_WindowIsVisible 146
#define FN_WindowIsBordered 147
#define FN_WindowIsResizable 148
#define FN_WindowIsMinimized 149
#define FN_WindowIsMaximized 150
#define FN_WindowHasInputFocus 151
#define FN_WindowHasMouseFocus 152
#define FN_SetWindowFullscreen 153
#define SETWINDOWFULLSCREEN_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_MaximizeWindow 154
#define FN_MinimizeWindow 155
#define FN_SetWindowBordered 156
#define SETWINDOWBORDERED_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_WindowClip 157
#define WINDOWCLIP_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WINDOWCLIP_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define WINDOWCLIP_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define WINDOWCLIP_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_WindowExists 158
#define FN_WindowEvent_Close 159
#define FN_WindowEvent_Maximize 160
#define FN_WindowEvent_Minimize 161
#define FN_FPS 162
#define FN_SetWindowIcon 163
#define SETWINDOWICON_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_WindowEvent_Resize 164
#define FN_SetWindowAutoClose 165
#define SETWINDOWAUTOCLOSE_EXIT_ON_CLOSE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetWindowResizable 166
#define SETWINDOWRESIZABLE_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_WindowMode 167
#define WINDOWMODE_VISIBLE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WINDOWMODE_FULLSCREEN num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define WINDOWMODE_RESIZABLE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define WINDOWMODE_BORDERLESS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define WINDOWMODE_HIGHDPI num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getWindowMode 168
#define FN_RestoreWindow 169
#define FN_GrabInput 170
#define GRABINPUT_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetWindowAlwaysOnTop 171
#define SETWINDOWALWAYSONTOP_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetMouseRelative 172
#define SETMOUSERELATIVE_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetWindowVSync 173
#define SETWINDOWVSYNC_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_FlashWindow 174
#define FLASHWINDOW_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_WindowIsGrabbed 175
#define FN_PreUpdate 176
#define FN_SetFPS 177
#define SETFPS_FPS_VAL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_OpenCanvas 178
#define OPENCANVAS_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define OPENCANVAS_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define OPENCANVAS_VIEWPORT_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define OPENCANVAS_VIEWPORT_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define OPENCANVAS_VIEWPORT_W num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define OPENCANVAS_VIEWPORT_H num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define OPENCANVAS_MODE num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_CloseCanvas 179
#define CLOSECANVAS_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_OpenCanvas3D 180
#define OPENCANVAS3D_VIEWPORT_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define OPENCANVAS3D_VIEWPORT_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define OPENCANVAS3D_VIEWPORT_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define OPENCANVAS3D_VIEWPORT_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define OPENCANVAS3D_MODE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_SetCanvasVisible 181
#define SETCANVASVISIBLE_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCANVASVISIBLE_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_CanvasIsVisible 182
#define CANVASISVISIBLE_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetCanvasViewport 183
#define SETCANVASVIEWPORT_CNUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCANVASVIEWPORT_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCANVASVIEWPORT_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETCANVASVIEWPORT_W num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETCANVASVIEWPORT_H num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_GetCanvasViewport 184
#define GETCANVASVIEWPORT_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCANVASVIEWPORT_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCANVASVIEWPORT_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETCANVASVIEWPORT_W num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETCANVASVIEWPORT_H num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_Canvas 185
#define CANVAS_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetCanvasOffset 186
#define SETCANVASOFFSET_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCANVASOFFSET_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCANVASOFFSET_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetCanvasOffset 187
#define GETCANVASOFFSET_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCANVASOFFSET_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCANVASOFFSET_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetCanvasSize 188
#define GETCANVASSIZE_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCANVASSIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCANVASSIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ClearCanvas 189
#define FN_SetCanvasAlpha 190
#define SETCANVASALPHA_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCANVASALPHA_A num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetCanvasAlpha 191
#define GETCANVASALPHA_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetCanvasColorMod 192
#define SETCANVASCOLORMOD_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCANVASCOLORMOD_C num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetCanvasColorMod 193
#define GETCANVASCOLORMOD_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CloneCanvas 194
#define CLONECANVAS_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CLONECANVAS_MODE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetCanvasZ 195
#define SETCANVASZ_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCANVASZ_Z num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_CanvasZ 196
#define CANVASZ_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CanvasClip 197
#define CANVASCLIP_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CANVASCLIP_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CANVASCLIP_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CANVASCLIP_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_ActiveCanvas 198
#define FN_SetCanvasPhysics2D 199
#define SETCANVASPHYSICS2D_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCANVASPHYSICS2D_STATE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_OpenCanvasSpriteLayer 200
#define OPENCANVASSPRITELAYER_VIEWPORT_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define OPENCANVASSPRITELAYER_VIEWPORT_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define OPENCANVASSPRITELAYER_VIEWPORT_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define OPENCANVASSPRITELAYER_VIEWPORT_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetSpriteCanvasBlendMode 201
#define SETSPRITECANVASBLENDMODE_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITECANVASBLENDMODE_BLEND_MODE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteCanvasBlendMode 202
#define GETSPRITECANVASBLENDMODE_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteCanvasAntiAliasMode 203
#define SETSPRITECANVASANTIALIASMODE_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITECANVASANTIALIASMODE_AA_MODE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteCanvasAntiAliasMode 204
#define GETSPRITECANVASANTIALIASMODE_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteCanvasBilinearFilter 205
#define SETSPRITECANVASBILINEARFILTER_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITECANVASBILINEARFILTER_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteCanvasBilinearFilter 206
#define GETSPRITECANVASBILINEARFILTER_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetSpriteCanvasPhysics 207
#define GETSPRITECANVASPHYSICS_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteCanvasRenderPriority 208
#define SETSPRITECANVASRENDERPRIORITY_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITECANVASRENDERPRIORITY_PRIORITY num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITECANVASRENDERPRIORITY_ORDER num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetSpriteCanvasRenderPriority 209
#define GETSPRITECANVASRENDERPRIORITY_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITECANVASRENDERPRIORITY_PRIORITY num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITECANVASRENDERPRIORITY_ORDER num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetPostEffect 210
#define SETPOSTEFFECT_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPOSTEFFECT_EFFECT_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ClearPostEffect 211
#define CLEARPOSTEFFECT_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetPostEffectProperty 212
#define SETPOSTEFFECTPROPERTY_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPOSTEFFECTPROPERTY_PROPERTY num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPOSTEFFECTPROPERTY_PROPERTY_VALUE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetPostEffectProperty 213
#define GETPOSTEFFECTPROPERTY_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPOSTEFFECTPROPERTY_PROPERTY num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetPostEffectActive 214
#define SETPOSTEFFECTACTIVE_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPOSTEFFECTACTIVE_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_PostEffectIsActive 215
#define POSTEFFECTISACTIVE_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetPostEffectType 216
#define GETPOSTEFFECTTYPE_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Circle 217
#define CIRCLE_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CIRCLE_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CIRCLE_RADIUS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_CircleFill 218
#define CIRCLEFILL_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CIRCLEFILL_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CIRCLEFILL_RADIUS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_Ellipse 219
#define ELLIPSE_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ELLIPSE_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ELLIPSE_RX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define ELLIPSE_RY num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_EllipseFill 220
#define ELLIPSEFILL_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ELLIPSEFILL_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ELLIPSEFILL_RX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define ELLIPSEFILL_RY num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_FloodFill 221
#define FLOODFILL_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FLOODFILL_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetPixel 222
#define GETPIXEL_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPIXEL_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetColor 223
#define SETCOLOR_C num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Line 224
#define LINE_X1 num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define LINE_Y1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define LINE_X2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define LINE_Y2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_Poly 225
#define POLY_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define POLY_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define POLY_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_Rect 226
#define RECT_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define RECT_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define RECT_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define RECT_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_RectFill 227
#define RECTFILL_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define RECTFILL_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define RECTFILL_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define RECTFILL_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_RGB 228
#define RGB_R num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define RGB_G num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define RGB_B num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_RGBA 229
#define RGBA_R num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define RGBA_G num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define RGBA_B num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define RGBA_A num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_Pset 230
#define PSET_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define PSET_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_Triangle 231
#define TRIANGLE_X1 num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TRIANGLE_Y1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define TRIANGLE_X2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define TRIANGLE_Y2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define TRIANGLE_X3 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define TRIANGLE_Y3 num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_Line3D 232
#define LINE3D_X1 num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define LINE3D_Y1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define LINE3D_Z1 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define LINE3D_X2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define LINE3D_Y2 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define LINE3D_Z2 num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_Box3D 233
#define BOX3D_MIN_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define BOX3D_MIN_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define BOX3D_MIN_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define BOX3D_MAX_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define BOX3D_MAX_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define BOX3D_MAX_Z num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_Triangle3D 234
#define TRIANGLE3D_X1 num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TRIANGLE3D_Y1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define TRIANGLE3D_Z1 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define TRIANGLE3D_X2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define TRIANGLE3D_Y2 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define TRIANGLE3D_Z2 num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define TRIANGLE3D_X3 num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define TRIANGLE3D_Y3 num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define TRIANGLE3D_Z3 num_var[8].nref[0].value[ num_var[8].byref_offset ]
#define FN_SetRenderCirclePoints 235
#define SETRENDERCIRCLEPOINTS_NUM_POINTS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_LoadImage 236
#define LOADIMAGE_IMG$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_LoadImageEx 237
#define LOADIMAGEEX_IMG$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define LOADIMAGEEX_COLKEY num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_createImage 238
#define CREATEIMAGE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEIMAGE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEIMAGE_BUFFER num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_createImageEx 239
#define CREATEIMAGEEX_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEIMAGEEX_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEIMAGEEX_BUFFER num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEIMAGEEX_COLOR num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_BufferFromImage 240
#define BUFFERFROMIMAGE_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define BUFFERFROMIMAGE_BUFFER num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ImageExists 241
#define IMAGEEXISTS_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ColorKey 242
#define COLORKEY_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COLORKEY_C num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setBilinearFilter 243
#define SETBILINEARFILTER_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getBilinearFilter 244
#define FN_CopyImage 245
#define COPYIMAGE_IMG_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteImage 246
#define DELETEIMAGE_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetImageAlpha 247
#define SETIMAGEALPHA_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETIMAGEALPHA_A num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetImageAlpha 248
#define GETIMAGEALPHA_IMG_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetImageSize 249
#define GETIMAGESIZE_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETIMAGESIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETIMAGESIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetBlendMode 250
#define SETBLENDMODE_BLEND_MODE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetBlendMode 251
#define FN_SetImageColorMod 252
#define SETIMAGECOLORMOD_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETIMAGECOLORMOD_C num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetImageColorMod 253
#define GETIMAGECOLORMOD_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DrawImage 254
#define DRAWIMAGE_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_DrawImage_Blit 255
#define DRAWIMAGE_BLIT_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_BLIT_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_BLIT_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_BLIT_SRC_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWIMAGE_BLIT_SRC_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define DRAWIMAGE_BLIT_SRC_W num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define DRAWIMAGE_BLIT_SRC_H num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_DrawImage_BlitEx 256
#define DRAWIMAGE_BLITEX_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_BLITEX_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_BLITEX_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_BLITEX_W num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWIMAGE_BLITEX_H num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define DRAWIMAGE_BLITEX_SRC_X num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define DRAWIMAGE_BLITEX_SRC_Y num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define DRAWIMAGE_BLITEX_SRC_W num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define DRAWIMAGE_BLITEX_SRC_H num_var[8].nref[0].value[ num_var[8].byref_offset ]
#define FN_DrawImage_Rotate 257
#define DRAWIMAGE_ROTATE_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_ROTATE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_ROTATE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_ROTATE_ANGLE num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_DrawImage_RotateEx 258
#define DRAWIMAGE_ROTATEEX_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_ROTATEEX_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_ROTATEEX_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_ROTATEEX_SRC_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWIMAGE_ROTATEEX_SRC_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define DRAWIMAGE_ROTATEEX_SRC_W num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define DRAWIMAGE_ROTATEEX_SRC_H num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define DRAWIMAGE_ROTATEEX_ANGLE num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define FN_DrawImage_Zoom 259
#define DRAWIMAGE_ZOOM_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_ZOOM_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_ZOOM_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_ZOOM_ZX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWIMAGE_ZOOM_ZY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_DrawImage_ZoomEx 260
#define DRAWIMAGE_ZOOMEX_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_ZOOMEX_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_ZOOMEX_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_ZOOMEX_SRC_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWIMAGE_ZOOMEX_SRC_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define DRAWIMAGE_ZOOMEX_SRC_W num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define DRAWIMAGE_ZOOMEX_SRC_H num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define DRAWIMAGE_ZOOMEX_ZX num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define DRAWIMAGE_ZOOMEX_ZY num_var[8].nref[0].value[ num_var[8].byref_offset ]
#define FN_DrawImage_Rotozoom 261
#define DRAWIMAGE_ROTOZOOM_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_ROTOZOOM_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_ROTOZOOM_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_ROTOZOOM_ANGLE num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWIMAGE_ROTOZOOM_ZX num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define DRAWIMAGE_ROTOZOOM_ZY num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_DrawImage_RotozoomEx 262
#define DRAWIMAGE_ROTOZOOMEX_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_ROTOZOOMEX_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_ROTOZOOMEX_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_ROTOZOOMEX_SRC_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWIMAGE_ROTOZOOMEX_SRC_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define DRAWIMAGE_ROTOZOOMEX_SRC_W num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define DRAWIMAGE_ROTOZOOMEX_SRC_H num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define DRAWIMAGE_ROTOZOOMEX_ANGLE num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define DRAWIMAGE_ROTOZOOMEX_ZX num_var[8].nref[0].value[ num_var[8].byref_offset ]
#define DRAWIMAGE_ROTOZOOMEX_ZY num_var[9].nref[0].value[ num_var[9].byref_offset ]
#define FN_DrawImage_Flip 263
#define DRAWIMAGE_FLIP_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_FLIP_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_FLIP_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_FLIP_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWIMAGE_FLIP_V num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_DrawImage_FlipEx 264
#define DRAWIMAGE_FLIPEX_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_FLIPEX_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_FLIPEX_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_FLIPEX_SRC_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWIMAGE_FLIPEX_SRC_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define DRAWIMAGE_FLIPEX_SRC_W num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define DRAWIMAGE_FLIPEX_SRC_H num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define DRAWIMAGE_FLIPEX_H num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define DRAWIMAGE_FLIPEX_V num_var[8].nref[0].value[ num_var[8].byref_offset ]
#define FN_SaveBMP 265
#define SAVEBMP_IMG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SAVEBMP_FILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_SetAntiAliasMode 266
#define SETANTIALIASMODE_AA_MODE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetAntiAliasMode 267
#define FN_ConvertToNormalMap 268
#define CONVERTTONORMALMAP_IMG_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CONVERTTONORMALMAP_AMP num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_InKey 269
#define FN_Key 270
#define KEY_KEY_CODE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_WaitKey 271
#define FN_HideMouse 272
#define FN_ShowMouse 273
#define FN_MouseIsVisible 274
#define FN_GetMouse 275
#define GETMOUSE_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMOUSE_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMOUSE_MB1 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETMOUSE_MB2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETMOUSE_MB3 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_MouseX 276
#define FN_MouseY 277
#define FN_MouseButton 278
#define MOUSEBUTTON_MB num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetMouseWheel 279
#define GETMOUSEWHEEL_X_AXIS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMOUSEWHEEL_Y_AXIS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_MouseWheelX 280
#define FN_MouseWheelY 281
#define FN_GetGlobalMouse 282
#define GETGLOBALMOUSE_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETGLOBALMOUSE_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETGLOBALMOUSE_MB1 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETGLOBALMOUSE_MB2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETGLOBALMOUSE_MB3 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_GlobalMouseX 283
#define FN_GlobalMouseY 284
#define FN_WarpMouse 285
#define WARPMOUSE_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WARPMOUSE_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_WarpMouseGlobal 286
#define WARPMOUSEGLOBAL_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WARPMOUSEGLOBAL_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetMouseZone 287
#define SETMOUSEZONE_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMOUSEZONE_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMOUSEZONE_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETMOUSEZONE_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_ClearMouseZone 288
#define FN_CreateSound 289
#define CREATESOUND_BUFFER num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATESOUND_BUFFER_SIZE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATESOUND_VOL num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_LoadSound 290
#define LOADSOUND_SND_FILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_LoadMusic 291
#define LOADMUSIC_MUSIC_FILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_PlaySound 292
#define PLAYSOUND_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define PLAYSOUND_CHANNEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define PLAYSOUND_LOOPS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_PlaySoundTimed 293
#define PLAYSOUNDTIMED_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define PLAYSOUNDTIMED_CHANNEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define PLAYSOUNDTIMED_LOOPS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define PLAYSOUNDTIMED_MS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_PlayMusic 294
#define PLAYMUSIC_MLOOPS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_PauseSound 295
#define PAUSESOUND_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ResumeSound 296
#define RESUMESOUND_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_PauseMusic 297
#define FN_ResumeMusic 298
#define FN_DeleteSound 299
#define DELETESOUND_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteMusic 300
#define FN_FadeMusicIn 301
#define FADEMUSICIN_FADE_TIME num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FADEMUSICIN_LOOPS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_FadeMusicOut 302
#define FADEMUSICOUT_FADE_TIME num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_MusicExists 303
#define FN_SetMusicVolume 304
#define SETMUSICVOLUME_VOL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetMusicVolume 305
#define FN_SetMusicPosition 306
#define SETMUSICPOSITION_POS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetMusicPosition 307
#define FN_RewindMusic 308
#define FN_SetSoundChannels 309
#define SETSOUNDCHANNELS_MAX_CHANNELS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumSoundChannels 310
#define FN_SoundIsEnabled 311
#define FN_SoundExists 312
#define SOUNDEXISTS_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetChannelVolume 313
#define SETCHANNELVOLUME_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCHANNELVOLUME_VOL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetChannelVolume 314
#define GETCHANNELVOLUME_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSoundVolume 315
#define SETSOUNDVOLUME_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSOUNDVOLUME_VOL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSoundVolume 316
#define GETSOUNDVOLUME_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_StopMusic 317
#define FN_StopSound 318
#define STOPSOUND_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetChannelPanning 319
#define SETCHANNELPANNING_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCHANNELPANNING_LEFT_VALUE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCHANNELPANNING_RIGHT_VALUE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetChannelDistance 320
#define SETCHANNELDISTANCE_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCHANNELDISTANCE_DIST_VALUE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ChannelIsPlaying 321
#define CHANNELISPLAYING_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ChannelIsPaused 322
#define CHANNELISPAUSED_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_QueryAudioSpec 323
#define QUERYAUDIOSPEC_FREQ num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define QUERYAUDIOSPEC_FORMAT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define QUERYAUDIOSPEC_CHANNELS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_MusicIsPlaying 324
#define FN_SetChannelSpacePosition 325
#define SETCHANNELSPACEPOSITION_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCHANNELSPACEPOSITION_ANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCHANNELSPACEPOSITION_DISTANCE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_NumJoysticks 326
#define FN_NumJoyAxes 327
#define NUMJOYAXES_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumJoyButtons 328
#define NUMJOYBUTTONS_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumJoyHats 329
#define NUMJOYHATS_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumJoyTrackBalls 330
#define NUMJOYTRACKBALLS_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_JoyAxis 331
#define JOYAXIS_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define JOYAXIS_JOY_AXIS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_JoyButton 332
#define JOYBUTTON_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define JOYBUTTON_JOY_BUTTON num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_JoyHat 333
#define JOYHAT_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define JOYHAT_JOY_HAT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetJoyTrackBall 334
#define GETJOYTRACKBALL_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOYTRACKBALL_BALL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOYTRACKBALL_DX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETJOYTRACKBALL_DY num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_JoyName$ 335
#define JOYNAME$_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_JoystickIsConnected 336
#define JOYSTICKISCONNECTED_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_JoyRumblePlay 337
#define JOYRUMBLEPLAY_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define JOYRUMBLEPLAY_STRENGTH num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define JOYRUMBLEPLAY_DURATION num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_JoyRumbleStop 338
#define JOYRUMBLESTOP_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_JoystickIsHaptic 339
#define JOYSTICKISHAPTIC_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_LoadFont 340
#define LOADFONT_FNT_FILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define LOADFONT_FONT_SIZE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteFont 341
#define DELETEFONT_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_FontExists 342
#define FONTEXISTS_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetFont 343
#define SETFONT_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DrawText 344
#define DRAWTEXT_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define DRAWTEXT_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWTEXT_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetTextSize 345
#define GETTEXTSIZE_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define GETTEXTSIZE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTEXTSIZE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_TextWidth 346
#define TEXTWIDTH_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_TextHeight 347
#define TEXTHEIGHT_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_ActiveFont 348
#define FN_TouchPressure 349
#define FN_GetTouch 350
#define GETTOUCH_STATUS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTOUCH_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTOUCH_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETTOUCH_DX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETTOUCH_DY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_GetMultiTouch 351
#define GETMULTITOUCH_STATUS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMULTITOUCH_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMULTITOUCH_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETMULTITOUCH_FINGERS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETMULTITOUCH_DIST num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETMULTITOUCH_THETA num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_GetTouchFinger 352
#define GETTOUCHFINGER_FINGER num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTOUCHFINGER_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTOUCHFINGER_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETTOUCHFINGER_PRESSURE num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_NumFingers 353
#define FN_GetAccel 354
#define GETACCEL_ACCEL_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACCEL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACCEL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACCEL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_AccelName$ 355
#define ACCELNAME$_ACCEL_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumAccels 356
#define FN_GetGyro 357
#define GETGYRO_GYRO_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETGYRO_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETGYRO_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETGYRO_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GyroName$ 358
#define GYRONAME$_GYRO_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumGyros 359
#define FN_TouchX 360
#define FN_TouchY 361
#define FN_CheckSockets 362
#define CHECKSOCKETS_TIMEOUT_MS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TCP_SocketReady 363
#define TCP_SOCKETREADY_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_UDP_SocketReady 364
#define UDP_SOCKETREADY_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TCP_OpenSocket 365
#define TCP_OPENSOCKET_HOST$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define TCP_OPENSOCKET_PORT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TCP_CloseSocket 366
#define TCP_CLOSESOCKET_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TCP_RemoteHost 367
#define TCP_REMOTEHOST_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TCP_RemotePort 368
#define TCP_REMOTEPORT_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TCP_GetData 369
#define TCP_GETDATA_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TCP_GETDATA_NUMBYTES num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define TCP_GETDATA_SDATA$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_TCP_SendData 370
#define TCP_SENDDATA_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TCP_SENDDATA_SDATA$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_TCP_AcceptSocket 371
#define TCP_ACCEPTSOCKET_SERVER num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_UDP_OpenSocket 372
#define UDP_OPENSOCKET_PORT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_UDP_CloseSocket 373
#define UDP_CLOSESOCKET_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_UDP_GetData 374
#define UDP_GETDATA_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define UDP_GETDATA_HOST$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define UDP_GETDATA_PORT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define UDP_GETDATA_SDATA$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_UDP_Length 375
#define FN_UDP_MaxLength 376
#define FN_UDP_RemoteHost$ 377
#define UDP_REMOTEHOST$_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_UDP_RemotePort 378
#define UDP_REMOTEPORT_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_UDP_SendData 379
#define UDP_SENDDATA_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define UDP_SENDDATA_HOST$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define UDP_SENDDATA_PORT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define UDP_SENDDATA_SDATA$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_LoadVideo 380
#define LOADVIDEO_VID$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_PlayVideo 381
#define PLAYVIDEO_VLOOPS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_PauseVideo 382
#define FN_StopVideo 383
#define FN_SetVideoPosition 384
#define SETVIDEOPOSITION_POS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ResumeVideo 385
#define FN_GetVideoPosition 386
#define FN_DeleteVideo 387
#define FN_VideoIsPlaying 388
#define FN_VideoEnd 389
#define FN_GetVideoStats 390
#define GETVIDEOSTATS_VFILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define GETVIDEOSTATS_VLEN num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETVIDEOSTATS_VFPS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETVIDEOSTATS_FRAME_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETVIDEOSTATS_FRAME_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetVideoDrawRect 391
#define SETVIDEODRAWRECT_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETVIDEODRAWRECT_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETVIDEODRAWRECT_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETVIDEODRAWRECT_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetVideoDrawRect 392
#define GETVIDEODRAWRECT_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETVIDEODRAWRECT_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETVIDEODRAWRECT_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETVIDEODRAWRECT_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetVideoSize 393
#define GETVIDEOSIZE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETVIDEOSIZE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_VideoExists 394
#define FN_SetVideoVolume 395
#define SETVIDEOVOLUME_VOL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetVideoVolume 396
#define FN_System 397
#define SYSTEM_CMD$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_OS$ 398
#define FN_Command$ 399
#define COMMAND$_ARG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumCommands 400
#define FN_Env$ 401
#define ENV$_V$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_SetEnv 402
#define SETENV_VAR$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define SETENV_VALUE$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_PrefPath$ 403
#define PREFPATH$_ORG_NAME$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define PREFPATH$_APP_NAME$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_Android_GetExternalStoragePath$ 404
#define FN_Android_GetExternalStorageState 405
#define FN_Android_GetInternalStoragePath$ 406
#define FN_Android_JNI_Message$ 407
#define ANDROID_JNI_MESSAGE$_ARG$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Runtime_Utility_Message$ 408
#define RUNTIME_UTILITY_MESSAGE$_ARG$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_GetDesktopDisplayMode 409
#define GETDESKTOPDISPLAYMODE_INDEX num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETDESKTOPDISPLAYMODE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETDESKTOPDISPLAYMODE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETDESKTOPDISPLAYMODE_FREQ num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetPowerInfo 410
#define GETPOWERINFO_STATUS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPOWERINFO_SECS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPOWERINFO_PCT num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_EvalJS$ 411
#define EVALJS$_JS_CODE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_SystemReturnStdOut$ 412
#define SYSTEMRETURNSTDOUT$_CMD$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_OpenURL 413
#define OPENURL_URL$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_MessageBox 414
#define MESSAGEBOX_TITLE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define MESSAGEBOX_MSG$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_Runtime$ 415
#define FN_NumCPUs 416
#define FN_SystemRam 417
#define FN_GetGPUInfo$ 418
#define FN_Steam_AddAchievement 419
#define STEAM_ADDACHIEVEMENT_ACH_ID$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define STEAM_ADDACHIEVEMENT_ACH_NAME$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_Steam_ClearAchievements 420
#define FN_Steam_FinalizeAchievements 421
#define FN_Steam_TriggerAchievement 422
#define STEAM_TRIGGERACHIEVEMENT_ACH_NAME$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Steam_GetID$ 423
#define FN_DimMatrix 424
#define DIMMATRIX_M_ROWS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DIMMATRIX_M_COLS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_DeleteMatrix 425
#define DELETEMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_AddMatrix 426
#define ADDMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ADDMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ADDMATRIX_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_AugmentMatrix 427
#define AUGMENTMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define AUGMENTMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define AUGMENTMATRIX_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_CopyMatrix 428
#define COPYMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COPYMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_InsertMatrixColumns 429
#define INSERTMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define INSERTMATRIXCOLUMNS_C num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define INSERTMATRIXCOLUMNS_NUM_COLS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_InsertMatrixRows 430
#define INSERTMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define INSERTMATRIXROWS_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define INSERTMATRIXROWS_NUM_ROWS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_MultiplyMatrix 431
#define MULTIPLYMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define MULTIPLYMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define MULTIPLYMATRIX_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_CubeMatrix 432
#define CUBEMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CUBEMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_DeleteMatrixColumns 433
#define DELETEMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DELETEMATRIXCOLUMNS_C num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DELETEMATRIXCOLUMNS_NUM_COLS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_DeleteMatrixRows 434
#define DELETEMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DELETEMATRIXROWS_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DELETEMATRIXROWS_NUM_ROWS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ClearMatrix 435
#define CLEARMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ClearMatrixColumns 436
#define CLEARMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CLEARMATRIXCOLUMNS_C num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CLEARMATRIXCOLUMNS_NUM_COLS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ClearMatrixRows 437
#define CLEARMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CLEARMATRIXROWS_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CLEARMATRIXROWS_NUM_ROWS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_FillMatrix 438
#define FILLMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FILLMATRIX_V num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_FillMatrixColumns 439
#define FILLMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FILLMATRIXCOLUMNS_C num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FILLMATRIXCOLUMNS_NUM_COLS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FILLMATRIXCOLUMNS_V num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_FillMatrixRows 440
#define FILLMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FILLMATRIXROWS_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FILLMATRIXROWS_NUM_ROWS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FILLMATRIXROWS_V num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_CopyMatrixColumns 441
#define COPYMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COPYMATRIXCOLUMNS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COPYMATRIXCOLUMNS_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define COPYMATRIXCOLUMNS_NUM_COLS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_CopyMatrixRows 442
#define COPYMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COPYMATRIXROWS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COPYMATRIXROWS_R num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define COPYMATRIXROWS_NUM_ROWS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetIdentityMatrix 443
#define SETIDENTITYMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETIDENTITYMATRIX_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SolveMatrix 444
#define SOLVEMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SOLVEMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SOLVEMATRIX_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_IsEqualMatrix 445
#define ISEQUALMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ISEQUALMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ISEQUALMATRIX_TOLERANCE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_Determinant 446
#define DETERMINANT_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_AdjointMatrix 447
#define ADJOINTMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ADJOINTMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_InvertMatrix 448
#define INVERTMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define INVERTMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_MatrixFromBuffer 449
#define MATRIXFROMBUFFER_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define MATRIXFROMBUFFER_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define MATRIXFROMBUFFER_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define MATRIXFROMBUFFER_BUFFER num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_BufferFromMatrix 450
#define BUFFERFROMMATRIX_BUFFER num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define BUFFERFROMMATRIX_MA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_RandomizeMatrix 451
#define RANDOMIZEMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define RANDOMIZEMATRIX_VMIN num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define RANDOMIZEMATRIX_VMAX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_MatrixValue 452
#define MATRIXVALUE_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define MATRIXVALUE_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define MATRIXVALUE_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetMatrixValue 453
#define SETMATRIXVALUE_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATRIXVALUE_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATRIXVALUE_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETMATRIXVALUE_V num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_ScalarMatrix 454
#define SCALARMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SCALARMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SCALARMATRIX_S_VALUE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ScalarMatrixColumns 455
#define SCALARMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SCALARMATRIXCOLUMNS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SCALARMATRIXCOLUMNS_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SCALARMATRIXCOLUMNS_NUM_COLS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SCALARMATRIXCOLUMNS_S_VALUE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_ScalarMatrixRows 456
#define SCALARMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SCALARMATRIXROWS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SCALARMATRIXROWS_R num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SCALARMATRIXROWS_NUM_ROWS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SCALARMATRIXROWS_S_VALUE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_SquareMatrix 457
#define SQUAREMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SQUAREMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_CofactorMatrix 458
#define COFACTORMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COFACTORMATRIX_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COFACTORMATRIX_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SubtractMatrix 459
#define SUBTRACTMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SUBTRACTMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SUBTRACTMATRIX_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SwapMatrix 460
#define SWAPMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SWAPMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SwapMatrixColumn 461
#define SWAPMATRIXCOLUMN_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SWAPMATRIXCOLUMN_C1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SWAPMATRIXCOLUMN_C2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SwapMatrixRow 462
#define SWAPMATRIXROW_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SWAPMATRIXROW_R1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SWAPMATRIXROW_R2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_TransposeMatrix 463
#define TRANSPOSEMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TRANSPOSEMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_UnAugmentMatrix 464
#define UNAUGMENTMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define UNAUGMENTMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define UNAUGMENTMATRIX_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ZeroMatrix 465
#define ZEROMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetMatrixSize 466
#define GETMATRIXSIZE_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMATRIXSIZE_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMATRIXSIZE_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_IncrementMatrixRows 467
#define INCREMENTMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define INCREMENTMATRIXROWS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define INCREMENTMATRIXROWS_R num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define INCREMENTMATRIXROWS_NUM_ROWS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define INCREMENTMATRIXROWS_VALUE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_IncrementMatrixColumns 468
#define INCREMENTMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define INCREMENTMATRIXCOLUMNS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define INCREMENTMATRIXCOLUMNS_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define INCREMENTMATRIXCOLUMNS_NUM_COLS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define INCREMENTMATRIXCOLUMNS_VALUE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_JoinMatrixRows 469
#define JOINMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define JOINMATRIXROWS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define JOINMATRIXROWS_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_JoinMatrixColumns 470
#define JOINMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define JOINMATRIXCOLUMNS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define JOINMATRIXCOLUMNS_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ClipMatrix 471
#define CLIPMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CLIPMATRIX_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CLIPMATRIX_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CLIPMATRIX_NUM_ROWS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CLIPMATRIX_NUM_COLS num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CLIPMATRIX_MB num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_SetMatrixTranslation 472
#define SETMATRIXTRANSLATION_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATRIXTRANSLATION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATRIXTRANSLATION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETMATRIXTRANSLATION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetMatrixRotation 473
#define SETMATRIXROTATION_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATRIXROTATION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATRIXROTATION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETMATRIXROTATION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetMatrixScale 474
#define SETMATRIXSCALE_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATRIXSCALE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATRIXSCALE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETMATRIXSCALE_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetMatrixTranslation 475
#define GETMATRIXTRANSLATION_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMATRIXTRANSLATION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMATRIXTRANSLATION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETMATRIXTRANSLATION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetMatrixRotation 476
#define GETMATRIXROTATION_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMATRIXROTATION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMATRIXROTATION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETMATRIXROTATION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetMatrixScale 477
#define GETMATRIXSCALE_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMATRIXSCALE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMATRIXSCALE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETMATRIXSCALE_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_MatrixExists 478
#define MATRIXEXISTS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetClipboardText$ 479
#define FN_SetClipboardText 480
#define SETCLIPBOARDTEXT_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_HasClipboardText 481
#define FN_ReadInput_Start 482
#define FN_ReadInput_Stop 483
#define FN_ReadInput_GetText$ 484
#define FN_ReadInput_SetText 485
#define READINPUT_SETTEXT_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_ReadInput_ToggleBackspace 486
#define READINPUT_TOGGLEBACKSPACE_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateSprite 487
#define CREATESPRITE_IMG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATESPRITE_FRAME_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATESPRITE_FRAME_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_DeleteSprite 488
#define DELETESPRITE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpritePosition 489
#define SETSPRITEPOSITION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEPOSITION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITEPOSITION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_TranslateSprite 490
#define TRANSLATESPRITE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TRANSLATESPRITE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define TRANSLATESPRITE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetSpritePosition 491
#define GETSPRITEPOSITION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEPOSITION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITEPOSITION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SpriteX 492
#define SPRITEX_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SpriteY 493
#define SPRITEY_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteRotation 494
#define SETSPRITEROTATION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEROTATION_ANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_RotateSprite 495
#define ROTATESPRITE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ROTATESPRITE_ANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteRotation 496
#define GETSPRITEROTATION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteScale 497
#define SETSPRITESCALE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITESCALE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITESCALE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ScaleSprite 498
#define SCALESPRITE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SCALESPRITE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SCALESPRITE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetSpriteScale 499
#define GETSPRITESCALE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITESCALE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITESCALE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetSpriteZ 500
#define SETSPRITEZ_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEZ_Z num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SpriteZ 501
#define SPRITEZ_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetSpriteSize 502
#define GETSPRITESIZE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITESIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITESIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SpriteWidth 503
#define SPRITEWIDTH_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SpriteHeight 504
#define SPRITEHEIGHT_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteVisible 505
#define SETSPRITEVISIBLE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEVISIBLE_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SpriteIsVisible 506
#define SPRITEISVISIBLE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteSolid 507
#define SETSPRITESOLID_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITESOLID_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SpriteIsSolid 508
#define SPRITEISSOLID_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteType 509
#define SETSPRITETYPE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITETYPE_SPRITE_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteType 510
#define GETSPRITETYPE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteSource 511
#define SETSPRITESOURCE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITESOURCE_IMG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteSource 512
#define GETSPRITESOURCE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SpriteExists 513
#define SPRITEEXISTS_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteColorMod 514
#define SETSPRITECOLORMOD_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITECOLORMOD_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetSpriteAlpha 515
#define SETSPRITEALPHA_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEALPHA_ALPHA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteColorMod 516
#define GETSPRITECOLORMOD_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetSpriteAlpha 517
#define GETSPRITEALPHA_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_AddSpriteChild 518
#define ADDSPRITECHILD_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ADDSPRITECHILD_CHILD_SPRITE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ADDSPRITECHILD_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define ADDSPRITECHILD_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_RemoveSpriteChild 519
#define REMOVESPRITECHILD_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define REMOVESPRITECHILD_CHILD_INDEX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteChildIndex 520
#define GETSPRITECHILDINDEX_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITECHILDINDEX_CHILD_SPRITE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_CreateSpriteAnimation 521
#define CREATESPRITEANIMATION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATESPRITEANIMATION_ANIM_LENGTH num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATESPRITEANIMATION_SPEED num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetSpriteFrame 522
#define SETSPRITEFRAME_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEFRAME_FRAME num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteFrame 523
#define GETSPRITEFRAME_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteAnimationFrame 524
#define SETSPRITEANIMATIONFRAME_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEANIMATIONFRAME_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITEANIMATIONFRAME_ANIM_FRAME num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETSPRITEANIMATIONFRAME_FRAME num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetSpriteAnimationFrame 525
#define GETSPRITEANIMATIONFRAME_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEANIMATIONFRAME_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITEANIMATIONFRAME_ANIM_FRAME num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetSpriteAnimationLength 526
#define SETSPRITEANIMATIONLENGTH_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEANIMATIONLENGTH_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITEANIMATIONLENGTH_ANIM_LENGTH num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetSpriteAnimationLength 527
#define GETSPRITEANIMATIONLENGTH_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEANIMATIONLENGTH_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetSpriteAnimationSpeed 528
#define SETSPRITEANIMATIONSPEED_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEANIMATIONSPEED_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITEANIMATIONSPEED_SPEED num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetSpriteAnimationSpeed 529
#define GETSPRITEANIMATIONSPEED_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEANIMATIONSPEED_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetSpriteAnimation 530
#define SETSPRITEANIMATION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEANIMATION_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITEANIMATION_NUM_LOOPS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetSpriteAnimation 531
#define GETSPRITEANIMATION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetSpriteCurrentAnimationFrame 532
#define GETSPRITECURRENTANIMATIONFRAME_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumSpriteAnimationLoops 533
#define NUMSPRITEANIMATIONLOOPS_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SpriteAnimationIsPlaying 534
#define SPRITEANIMATIONISPLAYING_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteSpriteAnimation 535
#define DELETESPRITEANIMATION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DELETESPRITEANIMATION_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteAnimationSource 536
#define GETSPRITEANIMATIONSOURCE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEANIMATIONSOURCE_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getSpriteCenter 537
#define GETSPRITECENTER_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITECENTER_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITECENTER_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setSpriteLinearVelocity 538
#define SETSPRITELINEARVELOCITY_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITELINEARVELOCITY_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITELINEARVELOCITY_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getSpriteLinearVelocity 539
#define GETSPRITELINEARVELOCITY_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITELINEARVELOCITY_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITELINEARVELOCITY_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setSpriteAngularVelocity 540
#define SETSPRITEANGULARVELOCITY_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEANGULARVELOCITY_AV num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getSpriteAngularVelocity 541
#define GETSPRITEANGULARVELOCITY_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_applySpriteForce 542
#define APPLYSPRITEFORCE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYSPRITEFORCE_FX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYSPRITEFORCE_FY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYSPRITEFORCE_PX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define APPLYSPRITEFORCE_PY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_applySpriteCentralForce 543
#define APPLYSPRITECENTRALFORCE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYSPRITECENTRALFORCE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYSPRITECENTRALFORCE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_applySpriteTorque 544
#define APPLYSPRITETORQUE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYSPRITETORQUE_TORQUE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_applySpriteLinearImpulse 545
#define APPLYSPRITELINEARIMPULSE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYSPRITELINEARIMPULSE_IX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYSPRITELINEARIMPULSE_IY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYSPRITELINEARIMPULSE_PX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define APPLYSPRITELINEARIMPULSE_PY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_applySpriteAngularImpulse 546
#define APPLYSPRITEANGULARIMPULSE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYSPRITEANGULARIMPULSE_IMPULSE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getSpriteMass 547
#define GETSPRITEMASS_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSpriteInertia 548
#define GETSPRITEINERTIA_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSpriteWorldPoint 549
#define GETSPRITEWORLDPOINT_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEWORLDPOINT_LX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITEWORLDPOINT_LY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITEWORLDPOINT_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITEWORLDPOINT_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getSpriteWorldVector 550
#define GETSPRITEWORLDVECTOR_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEWORLDVECTOR_LX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITEWORLDVECTOR_LY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITEWORLDVECTOR_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITEWORLDVECTOR_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getSpriteLocalPoint 551
#define GETSPRITELOCALPOINT_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITELOCALPOINT_WX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITELOCALPOINT_WY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITELOCALPOINT_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITELOCALPOINT_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getSpriteLocalVector 552
#define GETSPRITELOCALVECTOR_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITELOCALVECTOR_WX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITELOCALVECTOR_WY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITELOCALVECTOR_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITELOCALVECTOR_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getSpriteLinearVelocityFromLocalPoint 553
#define GETSPRITELINEARVELOCITYFROMLOCALPOINT_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMLOCALPOINT_PX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMLOCALPOINT_PY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMLOCALPOINT_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMLOCALPOINT_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getSpriteLinearVelocityFromWorldPoint 554
#define GETSPRITELINEARVELOCITYFROMWORLDPOINT_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMWORLDPOINT_WX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMWORLDPOINT_WY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMWORLDPOINT_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMWORLDPOINT_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getSpriteLinearDamping 555
#define GETSPRITELINEARDAMPING_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSpriteLinearDamping 556
#define SETSPRITELINEARDAMPING_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITELINEARDAMPING_LINEARDAMPING num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getSpriteAngularDamping 557
#define GETSPRITEANGULARDAMPING_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSpriteAngularDamping 558
#define SETSPRITEANGULARDAMPING_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEANGULARDAMPING_ANGULARDAMPING num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getSpriteGravityScale 559
#define GETSPRITEGRAVITYSCALE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSpriteGravityScale 560
#define SETSPRITEGRAVITYSCALE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEGRAVITYSCALE_G_SCALE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSpriteBullet 561
#define SETSPRITEBULLET_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEBULLET_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_spriteIsBullet 562
#define SPRITEISBULLET_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSpriteSleepAllowed 563
#define SETSPRITESLEEPALLOWED_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITESLEEPALLOWED_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_spriteSleepAllowed 564
#define SPRITESLEEPALLOWED_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSpriteAwake 565
#define SETSPRITEAWAKE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEAWAKE_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_spriteIsAwake 566
#define SPRITEISAWAKE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSpriteFixedRotation 567
#define SETSPRITEFIXEDROTATION_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEFIXEDROTATION_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_spriteIsFixedRotation 568
#define SPRITEISFIXEDROTATION_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteDensity 569
#define SETSPRITEDENSITY_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEDENSITY_DENSITY num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteDensity 570
#define GETSPRITEDENSITY_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteFriction 571
#define SETSPRITEFRICTION_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEFRICTION_FRICTION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteFriction 572
#define GETSPRITEFRICTION_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteRestitution 573
#define SETSPRITERESTITUTION_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITERESTITUTION_RESTITUTION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteRestitution 574
#define GETSPRITERESTITUTION_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteRestitutionThreshold 575
#define SETSPRITERESTITUTIONTHRESHOLD_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITERESTITUTIONTHRESHOLD_THRESHOLD num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteRestitutionThreshold 576
#define GETSPRITERESTITUTIONTHRESHOLD_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetSpriteAABB 577
#define GETSPRITEAABB_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEAABB_X1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITEAABB_Y1 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITEAABB_X2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITEAABB_Y2 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_SetGravity2D 578
#define SETGRAVITY2D_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETGRAVITY2D_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetGravity2D 579
#define GETGRAVITY2D_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETGRAVITY2D_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetWorld2DTimeStep 580
#define SETWORLD2DTIMESTEP_TS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetWorld2DVelocityIterations 581
#define SETWORLD2DVELOCITYITERATIONS_V num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetWorld2DPositionIterations 582
#define SETWORLD2DPOSITIONITERATIONS_P num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetWorld2DTimeStep 583
#define FN_GetWorld2DVelocityIterations 584
#define FN_GetWorld2DPositionIterations 585
#define FN_SetWorld2DAutoClearForces 586
#define SETWORLD2DAUTOCLEARFORCES_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetWorld2DAutoClearForces 587
#define FN_CastRay2D 588
#define CASTRAY2D_FROM_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CASTRAY2D_FROM_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CASTRAY2D_TO_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CASTRAY2D_TO_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_CastRay2D_All 589
#define CASTRAY2D_ALL_FROM_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CASTRAY2D_ALL_FROM_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CASTRAY2D_ALL_TO_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CASTRAY2D_ALL_TO_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetRayHit2D 590
#define GETRAYHIT2D_INDEX num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETRAYHIT2D_SPR_ID num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETRAYHIT2D_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETRAYHIT2D_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETRAYHIT2D_NORMAL_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETRAYHIT2D_NORMAL_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_SetSpriteShape 591
#define SETSPRITESHAPE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITESHAPE_SHAPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteShape 592
#define GETSPRITESHAPE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteRadius 593
#define SETSPRITERADIUS_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITERADIUS_RADIUS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteRadius 594
#define GETSPRITERADIUS_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteBox 595
#define SETSPRITEBOX_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEBOX_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITEBOX_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetSpriteBoxSize 596
#define GETSPRITEBOXSIZE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEBOXSIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITEBOXSIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetSpriteChain 597
#define SETSPRITECHAIN_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITECHAIN_VX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITECHAIN_VY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETSPRITECHAIN_V_COUNT num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETSPRITECHAIN_PREV_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define SETSPRITECHAIN_PREV_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define SETSPRITECHAIN_NEXT_X num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define SETSPRITECHAIN_NEXT_Y num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define FN_SetSpriteChainLoop 598
#define SETSPRITECHAINLOOP_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITECHAINLOOP_VX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITECHAINLOOP_VY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETSPRITECHAINLOOP_V_COUNT num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetSpritePolygon 599
#define SETSPRITEPOLYGON_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEPOLYGON_VX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITEPOLYGON_VY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETSPRITEPOLYGON_V_COUNT num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetSpriteShapeOffset 600
#define SETSPRITESHAPEOFFSET_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITESHAPEOFFSET_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITESHAPEOFFSET_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetSpriteShapeOffset 601
#define GETSPRITESHAPEOFFSET_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITESHAPEOFFSET_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITESHAPEOFFSET_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetSpriteWorldCenter 602
#define GETSPRITEWORLDCENTER_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEWORLDCENTER_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITEWORLDCENTER_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_createDistanceJoint 603
#define CREATEDISTANCEJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEDISTANCEJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEDISTANCEJOINT_AX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEDISTANCEJOINT_AY num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEDISTANCEJOINT_BX num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CREATEDISTANCEJOINT_BY num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define CREATEDISTANCEJOINT_COLLIDE_CONNECT num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_createFrictionJoint 604
#define CREATEFRICTIONJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEFRICTIONJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEFRICTIONJOINT_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEFRICTIONJOINT_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEFRICTIONJOINT_COLLIDE_CONNECT num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_createGearJoint 605
#define CREATEGEARJOINT_JOINTA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEGEARJOINT_JOINTB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEGEARJOINT_G_RATIO num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEGEARJOINT_COLLIDE_CONNECT num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_createMotorJoint 606
#define CREATEMOTORJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEMOTORJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEMOTORJOINT_COLLIDE_CONNECT num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_createPrismaticJoint 607
#define CREATEPRISMATICJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEPRISMATICJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEPRISMATICJOINT_AX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEPRISMATICJOINT_AY num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEPRISMATICJOINT_AXISX num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CREATEPRISMATICJOINT_AXISY num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define CREATEPRISMATICJOINT_COLLIDE_CONNECT num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_createPulleyJoint 608
#define CREATEPULLEYJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEPULLEYJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEPULLEYJOINT_GAX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEPULLEYJOINT_GAY num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEPULLEYJOINT_GBX num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CREATEPULLEYJOINT_GBY num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define CREATEPULLEYJOINT_AX num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define CREATEPULLEYJOINT_AY num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define CREATEPULLEYJOINT_BX num_var[8].nref[0].value[ num_var[8].byref_offset ]
#define CREATEPULLEYJOINT_BY num_var[9].nref[0].value[ num_var[9].byref_offset ]
#define CREATEPULLEYJOINT_J_RATIO num_var[10].nref[0].value[ num_var[10].byref_offset ]
#define CREATEPULLEYJOINT_COLLIDE_CONNECT num_var[11].nref[0].value[ num_var[11].byref_offset ]
#define FN_createRevoluteJoint 609
#define CREATEREVOLUTEJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEREVOLUTEJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEREVOLUTEJOINT_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEREVOLUTEJOINT_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEREVOLUTEJOINT_COLLIDE_CONNECT num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_createWeldJoint 610
#define CREATEWELDJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEWELDJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEWELDJOINT_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEWELDJOINT_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEWELDJOINT_COLLIDE_CONNECT num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_createWheelJoint 611
#define CREATEWHEELJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEWHEELJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEWHEELJOINT_AX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEWHEELJOINT_AY num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEWHEELJOINT_AXISX num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CREATEWHEELJOINT_AXISY num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define CREATEWHEELJOINT_COLLIDE_CONNECT num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_getJointWorldAnchorA 612
#define GETJOINTWORLDANCHORA_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTWORLDANCHORA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTWORLDANCHORA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointWorldAnchorB 613
#define GETJOINTWORLDANCHORB_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTWORLDANCHORB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTWORLDANCHORB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointReactionForce 614
#define GETJOINTREACTIONFORCE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTREACTIONFORCE_INV_DT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTREACTIONFORCE_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETJOINTREACTIONFORCE_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getJointReactionTorque 615
#define GETJOINTREACTIONTORQUE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTREACTIONTORQUE_INV_DT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointLocalAnchorA 616
#define GETJOINTLOCALANCHORA_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTLOCALANCHORA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTLOCALANCHORA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointLocalAnchorB 617
#define GETJOINTLOCALANCHORB_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTLOCALANCHORB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTLOCALANCHORB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setJointLength 618
#define SETJOINTLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTLENGTH_JLEN num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointLength 619
#define GETJOINTLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointMinLength 620
#define SETJOINTMINLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMINLENGTH_JLEN num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMinLength 621
#define GETJOINTMINLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointMaxLength 622
#define SETJOINTMAXLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMAXLENGTH_JLEN num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMaxLength 623
#define GETJOINTMAXLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointCurrentLength 624
#define GETJOINTCURRENTLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointStiffness 625
#define SETJOINTSTIFFNESS_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTSTIFFNESS_STIFFNESS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointStiffness 626
#define GETJOINTSTIFFNESS_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointDamping 627
#define SETJOINTDAMPING_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTDAMPING_DAMPING num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointDamping 628
#define GETJOINTDAMPING_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointMaxForce 629
#define SETJOINTMAXFORCE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMAXFORCE_FORCE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMaxForce 630
#define GETJOINTMAXFORCE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointMaxTorque 631
#define SETJOINTMAXTORQUE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMAXTORQUE_TORQUE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMaxTorque 632
#define GETJOINTMAXTORQUE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointCorrectionFactor 633
#define SETJOINTCORRECTIONFACTOR_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTCORRECTIONFACTOR_FACTOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointCorrectionFactor 634
#define GETJOINTCORRECTIONFACTOR_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointRatio 635
#define SETJOINTRATIO_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTRATIO_J_RATIO num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointRatio 636
#define GETJOINTRATIO_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointLinearOffset 637
#define SETJOINTLINEAROFFSET_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTLINEAROFFSET_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETJOINTLINEAROFFSET_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointLinearOffset 638
#define GETJOINTLINEAROFFSET_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTLINEAROFFSET_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTLINEAROFFSET_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setJointAngularOffset 639
#define SETJOINTANGULAROFFSET_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTANGULAROFFSET_ANGLEOFFSET num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointAngularOffset 640
#define GETJOINTANGULAROFFSET_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointLocalAxisA 641
#define GETJOINTLOCALAXISA_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTLOCALAXISA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTLOCALAXISA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointReferenceAngle 642
#define GETJOINTREFERENCEANGLE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointTranslation 643
#define GETJOINTTRANSLATION_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointSpeed 644
#define GETJOINTSPEED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_jointIsLimitEnabled 645
#define JOINTISLIMITENABLED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_enableJointLimit 646
#define ENABLEJOINTLIMIT_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ENABLEJOINTLIMIT_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointLowerLimit 647
#define GETJOINTLOWERLIMIT_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointUpperLimit 648
#define GETJOINTUPPERLIMIT_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointLimits 649
#define SETJOINTLIMITS_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTLIMITS_LOWER_LIMIT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETJOINTLIMITS_UPPER_LIMIT num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_jointMotorIsEnabled 650
#define JOINTMOTORISENABLED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_enableJointMotor 651
#define ENABLEJOINTMOTOR_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ENABLEJOINTMOTOR_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setJointMotorSpeed 652
#define SETJOINTMOTORSPEED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMOTORSPEED_SPEED num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMotorSpeed 653
#define GETJOINTMOTORSPEED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointMaxMotorForce 654
#define SETJOINTMAXMOTORFORCE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMAXMOTORFORCE_FORCE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMaxMotorForce 655
#define GETJOINTMAXMOTORFORCE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointMotorForce 656
#define GETJOINTMOTORFORCE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTMOTORFORCE_INV_DT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setJointMaxMotorTorque 657
#define SETJOINTMAXMOTORTORQUE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMAXMOTORTORQUE_TORQUE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMaxMotorTorque 658
#define GETJOINTMAXMOTORTORQUE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointMotorTorque 659
#define GETJOINTMOTORTORQUE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTMOTORTORQUE_INV_DT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointGroundAnchorA 660
#define GETJOINTGROUNDANCHORA_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTGROUNDANCHORA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTGROUNDANCHORA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointGroundAnchorB 661
#define GETJOINTGROUNDANCHORB_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTGROUNDANCHORB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTGROUNDANCHORB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointLengthA 662
#define GETJOINTLENGTHA_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointLengthB 663
#define GETJOINTLENGTHB_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointCurrentLengthA 664
#define GETJOINTCURRENTLENGTHA_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointCurrentLengthB 665
#define GETJOINTCURRENTLENGTHB_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointOrigin 666
#define SETJOINTORIGIN_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTORIGIN_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETJOINTORIGIN_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointAngle 667
#define GETJOINTANGLE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointLinearSpeed 668
#define GETJOINTLINEARSPEED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointAngularSpeed 669
#define GETJOINTANGULARSPEED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteJoint 670
#define DELETEJOINT_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_JointExists 671
#define JOINTEXISTS_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateTileSet 672
#define CREATETILESET_IMG_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATETILESET_TILE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATETILESET_TILE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetTileAnimationLength 673
#define SETTILEANIMATIONLENGTH_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTILEANIMATIONLENGTH_BASE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTILEANIMATIONLENGTH_NUM_FRAMES num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetTileAnimationLength 674
#define GETTILEANIMATIONLENGTH_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTILEANIMATIONLENGTH_BASE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetTileAnimationFrame 675
#define SETTILEANIMATIONFRAME_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTILEANIMATIONFRAME_BASE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTILEANIMATIONFRAME_ANIM_FRAME num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETTILEANIMATIONFRAME_TILE_FRAME num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetTileAnimationFrame 676
#define GETTILEANIMATIONFRAME_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTILEANIMATIONFRAME_BASE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTILEANIMATIONFRAME_ANIM_FRAME num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetTileAnimationSpeed 677
#define SETTILEANIMATIONSPEED_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTILEANIMATIONSPEED_BASE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTILEANIMATIONSPEED_SPEED num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetTileAnimationSpeed 678
#define GETTILEANIMATIONSPEED_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTILEANIMATIONSPEED_BASE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_CreateTileMap 679
#define CREATETILEMAP_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATETILEMAP_WIDTHINTILES num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATETILEMAP_HEIGHTINTILES num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetTileMapSize 680
#define SETTILEMAPSIZE_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTILEMAPSIZE_WIDTHINTILES num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTILEMAPSIZE_HEIGHTINTILES num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetTileMapSize 681
#define GETTILEMAPSIZE_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTILEMAPSIZE_WIDTHINTILES num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTILEMAPSIZE_HEIGHTINTILES num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetTile 682
#define SETTILE_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTILE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTILE_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETTILE_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetTile 683
#define GETTILE_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTILE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTILE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_FillTile 684
#define FILLTILE_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FILLTILE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FILLTILE_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FILLTILE_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FILLTILE_WIDTHINTILES num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FILLTILE_HEIGHTINTILES num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_DrawTileMap 685
#define DRAWTILEMAP_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWTILEMAP_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWTILEMAP_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWTILEMAP_W num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWTILEMAP_H num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define DRAWTILEMAP_OFFSET_X num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define DRAWTILEMAP_OFFSET_Y num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_DeleteTileSet 686
#define DELETETILESET_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteTileMap 687
#define DELETETILEMAP_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TileSetExists 688
#define TILESETEXISTS_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TileMapExists 689
#define TILEMAPEXISTS_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_LoadMesh 690
#define LOADMESH_MESH_FILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_DeleteMesh 691
#define DELETEMESH_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateMesh 692
#define FN_AddMeshBuffer 693
#define ADDMESHBUFFER_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ADDMESHBUFFER_VERTEX_COUNT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ADDMESHBUFFER_VERTEX_DATA num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define ADDMESHBUFFER_NORMAL_DATA num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define ADDMESHBUFFER_UV_DATA num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define ADDMESHBUFFER_INDEX_COUNT num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define ADDMESHBUFFER_INDEX_DATA num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_LoadMeshFromArchive 694
#define LOADMESHFROMARCHIVE_ARCHIVE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define LOADMESHFROMARCHIVE_MESH_FILE$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_CreatePlaneMesh 695
#define CREATEPLANEMESH_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEPLANEMESH_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEPLANEMESH_TILECOUNT_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEPLANEMESH_TILECOUNT_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEPLANEMESH_TXREPEAT_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CREATEPLANEMESH_TXREPEAT_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_LoadAN8 696
#define LOADAN8_AN8_FILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_LoadMeshFromAN8 697
#define LOADMESHFROMAN8_AN8_PROJECT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define LOADMESHFROMAN8_AN8_SCENE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_GetNumAN8Scenes 698
#define GETNUMAN8SCENES_AN8_PROJECT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetAN8SceneName$ 699
#define GETAN8SCENENAME$_AN8_PROJECT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETAN8SCENENAME$_SCENE_NUM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_CreateConeMesh 700
#define CREATECONEMESH_RADIUS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATECONEMESH_CONE_LENGTH num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATECONEMESH_TESSELATION num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATECONEMESH_TOP_COLOR num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATECONEMESH_BOTTOM_COLOR num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_CreateCylinderMesh 701
#define CREATECYLINDERMESH_RADIUS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATECYLINDERMESH_CYLINDER_LENGTH num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATECYLINDERMESH_TESSELATION num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATECYLINDERMESH_COLOR num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATECYLINDERMESH_CLOSE_TOP num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_CreateVolumeLightMesh 702
#define CREATEVOLUMELIGHTMESH_U num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEVOLUMELIGHTMESH_V num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEVOLUMELIGHTMESH_FOOT_COLOR num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEVOLUMELIGHTMESH_TAIL_COLOR num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEVOLUMELIGHTMESH_LP_DISTANCE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CREATEVOLUMELIGHTMESH_DIM_X num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define CREATEVOLUMELIGHTMESH_DIM_Y num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define CREATEVOLUMELIGHTMESH_DIM_Z num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define FN_DeleteAN8 703
#define DELETEAN8_AN8_PROJECT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetMeshBoundingBox 704
#define SETMESHBOUNDINGBOX_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMESHBOUNDINGBOX_MIN_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMESHBOUNDINGBOX_MIN_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETMESHBOUNDINGBOX_MIN_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETMESHBOUNDINGBOX_MAX_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define SETMESHBOUNDINGBOX_MAX_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define SETMESHBOUNDINGBOX_MAX_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_GetMeshBoundingBox 705
#define GETMESHBOUNDINGBOX_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMESHBOUNDINGBOX_MIN_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMESHBOUNDINGBOX_MIN_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETMESHBOUNDINGBOX_MIN_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETMESHBOUNDINGBOX_MAX_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETMESHBOUNDINGBOX_MAX_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETMESHBOUNDINGBOX_MAX_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_ReCalculateMeshBoundingBox 706
#define RECALCULATEMESHBOUNDINGBOX_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_MakePlanarTextureMap 707
#define MAKEPLANARTEXTUREMAP_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define MAKEPLANARTEXTUREMAP_RESOLUTION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ReCalculateMeshNormals 708
#define RECALCULATEMESHNORMALS_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetMeshPolygonCount 709
#define GETMESHPOLYGONCOUNT_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_FlipMeshSurfaces 710
#define FLIPMESHSURFACES_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetMeshBuffer 711
#define SETMESHBUFFER_MESH_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMESHBUFFER_BUFFER_NUM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMESHBUFFER_VERTEX_COUNT num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETMESHBUFFER_VERTEX_DATA num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETMESHBUFFER_NORMAL_DATA num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define SETMESHBUFFER_UV_DATA num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define SETMESHBUFFER_INDEX_COUNT num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define SETMESHBUFFER_INDEX_DATA num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define FN_GetMeshBufferCount 712
#define GETMESHBUFFERCOUNT_MESH_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetMeshBufferVertexCount 713
#define GETMESHBUFFERVERTEXCOUNT_MESH_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMESHBUFFERVERTEXCOUNT_BUFFER_INDEX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetMeshBufferIndexCount 714
#define GETMESHBUFFERINDEXCOUNT_MESH_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMESHBUFFERINDEXCOUNT_BUFFER_INDEX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetMeshBuffer 715
#define GETMESHBUFFER_MESH_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMESHBUFFER_BUFFER_INDEX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMESHBUFFER_VERTEX_DATA num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETMESHBUFFER_NORMAL_DATA num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETMESHBUFFER_UV_DATA num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETMESHBUFFER_INDEX_DATA num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_CreateAnimatedActor 716
#define CREATEANIMATEDACTOR_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateOctreeActor 717
#define CREATEOCTREEACTOR_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateCubeActor 718
#define CREATECUBEACTOR_CUBE_SIZE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateSphereActor 719
#define CREATESPHEREACTOR_RADIUS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateWaterActor 720
#define CREATEWATERACTOR_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEWATERACTOR_WAVEHEIGHT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEWATERACTOR_WAVESPEED num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEWATERACTOR_WAVELENGTH num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_CreateLightActor 721
#define FN_CreateBillboardActor 722
#define FN_CreateTerrainActor 723
#define CREATETERRAINACTOR_HMAP_FILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_CreateParticleActor 724
#define CREATEPARTICLEACTOR_PARTICLE_TYPE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateProjectorActor 725
#define FN_CreateCompositeActor 726
#define FN_CreateVehicleActor 727
#define CREATEVEHICLEACTOR_CHASSIS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteActor 728
#define DELETEACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetActorTransform 729
#define GETACTORTRANSFORM_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORTRANSFORM_MATRIX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetActorPosition 730
#define SETACTORPOSITION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORPOSITION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORPOSITION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORPOSITION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_TranslateActorLocal 731
#define TRANSLATEACTORLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TRANSLATEACTORLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define TRANSLATEACTORLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define TRANSLATEACTORLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_TranslateActorWorld 732
#define TRANSLATEACTORWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TRANSLATEACTORWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define TRANSLATEACTORWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define TRANSLATEACTORWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetActorPosition 733
#define GETACTORPOSITION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORPOSITION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORPOSITION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORPOSITION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetActorScale 734
#define SETACTORSCALE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORSCALE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORSCALE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORSCALE_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_ScaleActor 735
#define SCALEACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SCALEACTOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SCALEACTOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SCALEACTOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetActorScale 736
#define GETACTORSCALE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORSCALE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORSCALE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORSCALE_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetActorRotation 737
#define SETACTORROTATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORROTATION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORROTATION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORROTATION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_RotateActor 738
#define ROTATEACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ROTATEACTOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ROTATEACTOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define ROTATEACTOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetActorRotation 739
#define GETACTORROTATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORROTATION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORROTATION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORROTATION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetActorVisible 740
#define SETACTORVISIBLE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORVISIBLE_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ActorIsVisible 741
#define ACTORISVISIBLE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetActorAutoCulling 742
#define SETACTORAUTOCULLING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORAUTOCULLING_CULL_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetActorAutoCulling 743
#define GETACTORAUTOCULLING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_AddActorShadow 744
#define ADDACTORSHADOW_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_RemoveActorShadow 745
#define REMOVEACTORSHADOW_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ActorExists 746
#define ACTOREXISTS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetActorType 747
#define GETACTORTYPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateActorAnimation 748
#define CREATEACTORANIMATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEACTORANIMATION_START_FRAME num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEACTORANIMATION_END_FRAME num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEACTORANIMATION_SPEED num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetActorAnimation 749
#define SETACTORANIMATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORANIMATION_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORANIMATION_NUM_LOOPS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetActorAnimationSpeed 750
#define SETACTORANIMATIONSPEED_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORANIMATIONSPEED_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORANIMATIONSPEED_SPEED num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetActorAnimationFrames 751
#define SETACTORANIMATIONFRAMES_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORANIMATIONFRAMES_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORANIMATIONFRAMES_START_FRAME num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORANIMATIONFRAMES_END_FRAME num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetActorCurrentAnimation 752
#define GETACTORCURRENTANIMATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetActorAnimationSpeed 753
#define GETACTORANIMATIONSPEED_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORANIMATIONSPEED_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetActorAnimationStartFrame 754
#define GETACTORANIMATIONSTARTFRAME_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORANIMATIONSTARTFRAME_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetActorAnimationEndFrame 755
#define GETACTORANIMATIONENDFRAME_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORANIMATIONENDFRAME_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetActorFrame 756
#define SETACTORFRAME_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORFRAME_FRAME num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetActorFrame 757
#define GETACTORFRAME_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ActorAnimationIsPlaying 758
#define ACTORANIMATIONISPLAYING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumActorAnimationLoops 759
#define NUMACTORANIMATIONLOOPS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetActorMD2Animation 760
#define SETACTORMD2ANIMATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORMD2ANIMATION_ANIM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORMD2ANIMATION_NUM_LOOPS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetActorMD2AnimationByName 761
#define SETACTORMD2ANIMATIONBYNAME_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORMD2ANIMATIONBYNAME_ANIM_NAME$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define SETACTORMD2ANIMATIONBYNAME_NUM_LOOPS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_DeleteActorAnimation 762
#define DELETEACTORANIMATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DELETEACTORANIMATION_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetActorBoneCount 763
#define GETACTORBONECOUNT_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetActorBoneIndex 764
#define GETACTORBONEINDEX_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORBONEINDEX_BONE_NAME$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_GetActorBoneName$ 765
#define GETACTORBONENAME$_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORBONENAME$_BONE_INDEX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetActorBonePosition 766
#define GETACTORBONEPOSITION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORBONEPOSITION_BONE_INDEX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORBONEPOSITION_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORBONEPOSITION_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETACTORBONEPOSITION_Z num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_GetActorBoneRotation 767
#define GETACTORBONEROTATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORBONEROTATION_BONE_INDEX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORBONEROTATION_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORBONEROTATION_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETACTORBONEROTATION_Z num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_GetActorBoneScale 768
#define GETACTORBONESCALE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORBONESCALE_BONE_INDEX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORBONESCALE_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORBONESCALE_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETACTORBONESCALE_Z num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_GetActorBoneRelativeTranform 769
#define GETACTORBONERELATIVETRANFORM_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORBONERELATIVETRANFORM_BONE_INDEX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORBONERELATIVETRANFORM_T_MATRIX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetActorBoneAbsoluteTranform 770
#define GETACTORBONEABSOLUTETRANFORM_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORBONEABSOLUTETRANFORM_BONE_INDEX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORBONEABSOLUTETRANFORM_T_MATRIX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetGravity3D 771
#define SETGRAVITY3D_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETGRAVITY3D_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETGRAVITY3D_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetGravity3D 772
#define GETGRAVITY3D_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETGRAVITY3D_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETGRAVITY3D_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetActorShape 773
#define SETACTORSHAPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORSHAPE_SHAPE_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORSHAPE_MASS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetActorShape 774
#define GETACTORSHAPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetActorSolid 775
#define SETACTORSOLID_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORSOLID_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ActorIsSolid 776
#define ACTORISSOLID_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetActorCollision 777
#define GETACTORCOLLISION_ACTOR1 num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORCOLLISION_ACTOR2 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetActorGravity 778
#define SETACTORGRAVITY_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORGRAVITY_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORGRAVITY_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORGRAVITY_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetActorGravity 779
#define GETACTORGRAVITY_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORGRAVITY_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORGRAVITY_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORGRAVITY_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorDamping 780
#define SETACTORDAMPING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORDAMPING_LIN_DAMPING num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORDAMPING_ANG_DAMPING num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getActorLinearDamping 781
#define GETACTORLINEARDAMPING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getActorAngularDamping 782
#define GETACTORANGULARDAMPING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getActorLinearSleepThreshold 783
#define GETACTORLINEARSLEEPTHRESHOLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getActorAngularSleepThreshold 784
#define GETACTORANGULARSLEEPTHRESHOLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_applyActorDamping 785
#define APPLYACTORDAMPING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORDAMPING_TIMESTEP num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setActorMassProperties 786
#define SETACTORMASSPROPERTIES_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORMASSPROPERTIES_MASS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORMASSPROPERTIES_INERTIA_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORMASSPROPERTIES_INERTIA_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETACTORMASSPROPERTIES_INERTIA_Z num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getActorLinearFactor 787
#define GETACTORLINEARFACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORLINEARFACTOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORLINEARFACTOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORLINEARFACTOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorLinearFactor 788
#define SETACTORLINEARFACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORLINEARFACTOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORLINEARFACTOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORLINEARFACTOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorInverseMass 789
#define GETACTORINVERSEMASS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_integrateActorVelocities 790
#define INTEGRATEACTORVELOCITIES_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define INTEGRATEACTORVELOCITIES_V_STEP num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_applyActorCentralForceLocal 791
#define APPLYACTORCENTRALFORCELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORCENTRALFORCELOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORCENTRALFORCELOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORCENTRALFORCELOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorCentralForceWorld 792
#define APPLYACTORCENTRALFORCEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORCENTRALFORCEWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORCENTRALFORCEWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORCENTRALFORCEWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorTotalForce 793
#define GETACTORTOTALFORCE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORTOTALFORCE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORTOTALFORCE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORTOTALFORCE_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorTotalTorque 794
#define GETACTORTOTALTORQUE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORTOTALTORQUE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORTOTALTORQUE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORTOTALTORQUE_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorInverseInertiaDiagLocal 795
#define GETACTORINVERSEINERTIADIAGLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORINVERSEINERTIADIAGLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORINVERSEINERTIADIAGLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORINVERSEINERTIADIAGLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorInverseInertiaDiagLocal 796
#define SETACTORINVERSEINERTIADIAGLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORINVERSEINERTIADIAGLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORINVERSEINERTIADIAGLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORINVERSEINERTIADIAGLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorSleepThresholds 797
#define SETACTORSLEEPTHRESHOLDS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORSLEEPTHRESHOLDS_LINEAR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORSLEEPTHRESHOLDS_ANGULAR num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_applyActorTorqueLocal 798
#define APPLYACTORTORQUELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORTORQUELOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORTORQUELOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORTORQUELOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorTorqueWorld 799
#define APPLYACTORTORQUEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORTORQUEWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORTORQUEWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORTORQUEWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorForceLocal 800
#define APPLYACTORFORCELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORFORCELOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORFORCELOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORFORCELOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define APPLYACTORFORCELOCAL_REL_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define APPLYACTORFORCELOCAL_REL_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define APPLYACTORFORCELOCAL_REL_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_applyActorForceWorld 801
#define APPLYACTORFORCEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORFORCEWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORFORCEWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORFORCEWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define APPLYACTORFORCEWORLD_REL_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define APPLYACTORFORCEWORLD_REL_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define APPLYACTORFORCEWORLD_REL_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_applyActorCentralImpulseLocal 802
#define APPLYACTORCENTRALIMPULSELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORCENTRALIMPULSELOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORCENTRALIMPULSELOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORCENTRALIMPULSELOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorCentralImpulseWorld 803
#define APPLYACTORCENTRALIMPULSEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORCENTRALIMPULSEWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORCENTRALIMPULSEWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORCENTRALIMPULSEWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorTorqueImpulseLocal 804
#define APPLYACTORTORQUEIMPULSELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORTORQUEIMPULSELOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORTORQUEIMPULSELOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORTORQUEIMPULSELOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorTorqueImpulseWorld 805
#define APPLYACTORTORQUEIMPULSEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORTORQUEIMPULSEWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORTORQUEIMPULSEWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORTORQUEIMPULSEWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorImpulseLocal 806
#define APPLYACTORIMPULSELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORIMPULSELOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORIMPULSELOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORIMPULSELOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define APPLYACTORIMPULSELOCAL_REL_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define APPLYACTORIMPULSELOCAL_REL_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define APPLYACTORIMPULSELOCAL_REL_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_applyActorImpulseWorld 807
#define APPLYACTORIMPULSEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORIMPULSEWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORIMPULSEWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORIMPULSEWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define APPLYACTORIMPULSEWORLD_REL_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define APPLYACTORIMPULSEWORLD_REL_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define APPLYACTORIMPULSEWORLD_REL_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_clearActorForces 808
#define CLEARACTORFORCES_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_updateActorInertiaTensor 809
#define UPDATEACTORINERTIATENSOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getActorCenter 810
#define GETACTORCENTER_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORCENTER_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORCENTER_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORCENTER_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorRotationQ 811
#define GETACTORROTATIONQ_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORROTATIONQ_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORROTATIONQ_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORROTATIONQ_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETACTORROTATIONQ_W num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getActorLinearVelocityWorld 812
#define GETACTORLINEARVELOCITYWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORLINEARVELOCITYWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORLINEARVELOCITYWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORLINEARVELOCITYWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorAngularVelocityWorld 813
#define GETACTORANGULARVELOCITYWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORANGULARVELOCITYWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORANGULARVELOCITYWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORANGULARVELOCITYWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorLinearVelocityLocal 814
#define SETACTORLINEARVELOCITYLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORLINEARVELOCITYLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORLINEARVELOCITYLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORLINEARVELOCITYLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorLinearVelocityWorld 815
#define SETACTORLINEARVELOCITYWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORLINEARVELOCITYWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORLINEARVELOCITYWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORLINEARVELOCITYWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorAngularVelocityLocal 816
#define SETACTORANGULARVELOCITYLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORANGULARVELOCITYLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORANGULARVELOCITYLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORANGULARVELOCITYLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorAngularVelocityWorld 817
#define SETACTORANGULARVELOCITYWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORANGULARVELOCITYWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORANGULARVELOCITYWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORANGULARVELOCITYWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorVelocityInLocalPoint 818
#define GETACTORVELOCITYINLOCALPOINT_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORVELOCITYINLOCALPOINT_REL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORVELOCITYINLOCALPOINT_REL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORVELOCITYINLOCALPOINT_REL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETACTORVELOCITYINLOCALPOINT_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETACTORVELOCITYINLOCALPOINT_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETACTORVELOCITYINLOCALPOINT_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_getActorLinearVelocityLocal 819
#define GETACTORLINEARVELOCITYLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORLINEARVELOCITYLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORLINEARVELOCITYLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORLINEARVELOCITYLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorAngularVelocityLocal 820
#define GETACTORANGULARVELOCITYLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORANGULARVELOCITYLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORANGULARVELOCITYLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORANGULARVELOCITYLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorAABB 821
#define GETACTORAABB_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORAABB_MIN_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORAABB_MIN_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORAABB_MIN_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETACTORAABB_MAX_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETACTORAABB_MAX_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETACTORAABB_MAX_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_computeActorImpulseDenominator 822
#define COMPUTEACTORIMPULSEDENOMINATOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_POS_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_POS_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_POS_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_NORMAL_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_NORMAL_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_NORMAL_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_computeActorAngularImpulseDenominator 823
#define COMPUTEACTORANGULARIMPULSEDENOMINATOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COMPUTEACTORANGULARIMPULSEDENOMINATOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COMPUTEACTORANGULARIMPULSEDENOMINATOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define COMPUTEACTORANGULARIMPULSEDENOMINATOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorAngularFactor 824
#define SETACTORANGULARFACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORANGULARFACTOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORANGULARFACTOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORANGULARFACTOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorAngularFactor 825
#define GETACTORANGULARFACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORANGULARFACTOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORANGULARFACTOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORANGULARFACTOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_computeActorGyroImpulseLocal 826
#define COMPUTEACTORGYROIMPULSELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COMPUTEACTORGYROIMPULSELOCAL_DT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COMPUTEACTORGYROIMPULSELOCAL_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define COMPUTEACTORGYROIMPULSELOCAL_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define COMPUTEACTORGYROIMPULSELOCAL_Z num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_computeActorGyroImpulseWorld 827
#define COMPUTEACTORGYROIMPULSEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COMPUTEACTORGYROIMPULSEWORLD_DT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COMPUTEACTORGYROIMPULSEWORLD_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define COMPUTEACTORGYROIMPULSEWORLD_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define COMPUTEACTORGYROIMPULSEWORLD_Z num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getActorLocalInertia 828
#define GETACTORLOCALINERTIA_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORLOCALINERTIA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORLOCALINERTIA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORLOCALINERTIA_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetActorSleepState 829
#define SETACTORSLEEPSTATE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORSLEEPSTATE_STATE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_CastRay3D 830
#define CASTRAY3D_FROM_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CASTRAY3D_FROM_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CASTRAY3D_FROM_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CASTRAY3D_TO_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CASTRAY3D_TO_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CASTRAY3D_TO_Z num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_CastRay3D_All 831
#define CASTRAY3D_ALL_FROM_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CASTRAY3D_ALL_FROM_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CASTRAY3D_ALL_FROM_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CASTRAY3D_ALL_TO_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CASTRAY3D_ALL_TO_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CASTRAY3D_ALL_TO_Z num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_GetRayHit3D 832
#define GETRAYHIT3D_INDEX num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETRAYHIT3D_ACTOR_ID num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETRAYHIT3D_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETRAYHIT3D_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETRAYHIT3D_Z num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETRAYHIT3D_NORMAL_X num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETRAYHIT3D_NORMAL_Y num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define GETRAYHIT3D_NORMAL_Z num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define FN_SetActorShapeEx 833
#define SETACTORSHAPEEX_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORSHAPEEX_SHAPE_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORSHAPEEX_MASS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORSHAPEEX_RADIUS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetActorImpactMesh 834
#define SETACTORIMPACTMESH_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORIMPACTMESH_MESH num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORIMPACTMESH_MASS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_createPointConstraint 835
#define CREATEPOINTCONSTRAINT_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEPOINTCONSTRAINT_PXA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEPOINTCONSTRAINT_PYA num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEPOINTCONSTRAINT_PZA num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_createPointConstraintEx 836
#define CREATEPOINTCONSTRAINTEX_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_ACTORB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PXA num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PYA num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PZA num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PXB num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PYB num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PZB num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define FN_setPointPivotA 837
#define SETPOINTPIVOTA_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPOINTPIVOTA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPOINTPIVOTA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETPOINTPIVOTA_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setPointPivotB 838
#define SETPOINTPIVOTB_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPOINTPIVOTB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPOINTPIVOTB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETPOINTPIVOTB_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_createHingeConstraint 839
#define CREATEHINGECONSTRAINT_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEHINGECONSTRAINT_FRAMEA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEHINGECONSTRAINT_USEREFERENCEFRAMEA num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_createHingeConstraintEx 840
#define CREATEHINGECONSTRAINTEX_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEHINGECONSTRAINTEX_ACTORB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEHINGECONSTRAINTEX_FRAMEA num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEHINGECONSTRAINTEX_FRAMEB num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEHINGECONSTRAINTEX_USEREFERENCEFRAMEA num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_createSlideConstraint 841
#define CREATESLIDECONSTRAINT_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATESLIDECONSTRAINT_FRAMEINB_MATRIX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATESLIDECONSTRAINT_USELINEARREFERENCEFRAMEA num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_createSlideConstraintEx 842
#define CREATESLIDECONSTRAINTEX_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATESLIDECONSTRAINTEX_ACTORB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATESLIDECONSTRAINTEX_FRAMEINA_MATRIX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATESLIDECONSTRAINTEX_FRAMEINB_MATRIX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATESLIDECONSTRAINTEX_USELINEARREFERENCEFRAMEA num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_createConeConstraint 843
#define CREATECONECONSTRAINT_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATECONECONSTRAINT_RBAFRAME_MATRIX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_createConeConstraintEx 844
#define CREATECONECONSTRAINTEX_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATECONECONSTRAINTEX_ACTORB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATECONECONSTRAINTEX_RBAFRAME_MATRIX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATECONECONSTRAINTEX_RBBFRAME_MATRIX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_deleteConstraint 845
#define DELETECONSTRAINT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConstraintFrameOffsetA 846
#define GETCONSTRAINTFRAMEOFFSETA_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_RX num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_RY num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_RZ num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_getConstraintFrameOffsetB 847
#define GETCONSTRAINTFRAMEOFFSETB_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_RX num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_RY num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_RZ num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_useConstraintFrameOffset 848
#define USECONSTRAINTFRAMEOFFSET_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define USECONSTRAINTFRAMEOFFSET_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getHingeAngle 849
#define GETHINGEANGLE_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getHingeAngleEx 850
#define GETHINGEANGLEEX_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETHINGEANGLEEX_T_MATRIXA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETHINGEANGLEEX_T_MATRIXB num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getConstraintBreakingImpulseThreshold 851
#define GETCONSTRAINTBREAKINGIMPULSETHRESHOLD_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConstraintAFrame 852
#define GETCONSTRAINTAFRAME_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCONSTRAINTAFRAME_MA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getConstraintBFrame 853
#define GETCONSTRAINTBFRAME_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCONSTRAINTBFRAME_MA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setHingeAxis 854
#define SETHINGEAXIS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETHINGEAXIS_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETHINGEAXIS_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETHINGEAXIS_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setConstraintBreakingImpulseThreshold 855
#define SETCONSTRAINTBREAKINGIMPULSETHRESHOLD_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONSTRAINTBREAKINGIMPULSETHRESHOLD_THRESHOLD num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setConstraintFrames 856
#define SETCONSTRAINTFRAMES_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONSTRAINTFRAMES_FRAMEA_MATRIX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCONSTRAINTFRAMES_FRAMEB_MATRIX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setHingeLimit 857
#define SETHINGELIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETHINGELIMIT_LOW num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETHINGELIMIT_HIGH num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETHINGELIMIT_SOFTNESS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETHINGELIMIT_BIAS_FACTOR num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define SETHINGELIMIT_RELAXATION_FACTOR num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_setConeLimit 858
#define SETCONELIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONELIMIT_SWINGSPAN1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCONELIMIT_SWINGSPAN2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETCONELIMIT_TWISTSPAN num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETCONELIMIT_SOFTNESS num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define SETCONELIMIT_BIAS_FACTOR num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define SETCONELIMIT_RELAXATION_FACTOR num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_getHingeLimitBiasFactor 859
#define GETHINGELIMITBIASFACTOR_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getHingeLimitRelaxationFactor 860
#define GETHINGELIMITRELAXATIONFACTOR_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getHingeLimitSign 861
#define GETHINGELIMITSIGN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getHingeSolveLimit 862
#define GETHINGESOLVELIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_useHingeReferenceFrameA 863
#define USEHINGEREFERENCEFRAMEA_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define USEHINGEREFERENCEFRAMEA_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getConstraintAppliedImpulse 864
#define GETCONSTRAINTAPPLIEDIMPULSE_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConstraintFixedActor 865
#define GETCONSTRAINTFIXEDACTOR_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getPointPivotA 866
#define GETPOINTPIVOTA_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPOINTPIVOTA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPOINTPIVOTA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETPOINTPIVOTA_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getPointPivotB 867
#define GETPOINTPIVOTB_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPOINTPIVOTB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPOINTPIVOTB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETPOINTPIVOTB_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getConstraintActorA 868
#define GETCONSTRAINTACTORA_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConstraintActorB 869
#define GETCONSTRAINTACTORB_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setConstraintSolverIterations 870
#define SETCONSTRAINTSOLVERITERATIONS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONSTRAINTSOLVERITERATIONS_NUM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getConeBiasFactor 871
#define GETCONEBIASFACTOR_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeDamping 872
#define GETCONEDAMPING_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeFixThresh 873
#define GETCONEFIXTHRESH_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeLimit 874
#define GETCONELIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCONELIMIT_LIMIT_INDEX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getConstraintLimitSoftness 875
#define GETCONSTRAINTLIMITSOFTNESS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConstraintSolverIterations 876
#define GETCONSTRAINTSOLVERITERATIONS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeAnglePoint 877
#define GETCONEANGLEPOINT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCONEANGLEPOINT_ANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCONEANGLEPOINT_C_LEN num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETCONEANGLEPOINT_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETCONEANGLEPOINT_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETCONEANGLEPOINT_Z num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_getConstraintAngularOnly 878
#define GETCONSTRAINTANGULARONLY_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeSolveSwingLimit 879
#define GETCONESOLVESWINGLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeSolveTwistLimit 880
#define GETCONESOLVETWISTLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeSwingSpan1 881
#define GETCONESWINGSPAN1_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeSwingSpan2 882
#define GETCONESWINGSPAN2_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeTwistAngle 883
#define GETCONETWISTANGLE_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeTwistLimitSign 884
#define GETCONETWISTLIMITSIGN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeTwistSpan 885
#define GETCONETWISTSPAN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setConstraintAngularOnly 886
#define SETCONSTRAINTANGULARONLY_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONSTRAINTANGULARONLY_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setConeDamping 887
#define SETCONEDAMPING_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONEDAMPING_DAMPING num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setConeFixThresh 888
#define SETCONEFIXTHRESH_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONEFIXTHRESH_FIXTHRESH num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getSlideAnchorA 889
#define GETSLIDEANCHORA_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSLIDEANCHORA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSLIDEANCHORA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSLIDEANCHORA_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getSlideAnchorB 890
#define GETSLIDEANCHORB_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSLIDEANCHORB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSLIDEANCHORB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSLIDEANCHORB_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getSlideAngDepth 891
#define GETSLIDEANGDEPTH_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideAngularPos 892
#define GETSLIDEANGULARPOS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideDampingDirAng 893
#define GETSLIDEDAMPINGDIRANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideDampingDirLin 894
#define GETSLIDEDAMPINGDIRLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideDampingLimAng 895
#define GETSLIDEDAMPINGLIMANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideDampingLimLin 896
#define GETSLIDEDAMPINGLIMLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideDampingOrthoAng 897
#define GETSLIDEDAMPINGORTHOANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideDampingOrthoLin 898
#define GETSLIDEDAMPINGORTHOLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideLinearPos 899
#define GETSLIDELINEARPOS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideLinDepth 900
#define GETSLIDELINDEPTH_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideLowerAngLimit 901
#define GETSLIDELOWERANGLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideLowerLinLimit 902
#define GETSLIDELOWERLINLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideRestitutionDirAng 903
#define GETSLIDERESTITUTIONDIRANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideRestitutionDirLin 904
#define GETSLIDERESTITUTIONDIRLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideRestitutionLimAng 905
#define GETSLIDERESTITUTIONLIMANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideRestitutionLimLin 906
#define GETSLIDERESTITUTIONLIMLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideRestitutionOrthoAng 907
#define GETSLIDERESTITUTIONORTHOANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideRestitutionOrthoLin 908
#define GETSLIDERESTITUTIONORTHOLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSoftnessDirAng 909
#define GETSLIDESOFTNESSDIRANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSoftnessDirLin 910
#define GETSLIDESOFTNESSDIRLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSoftnessLimAng 911
#define GETSLIDESOFTNESSLIMANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSoftnessLimLin 912
#define GETSLIDESOFTNESSLIMLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSoftnessOrthoAng 913
#define GETSLIDESOFTNESSORTHOANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSoftnessOrthoLin 914
#define GETSLIDESOFTNESSORTHOLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSolveAngLimit 915
#define GETSLIDESOLVEANGLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSolveLinLimit 916
#define GETSLIDESOLVELINLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideUpperAngLimit 917
#define GETSLIDEUPPERANGLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideUpperLinLimit 918
#define GETSLIDEUPPERLINLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideUseFrameOffset 919
#define GETSLIDEUSEFRAMEOFFSET_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSlideDampingDirAng 920
#define SETSLIDEDAMPINGDIRANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEDAMPINGDIRANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideDampingDirLin 921
#define SETSLIDEDAMPINGDIRLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEDAMPINGDIRLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideDampingLimAng 922
#define SETSLIDEDAMPINGLIMANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEDAMPINGLIMANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideDampingLimLin 923
#define SETSLIDEDAMPINGLIMLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEDAMPINGLIMLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideDampingOrthoAng 924
#define SETSLIDEDAMPINGORTHOANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEDAMPINGORTHOANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideDampingOrthoLin 925
#define SETSLIDEDAMPINGORTHOLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEDAMPINGORTHOLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideLowerAngLimit 926
#define SETSLIDELOWERANGLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDELOWERANGLIMIT_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideLowerLinLimit 927
#define SETSLIDELOWERLINLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDELOWERLINLIMIT_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideRestitutionDirAng 928
#define SETSLIDERESTITUTIONDIRANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDERESTITUTIONDIRANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideRestitutionDirLin 929
#define SETSLIDERESTITUTIONDIRLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDERESTITUTIONDIRLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideRestitutionLimAng 930
#define SETSLIDERESTITUTIONLIMANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDERESTITUTIONLIMANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideRestitutionLimLin 931
#define SETSLIDERESTITUTIONLIMLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDERESTITUTIONLIMLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideRestitutionOrthoAng 932
#define SETSLIDERESTITUTIONORTHOANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDERESTITUTIONORTHOANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideRestitutionOrthoLin 933
#define SETSLIDERESTITUTIONORTHOLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDERESTITUTIONORTHOLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideSoftnessDirAng 934
#define SETSLIDESOFTNESSDIRANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDESOFTNESSDIRANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideSoftnessDirLin 935
#define SETSLIDESOFTNESSDIRLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDESOFTNESSDIRLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideSoftnessLimAng 936
#define SETSLIDESOFTNESSLIMANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDESOFTNESSLIMANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideSoftnessLimLin 937
#define SETSLIDESOFTNESSLIMLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDESOFTNESSLIMLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideSoftnessOrthoAng 938
#define SETSLIDESOFTNESSORTHOANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDESOFTNESSORTHOANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideSoftnessOrthoLin 939
#define SETSLIDESOFTNESSORTHOLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDESOFTNESSORTHOLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideUpperAngLimit 940
#define SETSLIDEUPPERANGLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEUPPERANGLIMIT_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideUpperLinLimit 941
#define SETSLIDEUPPERLINLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEUPPERLINLIMIT_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ConstraintExists 942
#define CONSTRAINTEXISTS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetCameraPosition 943
#define SETCAMERAPOSITION_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCAMERAPOSITION_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCAMERAPOSITION_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetCameraPosition 944
#define GETCAMERAPOSITION_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCAMERAPOSITION_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCAMERAPOSITION_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_TranslateCamera 945
#define TRANSLATECAMERA_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TRANSLATECAMERA_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define TRANSLATECAMERA_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetCameraRotation 946
#define SETCAMERAROTATION_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCAMERAROTATION_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCAMERAROTATION_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetCameraRotation 947
#define GETCAMERAROTATION_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCAMERAROTATION_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCAMERAROTATION_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_RotateCamera 948
#define ROTATECAMERA_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ROTATECAMERA_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ROTATECAMERA_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetCameraFOV 949
#define SETCAMERAFOV_FOV num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetCameraFOV 950
#define FN_SetCameraAspectRatio 951
#define SETCAMERAASPECTRATIO_ASPECT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetCameraAspectRatio 952
#define FN_SetCameraFarValue 953
#define SETCAMERAFARVALUE_ZF num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetCameraFarValue 954
#define FN_SetCameraNearValue 955
#define SETCAMERANEARVALUE_ZN num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetCameraNearValue 956
#define FN_SetProjectionMatrix 957
#define SETPROJECTIONMATRIX_MATA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPROJECTIONMATRIX_PROJECTION_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetProjectionMatrix 958
#define GETPROJECTIONMATRIX_MATA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetWorldToViewportPosition 959
#define GETWORLDTOVIEWPORTPOSITION_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWORLDTOVIEWPORTPOSITION_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETWORLDTOVIEWPORTPOSITION_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETWORLDTOVIEWPORTPOSITION_VX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETWORLDTOVIEWPORTPOSITION_VY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_AddSceneSkyBox 960
#define ADDSCENESKYBOX_IMG_TOP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ADDSCENESKYBOX_IMG_BOTTOM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ADDSCENESKYBOX_IMG_LEFT num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define ADDSCENESKYBOX_IMG_RIGHT num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define ADDSCENESKYBOX_IMG_FRONT num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define ADDSCENESKYBOX_IMG_BACK num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_AddSceneSkyDome 961
#define ADDSCENESKYDOME_IMG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_AddSceneSkyDomeEx 962
#define ADDSCENESKYDOMEEX_IMG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ADDSCENESKYDOMEEX_HORIRES num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ADDSCENESKYDOMEEX_VERTRES num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define ADDSCENESKYDOMEEX_TXPERCENTAGE num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define ADDSCENESKYDOMEEX_SPHEREPERCENTAGE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define ADDSCENESKYDOMEEX_RADIUS num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_RemoveSceneSky 963
#define FN_SetWorld3DMaxSubSteps 964
#define SETWORLD3DMAXSUBSTEPS_STEPS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetWorld3DTimeStep 965
#define SETWORLD3DTIMESTEP_TS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetWorld3DMaxSubSteps 966
#define FN_GetWorld3DTimeStep 967
#define FN_SetSceneFog 968
#define SETSCENEFOG_COLOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSCENEFOG_FOG_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSCENEFOG_START_VAL num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETSCENEFOG_END_VAL num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETSCENEFOG_DENSITY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define SETSCENEFOG_PIXELFOG num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define SETSCENEFOG_RANGEFOG num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_GetSceneFog 969
#define GETSCENEFOG_COLOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSCENEFOG_FOG_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSCENEFOG_START_VAL num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSCENEFOG_END_VAL num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSCENEFOG_DENSITY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETSCENEFOG_PIXELFOG num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETSCENEFOG_RANGEFOG num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_ClearScene 970
#define FN_SetSceneShadowColor 971
#define SETSCENESHADOWCOLOR_COLOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetSceneShadowColor 972
#define FN_SetSceneAmbientColor 973
#define SETSCENEAMBIENTCOLOR_COLOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetSceneAmbientColor 974
#define FN_Pipeline_Begin 975
#define FN_Pipeline_End 976
#define FN_Pipeline_Render 977
#define FN_SetPhysics3D 978
#define SETPHYSICS3D_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetPhysics3D 979
#define FN_startParticleEmitter 980
#define STARTPARTICLEEMITTER_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_stopParticleEmitter 981
#define STOPPARTICLEEMITTER_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleDirection 982
#define SETPARTICLEDIRECTION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEDIRECTION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPARTICLEDIRECTION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETPARTICLEDIRECTION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getParticleDirection 983
#define GETPARTICLEDIRECTION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPARTICLEDIRECTION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPARTICLEDIRECTION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETPARTICLEDIRECTION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_useParticleEveryMeshVertex 984
#define USEPARTICLEEVERYMESHVERTEX_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define USEPARTICLEEVERYMESHVERTEX_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_particleIsUsingEveryMeshVertex 985
#define PARTICLEISUSINGEVERYMESHVERTEX_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleNormalDirectionMod 986
#define SETPARTICLENORMALDIRECTIONMOD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLENORMALDIRECTIONMOD_ND_MOD num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleNormalDirectionMod 987
#define GETPARTICLENORMALDIRECTIONMOD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_useParticleNormalDirection 988
#define USEPARTICLENORMALDIRECTION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define USEPARTICLENORMALDIRECTION_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_particleIsUsingNormalDirection 989
#define PARTICLEISUSINGNORMALDIRECTION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMesh 990
#define SETPARTICLEMESH_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMESH_MESH num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setMinParticlesPerSecond 991
#define SETMINPARTICLESPERSECOND_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMINPARTICLESPERSECOND_MINPARTICLESPERSECOND num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMinParticlesPerSecond 992
#define GETMINPARTICLESPERSECOND_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaxParticlesPerSecond 993
#define SETMAXPARTICLESPERSECOND_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMAXPARTICLESPERSECOND_MAXPARTICLESPERSECOND num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaxParticlesPerSecond 994
#define GETMAXPARTICLESPERSECOND_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMinStartColor 995
#define SETPARTICLEMINSTARTCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMINSTARTCOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleMinStartColor 996
#define GETPARTICLEMINSTARTCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMaxStartColor 997
#define SETPARTICLEMAXSTARTCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMAXSTARTCOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleMaxStartColor 998
#define GETPARTICLEMAXSTARTCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMinLife 999
#define SETPARTICLEMINLIFE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMINLIFE_MINLIFE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleMinLife 1000
#define GETPARTICLEMINLIFE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMaxLife 1001
#define SETPARTICLEMAXLIFE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMAXLIFE_MAXLIFE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleMaxLife 1002
#define GETPARTICLEMAXLIFE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMaxAngle 1003
#define SETPARTICLEMAXANGLE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMAXANGLE_MAXANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleMaxAngle 1004
#define GETPARTICLEMAXANGLE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMinStartSize 1005
#define SETPARTICLEMINSTARTSIZE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMINSTARTSIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPARTICLEMINSTARTSIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getParticleMinStartSize 1006
#define GETPARTICLEMINSTARTSIZE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPARTICLEMINSTARTSIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPARTICLEMINSTARTSIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setParticleMaxStartSize 1007
#define SETPARTICLEMAXSTARTSIZE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMAXSTARTSIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPARTICLEMAXSTARTSIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getParticleMaxStartSize 1008
#define GETPARTICLEMAXSTARTSIZE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPARTICLEMAXSTARTSIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPARTICLEMAXSTARTSIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setParticleCenter 1009
#define SETPARTICLECENTER_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLECENTER_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPARTICLECENTER_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETPARTICLECENTER_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getParticleCenter 1010
#define GETPARTICLECENTER_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPARTICLECENTER_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPARTICLECENTER_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETPARTICLECENTER_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setParticleRadius 1011
#define SETPARTICLERADIUS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLERADIUS_RADIUS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleRadius 1012
#define GETPARTICLERADIUS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleRingThickness 1013
#define SETPARTICLERINGTHICKNESS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLERINGTHICKNESS_RINGTHICKNESS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleRingThickness 1014
#define GETPARTICLERINGTHICKNESS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleBox 1015
#define SETPARTICLEBOX_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEBOX_MIN_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPARTICLEBOX_MIN_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETPARTICLEBOX_MIN_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETPARTICLEBOX_MAX_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define SETPARTICLEBOX_MAX_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define SETPARTICLEBOX_MAX_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_getParticleBox 1016
#define GETPARTICLEBOX_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPARTICLEBOX_MIN_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPARTICLEBOX_MIN_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETPARTICLEBOX_MIN_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETPARTICLEBOX_MAX_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETPARTICLEBOX_MAX_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETPARTICLEBOX_MAX_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_setParticleNormal 1017
#define SETPARTICLENORMAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLENORMAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPARTICLENORMAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETPARTICLENORMAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getParticleNormal 1018
#define GETPARTICLENORMAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPARTICLENORMAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPARTICLENORMAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETPARTICLENORMAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setParticleLength 1019
#define SETPARTICLELENGTH_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLELENGTH_P_LEN num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleLength 1020
#define GETPARTICLELENGTH_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_useParticleOutlineOnly 1021
#define USEPARTICLEOUTLINEONLY_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define USEPARTICLEOUTLINEONLY_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_particleIsUsingOutlineOnly 1022
#define PARTICLEISUSINGOUTLINEONLY_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getParticleType 1023
#define GETPARTICLETYPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_lightIsCastingShadow 1024
#define LIGHTISCASTINGSHADOW_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getLightType 1025
#define GETLIGHTTYPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getLightRadius 1026
#define GETLIGHTRADIUS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setLightType 1027
#define SETLIGHTTYPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTTYPE_LIGHT_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setLightRadius 1028
#define SETLIGHTRADIUS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTRADIUS_RADIUS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setLightShadowCast 1029
#define SETLIGHTSHADOWCAST_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTSHADOWCAST_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetLightAmbientColor 1030
#define SETLIGHTAMBIENTCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTAMBIENTCOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetLightAmbientColor 1031
#define GETLIGHTAMBIENTCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetLightAttenuation 1032
#define SETLIGHTATTENUATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTATTENUATION_L_CONSTANT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETLIGHTATTENUATION_L_LINEAR num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETLIGHTATTENUATION_L_QUADRATIC num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetLightAttenuation 1033
#define GETLIGHTATTENUATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETLIGHTATTENUATION_CONSTANT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETLIGHTATTENUATION_LINEAR num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETLIGHTATTENUATION_QUADRATIC num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetLightDiffuseColor 1034
#define SETLIGHTDIFFUSECOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTDIFFUSECOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetLightDiffuseColor 1035
#define GETLIGHTDIFFUSECOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetLightFalloff 1036
#define SETLIGHTFALLOFF_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTFALLOFF_FALLOFF num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetLightFalloff 1037
#define GETLIGHTFALLOFF_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetLightInnerCone 1038
#define SETLIGHTINNERCONE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTINNERCONE_ANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetLightInnerCone 1039
#define GETLIGHTINNERCONE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetLightOuterCone 1040
#define SETLIGHTOUTERCONE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTOUTERCONE_ANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetLightOuterCone 1041
#define GETLIGHTOUTERCONE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetLightSpecularColor 1042
#define SETLIGHTSPECULARCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTSPECULARCOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetLightSpecularColor 1043
#define GETLIGHTSPECULARCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetTerrainPatchAABB 1044
#define GETTERRAINPATCHAABB_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTERRAINPATCHAABB_PATCHX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTERRAINPATCHAABB_PATCHZ num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETTERRAINPATCHAABB_MINX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETTERRAINPATCHAABB_MINY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETTERRAINPATCHAABB_MINZ num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETTERRAINPATCHAABB_MAXX num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define GETTERRAINPATCHAABB_MAXY num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define GETTERRAINPATCHAABB_MAXZ num_var[8].nref[0].value[ num_var[8].byref_offset ]
#define FN_GetTerrainPatchLOD 1045
#define GETTERRAINPATCHLOD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTERRAINPATCHLOD_PATCHX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTERRAINPATCHLOD_PATCHZ num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetTerrainHeight 1046
#define GETTERRAINHEIGHT_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTERRAINHEIGHT_PATCHX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTERRAINHEIGHT_PATCHZ num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetTerrainCenter 1047
#define GETTERRAINCENTER_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTERRAINCENTER_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTERRAINCENTER_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETTERRAINCENTER_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetTerrainLODDistance 1048
#define SETTERRAINLODDISTANCE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTERRAINLODDISTANCE_LOD num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTERRAINLODDISTANCE_DISTANCE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ScaleTerrainTexture 1049
#define SCALETERRAINTEXTURE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SCALETERRAINTEXTURE_SCALE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SCALETERRAINTEXTURE_SCALE2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetTerrainCameraMovementDelta 1050
#define SETTERRAINCAMERAMOVEMENTDELTA_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTERRAINCAMERAMOVEMENTDELTA_DELTA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetTerrainCameraRotationDelta 1051
#define SETTERRAINCAMERAROTATIONDELTA_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTERRAINCAMERAROTATIONDELTA_DELTA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetTerrainPatchLOD 1052
#define SETTERRAINPATCHLOD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTERRAINPATCHLOD_PATCHX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTERRAINPATCHLOD_PATCHZ num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETTERRAINPATCHLOD_LOD num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetProjectorTarget 1053
#define SETPROJECTORTARGET_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPROJECTORTARGET_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPROJECTORTARGET_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETPROJECTORTARGET_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetProjectorTarget 1054
#define GETPROJECTORTARGET_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPROJECTORTARGET_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPROJECTORTARGET_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETPROJECTORTARGET_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetProjectorFOV 1055
#define SETPROJECTORFOV_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPROJECTORFOV_FOV num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetProjectorFOV 1056
#define GETPROJECTORFOV_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetProjectorTexture 1057
#define SETPROJECTORTEXTURE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPROJECTORTEXTURE_IMG_ID num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetProjectorTexture 1058
#define GETPROJECTORTEXTURE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_AddProjectorEffectActor 1059
#define ADDPROJECTOREFFECTACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ADDPROJECTOREFFECTACTOR_TGT_ACTOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetProjectorEffectActorCount 1060
#define GETPROJECTOREFFECTACTORCOUNT_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetProjectorEffectActor 1061
#define GETPROJECTOREFFECTACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPROJECTOREFFECTACTOR_TGT_INDEX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_RemoveProjectorEffectActor 1062
#define REMOVEPROJECTOREFFECTACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define REMOVEPROJECTOREFFECTACTOR_TGT_INDEX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_AddCompositeChild 1063
#define ADDCOMPOSITECHILD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ADDCOMPOSITECHILD_CHILD_ACTOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ADDCOMPOSITECHILD_T_MATRIX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetCompositeChildCount 1064
#define GETCOMPOSITECHILDCOUNT_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetCompositeChild 1065
#define GETCOMPOSITECHILD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCOMPOSITECHILD_CHILD_INDEX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetCompositeChildIndex 1066
#define GETCOMPOSITECHILDINDEX_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCOMPOSITECHILDINDEX_CHILD_ACTOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_RemoveCompositeChild 1067
#define REMOVECOMPOSITECHILD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define REMOVECOMPOSITECHILD_CHILD_INDEX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetCompositeChildTransform 1068
#define GETCOMPOSITECHILDTRANSFORM_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCOMPOSITECHILDTRANSFORM_CHILD_INDEX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCOMPOSITECHILDTRANSFORM_T_MATRIX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetCompositeAABB 1069
#define GETCOMPOSITEAABB_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCOMPOSITEAABB_T_MATRIX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCOMPOSITEAABB_MIN_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETCOMPOSITEAABB_MIN_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETCOMPOSITEAABB_MIN_Z num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETCOMPOSITEAABB_MAX_X num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETCOMPOSITEAABB_MAX_Y num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define GETCOMPOSITEAABB_MAX_Z num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define FN_RecalculateCompositeAABB 1070
#define RECALCULATECOMPOSITEAABB_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GenerateCompositeAABBFromChildren 1071
#define GENERATECOMPOSITEAABBFROMCHILDREN_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CalculateCompositePrincipalTransform 1072
#define CALCULATECOMPOSITEPRINCIPALTRANSFORM_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CALCULATECOMPOSITEPRINCIPALTRANSFORM_MASSES num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CALCULATECOMPOSITEPRINCIPALTRANSFORM_PRINCIPAL_MATRIX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CALCULATECOMPOSITEPRINCIPALTRANSFORM_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CALCULATECOMPOSITEPRINCIPALTRANSFORM_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CALCULATECOMPOSITEPRINCIPALTRANSFORM_Z num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_UpdateCompositeChildTransform 1073
#define UPDATECOMPOSITECHILDTRANSFORM_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define UPDATECOMPOSITECHILDTRANSFORM_CHILD_INDEX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define UPDATECOMPOSITECHILDTRANSFORM_T_MATRIX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define UPDATECOMPOSITECHILDTRANSFORM_RECALC_FLAG num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetCompositeUpdateRevision 1074
#define GETCOMPOSITEUPDATEREVISION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_AddVehicleWheel 1075
#define ADDVEHICLEWHEEL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ADDVEHICLEWHEEL_WHEEL_ACTOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ADDVEHICLEWHEEL_IS_FRONT_WHEEL num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetVehicleAxis 1076
#define GETVEHICLEAXIS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETVEHICLEAXIS_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETVEHICLEAXIS_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETVEHICLEAXIS_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetVehicleForwardVector 1077
#define GETVEHICLEFORWARDVECTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETVEHICLEFORWARDVECTOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETVEHICLEFORWARDVECTOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETVEHICLEFORWARDVECTOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetVehicleCurrentSpeed 1078
#define GETVEHICLECURRENTSPEED_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetWheelCount 1079
#define GETWHEELCOUNT_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetVehicleChassisWorldTransform 1080
#define GETVEHICLECHASSISWORLDTRANSFORM_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETVEHICLECHASSISWORLDTRANSFORM_T_MATRIX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWheelSteeringValue 1081
#define GETWHEELSTEERINGVALUE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWHEELSTEERINGVALUE_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWheelWorldTransform 1082
#define GETWHEELWORLDTRANSFORM_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWHEELWORLDTRANSFORM_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETWHEELWORLDTRANSFORM_T_MATRIX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetWheelConnectionPoint 1083
#define GETWHEELCONNECTIONPOINT_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWHEELCONNECTIONPOINT_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETWHEELCONNECTIONPOINT_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETWHEELCONNECTIONPOINT_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETWHEELCONNECTIONPOINT_Z num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_GetWheelDirection 1084
#define GETWHEELDIRECTION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWHEELDIRECTION_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETWHEELDIRECTION_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETWHEELDIRECTION_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETWHEELDIRECTION_Z num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_GetWheelAxel 1085
#define GETWHEELAXEL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWHEELAXEL_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETWHEELAXEL_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETWHEELAXEL_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETWHEELAXEL_Z num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_GetWheelSuspensionLength 1086
#define GETWHEELSUSPENSIONLENGTH_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWHEELSUSPENSIONLENGTH_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWheelMaxSuspensionTravel 1087
#define GETWHEELMAXSUSPENSIONTRAVEL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWHEELMAXSUSPENSIONTRAVEL_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWheelRadius 1088
#define GETWHEELRADIUS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWHEELRADIUS_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWheelSuspensionStiffness 1089
#define GETWHEELSUSPENSIONSTIFFNESS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWHEELSUSPENSIONSTIFFNESS_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWheelDampingCompression 1090
#define GETWHEELDAMPINGCOMPRESSION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWHEELDAMPINGCOMPRESSION_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWheelDampingRelaxation 1091
#define GETWHEELDAMPINGRELAXATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWHEELDAMPINGRELAXATION_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWheelFrictionSlip 1092
#define GETWHEELFRICTIONSLIP_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWHEELFRICTIONSLIP_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWheelRotation 1093
#define GETWHEELROTATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWHEELROTATION_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWheelRotationDelta 1094
#define GETWHEELROTATIONDELTA_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWHEELROTATIONDELTA_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWheelRollInfluence 1095
#define GETWHEELROLLINFLUENCE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWHEELROLLINFLUENCE_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWheelEngineForce 1096
#define GETWHEELENGINEFORCE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWHEELENGINEFORCE_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWheelBrake 1097
#define GETWHEELBRAKE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWHEELBRAKE_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_WheelIsFront 1098
#define WHEELISFRONT_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WHEELISFRONT_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWheelInverseContactSuspension 1099
#define GETWHEELINVERSECONTACTSUSPENSION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWHEELINVERSECONTACTSUSPENSION_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWheelSuspensionVelocity 1100
#define GETWHEELSUSPENSIONVELOCITY_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWHEELSUSPENSIONVELOCITY_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ResetVehicleSuspension 1101
#define RESETVEHICLESUSPENSION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetWheelSteeringValue 1102
#define SETWHEELSTEERINGVALUE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWHEELSTEERINGVALUE_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETWHEELSTEERINGVALUE_STEERING num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ApplyWheelEngineForce 1103
#define APPLYWHEELENGINEFORCE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYWHEELENGINEFORCE_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYWHEELENGINEFORCE_FORCE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetWheelBrake 1104
#define SETWHEELBRAKE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWHEELBRAKE_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETWHEELBRAKE_BRAKE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetVehiclePitchControl 1105
#define SETVEHICLEPITCHCONTROL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETVEHICLEPITCHCONTROL_PITCH num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetWheelConnectionPoint 1106
#define SETWHEELCONNECTIONPOINT_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWHEELCONNECTIONPOINT_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETWHEELCONNECTIONPOINT_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETWHEELCONNECTIONPOINT_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETWHEELCONNECTIONPOINT_Z num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_SetWheelDirection 1107
#define SETWHEELDIRECTION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWHEELDIRECTION_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETWHEELDIRECTION_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETWHEELDIRECTION_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETWHEELDIRECTION_Z num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_SetWheelAxel 1108
#define SETWHEELAXEL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWHEELAXEL_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETWHEELAXEL_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETWHEELAXEL_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETWHEELAXEL_Z num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_SetWheelSuspensionLength 1109
#define SETWHEELSUSPENSIONLENGTH_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWHEELSUSPENSIONLENGTH_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETWHEELSUSPENSIONLENGTH_S_LENGTH num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetWheelMaxSuspensionTravel 1110
#define SETWHEELMAXSUSPENSIONTRAVEL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWHEELMAXSUSPENSIONTRAVEL_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETWHEELMAXSUSPENSIONTRAVEL_MAX_TRAVEL num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetWheelRadius 1111
#define SETWHEELRADIUS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWHEELRADIUS_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETWHEELRADIUS_RADIUS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetWheelSuspensionStiffness 1112
#define SETWHEELSUSPENSIONSTIFFNESS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWHEELSUSPENSIONSTIFFNESS_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETWHEELSUSPENSIONSTIFFNESS_STIFFNESS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetWheelDampingCompression 1113
#define SETWHEELDAMPINGCOMPRESSION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWHEELDAMPINGCOMPRESSION_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETWHEELDAMPINGCOMPRESSION_DCOMP_VALUE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetWheelDampingRelaxation 1114
#define SETWHEELDAMPINGRELAXATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWHEELDAMPINGRELAXATION_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETWHEELDAMPINGRELAXATION_DREL_VALUE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetWheelFrictionSlip 1115
#define SETWHEELFRICTIONSLIP_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWHEELFRICTIONSLIP_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETWHEELFRICTIONSLIP_FSLIP_VALUE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetWheelRotation 1116
#define SETWHEELROTATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWHEELROTATION_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETWHEELROTATION_ROT num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetWheelRotationDelta 1117
#define SETWHEELROTATIONDELTA_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWHEELROTATIONDELTA_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETWHEELROTATIONDELTA_ROT_DELTA num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetWheelRollInfluence 1118
#define SETWHEELROLLINFLUENCE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWHEELROLLINFLUENCE_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETWHEELROLLINFLUENCE_ROLL_INFLUENCE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetWheelInverseContactSuspension 1119
#define SETWHEELINVERSECONTACTSUSPENSION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWHEELINVERSECONTACTSUSPENSION_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETWHEELINVERSECONTACTSUSPENSION_C_VALUE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetWheelSuspensionVelocity 1120
#define SETWHEELSUSPENSIONVELOCITY_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWHEELSUSPENSIONVELOCITY_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETWHEELSUSPENSIONVELOCITY_VELOCITY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetWheelActorOffsetTransform 1121
#define SETWHEELACTOROFFSETTRANSFORM_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWHEELACTOROFFSETTRANSFORM_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETWHEELACTOROFFSETTRANSFORM_T_MATRIX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetWheelActorOffsetTransform 1122
#define GETWHEELACTOROFFSETTRANSFORM_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWHEELACTOROFFSETTRANSFORM_WHEEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETWHEELACTOROFFSETTRANSFORM_T_MATRIX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_createMaterial 1123
#define FN_deleteMaterial 1124
#define DELETEMATERIAL_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setActorMaterial 1125
#define SETACTORMATERIAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORMATERIAL_MATERIAL_NUM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORMATERIAL_MATERIAL_ID num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getActorMaterial 1126
#define GETACTORMATERIAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORMATERIAL_MATERIAL_NUM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_copyActorMaterial 1127
#define COPYACTORMATERIAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COPYACTORMATERIAL_MATERIAL_NUM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_copyMaterial 1128
#define COPYMATERIAL_SMATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialTextureCanvas 1129
#define SETMATERIALTEXTURECANVAS_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALTEXTURECANVAS_LEVEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATERIALTEXTURECANVAS_CANVAS_ID num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setMaterialAmbientColor 1130
#define SETMATERIALAMBIENTCOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALAMBIENTCOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialAmbientColor 1131
#define GETMATERIALAMBIENTCOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialAntiAliasing 1132
#define SETMATERIALANTIALIASING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALANTIALIASING_AA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialAntiAliasing 1133
#define GETMATERIALANTIALIASING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialBackfaceCulling 1134
#define SETMATERIALBACKFACECULLING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALBACKFACECULLING_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialBackfaceCulling 1135
#define GETMATERIALBACKFACECULLING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialBlendFactor 1136
#define SETMATERIALBLENDFACTOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALBLENDFACTOR_BF num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialBlendFactor 1137
#define GETMATERIALBLENDFACTOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialBlendMode 1138
#define SETMATERIALBLENDMODE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALBLENDMODE_BLEND_MODE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialBlendMode 1139
#define GETMATERIALBLENDMODE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialColorMask 1140
#define SETMATERIALCOLORMASK_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALCOLORMASK_COLOR_MASK num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialColorMask 1141
#define GETMATERIALCOLORMASK_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialColorMode 1142
#define SETMATERIALCOLORMODE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALCOLORMODE_COLOR_MODE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialColorMode 1143
#define GETMATERIALCOLORMODE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialDiffuseColor 1144
#define SETMATERIALDIFFUSECOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALDIFFUSECOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialDiffuseColor 1145
#define GETMATERIALDIFFUSECOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialEmissiveColor 1146
#define SETMATERIALEMISSIVECOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALEMISSIVECOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialEmissiveColor 1147
#define GETMATERIALEMISSIVECOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialFog 1148
#define SETMATERIALFOG_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALFOG_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialFog 1149
#define GETMATERIALFOG_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialFrontfaceCulling 1150
#define SETMATERIALFRONTFACECULLING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALFRONTFACECULLING_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialFrontfaceCulling 1151
#define GETMATERIALFRONTFACECULLING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialGouraudShading 1152
#define SETMATERIALGOURAUDSHADING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALGOURAUDSHADING_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_materialIsGouraudShaded 1153
#define MATERIALISGOURAUDSHADED_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_materialIsAplhaBlend 1154
#define MATERIALISAPLHABLEND_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_materialIsTransparent 1155
#define MATERIALISTRANSPARENT_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialLighting 1156
#define SETMATERIALLIGHTING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALLIGHTING_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_materialIsLit 1157
#define MATERIALISLIT_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialType 1158
#define SETMATERIALTYPE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALTYPE_MAT_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialType 1159
#define GETMATERIALTYPE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialNormalize 1160
#define SETMATERIALNORMALIZE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALNORMALIZE_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_materialIsNormalized 1161
#define MATERIALISNORMALIZED_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialPointCloud 1162
#define SETMATERIALPOINTCLOUD_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALPOINTCLOUD_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_materialIsPointCloud 1163
#define MATERIALISPOINTCLOUD_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialFlag 1164
#define SETMATERIALFLAG_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALFLAG_MATERIAL_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATERIALFLAG_F_VALUE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getMaterialFlag 1165
#define GETMATERIALFLAG_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMATERIALFLAG_MATERIAL_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setMaterialTexture 1166
#define SETMATERIALTEXTURE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALTEXTURE_LEVEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATERIALTEXTURE_IMG_ID num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setMaterialShininess 1167
#define SETMATERIALSHININESS_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALSHININESS_SHININESS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialShininess 1168
#define GETMATERIALSHININESS_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialSpecularColor 1169
#define SETMATERIALSPECULARCOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALSPECULARCOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialSpecularColor 1170
#define GETMATERIALSPECULARCOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialThickness 1171
#define SETMATERIALTHICKNESS_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALTHICKNESS_THICKNESS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialThickness 1172
#define GETMATERIALTHICKNESS_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialWireframe 1173
#define SETMATERIALWIREFRAME_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALWIREFRAME_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_materialIsWireframe 1174
#define MATERIALISWIREFRAME_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setActorTexture 1175
#define SETACTORTEXTURE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORTEXTURE_LAYER num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORTEXTURE_IMAGE_ID num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getActorMaterialCount 1176
#define GETACTORMATERIALCOUNT_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setActorMaterialFlag 1177
#define SETACTORMATERIALFLAG_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORMATERIALFLAG_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORMATERIALFLAG_FLAG_VALUE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getActorMaterialFlag 1178
#define GETACTORMATERIALFLAG_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORMATERIALFLAG_MATERIAL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORMATERIALFLAG_FLAG num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setActorMaterialType 1179
#define SETACTORMATERIALTYPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORMATERIALTYPE_MATERIAL_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getActorMaterialType 1180
#define GETACTORMATERIALTYPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORMATERIALTYPE_MATERIAL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_MaterialExists 1181
#define MATERIALEXISTS_MATERIAL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumMaterialConstants 1182
#define NUMMATERIALCONSTANTS_MATERIAL_TYPE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetMaterialConstantName$ 1183
#define GETMATERIALCONSTANTNAME$_MATERIAL_TYPE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMATERIALCONSTANTNAME$_INDEX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetMaterialConstant 1184
#define SETMATERIALCONSTANT_MATERIAL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALCONSTANT_M_CONSTANT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define SETMATERIALCONSTANT_N1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATERIALCONSTANT_N2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETMATERIALCONSTANT_N3 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETMATERIALCONSTANT_N4 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_GetMaterialConstant 1185
#define GETMATERIALCONSTANT_MATERIAL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMATERIALCONSTANT_M_CONSTANT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define GETMATERIALCONSTANT_N1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMATERIALCONSTANT_N2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETMATERIALCONSTANT_N3 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETMATERIALCONSTANT_N4 num_var[4].nref[0].value[ num_var[4].byref_offset ]


#endif // RC_DEFINES_H_INCLUDED
