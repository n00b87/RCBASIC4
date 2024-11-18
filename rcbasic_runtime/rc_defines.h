#ifndef RC_DEFINES_H_INCLUDED
#define RC_DEFINES_H_INCLUDED

#define FN_Fprint 0
#define FPRINT_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Input$ 1
#define INPUT$_PROMPT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_tst 2
#define FN_ArrayDim 3
#define ARRAYDIM_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_StringArrayDim 4
#define STRINGARRAYDIM_ID$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_NumberArrayDim 5
#define NUMBERARRAYDIM_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ArraySize 6
#define ARRAYSIZE_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ARRAYSIZE_ARRAY_DIM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_StringArraySize 7
#define STRINGARRAYSIZE_ID$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define STRINGARRAYSIZE_ARRAY_DIM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumberArraySize 8
#define NUMBERARRAYSIZE_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define NUMBERARRAYSIZE_ARRAY_DIM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_NumberArrayCopy 9
#define NUMBERARRAYCOPY_SRC num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define NUMBERARRAYCOPY_DST num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_StringArrayCopy 10
#define STRINGARRAYCOPY_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define STRINGARRAYCOPY_DST$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_ArrayCopy 11
#define ARRAYCOPY_SRC num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ARRAYCOPY_DST num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_NumberArrayFill 12
#define NUMBERARRAYFILL_SRC num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define NUMBERARRAYFILL_FDATA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_StringArrayFill 13
#define STRINGARRAYFILL_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define STRINGARRAYFILL_FDATA$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_ArrayFill 14
#define ARRAYFILL_SRC num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ARRAYFILL_FDATA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_TypeArrayDim 15
#define TYPEARRAYDIM_ID usr_var[0].var_ref
#define FN_TypeArraySize 16
#define TYPEARRAYSIZE_ID usr_var[0].var_ref
#define TYPEARRAYSIZE_ARRAY_DIM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TypeArrayCopy 17
#define TYPEARRAYCOPY_SRC usr_var[0].var_ref
#define TYPEARRAYCOPY_DST usr_var[1].var_ref
#define FN_TypeArrayFill 18
#define TYPEARRAYFILL_SRC usr_var[0].var_ref
#define TYPEARRAYFILL_FDATA usr_var[1].var_ref->uid_value[0]
#define FN_Abs 19
#define ABS_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Acos 20
#define ACOS_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_AndBit 21
#define ANDBIT_A num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ANDBIT_B num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_Asin 22
#define ASIN_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Atan 23
#define ATAN_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Bin$ 24
#define BIN$_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CInt32 25
#define CINT32_I num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CInt64 26
#define CINT64_I num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Cos 27
#define COS_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Degrees 28
#define DEGREES_R num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Exp 29
#define EXP_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Frac 30
#define FRAC_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Hex$ 31
#define HEX$_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_HexVal 32
#define HEXVAL_N$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Int 33
#define INT_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Log 34
#define LOG_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Max 35
#define MAX_A num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define MAX_B num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_Min 36
#define MIN_A num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define MIN_B num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_OrBit 37
#define ORBIT_A num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ORBIT_B num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_Radians 38
#define RADIANS_D num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Randomize 39
#define RANDOMIZE_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Rand 40
#define RAND_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Round 41
#define ROUND_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Sign 42
#define SIGN_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Sin 43
#define SIN_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Sqrt 44
#define SQRT_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Tan 45
#define TAN_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_XOrBit 46
#define XORBIT_A num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define XORBIT_B num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetLineIntersection 47
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
#define FN_Interpolate 48
#define INTERPOLATE_MIN_A num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define INTERPOLATE_MAX_A num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define INTERPOLATE_MID_A num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define INTERPOLATE_MIN_B num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define INTERPOLATE_MAX_B num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_ATan2 49
#define ATAN2_Y num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ATAN2_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_PointInQuad 50
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
#define FN_PointInTri 51
#define POINTINTRI_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define POINTINTRI_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define POINTINTRI_X1 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define POINTINTRI_Y1 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define POINTINTRI_X2 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define POINTINTRI_Y2 num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define POINTINTRI_X3 num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define POINTINTRI_Y3 num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define FN_Distance2D 52
#define DISTANCE2D_X1 num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DISTANCE2D_Y1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DISTANCE2D_X2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DISTANCE2D_Y2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_Distance3D 53
#define DISTANCE3D_X1 num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DISTANCE3D_Y1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DISTANCE3D_Z1 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DISTANCE3D_X2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DISTANCE3D_Y2 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define DISTANCE3D_Z2 num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_GetCircleLineIntersection 54
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
#define FN_GetLinePlaneIntersection 55
#define GETLINEPLANEINTERSECTION_LINE_POINT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETLINEPLANEINTERSECTION_LINE_DIRECTION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETLINEPLANEINTERSECTION_PLANE_POINT_1 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETLINEPLANEINTERSECTION_PLANE_POINT_2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETLINEPLANEINTERSECTION_PLANE_POINT_3 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETLINEPLANEINTERSECTION_INTERSECTION num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_Asc 56
#define ASC_C$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Chr$ 57
#define CHR$_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Insert$ 58
#define INSERT$_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define INSERT$_TGT$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define INSERT$_POS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_InStr 59
#define INSTR_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define INSTR_SUBSTR$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_Lcase$ 60
#define LCASE$_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Left$ 61
#define LEFT$_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define LEFT$_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Length 62
#define LENGTH_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Len 63
#define LEN_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Ltrim$ 64
#define LTRIM$_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Mid$ 65
#define MID$_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define MID$_START num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define MID$_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ReplaceSubstr$ 66
#define REPLACESUBSTR$_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define REPLACESUBSTR$_RPC$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define REPLACESUBSTR$_POS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Replace$ 67
#define REPLACE$_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define REPLACE$_TGT$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define REPLACE$_RPC$ str_var[2].sref[0].value[ str_var[2].byref_offset ]
#define FN_Reverse$ 68
#define REVERSE$_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Right$ 69
#define RIGHT$_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define RIGHT$_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Rtrim$ 70
#define RTRIM$_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_StringFill$ 71
#define STRINGFILL$_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define STRINGFILL$_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Str$ 72
#define STR$_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Str_F$ 73
#define STR_F$_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Str_S$ 74
#define STR_S$_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Tally 75
#define TALLY_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define TALLY_SUBSTR$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_Trim$ 76
#define TRIM$_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Ucase$ 77
#define UCASE$_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Val 78
#define VAL_N$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Size 79
#define SIZE_S$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_BufferFromString 80
#define BUFFERFROMSTRING_S$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define BUFFERFROMSTRING_BUFFER num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_StringFromBuffer$ 81
#define STRINGFROMBUFFER$_BUFFER num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define STRINGFROMBUFFER$_BUFFER_SIZE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_CreateStack_N 82
#define FN_CreateStack_S 83
#define FN_ClearStack_N 84
#define CLEARSTACK_N_NUM_STACK num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ClearStack_S 85
#define CLEARSTACK_S_STR_STACK num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteStack_N 86
#define DELETESTACK_N_NUM_STACK num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteStack_S 87
#define DELETESTACK_S_STR_STACK num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Push_N 88
#define PUSH_N_NUM_STACK num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define PUSH_N_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_Pop_N 89
#define POP_N_NUM_STACK num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Push_S 90
#define PUSH_S_STR_STACK num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define PUSH_S_S$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Pop_S$ 91
#define POP_S$_STR_STACK num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Stack_Size_N 92
#define STACK_SIZE_N_NUM_STACK num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Stack_Size_S 93
#define STACK_SIZE_S_STR_STACK num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_OpenFile 94
#define OPENFILE_FILENAME$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define OPENFILE_MODE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CloseFile 95
#define CLOSEFILE_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ReadByte 96
#define READBYTE_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_WriteByte 97
#define WRITEBYTE_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WRITEBYTE_BYTE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ReadLine$ 98
#define READLINE$_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Write 99
#define WRITE_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WRITE_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_WriteLine 100
#define WRITELINE_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WRITELINE_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_CopyFile 101
#define COPYFILE_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define COPYFILE_DST$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_RemoveFile 102
#define REMOVEFILE_FILENAME$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_FileExists 103
#define FILEEXISTS_FILENAME$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_MoveFile 104
#define MOVEFILE_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define MOVEFILE_DST$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_RenameFile 105
#define RENAMEFILE_SRC$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define RENAMEFILE_DST$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_FileLength 106
#define FILELENGTH_FILENAME$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Tell 107
#define TELL_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Seek 108
#define SEEK_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SEEK_POS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_EOF 109
#define EOF_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_WriteByteBuffer 110
#define WRITEBYTEBUFFER_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WRITEBYTEBUFFER_BUF num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define WRITEBYTEBUFFER_BUF_SIZE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ReadByteBuffer 111
#define READBYTEBUFFER_STREAM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define READBYTEBUFFER_BUF num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define READBYTEBUFFER_BUF_SIZE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ChangeDir 112
#define CHANGEDIR_P$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_DirExists 113
#define DIREXISTS_P$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_DirFirst$ 114
#define FN_Dir$ 115
#define FN_DirNext$ 116
#define FN_MakeDir 117
#define MAKEDIR_P$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_RemoveDir 118
#define REMOVEDIR_P$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Date$ 119
#define FN_Easter$ 120
#define EASTER$_YEAR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Ticks 121
#define FN_Time$ 122
#define FN_Timer 123
#define FN_Wait 124
#define WAIT_M_SEC num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_OpenWindow 125
#define OPENWINDOW_TITLE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define OPENWINDOW_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define OPENWINDOW_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define OPENWINDOW_FULLSCREEN num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define OPENWINDOW_VSYNC num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_OpenWindowEx 126
#define OPENWINDOWEX_TITLE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define OPENWINDOWEX_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define OPENWINDOWEX_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define OPENWINDOWEX_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define OPENWINDOWEX_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define OPENWINDOWEX_MODE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define OPENWINDOWEX_AA num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define OPENWINDOWEX_STENCIL_BUFFER num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define OPENWINDOWEX_VSYNC num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define FN_CloseWindow 127
#define FN_RaiseWindow 128
#define FN_Update 129
#define FN_Cls 130
#define FN_SetClearColor 131
#define SETCLEARCOLOR_C num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ShowWindow 132
#define FN_HideWindow 133
#define FN_SetWindowTitle 134
#define SETWINDOWTITLE_TITLE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_WindowTitle$ 135
#define FN_SetWindowPosition 136
#define SETWINDOWPOSITION_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWINDOWPOSITION_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWindowPosition 137
#define GETWINDOWPOSITION_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWINDOWPOSITION_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetWindowSize 138
#define SETWINDOWSIZE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWINDOWSIZE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWindowSize 139
#define GETWINDOWSIZE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWINDOWSIZE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetWindowMinSize 140
#define SETWINDOWMINSIZE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWINDOWMINSIZE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWindowMinSize 141
#define GETWINDOWMINSIZE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWINDOWMINSIZE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetWindowMaxSize 142
#define SETWINDOWMAXSIZE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETWINDOWMAXSIZE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetWindowMaxSize 143
#define GETWINDOWMAXSIZE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWINDOWMAXSIZE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_WindowIsFullscreen 144
#define FN_WindowIsVisible 145
#define FN_WindowIsBordered 146
#define FN_WindowIsResizable 147
#define FN_WindowIsMinimized 148
#define FN_WindowIsMaximized 149
#define FN_WindowHasInputFocus 150
#define FN_WindowHasMouseFocus 151
#define FN_SetWindowFullscreen 152
#define SETWINDOWFULLSCREEN_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_MaximizeWindow 153
#define FN_MinimizeWindow 154
#define FN_SetWindowBordered 155
#define SETWINDOWBORDERED_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_WindowClip 156
#define WINDOWCLIP_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WINDOWCLIP_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define WINDOWCLIP_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define WINDOWCLIP_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_WindowExists 157
#define FN_WindowEvent_Close 158
#define FN_WindowEvent_Maximize 159
#define FN_WindowEvent_Minimize 160
#define FN_FPS 161
#define FN_SetWindowIcon 162
#define SETWINDOWICON_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_WindowEvent_Resize 163
#define FN_SetWindowAutoClose 164
#define SETWINDOWAUTOCLOSE_EXIT_ON_CLOSE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetWindowResizable 165
#define SETWINDOWRESIZABLE_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_WindowMode 166
#define WINDOWMODE_VISIBLE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WINDOWMODE_FULLSCREEN num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define WINDOWMODE_RESIZABLE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define WINDOWMODE_BORDERLESS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define WINDOWMODE_HIGHDPI num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getWindowMode 167
#define FN_RestoreWindow 168
#define FN_GrabInput 169
#define GRABINPUT_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetWindowAlwaysOnTop 170
#define SETWINDOWALWAYSONTOP_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetMouseRelative 171
#define SETMOUSERELATIVE_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_FlashWindow 172
#define FLASHWINDOW_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_WindowIsGrabbed 173
#define FN_PreUpdate 174
#define FN_OpenCanvas 175
#define OPENCANVAS_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define OPENCANVAS_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define OPENCANVAS_VIEWPORT_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define OPENCANVAS_VIEWPORT_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define OPENCANVAS_VIEWPORT_W num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define OPENCANVAS_VIEWPORT_H num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define OPENCANVAS_MODE num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_CloseCanvas 176
#define CLOSECANVAS_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_OpenCanvas3D 177
#define OPENCANVAS3D_VIEWPORT_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define OPENCANVAS3D_VIEWPORT_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define OPENCANVAS3D_VIEWPORT_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define OPENCANVAS3D_VIEWPORT_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define OPENCANVAS3D_MODE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_SetCanvasVisible 178
#define SETCANVASVISIBLE_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCANVASVISIBLE_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_CanvasIsVisible 179
#define CANVASISVISIBLE_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetCanvasViewport 180
#define SETCANVASVIEWPORT_CNUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCANVASVIEWPORT_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCANVASVIEWPORT_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETCANVASVIEWPORT_W num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETCANVASVIEWPORT_H num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_GetCanvasViewport 181
#define GETCANVASVIEWPORT_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCANVASVIEWPORT_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCANVASVIEWPORT_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETCANVASVIEWPORT_W num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETCANVASVIEWPORT_H num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_Canvas 182
#define CANVAS_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetCanvasOffset 183
#define SETCANVASOFFSET_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCANVASOFFSET_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCANVASOFFSET_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetCanvasOffset 184
#define GETCANVASOFFSET_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCANVASOFFSET_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCANVASOFFSET_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetCanvasSize 185
#define GETCANVASSIZE_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCANVASSIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCANVASSIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ClearCanvas 186
#define FN_SetCanvasAlpha 187
#define SETCANVASALPHA_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCANVASALPHA_A num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetCanvasAlpha 188
#define GETCANVASALPHA_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetCanvasColorMod 189
#define SETCANVASCOLORMOD_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCANVASCOLORMOD_C num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetCanvasColorMod 190
#define GETCANVASCOLORMOD_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CloneCanvas 191
#define CLONECANVAS_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CLONECANVAS_MODE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetCanvasZ 192
#define SETCANVASZ_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCANVASZ_Z num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_CanvasZ 193
#define CANVASZ_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CanvasClip 194
#define CANVASCLIP_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CANVASCLIP_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CANVASCLIP_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CANVASCLIP_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_ActiveCanvas 195
#define FN_SetCanvasPhysics2D 196
#define SETCANVASPHYSICS2D_C_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCANVASPHYSICS2D_STATE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_OpenCanvasSpriteLayer 197
#define OPENCANVASSPRITELAYER_VIEWPORT_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define OPENCANVASSPRITELAYER_VIEWPORT_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define OPENCANVASSPRITELAYER_VIEWPORT_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define OPENCANVASSPRITELAYER_VIEWPORT_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_Circle 198
#define CIRCLE_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CIRCLE_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CIRCLE_RADIUS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_CircleFill 199
#define CIRCLEFILL_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CIRCLEFILL_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CIRCLEFILL_RADIUS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_Ellipse 200
#define ELLIPSE_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ELLIPSE_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ELLIPSE_RX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define ELLIPSE_RY num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_EllipseFill 201
#define ELLIPSEFILL_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ELLIPSEFILL_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ELLIPSEFILL_RX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define ELLIPSEFILL_RY num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_FloodFill 202
#define FLOODFILL_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FLOODFILL_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetPixel 203
#define GETPIXEL_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPIXEL_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetColor 204
#define SETCOLOR_C num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_Line 205
#define LINE_X1 num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define LINE_Y1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define LINE_X2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define LINE_Y2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_Poly 206
#define POLY_N num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define POLY_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define POLY_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_Rect 207
#define RECT_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define RECT_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define RECT_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define RECT_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_RectFill 208
#define RECTFILL_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define RECTFILL_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define RECTFILL_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define RECTFILL_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_RGB 209
#define RGB_R num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define RGB_G num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define RGB_B num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_RGBA 210
#define RGBA_R num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define RGBA_G num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define RGBA_B num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define RGBA_A num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_Pset 211
#define PSET_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define PSET_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_LoadImage 212
#define LOADIMAGE_IMG$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_LoadImageEx 213
#define LOADIMAGEEX_IMG$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define LOADIMAGEEX_COLKEY num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_createImage 214
#define CREATEIMAGE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEIMAGE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEIMAGE_BUFFER num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_createImageEx 215
#define CREATEIMAGEEX_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEIMAGEEX_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEIMAGEEX_BUFFER num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEIMAGEEX_COLOR num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_BufferFromImage 216
#define BUFFERFROMIMAGE_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define BUFFERFROMIMAGE_BUFFER num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ImageExists 217
#define IMAGEEXISTS_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ColorKey 218
#define COLORKEY_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COLORKEY_C num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setBilinearFilter 219
#define SETBILINEARFILTER_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getBilinearFilter 220
#define FN_CopyImage 221
#define COPYIMAGE_IMG_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteImage 222
#define DELETEIMAGE_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetImageAlpha 223
#define SETIMAGEALPHA_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETIMAGEALPHA_A num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetImageAlpha 224
#define GETIMAGEALPHA_IMG_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetImageSize 225
#define GETIMAGESIZE_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETIMAGESIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETIMAGESIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetBlendMode 226
#define SETBLENDMODE_BLEND_MODE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetBlendMode 227
#define FN_SetImageColorMod 228
#define SETIMAGECOLORMOD_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETIMAGECOLORMOD_C num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetImageColorMod 229
#define GETIMAGECOLORMOD_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DrawImage 230
#define DRAWIMAGE_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_DrawImage_Blit 231
#define DRAWIMAGE_BLIT_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_BLIT_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_BLIT_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_BLIT_SRC_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWIMAGE_BLIT_SRC_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define DRAWIMAGE_BLIT_SRC_W num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define DRAWIMAGE_BLIT_SRC_H num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_DrawImage_BlitEx 232
#define DRAWIMAGE_BLITEX_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_BLITEX_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_BLITEX_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_BLITEX_W num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWIMAGE_BLITEX_H num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define DRAWIMAGE_BLITEX_SRC_X num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define DRAWIMAGE_BLITEX_SRC_Y num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define DRAWIMAGE_BLITEX_SRC_W num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define DRAWIMAGE_BLITEX_SRC_H num_var[8].nref[0].value[ num_var[8].byref_offset ]
#define FN_DrawImage_Rotate 233
#define DRAWIMAGE_ROTATE_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_ROTATE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_ROTATE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_ROTATE_ANGLE num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_DrawImage_RotateEx 234
#define DRAWIMAGE_ROTATEEX_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_ROTATEEX_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_ROTATEEX_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_ROTATEEX_SRC_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWIMAGE_ROTATEEX_SRC_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define DRAWIMAGE_ROTATEEX_SRC_W num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define DRAWIMAGE_ROTATEEX_SRC_H num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define DRAWIMAGE_ROTATEEX_ANGLE num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define FN_DrawImage_Zoom 235
#define DRAWIMAGE_ZOOM_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_ZOOM_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_ZOOM_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_ZOOM_ZX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWIMAGE_ZOOM_ZY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_DrawImage_ZoomEx 236
#define DRAWIMAGE_ZOOMEX_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_ZOOMEX_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_ZOOMEX_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_ZOOMEX_SRC_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWIMAGE_ZOOMEX_SRC_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define DRAWIMAGE_ZOOMEX_SRC_W num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define DRAWIMAGE_ZOOMEX_SRC_H num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define DRAWIMAGE_ZOOMEX_ZX num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define DRAWIMAGE_ZOOMEX_ZY num_var[8].nref[0].value[ num_var[8].byref_offset ]
#define FN_DrawImage_Rotozoom 237
#define DRAWIMAGE_ROTOZOOM_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_ROTOZOOM_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_ROTOZOOM_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_ROTOZOOM_ANGLE num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWIMAGE_ROTOZOOM_ZX num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define DRAWIMAGE_ROTOZOOM_ZY num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_DrawImage_RotozoomEx 238
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
#define FN_DrawImage_Flip 239
#define DRAWIMAGE_FLIP_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_FLIP_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_FLIP_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_FLIP_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWIMAGE_FLIP_V num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_DrawImage_FlipEx 240
#define DRAWIMAGE_FLIPEX_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWIMAGE_FLIPEX_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWIMAGE_FLIPEX_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWIMAGE_FLIPEX_SRC_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWIMAGE_FLIPEX_SRC_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define DRAWIMAGE_FLIPEX_SRC_W num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define DRAWIMAGE_FLIPEX_SRC_H num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define DRAWIMAGE_FLIPEX_H num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define DRAWIMAGE_FLIPEX_V num_var[8].nref[0].value[ num_var[8].byref_offset ]
#define FN_InKey 241
#define FN_Key 242
#define KEY_KEY_CODE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_WaitKey 243
#define FN_HideMouse 244
#define FN_ShowMouse 245
#define FN_MouseIsVisible 246
#define FN_GetMouse 247
#define GETMOUSE_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMOUSE_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMOUSE_MB1 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETMOUSE_MB2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETMOUSE_MB3 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_MouseX 248
#define FN_MouseY 249
#define FN_MouseButton 250
#define MOUSEBUTTON_MB num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetMouseWheel 251
#define GETMOUSEWHEEL_X_AXIS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMOUSEWHEEL_Y_AXIS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_MouseWheelX 252
#define FN_MouseWheelY 253
#define FN_GetGlobalMouse 254
#define GETGLOBALMOUSE_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETGLOBALMOUSE_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETGLOBALMOUSE_MB1 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETGLOBALMOUSE_MB2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETGLOBALMOUSE_MB3 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_GlobalMouseX 255
#define FN_GlobalMouseY 256
#define FN_WarpMouse 257
#define WARPMOUSE_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WARPMOUSE_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_WarpMouseGlobal 258
#define WARPMOUSEGLOBAL_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define WARPMOUSEGLOBAL_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetMouseZone 259
#define SETMOUSEZONE_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMOUSEZONE_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMOUSEZONE_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETMOUSEZONE_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_ClearMouseZone 260
#define FN_CreateSound 261
#define CREATESOUND_BUFFER num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATESOUND_BUFFER_SIZE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATESOUND_VOL num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_LoadSound 262
#define LOADSOUND_SND_FILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_LoadMusic 263
#define LOADMUSIC_MUSIC_FILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_PlaySound 264
#define PLAYSOUND_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define PLAYSOUND_CHANNEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define PLAYSOUND_LOOPS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_PlaySoundTimed 265
#define PLAYSOUNDTIMED_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define PLAYSOUNDTIMED_CHANNEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define PLAYSOUNDTIMED_LOOPS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define PLAYSOUNDTIMED_MS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_PlayMusic 266
#define PLAYMUSIC_MLOOPS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_PauseSound 267
#define PAUSESOUND_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ResumeSound 268
#define RESUMESOUND_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_PauseMusic 269
#define FN_ResumeMusic 270
#define FN_DeleteSound 271
#define DELETESOUND_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteMusic 272
#define FN_FadeMusicIn 273
#define FADEMUSICIN_FADE_TIME num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FADEMUSICIN_LOOPS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_FadeMusicOut 274
#define FADEMUSICOUT_FADE_TIME num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_MusicExists 275
#define FN_SetMusicVolume 276
#define SETMUSICVOLUME_VOL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetMusicVolume 277
#define FN_SetMusicPosition 278
#define SETMUSICPOSITION_POS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetMusicPosition 279
#define FN_RewindMusic 280
#define FN_SetSoundChannels 281
#define SETSOUNDCHANNELS_MAX_CHANNELS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumSoundChannels 282
#define FN_SoundIsEnabled 283
#define FN_SoundExists 284
#define SOUNDEXISTS_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetChannelVolume 285
#define SETCHANNELVOLUME_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCHANNELVOLUME_VOL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetChannelVolume 286
#define GETCHANNELVOLUME_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSoundVolume 287
#define SETSOUNDVOLUME_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSOUNDVOLUME_VOL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSoundVolume 288
#define GETSOUNDVOLUME_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_StopMusic 289
#define FN_StopSound 290
#define STOPSOUND_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetChannelPanning 291
#define SETCHANNELPANNING_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCHANNELPANNING_LEFT_VALUE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCHANNELPANNING_RIGHT_VALUE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetChannelDistance 292
#define SETCHANNELDISTANCE_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCHANNELDISTANCE_DIST_VALUE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ChannelIsPlaying 293
#define CHANNELISPLAYING_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ChannelIsPaused 294
#define CHANNELISPAUSED_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_QueryAudioSpec 295
#define QUERYAUDIOSPEC_FREQ num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define QUERYAUDIOSPEC_FORMAT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define QUERYAUDIOSPEC_CHANNELS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_MusicIsPlaying 296
#define FN_SetChannelSpacePosition 297
#define SETCHANNELSPACEPOSITION_CHANNEL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCHANNELSPACEPOSITION_ANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCHANNELSPACEPOSITION_DISTANCE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_NumJoysticks 298
#define FN_NumJoyAxes 299
#define NUMJOYAXES_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumJoyButtons 300
#define NUMJOYBUTTONS_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumJoyHats 301
#define NUMJOYHATS_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumJoyTrackBalls 302
#define NUMJOYTRACKBALLS_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_JoyAxis 303
#define JOYAXIS_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define JOYAXIS_JOY_AXIS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_JoyButton 304
#define JOYBUTTON_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define JOYBUTTON_JOY_BUTTON num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_JoyHat 305
#define JOYHAT_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define JOYHAT_JOY_HAT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetJoyTrackBall 306
#define GETJOYTRACKBALL_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOYTRACKBALL_BALL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOYTRACKBALL_DX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETJOYTRACKBALL_DY num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_JoyName$ 307
#define JOYNAME$_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_JoystickIsConnected 308
#define JOYSTICKISCONNECTED_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_JoyRumblePlay 309
#define JOYRUMBLEPLAY_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define JOYRUMBLEPLAY_STRENGTH num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define JOYRUMBLEPLAY_DURATION num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_JoyRumbleStop 310
#define JOYRUMBLESTOP_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_JoystickIsHaptic 311
#define JOYSTICKISHAPTIC_JOY_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_LoadFont 312
#define LOADFONT_FNT_FILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define LOADFONT_FONT_SIZE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteFont 313
#define DELETEFONT_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_FontExists 314
#define FONTEXISTS_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetFont 315
#define SETFONT_SLOT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DrawText 316
#define DRAWTEXT_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define DRAWTEXT_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWTEXT_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetTextSize 317
#define GETTEXTSIZE_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define GETTEXTSIZE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTEXTSIZE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_TextWidth 318
#define TEXTWIDTH_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_TextHeight 319
#define TEXTHEIGHT_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_TouchPressure 320
#define FN_GetTouch 321
#define GETTOUCH_STATUS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTOUCH_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTOUCH_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETTOUCH_DX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETTOUCH_DY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_GetMultiTouch 322
#define GETMULTITOUCH_STATUS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMULTITOUCH_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMULTITOUCH_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETMULTITOUCH_FINGERS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETMULTITOUCH_DIST num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETMULTITOUCH_THETA num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_GetTouchFinger 323
#define GETTOUCHFINGER_FINGER num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTOUCHFINGER_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTOUCHFINGER_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETTOUCHFINGER_PRESSURE num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_NumFingers 324
#define FN_GetAccel 325
#define GETACCEL_ACCEL_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACCEL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACCEL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACCEL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_AccelName$ 326
#define ACCELNAME$_ACCEL_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumAccels 327
#define FN_GetGyro 328
#define GETGYRO_GYRO_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETGYRO_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETGYRO_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETGYRO_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GyroName$ 329
#define GYRONAME$_GYRO_NUM num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumGyros 330
#define FN_CheckSockets 331
#define CHECKSOCKETS_TIMEOUT_MS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TCP_SocketReady 332
#define TCP_SOCKETREADY_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_UDP_SocketReady 333
#define UDP_SOCKETREADY_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TCP_OpenSocket 334
#define TCP_OPENSOCKET_HOST$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define TCP_OPENSOCKET_PORT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TCP_CloseSocket 335
#define TCP_CLOSESOCKET_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TCP_RemoteHost 336
#define TCP_REMOTEHOST_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TCP_RemotePort 337
#define TCP_REMOTEPORT_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_TCP_GetData 338
#define TCP_GETDATA_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TCP_GETDATA_NUMBYTES num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define TCP_GETDATA_SDATA$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_TCP_SendData 339
#define TCP_SENDDATA_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TCP_SENDDATA_SDATA$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_TCP_AcceptSocket 340
#define TCP_ACCEPTSOCKET_SERVER num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TCP_ACCEPTSOCKET_CLIENT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_UDP_OpenSocket 341
#define UDP_OPENSOCKET_PORT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_UDP_CloseSocket 342
#define UDP_CLOSESOCKET_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_UDP_GetData 343
#define UDP_GETDATA_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define UDP_GETDATA_HOST$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define UDP_GETDATA_PORT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define UDP_GETDATA_SDATA$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_UDP_Length 344
#define FN_UDP_MaxLength 345
#define FN_UDP_RemoteHost$ 346
#define UDP_REMOTEHOST$_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_UDP_RemotePort 347
#define UDP_REMOTEPORT_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_UDP_SendData 348
#define UDP_SENDDATA_SOCKET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define UDP_SENDDATA_HOST$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define UDP_SENDDATA_PORT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define UDP_SENDDATA_SDATA$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_LoadVideo 349
#define LOADVIDEO_VID$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_PlayVideo 350
#define PLAYVIDEO_VLOOPS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_PauseVideo 351
#define FN_StopVideo 352
#define FN_SetVideoPosition 353
#define SETVIDEOPOSITION_POS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ResumeVideo 354
#define FN_GetVideoPosition 355
#define FN_DeleteVideo 356
#define FN_VideoIsPlaying 357
#define FN_VideoEnd 358
#define FN_GetVideoStats 359
#define GETVIDEOSTATS_VFILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define GETVIDEOSTATS_VLEN num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETVIDEOSTATS_VFPS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETVIDEOSTATS_FRAME_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETVIDEOSTATS_FRAME_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetVideoDrawRect 360
#define SETVIDEODRAWRECT_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETVIDEODRAWRECT_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETVIDEODRAWRECT_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETVIDEODRAWRECT_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetVideoDrawRect 361
#define GETVIDEODRAWRECT_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETVIDEODRAWRECT_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETVIDEODRAWRECT_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETVIDEODRAWRECT_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetVideoSize 362
#define GETVIDEOSIZE_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETVIDEOSIZE_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_VideoExists 363
#define FN_SetVideoVolume 364
#define SETVIDEOVOLUME_VOL num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetVideoVolume 365
#define FN_System 366
#define SYSTEM_CMD$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_OS$ 367
#define FN_Command$ 368
#define COMMAND$_ARG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumCommands 369
#define FN_Env$ 370
#define ENV$_V$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_SetEnv 371
#define SETENV_VAR$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define SETENV_VALUE$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_PrefPath$ 372
#define PREFPATH$_ORG_NAME$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define PREFPATH$_APP_NAME$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_Android_GetExternalStoragePath$ 373
#define FN_Android_GetExternalStorageState 374
#define FN_Android_GetInternalStoragePath$ 375
#define FN_Android_JNI_Message$ 376
#define ANDROID_JNI_MESSAGE$_ARG$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_Runtime_Utility_Message$ 377
#define RUNTIME_UTILITY_MESSAGE$_ARG$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_GetDesktopDisplayMode 378
#define GETDESKTOPDISPLAYMODE_INDEX num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETDESKTOPDISPLAYMODE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETDESKTOPDISPLAYMODE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETDESKTOPDISPLAYMODE_FREQ num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetPowerInfo 379
#define GETPOWERINFO_STATUS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPOWERINFO_SECS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPOWERINFO_PCT num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_EvalJS$ 380
#define EVALJS$_JS_CODE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_SystemReturnStdOut$ 381
#define SYSTEMRETURNSTDOUT$_CMD$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_OpenURL 382
#define OPENURL_URL$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_MessageBox 383
#define MESSAGEBOX_TITLE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define MESSAGEBOX_MSG$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_Runtime$ 384
#define FN_NumCPUs 385
#define FN_SystemRam 386
#define FN_DimMatrix 387
#define DIMMATRIX_M_ROWS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DIMMATRIX_M_COLS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_DeleteMatrix 388
#define DELETEMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_AddMatrix 389
#define ADDMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ADDMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ADDMATRIX_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_AugmentMatrix 390
#define AUGMENTMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define AUGMENTMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define AUGMENTMATRIX_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_CopyMatrix 391
#define COPYMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COPYMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_InsertMatrixColumns 392
#define INSERTMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define INSERTMATRIXCOLUMNS_C num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define INSERTMATRIXCOLUMNS_NUM_COLS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_InsertMatrixRows 393
#define INSERTMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define INSERTMATRIXROWS_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define INSERTMATRIXROWS_NUM_ROWS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_MultiplyMatrix 394
#define MULTIPLYMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define MULTIPLYMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define MULTIPLYMATRIX_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_CubeMatrix 395
#define CUBEMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CUBEMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_DeleteMatrixColumns 396
#define DELETEMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DELETEMATRIXCOLUMNS_C num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DELETEMATRIXCOLUMNS_NUM_COLS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_DeleteMatrixRows 397
#define DELETEMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DELETEMATRIXROWS_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DELETEMATRIXROWS_NUM_ROWS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ClearMatrix 398
#define CLEARMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ClearMatrixColumns 399
#define CLEARMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CLEARMATRIXCOLUMNS_C num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CLEARMATRIXCOLUMNS_NUM_COLS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ClearMatrixRows 400
#define CLEARMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CLEARMATRIXROWS_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CLEARMATRIXROWS_NUM_ROWS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_FillMatrix 401
#define FILLMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FILLMATRIX_V num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_FillMatrixColumns 402
#define FILLMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FILLMATRIXCOLUMNS_C num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FILLMATRIXCOLUMNS_NUM_COLS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FILLMATRIXCOLUMNS_V num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_FillMatrixRows 403
#define FILLMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FILLMATRIXROWS_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FILLMATRIXROWS_NUM_ROWS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FILLMATRIXROWS_V num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_CopyMatrixColumns 404
#define COPYMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COPYMATRIXCOLUMNS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COPYMATRIXCOLUMNS_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define COPYMATRIXCOLUMNS_NUM_COLS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_CopyMatrixRows 405
#define COPYMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COPYMATRIXROWS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COPYMATRIXROWS_R num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define COPYMATRIXROWS_NUM_ROWS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetIdentityMatrix 406
#define SETIDENTITYMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETIDENTITYMATRIX_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SolveMatrix 407
#define SOLVEMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SOLVEMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SOLVEMATRIX_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_IsEqualMatrix 408
#define ISEQUALMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ISEQUALMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ISEQUALMATRIX_TOLERANCE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_Determinant 409
#define DETERMINANT_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_AdjointMatrix 410
#define ADJOINTMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ADJOINTMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_InvertMatrix 411
#define INVERTMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define INVERTMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_MatrixFromBuffer 412
#define MATRIXFROMBUFFER_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define MATRIXFROMBUFFER_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define MATRIXFROMBUFFER_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define MATRIXFROMBUFFER_BUFFER num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_BufferFromMatrix 413
#define BUFFERFROMMATRIX_BUFFER num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define BUFFERFROMMATRIX_MA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_RandomizeMatrix 414
#define RANDOMIZEMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define RANDOMIZEMATRIX_VMIN num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define RANDOMIZEMATRIX_VMAX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_MatrixValue 415
#define MATRIXVALUE_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define MATRIXVALUE_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define MATRIXVALUE_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetMatrixValue 416
#define SETMATRIXVALUE_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATRIXVALUE_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATRIXVALUE_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETMATRIXVALUE_V num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_ScalarMatrix 417
#define SCALARMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SCALARMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SCALARMATRIX_S_VALUE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ScalarMatrixColumns 418
#define SCALARMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SCALARMATRIXCOLUMNS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SCALARMATRIXCOLUMNS_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SCALARMATRIXCOLUMNS_NUM_COLS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SCALARMATRIXCOLUMNS_S_VALUE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_ScalarMatrixRows 419
#define SCALARMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SCALARMATRIXROWS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SCALARMATRIXROWS_R num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SCALARMATRIXROWS_NUM_ROWS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SCALARMATRIXROWS_S_VALUE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_SquareMatrix 420
#define SQUAREMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SQUAREMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_CofactorMatrix 421
#define COFACTORMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COFACTORMATRIX_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COFACTORMATRIX_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SubtractMatrix 422
#define SUBTRACTMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SUBTRACTMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SUBTRACTMATRIX_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SwapMatrix 423
#define SWAPMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SWAPMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SwapMatrixColumn 424
#define SWAPMATRIXCOLUMN_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SWAPMATRIXCOLUMN_C1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SWAPMATRIXCOLUMN_C2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SwapMatrixRow 425
#define SWAPMATRIXROW_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SWAPMATRIXROW_R1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SWAPMATRIXROW_R2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_TransposeMatrix 426
#define TRANSPOSEMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TRANSPOSEMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_UnAugmentMatrix 427
#define UNAUGMENTMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define UNAUGMENTMATRIX_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define UNAUGMENTMATRIX_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ZeroMatrix 428
#define ZEROMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetMatrixSize 429
#define GETMATRIXSIZE_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMATRIXSIZE_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMATRIXSIZE_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_IncrementMatrixRows 430
#define INCREMENTMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define INCREMENTMATRIXROWS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define INCREMENTMATRIXROWS_R num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define INCREMENTMATRIXROWS_NUM_ROWS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define INCREMENTMATRIXROWS_VALUE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_IncrementMatrixColumns 431
#define INCREMENTMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define INCREMENTMATRIXCOLUMNS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define INCREMENTMATRIXCOLUMNS_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define INCREMENTMATRIXCOLUMNS_NUM_COLS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define INCREMENTMATRIXCOLUMNS_VALUE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_JoinMatrixRows 432
#define JOINMATRIXROWS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define JOINMATRIXROWS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define JOINMATRIXROWS_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_JoinMatrixColumns 433
#define JOINMATRIXCOLUMNS_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define JOINMATRIXCOLUMNS_MB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define JOINMATRIXCOLUMNS_MC num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ClipMatrix 434
#define CLIPMATRIX_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CLIPMATRIX_R num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CLIPMATRIX_C num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CLIPMATRIX_NUM_ROWS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CLIPMATRIX_NUM_COLS num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CLIPMATRIX_MB num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_SetMatrixTranslation 435
#define SETMATRIXTRANSLATION_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATRIXTRANSLATION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATRIXTRANSLATION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETMATRIXTRANSLATION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetMatrixRotation 436
#define SETMATRIXROTATION_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATRIXROTATION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATRIXROTATION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETMATRIXROTATION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetMatrixScale 437
#define SETMATRIXSCALE_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATRIXSCALE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATRIXSCALE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETMATRIXSCALE_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetMatrixTranslation 438
#define GETMATRIXTRANSLATION_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMATRIXTRANSLATION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMATRIXTRANSLATION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETMATRIXTRANSLATION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetMatrixRotation 439
#define GETMATRIXROTATION_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMATRIXROTATION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMATRIXROTATION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETMATRIXROTATION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetMatrixScale 440
#define GETMATRIXSCALE_MA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMATRIXSCALE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETMATRIXSCALE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETMATRIXSCALE_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetClipboardText$ 441
#define FN_SetClipboardText 442
#define SETCLIPBOARDTEXT_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_HasClipboardText 443
#define FN_ReadInput_Start 444
#define FN_ReadInput_Stop 445
#define FN_ReadInput_Text$ 446
#define FN_ReadInput_SetText 447
#define READINPUT_SETTEXT_TXT$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_ReadInput_ToggleBackspace 448
#define READINPUT_TOGGLEBACKSPACE_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateSprite 449
#define CREATESPRITE_IMG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATESPRITE_FRAME_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATESPRITE_FRAME_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_DeleteSprite 450
#define DELETESPRITE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpritePosition 451
#define SETSPRITEPOSITION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEPOSITION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITEPOSITION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_TranslateSprite 452
#define TRANSLATESPRITE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TRANSLATESPRITE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define TRANSLATESPRITE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetSpritePosition 453
#define GETSPRITEPOSITION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEPOSITION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITEPOSITION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SpriteX 454
#define SPRITEX_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SpriteY 455
#define SPRITEY_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteRotation 456
#define SETSPRITEROTATION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEROTATION_ANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_RotateSprite 457
#define ROTATESPRITE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ROTATESPRITE_ANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteRotation 458
#define GETSPRITEROTATION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteScale 459
#define SETSPRITESCALE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITESCALE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITESCALE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ScaleSprite 460
#define SCALESPRITE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SCALESPRITE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SCALESPRITE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetSpriteScale 461
#define GETSPRITESCALE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITESCALE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITESCALE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetSpriteZ 462
#define SETSPRITEZ_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEZ_Z num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SpriteZ 463
#define SPRITEZ_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetSpriteSize 464
#define GETSPRITESIZE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITESIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITESIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SpriteWidth 465
#define SPRITEWIDTH_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SpriteHeight 466
#define SPRITEHEIGHT_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteVisible 467
#define SETSPRITEVISIBLE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEVISIBLE_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SpriteIsVisible 468
#define SPRITEISVISIBLE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteSolid 469
#define SETSPRITESOLID_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITESOLID_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SpriteIsSolid 470
#define SPRITEISSOLID_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteType 471
#define SETSPRITETYPE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITETYPE_SPRITE_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteType 472
#define GETSPRITETYPE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteSource 473
#define SETSPRITESOURCE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITESOURCE_IMG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteSource 474
#define GETSPRITESOURCE_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateSpriteAnimation 475
#define CREATESPRITEANIMATION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATESPRITEANIMATION_ANIM_LENGTH num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATESPRITEANIMATION_SPEED num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetSpriteFrame 476
#define SETSPRITEFRAME_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEFRAME_FRAME num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteFrame 477
#define GETSPRITEFRAME_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteAnimationFrame 478
#define SETSPRITEANIMATIONFRAME_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEANIMATIONFRAME_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITEANIMATIONFRAME_ANIM_FRAME num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETSPRITEANIMATIONFRAME_FRAME num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetSpriteAnimationFrame 479
#define GETSPRITEANIMATIONFRAME_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEANIMATIONFRAME_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITEANIMATIONFRAME_ANIM_FRAME num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetSpriteAnimationLength 480
#define SETSPRITEANIMATIONLENGTH_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEANIMATIONLENGTH_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITEANIMATIONLENGTH_ANIM_LENGTH num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetSpriteAnimationLength 481
#define GETSPRITEANIMATIONLENGTH_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEANIMATIONLENGTH_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetSpriteAnimationSpeed 482
#define SETSPRITEANIMATIONSPEED_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEANIMATIONSPEED_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITEANIMATIONSPEED_SPEED num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetSpriteAnimationSpeed 483
#define GETSPRITEANIMATIONSPEED_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEANIMATIONSPEED_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetSpriteAnimation 484
#define SETSPRITEANIMATION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEANIMATION_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITEANIMATION_NUM_LOOPS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetSpriteAnimation 485
#define GETSPRITEANIMATION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetSpriteCurrentAnimationFrame 486
#define GETSPRITECURRENTANIMATIONFRAME_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumSpriteAnimationLoops 487
#define NUMSPRITEANIMATIONLOOPS_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SpriteAnimationIsPlaying 488
#define SPRITEANIMATIONISPLAYING_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteSpriteAnimation 489
#define DELETESPRITEANIMATION_SPRITE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DELETESPRITEANIMATION_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getSpriteCenter 490
#define GETSPRITECENTER_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITECENTER_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITECENTER_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setSpriteLinearVelocity 491
#define SETSPRITELINEARVELOCITY_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITELINEARVELOCITY_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETSPRITELINEARVELOCITY_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getSpriteLinearVelocity 492
#define GETSPRITELINEARVELOCITY_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITELINEARVELOCITY_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITELINEARVELOCITY_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setSpriteAngularVelocity 493
#define SETSPRITEANGULARVELOCITY_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEANGULARVELOCITY_AV num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getSpriteAngularVelocity 494
#define GETSPRITEANGULARVELOCITY_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_applySpriteForce 495
#define APPLYSPRITEFORCE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYSPRITEFORCE_FX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYSPRITEFORCE_FY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYSPRITEFORCE_PX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define APPLYSPRITEFORCE_PY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_applySpriteCentralForce 496
#define APPLYSPRITECENTRALFORCE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYSPRITECENTRALFORCE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYSPRITECENTRALFORCE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_applySpriteTorque 497
#define APPLYSPRITETORQUE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYSPRITETORQUE_TORQUE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_applySpriteLinearImpulse 498
#define APPLYSPRITELINEARIMPULSE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYSPRITELINEARIMPULSE_IX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYSPRITELINEARIMPULSE_IY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYSPRITELINEARIMPULSE_PX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define APPLYSPRITELINEARIMPULSE_PY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_applySpriteAngularImpulse 499
#define APPLYSPRITEANGULARIMPULSE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYSPRITEANGULARIMPULSE_IMPULSE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getSpriteMass 500
#define GETSPRITEMASS_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSpriteInertia 501
#define GETSPRITEINERTIA_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSpriteWorldPoint 502
#define GETSPRITEWORLDPOINT_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEWORLDPOINT_LX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITEWORLDPOINT_LY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITEWORLDPOINT_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITEWORLDPOINT_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getSpriteWorldVector 503
#define GETSPRITEWORLDVECTOR_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEWORLDVECTOR_LX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITEWORLDVECTOR_LY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITEWORLDVECTOR_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITEWORLDVECTOR_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getSpriteLocalPoint 504
#define GETSPRITELOCALPOINT_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITELOCALPOINT_WX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITELOCALPOINT_WY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITELOCALPOINT_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITELOCALPOINT_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getSpriteLocalVector 505
#define GETSPRITELOCALVECTOR_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITELOCALVECTOR_WX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITELOCALVECTOR_WY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITELOCALVECTOR_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITELOCALVECTOR_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getSpriteLinearVelocityFromLocalPoint 506
#define GETSPRITELINEARVELOCITYFROMLOCALPOINT_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMLOCALPOINT_PX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMLOCALPOINT_PY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMLOCALPOINT_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMLOCALPOINT_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getSpriteLinearVelocityFromWorldPoint 507
#define GETSPRITELINEARVELOCITYFROMWORLDPOINT_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMWORLDPOINT_WX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMWORLDPOINT_WY num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMWORLDPOINT_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITELINEARVELOCITYFROMWORLDPOINT_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getSpriteLinearDamping 508
#define GETSPRITELINEARDAMPING_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSpriteLinearDamping 509
#define SETSPRITELINEARDAMPING_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITELINEARDAMPING_LINEARDAMPING num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getSpriteAngularDamping 510
#define GETSPRITEANGULARDAMPING_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSpriteAngularDamping 511
#define SETSPRITEANGULARDAMPING_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEANGULARDAMPING_ANGULARDAMPING num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getSpriteGravityScale 512
#define GETSPRITEGRAVITYSCALE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSpriteGravityScale 513
#define SETSPRITEGRAVITYSCALE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEGRAVITYSCALE_G_SCALE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSpriteBullet 514
#define SETSPRITEBULLET_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEBULLET_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_spriteIsBullet 515
#define SPRITEISBULLET_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSpriteSleepAllowed 516
#define SETSPRITESLEEPALLOWED_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITESLEEPALLOWED_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_spriteSleepAllowed 517
#define SPRITESLEEPALLOWED_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSpriteAwake 518
#define SETSPRITEAWAKE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEAWAKE_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_spriteIsAwake 519
#define SPRITEISAWAKE_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSpriteFixedRotation 520
#define SETSPRITEFIXEDROTATION_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEFIXEDROTATION_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_spriteIsFixedRotation 521
#define SPRITEISFIXEDROTATION_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteDensity 522
#define SETSPRITEDENSITY_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEDENSITY_DENSITY num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteDensity 523
#define GETSPRITEDENSITY_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteFriction 524
#define SETSPRITEFRICTION_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITEFRICTION_FRICTION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteFriction 525
#define GETSPRITEFRICTION_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteRestitution 526
#define SETSPRITERESTITUTION_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITERESTITUTION_RESTITUTION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteRestitution 527
#define GETSPRITERESTITUTION_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetSpriteRestitutionThreshold 528
#define SETSPRITERESTITUTIONTHRESHOLD_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSPRITERESTITUTIONTHRESHOLD_THRESHOLD num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetSpriteRestitutionThreshold 529
#define GETSPRITERESTITUTIONTHRESHOLD_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetSpriteAABB 530
#define GETSPRITEAABB_SPR_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSPRITEAABB_X1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSPRITEAABB_Y1 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSPRITEAABB_X2 num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETSPRITEAABB_Y2 num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_SetGravity2D 531
#define SETGRAVITY2D_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETGRAVITY2D_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetGravity2D 532
#define GETGRAVITY2D_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETGRAVITY2D_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetWorld2DTimeStep 533
#define SETWORLD2DTIMESTEP_TS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetWorld2DVelocityIterations 534
#define SETWORLD2DVELOCITYITERATIONS_V num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetWorld2DPositionIterations 535
#define SETWORLD2DPOSITIONITERATIONS_P num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetWorld2DTimeStep 536
#define FN_GetWorld2DVelocityIterations 537
#define FN_GetWorld2DPositionIterations 538
#define FN_SetWorld2DAutoClearForces 539
#define SETWORLD2DAUTOCLEARFORCES_FLAG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetWorld2DAutoClearForces 540
#define FN_createDistanceJoint 541
#define CREATEDISTANCEJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEDISTANCEJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEDISTANCEJOINT_AX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEDISTANCEJOINT_AY num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEDISTANCEJOINT_BX num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CREATEDISTANCEJOINT_BY num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define CREATEDISTANCEJOINT_COLLIDE_CONNECT num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_createFrictionJoint 542
#define CREATEFRICTIONJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEFRICTIONJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEFRICTIONJOINT_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEFRICTIONJOINT_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEFRICTIONJOINT_COLLIDE_CONNECT num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_createGearJoint 543
#define CREATEGEARJOINT_JOINTA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEGEARJOINT_JOINTB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEGEARJOINT_G_RATIO num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEGEARJOINT_COLLIDE_CONNECT num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_createMotorJoint 544
#define CREATEMOTORJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEMOTORJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEMOTORJOINT_COLLIDE_CONNECT num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_createPrismaticJoint 545
#define CREATEPRISMATICJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEPRISMATICJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEPRISMATICJOINT_AX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEPRISMATICJOINT_AY num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEPRISMATICJOINT_AXISX num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CREATEPRISMATICJOINT_AXISY num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define CREATEPRISMATICJOINT_COLLIDE_CONNECT num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_createPulleyJoint 546
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
#define FN_createRevoluteJoint 547
#define CREATEREVOLUTEJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEREVOLUTEJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEREVOLUTEJOINT_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEREVOLUTEJOINT_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEREVOLUTEJOINT_COLLIDE_CONNECT num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_createWeldJoint 548
#define CREATEWELDJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEWELDJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEWELDJOINT_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEWELDJOINT_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEWELDJOINT_COLLIDE_CONNECT num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_createWheelJoint 549
#define CREATEWHEELJOINT_SPRITEA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEWHEELJOINT_SPRITEB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEWHEELJOINT_AX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEWHEELJOINT_AY num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEWHEELJOINT_AXISX num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CREATEWHEELJOINT_AXISY num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define CREATEWHEELJOINT_COLLIDE_CONNECT num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_getJointWorldAnchorA 550
#define GETJOINTWORLDANCHORA_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTWORLDANCHORA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTWORLDANCHORA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointWorldAnchorB 551
#define GETJOINTWORLDANCHORB_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTWORLDANCHORB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTWORLDANCHORB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointReactionForce 552
#define GETJOINTREACTIONFORCE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTREACTIONFORCE_INV_DT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTREACTIONFORCE_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETJOINTREACTIONFORCE_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getJointReactionTorque 553
#define GETJOINTREACTIONTORQUE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTREACTIONTORQUE_INV_DT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointLocalAnchorA 554
#define GETJOINTLOCALANCHORA_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTLOCALANCHORA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTLOCALANCHORA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointLocalAnchorB 555
#define GETJOINTLOCALANCHORB_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTLOCALANCHORB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTLOCALANCHORB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setJointLength 556
#define SETJOINTLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTLENGTH_JLEN num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointLength 557
#define GETJOINTLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointMinLength 558
#define SETJOINTMINLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMINLENGTH_JLEN num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMinLength 559
#define GETJOINTMINLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointMaxLength 560
#define SETJOINTMAXLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMAXLENGTH_JLEN num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMaxLength 561
#define GETJOINTMAXLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointCurrentLength 562
#define GETJOINTCURRENTLENGTH_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointStiffness 563
#define SETJOINTSTIFFNESS_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTSTIFFNESS_STIFFNESS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointStiffness 564
#define GETJOINTSTIFFNESS_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointDamping 565
#define SETJOINTDAMPING_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTDAMPING_DAMPING num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointDamping 566
#define GETJOINTDAMPING_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointMaxForce 567
#define SETJOINTMAXFORCE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMAXFORCE_FORCE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMaxForce 568
#define GETJOINTMAXFORCE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointMaxTorque 569
#define SETJOINTMAXTORQUE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMAXTORQUE_TORQUE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMaxTorque 570
#define GETJOINTMAXTORQUE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointCorrectionFactor 571
#define SETJOINTCORRECTIONFACTOR_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTCORRECTIONFACTOR_FACTOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointCorrectionFactor 572
#define GETJOINTCORRECTIONFACTOR_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointRatio 573
#define SETJOINTRATIO_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTRATIO_J_RATIO num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointRatio 574
#define GETJOINTRATIO_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointLinearOffset 575
#define SETJOINTLINEAROFFSET_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTLINEAROFFSET_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETJOINTLINEAROFFSET_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointLinearOffset 576
#define GETJOINTLINEAROFFSET_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTLINEAROFFSET_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTLINEAROFFSET_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setJointAngularOffset 577
#define SETJOINTANGULAROFFSET_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTANGULAROFFSET_ANGLEOFFSET num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointAngularOffset 578
#define GETJOINTANGULAROFFSET_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointLocalAxisA 579
#define GETJOINTLOCALAXISA_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTLOCALAXISA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTLOCALAXISA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointReferenceAngle 580
#define GETJOINTREFERENCEANGLE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointTranslation 581
#define GETJOINTTRANSLATION_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointSpeed 582
#define GETJOINTSPEED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_jointIsLimitEnabled 583
#define JOINTISLIMITENABLED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_enableJointLimit 584
#define ENABLEJOINTLIMIT_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ENABLEJOINTLIMIT_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointLowerLimit 585
#define GETJOINTLOWERLIMIT_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointUpperLimit 586
#define GETJOINTUPPERLIMIT_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointLimits 587
#define SETJOINTLIMITS_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTLIMITS_LOWER_LIMIT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETJOINTLIMITS_UPPER_LIMIT num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_jointMotorIsEnabled 588
#define JOINTMOTORISENABLED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_enableJointMotor 589
#define ENABLEJOINTMOTOR_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ENABLEJOINTMOTOR_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setJointMotorSpeed 590
#define SETJOINTMOTORSPEED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMOTORSPEED_SPEED num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMotorSpeed 591
#define GETJOINTMOTORSPEED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointMaxMotorForce 592
#define SETJOINTMAXMOTORFORCE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMAXMOTORFORCE_FORCE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMaxMotorForce 593
#define GETJOINTMAXMOTORFORCE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointMotorForce 594
#define GETJOINTMOTORFORCE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTMOTORFORCE_INV_DT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setJointMaxMotorTorque 595
#define SETJOINTMAXMOTORTORQUE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTMAXMOTORTORQUE_TORQUE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointMaxMotorTorque 596
#define GETJOINTMAXMOTORTORQUE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointMotorTorque 597
#define GETJOINTMOTORTORQUE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTMOTORTORQUE_INV_DT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getJointGroundAnchorA 598
#define GETJOINTGROUNDANCHORA_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTGROUNDANCHORA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTGROUNDANCHORA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointGroundAnchorB 599
#define GETJOINTGROUNDANCHORB_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETJOINTGROUNDANCHORB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETJOINTGROUNDANCHORB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointLengthA 600
#define GETJOINTLENGTHA_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointLengthB 601
#define GETJOINTLENGTHB_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointCurrentLengthA 602
#define GETJOINTCURRENTLENGTHA_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointCurrentLengthB 603
#define GETJOINTCURRENTLENGTHB_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setJointOrigin 604
#define SETJOINTORIGIN_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETJOINTORIGIN_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETJOINTORIGIN_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getJointAngle 605
#define GETJOINTANGLE_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointLinearSpeed 606
#define GETJOINTLINEARSPEED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getJointAngularSpeed 607
#define GETJOINTANGULARSPEED_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteJoint 608
#define DELETEJOINT_JOINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateTileSet 609
#define CREATETILESET_IMG_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATETILESET_TILE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATETILESET_TILE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetTileAnimationLength 610
#define SETTILEANIMATIONLENGTH_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTILEANIMATIONLENGTH_BASE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTILEANIMATIONLENGTH_NUM_FRAMES num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetTileAnimationLength 611
#define GETTILEANIMATIONLENGTH_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTILEANIMATIONLENGTH_BASE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetTileAnimationFrame 612
#define SETTILEANIMATIONFRAME_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTILEANIMATIONFRAME_BASE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTILEANIMATIONFRAME_ANIM_FRAME num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETTILEANIMATIONFRAME_TILE_FRAME num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetTileAnimationFrame 613
#define GETTILEANIMATIONFRAME_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTILEANIMATIONFRAME_BASE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTILEANIMATIONFRAME_ANIM_FRAME num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetTileAnimationSpeed 614
#define SETTILEANIMATIONSPEED_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTILEANIMATIONSPEED_BASE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTILEANIMATIONSPEED_SPEED num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetTileAnimationSpeed 615
#define GETTILEANIMATIONSPEED_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTILEANIMATIONSPEED_BASE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_CreateTileMap 616
#define CREATETILEMAP_TILESET num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATETILEMAP_WIDTHINTILES num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATETILEMAP_HEIGHTINTILES num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetTileMapSize 617
#define SETTILEMAPSIZE_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTILEMAPSIZE_WIDTHINTILES num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTILEMAPSIZE_HEIGHTINTILES num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetTileMapSize 618
#define GETTILEMAPSIZE_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTILEMAPSIZE_WIDTHINTILES num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTILEMAPSIZE_HEIGHTINTILES num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetTile 619
#define SETTILE_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTILE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTILE_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETTILE_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetTile 620
#define GETTILE_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTILE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTILE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_FillTile 621
#define FILLTILE_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FILLTILE_TILE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FILLTILE_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FILLTILE_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FILLTILE_WIDTHINTILES num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FILLTILE_HEIGHTINTILES num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_DrawTileMap 622
#define DRAWTILEMAP_TILEMAP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DRAWTILEMAP_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define DRAWTILEMAP_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define DRAWTILEMAP_W num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define DRAWTILEMAP_H num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define DRAWTILEMAP_OFFSET_X num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define DRAWTILEMAP_OFFSET_Y num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_LoadMesh 623
#define LOADMESH_MESH_FILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_DeleteMesh 624
#define DELETEMESH_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateMesh 625
#define FN_AddMeshBuffer 626
#define ADDMESHBUFFER_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ADDMESHBUFFER_VERTEX_COUNT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ADDMESHBUFFER_VERTEX_DATA num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define ADDMESHBUFFER_NORMAL_DATA num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define ADDMESHBUFFER_UV_DATA num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define ADDMESHBUFFER_INDEX_COUNT num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define ADDMESHBUFFER_INDEX_DATA num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_LoadMeshFromArchive 627
#define LOADMESHFROMARCHIVE_ARCHIVE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define LOADMESHFROMARCHIVE_MESH_FILE$ str_var[1].sref[0].value[ str_var[1].byref_offset ]
#define FN_CreatePlaneMesh 628
#define CREATEPLANEMESH_W num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEPLANEMESH_H num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEPLANEMESH_TILECOUNT_W num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEPLANEMESH_TILECOUNT_H num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_LoadAN8 629
#define LOADAN8_AN8_FILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_LoadMeshFromAN8 630
#define LOADMESHFROMAN8_AN8_PROJECT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define LOADMESHFROMAN8_AN8_SCENE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_GetNumAN8Scenes 631
#define GETNUMAN8SCENES_AN8_PROJECT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetAN8SceneName$ 632
#define GETAN8SCENENAME$_AN8_PROJECT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETAN8SCENENAME$_SCENE_NUM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_CreateAnimatedActor 633
#define CREATEANIMATEDACTOR_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateOctreeActor 634
#define CREATEOCTREEACTOR_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateCubeActor 635
#define CREATECUBEACTOR_CUBE_SIZE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateSphereActor 636
#define CREATESPHEREACTOR_RADIUS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateWaterActor 637
#define CREATEWATERACTOR_MESH num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEWATERACTOR_WAVEHEIGHT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEWATERACTOR_WAVESPEED num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEWATERACTOR_WAVELENGTH num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_CreateLightActor 638
#define FN_CreateBillboardActor 639
#define FN_CreateTerrainActor 640
#define CREATETERRAINACTOR_HMAP_FILE$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define FN_CreateParticleActor 641
#define CREATEPARTICLEACTOR_PARTICLE_TYPE num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_DeleteActor 642
#define DELETEACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetActorTransform 643
#define GETACTORTRANSFORM_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORTRANSFORM_MATRIX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetActorPosition 644
#define SETACTORPOSITION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORPOSITION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORPOSITION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORPOSITION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_TranslateActorLocal 645
#define TRANSLATEACTORLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TRANSLATEACTORLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define TRANSLATEACTORLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define TRANSLATEACTORLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_TranslateActorWorld 646
#define TRANSLATEACTORWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TRANSLATEACTORWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define TRANSLATEACTORWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define TRANSLATEACTORWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetActorPosition 647
#define GETACTORPOSITION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORPOSITION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORPOSITION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORPOSITION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetActorScale 648
#define SETACTORSCALE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORSCALE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORSCALE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORSCALE_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_ScaleActor 649
#define SCALEACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SCALEACTOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SCALEACTOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SCALEACTOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetActorScale 650
#define GETACTORSCALE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORSCALE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORSCALE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORSCALE_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetActorRotation 651
#define SETACTORROTATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORROTATION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORROTATION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORROTATION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_RotateActor 652
#define ROTATEACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ROTATEACTOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ROTATEACTOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define ROTATEACTOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetActorRotation 653
#define GETACTORROTATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORROTATION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORROTATION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORROTATION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetActorVisible 654
#define SETACTORVISIBLE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORVISIBLE_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ActorIsVisible 655
#define ACTORISVISIBLE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetActorAutoCulling 656
#define SETACTORAUTOCULLING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORAUTOCULLING_CULL_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetActorAutoCulling 657
#define GETACTORAUTOCULLING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_AddActorShadow 658
#define ADDACTORSHADOW_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_RemoveActorShadow 659
#define REMOVEACTORSHADOW_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ActorExists 660
#define ACTOREXISTS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_CreateActorAnimation 661
#define CREATEACTORANIMATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEACTORANIMATION_START_FRAME num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEACTORANIMATION_END_FRAME num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEACTORANIMATION_SPEED num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetActorAnimation 662
#define SETACTORANIMATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORANIMATION_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORANIMATION_NUM_LOOPS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetActorAnimationSpeed 663
#define SETACTORANIMATIONSPEED_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORANIMATIONSPEED_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORANIMATIONSPEED_SPEED num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetActorAnimationFrames 664
#define SETACTORANIMATIONFRAMES_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORANIMATIONFRAMES_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORANIMATIONFRAMES_START_FRAME num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORANIMATIONFRAMES_END_FRAME num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetActorCurrentAnimation 665
#define GETACTORCURRENTANIMATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetActorAnimationSpeed 666
#define GETACTORANIMATIONSPEED_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORANIMATIONSPEED_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetActorAnimationStartFrame 667
#define GETACTORANIMATIONSTARTFRAME_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORANIMATIONSTARTFRAME_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetActorAnimationEndFrame 668
#define GETACTORANIMATIONENDFRAME_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORANIMATIONENDFRAME_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetActorFrame 669
#define SETACTORFRAME_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORFRAME_FRAME num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetActorFrame 670
#define GETACTORFRAME_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_ActorAnimationIsPlaying 671
#define ACTORANIMATIONISPLAYING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_NumActorAnimationLoops 672
#define NUMACTORANIMATIONLOOPS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetActorMD2Animation 673
#define SETACTORMD2ANIMATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORMD2ANIMATION_ANIM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORMD2ANIMATION_NUM_LOOPS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetActorMD2AnimationByName 674
#define SETACTORMD2ANIMATIONBYNAME_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORMD2ANIMATIONBYNAME_ANIM_NAME$ str_var[0].sref[0].value[ str_var[0].byref_offset ]
#define SETACTORMD2ANIMATIONBYNAME_NUM_LOOPS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_DeleteActorAnimation 675
#define DELETEACTORANIMATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define DELETEACTORANIMATION_ANIMATION num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetGravity3D 676
#define SETGRAVITY3D_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETGRAVITY3D_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETGRAVITY3D_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetGravity3D 677
#define GETGRAVITY3D_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETGRAVITY3D_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETGRAVITY3D_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetActorCollisionShape 678
#define SETACTORCOLLISIONSHAPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORCOLLISIONSHAPE_SHAPE_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORCOLLISIONSHAPE_MASS num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetActorCollisionShape 679
#define GETACTORCOLLISIONSHAPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetActorSolid 680
#define SETACTORSOLID_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORSOLID_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ActorIsSolid 681
#define ACTORISSOLID_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetActorCollision 682
#define GETACTORCOLLISION_ACTOR1 num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORCOLLISION_ACTOR2 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetActorGravity 683
#define SETACTORGRAVITY_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORGRAVITY_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORGRAVITY_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORGRAVITY_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetActorGravity 684
#define GETACTORGRAVITY_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORGRAVITY_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORGRAVITY_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORGRAVITY_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorDamping 685
#define SETACTORDAMPING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORDAMPING_LIN_DAMPING num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORDAMPING_ANG_DAMPING num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getActorLinearDamping 686
#define GETACTORLINEARDAMPING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getActorAngularDamping 687
#define GETACTORANGULARDAMPING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getActorLinearSleepThreshold 688
#define GETACTORLINEARSLEEPTHRESHOLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getActorAngularSleepThreshold 689
#define GETACTORANGULARSLEEPTHRESHOLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_applyActorDamping 690
#define APPLYACTORDAMPING_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORDAMPING_TIMESTEP num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setActorMassProperties 691
#define SETACTORMASSPROPERTIES_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORMASSPROPERTIES_MASS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORMASSPROPERTIES_INERTIA_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORMASSPROPERTIES_INERTIA_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETACTORMASSPROPERTIES_INERTIA_Z num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getActorLinearFactor 692
#define GETACTORLINEARFACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORLINEARFACTOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORLINEARFACTOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORLINEARFACTOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorLinearFactor 693
#define SETACTORLINEARFACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORLINEARFACTOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORLINEARFACTOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORLINEARFACTOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorInverseMass 694
#define GETACTORINVERSEMASS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_integrateActorVelocities 695
#define INTEGRATEACTORVELOCITIES_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define INTEGRATEACTORVELOCITIES_V_STEP num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_applyActorCentralForceLocal 696
#define APPLYACTORCENTRALFORCELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORCENTRALFORCELOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORCENTRALFORCELOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORCENTRALFORCELOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorCentralForceWorld 697
#define APPLYACTORCENTRALFORCEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORCENTRALFORCEWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORCENTRALFORCEWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORCENTRALFORCEWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorTotalForce 698
#define GETACTORTOTALFORCE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORTOTALFORCE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORTOTALFORCE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORTOTALFORCE_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorTotalTorque 699
#define GETACTORTOTALTORQUE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORTOTALTORQUE_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORTOTALTORQUE_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORTOTALTORQUE_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorInverseInertiaDiagLocal 700
#define GETACTORINVERSEINERTIADIAGLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORINVERSEINERTIADIAGLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORINVERSEINERTIADIAGLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORINVERSEINERTIADIAGLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorInverseInertiaDiagLocal 701
#define SETACTORINVERSEINERTIADIAGLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORINVERSEINERTIADIAGLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORINVERSEINERTIADIAGLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORINVERSEINERTIADIAGLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorSleepThresholds 702
#define SETACTORSLEEPTHRESHOLDS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORSLEEPTHRESHOLDS_LINEAR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORSLEEPTHRESHOLDS_ANGULAR num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_applyActorTorqueLocal 703
#define APPLYACTORTORQUELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORTORQUELOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORTORQUELOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORTORQUELOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorTorqueWorld 704
#define APPLYACTORTORQUEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORTORQUEWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORTORQUEWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORTORQUEWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorForceLocal 705
#define APPLYACTORFORCELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORFORCELOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORFORCELOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORFORCELOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define APPLYACTORFORCELOCAL_REL_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define APPLYACTORFORCELOCAL_REL_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define APPLYACTORFORCELOCAL_REL_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_applyActorForceWorld 706
#define APPLYACTORFORCEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORFORCEWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORFORCEWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORFORCEWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define APPLYACTORFORCEWORLD_REL_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define APPLYACTORFORCEWORLD_REL_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define APPLYACTORFORCEWORLD_REL_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_applyActorCentralImpulseLocal 707
#define APPLYACTORCENTRALIMPULSELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORCENTRALIMPULSELOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORCENTRALIMPULSELOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORCENTRALIMPULSELOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorCentralImpulseWorld 708
#define APPLYACTORCENTRALIMPULSEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORCENTRALIMPULSEWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORCENTRALIMPULSEWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORCENTRALIMPULSEWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorTorqueImpulseLocal 709
#define APPLYACTORTORQUEIMPULSELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORTORQUEIMPULSELOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORTORQUEIMPULSELOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORTORQUEIMPULSELOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorTorqueImpulseWorld 710
#define APPLYACTORTORQUEIMPULSEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORTORQUEIMPULSEWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORTORQUEIMPULSEWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORTORQUEIMPULSEWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_applyActorImpulseLocal 711
#define APPLYACTORIMPULSELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORIMPULSELOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORIMPULSELOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORIMPULSELOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define APPLYACTORIMPULSELOCAL_REL_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define APPLYACTORIMPULSELOCAL_REL_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define APPLYACTORIMPULSELOCAL_REL_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_applyActorImpulseWorld 712
#define APPLYACTORIMPULSEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define APPLYACTORIMPULSEWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define APPLYACTORIMPULSEWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define APPLYACTORIMPULSEWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define APPLYACTORIMPULSEWORLD_REL_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define APPLYACTORIMPULSEWORLD_REL_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define APPLYACTORIMPULSEWORLD_REL_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_clearActorForces 713
#define CLEARACTORFORCES_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_updateActorInertiaTensor 714
#define UPDATEACTORINERTIATENSOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getActorCenter 715
#define GETACTORCENTER_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORCENTER_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORCENTER_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORCENTER_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorRotationQ 716
#define GETACTORROTATIONQ_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORROTATIONQ_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORROTATIONQ_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORROTATIONQ_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETACTORROTATIONQ_W num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getActorLinearVelocityWorld 717
#define GETACTORLINEARVELOCITYWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORLINEARVELOCITYWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORLINEARVELOCITYWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORLINEARVELOCITYWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorAngularVelocityWorld 718
#define GETACTORANGULARVELOCITYWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORANGULARVELOCITYWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORANGULARVELOCITYWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORANGULARVELOCITYWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorLinearVelocityLocal 719
#define SETACTORLINEARVELOCITYLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORLINEARVELOCITYLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORLINEARVELOCITYLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORLINEARVELOCITYLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorLinearVelocityWorld 720
#define SETACTORLINEARVELOCITYWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORLINEARVELOCITYWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORLINEARVELOCITYWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORLINEARVELOCITYWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorAngularVelocityLocal 721
#define SETACTORANGULARVELOCITYLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORANGULARVELOCITYLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORANGULARVELOCITYLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORANGULARVELOCITYLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorAngularVelocityWorld 722
#define SETACTORANGULARVELOCITYWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORANGULARVELOCITYWORLD_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORANGULARVELOCITYWORLD_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORANGULARVELOCITYWORLD_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorVelocityInLocalPoint 723
#define GETACTORVELOCITYINLOCALPOINT_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORVELOCITYINLOCALPOINT_REL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORVELOCITYINLOCALPOINT_REL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORVELOCITYINLOCALPOINT_REL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETACTORVELOCITYINLOCALPOINT_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETACTORVELOCITYINLOCALPOINT_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETACTORVELOCITYINLOCALPOINT_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_getActorLinearVelocityLocal 724
#define GETACTORLINEARVELOCITYLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORLINEARVELOCITYLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORLINEARVELOCITYLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORLINEARVELOCITYLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorAngularVelocityLocal 725
#define GETACTORANGULARVELOCITYLOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORANGULARVELOCITYLOCAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORANGULARVELOCITYLOCAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORANGULARVELOCITYLOCAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorAABB 726
#define GETACTORAABB_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORAABB_MIN_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORAABB_MIN_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORAABB_MIN_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETACTORAABB_MAX_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETACTORAABB_MAX_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETACTORAABB_MAX_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_computeActorImpulseDenominator 727
#define COMPUTEACTORIMPULSEDENOMINATOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_POS_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_POS_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_POS_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_NORMAL_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_NORMAL_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_NORMAL_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_computeActorAngularImpulseDenominator 728
#define COMPUTEACTORANGULARIMPULSEDENOMINATOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COMPUTEACTORANGULARIMPULSEDENOMINATOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COMPUTEACTORANGULARIMPULSEDENOMINATOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define COMPUTEACTORANGULARIMPULSEDENOMINATOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setActorAngularFactor 729
#define SETACTORANGULARFACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORANGULARFACTOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORANGULARFACTOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETACTORANGULARFACTOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getActorAngularFactor 730
#define GETACTORANGULARFACTOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORANGULARFACTOR_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORANGULARFACTOR_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORANGULARFACTOR_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_computeActorGyroImpulseLocal 731
#define COMPUTEACTORGYROIMPULSELOCAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COMPUTEACTORGYROIMPULSELOCAL_DT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COMPUTEACTORGYROIMPULSELOCAL_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define COMPUTEACTORGYROIMPULSELOCAL_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define COMPUTEACTORGYROIMPULSELOCAL_Z num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_computeActorGyroImpulseWorld 732
#define COMPUTEACTORGYROIMPULSEWORLD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COMPUTEACTORGYROIMPULSEWORLD_DT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define COMPUTEACTORGYROIMPULSEWORLD_X num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define COMPUTEACTORGYROIMPULSEWORLD_Y num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define COMPUTEACTORGYROIMPULSEWORLD_Z num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_getActorLocalInertia 733
#define GETACTORLOCALINERTIA_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORLOCALINERTIA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORLOCALINERTIA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETACTORLOCALINERTIA_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetActorSleepState 734
#define SETACTORSLEEPSTATE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORSLEEPSTATE_STATE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_createPointConstraint 735
#define CREATEPOINTCONSTRAINT_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEPOINTCONSTRAINT_PXA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEPOINTCONSTRAINT_PYA num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEPOINTCONSTRAINT_PZA num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_createPointConstraintEx 736
#define CREATEPOINTCONSTRAINTEX_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_ACTORB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PXA num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PYA num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PZA num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PXB num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PYB num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PZB num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define FN_setPointPivotA 737
#define SETPOINTPIVOTA_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPOINTPIVOTA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPOINTPIVOTA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETPOINTPIVOTA_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setPointPivotB 738
#define SETPOINTPIVOTB_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPOINTPIVOTB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPOINTPIVOTB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETPOINTPIVOTB_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_createHingeConstraint 739
#define CREATEHINGECONSTRAINT_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEHINGECONSTRAINT_FRAMEA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEHINGECONSTRAINT_USEREFERENCEFRAMEA num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_createHingeConstraintEx 740
#define CREATEHINGECONSTRAINTEX_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATEHINGECONSTRAINTEX_ACTORB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATEHINGECONSTRAINTEX_FRAMEA num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATEHINGECONSTRAINTEX_FRAMEB num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATEHINGECONSTRAINTEX_USEREFERENCEFRAMEA num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_createSlideConstraint 741
#define CREATESLIDECONSTRAINT_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATESLIDECONSTRAINT_FRAMEINB_MATRIX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATESLIDECONSTRAINT_USELINEARREFERENCEFRAMEA num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_createSlideConstraintEx 742
#define CREATESLIDECONSTRAINTEX_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATESLIDECONSTRAINTEX_ACTORB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATESLIDECONSTRAINTEX_FRAMEINA_MATRIX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATESLIDECONSTRAINTEX_FRAMEINB_MATRIX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define CREATESLIDECONSTRAINTEX_USELINEARREFERENCEFRAMEA num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_createConeConstraint 743
#define CREATECONECONSTRAINT_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATECONECONSTRAINT_RBAFRAME_MATRIX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_createConeConstraintEx 744
#define CREATECONECONSTRAINTEX_ACTORA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define CREATECONECONSTRAINTEX_ACTORB num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define CREATECONECONSTRAINTEX_RBAFRAME_MATRIX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define CREATECONECONSTRAINTEX_RBBFRAME_MATRIX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_deleteConstraint 745
#define DELETECONSTRAINT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConstraintFrameOffsetA 746
#define GETCONSTRAINTFRAMEOFFSETA_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_RX num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_RY num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_RZ num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_getConstraintFrameOffsetB 747
#define GETCONSTRAINTFRAMEOFFSETB_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_RX num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_RY num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_RZ num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_useConstraintFrameOffset 748
#define USECONSTRAINTFRAMEOFFSET_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define USECONSTRAINTFRAMEOFFSET_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getHingeAngle 749
#define GETHINGEANGLE_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getHingeAngleEx 750
#define GETHINGEANGLEEX_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETHINGEANGLEEX_T_MATRIXA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETHINGEANGLEEX_T_MATRIXB num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getConstraintBreakingImpulseThreshold 751
#define GETCONSTRAINTBREAKINGIMPULSETHRESHOLD_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConstraintAFrame 752
#define GETCONSTRAINTAFRAME_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCONSTRAINTAFRAME_MA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getConstraintBFrame 753
#define GETCONSTRAINTBFRAME_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCONSTRAINTBFRAME_MA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setHingeAxis 754
#define SETHINGEAXIS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETHINGEAXIS_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETHINGEAXIS_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETHINGEAXIS_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setConstraintBreakingImpulseThreshold 755
#define SETCONSTRAINTBREAKINGIMPULSETHRESHOLD_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONSTRAINTBREAKINGIMPULSETHRESHOLD_THRESHOLD num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setConstraintFrames 756
#define SETCONSTRAINTFRAMES_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONSTRAINTFRAMES_FRAMEA_MATRIX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCONSTRAINTFRAMES_FRAMEB_MATRIX num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setHingeLimit 757
#define SETHINGELIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETHINGELIMIT_LOW num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETHINGELIMIT_HIGH num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETHINGELIMIT_SOFTNESS num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETHINGELIMIT_BIAS_FACTOR num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define SETHINGELIMIT_RELAXATION_FACTOR num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_setConeLimit 758
#define SETCONELIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONELIMIT_SWINGSPAN1 num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCONELIMIT_SWINGSPAN2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETCONELIMIT_TWISTSPAN num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETCONELIMIT_SOFTNESS num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define SETCONELIMIT_BIAS_FACTOR num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define SETCONELIMIT_RELAXATION_FACTOR num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_getHingeLimitBiasFactor 759
#define GETHINGELIMITBIASFACTOR_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getHingeLimitRelaxationFactor 760
#define GETHINGELIMITRELAXATIONFACTOR_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getHingeLimitSign 761
#define GETHINGELIMITSIGN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getHingeSolveLimit 762
#define GETHINGESOLVELIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_useHingeReferenceFrameA 763
#define USEHINGEREFERENCEFRAMEA_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define USEHINGEREFERENCEFRAMEA_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getConstraintAppliedImpulse 764
#define GETCONSTRAINTAPPLIEDIMPULSE_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConstraintFixedActor 765
#define GETCONSTRAINTFIXEDACTOR_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getPointPivotA 766
#define GETPOINTPIVOTA_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPOINTPIVOTA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPOINTPIVOTA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETPOINTPIVOTA_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getPointPivotB 767
#define GETPOINTPIVOTB_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPOINTPIVOTB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPOINTPIVOTB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETPOINTPIVOTB_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getConstraintActorA 768
#define GETCONSTRAINTACTORA_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConstraintActorB 769
#define GETCONSTRAINTACTORB_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setConstraintSolverIterations 770
#define SETCONSTRAINTSOLVERITERATIONS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONSTRAINTSOLVERITERATIONS_NUM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getConeBiasFactor 771
#define GETCONEBIASFACTOR_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeDamping 772
#define GETCONEDAMPING_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeFixThresh 773
#define GETCONEFIXTHRESH_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeLimit 774
#define GETCONELIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCONELIMIT_LIMIT_INDEX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getConstraintLimitSoftness 775
#define GETCONSTRAINTLIMITSOFTNESS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConstraintSolverIterations 776
#define GETCONSTRAINTSOLVERITERATIONS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeAnglePoint 777
#define GETCONEANGLEPOINT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCONEANGLEPOINT_ANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCONEANGLEPOINT_C_LEN num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETCONEANGLEPOINT_X num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETCONEANGLEPOINT_Y num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETCONEANGLEPOINT_Z num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_getConstraintAngularOnly 778
#define GETCONSTRAINTANGULARONLY_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeSolveSwingLimit 779
#define GETCONESOLVESWINGLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeSolveTwistLimit 780
#define GETCONESOLVETWISTLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeSwingSpan1 781
#define GETCONESWINGSPAN1_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeSwingSpan2 782
#define GETCONESWINGSPAN2_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeTwistAngle 783
#define GETCONETWISTANGLE_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeTwistLimitSign 784
#define GETCONETWISTLIMITSIGN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getConeTwistSpan 785
#define GETCONETWISTSPAN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setConstraintAngularOnly 786
#define SETCONSTRAINTANGULARONLY_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONSTRAINTANGULARONLY_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setConeDamping 787
#define SETCONEDAMPING_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONEDAMPING_DAMPING num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setConeFixThresh 788
#define SETCONEFIXTHRESH_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCONEFIXTHRESH_FIXTHRESH num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getSlideAnchorA 789
#define GETSLIDEANCHORA_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSLIDEANCHORA_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSLIDEANCHORA_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSLIDEANCHORA_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getSlideAnchorB 790
#define GETSLIDEANCHORB_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETSLIDEANCHORB_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETSLIDEANCHORB_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETSLIDEANCHORB_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getSlideAngDepth 791
#define GETSLIDEANGDEPTH_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideAngularPos 792
#define GETSLIDEANGULARPOS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideDampingDirAng 793
#define GETSLIDEDAMPINGDIRANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideDampingDirLin 794
#define GETSLIDEDAMPINGDIRLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideDampingLimAng 795
#define GETSLIDEDAMPINGLIMANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideDampingLimLin 796
#define GETSLIDEDAMPINGLIMLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideDampingOrthoAng 797
#define GETSLIDEDAMPINGORTHOANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideDampingOrthoLin 798
#define GETSLIDEDAMPINGORTHOLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideLinearPos 799
#define GETSLIDELINEARPOS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideLinDepth 800
#define GETSLIDELINDEPTH_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideLowerAngLimit 801
#define GETSLIDELOWERANGLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideLowerLinLimit 802
#define GETSLIDELOWERLINLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideRestitutionDirAng 803
#define GETSLIDERESTITUTIONDIRANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideRestitutionDirLin 804
#define GETSLIDERESTITUTIONDIRLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideRestitutionLimAng 805
#define GETSLIDERESTITUTIONLIMANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideRestitutionLimLin 806
#define GETSLIDERESTITUTIONLIMLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideRestitutionOrthoAng 807
#define GETSLIDERESTITUTIONORTHOANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideRestitutionOrthoLin 808
#define GETSLIDERESTITUTIONORTHOLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSoftnessDirAng 809
#define GETSLIDESOFTNESSDIRANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSoftnessDirLin 810
#define GETSLIDESOFTNESSDIRLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSoftnessLimAng 811
#define GETSLIDESOFTNESSLIMANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSoftnessLimLin 812
#define GETSLIDESOFTNESSLIMLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSoftnessOrthoAng 813
#define GETSLIDESOFTNESSORTHOANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSoftnessOrthoLin 814
#define GETSLIDESOFTNESSORTHOLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSolveAngLimit 815
#define GETSLIDESOLVEANGLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideSolveLinLimit 816
#define GETSLIDESOLVELINLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideUpperAngLimit 817
#define GETSLIDEUPPERANGLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideUpperLinLimit 818
#define GETSLIDEUPPERLINLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getSlideUseFrameOffset 819
#define GETSLIDEUSEFRAMEOFFSET_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setSlideDampingDirAng 820
#define SETSLIDEDAMPINGDIRANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEDAMPINGDIRANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideDampingDirLin 821
#define SETSLIDEDAMPINGDIRLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEDAMPINGDIRLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideDampingLimAng 822
#define SETSLIDEDAMPINGLIMANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEDAMPINGLIMANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideDampingLimLin 823
#define SETSLIDEDAMPINGLIMLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEDAMPINGLIMLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideDampingOrthoAng 824
#define SETSLIDEDAMPINGORTHOANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEDAMPINGORTHOANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideDampingOrthoLin 825
#define SETSLIDEDAMPINGORTHOLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEDAMPINGORTHOLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideLowerAngLimit 826
#define SETSLIDELOWERANGLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDELOWERANGLIMIT_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideLowerLinLimit 827
#define SETSLIDELOWERLINLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDELOWERLINLIMIT_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideRestitutionDirAng 828
#define SETSLIDERESTITUTIONDIRANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDERESTITUTIONDIRANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideRestitutionDirLin 829
#define SETSLIDERESTITUTIONDIRLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDERESTITUTIONDIRLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideRestitutionLimAng 830
#define SETSLIDERESTITUTIONLIMANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDERESTITUTIONLIMANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideRestitutionLimLin 831
#define SETSLIDERESTITUTIONLIMLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDERESTITUTIONLIMLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideRestitutionOrthoAng 832
#define SETSLIDERESTITUTIONORTHOANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDERESTITUTIONORTHOANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideRestitutionOrthoLin 833
#define SETSLIDERESTITUTIONORTHOLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDERESTITUTIONORTHOLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideSoftnessDirAng 834
#define SETSLIDESOFTNESSDIRANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDESOFTNESSDIRANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideSoftnessDirLin 835
#define SETSLIDESOFTNESSDIRLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDESOFTNESSDIRLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideSoftnessLimAng 836
#define SETSLIDESOFTNESSLIMANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDESOFTNESSLIMANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideSoftnessLimLin 837
#define SETSLIDESOFTNESSLIMLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDESOFTNESSLIMLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideSoftnessOrthoAng 838
#define SETSLIDESOFTNESSORTHOANG_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDESOFTNESSORTHOANG_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideSoftnessOrthoLin 839
#define SETSLIDESOFTNESSORTHOLIN_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDESOFTNESSORTHOLIN_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideUpperAngLimit 840
#define SETSLIDEUPPERANGLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEUPPERANGLIMIT_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setSlideUpperLinLimit 841
#define SETSLIDEUPPERLINLIMIT_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETSLIDEUPPERLINLIMIT_N num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_ConstraintExists 842
#define CONSTRAINTEXISTS_CONSTRAINT_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetCameraPosition 843
#define SETCAMERAPOSITION_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCAMERAPOSITION_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCAMERAPOSITION_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetCameraPosition 844
#define GETCAMERAPOSITION_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCAMERAPOSITION_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCAMERAPOSITION_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_TranslateCamera 845
#define TRANSLATECAMERA_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define TRANSLATECAMERA_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define TRANSLATECAMERA_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetCameraRotation 846
#define SETCAMERAROTATION_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETCAMERAROTATION_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETCAMERAROTATION_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetCameraRotation 847
#define GETCAMERAROTATION_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETCAMERAROTATION_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETCAMERAROTATION_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_RotateCamera 848
#define ROTATECAMERA_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ROTATECAMERA_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ROTATECAMERA_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetCameraFOV 849
#define SETCAMERAFOV_FOV num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetCameraFOV 850
#define FN_SetCameraAspectRatio 851
#define SETCAMERAASPECTRATIO_ASPECT num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetCameraAspectRatio 852
#define FN_SetCameraFarValue 853
#define SETCAMERAFARVALUE_ZF num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetCameraFarValue 854
#define FN_SetCameraNearValue 855
#define SETCAMERANEARVALUE_ZN num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetCameraNearValue 856
#define FN_SetProjectionMatrix 857
#define SETPROJECTIONMATRIX_MATA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPROJECTIONMATRIX_PROJECTION_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetProjectionMatrix 858
#define GETPROJECTIONMATRIX_MATA num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetWorldToViewportPosition 859
#define GETWORLDTOVIEWPORTPOSITION_X num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETWORLDTOVIEWPORTPOSITION_Y num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETWORLDTOVIEWPORTPOSITION_Z num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETWORLDTOVIEWPORTPOSITION_VX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETWORLDTOVIEWPORTPOSITION_VY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define FN_AddSceneSkyBox 860
#define ADDSCENESKYBOX_IMG_TOP num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ADDSCENESKYBOX_IMG_BOTTOM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ADDSCENESKYBOX_IMG_LEFT num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define ADDSCENESKYBOX_IMG_RIGHT num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define ADDSCENESKYBOX_IMG_FRONT num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define ADDSCENESKYBOX_IMG_BACK num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_AddSceneSkyDome 861
#define ADDSCENESKYDOME_IMG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_AddSceneSkyDomeEx 862
#define ADDSCENESKYDOMEEX_IMG num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define ADDSCENESKYDOMEEX_HORIRES num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define ADDSCENESKYDOMEEX_VERTRES num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define ADDSCENESKYDOMEEX_TXPERCENTAGE num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define ADDSCENESKYDOMEEX_SPHEREPERCENTAGE num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define ADDSCENESKYDOMEEX_RADIUS num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define FN_RemoveSceneSky 863
#define FN_SetWorld3DMaxSubSteps 864
#define SETWORLD3DMAXSUBSTEPS_STEPS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetWorld3DTimeStep 865
#define SETWORLD3DTIMESTEP_TS num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetWorld3DMaxSubSteps 866
#define FN_GetWorld3DTimeStep 867
#define FN_startParticleEmitter 868
#define STARTPARTICLEEMITTER_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_stopParticleEmitter 869
#define STOPPARTICLEEMITTER_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleDirection 870
#define SETPARTICLEDIRECTION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEDIRECTION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPARTICLEDIRECTION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETPARTICLEDIRECTION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getParticleDirection 871
#define GETPARTICLEDIRECTION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPARTICLEDIRECTION_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPARTICLEDIRECTION_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETPARTICLEDIRECTION_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_useParticleEveryMeshVertex 872
#define USEPARTICLEEVERYMESHVERTEX_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define USEPARTICLEEVERYMESHVERTEX_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_particleIsUsingEveryMeshVertex 873
#define PARTICLEISUSINGEVERYMESHVERTEX_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleNormalDirectionMod 874
#define SETPARTICLENORMALDIRECTIONMOD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLENORMALDIRECTIONMOD_ND_MOD num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleNormalDirectionMod 875
#define GETPARTICLENORMALDIRECTIONMOD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_useParticleNormalDirection 876
#define USEPARTICLENORMALDIRECTION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define USEPARTICLENORMALDIRECTION_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_particleIsUsingNormalDirection 877
#define PARTICLEISUSINGNORMALDIRECTION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMesh 878
#define SETPARTICLEMESH_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMESH_MESH num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setMinParticlesPerSecond 879
#define SETMINPARTICLESPERSECOND_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMINPARTICLESPERSECOND_MINPARTICLESPERSECOND num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMinParticlesPerSecond 880
#define GETMINPARTICLESPERSECOND_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaxParticlesPerSecond 881
#define SETMAXPARTICLESPERSECOND_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMAXPARTICLESPERSECOND_MAXPARTICLESPERSECOND num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaxParticlesPerSecond 882
#define GETMAXPARTICLESPERSECOND_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMinStartColor 883
#define SETPARTICLEMINSTARTCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMINSTARTCOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleMinStartColor 884
#define GETPARTICLEMINSTARTCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMaxStartColor 885
#define SETPARTICLEMAXSTARTCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMAXSTARTCOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleMaxStartColor 886
#define GETPARTICLEMAXSTARTCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMinLife 887
#define SETPARTICLEMINLIFE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMINLIFE_MINLIFE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleMinLife 888
#define GETPARTICLEMINLIFE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMaxLife 889
#define SETPARTICLEMAXLIFE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMAXLIFE_MAXLIFE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleMaxLife 890
#define GETPARTICLEMAXLIFE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMaxAngle 891
#define SETPARTICLEMAXANGLE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMAXANGLE_MAXANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleMaxAngle 892
#define GETPARTICLEMAXANGLE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleMinStartSize 893
#define SETPARTICLEMINSTARTSIZE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMINSTARTSIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPARTICLEMINSTARTSIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getParticleMinStartSize 894
#define GETPARTICLEMINSTARTSIZE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPARTICLEMINSTARTSIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPARTICLEMINSTARTSIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setParticleMaxStartSize 895
#define SETPARTICLEMAXSTARTSIZE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEMAXSTARTSIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPARTICLEMAXSTARTSIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getParticleMaxStartSize 896
#define GETPARTICLEMAXSTARTSIZE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPARTICLEMAXSTARTSIZE_W num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPARTICLEMAXSTARTSIZE_H num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setParticleCenter 897
#define SETPARTICLECENTER_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLECENTER_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPARTICLECENTER_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETPARTICLECENTER_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getParticleCenter 898
#define GETPARTICLECENTER_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPARTICLECENTER_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPARTICLECENTER_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETPARTICLECENTER_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setParticleRadius 899
#define SETPARTICLERADIUS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLERADIUS_RADIUS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleRadius 900
#define GETPARTICLERADIUS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleRingThickness 901
#define SETPARTICLERINGTHICKNESS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLERINGTHICKNESS_RINGTHICKNESS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleRingThickness 902
#define GETPARTICLERINGTHICKNESS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setParticleBox 903
#define SETPARTICLEBOX_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLEBOX_MIN_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPARTICLEBOX_MIN_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETPARTICLEBOX_MIN_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define SETPARTICLEBOX_MAX_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define SETPARTICLEBOX_MAX_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define SETPARTICLEBOX_MAX_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_getParticleBox 904
#define GETPARTICLEBOX_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPARTICLEBOX_MIN_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPARTICLEBOX_MIN_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETPARTICLEBOX_MIN_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETPARTICLEBOX_MAX_X num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETPARTICLEBOX_MAX_Y num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETPARTICLEBOX_MAX_Z num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define FN_setParticleNormal 905
#define SETPARTICLENORMAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLENORMAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETPARTICLENORMAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETPARTICLENORMAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_getParticleNormal 906
#define GETPARTICLENORMAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETPARTICLENORMAL_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETPARTICLENORMAL_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETPARTICLENORMAL_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_setParticleLength 907
#define SETPARTICLELENGTH_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETPARTICLELENGTH_P_LEN num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getParticleLength 908
#define GETPARTICLELENGTH_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_useParticleOutlineOnly 909
#define USEPARTICLEOUTLINEONLY_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define USEPARTICLEOUTLINEONLY_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_particleIsUsingOutlineOnly 910
#define PARTICLEISUSINGOUTLINEONLY_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getParticleType 911
#define GETPARTICLETYPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_lightIsCastingShadow 912
#define LIGHTISCASTINGSHADOW_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getLightType 913
#define GETLIGHTTYPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_getLightRadius 914
#define GETLIGHTRADIUS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setLightType 915
#define SETLIGHTTYPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTTYPE_LIGHT_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setLightRadius 916
#define SETLIGHTRADIUS_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTRADIUS_RADIUS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setLightShadowCast 917
#define SETLIGHTSHADOWCAST_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTSHADOWCAST_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetLightAmbientColor 918
#define SETLIGHTAMBIENTCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTAMBIENTCOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetLightAmbientColor 919
#define GETLIGHTAMBIENTCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetLightAttenuation 920
#define SETLIGHTATTENUATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTATTENUATION_L_CONSTANT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETLIGHTATTENUATION_L_LINEAR num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETLIGHTATTENUATION_L_QUADRATIC num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_GetLightAttenuation 921
#define GETLIGHTATTENUATION_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETLIGHTATTENUATION_CONSTANT num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETLIGHTATTENUATION_LINEAR num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETLIGHTATTENUATION_QUADRATIC num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetLightDiffuseColor 922
#define SETLIGHTDIFFUSECOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTDIFFUSECOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetLightDiffuseColor 923
#define GETLIGHTDIFFUSECOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetLightFalloff 924
#define SETLIGHTFALLOFF_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTFALLOFF_FALLOFF num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetLightFalloff 925
#define GETLIGHTFALLOFF_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetLightInnerCone 926
#define SETLIGHTINNERCONE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTINNERCONE_ANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetLightInnerCone 927
#define GETLIGHTINNERCONE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetLightOuterCone 928
#define SETLIGHTOUTERCONE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTOUTERCONE_ANGLE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetLightOuterCone 929
#define GETLIGHTOUTERCONE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_SetLightSpecularColor 930
#define SETLIGHTSPECULARCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETLIGHTSPECULARCOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_GetLightSpecularColor 931
#define GETLIGHTSPECULARCOLOR_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_GetTerrainPatchAABB 932
#define GETTERRAINPATCHAABB_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTERRAINPATCHAABB_PATCHX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTERRAINPATCHAABB_PATCHZ num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETTERRAINPATCHAABB_MINX num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define GETTERRAINPATCHAABB_MINY num_var[4].nref[0].value[ num_var[4].byref_offset ]
#define GETTERRAINPATCHAABB_MINZ num_var[5].nref[0].value[ num_var[5].byref_offset ]
#define GETTERRAINPATCHAABB_MAXX num_var[6].nref[0].value[ num_var[6].byref_offset ]
#define GETTERRAINPATCHAABB_MAXY num_var[7].nref[0].value[ num_var[7].byref_offset ]
#define GETTERRAINPATCHAABB_MAXZ num_var[8].nref[0].value[ num_var[8].byref_offset ]
#define FN_GetTerrainPatchLOD 933
#define GETTERRAINPATCHLOD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTERRAINPATCHLOD_PATCHX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTERRAINPATCHLOD_PATCHZ num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetTerrainHeight 934
#define GETTERRAINHEIGHT_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTERRAINHEIGHT_PATCHX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTERRAINHEIGHT_PATCHZ num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_GetTerrainCenter 935
#define GETTERRAINCENTER_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETTERRAINCENTER_X num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETTERRAINCENTER_Y num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define GETTERRAINCENTER_Z num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_SetTerrainLODDistance 936
#define SETTERRAINLODDISTANCE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTERRAINLODDISTANCE_LOD num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTERRAINLODDISTANCE_DISTANCE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_ScaleTerrainTexture 937
#define SCALETERRAINTEXTURE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SCALETERRAINTEXTURE_SCALE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SCALETERRAINTEXTURE_SCALE2 num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_SetTerrainCameraMovementDelta 938
#define SETTERRAINCAMERAMOVEMENTDELTA_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTERRAINCAMERAMOVEMENTDELTA_DELTA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetTerrainCameraRotationDelta 939
#define SETTERRAINCAMERAROTATIONDELTA_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTERRAINCAMERAROTATIONDELTA_DELTA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_SetTerrainPatchLOD 940
#define SETTERRAINPATCHLOD_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETTERRAINPATCHLOD_PATCHX num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETTERRAINPATCHLOD_PATCHZ num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define SETTERRAINPATCHLOD_LOD num_var[3].nref[0].value[ num_var[3].byref_offset ]
#define FN_createMaterial 941
#define FN_deleteMaterial 942
#define DELETEMATERIAL_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setActorMaterial 943
#define SETACTORMATERIAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORMATERIAL_MATERIAL_NUM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORMATERIAL_MATERIAL_ID num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getActorMaterial 944
#define GETACTORMATERIAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORMATERIAL_MATERIAL_NUM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_copyActorMaterial 945
#define COPYACTORMATERIAL_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define COPYACTORMATERIAL_MATERIAL_NUM num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_copyMaterial 946
#define COPYMATERIAL_SMATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialTextureCanvas 947
#define SETMATERIALTEXTURECANVAS_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALTEXTURECANVAS_LEVEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATERIALTEXTURECANVAS_CANVAS_ID num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setMaterialAmbientColor 948
#define SETMATERIALAMBIENTCOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALAMBIENTCOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialAmbientColor 949
#define GETMATERIALAMBIENTCOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialAntiAliasing 950
#define SETMATERIALANTIALIASING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALANTIALIASING_AA num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialAntiAliasing 951
#define GETMATERIALANTIALIASING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialBackfaceCulling 952
#define SETMATERIALBACKFACECULLING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALBACKFACECULLING_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialBackfaceCulling 953
#define GETMATERIALBACKFACECULLING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialBlendFactor 954
#define SETMATERIALBLENDFACTOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALBLENDFACTOR_BF num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialBlendFactor 955
#define GETMATERIALBLENDFACTOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialBlendMode 956
#define SETMATERIALBLENDMODE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALBLENDMODE_BLEND_MODE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialBlendMode 957
#define GETMATERIALBLENDMODE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialColorMask 958
#define SETMATERIALCOLORMASK_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALCOLORMASK_COLOR_MASK num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialColorMask 959
#define GETMATERIALCOLORMASK_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialColorMode 960
#define SETMATERIALCOLORMODE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALCOLORMODE_COLOR_MODE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialColorMode 961
#define GETMATERIALCOLORMODE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialDiffuseColor 962
#define SETMATERIALDIFFUSECOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALDIFFUSECOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialDiffuseColor 963
#define GETMATERIALDIFFUSECOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialEmissiveColor 964
#define SETMATERIALEMISSIVECOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALEMISSIVECOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialEmissiveColor 965
#define GETMATERIALEMISSIVECOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialFog 966
#define SETMATERIALFOG_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALFOG_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialFog 967
#define GETMATERIALFOG_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialFrontfaceCulling 968
#define SETMATERIALFRONTFACECULLING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALFRONTFACECULLING_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialFrontfaceCulling 969
#define GETMATERIALFRONTFACECULLING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialGouraudShading 970
#define SETMATERIALGOURAUDSHADING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALGOURAUDSHADING_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_materialIsGouraudShaded 971
#define MATERIALISGOURAUDSHADED_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_materialIsAplhaBlend 972
#define MATERIALISAPLHABLEND_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_materialIsTransparent 973
#define MATERIALISTRANSPARENT_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialLighting 974
#define SETMATERIALLIGHTING_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALLIGHTING_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_materialIsLit 975
#define MATERIALISLIT_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialType 976
#define SETMATERIALTYPE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALTYPE_MAT_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialType 977
#define GETMATERIALTYPE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialNormalize 978
#define SETMATERIALNORMALIZE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALNORMALIZE_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_materialIsNormalized 979
#define MATERIALISNORMALIZED_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialPointCloud 980
#define SETMATERIALPOINTCLOUD_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALPOINTCLOUD_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_materialIsPointCloud 981
#define MATERIALISPOINTCLOUD_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialFlag 982
#define SETMATERIALFLAG_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALFLAG_MATERIAL_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATERIALFLAG_F_VALUE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getMaterialFlag 983
#define GETMATERIALFLAG_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETMATERIALFLAG_MATERIAL_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_setMaterialTexture 984
#define SETMATERIALTEXTURE_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALTEXTURE_LEVEL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETMATERIALTEXTURE_IMG_ID num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setMaterialShininess 985
#define SETMATERIALSHININESS_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALSHININESS_SHININESS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialShininess 986
#define GETMATERIALSHININESS_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialSpecularColor 987
#define SETMATERIALSPECULARCOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALSPECULARCOLOR_COLOR num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialSpecularColor 988
#define GETMATERIALSPECULARCOLOR_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialThickness 989
#define SETMATERIALTHICKNESS_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALTHICKNESS_THICKNESS num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getMaterialThickness 990
#define GETMATERIALTHICKNESS_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setMaterialWireframe 991
#define SETMATERIALWIREFRAME_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETMATERIALWIREFRAME_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_materialIsWireframe 992
#define MATERIALISWIREFRAME_MATERIAL_ID num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setActorTexture 993
#define SETACTORTEXTURE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORTEXTURE_LAYER num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORTEXTURE_IMAGE_ID num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getActorMaterialCount 994
#define GETACTORMATERIALCOUNT_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define FN_setActorMaterialFlag 995
#define SETACTORMATERIALFLAG_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORMATERIALFLAG_FLAG num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define SETACTORMATERIALFLAG_FLAG_VALUE num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_getActorMaterialFlag 996
#define GETACTORMATERIALFLAG_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORMATERIALFLAG_MATERIAL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define GETACTORMATERIALFLAG_FLAG num_var[2].nref[0].value[ num_var[2].byref_offset ]
#define FN_setActorMaterialType 997
#define SETACTORMATERIALTYPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define SETACTORMATERIALTYPE_MATERIAL_TYPE num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_getActorMaterialType 998
#define GETACTORMATERIALTYPE_ACTOR num_var[0].nref[0].value[ num_var[0].byref_offset ]
#define GETACTORMATERIALTYPE_MATERIAL num_var[1].nref[0].value[ num_var[1].byref_offset ]
#define FN_MaterialExists 999
#define MATERIALEXISTS_MATERIAL num_var[0].nref[0].value[ num_var[0].byref_offset ]


#endif // RC_DEFINES_H_INCLUDED
