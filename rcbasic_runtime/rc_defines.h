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
#define FN_SetAntiAliasMode 246
#define SETANTIALIASMODE_AA_MODE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetAntiAliasMode 247
#define FN_ConvertToNormalMap 248
#define CONVERTTONORMALMAP_IMG_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CONVERTTONORMALMAP_AMP num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_InKey 249
#define FN_Key 250
#define KEY_KEY_CODE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_WaitKey 251
#define FN_HideMouse 252
#define FN_ShowMouse 253
#define FN_MouseIsVisible 254
#define FN_GetMouse 255
#define GETMOUSE_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMOUSE_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMOUSE_MB1 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETMOUSE_MB2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETMOUSE_MB3 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_MouseX 256
#define FN_MouseY 257
#define FN_MouseButton 258
#define MOUSEBUTTON_MB num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetMouseWheel 259
#define GETMOUSEWHEEL_X_AXIS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMOUSEWHEEL_Y_AXIS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_MouseWheelX 260
#define FN_MouseWheelY 261
#define FN_GetGlobalMouse 262
#define GETGLOBALMOUSE_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETGLOBALMOUSE_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETGLOBALMOUSE_MB1 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETGLOBALMOUSE_MB2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETGLOBALMOUSE_MB3 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_GlobalMouseX 263
#define FN_GlobalMouseY 264
#define FN_WarpMouse 265
#define WARPMOUSE_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WARPMOUSE_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_WarpMouseGlobal 266
#define WARPMOUSEGLOBAL_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WARPMOUSEGLOBAL_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetMouseZone 267
#define SETMOUSEZONE_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMOUSEZONE_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMOUSEZONE_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETMOUSEZONE_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_ClearMouseZone 268
#define FN_CreateSound 269
#define CREATESOUND_BUFFER num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATESOUND_BUFFER_SIZE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATESOUND_VOL num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_LoadSound 270
#define LOADSOUND_SND_FILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_LoadMusic 271
#define LOADMUSIC_MUSIC_FILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_PlaySound 272
#define PLAYSOUND_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define PLAYSOUND_CHANNEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define PLAYSOUND_LOOPS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_PlaySoundTimed 273
#define PLAYSOUNDTIMED_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define PLAYSOUNDTIMED_CHANNEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define PLAYSOUNDTIMED_LOOPS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define PLAYSOUNDTIMED_MS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_PlayMusic 274
#define PLAYMUSIC_MLOOPS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_PauseSound 275
#define PAUSESOUND_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ResumeSound 276
#define RESUMESOUND_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_PauseMusic 277
#define FN_ResumeMusic 278
#define FN_DeleteSound 279
#define DELETESOUND_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteMusic 280
#define FN_FadeMusicIn 281
#define FADEMUSICIN_FADE_TIME num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FADEMUSICIN_LOOPS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_FadeMusicOut 282
#define FADEMUSICOUT_FADE_TIME num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_MusicExists 283
#define FN_SetMusicVolume 284
#define SETMUSICVOLUME_VOL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetMusicVolume 285
#define FN_SetMusicPosition 286
#define SETMUSICPOSITION_POS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetMusicPosition 287
#define FN_RewindMusic 288
#define FN_SetSoundChannels 289
#define SETSOUNDCHANNELS_MAX_CHANNELS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumSoundChannels 290
#define FN_SoundIsEnabled 291
#define FN_SoundExists 292
#define SOUNDEXISTS_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetChannelVolume 293
#define SETCHANNELVOLUME_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCHANNELVOLUME_VOL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetChannelVolume 294
#define GETCHANNELVOLUME_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSoundVolume 295
#define SETSOUNDVOLUME_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSOUNDVOLUME_VOL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSoundVolume 296
#define GETSOUNDVOLUME_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_StopMusic 297
#define FN_StopSound 298
#define STOPSOUND_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetChannelPanning 299
#define SETCHANNELPANNING_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCHANNELPANNING_LEFT_VALUE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCHANNELPANNING_RIGHT_VALUE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetChannelDistance 300
#define SETCHANNELDISTANCE_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCHANNELDISTANCE_DIST_VALUE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ChannelIsPlaying 301
#define CHANNELISPLAYING_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ChannelIsPaused 302
#define CHANNELISPAUSED_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_QueryAudioSpec 303
#define QUERYAUDIOSPEC_FREQ num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define QUERYAUDIOSPEC_FORMAT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define QUERYAUDIOSPEC_CHANNELS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_MusicIsPlaying 304
#define FN_SetChannelSpacePosition 305
#define SETCHANNELSPACEPOSITION_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCHANNELSPACEPOSITION_ANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCHANNELSPACEPOSITION_DISTANCE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_NumJoysticks 306
#define FN_NumJoyAxes 307
#define NUMJOYAXES_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumJoyButtons 308
#define NUMJOYBUTTONS_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumJoyHats 309
#define NUMJOYHATS_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumJoyTrackBalls 310
#define NUMJOYTRACKBALLS_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_JoyAxis 311
#define JOYAXIS_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define JOYAXIS_JOY_AXIS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_JoyButton 312
#define JOYBUTTON_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define JOYBUTTON_JOY_BUTTON num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_JoyHat 313
#define JOYHAT_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define JOYHAT_JOY_HAT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetJoyTrackBall 314
#define GETJOYTRACKBALL_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOYTRACKBALL_BALL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOYTRACKBALL_DX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETJOYTRACKBALL_DY num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_JoyName$ 315
#define JOYNAME$_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_JoystickIsConnected 316
#define JOYSTICKISCONNECTED_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_JoyRumblePlay 317
#define JOYRUMBLEPLAY_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define JOYRUMBLEPLAY_STRENGTH num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define JOYRUMBLEPLAY_DURATION num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_JoyRumbleStop 318
#define JOYRUMBLESTOP_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_JoystickIsHaptic 319
#define JOYSTICKISHAPTIC_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_LoadFont 320
#define LOADFONT_FNT_FILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define LOADFONT_FONT_SIZE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteFont 321
#define DELETEFONT_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_FontExists 322
#define FONTEXISTS_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetFont 323
#define SETFONT_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DrawText 324
#define DRAWTEXT_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define DRAWTEXT_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWTEXT_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetTextSize 325
#define GETTEXTSIZE_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define GETTEXTSIZE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTEXTSIZE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_TextWidth 326
#define TEXTWIDTH_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_TextHeight 327
#define TEXTHEIGHT_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_TouchPressure 328
#define FN_GetTouch 329
#define GETTOUCH_STATUS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTOUCH_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTOUCH_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETTOUCH_DX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETTOUCH_DY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_GetMultiTouch 330
#define GETMULTITOUCH_STATUS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMULTITOUCH_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMULTITOUCH_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETMULTITOUCH_FINGERS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETMULTITOUCH_DIST num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETMULTITOUCH_THETA num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_GetTouchFinger 331
#define GETTOUCHFINGER_FINGER num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTOUCHFINGER_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTOUCHFINGER_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETTOUCHFINGER_PRESSURE num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_NumFingers 332
#define FN_GetAccel 333
#define GETACCEL_ACCEL_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACCEL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACCEL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACCEL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_AccelName$ 334
#define ACCELNAME$_ACCEL_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumAccels 335
#define FN_GetGyro 336
#define GETGYRO_GYRO_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETGYRO_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETGYRO_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETGYRO_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GyroName$ 337
#define GYRONAME$_GYRO_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumGyros 338
#define FN_CheckSockets 339
#define CHECKSOCKETS_TIMEOUT_MS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TCP_SocketReady 340
#define TCP_SOCKETREADY_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_UDP_SocketReady 341
#define UDP_SOCKETREADY_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TCP_OpenSocket 342
#define TCP_OPENSOCKET_HOST$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define TCP_OPENSOCKET_PORT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TCP_CloseSocket 343
#define TCP_CLOSESOCKET_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TCP_RemoteHost 344
#define TCP_REMOTEHOST_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TCP_RemotePort 345
#define TCP_REMOTEPORT_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TCP_GetData 346
#define TCP_GETDATA_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TCP_GETDATA_NUMBYTES num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define TCP_GETDATA_SDATA$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_TCP_SendData 347
#define TCP_SENDDATA_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TCP_SENDDATA_SDATA$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_TCP_AcceptSocket 348
#define TCP_ACCEPTSOCKET_SERVER num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_UDP_OpenSocket 349
#define UDP_OPENSOCKET_PORT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_UDP_CloseSocket 350
#define UDP_CLOSESOCKET_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_UDP_GetData 351
#define UDP_GETDATA_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define UDP_GETDATA_HOST$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define UDP_GETDATA_PORT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define UDP_GETDATA_SDATA$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_UDP_Length 352
#define FN_UDP_MaxLength 353
#define FN_UDP_RemoteHost$ 354
#define UDP_REMOTEHOST$_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_UDP_RemotePort 355
#define UDP_REMOTEPORT_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_UDP_SendData 356
#define UDP_SENDDATA_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define UDP_SENDDATA_HOST$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define UDP_SENDDATA_PORT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define UDP_SENDDATA_SDATA$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_LoadVideo 357
#define LOADVIDEO_VID$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_PlayVideo 358
#define PLAYVIDEO_VLOOPS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_PauseVideo 359
#define FN_StopVideo 360
#define FN_SetVideoPosition 361
#define SETVIDEOPOSITION_POS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ResumeVideo 362
#define FN_GetVideoPosition 363
#define FN_DeleteVideo 364
#define FN_VideoIsPlaying 365
#define FN_VideoEnd 366
#define FN_GetVideoStats 367
#define GETVIDEOSTATS_VFILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define GETVIDEOSTATS_VLEN num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETVIDEOSTATS_VFPS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETVIDEOSTATS_FRAME_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETVIDEOSTATS_FRAME_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetVideoDrawRect 368
#define SETVIDEODRAWRECT_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETVIDEODRAWRECT_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETVIDEODRAWRECT_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETVIDEODRAWRECT_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetVideoDrawRect 369
#define GETVIDEODRAWRECT_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETVIDEODRAWRECT_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETVIDEODRAWRECT_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETVIDEODRAWRECT_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetVideoSize 370
#define GETVIDEOSIZE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETVIDEOSIZE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_VideoExists 371
#define FN_SetVideoVolume 372
#define SETVIDEOVOLUME_VOL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetVideoVolume 373
#define FN_System 374
#define SYSTEM_CMD$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_OS$ 375
#define FN_Command$ 376
#define COMMAND$_ARG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumCommands 377
#define FN_Env$ 378
#define ENV$_V$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_SetEnv 379
#define SETENV_VAR$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define SETENV_VALUE$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_PrefPath$ 380
#define PREFPATH$_ORG_NAME$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define PREFPATH$_APP_NAME$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_Android_GetExternalStoragePath$ 381
#define FN_Android_GetExternalStorageState 382
#define FN_Android_GetInternalStoragePath$ 383
#define FN_Android_JNI_Message$ 384
#define ANDROID_JNI_MESSAGE$_ARG$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Runtime_Utility_Message$ 385
#define RUNTIME_UTILITY_MESSAGE$_ARG$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_GetDesktopDisplayMode 386
#define GETDESKTOPDISPLAYMODE_INDEX num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETDESKTOPDISPLAYMODE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETDESKTOPDISPLAYMODE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETDESKTOPDISPLAYMODE_FREQ num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetPowerInfo 387
#define GETPOWERINFO_STATUS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPOWERINFO_SECS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPOWERINFO_PCT num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_EvalJS$ 388
#define EVALJS$_JS_CODE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_SystemReturnStdOut$ 389
#define SYSTEMRETURNSTDOUT$_CMD$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_OpenURL 390
#define OPENURL_URL$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_MessageBox 391
#define MESSAGEBOX_TITLE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define MESSAGEBOX_MSG$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_Runtime$ 392
#define FN_NumCPUs 393
#define FN_SystemRam 394
#define FN_GetGPUInfo$ 395
#define FN_DimMatrix 396
#define DIMMATRIX_M_ROWS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DIMMATRIX_M_COLS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_DeleteMatrix 397
#define DELETEMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_AddMatrix 398
#define ADDMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ADDMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ADDMATRIX_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_AugmentMatrix 399
#define AUGMENTMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define AUGMENTMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define AUGMENTMATRIX_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_CopyMatrix 400
#define COPYMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COPYMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_InsertMatrixColumns 401
#define INSERTMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define INSERTMATRIXCOLUMNS_C num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define INSERTMATRIXCOLUMNS_NUM_COLS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_InsertMatrixRows 402
#define INSERTMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define INSERTMATRIXROWS_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define INSERTMATRIXROWS_NUM_ROWS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_MultiplyMatrix 403
#define MULTIPLYMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define MULTIPLYMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define MULTIPLYMATRIX_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_CubeMatrix 404
#define CUBEMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CUBEMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_DeleteMatrixColumns 405
#define DELETEMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DELETEMATRIXCOLUMNS_C num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DELETEMATRIXCOLUMNS_NUM_COLS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_DeleteMatrixRows 406
#define DELETEMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DELETEMATRIXROWS_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DELETEMATRIXROWS_NUM_ROWS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ClearMatrix 407
#define CLEARMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ClearMatrixColumns 408
#define CLEARMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CLEARMATRIXCOLUMNS_C num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CLEARMATRIXCOLUMNS_NUM_COLS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ClearMatrixRows 409
#define CLEARMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CLEARMATRIXROWS_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CLEARMATRIXROWS_NUM_ROWS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_FillMatrix 410
#define FILLMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FILLMATRIX_V num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_FillMatrixColumns 411
#define FILLMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FILLMATRIXCOLUMNS_C num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FILLMATRIXCOLUMNS_NUM_COLS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FILLMATRIXCOLUMNS_V num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_FillMatrixRows 412
#define FILLMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FILLMATRIXROWS_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FILLMATRIXROWS_NUM_ROWS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FILLMATRIXROWS_V num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_CopyMatrixColumns 413
#define COPYMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COPYMATRIXCOLUMNS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COPYMATRIXCOLUMNS_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define COPYMATRIXCOLUMNS_NUM_COLS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_CopyMatrixRows 414
#define COPYMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COPYMATRIXROWS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COPYMATRIXROWS_R num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define COPYMATRIXROWS_NUM_ROWS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetIdentityMatrix 415
#define SETIDENTITYMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETIDENTITYMATRIX_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SolveMatrix 416
#define SOLVEMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SOLVEMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SOLVEMATRIX_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_IsEqualMatrix 417
#define ISEQUALMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ISEQUALMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ISEQUALMATRIX_TOLERANCE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_Determinant 418
#define DETERMINANT_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_AdjointMatrix 419
#define ADJOINTMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ADJOINTMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_InvertMatrix 420
#define INVERTMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define INVERTMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_MatrixFromBuffer 421
#define MATRIXFROMBUFFER_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define MATRIXFROMBUFFER_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define MATRIXFROMBUFFER_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define MATRIXFROMBUFFER_BUFFER num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_BufferFromMatrix 422
#define BUFFERFROMMATRIX_BUFFER num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define BUFFERFROMMATRIX_MA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_RandomizeMatrix 423
#define RANDOMIZEMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define RANDOMIZEMATRIX_VMIN num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define RANDOMIZEMATRIX_VMAX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_MatrixValue 424
#define MATRIXVALUE_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define MATRIXVALUE_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define MATRIXVALUE_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetMatrixValue 425
#define SETMATRIXVALUE_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATRIXVALUE_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATRIXVALUE_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETMATRIXVALUE_V num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_ScalarMatrix 426
#define SCALARMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SCALARMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SCALARMATRIX_S_VALUE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ScalarMatrixColumns 427
#define SCALARMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SCALARMATRIXCOLUMNS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SCALARMATRIXCOLUMNS_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SCALARMATRIXCOLUMNS_NUM_COLS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SCALARMATRIXCOLUMNS_S_VALUE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_ScalarMatrixRows 428
#define SCALARMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SCALARMATRIXROWS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SCALARMATRIXROWS_R num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SCALARMATRIXROWS_NUM_ROWS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SCALARMATRIXROWS_S_VALUE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_SquareMatrix 429
#define SQUAREMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SQUAREMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_CofactorMatrix 430
#define COFACTORMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COFACTORMATRIX_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COFACTORMATRIX_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SubtractMatrix 431
#define SUBTRACTMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SUBTRACTMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SUBTRACTMATRIX_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SwapMatrix 432
#define SWAPMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SWAPMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SwapMatrixColumn 433
#define SWAPMATRIXCOLUMN_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SWAPMATRIXCOLUMN_C1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SWAPMATRIXCOLUMN_C2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SwapMatrixRow 434
#define SWAPMATRIXROW_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SWAPMATRIXROW_R1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SWAPMATRIXROW_R2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_TransposeMatrix 435
#define TRANSPOSEMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TRANSPOSEMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_UnAugmentMatrix 436
#define UNAUGMENTMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define UNAUGMENTMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define UNAUGMENTMATRIX_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ZeroMatrix 437
#define ZEROMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetMatrixSize 438
#define GETMATRIXSIZE_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMATRIXSIZE_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMATRIXSIZE_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_IncrementMatrixRows 439
#define INCREMENTMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define INCREMENTMATRIXROWS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define INCREMENTMATRIXROWS_R num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define INCREMENTMATRIXROWS_NUM_ROWS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define INCREMENTMATRIXROWS_VALUE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_IncrementMatrixColumns 440
#define INCREMENTMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define INCREMENTMATRIXCOLUMNS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define INCREMENTMATRIXCOLUMNS_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define INCREMENTMATRIXCOLUMNS_NUM_COLS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define INCREMENTMATRIXCOLUMNS_VALUE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_JoinMatrixRows 441
#define JOINMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define JOINMATRIXROWS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define JOINMATRIXROWS_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_JoinMatrixColumns 442
#define JOINMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define JOINMATRIXCOLUMNS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define JOINMATRIXCOLUMNS_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ClipMatrix 443
#define CLIPMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CLIPMATRIX_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CLIPMATRIX_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CLIPMATRIX_NUM_ROWS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CLIPMATRIX_NUM_COLS num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CLIPMATRIX_MB num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_SetMatrixTranslation 444
#define SETMATRIXTRANSLATION_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATRIXTRANSLATION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATRIXTRANSLATION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETMATRIXTRANSLATION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetMatrixRotation 445
#define SETMATRIXROTATION_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATRIXROTATION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATRIXROTATION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETMATRIXROTATION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetMatrixScale 446
#define SETMATRIXSCALE_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATRIXSCALE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATRIXSCALE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETMATRIXSCALE_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetMatrixTranslation 447
#define GETMATRIXTRANSLATION_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMATRIXTRANSLATION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMATRIXTRANSLATION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETMATRIXTRANSLATION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetMatrixRotation 448
#define GETMATRIXROTATION_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMATRIXROTATION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMATRIXROTATION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETMATRIXROTATION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetMatrixScale 449
#define GETMATRIXSCALE_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMATRIXSCALE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMATRIXSCALE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETMATRIXSCALE_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetClipboardText$ 450
#define FN_SetClipboardText 451
#define SETCLIPBOARDTEXT_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_HasClipboardText 452
#define FN_ReadInput_Start 453
#define FN_ReadInput_Stop 454
#define FN_ReadInput_GetText$ 455
#define FN_ReadInput_SetText 456
#define READINPUT_SETTEXT_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_ReadInput_ToggleBackspace 457
#define READINPUT_TOGGLEBACKSPACE_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateSprite 458
#define CREATESPRITE_IMG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATESPRITE_FRAME_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATESPRITE_FRAME_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_DeleteSprite 459
#define DELETESPRITE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpritePosition 460
#define SETSPRITEPOSITION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEPOSITION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITEPOSITION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_TranslateSprite 461
#define TRANSLATESPRITE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TRANSLATESPRITE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define TRANSLATESPRITE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetSpritePosition 462
#define GETSPRITEPOSITION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEPOSITION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITEPOSITION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SpriteX 463
#define SPRITEX_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SpriteY 464
#define SPRITEY_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteRotation 465
#define SETSPRITEROTATION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEROTATION_ANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_RotateSprite 466
#define ROTATESPRITE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ROTATESPRITE_ANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteRotation 467
#define GETSPRITEROTATION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteScale 468
#define SETSPRITESCALE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITESCALE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITESCALE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ScaleSprite 469
#define SCALESPRITE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SCALESPRITE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SCALESPRITE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetSpriteScale 470
#define GETSPRITESCALE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITESCALE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITESCALE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetSpriteZ 471
#define SETSPRITEZ_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEZ_Z num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SpriteZ 472
#define SPRITEZ_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetSpriteSize 473
#define GETSPRITESIZE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITESIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITESIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SpriteWidth 474
#define SPRITEWIDTH_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SpriteHeight 475
#define SPRITEHEIGHT_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteVisible 476
#define SETSPRITEVISIBLE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEVISIBLE_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SpriteIsVisible 477
#define SPRITEISVISIBLE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteSolid 478
#define SETSPRITESOLID_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITESOLID_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SpriteIsSolid 479
#define SPRITEISSOLID_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteType 480
#define SETSPRITETYPE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITETYPE_SPRITE_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteType 481
#define GETSPRITETYPE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteSource 482
#define SETSPRITESOURCE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITESOURCE_IMG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteSource 483
#define GETSPRITESOURCE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SpriteExists 484
#define SPRITEEXISTS_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteColorMod 485
#define SETSPRITECOLORMOD_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITECOLORMOD_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetSpriteAlpha 486
#define SETSPRITEALPHA_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEALPHA_ALPHA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteColorMod 487
#define GETSPRITECOLORMOD_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetSpriteAlpha 488
#define GETSPRITEALPHA_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateSpriteAnimation 489
#define CREATESPRITEANIMATION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATESPRITEANIMATION_ANIM_LENGTH num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATESPRITEANIMATION_SPEED num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetSpriteFrame 490
#define SETSPRITEFRAME_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEFRAME_FRAME num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteFrame 491
#define GETSPRITEFRAME_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteAnimationFrame 492
#define SETSPRITEANIMATIONFRAME_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEANIMATIONFRAME_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITEANIMATIONFRAME_ANIM_FRAME num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETSPRITEANIMATIONFRAME_FRAME num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetSpriteAnimationFrame 493
#define GETSPRITEANIMATIONFRAME_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEANIMATIONFRAME_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITEANIMATIONFRAME_ANIM_FRAME num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetSpriteAnimationLength 494
#define SETSPRITEANIMATIONLENGTH_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEANIMATIONLENGTH_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITEANIMATIONLENGTH_ANIM_LENGTH num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetSpriteAnimationLength 495
#define GETSPRITEANIMATIONLENGTH_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEANIMATIONLENGTH_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetSpriteAnimationSpeed 496
#define SETSPRITEANIMATIONSPEED_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEANIMATIONSPEED_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITEANIMATIONSPEED_SPEED num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetSpriteAnimationSpeed 497
#define GETSPRITEANIMATIONSPEED_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEANIMATIONSPEED_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetSpriteAnimation 498
#define SETSPRITEANIMATION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEANIMATION_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITEANIMATION_NUM_LOOPS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetSpriteAnimation 499
#define GETSPRITEANIMATION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetSpriteCurrentAnimationFrame 500
#define GETSPRITECURRENTANIMATIONFRAME_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumSpriteAnimationLoops 501
#define NUMSPRITEANIMATIONLOOPS_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SpriteAnimationIsPlaying 502
#define SPRITEANIMATIONISPLAYING_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteSpriteAnimation 503
#define DELETESPRITEANIMATION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DELETESPRITEANIMATION_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getSpriteCenter 504
#define GETSPRITECENTER_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITECENTER_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITECENTER_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setSpriteLinearVelocity 505
#define SETSPRITELINEARVELOCITY_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITELINEARVELOCITY_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITELINEARVELOCITY_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getSpriteLinearVelocity 506
#define GETSPRITELINEARVELOCITY_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITELINEARVELOCITY_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITELINEARVELOCITY_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setSpriteAngularVelocity 507
#define SETSPRITEANGULARVELOCITY_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEANGULARVELOCITY_AV num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getSpriteAngularVelocity 508
#define GETSPRITEANGULARVELOCITY_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_applySpriteForce 509
#define APPLYSPRITEFORCE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYSPRITEFORCE_FX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYSPRITEFORCE_FY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYSPRITEFORCE_PX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define APPLYSPRITEFORCE_PY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_applySpriteCentralForce 510
#define APPLYSPRITECENTRALFORCE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYSPRITECENTRALFORCE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYSPRITECENTRALFORCE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_applySpriteTorque 511
#define APPLYSPRITETORQUE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYSPRITETORQUE_TORQUE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_applySpriteLinearImpulse 512
#define APPLYSPRITELINEARIMPULSE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYSPRITELINEARIMPULSE_IX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYSPRITELINEARIMPULSE_IY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYSPRITELINEARIMPULSE_PX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define APPLYSPRITELINEARIMPULSE_PY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_applySpriteAngularImpulse 513
#define APPLYSPRITEANGULARIMPULSE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYSPRITEANGULARIMPULSE_IMPULSE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getSpriteMass 514
#define GETSPRITEMASS_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSpriteInertia 515
#define GETSPRITEINERTIA_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSpriteWorldPoint 516
#define GETSPRITEWORLDPOINT_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEWORLDPOINT_LX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITEWORLDPOINT_LY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITEWORLDPOINT_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITEWORLDPOINT_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getSpriteWorldVector 517
#define GETSPRITEWORLDVECTOR_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEWORLDVECTOR_LX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITEWORLDVECTOR_LY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITEWORLDVECTOR_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITEWORLDVECTOR_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getSpriteLocalPoint 518
#define GETSPRITELOCALPOINT_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITELOCALPOINT_WX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITELOCALPOINT_WY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITELOCALPOINT_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITELOCALPOINT_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getSpriteLocalVector 519
#define GETSPRITELOCALVECTOR_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITELOCALVECTOR_WX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITELOCALVECTOR_WY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITELOCALVECTOR_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITELOCALVECTOR_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getSpriteLinearVelocityFromLocalPoint 520
#define GETSPRITELINEARVELOCITYFROMLOCALPOINT_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMLOCALPOINT_PX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMLOCALPOINT_PY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMLOCALPOINT_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMLOCALPOINT_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getSpriteLinearVelocityFromWorldPoint 521
#define GETSPRITELINEARVELOCITYFROMWORLDPOINT_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMWORLDPOINT_WX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMWORLDPOINT_WY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMWORLDPOINT_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMWORLDPOINT_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getSpriteLinearDamping 522
#define GETSPRITELINEARDAMPING_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSpriteLinearDamping 523
#define SETSPRITELINEARDAMPING_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITELINEARDAMPING_LINEARDAMPING num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getSpriteAngularDamping 524
#define GETSPRITEANGULARDAMPING_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSpriteAngularDamping 525
#define SETSPRITEANGULARDAMPING_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEANGULARDAMPING_ANGULARDAMPING num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getSpriteGravityScale 526
#define GETSPRITEGRAVITYSCALE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSpriteGravityScale 527
#define SETSPRITEGRAVITYSCALE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEGRAVITYSCALE_G_SCALE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSpriteBullet 528
#define SETSPRITEBULLET_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEBULLET_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_spriteIsBullet 529
#define SPRITEISBULLET_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSpriteSleepAllowed 530
#define SETSPRITESLEEPALLOWED_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITESLEEPALLOWED_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_spriteSleepAllowed 531
#define SPRITESLEEPALLOWED_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSpriteAwake 532
#define SETSPRITEAWAKE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEAWAKE_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_spriteIsAwake 533
#define SPRITEISAWAKE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSpriteFixedRotation 534
#define SETSPRITEFIXEDROTATION_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEFIXEDROTATION_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_spriteIsFixedRotation 535
#define SPRITEISFIXEDROTATION_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteDensity 536
#define SETSPRITEDENSITY_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEDENSITY_DENSITY num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteDensity 537
#define GETSPRITEDENSITY_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteFriction 538
#define SETSPRITEFRICTION_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEFRICTION_FRICTION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteFriction 539
#define GETSPRITEFRICTION_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteRestitution 540
#define SETSPRITERESTITUTION_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITERESTITUTION_RESTITUTION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteRestitution 541
#define GETSPRITERESTITUTION_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteRestitutionThreshold 542
#define SETSPRITERESTITUTIONTHRESHOLD_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITERESTITUTIONTHRESHOLD_THRESHOLD num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteRestitutionThreshold 543
#define GETSPRITERESTITUTIONTHRESHOLD_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetSpriteAABB 544
#define GETSPRITEAABB_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEAABB_X1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITEAABB_Y1 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITEAABB_X2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITEAABB_Y2 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_SetGravity2D 545
#define SETGRAVITY2D_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETGRAVITY2D_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetGravity2D 546
#define GETGRAVITY2D_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETGRAVITY2D_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetWorld2DTimeStep 547
#define SETWORLD2DTIMESTEP_TS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetWorld2DVelocityIterations 548
#define SETWORLD2DVELOCITYITERATIONS_V num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetWorld2DPositionIterations 549
#define SETWORLD2DPOSITIONITERATIONS_P num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetWorld2DTimeStep 550
#define FN_GetWorld2DVelocityIterations 551
#define FN_GetWorld2DPositionIterations 552
#define FN_SetWorld2DAutoClearForces 553
#define SETWORLD2DAUTOCLEARFORCES_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetWorld2DAutoClearForces 554
#define FN_CastRay2D 555
#define CASTRAY2D_FROM_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CASTRAY2D_FROM_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CASTRAY2D_TO_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CASTRAY2D_TO_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_CastRay2D_All 556
#define CASTRAY2D_ALL_FROM_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CASTRAY2D_ALL_FROM_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CASTRAY2D_ALL_TO_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CASTRAY2D_ALL_TO_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetRayHit2D 557
#define GETRAYHIT2D_INDEX num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETRAYHIT2D_SPR_ID num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETRAYHIT2D_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETRAYHIT2D_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETRAYHIT2D_NORMAL_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETRAYHIT2D_NORMAL_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_SetSpriteCollisionShape 558
#define SETSPRITECOLLISIONSHAPE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITECOLLISIONSHAPE_SHAPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteCollisionShape 559
#define GETSPRITECOLLISIONSHAPE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteRadius 560
#define SETSPRITERADIUS_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITERADIUS_RADIUS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteRadius 561
#define GETSPRITERADIUS_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteBox 562
#define SETSPRITEBOX_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEBOX_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITEBOX_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetSpriteBoxSize 563
#define GETSPRITEBOXSIZE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEBOXSIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITEBOXSIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetSpriteChain 564
#define SETSPRITECHAIN_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITECHAIN_VX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITECHAIN_VY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETSPRITECHAIN_V_COUNT num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETSPRITECHAIN_PREV_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define SETSPRITECHAIN_PREV_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define SETSPRITECHAIN_NEXT_X num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define SETSPRITECHAIN_NEXT_Y num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define FN_SetSpriteChainLoop 565
#define SETSPRITECHAINLOOP_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITECHAINLOOP_VX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITECHAINLOOP_VY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETSPRITECHAINLOOP_V_COUNT num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetSpritePolygon 566
#define SETSPRITEPOLYGON_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEPOLYGON_VX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITEPOLYGON_VY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETSPRITEPOLYGON_V_COUNT num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_createDistanceJoint 567
#define CREATEDISTANCEJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEDISTANCEJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEDISTANCEJOINT_AX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEDISTANCEJOINT_AY num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEDISTANCEJOINT_BX num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CREATEDISTANCEJOINT_BY num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define CREATEDISTANCEJOINT_COLLIDE_CONNECT num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_createFrictionJoint 568
#define CREATEFRICTIONJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEFRICTIONJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEFRICTIONJOINT_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEFRICTIONJOINT_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEFRICTIONJOINT_COLLIDE_CONNECT num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_createGearJoint 569
#define CREATEGEARJOINT_JOINTA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEGEARJOINT_JOINTB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEGEARJOINT_G_RATIO num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEGEARJOINT_COLLIDE_CONNECT num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_createMotorJoint 570
#define CREATEMOTORJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEMOTORJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEMOTORJOINT_COLLIDE_CONNECT num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_createPrismaticJoint 571
#define CREATEPRISMATICJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEPRISMATICJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEPRISMATICJOINT_AX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEPRISMATICJOINT_AY num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEPRISMATICJOINT_AXISX num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CREATEPRISMATICJOINT_AXISY num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define CREATEPRISMATICJOINT_COLLIDE_CONNECT num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_createPulleyJoint 572
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
#define FN_createRevoluteJoint 573
#define CREATEREVOLUTEJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEREVOLUTEJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEREVOLUTEJOINT_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEREVOLUTEJOINT_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEREVOLUTEJOINT_COLLIDE_CONNECT num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_createWeldJoint 574
#define CREATEWELDJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEWELDJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEWELDJOINT_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEWELDJOINT_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEWELDJOINT_COLLIDE_CONNECT num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_createWheelJoint 575
#define CREATEWHEELJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEWHEELJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEWHEELJOINT_AX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEWHEELJOINT_AY num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEWHEELJOINT_AXISX num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CREATEWHEELJOINT_AXISY num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define CREATEWHEELJOINT_COLLIDE_CONNECT num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_getJointWorldAnchorA 576
#define GETJOINTWORLDANCHORA_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTWORLDANCHORA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTWORLDANCHORA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointWorldAnchorB 577
#define GETJOINTWORLDANCHORB_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTWORLDANCHORB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTWORLDANCHORB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointReactionForce 578
#define GETJOINTREACTIONFORCE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTREACTIONFORCE_INV_DT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTREACTIONFORCE_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETJOINTREACTIONFORCE_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getJointReactionTorque 579
#define GETJOINTREACTIONTORQUE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTREACTIONTORQUE_INV_DT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointLocalAnchorA 580
#define GETJOINTLOCALANCHORA_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTLOCALANCHORA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTLOCALANCHORA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointLocalAnchorB 581
#define GETJOINTLOCALANCHORB_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTLOCALANCHORB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTLOCALANCHORB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setJointLength 582
#define SETJOINTLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTLENGTH_JLEN num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointLength 583
#define GETJOINTLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointMinLength 584
#define SETJOINTMINLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMINLENGTH_JLEN num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMinLength 585
#define GETJOINTMINLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointMaxLength 586
#define SETJOINTMAXLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMAXLENGTH_JLEN num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMaxLength 587
#define GETJOINTMAXLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointCurrentLength 588
#define GETJOINTCURRENTLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointStiffness 589
#define SETJOINTSTIFFNESS_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTSTIFFNESS_STIFFNESS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointStiffness 590
#define GETJOINTSTIFFNESS_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointDamping 591
#define SETJOINTDAMPING_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTDAMPING_DAMPING num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointDamping 592
#define GETJOINTDAMPING_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointMaxForce 593
#define SETJOINTMAXFORCE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMAXFORCE_FORCE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMaxForce 594
#define GETJOINTMAXFORCE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointMaxTorque 595
#define SETJOINTMAXTORQUE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMAXTORQUE_TORQUE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMaxTorque 596
#define GETJOINTMAXTORQUE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointCorrectionFactor 597
#define SETJOINTCORRECTIONFACTOR_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTCORRECTIONFACTOR_FACTOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointCorrectionFactor 598
#define GETJOINTCORRECTIONFACTOR_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointRatio 599
#define SETJOINTRATIO_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTRATIO_J_RATIO num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointRatio 600
#define GETJOINTRATIO_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointLinearOffset 601
#define SETJOINTLINEAROFFSET_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTLINEAROFFSET_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETJOINTLINEAROFFSET_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointLinearOffset 602
#define GETJOINTLINEAROFFSET_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTLINEAROFFSET_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTLINEAROFFSET_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setJointAngularOffset 603
#define SETJOINTANGULAROFFSET_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTANGULAROFFSET_ANGLEOFFSET num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointAngularOffset 604
#define GETJOINTANGULAROFFSET_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointLocalAxisA 605
#define GETJOINTLOCALAXISA_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTLOCALAXISA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTLOCALAXISA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointReferenceAngle 606
#define GETJOINTREFERENCEANGLE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointTranslation 607
#define GETJOINTTRANSLATION_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointSpeed 608
#define GETJOINTSPEED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_jointIsLimitEnabled 609
#define JOINTISLIMITENABLED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_enableJointLimit 610
#define ENABLEJOINTLIMIT_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ENABLEJOINTLIMIT_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointLowerLimit 611
#define GETJOINTLOWERLIMIT_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointUpperLimit 612
#define GETJOINTUPPERLIMIT_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointLimits 613
#define SETJOINTLIMITS_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTLIMITS_LOWER_LIMIT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETJOINTLIMITS_UPPER_LIMIT num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_jointMotorIsEnabled 614
#define JOINTMOTORISENABLED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_enableJointMotor 615
#define ENABLEJOINTMOTOR_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ENABLEJOINTMOTOR_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setJointMotorSpeed 616
#define SETJOINTMOTORSPEED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMOTORSPEED_SPEED num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMotorSpeed 617
#define GETJOINTMOTORSPEED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointMaxMotorForce 618
#define SETJOINTMAXMOTORFORCE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMAXMOTORFORCE_FORCE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMaxMotorForce 619
#define GETJOINTMAXMOTORFORCE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointMotorForce 620
#define GETJOINTMOTORFORCE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTMOTORFORCE_INV_DT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setJointMaxMotorTorque 621
#define SETJOINTMAXMOTORTORQUE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMAXMOTORTORQUE_TORQUE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMaxMotorTorque 622
#define GETJOINTMAXMOTORTORQUE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointMotorTorque 623
#define GETJOINTMOTORTORQUE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTMOTORTORQUE_INV_DT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointGroundAnchorA 624
#define GETJOINTGROUNDANCHORA_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTGROUNDANCHORA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTGROUNDANCHORA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointGroundAnchorB 625
#define GETJOINTGROUNDANCHORB_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTGROUNDANCHORB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTGROUNDANCHORB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointLengthA 626
#define GETJOINTLENGTHA_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointLengthB 627
#define GETJOINTLENGTHB_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointCurrentLengthA 628
#define GETJOINTCURRENTLENGTHA_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointCurrentLengthB 629
#define GETJOINTCURRENTLENGTHB_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointOrigin 630
#define SETJOINTORIGIN_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTORIGIN_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETJOINTORIGIN_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointAngle 631
#define GETJOINTANGLE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointLinearSpeed 632
#define GETJOINTLINEARSPEED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointAngularSpeed 633
#define GETJOINTANGULARSPEED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteJoint 634
#define DELETEJOINT_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_JointExists 635
#define JOINTEXISTS_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateTileSet 636
#define CREATETILESET_IMG_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATETILESET_TILE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATETILESET_TILE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetTileAnimationLength 637
#define SETTILEANIMATIONLENGTH_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTILEANIMATIONLENGTH_BASE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTILEANIMATIONLENGTH_NUM_FRAMES num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetTileAnimationLength 638
#define GETTILEANIMATIONLENGTH_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTILEANIMATIONLENGTH_BASE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetTileAnimationFrame 639
#define SETTILEANIMATIONFRAME_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTILEANIMATIONFRAME_BASE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTILEANIMATIONFRAME_ANIM_FRAME num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETTILEANIMATIONFRAME_TILE_FRAME num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetTileAnimationFrame 640
#define GETTILEANIMATIONFRAME_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTILEANIMATIONFRAME_BASE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTILEANIMATIONFRAME_ANIM_FRAME num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetTileAnimationSpeed 641
#define SETTILEANIMATIONSPEED_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTILEANIMATIONSPEED_BASE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTILEANIMATIONSPEED_SPEED num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetTileAnimationSpeed 642
#define GETTILEANIMATIONSPEED_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTILEANIMATIONSPEED_BASE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_CreateTileMap 643
#define CREATETILEMAP_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATETILEMAP_WIDTHINTILES num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATETILEMAP_HEIGHTINTILES num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetTileMapSize 644
#define SETTILEMAPSIZE_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTILEMAPSIZE_WIDTHINTILES num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTILEMAPSIZE_HEIGHTINTILES num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetTileMapSize 645
#define GETTILEMAPSIZE_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTILEMAPSIZE_WIDTHINTILES num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTILEMAPSIZE_HEIGHTINTILES num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetTile 646
#define SETTILE_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTILE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTILE_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETTILE_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetTile 647
#define GETTILE_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTILE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTILE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_FillTile 648
#define FILLTILE_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FILLTILE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FILLTILE_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FILLTILE_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FILLTILE_WIDTHINTILES num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FILLTILE_HEIGHTINTILES num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_DrawTileMap 649
#define DRAWTILEMAP_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWTILEMAP_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWTILEMAP_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWTILEMAP_W num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWTILEMAP_H num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define DRAWTILEMAP_OFFSET_X num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define DRAWTILEMAP_OFFSET_Y num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_DeleteTileSet 650
#define DELETETILESET_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteTileMap 651
#define DELETETILEMAP_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_LoadMesh 652
#define LOADMESH_MESH_FILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_DeleteMesh 653
#define DELETEMESH_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateMesh 654
#define FN_AddMeshBuffer 655
#define ADDMESHBUFFER_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ADDMESHBUFFER_VERTEX_COUNT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ADDMESHBUFFER_VERTEX_DATA num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define ADDMESHBUFFER_NORMAL_DATA num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define ADDMESHBUFFER_UV_DATA num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define ADDMESHBUFFER_INDEX_COUNT num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define ADDMESHBUFFER_INDEX_DATA num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_LoadMeshFromArchive 656
#define LOADMESHFROMARCHIVE_ARCHIVE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define LOADMESHFROMARCHIVE_MESH_FILE$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_CreatePlaneMesh 657
#define CREATEPLANEMESH_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEPLANEMESH_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEPLANEMESH_TILECOUNT_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEPLANEMESH_TILECOUNT_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEPLANEMESH_TXREPEAT_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CREATEPLANEMESH_TXREPEAT_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_LoadAN8 658
#define LOADAN8_AN8_FILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_LoadMeshFromAN8 659
#define LOADMESHFROMAN8_AN8_PROJECT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define LOADMESHFROMAN8_AN8_SCENE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_GetNumAN8Scenes 660
#define GETNUMAN8SCENES_AN8_PROJECT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetAN8SceneName$ 661
#define GETAN8SCENENAME$_AN8_PROJECT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETAN8SCENENAME$_SCENE_NUM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_CreateConeMesh 662
#define CREATECONEMESH_RADIUS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATECONEMESH_CONE_LENGTH num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATECONEMESH_TESSELATION num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATECONEMESH_TOP_COLOR num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATECONEMESH_BOTTOM_COLOR num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_CreateCylinderMesh 663
#define CREATECYLINDERMESH_RADIUS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATECYLINDERMESH_CYLINDER_LENGTH num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATECYLINDERMESH_TESSELATION num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATECYLINDERMESH_COLOR num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATECYLINDERMESH_CLOSE_TOP num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_CreateVolumeLightMesh 664
#define CREATEVOLUMELIGHTMESH_U num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEVOLUMELIGHTMESH_V num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEVOLUMELIGHTMESH_FOOT_COLOR num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEVOLUMELIGHTMESH_TAIL_COLOR num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEVOLUMELIGHTMESH_LP_DISTANCE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CREATEVOLUMELIGHTMESH_DIM_X num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define CREATEVOLUMELIGHTMESH_DIM_Y num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define CREATEVOLUMELIGHTMESH_DIM_Z num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define FN_DeleteAN8 665
#define DELETEAN8_AN8_PROJECT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateAnimatedActor 666
#define CREATEANIMATEDACTOR_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateOctreeActor 667
#define CREATEOCTREEACTOR_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateCubeActor 668
#define CREATECUBEACTOR_CUBE_SIZE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateSphereActor 669
#define CREATESPHEREACTOR_RADIUS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateWaterActor 670
#define CREATEWATERACTOR_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEWATERACTOR_WAVEHEIGHT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEWATERACTOR_WAVESPEED num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEWATERACTOR_WAVELENGTH num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_CreateLightActor 671
#define FN_CreateBillboardActor 672
#define FN_CreateTerrainActor 673
#define CREATETERRAINACTOR_HMAP_FILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_CreateParticleActor 674
#define CREATEPARTICLEACTOR_PARTICLE_TYPE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteActor 675
#define DELETEACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetActorTransform 676
#define GETACTORTRANSFORM_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORTRANSFORM_MATRIX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetActorPosition 677
#define SETACTORPOSITION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORPOSITION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORPOSITION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORPOSITION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_TranslateActorLocal 678
#define TRANSLATEACTORLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TRANSLATEACTORLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define TRANSLATEACTORLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define TRANSLATEACTORLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_TranslateActorWorld 679
#define TRANSLATEACTORWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TRANSLATEACTORWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define TRANSLATEACTORWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define TRANSLATEACTORWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetActorPosition 680
#define GETACTORPOSITION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORPOSITION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORPOSITION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORPOSITION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetActorScale 681
#define SETACTORSCALE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORSCALE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORSCALE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORSCALE_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_ScaleActor 682
#define SCALEACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SCALEACTOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SCALEACTOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SCALEACTOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetActorScale 683
#define GETACTORSCALE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORSCALE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORSCALE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORSCALE_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetActorRotation 684
#define SETACTORROTATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORROTATION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORROTATION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORROTATION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_RotateActor 685
#define ROTATEACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ROTATEACTOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ROTATEACTOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define ROTATEACTOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetActorRotation 686
#define GETACTORROTATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORROTATION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORROTATION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORROTATION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetActorVisible 687
#define SETACTORVISIBLE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORVISIBLE_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ActorIsVisible 688
#define ACTORISVISIBLE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetActorAutoCulling 689
#define SETACTORAUTOCULLING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORAUTOCULLING_CULL_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetActorAutoCulling 690
#define GETACTORAUTOCULLING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_AddActorShadow 691
#define ADDACTORSHADOW_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_RemoveActorShadow 692
#define REMOVEACTORSHADOW_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ActorExists 693
#define ACTOREXISTS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateProjectorActor 694
#define FN_CreateActorAnimation 695
#define CREATEACTORANIMATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEACTORANIMATION_START_FRAME num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEACTORANIMATION_END_FRAME num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEACTORANIMATION_SPEED num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetActorAnimation 696
#define SETACTORANIMATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORANIMATION_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORANIMATION_NUM_LOOPS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetActorAnimationSpeed 697
#define SETACTORANIMATIONSPEED_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORANIMATIONSPEED_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORANIMATIONSPEED_SPEED num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetActorAnimationFrames 698
#define SETACTORANIMATIONFRAMES_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORANIMATIONFRAMES_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORANIMATIONFRAMES_START_FRAME num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORANIMATIONFRAMES_END_FRAME num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetActorCurrentAnimation 699
#define GETACTORCURRENTANIMATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetActorAnimationSpeed 700
#define GETACTORANIMATIONSPEED_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORANIMATIONSPEED_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetActorAnimationStartFrame 701
#define GETACTORANIMATIONSTARTFRAME_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORANIMATIONSTARTFRAME_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetActorAnimationEndFrame 702
#define GETACTORANIMATIONENDFRAME_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORANIMATIONENDFRAME_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetActorFrame 703
#define SETACTORFRAME_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORFRAME_FRAME num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetActorFrame 704
#define GETACTORFRAME_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ActorAnimationIsPlaying 705
#define ACTORANIMATIONISPLAYING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumActorAnimationLoops 706
#define NUMACTORANIMATIONLOOPS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetActorMD2Animation 707
#define SETACTORMD2ANIMATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORMD2ANIMATION_ANIM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORMD2ANIMATION_NUM_LOOPS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetActorMD2AnimationByName 708
#define SETACTORMD2ANIMATIONBYNAME_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORMD2ANIMATIONBYNAME_ANIM_NAME$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define SETACTORMD2ANIMATIONBYNAME_NUM_LOOPS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_DeleteActorAnimation 709
#define DELETEACTORANIMATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DELETEACTORANIMATION_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetGravity3D 710
#define SETGRAVITY3D_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETGRAVITY3D_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETGRAVITY3D_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetGravity3D 711
#define GETGRAVITY3D_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETGRAVITY3D_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETGRAVITY3D_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetActorCollisionShape 712
#define SETACTORCOLLISIONSHAPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORCOLLISIONSHAPE_SHAPE_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORCOLLISIONSHAPE_MASS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetActorCollisionShape 713
#define GETACTORCOLLISIONSHAPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetActorSolid 714
#define SETACTORSOLID_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORSOLID_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ActorIsSolid 715
#define ACTORISSOLID_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetActorCollision 716
#define GETACTORCOLLISION_ACTOR1 num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORCOLLISION_ACTOR2 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetActorGravity 717
#define SETACTORGRAVITY_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORGRAVITY_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORGRAVITY_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORGRAVITY_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetActorGravity 718
#define GETACTORGRAVITY_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORGRAVITY_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORGRAVITY_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORGRAVITY_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorDamping 719
#define SETACTORDAMPING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORDAMPING_LIN_DAMPING num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORDAMPING_ANG_DAMPING num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getActorLinearDamping 720
#define GETACTORLINEARDAMPING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getActorAngularDamping 721
#define GETACTORANGULARDAMPING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getActorLinearSleepThreshold 722
#define GETACTORLINEARSLEEPTHRESHOLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getActorAngularSleepThreshold 723
#define GETACTORANGULARSLEEPTHRESHOLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_applyActorDamping 724
#define APPLYACTORDAMPING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORDAMPING_TIMESTEP num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setActorMassProperties 725
#define SETACTORMASSPROPERTIES_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORMASSPROPERTIES_MASS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORMASSPROPERTIES_INERTIA_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORMASSPROPERTIES_INERTIA_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETACTORMASSPROPERTIES_INERTIA_Z num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getActorLinearFactor 726
#define GETACTORLINEARFACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORLINEARFACTOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORLINEARFACTOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORLINEARFACTOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorLinearFactor 727
#define SETACTORLINEARFACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORLINEARFACTOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORLINEARFACTOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORLINEARFACTOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorInverseMass 728
#define GETACTORINVERSEMASS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_integrateActorVelocities 729
#define INTEGRATEACTORVELOCITIES_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define INTEGRATEACTORVELOCITIES_V_STEP num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_applyActorCentralForceLocal 730
#define APPLYACTORCENTRALFORCELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORCENTRALFORCELOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORCENTRALFORCELOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORCENTRALFORCELOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorCentralForceWorld 731
#define APPLYACTORCENTRALFORCEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORCENTRALFORCEWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORCENTRALFORCEWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORCENTRALFORCEWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorTotalForce 732
#define GETACTORTOTALFORCE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORTOTALFORCE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORTOTALFORCE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORTOTALFORCE_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorTotalTorque 733
#define GETACTORTOTALTORQUE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORTOTALTORQUE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORTOTALTORQUE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORTOTALTORQUE_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorInverseInertiaDiagLocal 734
#define GETACTORINVERSEINERTIADIAGLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORINVERSEINERTIADIAGLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORINVERSEINERTIADIAGLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORINVERSEINERTIADIAGLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorInverseInertiaDiagLocal 735
#define SETACTORINVERSEINERTIADIAGLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORINVERSEINERTIADIAGLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORINVERSEINERTIADIAGLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORINVERSEINERTIADIAGLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorSleepThresholds 736
#define SETACTORSLEEPTHRESHOLDS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORSLEEPTHRESHOLDS_LINEAR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORSLEEPTHRESHOLDS_ANGULAR num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_applyActorTorqueLocal 737
#define APPLYACTORTORQUELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORTORQUELOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORTORQUELOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORTORQUELOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorTorqueWorld 738
#define APPLYACTORTORQUEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORTORQUEWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORTORQUEWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORTORQUEWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorForceLocal 739
#define APPLYACTORFORCELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORFORCELOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORFORCELOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORFORCELOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define APPLYACTORFORCELOCAL_REL_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define APPLYACTORFORCELOCAL_REL_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define APPLYACTORFORCELOCAL_REL_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_applyActorForceWorld 740
#define APPLYACTORFORCEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORFORCEWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORFORCEWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORFORCEWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define APPLYACTORFORCEWORLD_REL_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define APPLYACTORFORCEWORLD_REL_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define APPLYACTORFORCEWORLD_REL_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_applyActorCentralImpulseLocal 741
#define APPLYACTORCENTRALIMPULSELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORCENTRALIMPULSELOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORCENTRALIMPULSELOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORCENTRALIMPULSELOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorCentralImpulseWorld 742
#define APPLYACTORCENTRALIMPULSEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORCENTRALIMPULSEWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORCENTRALIMPULSEWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORCENTRALIMPULSEWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorTorqueImpulseLocal 743
#define APPLYACTORTORQUEIMPULSELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORTORQUEIMPULSELOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORTORQUEIMPULSELOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORTORQUEIMPULSELOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorTorqueImpulseWorld 744
#define APPLYACTORTORQUEIMPULSEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORTORQUEIMPULSEWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORTORQUEIMPULSEWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORTORQUEIMPULSEWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorImpulseLocal 745
#define APPLYACTORIMPULSELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORIMPULSELOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORIMPULSELOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORIMPULSELOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define APPLYACTORIMPULSELOCAL_REL_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define APPLYACTORIMPULSELOCAL_REL_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define APPLYACTORIMPULSELOCAL_REL_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_applyActorImpulseWorld 746
#define APPLYACTORIMPULSEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORIMPULSEWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORIMPULSEWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORIMPULSEWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define APPLYACTORIMPULSEWORLD_REL_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define APPLYACTORIMPULSEWORLD_REL_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define APPLYACTORIMPULSEWORLD_REL_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_clearActorForces 747
#define CLEARACTORFORCES_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_updateActorInertiaTensor 748
#define UPDATEACTORINERTIATENSOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getActorCenter 749
#define GETACTORCENTER_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORCENTER_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORCENTER_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORCENTER_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorRotationQ 750
#define GETACTORROTATIONQ_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORROTATIONQ_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORROTATIONQ_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORROTATIONQ_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETACTORROTATIONQ_W num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getActorLinearVelocityWorld 751
#define GETACTORLINEARVELOCITYWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORLINEARVELOCITYWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORLINEARVELOCITYWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORLINEARVELOCITYWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorAngularVelocityWorld 752
#define GETACTORANGULARVELOCITYWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORANGULARVELOCITYWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORANGULARVELOCITYWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORANGULARVELOCITYWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorLinearVelocityLocal 753
#define SETACTORLINEARVELOCITYLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORLINEARVELOCITYLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORLINEARVELOCITYLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORLINEARVELOCITYLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorLinearVelocityWorld 754
#define SETACTORLINEARVELOCITYWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORLINEARVELOCITYWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORLINEARVELOCITYWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORLINEARVELOCITYWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorAngularVelocityLocal 755
#define SETACTORANGULARVELOCITYLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORANGULARVELOCITYLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORANGULARVELOCITYLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORANGULARVELOCITYLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorAngularVelocityWorld 756
#define SETACTORANGULARVELOCITYWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORANGULARVELOCITYWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORANGULARVELOCITYWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORANGULARVELOCITYWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorVelocityInLocalPoint 757
#define GETACTORVELOCITYINLOCALPOINT_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORVELOCITYINLOCALPOINT_REL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORVELOCITYINLOCALPOINT_REL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORVELOCITYINLOCALPOINT_REL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETACTORVELOCITYINLOCALPOINT_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETACTORVELOCITYINLOCALPOINT_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETACTORVELOCITYINLOCALPOINT_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_getActorLinearVelocityLocal 758
#define GETACTORLINEARVELOCITYLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORLINEARVELOCITYLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORLINEARVELOCITYLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORLINEARVELOCITYLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorAngularVelocityLocal 759
#define GETACTORANGULARVELOCITYLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORANGULARVELOCITYLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORANGULARVELOCITYLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORANGULARVELOCITYLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorAABB 760
#define GETACTORAABB_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORAABB_MIN_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORAABB_MIN_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORAABB_MIN_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETACTORAABB_MAX_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETACTORAABB_MAX_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETACTORAABB_MAX_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_computeActorImpulseDenominator 761
#define COMPUTEACTORIMPULSEDENOMINATOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_POS_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_POS_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_POS_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_NORMAL_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_NORMAL_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_NORMAL_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_computeActorAngularImpulseDenominator 762
#define COMPUTEACTORANGULARIMPULSEDENOMINATOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COMPUTEACTORANGULARIMPULSEDENOMINATOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COMPUTEACTORANGULARIMPULSEDENOMINATOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define COMPUTEACTORANGULARIMPULSEDENOMINATOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorAngularFactor 763
#define SETACTORANGULARFACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORANGULARFACTOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORANGULARFACTOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORANGULARFACTOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorAngularFactor 764
#define GETACTORANGULARFACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORANGULARFACTOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORANGULARFACTOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORANGULARFACTOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_computeActorGyroImpulseLocal 765
#define COMPUTEACTORGYROIMPULSELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COMPUTEACTORGYROIMPULSELOCAL_DT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COMPUTEACTORGYROIMPULSELOCAL_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define COMPUTEACTORGYROIMPULSELOCAL_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define COMPUTEACTORGYROIMPULSELOCAL_Z num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_computeActorGyroImpulseWorld 766
#define COMPUTEACTORGYROIMPULSEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COMPUTEACTORGYROIMPULSEWORLD_DT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COMPUTEACTORGYROIMPULSEWORLD_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define COMPUTEACTORGYROIMPULSEWORLD_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define COMPUTEACTORGYROIMPULSEWORLD_Z num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getActorLocalInertia 767
#define GETACTORLOCALINERTIA_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORLOCALINERTIA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORLOCALINERTIA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORLOCALINERTIA_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetActorSleepState 768
#define SETACTORSLEEPSTATE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORSLEEPSTATE_STATE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_CastRay3D 769
#define CASTRAY3D_FROM_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CASTRAY3D_FROM_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CASTRAY3D_FROM_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CASTRAY3D_TO_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CASTRAY3D_TO_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CASTRAY3D_TO_Z num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_CastRay3D_All 770
#define CASTRAY3D_ALL_FROM_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CASTRAY3D_ALL_FROM_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CASTRAY3D_ALL_FROM_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CASTRAY3D_ALL_TO_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CASTRAY3D_ALL_TO_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CASTRAY3D_ALL_TO_Z num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_GetRayHit3D 771
#define GETRAYHIT3D_INDEX num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETRAYHIT3D_ACTOR_ID num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETRAYHIT3D_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETRAYHIT3D_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETRAYHIT3D_Z num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETRAYHIT3D_NORMAL_X num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETRAYHIT3D_NORMAL_Y num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define GETRAYHIT3D_NORMAL_Z num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define FN_createPointConstraint 772
#define CREATEPOINTCONSTRAINT_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEPOINTCONSTRAINT_PXA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEPOINTCONSTRAINT_PYA num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEPOINTCONSTRAINT_PZA num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_createPointConstraintEx 773
#define CREATEPOINTCONSTRAINTEX_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_ACTORB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PXA num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PYA num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PZA num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PXB num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PYB num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PZB num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define FN_setPointPivotA 774
#define SETPOINTPIVOTA_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPOINTPIVOTA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPOINTPIVOTA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETPOINTPIVOTA_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setPointPivotB 775
#define SETPOINTPIVOTB_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPOINTPIVOTB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPOINTPIVOTB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETPOINTPIVOTB_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_createHingeConstraint 776
#define CREATEHINGECONSTRAINT_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEHINGECONSTRAINT_FRAMEA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEHINGECONSTRAINT_USEREFERENCEFRAMEA num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_createHingeConstraintEx 777
#define CREATEHINGECONSTRAINTEX_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEHINGECONSTRAINTEX_ACTORB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEHINGECONSTRAINTEX_FRAMEA num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEHINGECONSTRAINTEX_FRAMEB num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEHINGECONSTRAINTEX_USEREFERENCEFRAMEA num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_createSlideConstraint 778
#define CREATESLIDECONSTRAINT_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATESLIDECONSTRAINT_FRAMEINB_MATRIX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATESLIDECONSTRAINT_USELINEARREFERENCEFRAMEA num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_createSlideConstraintEx 779
#define CREATESLIDECONSTRAINTEX_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATESLIDECONSTRAINTEX_ACTORB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATESLIDECONSTRAINTEX_FRAMEINA_MATRIX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATESLIDECONSTRAINTEX_FRAMEINB_MATRIX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATESLIDECONSTRAINTEX_USELINEARREFERENCEFRAMEA num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_createConeConstraint 780
#define CREATECONECONSTRAINT_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATECONECONSTRAINT_RBAFRAME_MATRIX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_createConeConstraintEx 781
#define CREATECONECONSTRAINTEX_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATECONECONSTRAINTEX_ACTORB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATECONECONSTRAINTEX_RBAFRAME_MATRIX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATECONECONSTRAINTEX_RBBFRAME_MATRIX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_deleteConstraint 782
#define DELETECONSTRAINT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConstraintFrameOffsetA 783
#define GETCONSTRAINTFRAMEOFFSETA_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_RX num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_RY num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_RZ num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_getConstraintFrameOffsetB 784
#define GETCONSTRAINTFRAMEOFFSETB_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_RX num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_RY num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_RZ num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_useConstraintFrameOffset 785
#define USECONSTRAINTFRAMEOFFSET_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define USECONSTRAINTFRAMEOFFSET_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getHingeAngle 786
#define GETHINGEANGLE_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getHingeAngleEx 787
#define GETHINGEANGLEEX_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETHINGEANGLEEX_T_MATRIXA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETHINGEANGLEEX_T_MATRIXB num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getConstraintBreakingImpulseThreshold 788
#define GETCONSTRAINTBREAKINGIMPULSETHRESHOLD_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConstraintAFrame 789
#define GETCONSTRAINTAFRAME_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCONSTRAINTAFRAME_MA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getConstraintBFrame 790
#define GETCONSTRAINTBFRAME_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCONSTRAINTBFRAME_MA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setHingeAxis 791
#define SETHINGEAXIS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETHINGEAXIS_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETHINGEAXIS_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETHINGEAXIS_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setConstraintBreakingImpulseThreshold 792
#define SETCONSTRAINTBREAKINGIMPULSETHRESHOLD_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONSTRAINTBREAKINGIMPULSETHRESHOLD_THRESHOLD num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setConstraintFrames 793
#define SETCONSTRAINTFRAMES_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONSTRAINTFRAMES_FRAMEA_MATRIX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCONSTRAINTFRAMES_FRAMEB_MATRIX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setHingeLimit 794
#define SETHINGELIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETHINGELIMIT_LOW num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETHINGELIMIT_HIGH num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETHINGELIMIT_SOFTNESS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETHINGELIMIT_BIAS_FACTOR num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define SETHINGELIMIT_RELAXATION_FACTOR num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_setConeLimit 795
#define SETCONELIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONELIMIT_SWINGSPAN1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCONELIMIT_SWINGSPAN2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETCONELIMIT_TWISTSPAN num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETCONELIMIT_SOFTNESS num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define SETCONELIMIT_BIAS_FACTOR num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define SETCONELIMIT_RELAXATION_FACTOR num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_getHingeLimitBiasFactor 796
#define GETHINGELIMITBIASFACTOR_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getHingeLimitRelaxationFactor 797
#define GETHINGELIMITRELAXATIONFACTOR_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getHingeLimitSign 798
#define GETHINGELIMITSIGN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getHingeSolveLimit 799
#define GETHINGESOLVELIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_useHingeReferenceFrameA 800
#define USEHINGEREFERENCEFRAMEA_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define USEHINGEREFERENCEFRAMEA_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getConstraintAppliedImpulse 801
#define GETCONSTRAINTAPPLIEDIMPULSE_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConstraintFixedActor 802
#define GETCONSTRAINTFIXEDACTOR_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getPointPivotA 803
#define GETPOINTPIVOTA_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPOINTPIVOTA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPOINTPIVOTA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETPOINTPIVOTA_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getPointPivotB 804
#define GETPOINTPIVOTB_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPOINTPIVOTB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPOINTPIVOTB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETPOINTPIVOTB_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getConstraintActorA 805
#define GETCONSTRAINTACTORA_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConstraintActorB 806
#define GETCONSTRAINTACTORB_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setConstraintSolverIterations 807
#define SETCONSTRAINTSOLVERITERATIONS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONSTRAINTSOLVERITERATIONS_NUM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getConeBiasFactor 808
#define GETCONEBIASFACTOR_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeDamping 809
#define GETCONEDAMPING_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeFixThresh 810
#define GETCONEFIXTHRESH_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeLimit 811
#define GETCONELIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCONELIMIT_LIMIT_INDEX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getConstraintLimitSoftness 812
#define GETCONSTRAINTLIMITSOFTNESS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConstraintSolverIterations 813
#define GETCONSTRAINTSOLVERITERATIONS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeAnglePoint 814
#define GETCONEANGLEPOINT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCONEANGLEPOINT_ANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCONEANGLEPOINT_C_LEN num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETCONEANGLEPOINT_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETCONEANGLEPOINT_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETCONEANGLEPOINT_Z num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_getConstraintAngularOnly 815
#define GETCONSTRAINTANGULARONLY_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeSolveSwingLimit 816
#define GETCONESOLVESWINGLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeSolveTwistLimit 817
#define GETCONESOLVETWISTLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeSwingSpan1 818
#define GETCONESWINGSPAN1_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeSwingSpan2 819
#define GETCONESWINGSPAN2_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeTwistAngle 820
#define GETCONETWISTANGLE_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeTwistLimitSign 821
#define GETCONETWISTLIMITSIGN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeTwistSpan 822
#define GETCONETWISTSPAN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setConstraintAngularOnly 823
#define SETCONSTRAINTANGULARONLY_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONSTRAINTANGULARONLY_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setConeDamping 824
#define SETCONEDAMPING_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONEDAMPING_DAMPING num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setConeFixThresh 825
#define SETCONEFIXTHRESH_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONEFIXTHRESH_FIXTHRESH num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getSlideAnchorA 826
#define GETSLIDEANCHORA_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSLIDEANCHORA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSLIDEANCHORA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSLIDEANCHORA_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getSlideAnchorB 827
#define GETSLIDEANCHORB_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSLIDEANCHORB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSLIDEANCHORB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSLIDEANCHORB_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getSlideAngDepth 828
#define GETSLIDEANGDEPTH_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideAngularPos 829
#define GETSLIDEANGULARPOS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideDampingDirAng 830
#define GETSLIDEDAMPINGDIRANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideDampingDirLin 831
#define GETSLIDEDAMPINGDIRLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideDampingLimAng 832
#define GETSLIDEDAMPINGLIMANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideDampingLimLin 833
#define GETSLIDEDAMPINGLIMLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideDampingOrthoAng 834
#define GETSLIDEDAMPINGORTHOANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideDampingOrthoLin 835
#define GETSLIDEDAMPINGORTHOLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideLinearPos 836
#define GETSLIDELINEARPOS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideLinDepth 837
#define GETSLIDELINDEPTH_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideLowerAngLimit 838
#define GETSLIDELOWERANGLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideLowerLinLimit 839
#define GETSLIDELOWERLINLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideRestitutionDirAng 840
#define GETSLIDERESTITUTIONDIRANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideRestitutionDirLin 841
#define GETSLIDERESTITUTIONDIRLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideRestitutionLimAng 842
#define GETSLIDERESTITUTIONLIMANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideRestitutionLimLin 843
#define GETSLIDERESTITUTIONLIMLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideRestitutionOrthoAng 844
#define GETSLIDERESTITUTIONORTHOANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideRestitutionOrthoLin 845
#define GETSLIDERESTITUTIONORTHOLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSoftnessDirAng 846
#define GETSLIDESOFTNESSDIRANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSoftnessDirLin 847
#define GETSLIDESOFTNESSDIRLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSoftnessLimAng 848
#define GETSLIDESOFTNESSLIMANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSoftnessLimLin 849
#define GETSLIDESOFTNESSLIMLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSoftnessOrthoAng 850
#define GETSLIDESOFTNESSORTHOANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSoftnessOrthoLin 851
#define GETSLIDESOFTNESSORTHOLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSolveAngLimit 852
#define GETSLIDESOLVEANGLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSolveLinLimit 853
#define GETSLIDESOLVELINLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideUpperAngLimit 854
#define GETSLIDEUPPERANGLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideUpperLinLimit 855
#define GETSLIDEUPPERLINLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideUseFrameOffset 856
#define GETSLIDEUSEFRAMEOFFSET_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSlideDampingDirAng 857
#define SETSLIDEDAMPINGDIRANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEDAMPINGDIRANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideDampingDirLin 858
#define SETSLIDEDAMPINGDIRLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEDAMPINGDIRLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideDampingLimAng 859
#define SETSLIDEDAMPINGLIMANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEDAMPINGLIMANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideDampingLimLin 860
#define SETSLIDEDAMPINGLIMLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEDAMPINGLIMLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideDampingOrthoAng 861
#define SETSLIDEDAMPINGORTHOANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEDAMPINGORTHOANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideDampingOrthoLin 862
#define SETSLIDEDAMPINGORTHOLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEDAMPINGORTHOLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideLowerAngLimit 863
#define SETSLIDELOWERANGLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDELOWERANGLIMIT_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideLowerLinLimit 864
#define SETSLIDELOWERLINLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDELOWERLINLIMIT_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideRestitutionDirAng 865
#define SETSLIDERESTITUTIONDIRANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDERESTITUTIONDIRANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideRestitutionDirLin 866
#define SETSLIDERESTITUTIONDIRLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDERESTITUTIONDIRLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideRestitutionLimAng 867
#define SETSLIDERESTITUTIONLIMANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDERESTITUTIONLIMANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideRestitutionLimLin 868
#define SETSLIDERESTITUTIONLIMLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDERESTITUTIONLIMLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideRestitutionOrthoAng 869
#define SETSLIDERESTITUTIONORTHOANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDERESTITUTIONORTHOANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideRestitutionOrthoLin 870
#define SETSLIDERESTITUTIONORTHOLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDERESTITUTIONORTHOLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideSoftnessDirAng 871
#define SETSLIDESOFTNESSDIRANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDESOFTNESSDIRANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideSoftnessDirLin 872
#define SETSLIDESOFTNESSDIRLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDESOFTNESSDIRLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideSoftnessLimAng 873
#define SETSLIDESOFTNESSLIMANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDESOFTNESSLIMANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideSoftnessLimLin 874
#define SETSLIDESOFTNESSLIMLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDESOFTNESSLIMLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideSoftnessOrthoAng 875
#define SETSLIDESOFTNESSORTHOANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDESOFTNESSORTHOANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideSoftnessOrthoLin 876
#define SETSLIDESOFTNESSORTHOLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDESOFTNESSORTHOLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideUpperAngLimit 877
#define SETSLIDEUPPERANGLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEUPPERANGLIMIT_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideUpperLinLimit 878
#define SETSLIDEUPPERLINLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEUPPERLINLIMIT_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ConstraintExists 879
#define CONSTRAINTEXISTS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetCameraPosition 880
#define SETCAMERAPOSITION_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCAMERAPOSITION_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCAMERAPOSITION_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetCameraPosition 881
#define GETCAMERAPOSITION_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCAMERAPOSITION_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCAMERAPOSITION_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_TranslateCamera 882
#define TRANSLATECAMERA_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TRANSLATECAMERA_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define TRANSLATECAMERA_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetCameraRotation 883
#define SETCAMERAROTATION_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCAMERAROTATION_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCAMERAROTATION_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetCameraRotation 884
#define GETCAMERAROTATION_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCAMERAROTATION_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCAMERAROTATION_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_RotateCamera 885
#define ROTATECAMERA_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ROTATECAMERA_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ROTATECAMERA_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetCameraFOV 886
#define SETCAMERAFOV_FOV num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetCameraFOV 887
#define FN_SetCameraAspectRatio 888
#define SETCAMERAASPECTRATIO_ASPECT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetCameraAspectRatio 889
#define FN_SetCameraFarValue 890
#define SETCAMERAFARVALUE_ZF num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetCameraFarValue 891
#define FN_SetCameraNearValue 892
#define SETCAMERANEARVALUE_ZN num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetCameraNearValue 893
#define FN_SetProjectionMatrix 894
#define SETPROJECTIONMATRIX_MATA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPROJECTIONMATRIX_PROJECTION_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetProjectionMatrix 895
#define GETPROJECTIONMATRIX_MATA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetWorldToViewportPosition 896
#define GETWORLDTOVIEWPORTPOSITION_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWORLDTOVIEWPORTPOSITION_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETWORLDTOVIEWPORTPOSITION_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETWORLDTOVIEWPORTPOSITION_VX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETWORLDTOVIEWPORTPOSITION_VY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_AddSceneSkyBox 897
#define ADDSCENESKYBOX_IMG_TOP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ADDSCENESKYBOX_IMG_BOTTOM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ADDSCENESKYBOX_IMG_LEFT num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define ADDSCENESKYBOX_IMG_RIGHT num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define ADDSCENESKYBOX_IMG_FRONT num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define ADDSCENESKYBOX_IMG_BACK num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_AddSceneSkyDome 898
#define ADDSCENESKYDOME_IMG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_AddSceneSkyDomeEx 899
#define ADDSCENESKYDOMEEX_IMG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ADDSCENESKYDOMEEX_HORIRES num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ADDSCENESKYDOMEEX_VERTRES num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define ADDSCENESKYDOMEEX_TXPERCENTAGE num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define ADDSCENESKYDOMEEX_SPHEREPERCENTAGE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define ADDSCENESKYDOMEEX_RADIUS num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_RemoveSceneSky 900
#define FN_SetWorld3DMaxSubSteps 901
#define SETWORLD3DMAXSUBSTEPS_STEPS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetWorld3DTimeStep 902
#define SETWORLD3DTIMESTEP_TS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetWorld3DMaxSubSteps 903
#define FN_GetWorld3DTimeStep 904
#define FN_SetSceneFog 905
#define SETSCENEFOG_COLOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSCENEFOG_FOG_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSCENEFOG_START_VAL num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETSCENEFOG_END_VAL num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETSCENEFOG_DENSITY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define SETSCENEFOG_PIXELFOG num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define SETSCENEFOG_RANGEFOG num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_GetSceneFog 906
#define GETSCENEFOG_COLOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSCENEFOG_FOG_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSCENEFOG_START_VAL num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSCENEFOG_END_VAL num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSCENEFOG_DENSITY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETSCENEFOG_PIXELFOG num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETSCENEFOG_RANGEFOG num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_ClearScene 907
#define FN_SetSceneShadowColor 908
#define SETSCENESHADOWCOLOR_COLOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetSceneShadowColor 909
#define FN_SetSceneAmbientColor 910
#define SETSCENEAMBIENTCOLOR_COLOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetSceneAmbientColor 911
#define FN_startParticleEmitter 912
#define STARTPARTICLEEMITTER_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_stopParticleEmitter 913
#define STOPPARTICLEEMITTER_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleDirection 914
#define SETPARTICLEDIRECTION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEDIRECTION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPARTICLEDIRECTION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETPARTICLEDIRECTION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getParticleDirection 915
#define GETPARTICLEDIRECTION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPARTICLEDIRECTION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPARTICLEDIRECTION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETPARTICLEDIRECTION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_useParticleEveryMeshVertex 916
#define USEPARTICLEEVERYMESHVERTEX_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define USEPARTICLEEVERYMESHVERTEX_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_particleIsUsingEveryMeshVertex 917
#define PARTICLEISUSINGEVERYMESHVERTEX_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleNormalDirectionMod 918
#define SETPARTICLENORMALDIRECTIONMOD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLENORMALDIRECTIONMOD_ND_MOD num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleNormalDirectionMod 919
#define GETPARTICLENORMALDIRECTIONMOD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_useParticleNormalDirection 920
#define USEPARTICLENORMALDIRECTION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define USEPARTICLENORMALDIRECTION_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_particleIsUsingNormalDirection 921
#define PARTICLEISUSINGNORMALDIRECTION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMesh 922
#define SETPARTICLEMESH_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMESH_MESH num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setMinParticlesPerSecond 923
#define SETMINPARTICLESPERSECOND_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMINPARTICLESPERSECOND_MINPARTICLESPERSECOND num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMinParticlesPerSecond 924
#define GETMINPARTICLESPERSECOND_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaxParticlesPerSecond 925
#define SETMAXPARTICLESPERSECOND_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMAXPARTICLESPERSECOND_MAXPARTICLESPERSECOND num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaxParticlesPerSecond 926
#define GETMAXPARTICLESPERSECOND_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMinStartColor 927
#define SETPARTICLEMINSTARTCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMINSTARTCOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleMinStartColor 928
#define GETPARTICLEMINSTARTCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMaxStartColor 929
#define SETPARTICLEMAXSTARTCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMAXSTARTCOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleMaxStartColor 930
#define GETPARTICLEMAXSTARTCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMinLife 931
#define SETPARTICLEMINLIFE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMINLIFE_MINLIFE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleMinLife 932
#define GETPARTICLEMINLIFE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMaxLife 933
#define SETPARTICLEMAXLIFE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMAXLIFE_MAXLIFE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleMaxLife 934
#define GETPARTICLEMAXLIFE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMaxAngle 935
#define SETPARTICLEMAXANGLE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMAXANGLE_MAXANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleMaxAngle 936
#define GETPARTICLEMAXANGLE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMinStartSize 937
#define SETPARTICLEMINSTARTSIZE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMINSTARTSIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPARTICLEMINSTARTSIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getParticleMinStartSize 938
#define GETPARTICLEMINSTARTSIZE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPARTICLEMINSTARTSIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPARTICLEMINSTARTSIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setParticleMaxStartSize 939
#define SETPARTICLEMAXSTARTSIZE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMAXSTARTSIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPARTICLEMAXSTARTSIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getParticleMaxStartSize 940
#define GETPARTICLEMAXSTARTSIZE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPARTICLEMAXSTARTSIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPARTICLEMAXSTARTSIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setParticleCenter 941
#define SETPARTICLECENTER_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLECENTER_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPARTICLECENTER_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETPARTICLECENTER_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getParticleCenter 942
#define GETPARTICLECENTER_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPARTICLECENTER_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPARTICLECENTER_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETPARTICLECENTER_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setParticleRadius 943
#define SETPARTICLERADIUS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLERADIUS_RADIUS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleRadius 944
#define GETPARTICLERADIUS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleRingThickness 945
#define SETPARTICLERINGTHICKNESS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLERINGTHICKNESS_RINGTHICKNESS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleRingThickness 946
#define GETPARTICLERINGTHICKNESS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleBox 947
#define SETPARTICLEBOX_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEBOX_MIN_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPARTICLEBOX_MIN_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETPARTICLEBOX_MIN_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETPARTICLEBOX_MAX_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define SETPARTICLEBOX_MAX_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define SETPARTICLEBOX_MAX_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_getParticleBox 948
#define GETPARTICLEBOX_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPARTICLEBOX_MIN_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPARTICLEBOX_MIN_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETPARTICLEBOX_MIN_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETPARTICLEBOX_MAX_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETPARTICLEBOX_MAX_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETPARTICLEBOX_MAX_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_setParticleNormal 949
#define SETPARTICLENORMAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLENORMAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPARTICLENORMAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETPARTICLENORMAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getParticleNormal 950
#define GETPARTICLENORMAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPARTICLENORMAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPARTICLENORMAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETPARTICLENORMAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setParticleLength 951
#define SETPARTICLELENGTH_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLELENGTH_P_LEN num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleLength 952
#define GETPARTICLELENGTH_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_useParticleOutlineOnly 953
#define USEPARTICLEOUTLINEONLY_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define USEPARTICLEOUTLINEONLY_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_particleIsUsingOutlineOnly 954
#define PARTICLEISUSINGOUTLINEONLY_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getParticleType 955
#define GETPARTICLETYPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_lightIsCastingShadow 956
#define LIGHTISCASTINGSHADOW_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getLightType 957
#define GETLIGHTTYPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getLightRadius 958
#define GETLIGHTRADIUS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setLightType 959
#define SETLIGHTTYPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTTYPE_LIGHT_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setLightRadius 960
#define SETLIGHTRADIUS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTRADIUS_RADIUS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setLightShadowCast 961
#define SETLIGHTSHADOWCAST_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTSHADOWCAST_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetLightAmbientColor 962
#define SETLIGHTAMBIENTCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTAMBIENTCOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetLightAmbientColor 963
#define GETLIGHTAMBIENTCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetLightAttenuation 964
#define SETLIGHTATTENUATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTATTENUATION_L_CONSTANT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETLIGHTATTENUATION_L_LINEAR num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETLIGHTATTENUATION_L_QUADRATIC num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetLightAttenuation 965
#define GETLIGHTATTENUATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETLIGHTATTENUATION_CONSTANT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETLIGHTATTENUATION_LINEAR num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETLIGHTATTENUATION_QUADRATIC num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetLightDiffuseColor 966
#define SETLIGHTDIFFUSECOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTDIFFUSECOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetLightDiffuseColor 967
#define GETLIGHTDIFFUSECOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetLightFalloff 968
#define SETLIGHTFALLOFF_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTFALLOFF_FALLOFF num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetLightFalloff 969
#define GETLIGHTFALLOFF_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetLightInnerCone 970
#define SETLIGHTINNERCONE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTINNERCONE_ANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetLightInnerCone 971
#define GETLIGHTINNERCONE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetLightOuterCone 972
#define SETLIGHTOUTERCONE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTOUTERCONE_ANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetLightOuterCone 973
#define GETLIGHTOUTERCONE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetLightSpecularColor 974
#define SETLIGHTSPECULARCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTSPECULARCOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetLightSpecularColor 975
#define GETLIGHTSPECULARCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetTerrainPatchAABB 976
#define GETTERRAINPATCHAABB_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTERRAINPATCHAABB_PATCHX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTERRAINPATCHAABB_PATCHZ num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETTERRAINPATCHAABB_MINX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETTERRAINPATCHAABB_MINY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETTERRAINPATCHAABB_MINZ num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETTERRAINPATCHAABB_MAXX num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define GETTERRAINPATCHAABB_MAXY num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define GETTERRAINPATCHAABB_MAXZ num_var[8].nref[0].value[ num_var[8].byref_offset ]
#define FN_GetTerrainPatchLOD 977
#define GETTERRAINPATCHLOD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTERRAINPATCHLOD_PATCHX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTERRAINPATCHLOD_PATCHZ num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetTerrainHeight 978
#define GETTERRAINHEIGHT_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTERRAINHEIGHT_PATCHX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTERRAINHEIGHT_PATCHZ num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetTerrainCenter 979
#define GETTERRAINCENTER_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTERRAINCENTER_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTERRAINCENTER_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETTERRAINCENTER_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetTerrainLODDistance 980
#define SETTERRAINLODDISTANCE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTERRAINLODDISTANCE_LOD num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTERRAINLODDISTANCE_DISTANCE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ScaleTerrainTexture 981
#define SCALETERRAINTEXTURE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SCALETERRAINTEXTURE_SCALE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SCALETERRAINTEXTURE_SCALE2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetTerrainCameraMovementDelta 982
#define SETTERRAINCAMERAMOVEMENTDELTA_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTERRAINCAMERAMOVEMENTDELTA_DELTA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetTerrainCameraRotationDelta 983
#define SETTERRAINCAMERAROTATIONDELTA_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTERRAINCAMERAROTATIONDELTA_DELTA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetTerrainPatchLOD 984
#define SETTERRAINPATCHLOD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTERRAINPATCHLOD_PATCHX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTERRAINPATCHLOD_PATCHZ num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETTERRAINPATCHLOD_LOD num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetProjectorTarget 985
#define SETPROJECTORTARGET_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPROJECTORTARGET_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPROJECTORTARGET_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETPROJECTORTARGET_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetProjectorTarget 986
#define GETPROJECTORTARGET_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPROJECTORTARGET_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPROJECTORTARGET_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETPROJECTORTARGET_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetProjectorFOV 987
#define SETPROJECTORFOV_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPROJECTORFOV_FOV num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetProjectorFOV 988
#define GETPROJECTORFOV_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_createMaterial 989
#define FN_deleteMaterial 990
#define DELETEMATERIAL_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setActorMaterial 991
#define SETACTORMATERIAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORMATERIAL_MATERIAL_NUM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORMATERIAL_MATERIAL_ID num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getActorMaterial 992
#define GETACTORMATERIAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORMATERIAL_MATERIAL_NUM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_copyActorMaterial 993
#define COPYACTORMATERIAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COPYACTORMATERIAL_MATERIAL_NUM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_copyMaterial 994
#define COPYMATERIAL_SMATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialTextureCanvas 995
#define SETMATERIALTEXTURECANVAS_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALTEXTURECANVAS_LEVEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATERIALTEXTURECANVAS_CANVAS_ID num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setMaterialAmbientColor 996
#define SETMATERIALAMBIENTCOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALAMBIENTCOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialAmbientColor 997
#define GETMATERIALAMBIENTCOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialAntiAliasing 998
#define SETMATERIALANTIALIASING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALANTIALIASING_AA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialAntiAliasing 999
#define GETMATERIALANTIALIASING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialBackfaceCulling 1000
#define SETMATERIALBACKFACECULLING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALBACKFACECULLING_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialBackfaceCulling 1001
#define GETMATERIALBACKFACECULLING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialBlendFactor 1002
#define SETMATERIALBLENDFACTOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALBLENDFACTOR_BF num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialBlendFactor 1003
#define GETMATERIALBLENDFACTOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialBlendMode 1004
#define SETMATERIALBLENDMODE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALBLENDMODE_BLEND_MODE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialBlendMode 1005
#define GETMATERIALBLENDMODE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialColorMask 1006
#define SETMATERIALCOLORMASK_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALCOLORMASK_COLOR_MASK num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialColorMask 1007
#define GETMATERIALCOLORMASK_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialColorMode 1008
#define SETMATERIALCOLORMODE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALCOLORMODE_COLOR_MODE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialColorMode 1009
#define GETMATERIALCOLORMODE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialDiffuseColor 1010
#define SETMATERIALDIFFUSECOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALDIFFUSECOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialDiffuseColor 1011
#define GETMATERIALDIFFUSECOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialEmissiveColor 1012
#define SETMATERIALEMISSIVECOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALEMISSIVECOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialEmissiveColor 1013
#define GETMATERIALEMISSIVECOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialFog 1014
#define SETMATERIALFOG_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALFOG_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialFog 1015
#define GETMATERIALFOG_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialFrontfaceCulling 1016
#define SETMATERIALFRONTFACECULLING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALFRONTFACECULLING_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialFrontfaceCulling 1017
#define GETMATERIALFRONTFACECULLING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialGouraudShading 1018
#define SETMATERIALGOURAUDSHADING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALGOURAUDSHADING_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_materialIsGouraudShaded 1019
#define MATERIALISGOURAUDSHADED_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_materialIsAplhaBlend 1020
#define MATERIALISAPLHABLEND_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_materialIsTransparent 1021
#define MATERIALISTRANSPARENT_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialLighting 1022
#define SETMATERIALLIGHTING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALLIGHTING_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_materialIsLit 1023
#define MATERIALISLIT_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialType 1024
#define SETMATERIALTYPE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALTYPE_MAT_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialType 1025
#define GETMATERIALTYPE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialNormalize 1026
#define SETMATERIALNORMALIZE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALNORMALIZE_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_materialIsNormalized 1027
#define MATERIALISNORMALIZED_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialPointCloud 1028
#define SETMATERIALPOINTCLOUD_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALPOINTCLOUD_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_materialIsPointCloud 1029
#define MATERIALISPOINTCLOUD_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialFlag 1030
#define SETMATERIALFLAG_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALFLAG_MATERIAL_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATERIALFLAG_F_VALUE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getMaterialFlag 1031
#define GETMATERIALFLAG_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMATERIALFLAG_MATERIAL_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setMaterialTexture 1032
#define SETMATERIALTEXTURE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALTEXTURE_LEVEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATERIALTEXTURE_IMG_ID num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setMaterialShininess 1033
#define SETMATERIALSHININESS_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALSHININESS_SHININESS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialShininess 1034
#define GETMATERIALSHININESS_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialSpecularColor 1035
#define SETMATERIALSPECULARCOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALSPECULARCOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialSpecularColor 1036
#define GETMATERIALSPECULARCOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialThickness 1037
#define SETMATERIALTHICKNESS_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALTHICKNESS_THICKNESS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialThickness 1038
#define GETMATERIALTHICKNESS_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialWireframe 1039
#define SETMATERIALWIREFRAME_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALWIREFRAME_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_materialIsWireframe 1040
#define MATERIALISWIREFRAME_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setActorTexture 1041
#define SETACTORTEXTURE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORTEXTURE_LAYER num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORTEXTURE_IMAGE_ID num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getActorMaterialCount 1042
#define GETACTORMATERIALCOUNT_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setActorMaterialFlag 1043
#define SETACTORMATERIALFLAG_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORMATERIALFLAG_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORMATERIALFLAG_FLAG_VALUE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getActorMaterialFlag 1044
#define GETACTORMATERIALFLAG_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORMATERIALFLAG_MATERIAL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORMATERIALFLAG_FLAG num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setActorMaterialType 1045
#define SETACTORMATERIALTYPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORMATERIALTYPE_MATERIAL_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getActorMaterialType 1046
#define GETACTORMATERIALTYPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORMATERIALTYPE_MATERIAL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_MaterialExists 1047
#define MATERIALEXISTS_MATERIAL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumMaterialConstants 1048
#define NUMMATERIALCONSTANTS_MATERIAL_TYPE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetMaterialConstantName$ 1049
#define GETMATERIALCONSTANTNAME$_MATERIAL_TYPE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMATERIALCONSTANTNAME$_INDEX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetMaterialConstant 1050
#define SETMATERIALCONSTANT_MATERIAL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALCONSTANT_M_CONSTANT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define SETMATERIALCONSTANT_N1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATERIALCONSTANT_N2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETMATERIALCONSTANT_N3 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETMATERIALCONSTANT_N4 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_GetMaterialConstant 1051
#define GETMATERIALCONSTANT_MATERIAL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMATERIALCONSTANT_M_CONSTANT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define GETMATERIALCONSTANT_N1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMATERIALCONSTANT_N2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETMATERIALCONSTANT_N3 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETMATERIALCONSTANT_N4 num_var[4].nref[0].value[ num_var[4].byref_offset ]


#endif // RC_DEFINES_H_INCLUDED
