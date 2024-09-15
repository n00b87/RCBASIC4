#ifndef RC_DEFINES_H_INCLUDED
#define RC_DEFINES_H_INCLUDED

#define FN_Fprint 0
#define FPRINT_TXT$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_Input$ 1
#define INPUT$_PROMPT$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_ArrayDim 2
#define ARRAYDIM_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_StringArrayDim 3
#define STRINGARRAYDIM_ID$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_NumberArrayDim 4
#define NUMBERARRAYDIM_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_ArraySize 5
#define ARRAYSIZE_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define ARRAYSIZE_ARRAY_DIM num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_StringArraySize 6
#define STRINGARRAYSIZE_ID$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define STRINGARRAYSIZE_ARRAY_DIM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_NumberArraySize 7
#define NUMBERARRAYSIZE_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define NUMBERARRAYSIZE_ARRAY_DIM num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_NumberArrayCopy 8
#define NUMBERARRAYCOPY_SRC num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define NUMBERARRAYCOPY_DST num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_StringArrayCopy 9
#define STRINGARRAYCOPY_SRC$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define STRINGARRAYCOPY_DST$ str_var[1].sid_value.value[ str_var[1].byref_offset ]
#define FN_ArrayCopy 10
#define ARRAYCOPY_SRC num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define ARRAYCOPY_DST num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_NumberArrayFill 11
#define NUMBERARRAYFILL_SRC num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define NUMBERARRAYFILL_FDATA num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_StringArrayFill 12
#define STRINGARRAYFILL_SRC$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define STRINGARRAYFILL_FDATA$ str_var[1].sid_value.value[ str_var[1].byref_offset ]
#define FN_ArrayFill 13
#define ARRAYFILL_SRC num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define ARRAYFILL_FDATA num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_TypeArrayDim 14
#define TYPEARRAYDIM_ID usr_var[0].var_ref
#define FN_TypeArraySize 15
#define TYPEARRAYSIZE_ID usr_var[0].var_ref
#define TYPEARRAYSIZE_ARRAY_DIM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_TypeArrayCopy 16
#define TYPEARRAYCOPY_SRC usr_var[0].var_ref
#define TYPEARRAYCOPY_DST usr_var[1].var_ref
#define FN_TypeArrayFill 17
#define TYPEARRAYFILL_SRC usr_var[0].var_ref
#define TYPEARRAYFILL_FDATA usr_var[1].var_ref->uid_value[0]
#define FN_Abs 18
#define ABS_N num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Acos 19
#define ACOS_N num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_AndBit 20
#define ANDBIT_A num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define ANDBIT_B num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_Asin 21
#define ASIN_N num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Atan 22
#define ATAN_N num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Bin$ 23
#define BIN$_N num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_CInt32 24
#define CINT32_I num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_CInt64 25
#define CINT64_I num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Cos 26
#define COS_N num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Degrees 27
#define DEGREES_R num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Exp 28
#define EXP_N num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Frac 29
#define FRAC_N num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Hex$ 30
#define HEX$_N num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_HexVal 31
#define HEXVAL_N$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_Int 32
#define INT_N num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Log 33
#define LOG_N num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Max 34
#define MAX_A num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define MAX_B num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_Min 35
#define MIN_A num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define MIN_B num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_OrBit 36
#define ORBIT_A num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define ORBIT_B num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_Radians 37
#define RADIANS_D num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Randomize 38
#define RANDOMIZE_N num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Rand 39
#define RAND_N num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Round 40
#define ROUND_N num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Sign 41
#define SIGN_N num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Sin 42
#define SIN_N num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Sqrt 43
#define SQRT_N num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Tan 44
#define TAN_N num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_XOrBit 45
#define XORBIT_A num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define XORBIT_B num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_GetLineIntersection 46
#define GETLINEINTERSECTION_P0_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETLINEINTERSECTION_P0_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETLINEINTERSECTION_P1_X num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETLINEINTERSECTION_P1_Y num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define GETLINEINTERSECTION_P2_X num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define GETLINEINTERSECTION_P2_Y num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define GETLINEINTERSECTION_P3_X num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define GETLINEINTERSECTION_P3_Y num_var[7].nid_value.value[ num_var[7].byref_offset ]
#define GETLINEINTERSECTION_I_X num_var[8].nid_value.value[ num_var[8].byref_offset ]
#define GETLINEINTERSECTION_I_Y num_var[9].nid_value.value[ num_var[9].byref_offset ]
#define FN_Interpolate 47
#define INTERPOLATE_MIN_A num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define INTERPOLATE_MAX_A num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define INTERPOLATE_MID_A num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define INTERPOLATE_MIN_B num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define INTERPOLATE_MAX_B num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define FN_ATan2 48
#define ATAN2_Y num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define ATAN2_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_PointInQuad 49
#define POINTINQUAD_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define POINTINQUAD_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define POINTINQUAD_X1 num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define POINTINQUAD_Y1 num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define POINTINQUAD_X2 num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define POINTINQUAD_Y2 num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define POINTINQUAD_X3 num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define POINTINQUAD_Y3 num_var[7].nid_value.value[ num_var[7].byref_offset ]
#define POINTINQUAD_X4 num_var[8].nid_value.value[ num_var[8].byref_offset ]
#define POINTINQUAD_Y4 num_var[9].nid_value.value[ num_var[9].byref_offset ]
#define FN_PointInTri 50
#define POINTINTRI_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define POINTINTRI_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define POINTINTRI_X1 num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define POINTINTRI_Y1 num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define POINTINTRI_X2 num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define POINTINTRI_Y2 num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define POINTINTRI_X3 num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define POINTINTRI_Y3 num_var[7].nid_value.value[ num_var[7].byref_offset ]
#define FN_Distance2D 51
#define DISTANCE2D_X1 num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define DISTANCE2D_Y1 num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define DISTANCE2D_X2 num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define DISTANCE2D_Y2 num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_Distance3D 52
#define DISTANCE3D_X1 num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define DISTANCE3D_Y1 num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define DISTANCE3D_Z1 num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define DISTANCE3D_X2 num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define DISTANCE3D_Y2 num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define DISTANCE3D_Z2 num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define FN_GetCircleLineIntersection 53
#define GETCIRCLELINEINTERSECTION_CIRCLE_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETCIRCLELINEINTERSECTION_CIRCLE_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETCIRCLELINEINTERSECTION_RADIUS num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETCIRCLELINEINTERSECTION_X1 num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define GETCIRCLELINEINTERSECTION_Y1 num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define GETCIRCLELINEINTERSECTION_X2 num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define GETCIRCLELINEINTERSECTION_Y2 num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define GETCIRCLELINEINTERSECTION_IX1 num_var[7].nid_value.value[ num_var[7].byref_offset ]
#define GETCIRCLELINEINTERSECTION_IY1 num_var[8].nid_value.value[ num_var[8].byref_offset ]
#define GETCIRCLELINEINTERSECTION_IX2 num_var[9].nid_value.value[ num_var[9].byref_offset ]
#define GETCIRCLELINEINTERSECTION_IY2 num_var[10].nid_value.value[ num_var[10].byref_offset ]
#define FN_GetLinePlaneIntersection 54
#define GETLINEPLANEINTERSECTION_LINE_POINT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETLINEPLANEINTERSECTION_LINE_DIRECTION num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETLINEPLANEINTERSECTION_PLANE_POINT_1 num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETLINEPLANEINTERSECTION_PLANE_POINT_2 num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define GETLINEPLANEINTERSECTION_PLANE_POINT_3 num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define GETLINEPLANEINTERSECTION_INTERSECTION num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define FN_Asc 55
#define ASC_C$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_Chr$ 56
#define CHR$_N num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Insert$ 57
#define INSERT$_SRC$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define INSERT$_TGT$ str_var[1].sid_value.value[ str_var[1].byref_offset ]
#define INSERT$_POS num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_InStr 58
#define INSTR_SRC$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define INSTR_SUBSTR$ str_var[1].sid_value.value[ str_var[1].byref_offset ]
#define FN_Lcase$ 59
#define LCASE$_SRC$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_Left$ 60
#define LEFT$_SRC$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define LEFT$_N num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Length 61
#define LENGTH_SRC$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_Len 62
#define LEN_SRC$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_Ltrim$ 63
#define LTRIM$_SRC$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_Mid$ 64
#define MID$_SRC$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define MID$_START num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define MID$_N num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_ReplaceSubstr$ 65
#define REPLACESUBSTR$_SRC$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define REPLACESUBSTR$_RPC$ str_var[1].sid_value.value[ str_var[1].byref_offset ]
#define REPLACESUBSTR$_POS num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Replace$ 66
#define REPLACE$_SRC$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define REPLACE$_TGT$ str_var[1].sid_value.value[ str_var[1].byref_offset ]
#define REPLACE$_RPC$ str_var[2].sid_value.value[ str_var[2].byref_offset ]
#define FN_Reverse$ 67
#define REVERSE$_SRC$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_Right$ 68
#define RIGHT$_SRC$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define RIGHT$_N num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Rtrim$ 69
#define RTRIM$_SRC$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_StringFill$ 70
#define STRINGFILL$_SRC$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define STRINGFILL$_N num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Str$ 71
#define STR$_N num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Str_F$ 72
#define STR_F$_N num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Str_S$ 73
#define STR_S$_N num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Tally 74
#define TALLY_SRC$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define TALLY_SUBSTR$ str_var[1].sid_value.value[ str_var[1].byref_offset ]
#define FN_Trim$ 75
#define TRIM$_SRC$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_Ucase$ 76
#define UCASE$_SRC$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_Val 77
#define VAL_N$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_Size 78
#define SIZE_S$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_BufferFromString 79
#define BUFFERFROMSTRING_S$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define BUFFERFROMSTRING_BUFFER num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_StringFromBuffer$ 80
#define STRINGFROMBUFFER$_BUFFER num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define STRINGFROMBUFFER$_BUFFER_SIZE num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_CreateStack_N 81
#define FN_CreateStack_S 82
#define FN_ClearStack_N 83
#define CLEARSTACK_N_NUM_STACK num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_ClearStack_S 84
#define CLEARSTACK_S_STR_STACK num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_DeleteStack_N 85
#define DELETESTACK_N_NUM_STACK num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_DeleteStack_S 86
#define DELETESTACK_S_STR_STACK num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Push_N 87
#define PUSH_N_NUM_STACK num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define PUSH_N_N num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_Pop_N 88
#define POP_N_NUM_STACK num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Push_S 89
#define PUSH_S_STR_STACK num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define PUSH_S_S$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_Pop_S$ 90
#define POP_S$_STR_STACK num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Stack_Size_N 91
#define STACK_SIZE_N_NUM_STACK num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Stack_Size_S 92
#define STACK_SIZE_S_STR_STACK num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_OpenFile 93
#define OPENFILE_FILENAME$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define OPENFILE_MODE num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_CloseFile 94
#define CLOSEFILE_STREAM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_ReadByte 95
#define READBYTE_STREAM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_WriteByte 96
#define WRITEBYTE_STREAM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define WRITEBYTE_BYTE num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_ReadLine$ 97
#define READLINE$_STREAM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Write 98
#define WRITE_STREAM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define WRITE_TXT$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_WriteLine 99
#define WRITELINE_STREAM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define WRITELINE_TXT$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_CopyFile 100
#define COPYFILE_SRC$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define COPYFILE_DST$ str_var[1].sid_value.value[ str_var[1].byref_offset ]
#define FN_RemoveFile 101
#define REMOVEFILE_FILENAME$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_FileExists 102
#define FILEEXISTS_FILENAME$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_MoveFile 103
#define MOVEFILE_SRC$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define MOVEFILE_DST$ str_var[1].sid_value.value[ str_var[1].byref_offset ]
#define FN_RenameFile 104
#define RENAMEFILE_SRC$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define RENAMEFILE_DST$ str_var[1].sid_value.value[ str_var[1].byref_offset ]
#define FN_FileLength 105
#define FILELENGTH_FILENAME$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_Tell 106
#define TELL_STREAM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Seek 107
#define SEEK_STREAM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SEEK_POS num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_EOF 108
#define EOF_STREAM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_WriteByteBuffer 109
#define WRITEBYTEBUFFER_STREAM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define WRITEBYTEBUFFER_BUF num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define WRITEBYTEBUFFER_BUF_SIZE num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_ReadByteBuffer 110
#define READBYTEBUFFER_STREAM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define READBYTEBUFFER_BUF num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define READBYTEBUFFER_BUF_SIZE num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_ChangeDir 111
#define CHANGEDIR_P$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_DirExists 112
#define DIREXISTS_P$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_DirFirst$ 113
#define FN_Dir$ 114
#define FN_DirNext$ 115
#define FN_MakeDir 116
#define MAKEDIR_P$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_RemoveDir 117
#define REMOVEDIR_P$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_Date$ 118
#define FN_Easter$ 119
#define EASTER$_YEAR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Ticks 120
#define FN_Time$ 121
#define FN_Timer 122
#define FN_Wait 123
#define WAIT_M_SEC num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_OpenWindow 124
#define OPENWINDOW_TITLE$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define OPENWINDOW_W num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define OPENWINDOW_H num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define OPENWINDOW_FULLSCREEN num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define OPENWINDOW_VSYNC num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_OpenWindowEx 125
#define OPENWINDOWEX_TITLE$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define OPENWINDOWEX_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define OPENWINDOWEX_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define OPENWINDOWEX_W num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define OPENWINDOWEX_H num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define OPENWINDOWEX_MODE num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define OPENWINDOWEX_AA num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define OPENWINDOWEX_STENCIL_BUFFER num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define OPENWINDOWEX_VSYNC num_var[7].nid_value.value[ num_var[7].byref_offset ]
#define FN_CloseWindow 126
#define FN_RaiseWindow 127
#define FN_Update 128
#define FN_Cls 129
#define FN_SetClearColor 130
#define SETCLEARCOLOR_C num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_ShowWindow 131
#define FN_HideWindow 132
#define FN_SetWindowTitle 133
#define SETWINDOWTITLE_TITLE$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_WindowTitle$ 134
#define FN_SetWindowPosition 135
#define SETWINDOWPOSITION_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETWINDOWPOSITION_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_GetWindowPosition 136
#define GETWINDOWPOSITION_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETWINDOWPOSITION_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_SetWindowSize 137
#define SETWINDOWSIZE_W num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETWINDOWSIZE_H num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_GetWindowSize 138
#define GETWINDOWSIZE_W num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETWINDOWSIZE_H num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_SetWindowMinSize 139
#define SETWINDOWMINSIZE_W num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETWINDOWMINSIZE_H num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_GetWindowMinSize 140
#define GETWINDOWMINSIZE_W num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETWINDOWMINSIZE_H num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_SetWindowMaxSize 141
#define SETWINDOWMAXSIZE_W num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETWINDOWMAXSIZE_H num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_GetWindowMaxSize 142
#define GETWINDOWMAXSIZE_W num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETWINDOWMAXSIZE_H num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_WindowIsFullscreen 143
#define FN_WindowIsVisible 144
#define FN_WindowIsBordered 145
#define FN_WindowIsResizable 146
#define FN_WindowIsMinimized 147
#define FN_WindowIsMaximized 148
#define FN_WindowHasInputFocus 149
#define FN_WindowHasMouseFocus 150
#define FN_SetWindowFullscreen 151
#define SETWINDOWFULLSCREEN_FLAG num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_MaximizeWindow 152
#define FN_MinimizeWindow 153
#define FN_SetWindowBordered 154
#define SETWINDOWBORDERED_FLAG num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_WindowClip 155
#define WINDOWCLIP_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define WINDOWCLIP_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define WINDOWCLIP_W num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define WINDOWCLIP_H num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_WindowExists 156
#define FN_WindowEvent_Close 157
#define FN_WindowEvent_Maximize 158
#define FN_WindowEvent_Minimize 159
#define FN_FPS 160
#define FN_SetWindowIcon 161
#define SETWINDOWICON_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_WindowEvent_Resize 162
#define FN_SetWindowAutoClose 163
#define SETWINDOWAUTOCLOSE_EXIT_ON_CLOSE num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetWindowResizable 164
#define SETWINDOWRESIZABLE_FLAG num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_WindowMode 165
#define WINDOWMODE_VISIBLE num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define WINDOWMODE_FULLSCREEN num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define WINDOWMODE_RESIZABLE num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define WINDOWMODE_BORDERLESS num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define WINDOWMODE_HIGHDPI num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define FN_getWindowMode 166
#define FN_RestoreWindow 167
#define FN_GrabInput 168
#define GRABINPUT_FLAG num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetWindowAlwaysOnTop 169
#define SETWINDOWALWAYSONTOP_FLAG num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetMouseRelative 170
#define SETMOUSERELATIVE_FLAG num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetWindowVSync 171
#define SETWINDOWVSYNC_FLAG num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_FlashWindow 172
#define FLASHWINDOW_FLAG num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_WindowIsGrabbed 173
#define FN_OpenCanvas 174
#define OPENCANVAS_W num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define OPENCANVAS_H num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define OPENCANVAS_VIEWPORT_X num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define OPENCANVAS_VIEWPORT_Y num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define OPENCANVAS_VIEWPORT_W num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define OPENCANVAS_VIEWPORT_H num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define OPENCANVAS_MODE num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define FN_CloseCanvas 175
#define CLOSECANVAS_C_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetCanvas3D 176
#define SETCANVAS3D_C_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCANVAS3D_FLAG num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_SetCanvasVisible 177
#define SETCANVASVISIBLE_C_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCANVASVISIBLE_FLAG num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_CanvasIsVisible 178
#define CANVASISVISIBLE_C_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetCanvasViewport 179
#define SETCANVASVIEWPORT_CNUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCANVASVIEWPORT_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETCANVASVIEWPORT_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETCANVASVIEWPORT_W num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define SETCANVASVIEWPORT_H num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define FN_GetCanvasViewport 180
#define GETCANVASVIEWPORT_C_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETCANVASVIEWPORT_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETCANVASVIEWPORT_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETCANVASVIEWPORT_W num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define GETCANVASVIEWPORT_H num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define FN_Canvas 181
#define CANVAS_C_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetCanvasOffset 182
#define SETCANVASOFFSET_C_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCANVASOFFSET_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETCANVASOFFSET_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_GetCanvasOffset 183
#define GETCANVASOFFSET_C_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETCANVASOFFSET_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETCANVASOFFSET_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_GetCanvasSize 184
#define GETCANVASSIZE_C_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETCANVASSIZE_W num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETCANVASSIZE_H num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_ClearCanvas 185
#define FN_SetCanvasAlpha 186
#define SETCANVASALPHA_C_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCANVASALPHA_A num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_GetCanvasAlpha 187
#define GETCANVASALPHA_C_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetCanvasColorMod 188
#define SETCANVASCOLORMOD_C_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCANVASCOLORMOD_C num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_GetCanvasColorMod 189
#define GETCANVASCOLORMOD_C_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_CloneCanvas 190
#define CLONECANVAS_SRC num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define CLONECANVAS_DST num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_SetCanvasZ 191
#define SETCANVASZ_C_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCANVASZ_Z num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_GetCanvasZ 192
#define GETCANVASZ_C_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_CanvasClip 193
#define CANVASCLIP_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define CANVASCLIP_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define CANVASCLIP_W num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define CANVASCLIP_H num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_ActiveCanvas 194
#define FN_Circle 195
#define CIRCLE_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define CIRCLE_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define CIRCLE_RADIUS num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_CircleFill 196
#define CIRCLEFILL_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define CIRCLEFILL_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define CIRCLEFILL_RADIUS num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_Ellipse 197
#define ELLIPSE_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define ELLIPSE_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define ELLIPSE_RX num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define ELLIPSE_RY num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_EllipseFill 198
#define ELLIPSEFILL_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define ELLIPSEFILL_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define ELLIPSEFILL_RX num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define ELLIPSEFILL_RY num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_FloodFill 199
#define FLOODFILL_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FLOODFILL_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_GetPixel 200
#define GETPIXEL_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETPIXEL_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_SetColor 201
#define SETCOLOR_C num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_Line 202
#define LINE_X1 num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define LINE_Y1 num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define LINE_X2 num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define LINE_Y2 num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_Poly 203
#define POLY_N num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define POLY_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define POLY_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_Rect 204
#define RECT_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define RECT_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define RECT_W num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define RECT_H num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_RectFill 205
#define RECTFILL_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define RECTFILL_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define RECTFILL_W num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define RECTFILL_H num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_RGB 206
#define RGB_R num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define RGB_G num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define RGB_B num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_RGBA 207
#define RGBA_R num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define RGBA_G num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define RGBA_B num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define RGBA_A num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_Pset 208
#define PSET_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define PSET_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_LoadImage 209
#define LOADIMAGE_IMG$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_LoadImageEx 210
#define LOADIMAGEEX_IMG$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define LOADIMAGEEX_COLKEY num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_createImage 211
#define CREATEIMAGE_W num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define CREATEIMAGE_H num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define CREATEIMAGE_BUFFER num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_createImageEx 212
#define CREATEIMAGEEX_W num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define CREATEIMAGEEX_H num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define CREATEIMAGEEX_BUFFER num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define CREATEIMAGEEX_COLOR num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_getImageBuffer 213
#define GETIMAGEBUFFER_IMG_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETIMAGEBUFFER_BUFFER num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_ImageExists 214
#define IMAGEEXISTS_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_ColorKey 215
#define COLORKEY_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define COLORKEY_C num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setBilinearFilter 216
#define SETBILINEARFILTER_FLAG num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getBilinearFilter 217
#define FN_CopyImage 218
#define COPYIMAGE_IMG_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_DeleteImage 219
#define DELETEIMAGE_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetImageAlpha 220
#define SETIMAGEALPHA_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETIMAGEALPHA_A num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_GetImageAlpha 221
#define GETIMAGEALPHA_IMG_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_GetImageSize 222
#define GETIMAGESIZE_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETIMAGESIZE_W num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETIMAGESIZE_H num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_SetBlendMode 223
#define SETBLENDMODE_BLEND_MODE num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_GetBlendMode 224
#define GETBLENDMODE_BLEND_MODE num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetImageColorMod 225
#define SETIMAGECOLORMOD_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETIMAGECOLORMOD_C num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_ImageColorMod 226
#define IMAGECOLORMOD_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_DrawImage 227
#define DRAWIMAGE_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define DRAWIMAGE_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define DRAWIMAGE_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_DrawImage_Blit 228
#define DRAWIMAGE_BLIT_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define DRAWIMAGE_BLIT_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define DRAWIMAGE_BLIT_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define DRAWIMAGE_BLIT_SRC_X num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define DRAWIMAGE_BLIT_SRC_Y num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define DRAWIMAGE_BLIT_SRC_W num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define DRAWIMAGE_BLIT_SRC_H num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define FN_DrawImage_BlitEx 229
#define DRAWIMAGE_BLITEX_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define DRAWIMAGE_BLITEX_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define DRAWIMAGE_BLITEX_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define DRAWIMAGE_BLITEX_W num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define DRAWIMAGE_BLITEX_H num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define DRAWIMAGE_BLITEX_SRC_X num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define DRAWIMAGE_BLITEX_SRC_Y num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define DRAWIMAGE_BLITEX_SRC_W num_var[7].nid_value.value[ num_var[7].byref_offset ]
#define DRAWIMAGE_BLITEX_SRC_H num_var[8].nid_value.value[ num_var[8].byref_offset ]
#define FN_DrawImage_Rotate 230
#define DRAWIMAGE_ROTATE_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define DRAWIMAGE_ROTATE_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define DRAWIMAGE_ROTATE_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define DRAWIMAGE_ROTATE_ANGLE num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_DrawImage_RotateEx 231
#define DRAWIMAGE_ROTATEEX_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define DRAWIMAGE_ROTATEEX_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define DRAWIMAGE_ROTATEEX_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define DRAWIMAGE_ROTATEEX_SRC_X num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define DRAWIMAGE_ROTATEEX_SRC_Y num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define DRAWIMAGE_ROTATEEX_SRC_W num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define DRAWIMAGE_ROTATEEX_SRC_H num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define DRAWIMAGE_ROTATEEX_ANGLE num_var[7].nid_value.value[ num_var[7].byref_offset ]
#define FN_DrawImage_Zoom 232
#define DRAWIMAGE_ZOOM_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define DRAWIMAGE_ZOOM_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define DRAWIMAGE_ZOOM_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define DRAWIMAGE_ZOOM_ZX num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define DRAWIMAGE_ZOOM_ZY num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define FN_DrawImage_ZoomEx 233
#define DRAWIMAGE_ZOOMEX_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define DRAWIMAGE_ZOOMEX_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define DRAWIMAGE_ZOOMEX_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define DRAWIMAGE_ZOOMEX_SRC_X num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define DRAWIMAGE_ZOOMEX_SRC_Y num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define DRAWIMAGE_ZOOMEX_SRC_W num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define DRAWIMAGE_ZOOMEX_SRC_H num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define DRAWIMAGE_ZOOMEX_ZX num_var[7].nid_value.value[ num_var[7].byref_offset ]
#define DRAWIMAGE_ZOOMEX_ZY num_var[8].nid_value.value[ num_var[8].byref_offset ]
#define FN_DrawImage_Rotozoom 234
#define DRAWIMAGE_ROTOZOOM_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define DRAWIMAGE_ROTOZOOM_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define DRAWIMAGE_ROTOZOOM_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define DRAWIMAGE_ROTOZOOM_ANGLE num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define DRAWIMAGE_ROTOZOOM_ZX num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define DRAWIMAGE_ROTOZOOM_ZY num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define FN_DrawImage_RotozoomEx 235
#define DRAWIMAGE_ROTOZOOMEX_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define DRAWIMAGE_ROTOZOOMEX_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define DRAWIMAGE_ROTOZOOMEX_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define DRAWIMAGE_ROTOZOOMEX_SRC_X num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define DRAWIMAGE_ROTOZOOMEX_SRC_Y num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define DRAWIMAGE_ROTOZOOMEX_SRC_W num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define DRAWIMAGE_ROTOZOOMEX_SRC_H num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define DRAWIMAGE_ROTOZOOMEX_ANGLE num_var[7].nid_value.value[ num_var[7].byref_offset ]
#define DRAWIMAGE_ROTOZOOMEX_ZX num_var[8].nid_value.value[ num_var[8].byref_offset ]
#define DRAWIMAGE_ROTOZOOMEX_ZY num_var[9].nid_value.value[ num_var[9].byref_offset ]
#define FN_DrawImage_Flip 236
#define DRAWIMAGE_FLIP_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define DRAWIMAGE_FLIP_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define DRAWIMAGE_FLIP_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define DRAWIMAGE_FLIP_H num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define DRAWIMAGE_FLIP_V num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define FN_DrawImage_FlipEx 237
#define DRAWIMAGE_FLIPEX_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define DRAWIMAGE_FLIPEX_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define DRAWIMAGE_FLIPEX_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define DRAWIMAGE_FLIPEX_SRC_X num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define DRAWIMAGE_FLIPEX_SRC_Y num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define DRAWIMAGE_FLIPEX_SRC_W num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define DRAWIMAGE_FLIPEX_SRC_H num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define DRAWIMAGE_FLIPEX_H num_var[7].nid_value.value[ num_var[7].byref_offset ]
#define DRAWIMAGE_FLIPEX_V num_var[8].nid_value.value[ num_var[8].byref_offset ]
#define FN_InKey 238
#define FN_Key 239
#define KEY_KEY_CODE num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_WaitKey 240
#define FN_HideMouse 241
#define FN_ShowMouse 242
#define FN_MouseIsVisible 243
#define FN_GetMouse 244
#define GETMOUSE_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETMOUSE_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETMOUSE_MB1 num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETMOUSE_MB2 num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define GETMOUSE_MB3 num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define FN_MouseX 245
#define FN_MouseY 246
#define FN_MouseButton 247
#define MOUSEBUTTON_MB num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_GetMouseWheel 248
#define GETMOUSEWHEEL_X_AXIS num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETMOUSEWHEEL_Y_AXIS num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_MouseWheelX 249
#define FN_MouseWheelY 250
#define FN_GetGlobalMouse 251
#define GETGLOBALMOUSE_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETGLOBALMOUSE_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETGLOBALMOUSE_MB1 num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETGLOBALMOUSE_MB2 num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define GETGLOBALMOUSE_MB3 num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define FN_GlobalMouseX 252
#define FN_GlobalMouseY 253
#define FN_WarpMouse 254
#define WARPMOUSE_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define WARPMOUSE_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_WarpMouseGlobal 255
#define WARPMOUSEGLOBAL_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define WARPMOUSEGLOBAL_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_SetMouseZone 256
#define SETMOUSEZONE_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMOUSEZONE_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETMOUSEZONE_W num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETMOUSEZONE_H num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_ClearMouseZone 257
#define FN_SoundFromBuffer 258
#define SOUNDFROMBUFFER_BUFFER num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SOUNDFROMBUFFER_BUFFER_SIZE num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SOUNDFROMBUFFER_VOL num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_LoadSound 259
#define LOADSOUND_SND_FILE$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_LoadMusic 260
#define LOADMUSIC_MUSIC_FILE$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_PlaySound 261
#define PLAYSOUND_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define PLAYSOUND_CHANNEL num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define PLAYSOUND_LOOPS num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_PlaySoundTimed 262
#define PLAYSOUNDTIMED_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define PLAYSOUNDTIMED_CHANNEL num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define PLAYSOUNDTIMED_LOOPS num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define PLAYSOUNDTIMED_MS num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_PlayMusic 263
#define PLAYMUSIC_MLOOPS num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_PauseSound 264
#define PAUSESOUND_CHANNEL num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_ResumeSound 265
#define RESUMESOUND_CHANNEL num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_PauseMusic 266
#define FN_ResumeMusic 267
#define FN_DeleteSound 268
#define DELETESOUND_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_DeleteMusic 269
#define FN_FadeMusicIn 270
#define FADEMUSICIN_FADE_TIME num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FADEMUSICIN_LOOPS num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_FadeMusicOut 271
#define FADEMUSICOUT_FADE_TIME num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_MusicExists 272
#define FN_SetMusicVolume 273
#define SETMUSICVOLUME_VOL num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_GetMusicVolume 274
#define FN_SetMusicPosition 275
#define SETMUSICPOSITION_POS num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_GetMusicPosition 276
#define FN_RewindMusic 277
#define FN_SetSoundChannels 278
#define SETSOUNDCHANNELS_MAX_CHANNELS num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_NumSoundChannels 279
#define FN_SoundIsEnabled 280
#define FN_SoundExists 281
#define SOUNDEXISTS_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetChannelVolume 282
#define SETCHANNELVOLUME_CHANNEL num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCHANNELVOLUME_VOL num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_GetChannelVolume 283
#define GETCHANNELVOLUME_CHANNEL num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetSoundVolume 284
#define SETSOUNDVOLUME_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETSOUNDVOLUME_VOL num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_GetSoundVolume 285
#define GETSOUNDVOLUME_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_StopMusic 286
#define FN_StopSound 287
#define STOPSOUND_CHANNEL num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetChannelPanning 288
#define SETCHANNELPANNING_CHANNEL num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCHANNELPANNING_LEFT_VALUE num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETCHANNELPANNING_RIGHT_VALUE num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_SetChannelDistance 289
#define SETCHANNELDISTANCE_CHANNEL num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCHANNELDISTANCE_DIST_VALUE num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_ChannelIsPlaying 290
#define CHANNELISPLAYING_CHANNEL num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_ChannelIsPaused 291
#define CHANNELISPAUSED_CHANNEL num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_QueryAudioSpec 292
#define QUERYAUDIOSPEC_FREQ num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define QUERYAUDIOSPEC_FORMAT num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define QUERYAUDIOSPEC_CHANNELS num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_MusicIsPlaying 293
#define FN_SetChannelSpacePosition 294
#define SETCHANNELSPACEPOSITION_CHANNEL num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCHANNELSPACEPOSITION_ANGLE num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETCHANNELSPACEPOSITION_DISTANCE num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_NumJoysticks 295
#define FN_NumJoyAxes 296
#define NUMJOYAXES_JOY_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_NumJoyButtons 297
#define NUMJOYBUTTONS_JOY_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_NumJoyHats 298
#define NUMJOYHATS_JOY_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_NumJoyTrackBalls 299
#define NUMJOYTRACKBALLS_JOY_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_JoyAxis 300
#define JOYAXIS_JOY_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define JOYAXIS_JOY_AXIS num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_JoyButton 301
#define JOYBUTTON_JOY_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define JOYBUTTON_JOY_BUTTON num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_JoyHat 302
#define JOYHAT_JOY_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define JOYHAT_JOY_HAT num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_GetJoyTrackBall 303
#define GETJOYTRACKBALL_JOY_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETJOYTRACKBALL_BALL num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETJOYTRACKBALL_DX num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETJOYTRACKBALL_DY num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_JoyName$ 304
#define JOYNAME$_JOY_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_JoystickIsConnected 305
#define JOYSTICKISCONNECTED_JOY_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_JoyRumblePlay 306
#define JOYRUMBLEPLAY_JOY_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define JOYRUMBLEPLAY_STRENGTH num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define JOYRUMBLEPLAY_DURATION num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_JoyRumbleStop 307
#define JOYRUMBLESTOP_JOY_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_JoystickIsHaptic 308
#define JOYSTICKISHAPTIC_JOY_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_LoadFont 309
#define LOADFONT_FNT_FILE$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define LOADFONT_FONT_SIZE num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_DeleteFont 310
#define DELETEFONT_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_FontExists 311
#define FONTEXISTS_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetFont 312
#define SETFONT_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_DrawText 313
#define DRAWTEXT_TXT$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define DRAWTEXT_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define DRAWTEXT_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_RenderText 314
#define RENDERTEXT_SLOT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define RENDERTEXT_TXT$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_GetTextSize 315
#define GETTEXTSIZE_TXT$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define GETTEXTSIZE_W num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETTEXTSIZE_H num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_GetTextWidth 316
#define GETTEXTWIDTH_TXT$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_GetTextHeight 317
#define GETTEXTHEIGHT_TXT$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_TouchPressure 318
#define FN_GetTouch 319
#define GETTOUCH_STATUS num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETTOUCH_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETTOUCH_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETTOUCH_DX num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define GETTOUCH_DY num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define FN_GetMultiTouch 320
#define GETMULTITOUCH_STATUS num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETMULTITOUCH_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETMULTITOUCH_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETMULTITOUCH_FINGERS num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define GETMULTITOUCH_DIST num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define GETMULTITOUCH_THETA num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define FN_GetTouchFinger 321
#define GETTOUCHFINGER_FINGER num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETTOUCHFINGER_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETTOUCHFINGER_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETTOUCHFINGER_PRESSURE num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_NumFingers 322
#define FN_GetAccel 323
#define GETACCEL_ACCEL_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETACCEL_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETACCEL_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETACCEL_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_AccelName$ 324
#define ACCELNAME$_ACCEL_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_NumAccels 325
#define FN_GetGyro 326
#define GETGYRO_GYRO_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETGYRO_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETGYRO_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETGYRO_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_GyroName$ 327
#define GYRONAME$_GYRO_NUM num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_NumGyros 328
#define FN_CheckSockets 329
#define CHECKSOCKETS_TIMEOUT_MS num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_TCP_SocketReady 330
#define TCP_SOCKETREADY_SOCKET num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_UDP_SocketReady 331
#define UDP_SOCKETREADY_SOCKET num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_TCP_OpenSocket 332
#define TCP_OPENSOCKET_HOST$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define TCP_OPENSOCKET_PORT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_TCP_CloseSocket 333
#define TCP_CLOSESOCKET_SOCKET num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_TCP_RemoteHost 334
#define TCP_REMOTEHOST_SOCKET num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_TCP_RemotePort 335
#define TCP_REMOTEPORT_SOCKET num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_TCP_GetData 336
#define TCP_GETDATA_SOCKET num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define TCP_GETDATA_SDATA$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define TCP_GETDATA_NUMBYTES num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_TCP_SendData 337
#define TCP_SENDDATA_SOCKET num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define TCP_SENDDATA_SDATA$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_TCP_AcceptSocket 338
#define TCP_ACCEPTSOCKET_SERVER num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define TCP_ACCEPTSOCKET_CLIENT num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_UDP_OpenSocket 339
#define UDP_OPENSOCKET_PORT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_UDP_CloseSocket 340
#define UDP_CLOSESOCKET_SOCKET num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_UDP_GetData 341
#define UDP_GETDATA_SOCKET num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define UDP_GETDATA_SDATA$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define UDP_GETDATA_HOST$ str_var[1].sid_value.value[ str_var[1].byref_offset ]
#define UDP_GETDATA_PORT num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_UDP_Length 342
#define FN_UDP_MaxLength 343
#define FN_UDP_RemoteHost$ 344
#define UDP_REMOTEHOST$_SOCKET num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_UDP_RemotePort 345
#define UDP_REMOTEPORT_SOCKET num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_UDP_SendData 346
#define UDP_SENDDATA_SOCKET num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define UDP_SENDDATA_SDATA$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define UDP_SENDDATA_HOST$ str_var[1].sid_value.value[ str_var[1].byref_offset ]
#define UDP_SENDDATA_PORT num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_LoadVideo 347
#define LOADVIDEO_VID$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_PlayVideo 348
#define PLAYVIDEO_VLOOPS num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_PauseVideo 349
#define FN_StopVideo 350
#define FN_SetVideoPosition 351
#define SETVIDEOPOSITION_POS num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_ResumeVideo 352
#define FN_GetVideoPosition 353
#define FN_DeleteVideo 354
#define FN_VideoIsPlaying 355
#define FN_VideoEnd 356
#define FN_GetVideoStats 357
#define GETVIDEOSTATS_VFILE$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define GETVIDEOSTATS_VLEN num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETVIDEOSTATS_VFPS num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETVIDEOSTATS_FRAME_W num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETVIDEOSTATS_FRAME_H num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_SetVideoDrawRect 358
#define SETVIDEODRAWRECT_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETVIDEODRAWRECT_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETVIDEODRAWRECT_W num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETVIDEODRAWRECT_H num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_GetVideoDrawRect 359
#define GETVIDEODRAWRECT_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETVIDEODRAWRECT_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETVIDEODRAWRECT_W num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETVIDEODRAWRECT_H num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_GetVideoSize 360
#define GETVIDEOSIZE_W num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETVIDEOSIZE_H num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_VideoExists 361
#define FN_SetVideoAlpha 362
#define SETVIDEOALPHA_A num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetVideoVolume 363
#define SETVIDEOVOLUME_VOL num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_GetVideoVolume 364
#define GETVIDEOVOLUME_VOL num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_System 365
#define SYSTEM_CMD$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_OS$ 366
#define FN_Command$ 367
#define COMMAND$_ARG num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_NumCommands 368
#define FN_Env$ 369
#define ENV$_V$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_SetEnv 370
#define SETENV_VAR$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define SETENV_VALUE$ str_var[1].sid_value.value[ str_var[1].byref_offset ]
#define FN_PrefPath$ 371
#define PREFPATH$_ORG_NAME$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define PREFPATH$_APP_NAME$ str_var[1].sid_value.value[ str_var[1].byref_offset ]
#define FN_Android_GetExternalStoragePath$ 372
#define FN_Android_GetExternalStorageState 373
#define FN_Android_GetInternalStoragePath$ 374
#define FN_Android_JNI_Message$ 375
#define ANDROID_JNI_MESSAGE$_ARG$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_Runtime_Utility_Message$ 376
#define RUNTIME_UTILITY_MESSAGE$_ARG$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_GetDesktopDisplayMode 377
#define GETDESKTOPDISPLAYMODE_INDEX num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETDESKTOPDISPLAYMODE_W num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETDESKTOPDISPLAYMODE_H num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETDESKTOPDISPLAYMODE_FREQ num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_GetPowerInfo 378
#define GETPOWERINFO_STATUS num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETPOWERINFO_SECS num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETPOWERINFO_PCT num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_EvalJS$ 379
#define EVALJS$_JS_CODE$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_SystemReturnStdOut$ 380
#define SYSTEMRETURNSTDOUT$_CMD$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_OpenURL 381
#define OPENURL_URL$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_MessageBox 382
#define MESSAGEBOX_TITLE$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define MESSAGEBOX_MSG$ str_var[1].sid_value.value[ str_var[1].byref_offset ]
#define FN_Runtime$ 383
#define FN_NumCPUs 384
#define FN_DimMatrix 385
#define DIMMATRIX_M_ROWS num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define DIMMATRIX_M_COLS num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_DeleteMatrix 386
#define DELETEMATRIX_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_AddMatrix 387
#define ADDMATRIX_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define ADDMATRIX_MB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define ADDMATRIX_MC num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_AugmentMatrix 388
#define AUGMENTMATRIX_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define AUGMENTMATRIX_MB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define AUGMENTMATRIX_MC num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_CopyMatrix 389
#define COPYMATRIX_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define COPYMATRIX_MB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_InsertMatrixColumns 390
#define INSERTMATRIXCOLUMNS_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define INSERTMATRIXCOLUMNS_C num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define INSERTMATRIXCOLUMNS_NUM_COLS num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_InsertMatrixRows 391
#define INSERTMATRIXROWS_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define INSERTMATRIXROWS_R num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define INSERTMATRIXROWS_NUM_ROWS num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_MultiplyMatrix 392
#define MULTIPLYMATRIX_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define MULTIPLYMATRIX_MB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define MULTIPLYMATRIX_MC num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_CubeMatrix 393
#define CUBEMATRIX_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define CUBEMATRIX_MB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_DeleteMatrixColumns 394
#define DELETEMATRIXCOLUMNS_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define DELETEMATRIXCOLUMNS_C num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define DELETEMATRIXCOLUMNS_NUM_COLS num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_DeleteMatrixRows 395
#define DELETEMATRIXROWS_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define DELETEMATRIXROWS_R num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define DELETEMATRIXROWS_NUM_ROWS num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_ClearMatrix 396
#define CLEARMATRIX_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_ClearMatrixColumns 397
#define CLEARMATRIXCOLUMNS_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define CLEARMATRIXCOLUMNS_C num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define CLEARMATRIXCOLUMNS_NUM_COLS num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_ClearMatrixRows 398
#define CLEARMATRIXROWS_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define CLEARMATRIXROWS_R num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define CLEARMATRIXROWS_NUM_ROWS num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_FillMatrix 399
#define FILLMATRIX_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FILLMATRIX_V num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_FillMatrixColumns 400
#define FILLMATRIXCOLUMNS_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FILLMATRIXCOLUMNS_C num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FILLMATRIXCOLUMNS_NUM_COLS num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FILLMATRIXCOLUMNS_V num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_FillMatrixRows 401
#define FILLMATRIXROWS_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FILLMATRIXROWS_R num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FILLMATRIXROWS_NUM_ROWS num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FILLMATRIXROWS_V num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_CopyMatrixColumns 402
#define COPYMATRIXCOLUMNS_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define COPYMATRIXCOLUMNS_MB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define COPYMATRIXCOLUMNS_C num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define COPYMATRIXCOLUMNS_NUM_COLS num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_CopyMatrixRows 403
#define COPYMATRIXROWS_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define COPYMATRIXROWS_MB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define COPYMATRIXROWS_R num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define COPYMATRIXROWS_NUM_ROWS num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_IdentityMatrix 404
#define IDENTITYMATRIX_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define IDENTITYMATRIX_N num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_SolveMatrix 405
#define SOLVEMATRIX_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SOLVEMATRIX_MB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SOLVEMATRIX_MC num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_IsEqualMatrix 406
#define ISEQUALMATRIX_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define ISEQUALMATRIX_MB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define ISEQUALMATRIX_TOLERANCE num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_Determinant 407
#define DETERMINANT_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_AdjointMatrix 408
#define ADJOINTMATRIX_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define ADJOINTMATRIX_MB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_InvertMatrix 409
#define INVERTMATRIX_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define INVERTMATRIX_MB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_MatrixFromBuffer 410
#define MATRIXFROMBUFFER_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define MATRIXFROMBUFFER_R num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define MATRIXFROMBUFFER_C num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define MATRIXFROMBUFFER_BUFFER num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_GetMatrix 411
#define GETMATRIX_BUFFER num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETMATRIX_MA num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_RandomizeMatrix 412
#define RANDOMIZEMATRIX_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define RANDOMIZEMATRIX_VMIN num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define RANDOMIZEMATRIX_VMAX num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_MatrixValue 413
#define MATRIXVALUE_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define MATRIXVALUE_R num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define MATRIXVALUE_C num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_SetMatrixValue 414
#define SETMATRIXVALUE_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATRIXVALUE_R num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETMATRIXVALUE_C num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETMATRIXVALUE_V num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_ScalarMatrix 415
#define SCALARMATRIX_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SCALARMATRIX_MB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SCALARMATRIX_S_VALUE num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_ScalarMatrixColumns 416
#define SCALARMATRIXCOLUMNS_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SCALARMATRIXCOLUMNS_MB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SCALARMATRIXCOLUMNS_C num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SCALARMATRIXCOLUMNS_NUM_COLS num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define SCALARMATRIXCOLUMNS_S_VALUE num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define FN_ScalarMatrixRows 417
#define SCALARMATRIXROWS_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SCALARMATRIXROWS_MB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SCALARMATRIXROWS_R num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SCALARMATRIXROWS_NUM_ROWS num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define SCALARMATRIXROWS_S_VALUE num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define FN_SquareMatrix 418
#define SQUAREMATRIX_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SQUAREMATRIX_MB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_CofactorMatrix 419
#define COFACTORMATRIX_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define COFACTORMATRIX_R num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define COFACTORMATRIX_C num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_SubtractMatrix 420
#define SUBTRACTMATRIX_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SUBTRACTMATRIX_MB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SUBTRACTMATRIX_MC num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_SwapMatrix 421
#define SWAPMATRIX_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SWAPMATRIX_MB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_SwapMatrixColumn 422
#define SWAPMATRIXCOLUMN_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SWAPMATRIXCOLUMN_C1 num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SWAPMATRIXCOLUMN_C2 num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_SwapMatrixRow 423
#define SWAPMATRIXROW_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SWAPMATRIXROW_R1 num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SWAPMATRIXROW_R2 num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_TransposeMatrix 424
#define TRANSPOSEMATRIX_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define TRANSPOSEMATRIX_MB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_UnAugmentMatrix 425
#define UNAUGMENTMATRIX_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define UNAUGMENTMATRIX_MB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define UNAUGMENTMATRIX_MC num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_ZeroMatrix 426
#define ZEROMATRIX_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_GetMatrixSize 427
#define GETMATRIXSIZE_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETMATRIXSIZE_R num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETMATRIXSIZE_C num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_IncrementMatrixRows 428
#define INCREMENTMATRIXROWS_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define INCREMENTMATRIXROWS_MB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define INCREMENTMATRIXROWS_R num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define INCREMENTMATRIXROWS_NUM_ROWS num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define INCREMENTMATRIXROWS_VALUE num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define FN_IncrementMatrixColumns 429
#define INCREMENTMATRIXCOLUMNS_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define INCREMENTMATRIXCOLUMNS_MB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define INCREMENTMATRIXCOLUMNS_C num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define INCREMENTMATRIXCOLUMNS_NUM_COLS num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define INCREMENTMATRIXCOLUMNS_VALUE num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define FN_JoinMatrixRows 430
#define JOINMATRIXROWS_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define JOINMATRIXROWS_MB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define JOINMATRIXROWS_MC num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_JoinMatrixColumns 431
#define JOINMATRIXCOLUMNS_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define JOINMATRIXCOLUMNS_MB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define JOINMATRIXCOLUMNS_MC num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_ClipMatrix 432
#define CLIPMATRIX_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define CLIPMATRIX_R num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define CLIPMATRIX_C num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define CLIPMATRIX_NUM_ROWS num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define CLIPMATRIX_NUM_COLS num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define CLIPMATRIX_MB num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define FN_SetMatrixTranslation 433
#define SETMATRIXTRANSLATION_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATRIXTRANSLATION_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETMATRIXTRANSLATION_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETMATRIXTRANSLATION_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_SetMatrixRotation 434
#define SETMATRIXROTATION_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATRIXROTATION_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETMATRIXROTATION_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETMATRIXROTATION_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_SetMatrixScale 435
#define SETMATRIXSCALE_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATRIXSCALE_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETMATRIXSCALE_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETMATRIXSCALE_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_GetMatrixTranslation 436
#define GETMATRIXTRANSLATION_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETMATRIXTRANSLATION_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETMATRIXTRANSLATION_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETMATRIXTRANSLATION_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_GetMatrixRotation 437
#define GETMATRIXROTATION_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETMATRIXROTATION_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETMATRIXROTATION_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETMATRIXROTATION_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_GetMatrixScale 438
#define GETMATRIXSCALE_MA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETMATRIXSCALE_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETMATRIXSCALE_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETMATRIXSCALE_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_ClipboardText$ 439
#define FN_SetClipboardText 440
#define SETCLIPBOARDTEXT_TXT$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_HasClipboardText 441
#define FN_ReadInput_Start 442
#define FN_ReadInput_Stop 443
#define FN_ReadInput_Text$ 444
#define FN_ReadInput_SetText 445
#define READINPUT_SETTEXT_TXT$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_ReadInput_ToggleBackspace 446
#define READINPUT_TOGGLEBACKSPACE_FLAG num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_CreateSprite 447
#define CREATESPRITE_IMG num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_DeleteSprite 448
#define DELETESPRITE_SPRITE num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetSpritePosition 449
#define SETSPRITEPOSITION_SPRITE num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETSPRITEPOSITION_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETSPRITEPOSITION_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_LoadMesh 450
#define LOADMESH_MESH_FILE$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_DeleteMesh 451
#define DELETEMESH_MESH num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_CreateMesh 452
#define FN_AddMeshBuffer 453
#define ADDMESHBUFFER_MESH num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define ADDMESHBUFFER_VERTEX_COUNT num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define ADDMESHBUFFER_VERTEX_DATA num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define ADDMESHBUFFER_NORMAL_DATA num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define ADDMESHBUFFER_UV_DATA num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define ADDMESHBUFFER_INDEX_COUNT num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define ADDMESHBUFFER_INDEX_DATA num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define FN_LoadMeshFromArchive 454
#define LOADMESHFROMARCHIVE_ARCHIVE$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define LOADMESHFROMARCHIVE_MESH_FILE$ str_var[1].sid_value.value[ str_var[1].byref_offset ]
#define FN_CreateMeshActor 455
#define CREATEMESHACTOR_MESH num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_CreateMeshOctreeActor 456
#define CREATEMESHOCTREEACTOR_MESH num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_CreateCubeActor 457
#define CREATECUBEACTOR_CUBE_SIZE num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_CreateSphereActor 458
#define CREATESPHEREACTOR_RADIUS num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_CreateWaterPlaneActor 459
#define CREATEWATERPLANEACTOR_W num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define CREATEWATERPLANEACTOR_H num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_CreateLightActor 460
#define FN_CreateBillboardActor 461
#define FN_CreateTerrainActor 462
#define CREATETERRAINACTOR_HMAP_FILE$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_DeleteActor 463
#define DELETEACTOR_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_GetActorTransform 464
#define GETACTORTRANSFORM_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETACTORTRANSFORM_MATRIX num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_SetActorPosition 465
#define SETACTORPOSITION_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORPOSITION_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETACTORPOSITION_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETACTORPOSITION_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_TranslateActor 466
#define TRANSLATEACTOR_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define TRANSLATEACTOR_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define TRANSLATEACTOR_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define TRANSLATEACTOR_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_TranslateActorWorld 467
#define TRANSLATEACTORWORLD_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define TRANSLATEACTORWORLD_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define TRANSLATEACTORWORLD_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define TRANSLATEACTORWORLD_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_GetActorPosition 468
#define GETACTORPOSITION_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETACTORPOSITION_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETACTORPOSITION_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETACTORPOSITION_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_SetActorScale 469
#define SETACTORSCALE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORSCALE_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETACTORSCALE_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETACTORSCALE_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_ScaleActor 470
#define SCALEACTOR_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SCALEACTOR_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SCALEACTOR_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SCALEACTOR_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_GetActorScale 471
#define GETACTORSCALE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETACTORSCALE_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETACTORSCALE_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETACTORSCALE_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_SetActorRotation 472
#define SETACTORROTATION_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORROTATION_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETACTORROTATION_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETACTORROTATION_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_RotateActor 473
#define ROTATEACTOR_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define ROTATEACTOR_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define ROTATEACTOR_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define ROTATEACTOR_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_GetActorRotation 474
#define GETACTORROTATION_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETACTORROTATION_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETACTORROTATION_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETACTORROTATION_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_SetActorVisible 475
#define SETACTORVISIBLE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORVISIBLE_FLAG num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_ActorIsVisible 476
#define ACTORISVISIBLE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetActorAutoCulling 477
#define SETACTORAUTOCULLING_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORAUTOCULLING_CULL_TYPE num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_GetActorAutoCulling 478
#define GETACTORAUTOCULLING_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_AddActorShadow 479
#define ADDACTORSHADOW_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_RemoveActorShadow 480
#define REMOVEACTORSHADOW_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetGravity3D 481
#define SETGRAVITY3D_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETGRAVITY3D_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETGRAVITY3D_Z num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_GetGravity3D 482
#define GETGRAVITY3D_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETGRAVITY3D_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETGRAVITY3D_Z num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_SetActorCollisionShape 483
#define SETACTORCOLLISIONSHAPE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORCOLLISIONSHAPE_SHAPE_TYPE num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETACTORCOLLISIONSHAPE_MASS num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_GetActorCollisionShape 484
#define GETACTORCOLLISIONSHAPE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetActorSolid 485
#define SETACTORSOLID_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORSOLID_FLAG num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_ActorIsSolid 486
#define ACTORISSOLID_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_GetActorCollision 487
#define GETACTORCOLLISION_ACTOR1 num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETACTORCOLLISION_ACTOR2 num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_SetActorGravity 488
#define SETACTORGRAVITY_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORGRAVITY_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETACTORGRAVITY_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETACTORGRAVITY_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_GetActorGravity 489
#define GETACTORGRAVITY_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETACTORGRAVITY_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETACTORGRAVITY_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETACTORGRAVITY_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_setActorDamping 490
#define SETACTORDAMPING_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORDAMPING_LIN_DAMPING num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETACTORDAMPING_ANG_DAMPING num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_getActorLinearDamping 491
#define GETACTORLINEARDAMPING_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getActorAngularDamping 492
#define GETACTORANGULARDAMPING_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getActorLinearSleepThreshold 493
#define GETACTORLINEARSLEEPTHRESHOLD_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getActorAngularSleepThreshold 494
#define GETACTORANGULARSLEEPTHRESHOLD_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_applyActorDamping 495
#define APPLYACTORDAMPING_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define APPLYACTORDAMPING_TIMESTEP num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setActorMassProperties 496
#define SETACTORMASSPROPERTIES_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORMASSPROPERTIES_MASS num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETACTORMASSPROPERTIES_INERTIA_X num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETACTORMASSPROPERTIES_INERTIA_Y num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define SETACTORMASSPROPERTIES_INERTIA_Z num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define FN_getActorLinearFactor 497
#define GETACTORLINEARFACTOR_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETACTORLINEARFACTOR_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETACTORLINEARFACTOR_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETACTORLINEARFACTOR_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_setActorLinearFactor 498
#define SETACTORLINEARFACTOR_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORLINEARFACTOR_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETACTORLINEARFACTOR_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETACTORLINEARFACTOR_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_getActorInverseMass 499
#define GETACTORINVERSEMASS_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_integrateActorVelocities 500
#define INTEGRATEACTORVELOCITIES_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_applyActorCentralForceLocal 501
#define APPLYACTORCENTRALFORCELOCAL_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define APPLYACTORCENTRALFORCELOCAL_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define APPLYACTORCENTRALFORCELOCAL_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define APPLYACTORCENTRALFORCELOCAL_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_applyActorCentralForceWorld 502
#define APPLYACTORCENTRALFORCEWORLD_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define APPLYACTORCENTRALFORCEWORLD_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define APPLYACTORCENTRALFORCEWORLD_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define APPLYACTORCENTRALFORCEWORLD_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_getActorTotalForce 503
#define GETACTORTOTALFORCE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETACTORTOTALFORCE_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETACTORTOTALFORCE_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETACTORTOTALFORCE_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_getActorTotalTorque 504
#define GETACTORTOTALTORQUE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETACTORTOTALTORQUE_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETACTORTOTALTORQUE_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETACTORTOTALTORQUE_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_getActorInverseInertiaDiagLocal 505
#define GETACTORINVERSEINERTIADIAGLOCAL_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETACTORINVERSEINERTIADIAGLOCAL_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETACTORINVERSEINERTIADIAGLOCAL_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETACTORINVERSEINERTIADIAGLOCAL_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_setActorInverseInertiaDiagLocal 506
#define SETACTORINVERSEINERTIADIAGLOCAL_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORINVERSEINERTIADIAGLOCAL_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETACTORINVERSEINERTIADIAGLOCAL_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETACTORINVERSEINERTIADIAGLOCAL_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_setActorSleepThresholds 507
#define SETACTORSLEEPTHRESHOLDS_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORSLEEPTHRESHOLDS_LINEAR num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETACTORSLEEPTHRESHOLDS_ANGULAR num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_applyActorTorqueLocal 508
#define APPLYACTORTORQUELOCAL_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define APPLYACTORTORQUELOCAL_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define APPLYACTORTORQUELOCAL_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define APPLYACTORTORQUELOCAL_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_applyActorTorqueWorld 509
#define APPLYACTORTORQUEWORLD_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define APPLYACTORTORQUEWORLD_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define APPLYACTORTORQUEWORLD_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define APPLYACTORTORQUEWORLD_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_applyActorForceLocal 510
#define APPLYACTORFORCELOCAL_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define APPLYACTORFORCELOCAL_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define APPLYACTORFORCELOCAL_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define APPLYACTORFORCELOCAL_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define APPLYACTORFORCELOCAL_REL_X num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define APPLYACTORFORCELOCAL_REL_Y num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define APPLYACTORFORCELOCAL_REL_Z num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define FN_applyActorForceWorld 511
#define APPLYACTORFORCEWORLD_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define APPLYACTORFORCEWORLD_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define APPLYACTORFORCEWORLD_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define APPLYACTORFORCEWORLD_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define APPLYACTORFORCEWORLD_REL_X num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define APPLYACTORFORCEWORLD_REL_Y num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define APPLYACTORFORCEWORLD_REL_Z num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define FN_applyActorCentralImpulseLocal 512
#define APPLYACTORCENTRALIMPULSELOCAL_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define APPLYACTORCENTRALIMPULSELOCAL_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define APPLYACTORCENTRALIMPULSELOCAL_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define APPLYACTORCENTRALIMPULSELOCAL_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_applyActorCentralImpulseWorld 513
#define APPLYACTORCENTRALIMPULSEWORLD_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define APPLYACTORCENTRALIMPULSEWORLD_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define APPLYACTORCENTRALIMPULSEWORLD_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define APPLYACTORCENTRALIMPULSEWORLD_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_applyActorTorqueImpulseLocal 514
#define APPLYACTORTORQUEIMPULSELOCAL_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define APPLYACTORTORQUEIMPULSELOCAL_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define APPLYACTORTORQUEIMPULSELOCAL_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define APPLYACTORTORQUEIMPULSELOCAL_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_applyActorTorqueImpulseWorld 515
#define APPLYACTORTORQUEIMPULSEWORLD_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define APPLYACTORTORQUEIMPULSEWORLD_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define APPLYACTORTORQUEIMPULSEWORLD_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define APPLYACTORTORQUEIMPULSEWORLD_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_applyActorImpulseLocal 516
#define APPLYACTORIMPULSELOCAL_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define APPLYACTORIMPULSELOCAL_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define APPLYACTORIMPULSELOCAL_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define APPLYACTORIMPULSELOCAL_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define APPLYACTORIMPULSELOCAL_REL_X num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define APPLYACTORIMPULSELOCAL_REL_Y num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define APPLYACTORIMPULSELOCAL_REL_Z num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define FN_applyActorImpulseWorld 517
#define APPLYACTORIMPULSEWORLD_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define APPLYACTORIMPULSEWORLD_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define APPLYACTORIMPULSEWORLD_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define APPLYACTORIMPULSEWORLD_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define APPLYACTORIMPULSEWORLD_REL_X num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define APPLYACTORIMPULSEWORLD_REL_Y num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define APPLYACTORIMPULSEWORLD_REL_Z num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define FN_clearActorForces 518
#define CLEARACTORFORCES_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_updateActorInertiaTensor 519
#define UPDATEACTORINERTIATENSOR_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getActorCOMPosition 520
#define GETACTORCOMPOSITION_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETACTORCOMPOSITION_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETACTORCOMPOSITION_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETACTORCOMPOSITION_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_getActorRotationQ 521
#define GETACTORROTATIONQ_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETACTORROTATIONQ_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETACTORROTATIONQ_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETACTORROTATIONQ_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define GETACTORROTATIONQ_W num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define FN_getActorLinearVelocity 522
#define GETACTORLINEARVELOCITY_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETACTORLINEARVELOCITY_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETACTORLINEARVELOCITY_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETACTORLINEARVELOCITY_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_getActorAngularVelocity 523
#define GETACTORANGULARVELOCITY_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETACTORANGULARVELOCITY_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETACTORANGULARVELOCITY_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETACTORANGULARVELOCITY_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_setActorLinearVelocityLocal 524
#define SETACTORLINEARVELOCITYLOCAL_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORLINEARVELOCITYLOCAL_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETACTORLINEARVELOCITYLOCAL_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETACTORLINEARVELOCITYLOCAL_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_setActorLinearVelocityWorld 525
#define SETACTORLINEARVELOCITYWORLD_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORLINEARVELOCITYWORLD_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETACTORLINEARVELOCITYWORLD_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETACTORLINEARVELOCITYWORLD_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_setActorAngularVelocityLocal 526
#define SETACTORANGULARVELOCITYLOCAL_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORANGULARVELOCITYLOCAL_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETACTORANGULARVELOCITYLOCAL_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETACTORANGULARVELOCITYLOCAL_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_setActorAngularVelocityWorld 527
#define SETACTORANGULARVELOCITYWORLD_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORANGULARVELOCITYWORLD_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETACTORANGULARVELOCITYWORLD_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETACTORANGULARVELOCITYWORLD_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_getActorLocalPointVelocity 528
#define GETACTORLOCALPOINTVELOCITY_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETACTORLOCALPOINTVELOCITY_REL_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETACTORLOCALPOINTVELOCITY_REL_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETACTORLOCALPOINTVELOCITY_REL_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define GETACTORLOCALPOINTVELOCITY_X num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define GETACTORLOCALPOINTVELOCITY_Y num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define GETACTORLOCALPOINTVELOCITY_Z num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define FN_getActorLinearVelocityLocal 529
#define GETACTORLINEARVELOCITYLOCAL_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETACTORLINEARVELOCITYLOCAL_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETACTORLINEARVELOCITYLOCAL_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETACTORLINEARVELOCITYLOCAL_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_getActorAngularVelocityLocal 530
#define GETACTORANGULARVELOCITYLOCAL_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETACTORANGULARVELOCITYLOCAL_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETACTORANGULARVELOCITYLOCAL_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETACTORANGULARVELOCITYLOCAL_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_getActorAABB 531
#define GETACTORAABB_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETACTORAABB_MIN_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETACTORAABB_MIN_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETACTORAABB_MIN_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define GETACTORAABB_MAX_X num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define GETACTORAABB_MAX_Y num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define GETACTORAABB_MAX_Z num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define FN_computeActorImpulseDenominator 532
#define COMPUTEACTORIMPULSEDENOMINATOR_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_POS_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_POS_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_POS_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_NORMAL_X num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_NORMAL_Y num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define COMPUTEACTORIMPULSEDENOMINATOR_NORMAL_Z num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define FN_computeActorAngularImpulseDenominator 533
#define COMPUTEACTORANGULARIMPULSEDENOMINATOR_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define COMPUTEACTORANGULARIMPULSEDENOMINATOR_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define COMPUTEACTORANGULARIMPULSEDENOMINATOR_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define COMPUTEACTORANGULARIMPULSEDENOMINATOR_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_setActorAngularFactor 534
#define SETACTORANGULARFACTOR_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORANGULARFACTOR_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETACTORANGULARFACTOR_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETACTORANGULARFACTOR_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_getActorAngularFactor 535
#define GETACTORANGULARFACTOR_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETACTORANGULARFACTOR_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETACTORANGULARFACTOR_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETACTORANGULARFACTOR_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_computeActorGyroImpulseLocal 536
#define COMPUTEACTORGYROIMPULSELOCAL_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define COMPUTEACTORGYROIMPULSELOCAL_DT num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define COMPUTEACTORGYROIMPULSELOCAL_X num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define COMPUTEACTORGYROIMPULSELOCAL_Y num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define COMPUTEACTORGYROIMPULSELOCAL_Z num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define FN_computeActorGyroImpulseWorld 537
#define COMPUTEACTORGYROIMPULSEWORLD_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define COMPUTEACTORGYROIMPULSEWORLD_DT num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define COMPUTEACTORGYROIMPULSEWORLD_X num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define COMPUTEACTORGYROIMPULSEWORLD_Y num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define COMPUTEACTORGYROIMPULSEWORLD_Z num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define FN_getActorLocalInertia 538
#define GETACTORLOCALINERTIA_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETACTORLOCALINERTIA_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETACTORLOCALINERTIA_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETACTORLOCALINERTIA_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_createPointConstraint 539
#define CREATEPOINTCONSTRAINT_ACTORA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define CREATEPOINTCONSTRAINT_PXA num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define CREATEPOINTCONSTRAINT_PYA num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define CREATEPOINTCONSTRAINT_PZA num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_createPointConstraintEx 540
#define CREATEPOINTCONSTRAINTEX_ACTORA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_ACTORB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PXA num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PYA num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PZA num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PXB num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PYB num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define CREATEPOINTCONSTRAINTEX_PZB num_var[7].nid_value.value[ num_var[7].byref_offset ]
#define FN_setConstraintPivotA 541
#define SETCONSTRAINTPIVOTA_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTPIVOTA_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETCONSTRAINTPIVOTA_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETCONSTRAINTPIVOTA_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_setConstraintPivotB 542
#define SETCONSTRAINTPIVOTB_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTPIVOTB_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETCONSTRAINTPIVOTB_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETCONSTRAINTPIVOTB_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_createHingeConstraint 543
#define CREATEHINGECONSTRAINT_ACTORA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define CREATEHINGECONSTRAINT_PXA num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define CREATEHINGECONSTRAINT_PYA num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define CREATEHINGECONSTRAINT_PZA num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define CREATEHINGECONSTRAINT_AXA num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define CREATEHINGECONSTRAINT_AYA num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define CREATEHINGECONSTRAINT_AZA num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define FN_createHingeConstraintEx 544
#define CREATEHINGECONSTRAINTEX_ACTORA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define CREATEHINGECONSTRAINTEX_ACTORB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define CREATEHINGECONSTRAINTEX_PXA num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define CREATEHINGECONSTRAINTEX_PYA num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define CREATEHINGECONSTRAINTEX_PZA num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define CREATEHINGECONSTRAINTEX_PXB num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define CREATEHINGECONSTRAINTEX_PYB num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define CREATEHINGECONSTRAINTEX_PZB num_var[7].nid_value.value[ num_var[7].byref_offset ]
#define CREATEHINGECONSTRAINTEX_AXA num_var[8].nid_value.value[ num_var[8].byref_offset ]
#define CREATEHINGECONSTRAINTEX_AYA num_var[9].nid_value.value[ num_var[9].byref_offset ]
#define CREATEHINGECONSTRAINTEX_AZA num_var[10].nid_value.value[ num_var[10].byref_offset ]
#define CREATEHINGECONSTRAINTEX_AXB num_var[11].nid_value.value[ num_var[11].byref_offset ]
#define CREATEHINGECONSTRAINTEX_AYB num_var[12].nid_value.value[ num_var[12].byref_offset ]
#define CREATEHINGECONSTRAINTEX_AZB num_var[13].nid_value.value[ num_var[13].byref_offset ]
#define FN_createSlideConstraint 545
#define CREATESLIDECONSTRAINT_ACTORA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define CREATESLIDECONSTRAINT_FRAMEINB_MATRIX num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define CREATESLIDECONSTRAINT_USELINEARREFERENCEFRAMEA num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_createSlideConstraintEx 546
#define CREATESLIDECONSTRAINTEX_ACTORA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define CREATESLIDECONSTRAINTEX_ACTORB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define CREATESLIDECONSTRAINTEX_FRAMEINA_MATRIX num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define CREATESLIDECONSTRAINTEX_FRAMEINB_MATRIX num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define CREATESLIDECONSTRAINTEX_USELINEARREFERENCEFRAMEA num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define FN_createConeConstraint 547
#define CREATECONECONSTRAINT_ACTORA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define CREATECONECONSTRAINT_RBAFRAME_MATRIX num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_createConeConstraintEx 548
#define CREATECONECONSTRAINTEX_ACTORA num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define CREATECONECONSTRAINTEX_ACTORB num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define CREATECONECONSTRAINTEX_RBAFRAME_MATRIX num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define CREATECONECONSTRAINTEX_RBBFRAME_MATRIX num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_deleteConstraint 549
#define DELETECONSTRAINT_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintFrameOffsetA 550
#define GETCONSTRAINTFRAMEOFFSETA_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_RX num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_RY num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETA_RZ num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define FN_getConstraintFrameOffsetB 551
#define GETCONSTRAINTFRAMEOFFSETB_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_RX num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_RY num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define GETCONSTRAINTFRAMEOFFSETB_RZ num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define FN_useConstraintFrameOffset 552
#define USECONSTRAINTFRAMEOFFSET_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define USECONSTRAINTFRAMEOFFSET_FLAG num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getHingeAngle 553
#define GETHINGEANGLE_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getHingeAngleEx 554
#define GETHINGEANGLEEX_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETHINGEANGLEEX_T_MATRIXA num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETHINGEANGLEEX_T_MATRIXB num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_getConstraintBreakingImpulseThreshold 555
#define GETCONSTRAINTBREAKINGIMPULSETHRESHOLD_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintAFrame 556
#define GETCONSTRAINTAFRAME_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETCONSTRAINTAFRAME_MA num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getConstraintBFrame 557
#define GETCONSTRAINTBFRAME_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETCONSTRAINTBFRAME_MA num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setConstraintAxis 558
#define SETCONSTRAINTAXIS_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTAXIS_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETCONSTRAINTAXIS_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETCONSTRAINTAXIS_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_setConstraintBreakingImpulseThreshold 559
#define SETCONSTRAINTBREAKINGIMPULSETHRESHOLD_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTBREAKINGIMPULSETHRESHOLD_THRESHOLD num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setConstraintFrames 560
#define SETCONSTRAINTFRAMES_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTFRAMES_FRAMEA_MATRIX num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETCONSTRAINTFRAMES_FRAMEB_MATRIX num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_setHingeLimit 561
#define SETHINGELIMIT_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETHINGELIMIT_LOW num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETHINGELIMIT_HIGH num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETHINGELIMIT_SOFTNESS num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define SETHINGELIMIT_BIAS_FACTOR num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define SETHINGELIMIT_RELAXATION_FACTOR num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define FN_setConeLimit 562
#define SETCONELIMIT_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONELIMIT_SWINGSPAN1 num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETCONELIMIT_SWINGSPAN2 num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETCONELIMIT_TWISTSPAN num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define SETCONELIMIT_SOFTNESS num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define SETCONELIMIT_BIAS_FACTOR num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define SETCONELIMIT_RELAXATION_FACTOR num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define FN_getConstraintLimitBiasFactor 563
#define GETCONSTRAINTLIMITBIASFACTOR_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getLimitRelaxationFactor 564
#define GETLIMITRELAXATIONFACTOR_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintLimitSign 565
#define GETCONSTRAINTLIMITSIGN_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getHingeSolveLimit 566
#define GETHINGESOLVELIMIT_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_useHingeReferenceFrameA 567
#define USEHINGEREFERENCEFRAMEA_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define USEHINGEREFERENCEFRAMEA_FLAG num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getConstraintAppliedImpulse 568
#define GETCONSTRAINTAPPLIEDIMPULSE_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintFixedActor 569
#define GETCONSTRAINTFIXEDACTOR_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintPivotA 570
#define GETCONSTRAINTPIVOTA_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETCONSTRAINTPIVOTA_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETCONSTRAINTPIVOTA_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETCONSTRAINTPIVOTA_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_getConstraintPivotB 571
#define GETCONSTRAINTPIVOTB_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETCONSTRAINTPIVOTB_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETCONSTRAINTPIVOTB_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETCONSTRAINTPIVOTB_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_getConstraintActorA 572
#define GETCONSTRAINTACTORA_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintActorB 573
#define GETCONSTRAINTACTORB_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setConstraintSolverIterations 574
#define SETCONSTRAINTSOLVERITERATIONS_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTSOLVERITERATIONS_NUM num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getConstraintBiasFactor 575
#define GETCONSTRAINTBIASFACTOR_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintDamping 576
#define GETCONSTRAINTDAMPING_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintFixThresh 577
#define GETCONSTRAINTFIXTHRESH_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintLimit 578
#define GETCONSTRAINTLIMIT_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETCONSTRAINTLIMIT_LIMIT_INDEX num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getConstraintLimitSoftness 579
#define GETCONSTRAINTLIMITSOFTNESS_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintSolverIterations 580
#define GETCONSTRAINTSOLVERITERATIONS_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintAnglePoint 581
#define GETCONSTRAINTANGLEPOINT_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETCONSTRAINTANGLEPOINT_ANGLE num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETCONSTRAINTANGLEPOINT_C_LEN num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETCONSTRAINTANGLEPOINT_X num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define GETCONSTRAINTANGLEPOINT_Y num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define GETCONSTRAINTANGLEPOINT_Z num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define FN_getConstraintAngularOnly 582
#define GETCONSTRAINTANGULARONLY_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintSolveSwingLimit 583
#define GETCONSTRAINTSOLVESWINGLIMIT_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintSolveTwistLimit 584
#define GETCONSTRAINTSOLVETWISTLIMIT_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintSolveLimit 585
#define GETCONSTRAINTSOLVELIMIT_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintSwingSpan1 586
#define GETCONSTRAINTSWINGSPAN1_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintSwingSpan2 587
#define GETCONSTRAINTSWINGSPAN2_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintTwistAngle 588
#define GETCONSTRAINTTWISTANGLE_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintTwistLimitSign 589
#define GETCONSTRAINTTWISTLIMITSIGN_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintTwistSpan 590
#define GETCONSTRAINTTWISTSPAN_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setConstraintAngularOnly 591
#define SETCONSTRAINTANGULARONLY_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTANGULARONLY_FLAG num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setConstraintDamping 592
#define SETCONSTRAINTDAMPING_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTDAMPING_DAMPING num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setConstraintFixThresh 593
#define SETCONSTRAINTFIXTHRESH_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTFIXTHRESH_FIXTHRESH num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getConstraintAnchorA 594
#define GETCONSTRAINTANCHORA_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETCONSTRAINTANCHORA_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETCONSTRAINTANCHORA_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETCONSTRAINTANCHORA_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_getConstraintAnchorB 595
#define GETCONSTRAINTANCHORB_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETCONSTRAINTANCHORB_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETCONSTRAINTANCHORB_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETCONSTRAINTANCHORB_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_getConstraintAngDepth 596
#define GETCONSTRAINTANGDEPTH_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintAngularPos 597
#define GETCONSTRAINTANGULARPOS_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintDampingDirAng 598
#define GETCONSTRAINTDAMPINGDIRANG_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintDampingDirLin 599
#define GETCONSTRAINTDAMPINGDIRLIN_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintDampingLimAng 600
#define GETCONSTRAINTDAMPINGLIMANG_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintDampingLimLin 601
#define GETCONSTRAINTDAMPINGLIMLIN_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintDampingOrthoAng 602
#define GETCONSTRAINTDAMPINGORTHOANG_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintDampingOrthoLin 603
#define GETCONSTRAINTDAMPINGORTHOLIN_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintLinearPos 604
#define GETCONSTRAINTLINEARPOS_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintLinDepth 605
#define GETCONSTRAINTLINDEPTH_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintLowerAngLimit 606
#define GETCONSTRAINTLOWERANGLIMIT_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintLowerLinLimit 607
#define GETCONSTRAINTLOWERLINLIMIT_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintRestitutionDirAng 608
#define GETCONSTRAINTRESTITUTIONDIRANG_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintRestitutionDirLin 609
#define GETCONSTRAINTRESTITUTIONDIRLIN_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintRestitutionLimAng 610
#define GETCONSTRAINTRESTITUTIONLIMANG_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintRestitutionLimLin 611
#define GETCONSTRAINTRESTITUTIONLIMLIN_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintRestitutionOrthoAng 612
#define GETCONSTRAINTRESTITUTIONORTHOANG_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintRestitutionOrthoLin 613
#define GETCONSTRAINTRESTITUTIONORTHOLIN_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintSoftnessDirAng 614
#define GETCONSTRAINTSOFTNESSDIRANG_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintSoftnessDirLin 615
#define GETCONSTRAINTSOFTNESSDIRLIN_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintSoftnessLimAng 616
#define GETCONSTRAINTSOFTNESSLIMANG_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintSoftnessLimLin 617
#define GETCONSTRAINTSOFTNESSLIMLIN_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintSoftnessOrthoAng 618
#define GETCONSTRAINTSOFTNESSORTHOANG_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintSoftnessOrthoLin 619
#define GETCONSTRAINTSOFTNESSORTHOLIN_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintSolveAngLimit 620
#define GETCONSTRAINTSOLVEANGLIMIT_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintSolveLinLimit 621
#define GETCONSTRAINTSOLVELINLIMIT_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintUpperAngLimit 622
#define GETCONSTRAINTUPPERANGLIMIT_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintUpperLinLimit 623
#define GETCONSTRAINTUPPERLINLIMIT_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getConstraintUseFrameOffset 624
#define GETCONSTRAINTUSEFRAMEOFFSET_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setConstraintDampingDirAng 625
#define SETCONSTRAINTDAMPINGDIRANG_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTDAMPINGDIRANG_N num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setConstraintDampingDirLin 626
#define SETCONSTRAINTDAMPINGDIRLIN_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTDAMPINGDIRLIN_N num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setConstraintDampingLimAng 627
#define SETCONSTRAINTDAMPINGLIMANG_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTDAMPINGLIMANG_N num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setConstraintDampingLimLin 628
#define SETCONSTRAINTDAMPINGLIMLIN_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTDAMPINGLIMLIN_N num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setConstraintDampingOrthoAng 629
#define SETCONSTRAINTDAMPINGORTHOANG_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTDAMPINGORTHOANG_N num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setConstraintDampingOrthoLin 630
#define SETCONSTRAINTDAMPINGORTHOLIN_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTDAMPINGORTHOLIN_N num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setConstraintLowerAngLimit 631
#define SETCONSTRAINTLOWERANGLIMIT_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTLOWERANGLIMIT_N num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setConstraintLowerLinLimit 632
#define SETCONSTRAINTLOWERLINLIMIT_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTLOWERLINLIMIT_N num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setConstraintRestitutionDirAng 633
#define SETCONSTRAINTRESTITUTIONDIRANG_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTRESTITUTIONDIRANG_N num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setConstraintRestitutionDirLin 634
#define SETCONSTRAINTRESTITUTIONDIRLIN_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTRESTITUTIONDIRLIN_N num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setConstraintRestitutionLimAng 635
#define SETCONSTRAINTRESTITUTIONLIMANG_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTRESTITUTIONLIMANG_N num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setConstraintRestitutionLimLin 636
#define SETCONSTRAINTRESTITUTIONLIMLIN_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTRESTITUTIONLIMLIN_N num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setConstraintRestitutionOrthoAng 637
#define SETCONSTRAINTRESTITUTIONORTHOANG_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTRESTITUTIONORTHOANG_N num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setConstraintRestitutionOrthoLin 638
#define SETCONSTRAINTRESTITUTIONORTHOLIN_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTRESTITUTIONORTHOLIN_N num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setConstraintSoftnessDirAng 639
#define SETCONSTRAINTSOFTNESSDIRANG_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTSOFTNESSDIRANG_N num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setConstraintSoftnessDirLin 640
#define SETCONSTRAINTSOFTNESSDIRLIN_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTSOFTNESSDIRLIN_N num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setConstraintSoftnessLimAng 641
#define SETCONSTRAINTSOFTNESSLIMANG_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTSOFTNESSLIMANG_N num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setConstraintSoftnessLimLin 642
#define SETCONSTRAINTSOFTNESSLIMLIN_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTSOFTNESSLIMLIN_N num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setConstraintSoftnessOrthoAng 643
#define SETCONSTRAINTSOFTNESSORTHOANG_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTSOFTNESSORTHOANG_N num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setConstraintSoftnessOrthoLin 644
#define SETCONSTRAINTSOFTNESSORTHOLIN_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTSOFTNESSORTHOLIN_N num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setConstraintUpperAngLimit 645
#define SETCONSTRAINTUPPERANGLIMIT_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTUPPERANGLIMIT_N num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setConstraintUpperLinLimit 646
#define SETCONSTRAINTUPPERLINLIMIT_CONSTRAINT_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCONSTRAINTUPPERLINLIMIT_N num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_SetCameraPosition 647
#define SETCAMERAPOSITION_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCAMERAPOSITION_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETCAMERAPOSITION_Z num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_GetCameraPosition 648
#define GETCAMERAPOSITION_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETCAMERAPOSITION_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETCAMERAPOSITION_Z num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_TranslateCamera 649
#define TRANSLATECAMERA_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define TRANSLATECAMERA_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define TRANSLATECAMERA_Z num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_SetCameraRotation 650
#define SETCAMERAROTATION_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETCAMERAROTATION_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETCAMERAROTATION_Z num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_GetCameraRotation 651
#define GETCAMERAROTATION_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETCAMERAROTATION_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETCAMERAROTATION_Z num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_RotateCamera 652
#define ROTATECAMERA_X num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define ROTATECAMERA_Y num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define ROTATECAMERA_Z num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_SetCameraFOV 653
#define SETCAMERAFOV_FOV num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_GetCameraFOV 654
#define FN_SetCameraAspectRatio 655
#define SETCAMERAASPECTRATIO_ASPECT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_GetCameraAspectRatio 656
#define FN_SetCameraFarValue 657
#define SETCAMERAFARVALUE_ZF num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_GetCameraFarValue 658
#define FN_SetCameraNearValue 659
#define SETCAMERANEARVALUE_ZN num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_GetCameraNearValue 660
#define FN_AddSceneSkyBox 661
#define ADDSCENESKYBOX_IMG_TOP num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define ADDSCENESKYBOX_IMG_BOTTOM num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define ADDSCENESKYBOX_IMG_LEFT num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define ADDSCENESKYBOX_IMG_RIGHT num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define ADDSCENESKYBOX_IMG_FRONT num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define ADDSCENESKYBOX_IMG_BACK num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define FN_AddSceneSkyDome 662
#define ADDSCENESKYDOME_IMG num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_AddSceneSkyDomeEx 663
#define ADDSCENESKYDOMEEX_IMG num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define ADDSCENESKYDOMEEX_HORIRES num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define ADDSCENESKYDOMEEX_VERTRES num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define ADDSCENESKYDOMEEX_TXPERCENTAGE num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define ADDSCENESKYDOMEEX_SPHEREPERCENTAGE num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define ADDSCENESKYDOMEEX_RADIUS num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define FN_RemoveSceneSky 664
#define FN_SetWorld3DDeltaTime 665
#define SETWORLD3DDELTATIME_DT num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetWorld3DMaxSubSteps 666
#define SETWORLD3DMAXSUBSTEPS_STEPS num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetWorld3DTimeStep 667
#define SETWORLD3DTIMESTEP_TS num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_startParticleEmitter 668
#define STARTPARTICLEEMITTER_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_stopParticleEmitter 669
#define STOPPARTICLEEMITTER_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setParticleDirection 670
#define SETPARTICLEDIRECTION_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETPARTICLEDIRECTION_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETPARTICLEDIRECTION_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETPARTICLEDIRECTION_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_getParticleDirection 671
#define GETPARTICLEDIRECTION_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETPARTICLEDIRECTION_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETPARTICLEDIRECTION_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETPARTICLEDIRECTION_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_useParticleEveryMeshVertex 672
#define USEPARTICLEEVERYMESHVERTEX_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define USEPARTICLEEVERYMESHVERTEX_FLAG num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_particleIsUsingEveryMeshVertex 673
#define PARTICLEISUSINGEVERYMESHVERTEX_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setParticleNormalDirectionMod 674
#define SETPARTICLENORMALDIRECTIONMOD_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getParticleNormalDirectionMod 675
#define GETPARTICLENORMALDIRECTIONMOD_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_useParticleNormalDirection 676
#define USEPARTICLENORMALDIRECTION_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define USEPARTICLENORMALDIRECTION_FLAG num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_particleIsUsingNormalDirection 677
#define PARTICLEISUSINGNORMALDIRECTION_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setParticleMesh 678
#define SETPARTICLEMESH_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETPARTICLEMESH_MESH num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setParticleMinParticlesPerSecond 679
#define SETPARTICLEMINPARTICLESPERSECOND_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETPARTICLEMINPARTICLESPERSECOND_MINPARTICLESPERSECOND num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getParticleMinParticlesPerSecond 680
#define GETPARTICLEMINPARTICLESPERSECOND_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setParticleMaxParticlesPerSecond 681
#define SETPARTICLEMAXPARTICLESPERSECOND_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETPARTICLEMAXPARTICLESPERSECOND_MAXPARTICLESPERSECOND num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getParticleMaxParticlesPerSecond 682
#define GETPARTICLEMAXPARTICLESPERSECOND_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setParticleMinStartColor 683
#define SETPARTICLEMINSTARTCOLOR_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETPARTICLEMINSTARTCOLOR_COLOR num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getParticleMinStartColor 684
#define GETPARTICLEMINSTARTCOLOR_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setParticleMaxStartColor 685
#define SETPARTICLEMAXSTARTCOLOR_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETPARTICLEMAXSTARTCOLOR_COLOR num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getParticleMaxStartColor 686
#define GETPARTICLEMAXSTARTCOLOR_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setParticleMinLife 687
#define SETPARTICLEMINLIFE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETPARTICLEMINLIFE_MINLIFE num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getParticleMinLife 688
#define GETPARTICLEMINLIFE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setParticleMaxLife 689
#define SETPARTICLEMAXLIFE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETPARTICLEMAXLIFE_MAXLIFE num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getParticleMaxLife 690
#define GETPARTICLEMAXLIFE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setParticleMaxAngle 691
#define SETPARTICLEMAXANGLE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETPARTICLEMAXANGLE_MAXANGLE num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getParticleMaxAngle 692
#define GETPARTICLEMAXANGLE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setParticleMinStartSize 693
#define SETPARTICLEMINSTARTSIZE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETPARTICLEMINSTARTSIZE_W num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETPARTICLEMINSTARTSIZE_H num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_getParticleMinStartSize 694
#define GETPARTICLEMINSTARTSIZE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETPARTICLEMINSTARTSIZE_W num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETPARTICLEMINSTARTSIZE_H num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_setParticleMaxStartSize 695
#define SETPARTICLEMAXSTARTSIZE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETPARTICLEMAXSTARTSIZE_W num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETPARTICLEMAXSTARTSIZE_H num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_getParticleMaxStartSize 696
#define GETPARTICLEMAXSTARTSIZE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETPARTICLEMAXSTARTSIZE_W num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETPARTICLEMAXSTARTSIZE_H num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_setParticleCenter 697
#define SETPARTICLECENTER_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETPARTICLECENTER_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETPARTICLECENTER_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETPARTICLECENTER_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_getParticleCenter 698
#define GETPARTICLECENTER_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETPARTICLECENTER_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETPARTICLECENTER_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETPARTICLECENTER_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_setParticleRadius 699
#define SETPARTICLERADIUS_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETPARTICLERADIUS_RADIUS num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getParticleRadius 700
#define GETPARTICLERADIUS_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setParticleRingThickness 701
#define SETPARTICLERINGTHICKNESS_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETPARTICLERINGTHICKNESS_RINGTHICKNESS num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getParticleRingThickness 702
#define GETPARTICLERINGTHICKNESS_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setParticleBox 703
#define SETPARTICLEBOX_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETPARTICLEBOX_MIN_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETPARTICLEBOX_MIN_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETPARTICLEBOX_MIN_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define SETPARTICLEBOX_MAX_X num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define SETPARTICLEBOX_MAX_Y num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define SETPARTICLEBOX_MAX_Z num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define FN_getParticleBox 704
#define GETPARTICLEBOX_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETPARTICLEBOX_MIN_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETPARTICLEBOX_MIN_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETPARTICLEBOX_MIN_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define GETPARTICLEBOX_MAX_X num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define GETPARTICLEBOX_MAX_Y num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define GETPARTICLEBOX_MAX_Z num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define FN_setParticleNormal 705
#define SETPARTICLENORMAL_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETPARTICLENORMAL_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETPARTICLENORMAL_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETPARTICLENORMAL_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_getParticleNormal 706
#define GETPARTICLENORMAL_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETPARTICLENORMAL_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETPARTICLENORMAL_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETPARTICLENORMAL_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_setParticleLength 707
#define SETPARTICLELENGTH_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETPARTICLELENGTH_P_LEN num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getParticleLength 708
#define GETPARTICLELENGTH_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_useParticleOutlineOnly 709
#define USEPARTICLEOUTLINEONLY_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define USEPARTICLEOUTLINEONLY_FLAG num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_particleIsUsingOutlineOnly 710
#define PARTICLEISUSINGOUTLINEONLY_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_lightIsCastingShadow 711
#define LIGHTISCASTINGSHADOW_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getLightType 712
#define GETLIGHTTYPE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_getLightRadius 713
#define GETLIGHTRADIUS_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setLightType 714
#define SETLIGHTTYPE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETLIGHTTYPE_LIGHT_TYPE num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setLightRadius 715
#define SETLIGHTRADIUS_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETLIGHTRADIUS_RADIUS num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setLightShadowCast 716
#define SETLIGHTSHADOWCAST_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETLIGHTSHADOWCAST_FLAG num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_SetLightAmbientColor 717
#define SETLIGHTAMBIENTCOLOR_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETLIGHTAMBIENTCOLOR_COLOR num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_GetLightAmbientColor 718
#define GETLIGHTAMBIENTCOLOR_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetLightAttenuation 719
#define SETLIGHTATTENUATION_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETLIGHTATTENUATION_L_CONSTANT num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETLIGHTATTENUATION_L_LINEAR num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETLIGHTATTENUATION_L_QUADRATIC num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_GetLightAttenuation 720
#define GETLIGHTATTENUATION_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETLIGHTATTENUATION_CONSTANT num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETLIGHTATTENUATION_LINEAR num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETLIGHTATTENUATION_QUADRATIC num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_SetLightDiffuseColor 721
#define SETLIGHTDIFFUSECOLOR_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETLIGHTDIFFUSECOLOR_COLOR num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_GetLightDiffuseColor 722
#define GETLIGHTDIFFUSECOLOR_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetLightFalloff 723
#define SETLIGHTFALLOFF_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETLIGHTFALLOFF_FALLOFF num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_GetLightFalloff 724
#define GETLIGHTFALLOFF_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetLightInnerCone 725
#define SETLIGHTINNERCONE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETLIGHTINNERCONE_ANGLE num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_GetLightInnerCone 726
#define GETLIGHTINNERCONE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetLightOuterCone 727
#define SETLIGHTOUTERCONE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETLIGHTOUTERCONE_ANGLE num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_GetLightOuterCone 728
#define GETLIGHTOUTERCONE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetLightSpecularColor 729
#define SETLIGHTSPECULARCOLOR_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETLIGHTSPECULARCOLOR_COLOR num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_GetLightSpecularColor 730
#define GETLIGHTSPECULARCOLOR_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_GetTerrainPatchAABB 731
#define GETTERRAINPATCHAABB_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETTERRAINPATCHAABB_PATCHX num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETTERRAINPATCHAABB_PATCHZ num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETTERRAINPATCHAABB_MINX num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define GETTERRAINPATCHAABB_MINY num_var[4].nid_value.value[ num_var[4].byref_offset ]
#define GETTERRAINPATCHAABB_MINZ num_var[5].nid_value.value[ num_var[5].byref_offset ]
#define GETTERRAINPATCHAABB_MAXX num_var[6].nid_value.value[ num_var[6].byref_offset ]
#define GETTERRAINPATCHAABB_MAXY num_var[7].nid_value.value[ num_var[7].byref_offset ]
#define GETTERRAINPATCHAABB_MAXZ num_var[8].nid_value.value[ num_var[8].byref_offset ]
#define FN_GetTerrainPatchLOD 732
#define GETTERRAINPATCHLOD_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETTERRAINPATCHLOD_PATCHX num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETTERRAINPATCHLOD_PATCHZ num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_GetTerrainHeight 733
#define GETTERRAINHEIGHT_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETTERRAINHEIGHT_PATCHX num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETTERRAINHEIGHT_PATCHZ num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_GetTerrainCenter 734
#define GETTERRAINCENTER_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETTERRAINCENTER_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETTERRAINCENTER_Y num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define GETTERRAINCENTER_Z num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_SetTerrainLODDistance 735
#define SETTERRAINLODDISTANCE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETTERRAINLODDISTANCE_LOD num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETTERRAINLODDISTANCE_DISTANCE num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_ScaleTerrainTexture 736
#define SCALETERRAINTEXTURE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SCALETERRAINTEXTURE_SCALE num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SCALETERRAINTEXTURE_SCALE2 num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_SetTerrainCameraMovementDelta 737
#define SETTERRAINCAMERAMOVEMENTDELTA_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETTERRAINCAMERAMOVEMENTDELTA_DELTA num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_SetTerrainCameraRotationDelta 738
#define SETTERRAINCAMERAROTATIONDELTA_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETTERRAINCAMERAROTATIONDELTA_DELTA num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_SetTerrainPatchLOD 739
#define SETTERRAINPATCHLOD_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETTERRAINPATCHLOD_PATCHX num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETTERRAINPATCHLOD_PATCHZ num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define SETTERRAINPATCHLOD_LOD num_var[3].nid_value.value[ num_var[3].byref_offset ]
#define FN_setWaterWindForce 740
#define SETWATERWINDFORCE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETWATERWINDFORCE_F num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getWaterWindForce 741
#define GETWATERWINDFORCE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setWaterWaveHeight 742
#define SETWATERWAVEHEIGHT_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETWATERWAVEHEIGHT_H num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getWaterWaveHeight 743
#define GETWATERWAVEHEIGHT_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setWaterWindDirection 744
#define SETWATERWINDDIRECTION_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETWATERWINDDIRECTION_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETWATERWINDDIRECTION_Z num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_getWaterWindDirection 745
#define GETWATERWINDDIRECTION_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETWATERWINDDIRECTION_X num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETWATERWINDDIRECTION_Z num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_setWaterColor 746
#define SETWATERCOLOR_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETWATERCOLOR_C num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getWaterColor 747
#define GETWATERCOLOR_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setWaterColorBlendFactor 748
#define SETWATERCOLORBLENDFACTOR_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETWATERCOLORBLENDFACTOR_CBFACTOR num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getWaterColorBlendFactor 749
#define GETWATERCOLORBLENDFACTOR_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_SetActorAnimation 750
#define SETACTORANIMATION_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORANIMATION_START_FRAME num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETACTORANIMATION_END_FRAME num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_SetActorAnimationSpeed 751
#define SETACTORANIMATIONSPEED_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORANIMATIONSPEED_SPEED num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_SetActorFrame 752
#define SETACTORFRAME_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORFRAME_FRAME num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_SetActorMD2Animation 753
#define SETACTORMD2ANIMATION_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORMD2ANIMATION_ANIM num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_SetActorMD2AnimationByName 754
#define SETACTORMD2ANIMATIONBYNAME_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORMD2ANIMATIONBYNAME_ANIM_NAME$ str_var[0].sid_value.value[ str_var[0].byref_offset ]
#define FN_GetActorAnimationSpeed 755
#define GETACTORANIMATIONSPEED_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_GetActorEndFrame 756
#define GETACTORENDFRAME_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_GetActorCurrentFrame 757
#define GETACTORCURRENTFRAME_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_GetActorStartFrame 758
#define GETACTORSTARTFRAME_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_StartActorTransition 759
#define STARTACTORTRANSITION_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define STARTACTORTRANSITION_FRAME num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define STARTACTORTRANSITION_TRANSITION_TIME num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_StopActorTransition 760
#define STOPACTORTRANSITION_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_ActorIsInTransition 761
#define ACTORISINTRANSITION_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_GetActorTransitionTime 762
#define GETACTORTRANSITIONTIME_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_actorAnimationIsLooped 763
#define ACTORANIMATIONISLOOPED_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_loopActorAnimation 764
#define LOOPACTORANIMATION_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define LOOPACTORANIMATION_FLAG num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_createMaterial 765
#define FN_deleteMaterial 766
#define DELETEMATERIAL_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setActorMaterial 767
#define SETACTORMATERIAL_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORMATERIAL_MATERIAL_NUM num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETACTORMATERIAL_MATERIAL_ID num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_getActorMaterial 768
#define GETACTORMATERIAL_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETACTORMATERIAL_MATERIAL_NUM num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_copyActorMaterial 769
#define COPYACTORMATERIAL_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define COPYACTORMATERIAL_MATERIAL_NUM num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_copyMaterial 770
#define COPYMATERIAL_SMATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setMaterialTextureCanvas 771
#define SETMATERIALTEXTURECANVAS_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATERIALTEXTURECANVAS_LEVEL num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETMATERIALTEXTURECANVAS_CANVAS_ID num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_setMaterialAmbientColor 772
#define SETMATERIALAMBIENTCOLOR_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATERIALAMBIENTCOLOR_COLOR num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getMaterialAmbientColor 773
#define GETMATERIALAMBIENTCOLOR_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setMaterialAntiAliasing 774
#define SETMATERIALANTIALIASING_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATERIALANTIALIASING_AA num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getMaterialAntiAliasing 775
#define GETMATERIALANTIALIASING_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setMaterialBackfaceCulling 776
#define SETMATERIALBACKFACECULLING_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATERIALBACKFACECULLING_FLAG num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getMaterialBackfaceCulling 777
#define GETMATERIALBACKFACECULLING_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setMaterialBlendFactor 778
#define SETMATERIALBLENDFACTOR_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATERIALBLENDFACTOR_BF num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getMaterialBlendFactor 779
#define GETMATERIALBLENDFACTOR_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setMaterialBlendMode 780
#define SETMATERIALBLENDMODE_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATERIALBLENDMODE_BLEND_MODE num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getMaterialBlendMode 781
#define GETMATERIALBLENDMODE_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setMaterialColorMask 782
#define SETMATERIALCOLORMASK_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATERIALCOLORMASK_COLOR_MASK num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getMaterialColorMask 783
#define GETMATERIALCOLORMASK_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setMaterialColorMode 784
#define SETMATERIALCOLORMODE_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATERIALCOLORMODE_COLOR_MODE num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getMaterialColorMode 785
#define GETMATERIALCOLORMODE_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setMaterialDiffuseColor 786
#define SETMATERIALDIFFUSECOLOR_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATERIALDIFFUSECOLOR_COLOR num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getMaterialDiffuseColor 787
#define GETMATERIALDIFFUSECOLOR_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setMaterialEmissiveColor 788
#define SETMATERIALEMISSIVECOLOR_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATERIALEMISSIVECOLOR_COLOR num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getMaterialEmissiveColor 789
#define GETMATERIALEMISSIVECOLOR_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setMaterialFog 790
#define SETMATERIALFOG_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATERIALFOG_FLAG num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getMaterialFog 791
#define GETMATERIALFOG_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setMaterialFrontfaceCulling 792
#define SETMATERIALFRONTFACECULLING_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATERIALFRONTFACECULLING_FLAG num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getMaterialFrontfaceCulling 793
#define GETMATERIALFRONTFACECULLING_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setMaterialGouraudShading 794
#define SETMATERIALGOURAUDSHADING_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATERIALGOURAUDSHADING_FLAG num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_materialGouraudShading 795
#define MATERIALGOURAUDSHADING_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_materialIsAplhaBlend 796
#define MATERIALISAPLHABLEND_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_materialIsTransparent 797
#define MATERIALISTRANSPARENT_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setMaterialLighting 798
#define SETMATERIALLIGHTING_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATERIALLIGHTING_FLAG num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_materialIsLit 799
#define MATERIALISLIT_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setMaterialType 800
#define SETMATERIALTYPE_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATERIALTYPE_MAT_TYPE num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getMaterialType 801
#define GETMATERIALTYPE_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setMaterialNormalize 802
#define SETMATERIALNORMALIZE_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATERIALNORMALIZE_FLAG num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_materialIsNormalized 803
#define MATERIALISNORMALIZED_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setMaterialPointCloud 804
#define SETMATERIALPOINTCLOUD_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATERIALPOINTCLOUD_FLAG num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_materialIsPointCloud 805
#define MATERIALISPOINTCLOUD_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setMaterialFlag 806
#define SETMATERIALFLAG_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATERIALFLAG_MATERIAL_FLAG num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETMATERIALFLAG_F_VALUE num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_getMaterialFlag 807
#define GETMATERIALFLAG_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETMATERIALFLAG_MATERIAL_FLAG num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_setMaterialTexture 808
#define SETMATERIALTEXTURE_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATERIALTEXTURE_LEVEL num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETMATERIALTEXTURE_IMG_ID num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_setMaterialShininess 809
#define SETMATERIALSHININESS_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATERIALSHININESS_SHININESS num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getMaterialShininess 810
#define GETMATERIALSHININESS_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setMaterialSpecularColor 811
#define SETMATERIALSPECULARCOLOR_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATERIALSPECULARCOLOR_COLOR num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getMaterialSpecularColor 812
#define GETMATERIALSPECULARCOLOR_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setMaterialThickness 813
#define SETMATERIALTHICKNESS_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATERIALTHICKNESS_THICKNESS num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getMaterialThickness 814
#define GETMATERIALTHICKNESS_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setMaterialWireframe 815
#define SETMATERIALWIREFRAME_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETMATERIALWIREFRAME_FLAG num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_materialIsWireframe 816
#define MATERIALISWIREFRAME_MATERIAL_ID num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setActorTexture 817
#define SETACTORTEXTURE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORTEXTURE_LAYER num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETACTORTEXTURE_IMAGE_ID num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_getActorMaterialCount 818
#define GETACTORMATERIALCOUNT_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define FN_setActorMaterialFlag 819
#define SETACTORMATERIALFLAG_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORMATERIALFLAG_FLAG num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define SETACTORMATERIALFLAG_FLAG_VALUE num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_getActorMaterialFlag 820
#define GETACTORMATERIALFLAG_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETACTORMATERIALFLAG_MATERIAL num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define GETACTORMATERIALFLAG_FLAG num_var[2].nid_value.value[ num_var[2].byref_offset ]
#define FN_setActorMaterialType 821
#define SETACTORMATERIALTYPE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define SETACTORMATERIALTYPE_MATERIAL_TYPE num_var[1].nid_value.value[ num_var[1].byref_offset ]
#define FN_getActorMaterialType 822
#define GETACTORMATERIALTYPE_ACTOR num_var[0].nid_value.value[ num_var[0].byref_offset ]
#define GETACTORMATERIALTYPE_MATERIAL num_var[1].nid_value.value[ num_var[1].byref_offset ]


#endif // RC_DEFINES_H_INCLUDED
