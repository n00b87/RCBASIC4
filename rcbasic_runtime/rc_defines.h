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
#define FN_OpenFile 93
#define OPENFILE_FILENAME$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define OPENFILE_MODE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CloseFile 94
#define CLOSEFILE_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ReadByte 95
#define READBYTE_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_WriteByte 96
#define WRITEBYTE_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WRITEBYTE_BYTE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ReadLine$ 97
#define READLINE$_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Write 98
#define WRITE_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WRITE_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_WriteLine 99
#define WRITELINE_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WRITELINE_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_CopyFile 100
#define COPYFILE_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define COPYFILE_DST$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_RemoveFile 101
#define REMOVEFILE_FILENAME$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_FileExists 102
#define FILEEXISTS_FILENAME$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_MoveFile 103
#define MOVEFILE_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define MOVEFILE_DST$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_RenameFile 104
#define RENAMEFILE_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define RENAMEFILE_DST$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_FileLength 105
#define FILELENGTH_FILENAME$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Tell 106
#define TELL_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Seek 107
#define SEEK_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SEEK_POS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_EOF 108
#define EOF_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_WriteByteBuffer 109
#define WRITEBYTEBUFFER_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WRITEBYTEBUFFER_BUF num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define WRITEBYTEBUFFER_BUF_SIZE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ReadByteBuffer 110
#define READBYTEBUFFER_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define READBYTEBUFFER_BUF num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define READBYTEBUFFER_BUF_SIZE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ChangeDir 111
#define CHANGEDIR_P$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_DirExists 112
#define DIREXISTS_P$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_DirFirst$ 113
#define FN_Dir$ 114
#define FN_DirNext$ 115
#define FN_MakeDir 116
#define MAKEDIR_P$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_RemoveDir 117
#define REMOVEDIR_P$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Date$ 118
#define FN_Easter$ 119
#define EASTER$_YEAR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Ticks 120
#define FN_Time$ 121
#define FN_Timer 122
#define FN_Wait 123
#define WAIT_M_SEC num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_OpenWindow 124
#define OPENWINDOW_TITLE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define OPENWINDOW_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define OPENWINDOW_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define OPENWINDOW_FULLSCREEN num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define OPENWINDOW_VSYNC num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_OpenWindowEx 125
#define OPENWINDOWEX_TITLE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define OPENWINDOWEX_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define OPENWINDOWEX_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define OPENWINDOWEX_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define OPENWINDOWEX_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define OPENWINDOWEX_MODE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define OPENWINDOWEX_AA num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define OPENWINDOWEX_STENCIL_BUFFER num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define OPENWINDOWEX_VSYNC num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define FN_CloseWindow 126
#define FN_RaiseWindow 127
#define FN_Update 128
#define FN_Cls 129
#define FN_SetClearColor 130
#define SETCLEARCOLOR_C num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ShowWindow 131
#define FN_HideWindow 132
#define FN_SetWindowTitle 133
#define SETWINDOWTITLE_TITLE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_WindowTitle$ 134
#define FN_SetWindowPosition 135
#define SETWINDOWPOSITION_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWINDOWPOSITION_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWindowPosition 136
#define GETWINDOWPOSITION_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWINDOWPOSITION_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetWindowSize 137
#define SETWINDOWSIZE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWINDOWSIZE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWindowSize 138
#define GETWINDOWSIZE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWINDOWSIZE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetWindowMinSize 139
#define SETWINDOWMINSIZE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWINDOWMINSIZE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWindowMinSize 140
#define GETWINDOWMINSIZE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWINDOWMINSIZE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetWindowMaxSize 141
#define SETWINDOWMAXSIZE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWINDOWMAXSIZE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWindowMaxSize 142
#define GETWINDOWMAXSIZE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWINDOWMAXSIZE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_WindowIsFullscreen 143
#define FN_WindowIsVisible 144
#define FN_WindowIsBordered 145
#define FN_WindowIsResizable 146
#define FN_WindowIsMinimized 147
#define FN_WindowIsMaximized 148
#define FN_WindowHasInputFocus 149
#define FN_WindowHasMouseFocus 150
#define FN_SetWindowFullscreen 151
#define SETWINDOWFULLSCREEN_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_MaximizeWindow 152
#define FN_MinimizeWindow 153
#define FN_SetWindowBordered 154
#define SETWINDOWBORDERED_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_WindowClip 155
#define WINDOWCLIP_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WINDOWCLIP_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define WINDOWCLIP_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define WINDOWCLIP_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_WindowExists 156
#define FN_WindowEvent_Close 157
#define FN_WindowEvent_Maximize 158
#define FN_WindowEvent_Minimize 159
#define FN_FPS 160
#define FN_SetWindowIcon 161
#define SETWINDOWICON_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_WindowEvent_Resize 162
#define FN_SetWindowAutoClose 163
#define SETWINDOWAUTOCLOSE_EXIT_ON_CLOSE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetWindowResizable 164
#define SETWINDOWRESIZABLE_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_WindowMode 165
#define WINDOWMODE_VISIBLE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WINDOWMODE_FULLSCREEN num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define WINDOWMODE_RESIZABLE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define WINDOWMODE_BORDERLESS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define WINDOWMODE_HIGHDPI num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getWindowMode 166
#define FN_RestoreWindow 167
#define FN_GrabInput 168
#define GRABINPUT_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetWindowAlwaysOnTop 169
#define SETWINDOWALWAYSONTOP_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetMouseRelative 170
#define SETMOUSERELATIVE_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetWindowVSync 171
#define SETWINDOWVSYNC_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_FlashWindow 172
#define FLASHWINDOW_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_WindowIsGrabbed 173
#define FN_PreUpdate 174
#define FN_SetFPS 175
#define SETFPS_FPS_VAL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_OpenCanvas 176
#define OPENCANVAS_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define OPENCANVAS_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define OPENCANVAS_VIEWPORT_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define OPENCANVAS_VIEWPORT_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define OPENCANVAS_VIEWPORT_W num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define OPENCANVAS_VIEWPORT_H num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define OPENCANVAS_MODE num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_CloseCanvas 177
#define CLOSECANVAS_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_OpenCanvas3D 178
#define OPENCANVAS3D_VIEWPORT_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define OPENCANVAS3D_VIEWPORT_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define OPENCANVAS3D_VIEWPORT_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define OPENCANVAS3D_VIEWPORT_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define OPENCANVAS3D_MODE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_SetCanvasVisible 179
#define SETCANVASVISIBLE_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCANVASVISIBLE_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_CanvasIsVisible 180
#define CANVASISVISIBLE_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetCanvasViewport 181
#define SETCANVASVIEWPORT_CNUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCANVASVIEWPORT_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCANVASVIEWPORT_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETCANVASVIEWPORT_W num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETCANVASVIEWPORT_H num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_GetCanvasViewport 182
#define GETCANVASVIEWPORT_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCANVASVIEWPORT_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCANVASVIEWPORT_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETCANVASVIEWPORT_W num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETCANVASVIEWPORT_H num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_Canvas 183
#define CANVAS_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetCanvasOffset 184
#define SETCANVASOFFSET_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCANVASOFFSET_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCANVASOFFSET_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetCanvasOffset 185
#define GETCANVASOFFSET_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCANVASOFFSET_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCANVASOFFSET_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetCanvasSize 186
#define GETCANVASSIZE_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCANVASSIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCANVASSIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ClearCanvas 187
#define FN_SetCanvasAlpha 188
#define SETCANVASALPHA_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCANVASALPHA_A num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetCanvasAlpha 189
#define GETCANVASALPHA_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetCanvasColorMod 190
#define SETCANVASCOLORMOD_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCANVASCOLORMOD_C num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetCanvasColorMod 191
#define GETCANVASCOLORMOD_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CloneCanvas 192
#define CLONECANVAS_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CLONECANVAS_MODE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetCanvasZ 193
#define SETCANVASZ_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCANVASZ_Z num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_CanvasZ 194
#define CANVASZ_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CanvasClip 195
#define CANVASCLIP_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CANVASCLIP_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CANVASCLIP_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CANVASCLIP_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_ActiveCanvas 196
#define FN_SetCanvasPhysics2D 197
#define SETCANVASPHYSICS2D_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCANVASPHYSICS2D_STATE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_OpenCanvasSpriteLayer 198
#define OPENCANVASSPRITELAYER_VIEWPORT_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define OPENCANVASSPRITELAYER_VIEWPORT_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define OPENCANVASSPRITELAYER_VIEWPORT_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define OPENCANVASSPRITELAYER_VIEWPORT_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_Circle 199
#define CIRCLE_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CIRCLE_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CIRCLE_RADIUS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_CircleFill 200
#define CIRCLEFILL_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CIRCLEFILL_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CIRCLEFILL_RADIUS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_Ellipse 201
#define ELLIPSE_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ELLIPSE_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ELLIPSE_RX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define ELLIPSE_RY num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_EllipseFill 202
#define ELLIPSEFILL_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ELLIPSEFILL_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ELLIPSEFILL_RX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define ELLIPSEFILL_RY num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_FloodFill 203
#define FLOODFILL_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FLOODFILL_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetPixel 204
#define GETPIXEL_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPIXEL_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetColor 205
#define SETCOLOR_C num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Line 206
#define LINE_X1 num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define LINE_Y1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define LINE_X2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define LINE_Y2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_Poly 207
#define POLY_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define POLY_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define POLY_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_Rect 208
#define RECT_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define RECT_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define RECT_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define RECT_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_RectFill 209
#define RECTFILL_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define RECTFILL_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define RECTFILL_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define RECTFILL_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_RGB 210
#define RGB_R num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define RGB_G num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define RGB_B num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_RGBA 211
#define RGBA_R num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define RGBA_G num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define RGBA_B num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define RGBA_A num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_Pset 212
#define PSET_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define PSET_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_Triangle 213
#define TRIANGLE_X1 num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TRIANGLE_Y1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define TRIANGLE_X2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define TRIANGLE_Y2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define TRIANGLE_X3 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define TRIANGLE_Y3 num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_Line3D 214
#define LINE3D_X1 num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define LINE3D_Y1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define LINE3D_Z1 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define LINE3D_X2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define LINE3D_Y2 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define LINE3D_Z2 num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_Box3D 215
#define BOX3D_MIN_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define BOX3D_MIN_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define BOX3D_MIN_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define BOX3D_MAX_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define BOX3D_MAX_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define BOX3D_MAX_Z num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_Triangle3D 216
#define TRIANGLE3D_X1 num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TRIANGLE3D_Y1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define TRIANGLE3D_Z1 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define TRIANGLE3D_X2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define TRIANGLE3D_Y2 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define TRIANGLE3D_Z2 num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define TRIANGLE3D_X3 num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define TRIANGLE3D_Y3 num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define TRIANGLE3D_Z3 num_var[8].nref[0].value[ num_var[8].byref_offset ]
#define FN_LoadImage 217
#define LOADIMAGE_IMG$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_LoadImageEx 218
#define LOADIMAGEEX_IMG$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define LOADIMAGEEX_COLKEY num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_createImage 219
#define CREATEIMAGE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEIMAGE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEIMAGE_BUFFER num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_createImageEx 220
#define CREATEIMAGEEX_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEIMAGEEX_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEIMAGEEX_BUFFER num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEIMAGEEX_COLOR num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_BufferFromImage 221
#define BUFFERFROMIMAGE_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define BUFFERFROMIMAGE_BUFFER num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ImageExists 222
#define IMAGEEXISTS_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ColorKey 223
#define COLORKEY_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COLORKEY_C num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setBilinearFilter 224
#define SETBILINEARFILTER_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getBilinearFilter 225
#define FN_CopyImage 226
#define COPYIMAGE_IMG_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteImage 227
#define DELETEIMAGE_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetImageAlpha 228
#define SETIMAGEALPHA_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETIMAGEALPHA_A num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetImageAlpha 229
#define GETIMAGEALPHA_IMG_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetImageSize 230
#define GETIMAGESIZE_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETIMAGESIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETIMAGESIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetBlendMode 231
#define SETBLENDMODE_BLEND_MODE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetBlendMode 232
#define FN_SetImageColorMod 233
#define SETIMAGECOLORMOD_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETIMAGECOLORMOD_C num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetImageColorMod 234
#define GETIMAGECOLORMOD_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DrawImage 235
#define DRAWIMAGE_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_DrawImage_Blit 236
#define DRAWIMAGE_BLIT_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_BLIT_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_BLIT_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_BLIT_SRC_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWIMAGE_BLIT_SRC_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define DRAWIMAGE_BLIT_SRC_W num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define DRAWIMAGE_BLIT_SRC_H num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_DrawImage_BlitEx 237
#define DRAWIMAGE_BLITEX_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_BLITEX_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_BLITEX_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_BLITEX_W num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWIMAGE_BLITEX_H num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define DRAWIMAGE_BLITEX_SRC_X num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define DRAWIMAGE_BLITEX_SRC_Y num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define DRAWIMAGE_BLITEX_SRC_W num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define DRAWIMAGE_BLITEX_SRC_H num_var[8].nref[0].value[ num_var[8].byref_offset ]
#define FN_DrawImage_Rotate 238
#define DRAWIMAGE_ROTATE_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_ROTATE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_ROTATE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_ROTATE_ANGLE num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_DrawImage_RotateEx 239
#define DRAWIMAGE_ROTATEEX_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_ROTATEEX_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_ROTATEEX_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_ROTATEEX_SRC_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWIMAGE_ROTATEEX_SRC_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define DRAWIMAGE_ROTATEEX_SRC_W num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define DRAWIMAGE_ROTATEEX_SRC_H num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define DRAWIMAGE_ROTATEEX_ANGLE num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define FN_DrawImage_Zoom 240
#define DRAWIMAGE_ZOOM_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_ZOOM_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_ZOOM_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_ZOOM_ZX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWIMAGE_ZOOM_ZY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_DrawImage_ZoomEx 241
#define DRAWIMAGE_ZOOMEX_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_ZOOMEX_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_ZOOMEX_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_ZOOMEX_SRC_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWIMAGE_ZOOMEX_SRC_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define DRAWIMAGE_ZOOMEX_SRC_W num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define DRAWIMAGE_ZOOMEX_SRC_H num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define DRAWIMAGE_ZOOMEX_ZX num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define DRAWIMAGE_ZOOMEX_ZY num_var[8].nref[0].value[ num_var[8].byref_offset ]
#define FN_DrawImage_Rotozoom 242
#define DRAWIMAGE_ROTOZOOM_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_ROTOZOOM_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_ROTOZOOM_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_ROTOZOOM_ANGLE num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWIMAGE_ROTOZOOM_ZX num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define DRAWIMAGE_ROTOZOOM_ZY num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_DrawImage_RotozoomEx 243
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
#define FN_DrawImage_Flip 244
#define DRAWIMAGE_FLIP_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_FLIP_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_FLIP_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_FLIP_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWIMAGE_FLIP_V num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_DrawImage_FlipEx 245
#define DRAWIMAGE_FLIPEX_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_FLIPEX_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_FLIPEX_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_FLIPEX_SRC_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWIMAGE_FLIPEX_SRC_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define DRAWIMAGE_FLIPEX_SRC_W num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define DRAWIMAGE_FLIPEX_SRC_H num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define DRAWIMAGE_FLIPEX_H num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define DRAWIMAGE_FLIPEX_V num_var[8].nref[0].value[ num_var[8].byref_offset ]
#define FN_InKey 246
#define FN_Key 247
#define KEY_KEY_CODE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_WaitKey 248
#define FN_HideMouse 249
#define FN_ShowMouse 250
#define FN_MouseIsVisible 251
#define FN_GetMouse 252
#define GETMOUSE_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMOUSE_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMOUSE_MB1 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETMOUSE_MB2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETMOUSE_MB3 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_MouseX 253
#define FN_MouseY 254
#define FN_MouseButton 255
#define MOUSEBUTTON_MB num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetMouseWheel 256
#define GETMOUSEWHEEL_X_AXIS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMOUSEWHEEL_Y_AXIS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_MouseWheelX 257
#define FN_MouseWheelY 258
#define FN_GetGlobalMouse 259
#define GETGLOBALMOUSE_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETGLOBALMOUSE_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETGLOBALMOUSE_MB1 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETGLOBALMOUSE_MB2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETGLOBALMOUSE_MB3 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_GlobalMouseX 260
#define FN_GlobalMouseY 261
#define FN_WarpMouse 262
#define WARPMOUSE_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WARPMOUSE_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_WarpMouseGlobal 263
#define WARPMOUSEGLOBAL_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WARPMOUSEGLOBAL_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetMouseZone 264
#define SETMOUSEZONE_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMOUSEZONE_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMOUSEZONE_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETMOUSEZONE_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_ClearMouseZone 265
#define FN_CreateSound 266
#define CREATESOUND_BUFFER num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATESOUND_BUFFER_SIZE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATESOUND_VOL num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_LoadSound 267
#define LOADSOUND_SND_FILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_LoadMusic 268
#define LOADMUSIC_MUSIC_FILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_PlaySound 269
#define PLAYSOUND_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define PLAYSOUND_CHANNEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define PLAYSOUND_LOOPS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_PlaySoundTimed 270
#define PLAYSOUNDTIMED_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define PLAYSOUNDTIMED_CHANNEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define PLAYSOUNDTIMED_LOOPS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define PLAYSOUNDTIMED_MS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_PlayMusic 271
#define PLAYMUSIC_MLOOPS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_PauseSound 272
#define PAUSESOUND_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ResumeSound 273
#define RESUMESOUND_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_PauseMusic 274
#define FN_ResumeMusic 275
#define FN_DeleteSound 276
#define DELETESOUND_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteMusic 277
#define FN_FadeMusicIn 278
#define FADEMUSICIN_FADE_TIME num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FADEMUSICIN_LOOPS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_FadeMusicOut 279
#define FADEMUSICOUT_FADE_TIME num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_MusicExists 280
#define FN_SetMusicVolume 281
#define SETMUSICVOLUME_VOL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetMusicVolume 282
#define FN_SetMusicPosition 283
#define SETMUSICPOSITION_POS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetMusicPosition 284
#define FN_RewindMusic 285
#define FN_SetSoundChannels 286
#define SETSOUNDCHANNELS_MAX_CHANNELS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumSoundChannels 287
#define FN_SoundIsEnabled 288
#define FN_SoundExists 289
#define SOUNDEXISTS_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetChannelVolume 290
#define SETCHANNELVOLUME_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCHANNELVOLUME_VOL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetChannelVolume 291
#define GETCHANNELVOLUME_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSoundVolume 292
#define SETSOUNDVOLUME_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSOUNDVOLUME_VOL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSoundVolume 293
#define GETSOUNDVOLUME_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_StopMusic 294
#define FN_StopSound 295
#define STOPSOUND_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetChannelPanning 296
#define SETCHANNELPANNING_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCHANNELPANNING_LEFT_VALUE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCHANNELPANNING_RIGHT_VALUE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetChannelDistance 297
#define SETCHANNELDISTANCE_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCHANNELDISTANCE_DIST_VALUE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ChannelIsPlaying 298
#define CHANNELISPLAYING_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ChannelIsPaused 299
#define CHANNELISPAUSED_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_QueryAudioSpec 300
#define QUERYAUDIOSPEC_FREQ num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define QUERYAUDIOSPEC_FORMAT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define QUERYAUDIOSPEC_CHANNELS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_MusicIsPlaying 301
#define FN_SetChannelSpacePosition 302
#define SETCHANNELSPACEPOSITION_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCHANNELSPACEPOSITION_ANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCHANNELSPACEPOSITION_DISTANCE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_NumJoysticks 303
#define FN_NumJoyAxes 304
#define NUMJOYAXES_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumJoyButtons 305
#define NUMJOYBUTTONS_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumJoyHats 306
#define NUMJOYHATS_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumJoyTrackBalls 307
#define NUMJOYTRACKBALLS_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_JoyAxis 308
#define JOYAXIS_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define JOYAXIS_JOY_AXIS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_JoyButton 309
#define JOYBUTTON_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define JOYBUTTON_JOY_BUTTON num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_JoyHat 310
#define JOYHAT_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define JOYHAT_JOY_HAT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetJoyTrackBall 311
#define GETJOYTRACKBALL_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOYTRACKBALL_BALL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOYTRACKBALL_DX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETJOYTRACKBALL_DY num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_JoyName$ 312
#define JOYNAME$_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_JoystickIsConnected 313
#define JOYSTICKISCONNECTED_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_JoyRumblePlay 314
#define JOYRUMBLEPLAY_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define JOYRUMBLEPLAY_STRENGTH num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define JOYRUMBLEPLAY_DURATION num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_JoyRumbleStop 315
#define JOYRUMBLESTOP_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_JoystickIsHaptic 316
#define JOYSTICKISHAPTIC_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_LoadFont 317
#define LOADFONT_FNT_FILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define LOADFONT_FONT_SIZE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteFont 318
#define DELETEFONT_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_FontExists 319
#define FONTEXISTS_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetFont 320
#define SETFONT_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DrawText 321
#define DRAWTEXT_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define DRAWTEXT_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWTEXT_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetTextSize 322
#define GETTEXTSIZE_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define GETTEXTSIZE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTEXTSIZE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_TextWidth 323
#define TEXTWIDTH_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_TextHeight 324
#define TEXTHEIGHT_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_TouchPressure 325
#define FN_GetTouch 326
#define GETTOUCH_STATUS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTOUCH_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTOUCH_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETTOUCH_DX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETTOUCH_DY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_GetMultiTouch 327
#define GETMULTITOUCH_STATUS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMULTITOUCH_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMULTITOUCH_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETMULTITOUCH_FINGERS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETMULTITOUCH_DIST num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETMULTITOUCH_THETA num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_GetTouchFinger 328
#define GETTOUCHFINGER_FINGER num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTOUCHFINGER_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTOUCHFINGER_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETTOUCHFINGER_PRESSURE num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_NumFingers 329
#define FN_GetAccel 330
#define GETACCEL_ACCEL_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACCEL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACCEL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACCEL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_AccelName$ 331
#define ACCELNAME$_ACCEL_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumAccels 332
#define FN_GetGyro 333
#define GETGYRO_GYRO_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETGYRO_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETGYRO_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETGYRO_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GyroName$ 334
#define GYRONAME$_GYRO_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumGyros 335
#define FN_CheckSockets 336
#define CHECKSOCKETS_TIMEOUT_MS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TCP_SocketReady 337
#define TCP_SOCKETREADY_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_UDP_SocketReady 338
#define UDP_SOCKETREADY_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TCP_OpenSocket 339
#define TCP_OPENSOCKET_HOST$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define TCP_OPENSOCKET_PORT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TCP_CloseSocket 340
#define TCP_CLOSESOCKET_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TCP_RemoteHost 341
#define TCP_REMOTEHOST_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TCP_RemotePort 342
#define TCP_REMOTEPORT_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TCP_GetData 343
#define TCP_GETDATA_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TCP_GETDATA_NUMBYTES num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define TCP_GETDATA_SDATA$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_TCP_SendData 344
#define TCP_SENDDATA_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TCP_SENDDATA_SDATA$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_TCP_AcceptSocket 345
#define TCP_ACCEPTSOCKET_SERVER num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_UDP_OpenSocket 346
#define UDP_OPENSOCKET_PORT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_UDP_CloseSocket 347
#define UDP_CLOSESOCKET_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_UDP_GetData 348
#define UDP_GETDATA_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define UDP_GETDATA_HOST$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define UDP_GETDATA_PORT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define UDP_GETDATA_SDATA$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_UDP_Length 349
#define FN_UDP_MaxLength 350
#define FN_UDP_RemoteHost$ 351
#define UDP_REMOTEHOST$_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_UDP_RemotePort 352
#define UDP_REMOTEPORT_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_UDP_SendData 353
#define UDP_SENDDATA_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define UDP_SENDDATA_HOST$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define UDP_SENDDATA_PORT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define UDP_SENDDATA_SDATA$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_LoadVideo 354
#define LOADVIDEO_VID$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_PlayVideo 355
#define PLAYVIDEO_VLOOPS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_PauseVideo 356
#define FN_StopVideo 357
#define FN_SetVideoPosition 358
#define SETVIDEOPOSITION_POS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ResumeVideo 359
#define FN_GetVideoPosition 360
#define FN_DeleteVideo 361
#define FN_VideoIsPlaying 362
#define FN_VideoEnd 363
#define FN_GetVideoStats 364
#define GETVIDEOSTATS_VFILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define GETVIDEOSTATS_VLEN num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETVIDEOSTATS_VFPS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETVIDEOSTATS_FRAME_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETVIDEOSTATS_FRAME_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetVideoDrawRect 365
#define SETVIDEODRAWRECT_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETVIDEODRAWRECT_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETVIDEODRAWRECT_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETVIDEODRAWRECT_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetVideoDrawRect 366
#define GETVIDEODRAWRECT_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETVIDEODRAWRECT_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETVIDEODRAWRECT_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETVIDEODRAWRECT_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetVideoSize 367
#define GETVIDEOSIZE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETVIDEOSIZE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_VideoExists 368
#define FN_SetVideoVolume 369
#define SETVIDEOVOLUME_VOL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetVideoVolume 370
#define FN_System 371
#define SYSTEM_CMD$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_OS$ 372
#define FN_Command$ 373
#define COMMAND$_ARG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumCommands 374
#define FN_Env$ 375
#define ENV$_V$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_SetEnv 376
#define SETENV_VAR$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define SETENV_VALUE$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_PrefPath$ 377
#define PREFPATH$_ORG_NAME$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define PREFPATH$_APP_NAME$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_Android_GetExternalStoragePath$ 378
#define FN_Android_GetExternalStorageState 379
#define FN_Android_GetInternalStoragePath$ 380
#define FN_Android_JNI_Message$ 381
#define ANDROID_JNI_MESSAGE$_ARG$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Runtime_Utility_Message$ 382
#define RUNTIME_UTILITY_MESSAGE$_ARG$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_GetDesktopDisplayMode 383
#define GETDESKTOPDISPLAYMODE_INDEX num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETDESKTOPDISPLAYMODE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETDESKTOPDISPLAYMODE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETDESKTOPDISPLAYMODE_FREQ num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetPowerInfo 384
#define GETPOWERINFO_STATUS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPOWERINFO_SECS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPOWERINFO_PCT num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_EvalJS$ 385
#define EVALJS$_JS_CODE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_SystemReturnStdOut$ 386
#define SYSTEMRETURNSTDOUT$_CMD$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_OpenURL 387
#define OPENURL_URL$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_MessageBox 388
#define MESSAGEBOX_TITLE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define MESSAGEBOX_MSG$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_Runtime$ 389
#define FN_NumCPUs 390
#define FN_SystemRam 391
#define FN_DimMatrix 392
#define DIMMATRIX_M_ROWS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DIMMATRIX_M_COLS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_DeleteMatrix 393
#define DELETEMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_AddMatrix 394
#define ADDMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ADDMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ADDMATRIX_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_AugmentMatrix 395
#define AUGMENTMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define AUGMENTMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define AUGMENTMATRIX_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_CopyMatrix 396
#define COPYMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COPYMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_InsertMatrixColumns 397
#define INSERTMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define INSERTMATRIXCOLUMNS_C num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define INSERTMATRIXCOLUMNS_NUM_COLS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_InsertMatrixRows 398
#define INSERTMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define INSERTMATRIXROWS_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define INSERTMATRIXROWS_NUM_ROWS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_MultiplyMatrix 399
#define MULTIPLYMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define MULTIPLYMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define MULTIPLYMATRIX_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_CubeMatrix 400
#define CUBEMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CUBEMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_DeleteMatrixColumns 401
#define DELETEMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DELETEMATRIXCOLUMNS_C num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DELETEMATRIXCOLUMNS_NUM_COLS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_DeleteMatrixRows 402
#define DELETEMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DELETEMATRIXROWS_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DELETEMATRIXROWS_NUM_ROWS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ClearMatrix 403
#define CLEARMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ClearMatrixColumns 404
#define CLEARMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CLEARMATRIXCOLUMNS_C num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CLEARMATRIXCOLUMNS_NUM_COLS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ClearMatrixRows 405
#define CLEARMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CLEARMATRIXROWS_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CLEARMATRIXROWS_NUM_ROWS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_FillMatrix 406
#define FILLMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FILLMATRIX_V num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_FillMatrixColumns 407
#define FILLMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FILLMATRIXCOLUMNS_C num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FILLMATRIXCOLUMNS_NUM_COLS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FILLMATRIXCOLUMNS_V num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_FillMatrixRows 408
#define FILLMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FILLMATRIXROWS_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FILLMATRIXROWS_NUM_ROWS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FILLMATRIXROWS_V num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_CopyMatrixColumns 409
#define COPYMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COPYMATRIXCOLUMNS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COPYMATRIXCOLUMNS_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define COPYMATRIXCOLUMNS_NUM_COLS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_CopyMatrixRows 410
#define COPYMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COPYMATRIXROWS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COPYMATRIXROWS_R num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define COPYMATRIXROWS_NUM_ROWS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetIdentityMatrix 411
#define SETIDENTITYMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETIDENTITYMATRIX_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SolveMatrix 412
#define SOLVEMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SOLVEMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SOLVEMATRIX_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_IsEqualMatrix 413
#define ISEQUALMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ISEQUALMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ISEQUALMATRIX_TOLERANCE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_Determinant 414
#define DETERMINANT_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_AdjointMatrix 415
#define ADJOINTMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ADJOINTMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_InvertMatrix 416
#define INVERTMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define INVERTMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_MatrixFromBuffer 417
#define MATRIXFROMBUFFER_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define MATRIXFROMBUFFER_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define MATRIXFROMBUFFER_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define MATRIXFROMBUFFER_BUFFER num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_BufferFromMatrix 418
#define BUFFERFROMMATRIX_BUFFER num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define BUFFERFROMMATRIX_MA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_RandomizeMatrix 419
#define RANDOMIZEMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define RANDOMIZEMATRIX_VMIN num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define RANDOMIZEMATRIX_VMAX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_MatrixValue 420
#define MATRIXVALUE_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define MATRIXVALUE_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define MATRIXVALUE_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetMatrixValue 421
#define SETMATRIXVALUE_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATRIXVALUE_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATRIXVALUE_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETMATRIXVALUE_V num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_ScalarMatrix 422
#define SCALARMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SCALARMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SCALARMATRIX_S_VALUE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ScalarMatrixColumns 423
#define SCALARMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SCALARMATRIXCOLUMNS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SCALARMATRIXCOLUMNS_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SCALARMATRIXCOLUMNS_NUM_COLS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SCALARMATRIXCOLUMNS_S_VALUE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_ScalarMatrixRows 424
#define SCALARMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SCALARMATRIXROWS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SCALARMATRIXROWS_R num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SCALARMATRIXROWS_NUM_ROWS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SCALARMATRIXROWS_S_VALUE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_SquareMatrix 425
#define SQUAREMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SQUAREMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_CofactorMatrix 426
#define COFACTORMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COFACTORMATRIX_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COFACTORMATRIX_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SubtractMatrix 427
#define SUBTRACTMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SUBTRACTMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SUBTRACTMATRIX_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SwapMatrix 428
#define SWAPMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SWAPMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SwapMatrixColumn 429
#define SWAPMATRIXCOLUMN_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SWAPMATRIXCOLUMN_C1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SWAPMATRIXCOLUMN_C2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SwapMatrixRow 430
#define SWAPMATRIXROW_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SWAPMATRIXROW_R1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SWAPMATRIXROW_R2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_TransposeMatrix 431
#define TRANSPOSEMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TRANSPOSEMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_UnAugmentMatrix 432
#define UNAUGMENTMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define UNAUGMENTMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define UNAUGMENTMATRIX_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ZeroMatrix 433
#define ZEROMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetMatrixSize 434
#define GETMATRIXSIZE_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMATRIXSIZE_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMATRIXSIZE_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_IncrementMatrixRows 435
#define INCREMENTMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define INCREMENTMATRIXROWS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define INCREMENTMATRIXROWS_R num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define INCREMENTMATRIXROWS_NUM_ROWS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define INCREMENTMATRIXROWS_VALUE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_IncrementMatrixColumns 436
#define INCREMENTMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define INCREMENTMATRIXCOLUMNS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define INCREMENTMATRIXCOLUMNS_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define INCREMENTMATRIXCOLUMNS_NUM_COLS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define INCREMENTMATRIXCOLUMNS_VALUE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_JoinMatrixRows 437
#define JOINMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define JOINMATRIXROWS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define JOINMATRIXROWS_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_JoinMatrixColumns 438
#define JOINMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define JOINMATRIXCOLUMNS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define JOINMATRIXCOLUMNS_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ClipMatrix 439
#define CLIPMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CLIPMATRIX_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CLIPMATRIX_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CLIPMATRIX_NUM_ROWS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CLIPMATRIX_NUM_COLS num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CLIPMATRIX_MB num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_SetMatrixTranslation 440
#define SETMATRIXTRANSLATION_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATRIXTRANSLATION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATRIXTRANSLATION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETMATRIXTRANSLATION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetMatrixRotation 441
#define SETMATRIXROTATION_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATRIXROTATION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATRIXROTATION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETMATRIXROTATION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetMatrixScale 442
#define SETMATRIXSCALE_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATRIXSCALE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATRIXSCALE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETMATRIXSCALE_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetMatrixTranslation 443
#define GETMATRIXTRANSLATION_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMATRIXTRANSLATION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMATRIXTRANSLATION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETMATRIXTRANSLATION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetMatrixRotation 444
#define GETMATRIXROTATION_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMATRIXROTATION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMATRIXROTATION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETMATRIXROTATION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetMatrixScale 445
#define GETMATRIXSCALE_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMATRIXSCALE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMATRIXSCALE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETMATRIXSCALE_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetClipboardText$ 446
#define FN_SetClipboardText 447
#define SETCLIPBOARDTEXT_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_HasClipboardText 448
#define FN_ReadInput_Start 449
#define FN_ReadInput_Stop 450
#define FN_ReadInput_GetText$ 451
#define FN_ReadInput_SetText 452
#define READINPUT_SETTEXT_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_ReadInput_ToggleBackspace 453
#define READINPUT_TOGGLEBACKSPACE_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateSprite 454
#define CREATESPRITE_IMG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATESPRITE_FRAME_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATESPRITE_FRAME_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_DeleteSprite 455
#define DELETESPRITE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpritePosition 456
#define SETSPRITEPOSITION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEPOSITION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITEPOSITION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_TranslateSprite 457
#define TRANSLATESPRITE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TRANSLATESPRITE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define TRANSLATESPRITE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetSpritePosition 458
#define GETSPRITEPOSITION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEPOSITION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITEPOSITION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SpriteX 459
#define SPRITEX_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SpriteY 460
#define SPRITEY_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteRotation 461
#define SETSPRITEROTATION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEROTATION_ANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_RotateSprite 462
#define ROTATESPRITE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ROTATESPRITE_ANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteRotation 463
#define GETSPRITEROTATION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteScale 464
#define SETSPRITESCALE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITESCALE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITESCALE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ScaleSprite 465
#define SCALESPRITE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SCALESPRITE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SCALESPRITE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetSpriteScale 466
#define GETSPRITESCALE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITESCALE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITESCALE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetSpriteZ 467
#define SETSPRITEZ_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEZ_Z num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SpriteZ 468
#define SPRITEZ_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetSpriteSize 469
#define GETSPRITESIZE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITESIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITESIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SpriteWidth 470
#define SPRITEWIDTH_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SpriteHeight 471
#define SPRITEHEIGHT_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteVisible 472
#define SETSPRITEVISIBLE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEVISIBLE_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SpriteIsVisible 473
#define SPRITEISVISIBLE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteSolid 474
#define SETSPRITESOLID_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITESOLID_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SpriteIsSolid 475
#define SPRITEISSOLID_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteType 476
#define SETSPRITETYPE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITETYPE_SPRITE_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteType 477
#define GETSPRITETYPE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteSource 478
#define SETSPRITESOURCE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITESOURCE_IMG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteSource 479
#define GETSPRITESOURCE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateSpriteAnimation 480
#define CREATESPRITEANIMATION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATESPRITEANIMATION_ANIM_LENGTH num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATESPRITEANIMATION_SPEED num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetSpriteFrame 481
#define SETSPRITEFRAME_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEFRAME_FRAME num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteFrame 482
#define GETSPRITEFRAME_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteAnimationFrame 483
#define SETSPRITEANIMATIONFRAME_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEANIMATIONFRAME_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITEANIMATIONFRAME_ANIM_FRAME num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETSPRITEANIMATIONFRAME_FRAME num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetSpriteAnimationFrame 484
#define GETSPRITEANIMATIONFRAME_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEANIMATIONFRAME_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITEANIMATIONFRAME_ANIM_FRAME num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetSpriteAnimationLength 485
#define SETSPRITEANIMATIONLENGTH_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEANIMATIONLENGTH_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITEANIMATIONLENGTH_ANIM_LENGTH num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetSpriteAnimationLength 486
#define GETSPRITEANIMATIONLENGTH_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEANIMATIONLENGTH_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetSpriteAnimationSpeed 487
#define SETSPRITEANIMATIONSPEED_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEANIMATIONSPEED_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITEANIMATIONSPEED_SPEED num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetSpriteAnimationSpeed 488
#define GETSPRITEANIMATIONSPEED_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEANIMATIONSPEED_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetSpriteAnimation 489
#define SETSPRITEANIMATION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEANIMATION_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITEANIMATION_NUM_LOOPS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetSpriteAnimation 490
#define GETSPRITEANIMATION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetSpriteCurrentAnimationFrame 491
#define GETSPRITECURRENTANIMATIONFRAME_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumSpriteAnimationLoops 492
#define NUMSPRITEANIMATIONLOOPS_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SpriteAnimationIsPlaying 493
#define SPRITEANIMATIONISPLAYING_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteSpriteAnimation 494
#define DELETESPRITEANIMATION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DELETESPRITEANIMATION_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getSpriteCenter 495
#define GETSPRITECENTER_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITECENTER_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITECENTER_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setSpriteLinearVelocity 496
#define SETSPRITELINEARVELOCITY_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITELINEARVELOCITY_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITELINEARVELOCITY_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getSpriteLinearVelocity 497
#define GETSPRITELINEARVELOCITY_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITELINEARVELOCITY_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITELINEARVELOCITY_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setSpriteAngularVelocity 498
#define SETSPRITEANGULARVELOCITY_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEANGULARVELOCITY_AV num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getSpriteAngularVelocity 499
#define GETSPRITEANGULARVELOCITY_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_applySpriteForce 500
#define APPLYSPRITEFORCE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYSPRITEFORCE_FX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYSPRITEFORCE_FY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYSPRITEFORCE_PX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define APPLYSPRITEFORCE_PY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_applySpriteCentralForce 501
#define APPLYSPRITECENTRALFORCE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYSPRITECENTRALFORCE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYSPRITECENTRALFORCE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_applySpriteTorque 502
#define APPLYSPRITETORQUE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYSPRITETORQUE_TORQUE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_applySpriteLinearImpulse 503
#define APPLYSPRITELINEARIMPULSE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYSPRITELINEARIMPULSE_IX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYSPRITELINEARIMPULSE_IY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYSPRITELINEARIMPULSE_PX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define APPLYSPRITELINEARIMPULSE_PY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_applySpriteAngularImpulse 504
#define APPLYSPRITEANGULARIMPULSE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYSPRITEANGULARIMPULSE_IMPULSE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getSpriteMass 505
#define GETSPRITEMASS_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSpriteInertia 506
#define GETSPRITEINERTIA_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSpriteWorldPoint 507
#define GETSPRITEWORLDPOINT_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEWORLDPOINT_LX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITEWORLDPOINT_LY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITEWORLDPOINT_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITEWORLDPOINT_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getSpriteWorldVector 508
#define GETSPRITEWORLDVECTOR_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEWORLDVECTOR_LX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITEWORLDVECTOR_LY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITEWORLDVECTOR_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITEWORLDVECTOR_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getSpriteLocalPoint 509
#define GETSPRITELOCALPOINT_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITELOCALPOINT_WX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITELOCALPOINT_WY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITELOCALPOINT_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITELOCALPOINT_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getSpriteLocalVector 510
#define GETSPRITELOCALVECTOR_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITELOCALVECTOR_WX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITELOCALVECTOR_WY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITELOCALVECTOR_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITELOCALVECTOR_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getSpriteLinearVelocityFromLocalPoint 511
#define GETSPRITELINEARVELOCITYFROMLOCALPOINT_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMLOCALPOINT_PX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMLOCALPOINT_PY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMLOCALPOINT_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMLOCALPOINT_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getSpriteLinearVelocityFromWorldPoint 512
#define GETSPRITELINEARVELOCITYFROMWORLDPOINT_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMWORLDPOINT_WX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMWORLDPOINT_WY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMWORLDPOINT_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMWORLDPOINT_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getSpriteLinearDamping 513
#define GETSPRITELINEARDAMPING_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSpriteLinearDamping 514
#define SETSPRITELINEARDAMPING_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITELINEARDAMPING_LINEARDAMPING num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getSpriteAngularDamping 515
#define GETSPRITEANGULARDAMPING_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSpriteAngularDamping 516
#define SETSPRITEANGULARDAMPING_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEANGULARDAMPING_ANGULARDAMPING num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getSpriteGravityScale 517
#define GETSPRITEGRAVITYSCALE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSpriteGravityScale 518
#define SETSPRITEGRAVITYSCALE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEGRAVITYSCALE_G_SCALE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSpriteBullet 519
#define SETSPRITEBULLET_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEBULLET_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_spriteIsBullet 520
#define SPRITEISBULLET_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSpriteSleepAllowed 521
#define SETSPRITESLEEPALLOWED_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITESLEEPALLOWED_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_spriteSleepAllowed 522
#define SPRITESLEEPALLOWED_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSpriteAwake 523
#define SETSPRITEAWAKE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEAWAKE_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_spriteIsAwake 524
#define SPRITEISAWAKE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSpriteFixedRotation 525
#define SETSPRITEFIXEDROTATION_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEFIXEDROTATION_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_spriteIsFixedRotation 526
#define SPRITEISFIXEDROTATION_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteDensity 527
#define SETSPRITEDENSITY_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEDENSITY_DENSITY num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteDensity 528
#define GETSPRITEDENSITY_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteFriction 529
#define SETSPRITEFRICTION_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEFRICTION_FRICTION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteFriction 530
#define GETSPRITEFRICTION_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteRestitution 531
#define SETSPRITERESTITUTION_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITERESTITUTION_RESTITUTION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteRestitution 532
#define GETSPRITERESTITUTION_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteRestitutionThreshold 533
#define SETSPRITERESTITUTIONTHRESHOLD_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITERESTITUTIONTHRESHOLD_THRESHOLD num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteRestitutionThreshold 534
#define GETSPRITERESTITUTIONTHRESHOLD_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetSpriteAABB 535
#define GETSPRITEAABB_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEAABB_X1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITEAABB_Y1 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITEAABB_X2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITEAABB_Y2 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_SetGravity2D 536
#define SETGRAVITY2D_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETGRAVITY2D_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetGravity2D 537
#define GETGRAVITY2D_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETGRAVITY2D_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetWorld2DTimeStep 538
#define SETWORLD2DTIMESTEP_TS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetWorld2DVelocityIterations 539
#define SETWORLD2DVELOCITYITERATIONS_V num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetWorld2DPositionIterations 540
#define SETWORLD2DPOSITIONITERATIONS_P num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetWorld2DTimeStep 541
#define FN_GetWorld2DVelocityIterations 542
#define FN_GetWorld2DPositionIterations 543
#define FN_SetWorld2DAutoClearForces 544
#define SETWORLD2DAUTOCLEARFORCES_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetWorld2DAutoClearForces 545
#define FN_CastRay2D 546
#define CASTRAY2D_FROM_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CASTRAY2D_FROM_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CASTRAY2D_TO_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CASTRAY2D_TO_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_CastRay2D_All 547
#define CASTRAY2D_ALL_FROM_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CASTRAY2D_ALL_FROM_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CASTRAY2D_ALL_TO_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CASTRAY2D_ALL_TO_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetRayHit2D 548
#define GETRAYHIT2D_INDEX num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETRAYHIT2D_SPR_ID num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETRAYHIT2D_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETRAYHIT2D_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETRAYHIT2D_NORMAL_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETRAYHIT2D_NORMAL_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_createDistanceJoint 549
#define CREATEDISTANCEJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEDISTANCEJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEDISTANCEJOINT_AX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEDISTANCEJOINT_AY num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEDISTANCEJOINT_BX num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CREATEDISTANCEJOINT_BY num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define CREATEDISTANCEJOINT_COLLIDE_CONNECT num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_createFrictionJoint 550
#define CREATEFRICTIONJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEFRICTIONJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEFRICTIONJOINT_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEFRICTIONJOINT_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEFRICTIONJOINT_COLLIDE_CONNECT num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_createGearJoint 551
#define CREATEGEARJOINT_JOINTA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEGEARJOINT_JOINTB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEGEARJOINT_G_RATIO num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEGEARJOINT_COLLIDE_CONNECT num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_createMotorJoint 552
#define CREATEMOTORJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEMOTORJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEMOTORJOINT_COLLIDE_CONNECT num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_createPrismaticJoint 553
#define CREATEPRISMATICJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEPRISMATICJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEPRISMATICJOINT_AX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEPRISMATICJOINT_AY num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEPRISMATICJOINT_AXISX num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CREATEPRISMATICJOINT_AXISY num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define CREATEPRISMATICJOINT_COLLIDE_CONNECT num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_createPulleyJoint 554
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
#define FN_createRevoluteJoint 555
#define CREATEREVOLUTEJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEREVOLUTEJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEREVOLUTEJOINT_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEREVOLUTEJOINT_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEREVOLUTEJOINT_COLLIDE_CONNECT num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_createWeldJoint 556
#define CREATEWELDJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEWELDJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEWELDJOINT_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEWELDJOINT_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEWELDJOINT_COLLIDE_CONNECT num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_createWheelJoint 557
#define CREATEWHEELJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEWHEELJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEWHEELJOINT_AX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEWHEELJOINT_AY num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEWHEELJOINT_AXISX num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CREATEWHEELJOINT_AXISY num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define CREATEWHEELJOINT_COLLIDE_CONNECT num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_getJointWorldAnchorA 558
#define GETJOINTWORLDANCHORA_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTWORLDANCHORA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTWORLDANCHORA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointWorldAnchorB 559
#define GETJOINTWORLDANCHORB_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTWORLDANCHORB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTWORLDANCHORB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointReactionForce 560
#define GETJOINTREACTIONFORCE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTREACTIONFORCE_INV_DT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTREACTIONFORCE_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETJOINTREACTIONFORCE_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getJointReactionTorque 561
#define GETJOINTREACTIONTORQUE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTREACTIONTORQUE_INV_DT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointLocalAnchorA 562
#define GETJOINTLOCALANCHORA_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTLOCALANCHORA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTLOCALANCHORA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointLocalAnchorB 563
#define GETJOINTLOCALANCHORB_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTLOCALANCHORB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTLOCALANCHORB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setJointLength 564
#define SETJOINTLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTLENGTH_JLEN num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointLength 565
#define GETJOINTLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointMinLength 566
#define SETJOINTMINLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMINLENGTH_JLEN num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMinLength 567
#define GETJOINTMINLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointMaxLength 568
#define SETJOINTMAXLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMAXLENGTH_JLEN num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMaxLength 569
#define GETJOINTMAXLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointCurrentLength 570
#define GETJOINTCURRENTLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointStiffness 571
#define SETJOINTSTIFFNESS_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTSTIFFNESS_STIFFNESS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointStiffness 572
#define GETJOINTSTIFFNESS_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointDamping 573
#define SETJOINTDAMPING_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTDAMPING_DAMPING num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointDamping 574
#define GETJOINTDAMPING_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointMaxForce 575
#define SETJOINTMAXFORCE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMAXFORCE_FORCE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMaxForce 576
#define GETJOINTMAXFORCE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointMaxTorque 577
#define SETJOINTMAXTORQUE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMAXTORQUE_TORQUE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMaxTorque 578
#define GETJOINTMAXTORQUE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointCorrectionFactor 579
#define SETJOINTCORRECTIONFACTOR_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTCORRECTIONFACTOR_FACTOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointCorrectionFactor 580
#define GETJOINTCORRECTIONFACTOR_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointRatio 581
#define SETJOINTRATIO_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTRATIO_J_RATIO num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointRatio 582
#define GETJOINTRATIO_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointLinearOffset 583
#define SETJOINTLINEAROFFSET_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTLINEAROFFSET_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETJOINTLINEAROFFSET_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointLinearOffset 584
#define GETJOINTLINEAROFFSET_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTLINEAROFFSET_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTLINEAROFFSET_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setJointAngularOffset 585
#define SETJOINTANGULAROFFSET_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTANGULAROFFSET_ANGLEOFFSET num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointAngularOffset 586
#define GETJOINTANGULAROFFSET_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointLocalAxisA 587
#define GETJOINTLOCALAXISA_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTLOCALAXISA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTLOCALAXISA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointReferenceAngle 588
#define GETJOINTREFERENCEANGLE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointTranslation 589
#define GETJOINTTRANSLATION_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointSpeed 590
#define GETJOINTSPEED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_jointIsLimitEnabled 591
#define JOINTISLIMITENABLED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_enableJointLimit 592
#define ENABLEJOINTLIMIT_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ENABLEJOINTLIMIT_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointLowerLimit 593
#define GETJOINTLOWERLIMIT_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointUpperLimit 594
#define GETJOINTUPPERLIMIT_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointLimits 595
#define SETJOINTLIMITS_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTLIMITS_LOWER_LIMIT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETJOINTLIMITS_UPPER_LIMIT num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_jointMotorIsEnabled 596
#define JOINTMOTORISENABLED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_enableJointMotor 597
#define ENABLEJOINTMOTOR_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ENABLEJOINTMOTOR_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setJointMotorSpeed 598
#define SETJOINTMOTORSPEED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMOTORSPEED_SPEED num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMotorSpeed 599
#define GETJOINTMOTORSPEED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointMaxMotorForce 600
#define SETJOINTMAXMOTORFORCE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMAXMOTORFORCE_FORCE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMaxMotorForce 601
#define GETJOINTMAXMOTORFORCE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointMotorForce 602
#define GETJOINTMOTORFORCE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTMOTORFORCE_INV_DT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setJointMaxMotorTorque 603
#define SETJOINTMAXMOTORTORQUE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMAXMOTORTORQUE_TORQUE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMaxMotorTorque 604
#define GETJOINTMAXMOTORTORQUE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointMotorTorque 605
#define GETJOINTMOTORTORQUE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTMOTORTORQUE_INV_DT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointGroundAnchorA 606
#define GETJOINTGROUNDANCHORA_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTGROUNDANCHORA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTGROUNDANCHORA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointGroundAnchorB 607
#define GETJOINTGROUNDANCHORB_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTGROUNDANCHORB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTGROUNDANCHORB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointLengthA 608
#define GETJOINTLENGTHA_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointLengthB 609
#define GETJOINTLENGTHB_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointCurrentLengthA 610
#define GETJOINTCURRENTLENGTHA_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointCurrentLengthB 611
#define GETJOINTCURRENTLENGTHB_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointOrigin 612
#define SETJOINTORIGIN_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTORIGIN_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETJOINTORIGIN_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointAngle 613
#define GETJOINTANGLE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointLinearSpeed 614
#define GETJOINTLINEARSPEED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointAngularSpeed 615
#define GETJOINTANGULARSPEED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteJoint 616
#define DELETEJOINT_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateTileSet 617
#define CREATETILESET_IMG_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATETILESET_TILE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATETILESET_TILE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetTileAnimationLength 618
#define SETTILEANIMATIONLENGTH_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTILEANIMATIONLENGTH_BASE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTILEANIMATIONLENGTH_NUM_FRAMES num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetTileAnimationLength 619
#define GETTILEANIMATIONLENGTH_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTILEANIMATIONLENGTH_BASE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetTileAnimationFrame 620
#define SETTILEANIMATIONFRAME_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTILEANIMATIONFRAME_BASE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTILEANIMATIONFRAME_ANIM_FRAME num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETTILEANIMATIONFRAME_TILE_FRAME num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetTileAnimationFrame 621
#define GETTILEANIMATIONFRAME_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTILEANIMATIONFRAME_BASE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTILEANIMATIONFRAME_ANIM_FRAME num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetTileAnimationSpeed 622
#define SETTILEANIMATIONSPEED_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTILEANIMATIONSPEED_BASE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTILEANIMATIONSPEED_SPEED num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetTileAnimationSpeed 623
#define GETTILEANIMATIONSPEED_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTILEANIMATIONSPEED_BASE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_CreateTileMap 624
#define CREATETILEMAP_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATETILEMAP_WIDTHINTILES num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATETILEMAP_HEIGHTINTILES num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetTileMapSize 625
#define SETTILEMAPSIZE_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTILEMAPSIZE_WIDTHINTILES num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTILEMAPSIZE_HEIGHTINTILES num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetTileMapSize 626
#define GETTILEMAPSIZE_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTILEMAPSIZE_WIDTHINTILES num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTILEMAPSIZE_HEIGHTINTILES num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetTile 627
#define SETTILE_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTILE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTILE_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETTILE_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetTile 628
#define GETTILE_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTILE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTILE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_FillTile 629
#define FILLTILE_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FILLTILE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FILLTILE_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FILLTILE_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FILLTILE_WIDTHINTILES num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FILLTILE_HEIGHTINTILES num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_DrawTileMap 630
#define DRAWTILEMAP_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWTILEMAP_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWTILEMAP_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWTILEMAP_W num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWTILEMAP_H num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define DRAWTILEMAP_OFFSET_X num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define DRAWTILEMAP_OFFSET_Y num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_DeleteTileSet 631
#define DELETETILESET_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteTileMap 632
#define DELETETILEMAP_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_LoadMesh 633
#define LOADMESH_MESH_FILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_DeleteMesh 634
#define DELETEMESH_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateMesh 635
#define FN_AddMeshBuffer 636
#define ADDMESHBUFFER_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ADDMESHBUFFER_VERTEX_COUNT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ADDMESHBUFFER_VERTEX_DATA num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define ADDMESHBUFFER_NORMAL_DATA num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define ADDMESHBUFFER_UV_DATA num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define ADDMESHBUFFER_INDEX_COUNT num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define ADDMESHBUFFER_INDEX_DATA num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_LoadMeshFromArchive 637
#define LOADMESHFROMARCHIVE_ARCHIVE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define LOADMESHFROMARCHIVE_MESH_FILE$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_CreatePlaneMesh 638
#define CREATEPLANEMESH_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEPLANEMESH_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEPLANEMESH_TILECOUNT_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEPLANEMESH_TILECOUNT_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_LoadAN8 639
#define LOADAN8_AN8_FILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_LoadMeshFromAN8 640
#define LOADMESHFROMAN8_AN8_PROJECT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define LOADMESHFROMAN8_AN8_SCENE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_GetNumAN8Scenes 641
#define GETNUMAN8SCENES_AN8_PROJECT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetAN8SceneName$ 642
#define GETAN8SCENENAME$_AN8_PROJECT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETAN8SCENENAME$_SCENE_NUM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_CreateAnimatedActor 643
#define CREATEANIMATEDACTOR_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateOctreeActor 644
#define CREATEOCTREEACTOR_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateCubeActor 645
#define CREATECUBEACTOR_CUBE_SIZE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateSphereActor 646
#define CREATESPHEREACTOR_RADIUS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateWaterActor 647
#define CREATEWATERACTOR_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEWATERACTOR_WAVEHEIGHT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEWATERACTOR_WAVESPEED num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEWATERACTOR_WAVELENGTH num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_CreateLightActor 648
#define FN_CreateBillboardActor 649
#define FN_CreateTerrainActor 650
#define CREATETERRAINACTOR_HMAP_FILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_CreateParticleActor 651
#define CREATEPARTICLEACTOR_PARTICLE_TYPE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteActor 652
#define DELETEACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetActorTransform 653
#define GETACTORTRANSFORM_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORTRANSFORM_MATRIX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetActorPosition 654
#define SETACTORPOSITION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORPOSITION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORPOSITION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORPOSITION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_TranslateActorLocal 655
#define TRANSLATEACTORLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TRANSLATEACTORLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define TRANSLATEACTORLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define TRANSLATEACTORLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_TranslateActorWorld 656
#define TRANSLATEACTORWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TRANSLATEACTORWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define TRANSLATEACTORWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define TRANSLATEACTORWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetActorPosition 657
#define GETACTORPOSITION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORPOSITION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORPOSITION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORPOSITION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetActorScale 658
#define SETACTORSCALE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORSCALE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORSCALE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORSCALE_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_ScaleActor 659
#define SCALEACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SCALEACTOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SCALEACTOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SCALEACTOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetActorScale 660
#define GETACTORSCALE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORSCALE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORSCALE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORSCALE_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetActorRotation 661
#define SETACTORROTATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORROTATION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORROTATION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORROTATION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_RotateActor 662
#define ROTATEACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ROTATEACTOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ROTATEACTOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define ROTATEACTOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetActorRotation 663
#define GETACTORROTATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORROTATION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORROTATION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORROTATION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetActorVisible 664
#define SETACTORVISIBLE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORVISIBLE_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ActorIsVisible 665
#define ACTORISVISIBLE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetActorAutoCulling 666
#define SETACTORAUTOCULLING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORAUTOCULLING_CULL_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetActorAutoCulling 667
#define GETACTORAUTOCULLING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_AddActorShadow 668
#define ADDACTORSHADOW_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_RemoveActorShadow 669
#define REMOVEACTORSHADOW_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ActorExists 670
#define ACTOREXISTS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateActorAnimation 671
#define CREATEACTORANIMATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEACTORANIMATION_START_FRAME num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEACTORANIMATION_END_FRAME num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEACTORANIMATION_SPEED num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetActorAnimation 672
#define SETACTORANIMATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORANIMATION_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORANIMATION_NUM_LOOPS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetActorAnimationSpeed 673
#define SETACTORANIMATIONSPEED_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORANIMATIONSPEED_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORANIMATIONSPEED_SPEED num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetActorAnimationFrames 674
#define SETACTORANIMATIONFRAMES_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORANIMATIONFRAMES_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORANIMATIONFRAMES_START_FRAME num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORANIMATIONFRAMES_END_FRAME num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetActorCurrentAnimation 675
#define GETACTORCURRENTANIMATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetActorAnimationSpeed 676
#define GETACTORANIMATIONSPEED_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORANIMATIONSPEED_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetActorAnimationStartFrame 677
#define GETACTORANIMATIONSTARTFRAME_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORANIMATIONSTARTFRAME_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetActorAnimationEndFrame 678
#define GETACTORANIMATIONENDFRAME_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORANIMATIONENDFRAME_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetActorFrame 679
#define SETACTORFRAME_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORFRAME_FRAME num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetActorFrame 680
#define GETACTORFRAME_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ActorAnimationIsPlaying 681
#define ACTORANIMATIONISPLAYING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumActorAnimationLoops 682
#define NUMACTORANIMATIONLOOPS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetActorMD2Animation 683
#define SETACTORMD2ANIMATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORMD2ANIMATION_ANIM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORMD2ANIMATION_NUM_LOOPS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetActorMD2AnimationByName 684
#define SETACTORMD2ANIMATIONBYNAME_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORMD2ANIMATIONBYNAME_ANIM_NAME$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define SETACTORMD2ANIMATIONBYNAME_NUM_LOOPS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_DeleteActorAnimation 685
#define DELETEACTORANIMATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DELETEACTORANIMATION_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetGravity3D 686
#define SETGRAVITY3D_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETGRAVITY3D_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETGRAVITY3D_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetGravity3D 687
#define GETGRAVITY3D_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETGRAVITY3D_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETGRAVITY3D_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetActorCollisionShape 688
#define SETACTORCOLLISIONSHAPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORCOLLISIONSHAPE_SHAPE_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORCOLLISIONSHAPE_MASS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetActorCollisionShape 689
#define GETACTORCOLLISIONSHAPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetActorSolid 690
#define SETACTORSOLID_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORSOLID_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ActorIsSolid 691
#define ACTORISSOLID_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetActorCollision 692
#define GETACTORCOLLISION_ACTOR1 num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORCOLLISION_ACTOR2 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetActorGravity 693
#define SETACTORGRAVITY_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORGRAVITY_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORGRAVITY_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORGRAVITY_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetActorGravity 694
#define GETACTORGRAVITY_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORGRAVITY_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORGRAVITY_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORGRAVITY_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorDamping 695
#define SETACTORDAMPING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORDAMPING_LIN_DAMPING num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORDAMPING_ANG_DAMPING num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getActorLinearDamping 696
#define GETACTORLINEARDAMPING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getActorAngularDamping 697
#define GETACTORANGULARDAMPING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getActorLinearSleepThreshold 698
#define GETACTORLINEARSLEEPTHRESHOLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getActorAngularSleepThreshold 699
#define GETACTORANGULARSLEEPTHRESHOLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_applyActorDamping 700
#define APPLYACTORDAMPING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORDAMPING_TIMESTEP num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setActorMassProperties 701
#define SETACTORMASSPROPERTIES_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORMASSPROPERTIES_MASS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORMASSPROPERTIES_INERTIA_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORMASSPROPERTIES_INERTIA_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETACTORMASSPROPERTIES_INERTIA_Z num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getActorLinearFactor 702
#define GETACTORLINEARFACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORLINEARFACTOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORLINEARFACTOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORLINEARFACTOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorLinearFactor 703
#define SETACTORLINEARFACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORLINEARFACTOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORLINEARFACTOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORLINEARFACTOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorInverseMass 704
#define GETACTORINVERSEMASS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_integrateActorVelocities 705
#define INTEGRATEACTORVELOCITIES_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define INTEGRATEACTORVELOCITIES_V_STEP num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_applyActorCentralForceLocal 706
#define APPLYACTORCENTRALFORCELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORCENTRALFORCELOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORCENTRALFORCELOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORCENTRALFORCELOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorCentralForceWorld 707
#define APPLYACTORCENTRALFORCEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORCENTRALFORCEWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORCENTRALFORCEWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORCENTRALFORCEWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorTotalForce 708
#define GETACTORTOTALFORCE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORTOTALFORCE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORTOTALFORCE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORTOTALFORCE_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorTotalTorque 709
#define GETACTORTOTALTORQUE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORTOTALTORQUE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORTOTALTORQUE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORTOTALTORQUE_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorInverseInertiaDiagLocal 710
#define GETACTORINVERSEINERTIADIAGLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORINVERSEINERTIADIAGLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORINVERSEINERTIADIAGLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORINVERSEINERTIADIAGLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorInverseInertiaDiagLocal 711
#define SETACTORINVERSEINERTIADIAGLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORINVERSEINERTIADIAGLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORINVERSEINERTIADIAGLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORINVERSEINERTIADIAGLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorSleepThresholds 712
#define SETACTORSLEEPTHRESHOLDS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORSLEEPTHRESHOLDS_LINEAR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORSLEEPTHRESHOLDS_ANGULAR num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_applyActorTorqueLocal 713
#define APPLYACTORTORQUELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORTORQUELOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORTORQUELOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORTORQUELOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorTorqueWorld 714
#define APPLYACTORTORQUEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORTORQUEWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORTORQUEWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORTORQUEWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorForceLocal 715
#define APPLYACTORFORCELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORFORCELOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORFORCELOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORFORCELOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define APPLYACTORFORCELOCAL_REL_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define APPLYACTORFORCELOCAL_REL_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define APPLYACTORFORCELOCAL_REL_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_applyActorForceWorld 716
#define APPLYACTORFORCEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORFORCEWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORFORCEWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORFORCEWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define APPLYACTORFORCEWORLD_REL_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define APPLYACTORFORCEWORLD_REL_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define APPLYACTORFORCEWORLD_REL_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_applyActorCentralImpulseLocal 717
#define APPLYACTORCENTRALIMPULSELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORCENTRALIMPULSELOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORCENTRALIMPULSELOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORCENTRALIMPULSELOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorCentralImpulseWorld 718
#define APPLYACTORCENTRALIMPULSEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORCENTRALIMPULSEWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORCENTRALIMPULSEWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORCENTRALIMPULSEWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorTorqueImpulseLocal 719
#define APPLYACTORTORQUEIMPULSELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORTORQUEIMPULSELOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORTORQUEIMPULSELOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORTORQUEIMPULSELOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorTorqueImpulseWorld 720
#define APPLYACTORTORQUEIMPULSEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORTORQUEIMPULSEWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORTORQUEIMPULSEWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORTORQUEIMPULSEWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorImpulseLocal 721
#define APPLYACTORIMPULSELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORIMPULSELOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORIMPULSELOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORIMPULSELOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define APPLYACTORIMPULSELOCAL_REL_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define APPLYACTORIMPULSELOCAL_REL_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define APPLYACTORIMPULSELOCAL_REL_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_applyActorImpulseWorld 722
#define APPLYACTORIMPULSEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORIMPULSEWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORIMPULSEWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORIMPULSEWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define APPLYACTORIMPULSEWORLD_REL_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define APPLYACTORIMPULSEWORLD_REL_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define APPLYACTORIMPULSEWORLD_REL_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_clearActorForces 723
#define CLEARACTORFORCES_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_updateActorInertiaTensor 724
#define UPDATEACTORINERTIATENSOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getActorCenter 725
#define GETACTORCENTER_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORCENTER_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORCENTER_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORCENTER_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorRotationQ 726
#define GETACTORROTATIONQ_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORROTATIONQ_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORROTATIONQ_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORROTATIONQ_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETACTORROTATIONQ_W num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getActorLinearVelocityWorld 727
#define GETACTORLINEARVELOCITYWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORLINEARVELOCITYWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORLINEARVELOCITYWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORLINEARVELOCITYWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorAngularVelocityWorld 728
#define GETACTORANGULARVELOCITYWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORANGULARVELOCITYWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORANGULARVELOCITYWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORANGULARVELOCITYWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorLinearVelocityLocal 729
#define SETACTORLINEARVELOCITYLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORLINEARVELOCITYLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORLINEARVELOCITYLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORLINEARVELOCITYLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorLinearVelocityWorld 730
#define SETACTORLINEARVELOCITYWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORLINEARVELOCITYWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORLINEARVELOCITYWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORLINEARVELOCITYWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorAngularVelocityLocal 731
#define SETACTORANGULARVELOCITYLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORANGULARVELOCITYLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORANGULARVELOCITYLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORANGULARVELOCITYLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorAngularVelocityWorld 732
#define SETACTORANGULARVELOCITYWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORANGULARVELOCITYWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORANGULARVELOCITYWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORANGULARVELOCITYWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorVelocityInLocalPoint 733
#define GETACTORVELOCITYINLOCALPOINT_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORVELOCITYINLOCALPOINT_REL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORVELOCITYINLOCALPOINT_REL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORVELOCITYINLOCALPOINT_REL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETACTORVELOCITYINLOCALPOINT_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETACTORVELOCITYINLOCALPOINT_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETACTORVELOCITYINLOCALPOINT_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_getActorLinearVelocityLocal 734
#define GETACTORLINEARVELOCITYLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORLINEARVELOCITYLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORLINEARVELOCITYLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORLINEARVELOCITYLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorAngularVelocityLocal 735
#define GETACTORANGULARVELOCITYLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORANGULARVELOCITYLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORANGULARVELOCITYLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORANGULARVELOCITYLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorAABB 736
#define GETACTORAABB_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORAABB_MIN_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORAABB_MIN_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORAABB_MIN_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETACTORAABB_MAX_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETACTORAABB_MAX_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETACTORAABB_MAX_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_computeActorImpulseDenominator 737
#define COMPUTEACTORIMPULSEDENOMINATOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_POS_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_POS_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_POS_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_NORMAL_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_NORMAL_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_NORMAL_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_computeActorAngularImpulseDenominator 738
#define COMPUTEACTORANGULARIMPULSEDENOMINATOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COMPUTEACTORANGULARIMPULSEDENOMINATOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COMPUTEACTORANGULARIMPULSEDENOMINATOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define COMPUTEACTORANGULARIMPULSEDENOMINATOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorAngularFactor 739
#define SETACTORANGULARFACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORANGULARFACTOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORANGULARFACTOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORANGULARFACTOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorAngularFactor 740
#define GETACTORANGULARFACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORANGULARFACTOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORANGULARFACTOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORANGULARFACTOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_computeActorGyroImpulseLocal 741
#define COMPUTEACTORGYROIMPULSELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COMPUTEACTORGYROIMPULSELOCAL_DT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COMPUTEACTORGYROIMPULSELOCAL_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define COMPUTEACTORGYROIMPULSELOCAL_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define COMPUTEACTORGYROIMPULSELOCAL_Z num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_computeActorGyroImpulseWorld 742
#define COMPUTEACTORGYROIMPULSEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COMPUTEACTORGYROIMPULSEWORLD_DT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COMPUTEACTORGYROIMPULSEWORLD_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define COMPUTEACTORGYROIMPULSEWORLD_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define COMPUTEACTORGYROIMPULSEWORLD_Z num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getActorLocalInertia 743
#define GETACTORLOCALINERTIA_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORLOCALINERTIA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORLOCALINERTIA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORLOCALINERTIA_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetActorSleepState 744
#define SETACTORSLEEPSTATE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORSLEEPSTATE_STATE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_CastRay3D 745
#define CASTRAY3D_FROM_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CASTRAY3D_FROM_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CASTRAY3D_FROM_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CASTRAY3D_TO_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CASTRAY3D_TO_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CASTRAY3D_TO_Z num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_CastRay3D_All 746
#define CASTRAY3D_ALL_FROM_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CASTRAY3D_ALL_FROM_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CASTRAY3D_ALL_FROM_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CASTRAY3D_ALL_TO_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CASTRAY3D_ALL_TO_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CASTRAY3D_ALL_TO_Z num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_GetRayHit3D 747
#define GETRAYHIT3D_INDEX num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETRAYHIT3D_ACTOR_ID num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETRAYHIT3D_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETRAYHIT3D_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETRAYHIT3D_Z num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETRAYHIT3D_NORMAL_X num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETRAYHIT3D_NORMAL_Y num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define GETRAYHIT3D_NORMAL_Z num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define FN_createPointConstraint 748
#define CREATEPOINTCONSTRAINT_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEPOINTCONSTRAINT_PXA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEPOINTCONSTRAINT_PYA num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEPOINTCONSTRAINT_PZA num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_createPointConstraintEx 749
#define CREATEPOINTCONSTRAINTEX_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_ACTORB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PXA num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PYA num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PZA num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PXB num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PYB num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PZB num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define FN_setPointPivotA 750
#define SETPOINTPIVOTA_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPOINTPIVOTA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPOINTPIVOTA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETPOINTPIVOTA_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setPointPivotB 751
#define SETPOINTPIVOTB_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPOINTPIVOTB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPOINTPIVOTB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETPOINTPIVOTB_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_createHingeConstraint 752
#define CREATEHINGECONSTRAINT_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEHINGECONSTRAINT_FRAMEA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEHINGECONSTRAINT_USEREFERENCEFRAMEA num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_createHingeConstraintEx 753
#define CREATEHINGECONSTRAINTEX_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEHINGECONSTRAINTEX_ACTORB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEHINGECONSTRAINTEX_FRAMEA num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEHINGECONSTRAINTEX_FRAMEB num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEHINGECONSTRAINTEX_USEREFERENCEFRAMEA num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_createSlideConstraint 754
#define CREATESLIDECONSTRAINT_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATESLIDECONSTRAINT_FRAMEINB_MATRIX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATESLIDECONSTRAINT_USELINEARREFERENCEFRAMEA num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_createSlideConstraintEx 755
#define CREATESLIDECONSTRAINTEX_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATESLIDECONSTRAINTEX_ACTORB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATESLIDECONSTRAINTEX_FRAMEINA_MATRIX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATESLIDECONSTRAINTEX_FRAMEINB_MATRIX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATESLIDECONSTRAINTEX_USELINEARREFERENCEFRAMEA num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_createConeConstraint 756
#define CREATECONECONSTRAINT_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATECONECONSTRAINT_RBAFRAME_MATRIX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_createConeConstraintEx 757
#define CREATECONECONSTRAINTEX_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATECONECONSTRAINTEX_ACTORB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATECONECONSTRAINTEX_RBAFRAME_MATRIX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATECONECONSTRAINTEX_RBBFRAME_MATRIX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_deleteConstraint 758
#define DELETECONSTRAINT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConstraintFrameOffsetA 759
#define GETCONSTRAINTFRAMEOFFSETA_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_RX num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_RY num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_RZ num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_getConstraintFrameOffsetB 760
#define GETCONSTRAINTFRAMEOFFSETB_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_RX num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_RY num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_RZ num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_useConstraintFrameOffset 761
#define USECONSTRAINTFRAMEOFFSET_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define USECONSTRAINTFRAMEOFFSET_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getHingeAngle 762
#define GETHINGEANGLE_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getHingeAngleEx 763
#define GETHINGEANGLEEX_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETHINGEANGLEEX_T_MATRIXA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETHINGEANGLEEX_T_MATRIXB num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getConstraintBreakingImpulseThreshold 764
#define GETCONSTRAINTBREAKINGIMPULSETHRESHOLD_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConstraintAFrame 765
#define GETCONSTRAINTAFRAME_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCONSTRAINTAFRAME_MA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getConstraintBFrame 766
#define GETCONSTRAINTBFRAME_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCONSTRAINTBFRAME_MA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setHingeAxis 767
#define SETHINGEAXIS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETHINGEAXIS_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETHINGEAXIS_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETHINGEAXIS_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setConstraintBreakingImpulseThreshold 768
#define SETCONSTRAINTBREAKINGIMPULSETHRESHOLD_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONSTRAINTBREAKINGIMPULSETHRESHOLD_THRESHOLD num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setConstraintFrames 769
#define SETCONSTRAINTFRAMES_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONSTRAINTFRAMES_FRAMEA_MATRIX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCONSTRAINTFRAMES_FRAMEB_MATRIX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setHingeLimit 770
#define SETHINGELIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETHINGELIMIT_LOW num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETHINGELIMIT_HIGH num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETHINGELIMIT_SOFTNESS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETHINGELIMIT_BIAS_FACTOR num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define SETHINGELIMIT_RELAXATION_FACTOR num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_setConeLimit 771
#define SETCONELIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONELIMIT_SWINGSPAN1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCONELIMIT_SWINGSPAN2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETCONELIMIT_TWISTSPAN num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETCONELIMIT_SOFTNESS num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define SETCONELIMIT_BIAS_FACTOR num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define SETCONELIMIT_RELAXATION_FACTOR num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_getHingeLimitBiasFactor 772
#define GETHINGELIMITBIASFACTOR_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getHingeLimitRelaxationFactor 773
#define GETHINGELIMITRELAXATIONFACTOR_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getHingeLimitSign 774
#define GETHINGELIMITSIGN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getHingeSolveLimit 775
#define GETHINGESOLVELIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_useHingeReferenceFrameA 776
#define USEHINGEREFERENCEFRAMEA_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define USEHINGEREFERENCEFRAMEA_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getConstraintAppliedImpulse 777
#define GETCONSTRAINTAPPLIEDIMPULSE_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConstraintFixedActor 778
#define GETCONSTRAINTFIXEDACTOR_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getPointPivotA 779
#define GETPOINTPIVOTA_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPOINTPIVOTA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPOINTPIVOTA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETPOINTPIVOTA_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getPointPivotB 780
#define GETPOINTPIVOTB_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPOINTPIVOTB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPOINTPIVOTB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETPOINTPIVOTB_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getConstraintActorA 781
#define GETCONSTRAINTACTORA_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConstraintActorB 782
#define GETCONSTRAINTACTORB_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setConstraintSolverIterations 783
#define SETCONSTRAINTSOLVERITERATIONS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONSTRAINTSOLVERITERATIONS_NUM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getConeBiasFactor 784
#define GETCONEBIASFACTOR_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeDamping 785
#define GETCONEDAMPING_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeFixThresh 786
#define GETCONEFIXTHRESH_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeLimit 787
#define GETCONELIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCONELIMIT_LIMIT_INDEX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getConstraintLimitSoftness 788
#define GETCONSTRAINTLIMITSOFTNESS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConstraintSolverIterations 789
#define GETCONSTRAINTSOLVERITERATIONS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeAnglePoint 790
#define GETCONEANGLEPOINT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCONEANGLEPOINT_ANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCONEANGLEPOINT_C_LEN num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETCONEANGLEPOINT_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETCONEANGLEPOINT_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETCONEANGLEPOINT_Z num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_getConstraintAngularOnly 791
#define GETCONSTRAINTANGULARONLY_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeSolveSwingLimit 792
#define GETCONESOLVESWINGLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeSolveTwistLimit 793
#define GETCONESOLVETWISTLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeSwingSpan1 794
#define GETCONESWINGSPAN1_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeSwingSpan2 795
#define GETCONESWINGSPAN2_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeTwistAngle 796
#define GETCONETWISTANGLE_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeTwistLimitSign 797
#define GETCONETWISTLIMITSIGN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeTwistSpan 798
#define GETCONETWISTSPAN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setConstraintAngularOnly 799
#define SETCONSTRAINTANGULARONLY_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONSTRAINTANGULARONLY_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setConeDamping 800
#define SETCONEDAMPING_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONEDAMPING_DAMPING num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setConeFixThresh 801
#define SETCONEFIXTHRESH_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONEFIXTHRESH_FIXTHRESH num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getSlideAnchorA 802
#define GETSLIDEANCHORA_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSLIDEANCHORA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSLIDEANCHORA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSLIDEANCHORA_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getSlideAnchorB 803
#define GETSLIDEANCHORB_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSLIDEANCHORB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSLIDEANCHORB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSLIDEANCHORB_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getSlideAngDepth 804
#define GETSLIDEANGDEPTH_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideAngularPos 805
#define GETSLIDEANGULARPOS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideDampingDirAng 806
#define GETSLIDEDAMPINGDIRANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideDampingDirLin 807
#define GETSLIDEDAMPINGDIRLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideDampingLimAng 808
#define GETSLIDEDAMPINGLIMANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideDampingLimLin 809
#define GETSLIDEDAMPINGLIMLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideDampingOrthoAng 810
#define GETSLIDEDAMPINGORTHOANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideDampingOrthoLin 811
#define GETSLIDEDAMPINGORTHOLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideLinearPos 812
#define GETSLIDELINEARPOS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideLinDepth 813
#define GETSLIDELINDEPTH_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideLowerAngLimit 814
#define GETSLIDELOWERANGLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideLowerLinLimit 815
#define GETSLIDELOWERLINLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideRestitutionDirAng 816
#define GETSLIDERESTITUTIONDIRANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideRestitutionDirLin 817
#define GETSLIDERESTITUTIONDIRLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideRestitutionLimAng 818
#define GETSLIDERESTITUTIONLIMANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideRestitutionLimLin 819
#define GETSLIDERESTITUTIONLIMLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideRestitutionOrthoAng 820
#define GETSLIDERESTITUTIONORTHOANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideRestitutionOrthoLin 821
#define GETSLIDERESTITUTIONORTHOLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSoftnessDirAng 822
#define GETSLIDESOFTNESSDIRANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSoftnessDirLin 823
#define GETSLIDESOFTNESSDIRLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSoftnessLimAng 824
#define GETSLIDESOFTNESSLIMANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSoftnessLimLin 825
#define GETSLIDESOFTNESSLIMLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSoftnessOrthoAng 826
#define GETSLIDESOFTNESSORTHOANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSoftnessOrthoLin 827
#define GETSLIDESOFTNESSORTHOLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSolveAngLimit 828
#define GETSLIDESOLVEANGLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSolveLinLimit 829
#define GETSLIDESOLVELINLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideUpperAngLimit 830
#define GETSLIDEUPPERANGLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideUpperLinLimit 831
#define GETSLIDEUPPERLINLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideUseFrameOffset 832
#define GETSLIDEUSEFRAMEOFFSET_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSlideDampingDirAng 833
#define SETSLIDEDAMPINGDIRANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEDAMPINGDIRANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideDampingDirLin 834
#define SETSLIDEDAMPINGDIRLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEDAMPINGDIRLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideDampingLimAng 835
#define SETSLIDEDAMPINGLIMANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEDAMPINGLIMANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideDampingLimLin 836
#define SETSLIDEDAMPINGLIMLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEDAMPINGLIMLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideDampingOrthoAng 837
#define SETSLIDEDAMPINGORTHOANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEDAMPINGORTHOANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideDampingOrthoLin 838
#define SETSLIDEDAMPINGORTHOLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEDAMPINGORTHOLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideLowerAngLimit 839
#define SETSLIDELOWERANGLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDELOWERANGLIMIT_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideLowerLinLimit 840
#define SETSLIDELOWERLINLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDELOWERLINLIMIT_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideRestitutionDirAng 841
#define SETSLIDERESTITUTIONDIRANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDERESTITUTIONDIRANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideRestitutionDirLin 842
#define SETSLIDERESTITUTIONDIRLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDERESTITUTIONDIRLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideRestitutionLimAng 843
#define SETSLIDERESTITUTIONLIMANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDERESTITUTIONLIMANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideRestitutionLimLin 844
#define SETSLIDERESTITUTIONLIMLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDERESTITUTIONLIMLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideRestitutionOrthoAng 845
#define SETSLIDERESTITUTIONORTHOANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDERESTITUTIONORTHOANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideRestitutionOrthoLin 846
#define SETSLIDERESTITUTIONORTHOLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDERESTITUTIONORTHOLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideSoftnessDirAng 847
#define SETSLIDESOFTNESSDIRANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDESOFTNESSDIRANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideSoftnessDirLin 848
#define SETSLIDESOFTNESSDIRLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDESOFTNESSDIRLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideSoftnessLimAng 849
#define SETSLIDESOFTNESSLIMANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDESOFTNESSLIMANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideSoftnessLimLin 850
#define SETSLIDESOFTNESSLIMLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDESOFTNESSLIMLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideSoftnessOrthoAng 851
#define SETSLIDESOFTNESSORTHOANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDESOFTNESSORTHOANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideSoftnessOrthoLin 852
#define SETSLIDESOFTNESSORTHOLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDESOFTNESSORTHOLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideUpperAngLimit 853
#define SETSLIDEUPPERANGLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEUPPERANGLIMIT_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideUpperLinLimit 854
#define SETSLIDEUPPERLINLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEUPPERLINLIMIT_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ConstraintExists 855
#define CONSTRAINTEXISTS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetCameraPosition 856
#define SETCAMERAPOSITION_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCAMERAPOSITION_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCAMERAPOSITION_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetCameraPosition 857
#define GETCAMERAPOSITION_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCAMERAPOSITION_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCAMERAPOSITION_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_TranslateCamera 858
#define TRANSLATECAMERA_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TRANSLATECAMERA_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define TRANSLATECAMERA_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetCameraRotation 859
#define SETCAMERAROTATION_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCAMERAROTATION_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCAMERAROTATION_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetCameraRotation 860
#define GETCAMERAROTATION_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCAMERAROTATION_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCAMERAROTATION_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_RotateCamera 861
#define ROTATECAMERA_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ROTATECAMERA_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ROTATECAMERA_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetCameraFOV 862
#define SETCAMERAFOV_FOV num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetCameraFOV 863
#define FN_SetCameraAspectRatio 864
#define SETCAMERAASPECTRATIO_ASPECT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetCameraAspectRatio 865
#define FN_SetCameraFarValue 866
#define SETCAMERAFARVALUE_ZF num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetCameraFarValue 867
#define FN_SetCameraNearValue 868
#define SETCAMERANEARVALUE_ZN num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetCameraNearValue 869
#define FN_SetProjectionMatrix 870
#define SETPROJECTIONMATRIX_MATA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPROJECTIONMATRIX_PROJECTION_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetProjectionMatrix 871
#define GETPROJECTIONMATRIX_MATA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetWorldToViewportPosition 872
#define GETWORLDTOVIEWPORTPOSITION_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWORLDTOVIEWPORTPOSITION_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETWORLDTOVIEWPORTPOSITION_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETWORLDTOVIEWPORTPOSITION_VX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETWORLDTOVIEWPORTPOSITION_VY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_AddSceneSkyBox 873
#define ADDSCENESKYBOX_IMG_TOP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ADDSCENESKYBOX_IMG_BOTTOM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ADDSCENESKYBOX_IMG_LEFT num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define ADDSCENESKYBOX_IMG_RIGHT num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define ADDSCENESKYBOX_IMG_FRONT num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define ADDSCENESKYBOX_IMG_BACK num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_AddSceneSkyDome 874
#define ADDSCENESKYDOME_IMG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_AddSceneSkyDomeEx 875
#define ADDSCENESKYDOMEEX_IMG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ADDSCENESKYDOMEEX_HORIRES num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ADDSCENESKYDOMEEX_VERTRES num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define ADDSCENESKYDOMEEX_TXPERCENTAGE num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define ADDSCENESKYDOMEEX_SPHEREPERCENTAGE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define ADDSCENESKYDOMEEX_RADIUS num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_RemoveSceneSky 876
#define FN_SetWorld3DMaxSubSteps 877
#define SETWORLD3DMAXSUBSTEPS_STEPS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetWorld3DTimeStep 878
#define SETWORLD3DTIMESTEP_TS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetWorld3DMaxSubSteps 879
#define FN_GetWorld3DTimeStep 880
#define FN_SetSceneFog 881
#define SETSCENEFOG_COLOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSCENEFOG_FOG_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSCENEFOG_START_VAL num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETSCENEFOG_END_VAL num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETSCENEFOG_DENSITY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define SETSCENEFOG_PIXELFOG num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define SETSCENEFOG_RANGEFOG num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_GetSceneFog 882
#define GETSCENEFOG_COLOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSCENEFOG_FOG_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSCENEFOG_START_VAL num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSCENEFOG_END_VAL num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSCENEFOG_DENSITY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETSCENEFOG_PIXELFOG num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETSCENEFOG_RANGEFOG num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_ClearScene 883
#define FN_startParticleEmitter 884
#define STARTPARTICLEEMITTER_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_stopParticleEmitter 885
#define STOPPARTICLEEMITTER_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleDirection 886
#define SETPARTICLEDIRECTION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEDIRECTION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPARTICLEDIRECTION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETPARTICLEDIRECTION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getParticleDirection 887
#define GETPARTICLEDIRECTION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPARTICLEDIRECTION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPARTICLEDIRECTION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETPARTICLEDIRECTION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_useParticleEveryMeshVertex 888
#define USEPARTICLEEVERYMESHVERTEX_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define USEPARTICLEEVERYMESHVERTEX_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_particleIsUsingEveryMeshVertex 889
#define PARTICLEISUSINGEVERYMESHVERTEX_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleNormalDirectionMod 890
#define SETPARTICLENORMALDIRECTIONMOD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLENORMALDIRECTIONMOD_ND_MOD num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleNormalDirectionMod 891
#define GETPARTICLENORMALDIRECTIONMOD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_useParticleNormalDirection 892
#define USEPARTICLENORMALDIRECTION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define USEPARTICLENORMALDIRECTION_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_particleIsUsingNormalDirection 893
#define PARTICLEISUSINGNORMALDIRECTION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMesh 894
#define SETPARTICLEMESH_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMESH_MESH num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setMinParticlesPerSecond 895
#define SETMINPARTICLESPERSECOND_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMINPARTICLESPERSECOND_MINPARTICLESPERSECOND num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMinParticlesPerSecond 896
#define GETMINPARTICLESPERSECOND_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaxParticlesPerSecond 897
#define SETMAXPARTICLESPERSECOND_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMAXPARTICLESPERSECOND_MAXPARTICLESPERSECOND num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaxParticlesPerSecond 898
#define GETMAXPARTICLESPERSECOND_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMinStartColor 899
#define SETPARTICLEMINSTARTCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMINSTARTCOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleMinStartColor 900
#define GETPARTICLEMINSTARTCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMaxStartColor 901
#define SETPARTICLEMAXSTARTCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMAXSTARTCOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleMaxStartColor 902
#define GETPARTICLEMAXSTARTCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMinLife 903
#define SETPARTICLEMINLIFE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMINLIFE_MINLIFE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleMinLife 904
#define GETPARTICLEMINLIFE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMaxLife 905
#define SETPARTICLEMAXLIFE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMAXLIFE_MAXLIFE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleMaxLife 906
#define GETPARTICLEMAXLIFE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMaxAngle 907
#define SETPARTICLEMAXANGLE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMAXANGLE_MAXANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleMaxAngle 908
#define GETPARTICLEMAXANGLE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMinStartSize 909
#define SETPARTICLEMINSTARTSIZE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMINSTARTSIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPARTICLEMINSTARTSIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getParticleMinStartSize 910
#define GETPARTICLEMINSTARTSIZE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPARTICLEMINSTARTSIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPARTICLEMINSTARTSIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setParticleMaxStartSize 911
#define SETPARTICLEMAXSTARTSIZE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMAXSTARTSIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPARTICLEMAXSTARTSIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getParticleMaxStartSize 912
#define GETPARTICLEMAXSTARTSIZE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPARTICLEMAXSTARTSIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPARTICLEMAXSTARTSIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setParticleCenter 913
#define SETPARTICLECENTER_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLECENTER_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPARTICLECENTER_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETPARTICLECENTER_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getParticleCenter 914
#define GETPARTICLECENTER_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPARTICLECENTER_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPARTICLECENTER_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETPARTICLECENTER_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setParticleRadius 915
#define SETPARTICLERADIUS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLERADIUS_RADIUS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleRadius 916
#define GETPARTICLERADIUS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleRingThickness 917
#define SETPARTICLERINGTHICKNESS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLERINGTHICKNESS_RINGTHICKNESS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleRingThickness 918
#define GETPARTICLERINGTHICKNESS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleBox 919
#define SETPARTICLEBOX_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEBOX_MIN_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPARTICLEBOX_MIN_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETPARTICLEBOX_MIN_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETPARTICLEBOX_MAX_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define SETPARTICLEBOX_MAX_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define SETPARTICLEBOX_MAX_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_getParticleBox 920
#define GETPARTICLEBOX_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPARTICLEBOX_MIN_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPARTICLEBOX_MIN_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETPARTICLEBOX_MIN_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETPARTICLEBOX_MAX_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETPARTICLEBOX_MAX_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETPARTICLEBOX_MAX_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_setParticleNormal 921
#define SETPARTICLENORMAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLENORMAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPARTICLENORMAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETPARTICLENORMAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getParticleNormal 922
#define GETPARTICLENORMAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPARTICLENORMAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPARTICLENORMAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETPARTICLENORMAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setParticleLength 923
#define SETPARTICLELENGTH_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLELENGTH_P_LEN num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleLength 924
#define GETPARTICLELENGTH_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_useParticleOutlineOnly 925
#define USEPARTICLEOUTLINEONLY_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define USEPARTICLEOUTLINEONLY_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_particleIsUsingOutlineOnly 926
#define PARTICLEISUSINGOUTLINEONLY_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getParticleType 927
#define GETPARTICLETYPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_lightIsCastingShadow 928
#define LIGHTISCASTINGSHADOW_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getLightType 929
#define GETLIGHTTYPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getLightRadius 930
#define GETLIGHTRADIUS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setLightType 931
#define SETLIGHTTYPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTTYPE_LIGHT_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setLightRadius 932
#define SETLIGHTRADIUS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTRADIUS_RADIUS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setLightShadowCast 933
#define SETLIGHTSHADOWCAST_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTSHADOWCAST_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetLightAmbientColor 934
#define SETLIGHTAMBIENTCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTAMBIENTCOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetLightAmbientColor 935
#define GETLIGHTAMBIENTCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetLightAttenuation 936
#define SETLIGHTATTENUATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTATTENUATION_L_CONSTANT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETLIGHTATTENUATION_L_LINEAR num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETLIGHTATTENUATION_L_QUADRATIC num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetLightAttenuation 937
#define GETLIGHTATTENUATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETLIGHTATTENUATION_CONSTANT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETLIGHTATTENUATION_LINEAR num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETLIGHTATTENUATION_QUADRATIC num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetLightDiffuseColor 938
#define SETLIGHTDIFFUSECOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTDIFFUSECOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetLightDiffuseColor 939
#define GETLIGHTDIFFUSECOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetLightFalloff 940
#define SETLIGHTFALLOFF_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTFALLOFF_FALLOFF num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetLightFalloff 941
#define GETLIGHTFALLOFF_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetLightInnerCone 942
#define SETLIGHTINNERCONE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTINNERCONE_ANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetLightInnerCone 943
#define GETLIGHTINNERCONE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetLightOuterCone 944
#define SETLIGHTOUTERCONE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTOUTERCONE_ANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetLightOuterCone 945
#define GETLIGHTOUTERCONE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetLightSpecularColor 946
#define SETLIGHTSPECULARCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTSPECULARCOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetLightSpecularColor 947
#define GETLIGHTSPECULARCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetTerrainPatchAABB 948
#define GETTERRAINPATCHAABB_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTERRAINPATCHAABB_PATCHX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTERRAINPATCHAABB_PATCHZ num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETTERRAINPATCHAABB_MINX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETTERRAINPATCHAABB_MINY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETTERRAINPATCHAABB_MINZ num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETTERRAINPATCHAABB_MAXX num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define GETTERRAINPATCHAABB_MAXY num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define GETTERRAINPATCHAABB_MAXZ num_var[8].nref[0].value[ num_var[8].byref_offset ]
#define FN_GetTerrainPatchLOD 949
#define GETTERRAINPATCHLOD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTERRAINPATCHLOD_PATCHX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTERRAINPATCHLOD_PATCHZ num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetTerrainHeight 950
#define GETTERRAINHEIGHT_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTERRAINHEIGHT_PATCHX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTERRAINHEIGHT_PATCHZ num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetTerrainCenter 951
#define GETTERRAINCENTER_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTERRAINCENTER_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTERRAINCENTER_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETTERRAINCENTER_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetTerrainLODDistance 952
#define SETTERRAINLODDISTANCE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTERRAINLODDISTANCE_LOD num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTERRAINLODDISTANCE_DISTANCE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ScaleTerrainTexture 953
#define SCALETERRAINTEXTURE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SCALETERRAINTEXTURE_SCALE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SCALETERRAINTEXTURE_SCALE2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetTerrainCameraMovementDelta 954
#define SETTERRAINCAMERAMOVEMENTDELTA_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTERRAINCAMERAMOVEMENTDELTA_DELTA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetTerrainCameraRotationDelta 955
#define SETTERRAINCAMERAROTATIONDELTA_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTERRAINCAMERAROTATIONDELTA_DELTA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetTerrainPatchLOD 956
#define SETTERRAINPATCHLOD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTERRAINPATCHLOD_PATCHX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTERRAINPATCHLOD_PATCHZ num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETTERRAINPATCHLOD_LOD num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_createMaterial 957
#define FN_deleteMaterial 958
#define DELETEMATERIAL_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setActorMaterial 959
#define SETACTORMATERIAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORMATERIAL_MATERIAL_NUM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORMATERIAL_MATERIAL_ID num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getActorMaterial 960
#define GETACTORMATERIAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORMATERIAL_MATERIAL_NUM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_copyActorMaterial 961
#define COPYACTORMATERIAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COPYACTORMATERIAL_MATERIAL_NUM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_copyMaterial 962
#define COPYMATERIAL_SMATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialTextureCanvas 963
#define SETMATERIALTEXTURECANVAS_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALTEXTURECANVAS_LEVEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATERIALTEXTURECANVAS_CANVAS_ID num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setMaterialAmbientColor 964
#define SETMATERIALAMBIENTCOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALAMBIENTCOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialAmbientColor 965
#define GETMATERIALAMBIENTCOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialAntiAliasing 966
#define SETMATERIALANTIALIASING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALANTIALIASING_AA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialAntiAliasing 967
#define GETMATERIALANTIALIASING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialBackfaceCulling 968
#define SETMATERIALBACKFACECULLING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALBACKFACECULLING_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialBackfaceCulling 969
#define GETMATERIALBACKFACECULLING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialBlendFactor 970
#define SETMATERIALBLENDFACTOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALBLENDFACTOR_BF num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialBlendFactor 971
#define GETMATERIALBLENDFACTOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialBlendMode 972
#define SETMATERIALBLENDMODE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALBLENDMODE_BLEND_MODE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialBlendMode 973
#define GETMATERIALBLENDMODE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialColorMask 974
#define SETMATERIALCOLORMASK_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALCOLORMASK_COLOR_MASK num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialColorMask 975
#define GETMATERIALCOLORMASK_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialColorMode 976
#define SETMATERIALCOLORMODE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALCOLORMODE_COLOR_MODE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialColorMode 977
#define GETMATERIALCOLORMODE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialDiffuseColor 978
#define SETMATERIALDIFFUSECOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALDIFFUSECOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialDiffuseColor 979
#define GETMATERIALDIFFUSECOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialEmissiveColor 980
#define SETMATERIALEMISSIVECOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALEMISSIVECOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialEmissiveColor 981
#define GETMATERIALEMISSIVECOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialFog 982
#define SETMATERIALFOG_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALFOG_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialFog 983
#define GETMATERIALFOG_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialFrontfaceCulling 984
#define SETMATERIALFRONTFACECULLING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALFRONTFACECULLING_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialFrontfaceCulling 985
#define GETMATERIALFRONTFACECULLING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialGouraudShading 986
#define SETMATERIALGOURAUDSHADING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALGOURAUDSHADING_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_materialIsGouraudShaded 987
#define MATERIALISGOURAUDSHADED_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_materialIsAplhaBlend 988
#define MATERIALISAPLHABLEND_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_materialIsTransparent 989
#define MATERIALISTRANSPARENT_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialLighting 990
#define SETMATERIALLIGHTING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALLIGHTING_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_materialIsLit 991
#define MATERIALISLIT_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialType 992
#define SETMATERIALTYPE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALTYPE_MAT_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialType 993
#define GETMATERIALTYPE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialNormalize 994
#define SETMATERIALNORMALIZE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALNORMALIZE_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_materialIsNormalized 995
#define MATERIALISNORMALIZED_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialPointCloud 996
#define SETMATERIALPOINTCLOUD_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALPOINTCLOUD_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_materialIsPointCloud 997
#define MATERIALISPOINTCLOUD_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialFlag 998
#define SETMATERIALFLAG_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALFLAG_MATERIAL_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATERIALFLAG_F_VALUE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getMaterialFlag 999
#define GETMATERIALFLAG_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMATERIALFLAG_MATERIAL_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setMaterialTexture 1000
#define SETMATERIALTEXTURE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALTEXTURE_LEVEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATERIALTEXTURE_IMG_ID num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setMaterialShininess 1001
#define SETMATERIALSHININESS_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALSHININESS_SHININESS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialShininess 1002
#define GETMATERIALSHININESS_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialSpecularColor 1003
#define SETMATERIALSPECULARCOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALSPECULARCOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialSpecularColor 1004
#define GETMATERIALSPECULARCOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialThickness 1005
#define SETMATERIALTHICKNESS_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALTHICKNESS_THICKNESS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialThickness 1006
#define GETMATERIALTHICKNESS_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialWireframe 1007
#define SETMATERIALWIREFRAME_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALWIREFRAME_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_materialIsWireframe 1008
#define MATERIALISWIREFRAME_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setActorTexture 1009
#define SETACTORTEXTURE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORTEXTURE_LAYER num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORTEXTURE_IMAGE_ID num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getActorMaterialCount 1010
#define GETACTORMATERIALCOUNT_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setActorMaterialFlag 1011
#define SETACTORMATERIALFLAG_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORMATERIALFLAG_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORMATERIALFLAG_FLAG_VALUE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getActorMaterialFlag 1012
#define GETACTORMATERIALFLAG_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORMATERIALFLAG_MATERIAL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORMATERIALFLAG_FLAG num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setActorMaterialType 1013
#define SETACTORMATERIALTYPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORMATERIALTYPE_MATERIAL_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getActorMaterialType 1014
#define GETACTORMATERIALTYPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORMATERIALTYPE_MATERIAL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_MaterialExists 1015
#define MATERIALEXISTS_MATERIAL num_var[0].nref[0].value[ num_var[0].byref_offset ]


#endif // RC_DEFINES_H_INCLUDED
