case FN_FPrint: //Sub Procedure
	rc_fprint( FPRINT_TXT$ );
	break;
case FN_Input$: //String Function
	 rc_push_str(rc_input( INPUT$_PROMPT$ ));
	break;
case FN_ArrayDim: //Number Function
	//DUMMY CASE

	break;
case FN_StringArrayDim: //Number Function
	rc_push_num( rc_string_array_dim( (rc_strId*) str_var[0].sid_value.ref_parent ) );
	arr_ref_id.clear();

	break;
case FN_NumberArrayDim: //Number Function
	rc_push_num( rc_number_array_dim( (rc_numId*)num_var[0].nid_value.ref_parent ) );
	arr_ref_id.clear();

	break;
case FN_ArraySize: //Number Function
	//DUMMY CASE

	break;
case FN_StringArraySize: //Number Function
	rc_push_num( rc_string_array_size( (rc_strId*) str_var[0].sid_value.ref_parent, STRINGARRAYSIZE_ARRAY_DIM));
	arr_ref_id.clear();

	break;
case FN_NumberArraySize: //Number Function
	rc_push_num( rc_number_array_size( (rc_numId*)num_var[0].nid_value.ref_parent, NUMBERARRAYSIZE_ARRAY_DIM));
	arr_ref_id.clear();

	break;
case FN_NumberArrayCopy: //Sub Procedure
	rc_number_array_copy( &num_var[0], &num_var[1]);
	arr_ref_id.clear();

	break;
case FN_StringArrayCopy: //Sub Procedure
	rc_string_array_copy( &str_var[0], &str_var[1]);
	arr_ref_id.clear();

	break;
case FN_ArrayCopy: //Sub Procedure
	//DUMMY CASE

	break;
case FN_NumberArrayFill: //Sub Procedure
	rc_number_array_fill( &num_var[0], NUMBERARRAYFILL_FDATA);
	arr_ref_id.clear();

	break;
case FN_StringArrayFill: //Sub Procedure
	rc_string_array_fill( &str_var[0], STRINGARRAYFILL_FDATA$);
	arr_ref_id.clear();

	break;
case FN_ArrayFill: //Sub Procedure
	//DUMMY CASE

	break;
case FN_TypeArrayDim: //Number Function
	rc_push_num( rc_type_array_dim( TYPEARRAYDIM_ID ) );
	arr_ref_id.clear();

	break;
case FN_TypeArraySize: //Number Function
	rc_push_num( rc_type_array_size( TYPEARRAYSIZE_ID, TYPEARRAYSIZE_ARRAY_DIM ) );
	arr_ref_id.clear();

	break;
case FN_TypeArrayCopy: //Sub Procedure
	rc_free_type(TYPEARRAYCOPY_DST);
	rc_type_array_copy( TYPEARRAYCOPY_SRC, TYPEARRAYCOPY_DST );

	break;
case FN_TypeArrayFill: //Sub Procedure
	rc_type_array_fill( TYPEARRAYFILL_SRC, &TYPEARRAYFILL_FDATA );

	break;
case FN_Abs: //Number Function
	 rc_push_num(rc_intern_abs( ABS_N ));
	break;
case FN_Acos: //Number Function
	 rc_push_num(rc_intern_aCos( ACOS_N ));
	break;
case FN_AndBit: //Number Function
	 rc_push_num(rc_intern_andBit( ANDBIT_A,  ANDBIT_B ));
	break;
case FN_Asin: //Number Function
	 rc_push_num(rc_intern_aSin( ASIN_N ));
	break;
case FN_Atan: //Number Function
	 rc_push_num(rc_intern_aTan( ATAN_N ));
	break;
case FN_Bin$: //String Function
	 rc_push_str(rc_intern_bin( BIN$_N ));
	break;
case FN_CInt32: //Number Function
	 rc_push_num(rc_intern_cint32( CINT32_I ));
	break;
case FN_CInt64: //Number Function
	 rc_push_num(rc_intern_cint64( CINT64_I ));
	break;
case FN_Cos: //Number Function
	 rc_push_num(rc_intern_cos( COS_N ));
	break;
case FN_Degrees: //Number Function
	 rc_push_num(rc_intern_degrees( DEGREES_R ));
	break;
case FN_Exp: //Number Function
	 rc_push_num(rc_intern_exp( EXP_N ));
	break;
case FN_Frac: //Number Function
	 rc_push_num(rc_intern_frac( FRAC_N ));
	break;
case FN_Hex$: //String Function
	 rc_push_str(rc_intern_hex( HEX$_N ));
	break;
case FN_HexVal: //Number Function
	 rc_push_num(rc_intern_hexInt( HEXVAL_N$ ));
	break;
case FN_Int: //Number Function
	 rc_push_num(rc_intern_int( INT_N ));
	break;
case FN_Log: //Number Function
	 rc_push_num(rc_intern_log( LOG_N ));
	break;
case FN_Max: //Number Function
	 rc_push_num(rc_intern_max( MAX_A,  MAX_B ));
	break;
case FN_Min: //Number Function
	 rc_push_num(rc_intern_min( MIN_A,  MIN_B ));
	break;
case FN_OrBit: //Number Function
	 rc_push_num(rc_intern_orBit( ORBIT_A,  ORBIT_B ));
	break;
case FN_Radians: //Number Function
	 rc_push_num(rc_intern_radians( RADIANS_D ));
	break;
case FN_Randomize: //Number Function
	 rc_push_num(rc_intern_randomize( RANDOMIZE_N ));
	break;
case FN_Rand: //Number Function
	 rc_push_num(rc_intern_rand( RAND_N ));
	break;
case FN_Round: //Number Function
	 rc_push_num(rc_intern_round( ROUND_N ));
	break;
case FN_Sign: //Number Function
	 rc_push_num(rc_intern_sign( SIGN_N ));
	break;
case FN_Sin: //Number Function
	 rc_push_num(rc_intern_sin( SIN_N ));
	break;
case FN_Sqrt: //Number Function
	 rc_push_num(rc_intern_sqrt( SQRT_N ));
	break;
case FN_Tan: //Number Function
	 rc_push_num(rc_intern_tan( TAN_N ));
	break;
case FN_XOrBit: //Number Function
	 rc_push_num(rc_intern_xorbit( XORBIT_A,  XORBIT_B ));
	break;
case FN_GetLineIntersection: //Number Function
	 rc_push_num(GetLineIntersect( GETLINEINTERSECTION_P0_X,  GETLINEINTERSECTION_P0_Y,  GETLINEINTERSECTION_P1_X,  GETLINEINTERSECTION_P1_Y,  GETLINEINTERSECTION_P2_X,  GETLINEINTERSECTION_P2_Y,  GETLINEINTERSECTION_P3_X,  GETLINEINTERSECTION_P3_Y,  &GETLINEINTERSECTION_I_X,  &GETLINEINTERSECTION_I_Y ));
	break;
case FN_Interpolate: //Number Function
	 rc_push_num(Interpolate( INTERPOLATE_MIN_A,  INTERPOLATE_MAX_A,  INTERPOLATE_MID_A,  INTERPOLATE_MIN_B,  INTERPOLATE_MAX_B ));
	break;
case FN_ATan2: //Number Function
	 rc_push_num(atan2( ATAN2_Y,  ATAN2_X ));
	break;
case FN_PointInQuad: //Number Function
	 rc_push_num(PointInQuad( POINTINQUAD_X,  POINTINQUAD_Y,  POINTINQUAD_X1,  POINTINQUAD_Y1,  POINTINQUAD_X2,  POINTINQUAD_Y2,  POINTINQUAD_X3,  POINTINQUAD_Y3,  POINTINQUAD_X4,  POINTINQUAD_Y4 ));
	break;
case FN_PointInTri: //Number Function
	 rc_push_num(PointInTri( POINTINTRI_X,  POINTINTRI_Y,  POINTINTRI_X1,  POINTINTRI_Y1,  POINTINTRI_X2,  POINTINTRI_Y2,  POINTINTRI_X3,  POINTINTRI_Y3 ));
	break;
case FN_Distance2D: //Number Function
	 rc_push_num(Distance2D( DISTANCE2D_X1,  DISTANCE2D_Y1,  DISTANCE2D_X2,  DISTANCE2D_Y2 ));
	break;
case FN_Distance3D: //Number Function
	 rc_push_num(Distance3D( DISTANCE3D_X1,  DISTANCE3D_Y1,  DISTANCE3D_Z1,  DISTANCE3D_X2,  DISTANCE3D_Y2,  DISTANCE3D_Z2 ));
	break;
case FN_GetCircleLineIntersection: //Number Function
	 rc_push_num(GetCircleLineIntersection( GETCIRCLELINEINTERSECTION_CIRCLE_X,  GETCIRCLELINEINTERSECTION_CIRCLE_Y,  GETCIRCLELINEINTERSECTION_RADIUS,  GETCIRCLELINEINTERSECTION_X1,  GETCIRCLELINEINTERSECTION_Y1,  GETCIRCLELINEINTERSECTION_X2,  GETCIRCLELINEINTERSECTION_Y2,  &GETCIRCLELINEINTERSECTION_IX1,  &GETCIRCLELINEINTERSECTION_IY1,  &GETCIRCLELINEINTERSECTION_IX2,  &GETCIRCLELINEINTERSECTION_IY2 ));
	break;
case FN_GetLinePlaneIntersection: //Number Function
	 rc_push_num(GetLinePlaneIntersection( &GETLINEPLANEINTERSECTION_LINE_POINT,  &GETLINEPLANEINTERSECTION_LINE_DIRECTION,  &GETLINEPLANEINTERSECTION_PLANE_POINT_1,  &GETLINEPLANEINTERSECTION_PLANE_POINT_2,  &GETLINEPLANEINTERSECTION_PLANE_POINT_3,  &GETLINEPLANEINTERSECTION_INTERSECTION ));
	break;
case FN_Asc: //Number Function
	 rc_push_num(rc_intern_asc( ASC_C$ ));
	break;
case FN_Chr$: //String Function
	 rc_push_str(rc_intern_chr( CHR$_N ));
	break;
case FN_Insert$: //String Function
	 rc_push_str(rc_intern_insert( INSERT$_SRC$,  INSERT$_TGT$,  INSERT$_POS ));
	break;
case FN_InStr: //Number Function
	 rc_push_num(rc_intern_instr( INSTR_SRC$,  INSTR_SUBSTR$ ));
	break;
case FN_Lcase$: //String Function
	 rc_push_str(rc_intern_lcase( LCASE$_SRC$ ));
	break;
case FN_Left$: //String Function
	 rc_push_str(rc_intern_left( LEFT$_SRC$,  LEFT$_N ));
	break;
case FN_Length: //Number Function
	 rc_push_num(rc_intern_length( LENGTH_SRC$ ));
	break;
case FN_Len: //Number Function
	 rc_push_num(rc_intern_length( LEN_SRC$ ));
	break;
case FN_Ltrim$: //String Function
	 rc_push_str(rc_intern_ltrim( LTRIM$_SRC$ ));
	break;
case FN_Mid$: //String Function
	 rc_push_str(rc_intern_mid( MID$_SRC$,  MID$_START,  MID$_N ));
	break;
case FN_ReplaceSubstr$: //String Function
	 rc_push_str(rc_intern_replaceSubstr( REPLACESUBSTR$_SRC$,  REPLACESUBSTR$_RPC$,  REPLACESUBSTR$_POS ));
	break;
case FN_Replace$: //String Function
	 rc_push_str(rc_intern_replace( REPLACE$_SRC$,  REPLACE$_TGT$,  REPLACE$_RPC$ ));
	break;
case FN_Reverse$: //String Function
	 rc_push_str(rc_intern_reverse( REVERSE$_SRC$ ));
	break;
case FN_Right$: //String Function
	 rc_push_str(rc_intern_right( RIGHT$_SRC$,  RIGHT$_N ));
	break;
case FN_Rtrim$: //String Function
	 rc_push_str(rc_intern_rtrim( RTRIM$_SRC$ ));
	break;
case FN_StringFill$: //String Function
	 rc_push_str(rc_intern_stringfill( STRINGFILL$_SRC$,  STRINGFILL$_N ));
	break;
case FN_Str$: //String Function
	 rc_push_str(rc_intern_str( STR$_N ));
	break;
case FN_Str_F$: //String Function
	 rc_push_str(rc_intern_str_f( STR_F$_N ));
	break;
case FN_Str_S$: //String Function
	 rc_push_str(rc_intern_str_s( STR_S$_N ));
	break;
case FN_Tally: //Number Function
	 rc_push_num(rc_intern_tally( TALLY_SRC$,  TALLY_SUBSTR$ ));
	break;
case FN_Trim$: //String Function
	 rc_push_str(rc_intern_trim( TRIM$_SRC$ ));
	break;
case FN_Ucase$: //String Function
	 rc_push_str(rc_intern_ucase( UCASE$_SRC$ ));
	break;
case FN_Val: //Number Function
	 rc_push_num(rc_intern_val( VAL_N$ ));
	break;
case FN_Size: //Number Function
	 rc_push_num(rc_intern_size( SIZE_S$ ));
	break;
case FN_BufferFromString: //Number Function
	 rc_push_num(rc_intern_bufferFromString( BUFFERFROMSTRING_S$,  &BUFFERFROMSTRING_BUFFER ));
	break;
case FN_StringFromBuffer$: //String Function
	 rc_push_str(rc_intern_stringFromBuffer( &STRINGFROMBUFFER$_BUFFER,  STRINGFROMBUFFER$_BUFFER_SIZE ));
	break;
case FN_CreateStack_N: //Number Function
	 rc_push_num(rc_intern_createStack_N(  ));
	break;
case FN_CreateStack_S: //Number Function
	 rc_push_num(rc_intern_createStack_S(  ));
	break;
case FN_ClearStack_N: //Sub Procedure
	rc_intern_clearStack_N( CLEARSTACK_N_NUM_STACK );
	break;
case FN_ClearStack_S: //Sub Procedure
	rc_intern_clearStack_S( CLEARSTACK_S_STR_STACK );
	break;
case FN_DeleteStack_N: //Sub Procedure
	rc_intern_deleteStack_N( DELETESTACK_N_NUM_STACK );
	break;
case FN_DeleteStack_S: //Sub Procedure
	rc_intern_deleteStack_S( DELETESTACK_S_STR_STACK );
	break;
case FN_Push_N: //Sub Procedure
	rc_intern_push_n( PUSH_N_NUM_STACK,  PUSH_N_N );
	break;
case FN_Pop_N: //Number Function
	 rc_push_num(rc_intern_pop_n( POP_N_NUM_STACK ));
	break;
case FN_Push_S: //Sub Procedure
	rc_intern_push_s( PUSH_S_STR_STACK,  PUSH_S_S$ );
	break;
case FN_Pop_S$: //String Function
	 rc_push_str(rc_intern_pop_s( POP_S$_STR_STACK ));
	break;
case FN_Stack_Size_N: //Number Function
	 rc_push_num(rc_intern_n_stack_size( STACK_SIZE_N_NUM_STACK ));
	break;
case FN_Stack_Size_S: //Number Function
	 rc_push_num(rc_intern_s_stack_size( STACK_SIZE_S_STR_STACK ));
	break;
case FN_OpenFile: //Number Function
	 rc_push_num(rc_intern_fileOpen( OPENFILE_FILENAME$,  OPENFILE_MODE ));
	break;
case FN_CloseFile: //Sub Procedure
	rc_intern_fileClose( CLOSEFILE_STREAM );
	break;
case FN_ReadByte: //Number Function
	 rc_push_num(rc_intern_fileReadByte( READBYTE_STREAM ));
	break;
case FN_WriteByte: //Sub Procedure
	rc_intern_fileWriteByte( WRITEBYTE_STREAM,  WRITEBYTE_BYTE );
	break;
case FN_ReadLine$: //String Function
	 rc_push_str(rc_intern_fileReadLine( READLINE$_STREAM ));
	break;
case FN_Write: //Sub Procedure
	rc_intern_fileWrite( WRITE_STREAM,  WRITE_TXT$ );
	break;
case FN_WriteLine: //Sub Procedure
	rc_intern_fileWriteLine( WRITELINE_STREAM,  WRITELINE_TXT$ );
	break;
case FN_CopyFile: //Sub Procedure
	rc_intern_fileCopy( COPYFILE_SRC$,  COPYFILE_DST$ );
	break;
case FN_RemoveFile: //Number Function
	 rc_push_num(rc_intern_fileDelete( REMOVEFILE_FILENAME$ ));
	break;
case FN_FileExists: //Number Function
	 rc_push_num(rc_intern_fileExist( FILEEXISTS_FILENAME$ ));
	break;
case FN_MoveFile: //Number Function
	 rc_push_num(rc_intern_fileMove( MOVEFILE_SRC$,  MOVEFILE_DST$ ));
	break;
case FN_RenameFile: //Number Function
	 rc_push_num(rc_intern_fileRename( RENAMEFILE_SRC$,  RENAMEFILE_DST$ ));
	break;
case FN_FileLength: //Number Function
	 rc_push_num(rc_intern_fileLength( FILELENGTH_FILENAME$ ));
	break;
case FN_Tell: //Number Function
	 rc_push_num(rc_intern_fileTell( TELL_STREAM ));
	break;
case FN_Seek: //Number Function
	 rc_push_num(rc_intern_fileSeek( SEEK_STREAM,  SEEK_POS ));
	break;
case FN_EOF: //Number Function
	 rc_push_num(rc_intern_eof( EOF_STREAM ));
	break;
case FN_WriteByteBuffer: //Number Function
	 rc_push_num(rc_intern_fileWriteByteBuffer( WRITEBYTEBUFFER_STREAM,  &WRITEBYTEBUFFER_BUF,  WRITEBYTEBUFFER_BUF_SIZE ));
	break;
case FN_ReadByteBuffer: //Number Function
	 rc_push_num(rc_intern_fileReadByteBuffer( READBYTEBUFFER_STREAM,  &READBYTEBUFFER_BUF,  READBYTEBUFFER_BUF_SIZE ));
	break;
case FN_ChangeDir: //Sub Procedure
	rc_intern_dirChange( CHANGEDIR_P$ );
	break;
case FN_DirExists: //Number Function
	 rc_push_num(rc_intern_dirExist( DIREXISTS_P$ ));
	break;
case FN_DirFirst$: //String Function
	 rc_push_str(rc_intern_dirFirst(  ));
	break;
case FN_Dir$: //String Function
	 rc_push_str(rc_intern_dir(  ));
	break;
case FN_DirNext$: //String Function
	 rc_push_str(rc_intern_dirNext(  ));
	break;
case FN_MakeDir: //Number Function
	 rc_push_num(rc_intern_dirCreate( MAKEDIR_P$ ));
	break;
case FN_RemoveDir: //Number Function
	 rc_push_num(rc_intern_dirDelete( REMOVEDIR_P$ ));
	break;
case FN_Date$: //String Function
	 rc_push_str(rc_intern_date(  ));
	break;
case FN_Easter$: //String Function
	 rc_push_str(rc_intern_easter( EASTER$_YEAR ));
	break;
case FN_Ticks: //Number Function
	 rc_push_num(rc_intern_ticks(  ));
	break;
case FN_Time$: //String Function
	 rc_push_str(rc_intern_time(  ));
	break;
case FN_Timer: //Number Function
	 rc_push_num(rc_intern_timer(  ));
	break;
case FN_Wait: //Sub Procedure
	rc_intern_wait( WAIT_M_SEC );
	break;
case FN_OpenWindow: //Number Function
	 rc_push_num(rc_windowOpen( OPENWINDOW_TITLE$,  OPENWINDOW_W,  OPENWINDOW_H,  OPENWINDOW_FULLSCREEN,  OPENWINDOW_VSYNC ));
	break;
case FN_OpenWindowEx: //Number Function
	 rc_push_num(rc_windowOpenEx( OPENWINDOWEX_TITLE$,  OPENWINDOWEX_X,  OPENWINDOWEX_Y,  OPENWINDOWEX_W,  OPENWINDOWEX_H,  OPENWINDOWEX_MODE,  OPENWINDOWEX_AA,  OPENWINDOWEX_STENCIL_BUFFER,  OPENWINDOWEX_VSYNC ));
	break;
case FN_CloseWindow: //Sub Procedure
	rc_closeWindow_hw(  );
	break;
case FN_RaiseWindow: //Sub Procedure
	rc_raiseWindow(  );
	break;
case FN_Update: //Sub Procedure
	rc_update(  );
	break;
case FN_Cls: //Sub Procedure
	rc_cls(  );
	break;
case FN_SetClearColor: //Sub Procedure
	rc_setClearColor( SETCLEARCOLOR_C );
	break;
case FN_ShowWindow: //Sub Procedure
	rc_showWindow(  );
	break;
case FN_HideWindow: //Sub Procedure
	rc_hideWindow(  );
	break;
case FN_SetWindowTitle: //Sub Procedure
	rc_setWindowTitle( SETWINDOWTITLE_TITLE$ );
	break;
case FN_WindowTitle$: //String Function
	 rc_push_str(rc_getWindowTitle(  ));
	break;
case FN_SetWindowPosition: //Sub Procedure
	rc_setWindowPosition( SETWINDOWPOSITION_X,  SETWINDOWPOSITION_Y );
	break;
case FN_GetWindowPosition: //Sub Procedure
	rc_getWindowPosition( &GETWINDOWPOSITION_X,  &GETWINDOWPOSITION_Y );
	break;
case FN_SetWindowSize: //Sub Procedure
	rc_setWindowSize( SETWINDOWSIZE_W,  SETWINDOWSIZE_H );
	break;
case FN_GetWindowSize: //Sub Procedure
	rc_getWindowSize( &GETWINDOWSIZE_W,  &GETWINDOWSIZE_H );
	break;
case FN_SetWindowMinSize: //Sub Procedure
	rc_setWindowMinSize( SETWINDOWMINSIZE_W,  SETWINDOWMINSIZE_H );
	break;
case FN_GetWindowMinSize: //Sub Procedure
	rc_getWindowMinSize( &GETWINDOWMINSIZE_W,  &GETWINDOWMINSIZE_H );
	break;
case FN_SetWindowMaxSize: //Sub Procedure
	rc_setWindowMaxSize( SETWINDOWMAXSIZE_W,  SETWINDOWMAXSIZE_H );
	break;
case FN_GetWindowMaxSize: //Sub Procedure
	rc_getWindowMaxSize( &GETWINDOWMAXSIZE_W,  &GETWINDOWMAXSIZE_H );
	break;
case FN_WindowIsFullscreen: //Number Function
	 rc_push_num(rc_windowIsFullscreen(  ));
	break;
case FN_WindowIsVisible: //Number Function
	 rc_push_num(rc_windowIsVisible(  ));
	break;
case FN_WindowIsBordered: //Number Function
	 rc_push_num(rc_windowIsBordered(  ));
	break;
case FN_WindowIsResizable: //Number Function
	 rc_push_num(rc_windowIsResizable(  ));
	break;
case FN_WindowIsMinimized: //Number Function
	 rc_push_num(rc_windowIsMinimized(  ));
	break;
case FN_WindowIsMaximized: //Number Function
	 rc_push_num(rc_windowIsMaximized(  ));
	break;
case FN_WindowHasInputFocus: //Number Function
	 rc_push_num(rc_windowHasInputFocus(  ));
	break;
case FN_WindowHasMouseFocus: //Number Function
	 rc_push_num(rc_windowHasMouseFocus(  ));
	break;
case FN_SetWindowFullscreen: //Sub Procedure
	rc_setWindowFullscreen( SETWINDOWFULLSCREEN_FLAG );
	break;
case FN_MaximizeWindow: //Sub Procedure
	rc_maximizeWindow(  );
	break;
case FN_MinimizeWindow: //Sub Procedure
	rc_minimizeWindow(  );
	break;
case FN_SetWindowBordered: //Sub Procedure
	rc_setWindowBordered( SETWINDOWBORDERED_FLAG );
	break;
case FN_WindowClip: //Number Function
	 rc_push_num(rc_windowClip( WINDOWCLIP_X,  WINDOWCLIP_Y,  WINDOWCLIP_W,  WINDOWCLIP_H ));
	break;
case FN_WindowExists: //Number Function
	 rc_push_num(rc_windowExists(  ));
	break;
case FN_WindowEvent_Close: //Number Function
	 rc_push_num(rc_windowEvent_Close(  ));
	break;
case FN_WindowEvent_Maximize: //Number Function
	 rc_push_num(rc_windowEvent_Maximize(  ));
	break;
case FN_WindowEvent_Minimize: //Number Function
	 rc_push_num(rc_windowEvent_Minimize(  ));
	break;
case FN_FPS: //Number Function
	 rc_push_num(rc_FPS(  ));
	break;
case FN_SetWindowIcon: //Sub Procedure
	rc_setWindowIcon( SETWINDOWICON_SLOT );
	break;
case FN_WindowEvent_Resize: //Number Function
	 rc_push_num(rc_windowEvent_Resize(  ));
	break;
case FN_SetWindowAutoClose: //Sub Procedure
	rc_setWindowAutoClose( SETWINDOWAUTOCLOSE_EXIT_ON_CLOSE );
	break;
case FN_SetWindowResizable: //Sub Procedure
	rc_setWindowResizable( SETWINDOWRESIZABLE_FLAG );
	break;
case FN_WindowMode: //Number Function
	 rc_push_num(rc_windowMode( WINDOWMODE_VISIBLE,  WINDOWMODE_FULLSCREEN,  WINDOWMODE_RESIZABLE,  WINDOWMODE_BORDERLESS,  WINDOWMODE_HIGHDPI ));
	break;
case FN_getWindowMode: //Number Function
	 rc_push_num(rc_getWindowMode(  ));
	break;
case FN_RestoreWindow: //Sub Procedure
	rc_restoreWindow(  );
	break;
case FN_GrabInput: //Sub Procedure
	rc_grabInput( GRABINPUT_FLAG );
	break;
case FN_SetWindowAlwaysOnTop: //Sub Procedure
	rc_setWindowAlwaysOnTop( SETWINDOWALWAYSONTOP_FLAG );
	break;
case FN_SetMouseRelative: //Sub Procedure
	rc_setMouseRelative( SETMOUSERELATIVE_FLAG );
	break;
case FN_FlashWindow: //Number Function
	 rc_push_num(rc_flashWindow( FLASHWINDOW_FLAG ));
	break;
case FN_WindowIsGrabbed: //Number Function
	 rc_push_num(rc_windowIsGrabbed(  ));
	break;
case FN_PreUpdate: //Sub Procedure
	rc_preUpdate(  );
	break;
case FN_OpenCanvas: //Number Function
	 rc_push_num(rc_canvasOpen( OPENCANVAS_W,  OPENCANVAS_H,  OPENCANVAS_VIEWPORT_X,  OPENCANVAS_VIEWPORT_Y,  OPENCANVAS_VIEWPORT_W,  OPENCANVAS_VIEWPORT_H,  OPENCANVAS_MODE ));
	break;
case FN_CloseCanvas: //Sub Procedure
	rc_canvasClose( CLOSECANVAS_C_NUM );
	break;
case FN_OpenCanvas3D: //Number Function
	 rc_push_num(rc_canvasOpen3D( OPENCANVAS3D_VIEWPORT_X,  OPENCANVAS3D_VIEWPORT_Y,  OPENCANVAS3D_VIEWPORT_W,  OPENCANVAS3D_VIEWPORT_H,  OPENCANVAS3D_MODE ));
	break;
case FN_SetCanvasVisible: //Sub Procedure
	rc_setCanvasVisible( SETCANVASVISIBLE_C_NUM,  SETCANVASVISIBLE_FLAG );
	break;
case FN_CanvasIsVisible: //Number Function
	 rc_push_num(rc_canvasIsVisible( CANVASISVISIBLE_C_NUM ));
	break;
case FN_SetCanvasViewport: //Sub Procedure
	rc_setCanvasViewport( SETCANVASVIEWPORT_CNUM,  SETCANVASVIEWPORT_X,  SETCANVASVIEWPORT_Y,  SETCANVASVIEWPORT_W,  SETCANVASVIEWPORT_H );
	break;
case FN_GetCanvasViewport: //Sub Procedure
	rc_getCanvasViewport( GETCANVASVIEWPORT_C_NUM,  &GETCANVASVIEWPORT_X,  &GETCANVASVIEWPORT_Y,  &GETCANVASVIEWPORT_W,  &GETCANVASVIEWPORT_H );
	break;
case FN_Canvas: //Sub Procedure
	rc_setActiveCanvas( CANVAS_C_NUM );
	break;
case FN_SetCanvasOffset: //Sub Procedure
	rc_setCanvasOffset( SETCANVASOFFSET_C_NUM,  SETCANVASOFFSET_X,  SETCANVASOFFSET_Y );
	break;
case FN_GetCanvasOffset: //Sub Procedure
	rc_getCanvasOffset( GETCANVASOFFSET_C_NUM,  &GETCANVASOFFSET_X,  &GETCANVASOFFSET_Y );
	break;
case FN_GetCanvasSize: //Sub Procedure
	rc_getCanvasSize( GETCANVASSIZE_C_NUM,  &GETCANVASSIZE_W,  &GETCANVASSIZE_H );
	break;
case FN_ClearCanvas: //Sub Procedure
	rc_clearCanvas(  );
	break;
case FN_SetCanvasAlpha: //Sub Procedure
	rc_setCanvasAlpha( SETCANVASALPHA_C_NUM,  SETCANVASALPHA_A );
	break;
case FN_GetCanvasAlpha: //Number Function
	 rc_push_num(rc_canvasAlpha( GETCANVASALPHA_C_NUM ));
	break;
case FN_SetCanvasColorMod: //Sub Procedure
	rc_setCanvasColorMod( SETCANVASCOLORMOD_C_NUM,  SETCANVASCOLORMOD_C );
	break;
case FN_GetCanvasColorMod: //Number Function
	 rc_push_num(rc_getCanvasColorMod( GETCANVASCOLORMOD_C_NUM ));
	break;
case FN_CloneCanvas: //Number Function
	 rc_push_num(rc_cloneCanvas( CLONECANVAS_C_NUM,  CLONECANVAS_MODE ));
	break;
case FN_SetCanvasZ: //Sub Procedure
	rc_setCanvasZ( SETCANVASZ_C_NUM,  SETCANVASZ_Z );
	break;
case FN_CanvasZ: //Number Function
	 rc_push_num(rc_getCanvasZ( CANVASZ_C_NUM ));
	break;
case FN_CanvasClip: //Number Function
	 rc_push_num(rc_canvasClip( CANVASCLIP_X,  CANVASCLIP_Y,  CANVASCLIP_W,  CANVASCLIP_H ));
	break;
case FN_ActiveCanvas: //Number Function
	 rc_push_num(rc_activeCanvas(  ));
	break;
case FN_SetCanvasPhysics2D: //Sub Procedure
	rc_setCanvasPhysics2D( SETCANVASPHYSICS2D_C_NUM,  SETCANVASPHYSICS2D_STATE );
	break;
case FN_OpenCanvasSpriteLayer: //Number Function
	 rc_push_num(rc_canvasOpenSpriteLayer( OPENCANVASSPRITELAYER_VIEWPORT_X,  OPENCANVASSPRITELAYER_VIEWPORT_Y,  OPENCANVASSPRITELAYER_VIEWPORT_W,  OPENCANVASSPRITELAYER_VIEWPORT_H ));
	break;
case FN_Circle: //Sub Procedure
	rc_drawCircle( CIRCLE_X,  CIRCLE_Y,  CIRCLE_RADIUS );
	break;
case FN_CircleFill: //Sub Procedure
	rc_drawCircleFill( CIRCLEFILL_X,  CIRCLEFILL_Y,  CIRCLEFILL_RADIUS );
	break;
case FN_Ellipse: //Sub Procedure
	rc_drawEllipse( ELLIPSE_X,  ELLIPSE_Y,  ELLIPSE_RX,  ELLIPSE_RY );
	break;
case FN_EllipseFill: //Sub Procedure
	rc_drawEllipseFill( ELLIPSEFILL_X,  ELLIPSEFILL_Y,  ELLIPSEFILL_RX,  ELLIPSEFILL_RY );
	break;
case FN_FloodFill: //Sub Procedure
	rc_floodFill( FLOODFILL_X,  FLOODFILL_Y );
	break;
case FN_GetPixel: //Number Function
	 rc_push_num(rc_getPixel( GETPIXEL_X,  GETPIXEL_Y ));
	break;
case FN_SetColor: //Sub Procedure
	rc_setColor( SETCOLOR_C );
	break;
case FN_Line: //Sub Procedure
	rc_drawLine( LINE_X1,  LINE_Y1,  LINE_X2,  LINE_Y2 );
	break;
case FN_Poly: //Sub Procedure
	rc_poly( POLY_N,  &POLY_X,  &POLY_Y );
	break;
case FN_Rect: //Sub Procedure
	rc_drawRect( RECT_X,  RECT_Y,  RECT_W,  RECT_H );
	break;
case FN_RectFill: //Sub Procedure
	rc_drawRectFill( RECTFILL_X,  RECTFILL_Y,  RECTFILL_W,  RECTFILL_H );
	break;
case FN_RGB: //Number Function
	 rc_push_num(rc_rgb( RGB_R,  RGB_G,  RGB_B ));
	break;
case FN_RGBA: //Number Function
	 rc_push_num(rc_rgba( RGBA_R,  RGBA_G,  RGBA_B,  RGBA_A ));
	break;
case FN_Pset: //Sub Procedure
	rc_drawPixel( PSET_X,  PSET_Y );
	break;
case FN_Triangle: //Sub Procedure
	rc_drawTriangle( TRIANGLE_X1,  TRIANGLE_Y1,  TRIANGLE_X2,  TRIANGLE_Y2,  TRIANGLE_X3,  TRIANGLE_Y3 );
	break;
case FN_Line3D: //Sub Procedure
	rc_drawLine3D( LINE3D_X1,  LINE3D_Y1,  LINE3D_Z1,  LINE3D_X2,  LINE3D_Y2,  LINE3D_Z2 );
	break;
case FN_Box3D: //Sub Procedure
	rc_drawBox3D( BOX3D_MIN_X,  BOX3D_MIN_Y,  BOX3D_MIN_Z,  BOX3D_MAX_X,  BOX3D_MAX_Y,  BOX3D_MAX_Z );
	break;
case FN_Triangle3D: //Sub Procedure
	rc_drawTriangle3D( TRIANGLE3D_X1,  TRIANGLE3D_Y1,  TRIANGLE3D_Z1,  TRIANGLE3D_X2,  TRIANGLE3D_Y2,  TRIANGLE3D_Z2,  TRIANGLE3D_X3,  TRIANGLE3D_Y3,  TRIANGLE3D_Z3 );
	break;
case FN_LoadImage: //Number Function
	 rc_push_num(rc_loadImage( LOADIMAGE_IMG$ ));
	break;
case FN_LoadImageEx: //Number Function
	 rc_push_num(rc_loadImageEx( LOADIMAGEEX_IMG$,  LOADIMAGEEX_COLKEY ));
	break;
case FN_createImage: //Number Function
	 rc_push_num(rc_createImage( CREATEIMAGE_W,  CREATEIMAGE_H,  &CREATEIMAGE_BUFFER ));
	break;
case FN_createImageEx: //Number Function
	 rc_push_num(rc_createImageEx( CREATEIMAGEEX_W,  CREATEIMAGEEX_H,  &CREATEIMAGEEX_BUFFER,  CREATEIMAGEEX_COLOR ));
	break;
case FN_BufferFromImage: //Sub Procedure
	rc_getImageBuffer( BUFFERFROMIMAGE_SLOT,  &BUFFERFROMIMAGE_BUFFER );
	break;
case FN_ImageExists: //Number Function
	 rc_push_num(rc_imageExists( IMAGEEXISTS_SLOT ));
	break;
case FN_ColorKey: //Sub Procedure
	rc_setColorKey( COLORKEY_SLOT,  COLORKEY_C );
	break;
case FN_setBilinearFilter: //Sub Procedure
	rc_setBilinearFilter( SETBILINEARFILTER_FLAG );
	break;
case FN_getBilinearFilter: //Number Function
	 rc_push_num(rc_getBilinearFilter(  ));
	break;
case FN_CopyImage: //Number Function
	 rc_push_num(rc_copyImage( COPYIMAGE_IMG_ID ));
	break;
case FN_DeleteImage: //Sub Procedure
	rc_deleteImage( DELETEIMAGE_SLOT );
	break;
case FN_SetImageAlpha: //Sub Procedure
	rc_setImageAlpha( SETIMAGEALPHA_SLOT,  SETIMAGEALPHA_A );
	break;
case FN_GetImageAlpha: //Number Function
	 rc_push_num(rc_getImageAlpha( GETIMAGEALPHA_IMG_ID ));
	break;
case FN_GetImageSize: //Sub Procedure
	rc_getImageSize( GETIMAGESIZE_SLOT,  &GETIMAGESIZE_W,  &GETIMAGESIZE_H );
	break;
case FN_SetBlendMode: //Sub Procedure
	rc_setBlendMode( SETBLENDMODE_BLEND_MODE );
	break;
case FN_GetBlendMode: //Number Function
	 rc_push_num(rc_getBlendMode(  ));
	break;
case FN_SetImageColorMod: //Sub Procedure
	rc_setImageColorMod( SETIMAGECOLORMOD_SLOT,  SETIMAGECOLORMOD_C );
	break;
case FN_GetImageColorMod: //Number Function
	 rc_push_num(rc_getImageColorMod( GETIMAGECOLORMOD_SLOT ));
	break;
case FN_DrawImage: //Sub Procedure
	rc_drawImage( DRAWIMAGE_SLOT,  DRAWIMAGE_X,  DRAWIMAGE_Y );
	break;
case FN_DrawImage_Blit: //Sub Procedure
	rc_drawImage_Blit( DRAWIMAGE_BLIT_SLOT,  DRAWIMAGE_BLIT_X,  DRAWIMAGE_BLIT_Y,  DRAWIMAGE_BLIT_SRC_X,  DRAWIMAGE_BLIT_SRC_Y,  DRAWIMAGE_BLIT_SRC_W,  DRAWIMAGE_BLIT_SRC_H );
	break;
case FN_DrawImage_BlitEx: //Sub Procedure
	rc_drawImage_BlitEx( DRAWIMAGE_BLITEX_SLOT,  DRAWIMAGE_BLITEX_X,  DRAWIMAGE_BLITEX_Y,  DRAWIMAGE_BLITEX_W,  DRAWIMAGE_BLITEX_H,  DRAWIMAGE_BLITEX_SRC_X,  DRAWIMAGE_BLITEX_SRC_Y,  DRAWIMAGE_BLITEX_SRC_W,  DRAWIMAGE_BLITEX_SRC_H );
	break;
case FN_DrawImage_Rotate: //Sub Procedure
	rc_drawImage_Rotate( DRAWIMAGE_ROTATE_SLOT,  DRAWIMAGE_ROTATE_X,  DRAWIMAGE_ROTATE_Y,  DRAWIMAGE_ROTATE_ANGLE );
	break;
case FN_DrawImage_RotateEx: //Sub Procedure
	rc_drawImage_RotateEx( DRAWIMAGE_ROTATEEX_SLOT,  DRAWIMAGE_ROTATEEX_X,  DRAWIMAGE_ROTATEEX_Y,  DRAWIMAGE_ROTATEEX_SRC_X,  DRAWIMAGE_ROTATEEX_SRC_Y,  DRAWIMAGE_ROTATEEX_SRC_W,  DRAWIMAGE_ROTATEEX_SRC_H,  DRAWIMAGE_ROTATEEX_ANGLE );
	break;
case FN_DrawImage_Zoom: //Sub Procedure
	rc_drawImage_Zoom( DRAWIMAGE_ZOOM_SLOT,  DRAWIMAGE_ZOOM_X,  DRAWIMAGE_ZOOM_Y,  DRAWIMAGE_ZOOM_ZX,  DRAWIMAGE_ZOOM_ZY );
	break;
case FN_DrawImage_ZoomEx: //Sub Procedure
	rc_drawImage_ZoomEx( DRAWIMAGE_ZOOMEX_SLOT,  DRAWIMAGE_ZOOMEX_X,  DRAWIMAGE_ZOOMEX_Y,  DRAWIMAGE_ZOOMEX_SRC_X,  DRAWIMAGE_ZOOMEX_SRC_Y,  DRAWIMAGE_ZOOMEX_SRC_W,  DRAWIMAGE_ZOOMEX_SRC_H,  DRAWIMAGE_ZOOMEX_ZX,  DRAWIMAGE_ZOOMEX_ZY );
	break;
case FN_DrawImage_Rotozoom: //Sub Procedure
	rc_drawImage_Rotozoom( DRAWIMAGE_ROTOZOOM_SLOT,  DRAWIMAGE_ROTOZOOM_X,  DRAWIMAGE_ROTOZOOM_Y,  DRAWIMAGE_ROTOZOOM_ANGLE,  DRAWIMAGE_ROTOZOOM_ZX,  DRAWIMAGE_ROTOZOOM_ZY );
	break;
case FN_DrawImage_RotozoomEx: //Sub Procedure
	rc_drawImage_RotozoomEx( DRAWIMAGE_ROTOZOOMEX_SLOT,  DRAWIMAGE_ROTOZOOMEX_X,  DRAWIMAGE_ROTOZOOMEX_Y,  DRAWIMAGE_ROTOZOOMEX_SRC_X,  DRAWIMAGE_ROTOZOOMEX_SRC_Y,  DRAWIMAGE_ROTOZOOMEX_SRC_W,  DRAWIMAGE_ROTOZOOMEX_SRC_H,  DRAWIMAGE_ROTOZOOMEX_ANGLE,  DRAWIMAGE_ROTOZOOMEX_ZX,  DRAWIMAGE_ROTOZOOMEX_ZY );
	break;
case FN_DrawImage_Flip: //Sub Procedure
	rc_drawImage_Flip( DRAWIMAGE_FLIP_SLOT,  DRAWIMAGE_FLIP_X,  DRAWIMAGE_FLIP_Y,  DRAWIMAGE_FLIP_H,  DRAWIMAGE_FLIP_V );
	break;
case FN_DrawImage_FlipEx: //Sub Procedure
	rc_drawImage_FlipEx( DRAWIMAGE_FLIPEX_SLOT,  DRAWIMAGE_FLIPEX_X,  DRAWIMAGE_FLIPEX_Y,  DRAWIMAGE_FLIPEX_SRC_X,  DRAWIMAGE_FLIPEX_SRC_Y,  DRAWIMAGE_FLIPEX_SRC_W,  DRAWIMAGE_FLIPEX_SRC_H,  DRAWIMAGE_FLIPEX_H,  DRAWIMAGE_FLIPEX_V );
	break;
case FN_InKey: //Number Function
	 rc_push_num(rc_inKey(  ));
	break;
case FN_Key: //Number Function
	 rc_push_num(rc_key( KEY_KEY_CODE ));
	break;
case FN_WaitKey: //Number Function
	 rc_push_num(rc_waitKey(  ));
	break;
case FN_HideMouse: //Sub Procedure
	rc_hideMouse(  );
	break;
case FN_ShowMouse: //Sub Procedure
	rc_showMouse(  );
	break;
case FN_MouseIsVisible: //Number Function
	 rc_push_num(rc_mouseIsVisible(  ));
	break;
case FN_GetMouse: //Sub Procedure
	rc_getMouse( &GETMOUSE_X,  &GETMOUSE_Y,  &GETMOUSE_MB1,  &GETMOUSE_MB2,  &GETMOUSE_MB3 );
	break;
case FN_MouseX: //Number Function
	 rc_push_num(rc_mouseX(  ));
	break;
case FN_MouseY: //Number Function
	 rc_push_num(rc_mouseY(  ));
	break;
case FN_MouseButton: //Number Function
	 rc_push_num(rc_mouseButton( MOUSEBUTTON_MB ));
	break;
case FN_GetMouseWheel: //Sub Procedure
	rc_getMouseWheel( &GETMOUSEWHEEL_X_AXIS,  &GETMOUSEWHEEL_Y_AXIS );
	break;
case FN_MouseWheelX: //Number Function
	 rc_push_num(rc_mouseWheelX(  ));
	break;
case FN_MouseWheelY: //Number Function
	 rc_push_num(rc_mouseWheelY(  ));
	break;
case FN_GetGlobalMouse: //Sub Procedure
	rc_getGlobalMouse( &GETGLOBALMOUSE_X,  &GETGLOBALMOUSE_Y,  &GETGLOBALMOUSE_MB1,  &GETGLOBALMOUSE_MB2,  &GETGLOBALMOUSE_MB3 );
	break;
case FN_GlobalMouseX: //Number Function
	 rc_push_num(rc_globalMouseX(  ));
	break;
case FN_GlobalMouseY: //Number Function
	 rc_push_num(rc_globalMouseY(  ));
	break;
case FN_WarpMouse: //Sub Procedure
	rc_warpMouse( WARPMOUSE_X,  WARPMOUSE_Y );
	break;
case FN_WarpMouseGlobal: //Sub Procedure
	rc_warpMouseGlobal( WARPMOUSEGLOBAL_X,  WARPMOUSEGLOBAL_Y );
	break;
case FN_SetMouseZone: //Sub Procedure
	rc_setMouseZone( SETMOUSEZONE_X,  SETMOUSEZONE_Y,  SETMOUSEZONE_W,  SETMOUSEZONE_H );
	break;
case FN_ClearMouseZone: //Sub Procedure
	rc_clearMouseZone(  );
	break;
case FN_CreateSound: //Number Function
	 rc_push_num(rc_createSound( &CREATESOUND_BUFFER,  CREATESOUND_BUFFER_SIZE,  CREATESOUND_VOL ));
	break;
case FN_LoadSound: //Number Function
	 rc_push_num(rc_loadSound( LOADSOUND_SND_FILE$ ));
	break;
case FN_LoadMusic: //Sub Procedure
	rc_loadMusic( LOADMUSIC_MUSIC_FILE$ );
	break;
case FN_PlaySound: //Sub Procedure
	rc_playSound( PLAYSOUND_SLOT,  PLAYSOUND_CHANNEL,  PLAYSOUND_LOOPS );
	break;
case FN_PlaySoundTimed: //Sub Procedure
	rc_playSoundTimed( PLAYSOUNDTIMED_SLOT,  PLAYSOUNDTIMED_CHANNEL,  PLAYSOUNDTIMED_LOOPS,  PLAYSOUNDTIMED_MS );
	break;
case FN_PlayMusic: //Sub Procedure
	rc_playMusic( PLAYMUSIC_MLOOPS );
	break;
case FN_PauseSound: //Sub Procedure
	rc_pauseSound( PAUSESOUND_CHANNEL );
	break;
case FN_ResumeSound: //Sub Procedure
	rc_resumeSound( RESUMESOUND_CHANNEL );
	break;
case FN_PauseMusic: //Sub Procedure
	rc_pauseMusic(  );
	break;
case FN_ResumeMusic: //Sub Procedure
	rc_resumeMusic(  );
	break;
case FN_DeleteSound: //Sub Procedure
	rc_deleteSound( DELETESOUND_SLOT );
	break;
case FN_DeleteMusic: //Sub Procedure
	rc_deleteMusic(  );
	break;
case FN_FadeMusicIn: //Sub Procedure
	rc_fadeMusicIn( FADEMUSICIN_FADE_TIME,  FADEMUSICIN_LOOPS );
	break;
case FN_FadeMusicOut: //Sub Procedure
	rc_fadeMusicOut( FADEMUSICOUT_FADE_TIME );
	break;
case FN_MusicExists: //Number Function
	 rc_push_num(rc_musicExists(  ));
	break;
case FN_SetMusicVolume: //Sub Procedure
	rc_setMusicVolume( SETMUSICVOLUME_VOL );
	break;
case FN_GetMusicVolume: //Number Function
	 rc_push_num(rc_getMusicVolume(  ));
	break;
case FN_SetMusicPosition: //Sub Procedure
	rc_setMusicPosition( SETMUSICPOSITION_POS );
	break;
case FN_GetMusicPosition: //Number Function
	 rc_push_num(rc_getMusicPosition(  ));
	break;
case FN_RewindMusic: //Sub Procedure
	rc_rewindMusic(  );
	break;
case FN_SetSoundChannels: //Sub Procedure
	rc_setSoundChannels( SETSOUNDCHANNELS_MAX_CHANNELS );
	break;
case FN_NumSoundChannels: //Number Function
	 rc_push_num(rc_getSoundChannels(  ));
	break;
case FN_SoundIsEnabled: //Number Function
	 rc_push_num(rc_soundIsEnabled(  ));
	break;
case FN_SoundExists: //Number Function
	 rc_push_num(rc_soundExists( SOUNDEXISTS_SLOT ));
	break;
case FN_SetChannelVolume: //Sub Procedure
	rc_setChannelVolume( SETCHANNELVOLUME_CHANNEL,  SETCHANNELVOLUME_VOL );
	break;
case FN_GetChannelVolume: //Number Function
	 rc_push_num(rc_getChannelVolume( GETCHANNELVOLUME_CHANNEL ));
	break;
case FN_SetSoundVolume: //Sub Procedure
	rc_setSoundVolume( SETSOUNDVOLUME_SLOT,  SETSOUNDVOLUME_VOL );
	break;
case FN_GetSoundVolume: //Number Function
	 rc_push_num(rc_getSoundVolume( GETSOUNDVOLUME_SLOT ));
	break;
case FN_StopMusic: //Sub Procedure
	rc_stopMusic(  );
	break;
case FN_StopSound: //Sub Procedure
	rc_stopSound( STOPSOUND_CHANNEL );
	break;
case FN_SetChannelPanning: //Number Function
	 rc_push_num(rc_setChannelPanning( SETCHANNELPANNING_CHANNEL,  SETCHANNELPANNING_LEFT_VALUE,  SETCHANNELPANNING_RIGHT_VALUE ));
	break;
case FN_SetChannelDistance: //Number Function
	 rc_push_num(rc_setChannelDistance( SETCHANNELDISTANCE_CHANNEL,  SETCHANNELDISTANCE_DIST_VALUE ));
	break;
case FN_ChannelIsPlaying: //Number Function
	 rc_push_num(rc_channelIsPlaying( CHANNELISPLAYING_CHANNEL ));
	break;
case FN_ChannelIsPaused: //Number Function
	 rc_push_num(rc_channelIsPaused( CHANNELISPAUSED_CHANNEL ));
	break;
case FN_QueryAudioSpec: //Number Function
	 rc_push_num(rc_queryAudioSpec( &QUERYAUDIOSPEC_FREQ,  &QUERYAUDIOSPEC_FORMAT,  &QUERYAUDIOSPEC_CHANNELS ));
	break;
case FN_MusicIsPlaying: //Number Function
	 rc_push_num(rc_musicIsPlaying(  ));
	break;
case FN_SetChannelSpacePosition: //Number Function
	 rc_push_num(rc_setChannelSpacePosition( SETCHANNELSPACEPOSITION_CHANNEL,  SETCHANNELSPACEPOSITION_ANGLE,  SETCHANNELSPACEPOSITION_DISTANCE ));
	break;
case FN_NumJoysticks: //Number Function
	 rc_push_num(rc_getNumJoysticks(  ));
	break;
case FN_NumJoyAxes: //Number Function
	 rc_push_num(rc_numJoyAxes( NUMJOYAXES_JOY_NUM ));
	break;
case FN_NumJoyButtons: //Number Function
	 rc_push_num(rc_numJoyButtons( NUMJOYBUTTONS_JOY_NUM ));
	break;
case FN_NumJoyHats: //Number Function
	 rc_push_num(rc_numJoyHats( NUMJOYHATS_JOY_NUM ));
	break;
case FN_NumJoyTrackBalls: //Number Function
	 rc_push_num(rc_numJoyTrackBalls( NUMJOYTRACKBALLS_JOY_NUM ));
	break;
case FN_JoyAxis: //Number Function
	 rc_push_num(rc_joyAxis( JOYAXIS_JOY_NUM,  JOYAXIS_JOY_AXIS ));
	break;
case FN_JoyButton: //Number Function
	 rc_push_num(rc_joyButton( JOYBUTTON_JOY_NUM,  JOYBUTTON_JOY_BUTTON ));
	break;
case FN_JoyHat: //Number Function
	 rc_push_num(rc_joyHat( JOYHAT_JOY_NUM,  JOYHAT_JOY_HAT ));
	break;
case FN_GetJoyTrackBall: //Sub Procedure
	rc_getJoyTrackBall( GETJOYTRACKBALL_JOY_NUM,  GETJOYTRACKBALL_BALL,  &GETJOYTRACKBALL_DX,  &GETJOYTRACKBALL_DY );
	break;
case FN_JoyName$: //String Function
	 rc_push_str(rc_joyName( JOYNAME$_JOY_NUM ));
	break;
case FN_JoystickIsConnected: //Number Function
	 rc_push_num(rc_joystickIsConnected( JOYSTICKISCONNECTED_JOY_NUM ));
	break;
case FN_JoyRumblePlay: //Sub Procedure
	rc_joyRumblePlay( JOYRUMBLEPLAY_JOY_NUM,  JOYRUMBLEPLAY_STRENGTH,  JOYRUMBLEPLAY_DURATION );
	break;
case FN_JoyRumbleStop: //Sub Procedure
	rc_joyRumbleStop( JOYRUMBLESTOP_JOY_NUM );
	break;
case FN_JoystickIsHaptic: //Number Function
	 rc_push_num(rc_joystickIsHaptic( JOYSTICKISHAPTIC_JOY_NUM ));
	break;
case FN_LoadFont: //Number Function
	 rc_push_num(rc_loadFont( LOADFONT_FNT_FILE$,  LOADFONT_FONT_SIZE ));
	break;
case FN_DeleteFont: //Sub Procedure
	rc_deleteFont( DELETEFONT_SLOT );
	break;
case FN_FontExists: //Number Function
	 rc_push_num(rc_fontExists( FONTEXISTS_SLOT ));
	break;
case FN_SetFont: //Sub Procedure
	rc_setFont( SETFONT_SLOT );
	break;
case FN_DrawText: //Sub Procedure
	rc_drawText( DRAWTEXT_TXT$,  DRAWTEXT_X,  DRAWTEXT_Y );
	break;
case FN_GetTextSize: //Sub Procedure
	rc_getTextSize( GETTEXTSIZE_TXT$,  &GETTEXTSIZE_W,  &GETTEXTSIZE_H );
	break;
case FN_TextWidth: //Number Function
	 rc_push_num(rc_getTextWidth( TEXTWIDTH_TXT$ ));
	break;
case FN_TextHeight: //Number Function
	 rc_push_num(rc_getTextHeight( TEXTHEIGHT_TXT$ ));
	break;
case FN_TouchPressure: //Number Function
	 rc_push_num(rc_touchPressure(  ));
	break;
case FN_GetTouch: //Sub Procedure
	rc_getTouch( &GETTOUCH_STATUS,  &GETTOUCH_X,  &GETTOUCH_Y,  &GETTOUCH_DX,  &GETTOUCH_DY );
	break;
case FN_GetMultiTouch: //Sub Procedure
	rc_getMultiTouch( &GETMULTITOUCH_STATUS,  &GETMULTITOUCH_X,  &GETMULTITOUCH_Y,  &GETMULTITOUCH_FINGERS,  &GETMULTITOUCH_DIST,  &GETMULTITOUCH_THETA );
	break;
case FN_GetTouchFinger: //Sub Procedure
	rc_getTouchFinger( GETTOUCHFINGER_FINGER,  &GETTOUCHFINGER_X,  &GETTOUCHFINGER_Y,  &GETTOUCHFINGER_PRESSURE );
	break;
case FN_NumFingers: //Number Function
	 rc_push_num(rc_numFingers(  ));
	break;
case FN_GetAccel: //Sub Procedure
	rc_getAccel( GETACCEL_ACCEL_NUM,  &GETACCEL_X,  &GETACCEL_Y,  &GETACCEL_Z );
	break;
case FN_AccelName$: //String Function
	 rc_push_str(rc_accelName( ACCELNAME$_ACCEL_NUM ));
	break;
case FN_NumAccels: //Number Function
	 rc_push_num(rc_numAccels(  ));
	break;
case FN_GetGyro: //Sub Procedure
	rc_getGyro( GETGYRO_GYRO_NUM,  &GETGYRO_X,  &GETGYRO_Y,  &GETGYRO_Z );
	break;
case FN_GyroName$: //String Function
	 rc_push_str(rc_gyroName( GYRONAME$_GYRO_NUM ));
	break;
case FN_NumGyros: //Number Function
	 rc_push_num(rc_numGyros(  ));
	break;
case FN_CheckSockets: //Number Function
	 rc_push_num(rc_net_checkSockets( CHECKSOCKETS_TIMEOUT_MS ));
	break;
case FN_TCP_SocketReady: //Number Function
	 rc_push_num(rc_net_tcp_socketReady( TCP_SOCKETREADY_SOCKET ));
	break;
case FN_UDP_SocketReady: //Number Function
	 rc_push_num(rc_net_udp_socketReady( UDP_SOCKETREADY_SOCKET ));
	break;
case FN_TCP_OpenSocket: //Number Function
	 rc_push_num(rc_net_tcp_openSocket( TCP_OPENSOCKET_HOST$,  TCP_OPENSOCKET_PORT ));
	break;
case FN_TCP_CloseSocket: //Sub Procedure
	rc_net_tcp_closeSocket( TCP_CLOSESOCKET_SOCKET );
	break;
case FN_TCP_RemoteHost: //Number Function
	 rc_push_num(rc_net_tcp_remoteHost( TCP_REMOTEHOST_SOCKET ));
	break;
case FN_TCP_RemotePort: //Number Function
	 rc_push_num(rc_net_tcp_remotePort( TCP_REMOTEPORT_SOCKET ));
	break;
case FN_TCP_GetData: //Number Function
	 rc_push_num(rc_net_tcp_getData_str( TCP_GETDATA_SOCKET,  TCP_GETDATA_NUMBYTES,  &TCP_GETDATA_SDATA$ ));
	break;
case FN_TCP_SendData: //Sub Procedure
	rc_net_tcp_sendData( TCP_SENDDATA_SOCKET,  TCP_SENDDATA_SDATA$ );
	break;
case FN_TCP_AcceptSocket: //Number Function
	 rc_push_num(rc_net_tcp_acceptSocket( TCP_ACCEPTSOCKET_SERVER ));
	break;
case FN_UDP_OpenSocket: //Number Function
	 rc_push_num(rc_net_udp_openSocket( UDP_OPENSOCKET_PORT ));
	break;
case FN_UDP_CloseSocket: //Sub Procedure
	rc_net_udp_closeSocket( UDP_CLOSESOCKET_SOCKET );
	break;
case FN_UDP_GetData: //Number Function
	 rc_push_num(rc_net_udp_readStream( UDP_GETDATA_SOCKET,  &UDP_GETDATA_HOST$,  &UDP_GETDATA_PORT,  &UDP_GETDATA_SDATA$ ));
	break;
case FN_UDP_Length: //Number Function
	 rc_push_num(rc_net_udp_len(  ));
	break;
case FN_UDP_MaxLength: //Number Function
	 rc_push_num(rc_net_udp_maxlen(  ));
	break;
case FN_UDP_RemoteHost$: //String Function
	 rc_push_str(rc_net_udp_getRemoteHost( UDP_REMOTEHOST$_SOCKET ));
	break;
case FN_UDP_RemotePort: //Number Function
	 rc_push_num(rc_net_udp_getRemotePort( UDP_REMOTEPORT_SOCKET ));
	break;
case FN_UDP_SendData: //Sub Procedure
	rc_net_udp_sendData( UDP_SENDDATA_SOCKET,  UDP_SENDDATA_HOST$,  UDP_SENDDATA_PORT,  UDP_SENDDATA_SDATA$ );
	break;
case FN_LoadVideo: //Sub Procedure
	rc_loadVideo( LOADVIDEO_VID$ );
	break;
case FN_PlayVideo: //Sub Procedure
	rc_playVideo( PLAYVIDEO_VLOOPS );
	break;
case FN_PauseVideo: //Sub Procedure
	rc_pauseVideo(  );
	break;
case FN_StopVideo: //Sub Procedure
	rc_stopVideo(  );
	break;
case FN_SetVideoPosition: //Sub Procedure
	rc_setVideoPosition( SETVIDEOPOSITION_POS );
	break;
case FN_ResumeVideo: //Sub Procedure
	rc_resumeVideo(  );
	break;
case FN_GetVideoPosition: //Number Function
	 rc_push_num(rc_getVideoPosition(  ));
	break;
case FN_DeleteVideo: //Sub Procedure
	rc_deleteVideo(  );
	break;
case FN_VideoIsPlaying: //Number Function
	 rc_push_num(rc_videoIsPlaying(  ));
	break;
case FN_VideoEnd: //Number Function
	 rc_push_num(rc_videoEnd(  ));
	break;
case FN_GetVideoStats: //Sub Procedure
	rc_getVideoStats( GETVIDEOSTATS_VFILE$,  &GETVIDEOSTATS_VLEN,  &GETVIDEOSTATS_VFPS,  &GETVIDEOSTATS_FRAME_W,  &GETVIDEOSTATS_FRAME_H );
	break;
case FN_SetVideoDrawRect: //Sub Procedure
	rc_setVideoDrawRect( SETVIDEODRAWRECT_X,  SETVIDEODRAWRECT_Y,  SETVIDEODRAWRECT_W,  SETVIDEODRAWRECT_H );
	break;
case FN_GetVideoDrawRect: //Sub Procedure
	rc_getVideoDrawRect( &GETVIDEODRAWRECT_X,  &GETVIDEODRAWRECT_Y,  &GETVIDEODRAWRECT_W,  &GETVIDEODRAWRECT_H );
	break;
case FN_GetVideoSize: //Sub Procedure
	rc_getVideoSize( &GETVIDEOSIZE_W,  &GETVIDEOSIZE_H );
	break;
case FN_VideoExists: //Number Function
	 rc_push_num(rc_videoExists(  ));
	break;
case FN_SetVideoVolume: //Sub Procedure
	rc_setVideoVolume( SETVIDEOVOLUME_VOL );
	break;
case FN_GetVideoVolume: //Number Function
	 rc_push_num(rc_getVideoVolume(  ));
	break;
case FN_System: //Number Function
	 rc_push_num(rc_intern_system( SYSTEM_CMD$ ));
	break;
case FN_OS$: //String Function
	 rc_push_str(rc_intern_OS(  ));
	break;
case FN_Command$: //String Function
	 rc_push_str(rc_intern_command( COMMAND$_ARG ));
	break;
case FN_NumCommands: //Number Function
	 rc_push_num(rc_intern_numCommands(  ));
	break;
case FN_Env$: //String Function
	 rc_push_str(rc_intern_env( ENV$_V$ ));
	break;
case FN_SetEnv: //Sub Procedure
	rc_intern_setEnv( SETENV_VAR$,  SETENV_VALUE$ );
	break;
case FN_PrefPath$: //String Function
	 rc_push_str(rc_intern_prefPath( PREFPATH$_ORG_NAME$,  PREFPATH$_APP_NAME$ ));
	break;
case FN_Android_GetExternalStoragePath$: //String Function
	 rc_push_str(rc_intern_android_getExternalStoragePath(  ));
	break;
case FN_Android_GetExternalStorageState: //Number Function
	 rc_push_num(rc_intern_android_getExternalStorageState(  ));
	break;
case FN_Android_GetInternalStoragePath$: //String Function
	 rc_push_str(rc_intern_android_getInternalStoragePath(  ));
	break;
case FN_Android_JNI_Message$: //String Function
	 rc_push_str(rc_intern_android_jni_message( ANDROID_JNI_MESSAGE$_ARG$ ));
	break;
case FN_Runtime_Utility_Message$: //String Function
	 rc_push_str(rc_intern_runtime_utility( RUNTIME_UTILITY_MESSAGE$_ARG$ ));
	break;
case FN_GetDesktopDisplayMode: //Sub Procedure
	rc_getDesktopDisplayMode( GETDESKTOPDISPLAYMODE_INDEX,  &GETDESKTOPDISPLAYMODE_W,  &GETDESKTOPDISPLAYMODE_H,  &GETDESKTOPDISPLAYMODE_FREQ );
	break;
case FN_GetPowerInfo: //Sub Procedure
	rc_intern_getPowerInfo( &GETPOWERINFO_STATUS,  &GETPOWERINFO_SECS,  &GETPOWERINFO_PCT );
	break;
case FN_EvalJS$: //String Function
	 rc_push_str(rc_intern_evalJS( EVALJS$_JS_CODE$ ));
	break;
case FN_SystemReturnStdOut$: //String Function
	 rc_push_str(rc_intern_sysReturnOutput( SYSTEMRETURNSTDOUT$_CMD$ ));
	break;
case FN_OpenURL: //Number Function
	 rc_push_num(rc_openURL( OPENURL_URL$ ));
	break;
case FN_MessageBox: //Number Function
	 rc_push_num(rc_messageBox( MESSAGEBOX_TITLE$,  MESSAGEBOX_MSG$ ));
	break;
case FN_Runtime$: //String Function
	rc_push_str( rcbasic_runtime_path );

	break;
case FN_NumCPUs: //Number Function
	 rc_push_num(rc_numCPUs(  ));
	break;
case FN_SystemRam: //Number Function
	 rc_push_num(rc_intern_systemRam(  ));
	break;
case FN_DimMatrix: //Number Function
	 rc_push_num(rc_dimMatrix( DIMMATRIX_M_ROWS,  DIMMATRIX_M_COLS ));
	break;
case FN_DeleteMatrix: //Sub Procedure
	rc_deleteMatrix( DELETEMATRIX_MA );
	break;
case FN_AddMatrix: //Number Function
	 rc_push_num(rc_addMatrix( ADDMATRIX_MA,  ADDMATRIX_MB,  ADDMATRIX_MC ));
	break;
case FN_AugmentMatrix: //Number Function
	 rc_push_num(rc_augmentMatrix( AUGMENTMATRIX_MA,  AUGMENTMATRIX_MB,  AUGMENTMATRIX_MC ));
	break;
case FN_CopyMatrix: //Sub Procedure
	rc_copyMatrix( COPYMATRIX_MA,  COPYMATRIX_MB );
	break;
case FN_InsertMatrixColumns: //Number Function
	 rc_push_num(rc_insertMatrixColumns( INSERTMATRIXCOLUMNS_MA,  INSERTMATRIXCOLUMNS_C,  INSERTMATRIXCOLUMNS_NUM_COLS ));
	break;
case FN_InsertMatrixRows: //Number Function
	 rc_push_num(rc_insertMatrixRows( INSERTMATRIXROWS_MA,  INSERTMATRIXROWS_R,  INSERTMATRIXROWS_NUM_ROWS ));
	break;
case FN_MultiplyMatrix: //Number Function
	 rc_push_num(rc_multiplyMatrix( MULTIPLYMATRIX_MA,  MULTIPLYMATRIX_MB,  MULTIPLYMATRIX_MC ));
	break;
case FN_CubeMatrix: //Number Function
	 rc_push_num(rc_cubeMatrix( CUBEMATRIX_MA,  CUBEMATRIX_MB ));
	break;
case FN_DeleteMatrixColumns: //Number Function
	 rc_push_num(rc_deleteMatrixColumns( DELETEMATRIXCOLUMNS_MA,  DELETEMATRIXCOLUMNS_C,  DELETEMATRIXCOLUMNS_NUM_COLS ));
	break;
case FN_DeleteMatrixRows: //Number Function
	 rc_push_num(rc_deleteMatrixRows( DELETEMATRIXROWS_MA,  DELETEMATRIXROWS_R,  DELETEMATRIXROWS_NUM_ROWS ));
	break;
case FN_ClearMatrix: //Sub Procedure
	rc_clearMatrix( CLEARMATRIX_MA );
	break;
case FN_ClearMatrixColumns: //Number Function
	 rc_push_num(rc_clearMatrixColumns( CLEARMATRIXCOLUMNS_MA,  CLEARMATRIXCOLUMNS_C,  CLEARMATRIXCOLUMNS_NUM_COLS ));
	break;
case FN_ClearMatrixRows: //Number Function
	 rc_push_num(rc_clearMatrixRows( CLEARMATRIXROWS_MA,  CLEARMATRIXROWS_R,  CLEARMATRIXROWS_NUM_ROWS ));
	break;
case FN_FillMatrix: //Sub Procedure
	rc_fillMatrix( FILLMATRIX_MA,  FILLMATRIX_V );
	break;
case FN_FillMatrixColumns: //Number Function
	 rc_push_num(rc_fillMatrixColumns( FILLMATRIXCOLUMNS_MA,  FILLMATRIXCOLUMNS_C,  FILLMATRIXCOLUMNS_NUM_COLS,  FILLMATRIXCOLUMNS_V ));
	break;
case FN_FillMatrixRows: //Number Function
	 rc_push_num(rc_fillMatrixRows( FILLMATRIXROWS_MA,  FILLMATRIXROWS_R,  FILLMATRIXROWS_NUM_ROWS,  FILLMATRIXROWS_V ));
	break;
case FN_CopyMatrixColumns: //Number Function
	 rc_push_num(rc_copyMatrixColumns( COPYMATRIXCOLUMNS_MA,  COPYMATRIXCOLUMNS_MB,  COPYMATRIXCOLUMNS_C,  COPYMATRIXCOLUMNS_NUM_COLS ));
	break;
case FN_CopyMatrixRows: //Number Function
	 rc_push_num(rc_copyMatrixRows( COPYMATRIXROWS_MA,  COPYMATRIXROWS_MB,  COPYMATRIXROWS_R,  COPYMATRIXROWS_NUM_ROWS ));
	break;
case FN_SetIdentityMatrix: //Sub Procedure
	rc_setIdentityMatrix( SETIDENTITYMATRIX_MA,  SETIDENTITYMATRIX_N );
	break;
case FN_SolveMatrix: //Number Function
	 rc_push_num(rc_solveMatrix( SOLVEMATRIX_MA,  SOLVEMATRIX_MB,  SOLVEMATRIX_MC ));
	break;
case FN_IsEqualMatrix: //Number Function
	 rc_push_num(rc_isEqualMatrix( ISEQUALMATRIX_MA,  ISEQUALMATRIX_MB,  ISEQUALMATRIX_TOLERANCE ));
	break;
case FN_Determinant: //Number Function
	 rc_push_num(rc_determinant( DETERMINANT_MA ));
	break;
case FN_AdjointMatrix: //Number Function
	 rc_push_num(rc_adjointMatrix( ADJOINTMATRIX_MA,  ADJOINTMATRIX_MB ));
	break;
case FN_InvertMatrix: //Number Function
	 rc_push_num(rc_invertMatrix( INVERTMATRIX_MA,  INVERTMATRIX_MB ));
	break;
case FN_MatrixFromBuffer: //Sub Procedure
	rc_matrixFromBuffer( MATRIXFROMBUFFER_MA,  MATRIXFROMBUFFER_R,  MATRIXFROMBUFFER_C,  &MATRIXFROMBUFFER_BUFFER );
	break;
case FN_BufferFromMatrix: //Sub Procedure
	rc_bufferFromMatrix( &BUFFERFROMMATRIX_BUFFER,  BUFFERFROMMATRIX_MA );
	break;
case FN_RandomizeMatrix: //Sub Procedure
	rc_randomizeMatrix( RANDOMIZEMATRIX_MA,  RANDOMIZEMATRIX_VMIN,  RANDOMIZEMATRIX_VMAX );
	break;
case FN_MatrixValue: //Number Function
	 rc_push_num(rc_matrixValue( MATRIXVALUE_MA,  MATRIXVALUE_R,  MATRIXVALUE_C ));
	break;
case FN_SetMatrixValue: //Sub Procedure
	rc_setMatrixValue( SETMATRIXVALUE_MA,  SETMATRIXVALUE_R,  SETMATRIXVALUE_C,  SETMATRIXVALUE_V );
	break;
case FN_ScalarMatrix: //Sub Procedure
	rc_scalarMatrix( SCALARMATRIX_MA,  SCALARMATRIX_MB,  SCALARMATRIX_S_VALUE );
	break;
case FN_ScalarMatrixColumns: //Number Function
	 rc_push_num(rc_scalarMatrixColumns( SCALARMATRIXCOLUMNS_MA,  SCALARMATRIXCOLUMNS_MB,  SCALARMATRIXCOLUMNS_C,  SCALARMATRIXCOLUMNS_NUM_COLS,  SCALARMATRIXCOLUMNS_S_VALUE ));
	break;
case FN_ScalarMatrixRows: //Number Function
	 rc_push_num(rc_scalarMatrixRows( SCALARMATRIXROWS_MA,  SCALARMATRIXROWS_MB,  SCALARMATRIXROWS_R,  SCALARMATRIXROWS_NUM_ROWS,  SCALARMATRIXROWS_S_VALUE ));
	break;
case FN_SquareMatrix: //Number Function
	 rc_push_num(rc_squareMatrix( SQUAREMATRIX_MA,  SQUAREMATRIX_MB ));
	break;
case FN_CofactorMatrix: //Sub Procedure
	rc_subMatrix( COFACTORMATRIX_MA,  COFACTORMATRIX_R,  COFACTORMATRIX_C );
	break;
case FN_SubtractMatrix: //Number Function
	 rc_push_num(rc_subtractMatrix( SUBTRACTMATRIX_MA,  SUBTRACTMATRIX_MB,  SUBTRACTMATRIX_MC ));
	break;
case FN_SwapMatrix: //Sub Procedure
	rc_swapMatrix( SWAPMATRIX_MA,  SWAPMATRIX_MB );
	break;
case FN_SwapMatrixColumn: //Number Function
	 rc_push_num(rc_swapMatrixColumn( SWAPMATRIXCOLUMN_MA,  SWAPMATRIXCOLUMN_C1,  SWAPMATRIXCOLUMN_C2 ));
	break;
case FN_SwapMatrixRow: //Number Function
	 rc_push_num(rc_swapMatrixRow( SWAPMATRIXROW_MA,  SWAPMATRIXROW_R1,  SWAPMATRIXROW_R2 ));
	break;
case FN_TransposeMatrix: //Number Function
	 rc_push_num(rc_transposeMatrix( TRANSPOSEMATRIX_MA,  TRANSPOSEMATRIX_MB ));
	break;
case FN_UnAugmentMatrix: //Number Function
	 rc_push_num(rc_unAugmentMatrix( UNAUGMENTMATRIX_MA,  UNAUGMENTMATRIX_MB,  UNAUGMENTMATRIX_MC ));
	break;
case FN_ZeroMatrix: //Sub Procedure
	rc_zeroMatrix( ZEROMATRIX_MA );
	break;
case FN_GetMatrixSize: //Sub Procedure
	rc_getMatrixSize( GETMATRIXSIZE_MA,  &GETMATRIXSIZE_R,  &GETMATRIXSIZE_C );
	break;
case FN_IncrementMatrixRows: //Sub Procedure
	rc_incrementMatrixRows( INCREMENTMATRIXROWS_MA,  INCREMENTMATRIXROWS_MB,  INCREMENTMATRIXROWS_R,  INCREMENTMATRIXROWS_NUM_ROWS,  INCREMENTMATRIXROWS_VALUE );
	break;
case FN_IncrementMatrixColumns: //Sub Procedure
	rc_incrementMatrixColumns( INCREMENTMATRIXCOLUMNS_MA,  INCREMENTMATRIXCOLUMNS_MB,  INCREMENTMATRIXCOLUMNS_C,  INCREMENTMATRIXCOLUMNS_NUM_COLS,  INCREMENTMATRIXCOLUMNS_VALUE );
	break;
case FN_JoinMatrixRows: //Sub Procedure
	rc_joinMatrixRows( JOINMATRIXROWS_MA,  JOINMATRIXROWS_MB,  JOINMATRIXROWS_MC );
	break;
case FN_JoinMatrixColumns: //Sub Procedure
	rc_joinMatrixColumns( JOINMATRIXCOLUMNS_MA,  JOINMATRIXCOLUMNS_MB,  JOINMATRIXCOLUMNS_MC );
	break;
case FN_ClipMatrix: //Sub Procedure
	rc_clipMatrix( CLIPMATRIX_MA,  CLIPMATRIX_R,  CLIPMATRIX_C,  CLIPMATRIX_NUM_ROWS,  CLIPMATRIX_NUM_COLS,  CLIPMATRIX_MB );
	break;
case FN_SetMatrixTranslation: //Sub Procedure
	rc_setMatrixTranslation( SETMATRIXTRANSLATION_MA,  SETMATRIXTRANSLATION_X,  SETMATRIXTRANSLATION_Y,  SETMATRIXTRANSLATION_Z );
	break;
case FN_SetMatrixRotation: //Sub Procedure
	rc_setMatrixRotation( SETMATRIXROTATION_MA,  SETMATRIXROTATION_X,  SETMATRIXROTATION_Y,  SETMATRIXROTATION_Z );
	break;
case FN_SetMatrixScale: //Sub Procedure
	rc_setMatrixScale( SETMATRIXSCALE_MA,  SETMATRIXSCALE_X,  SETMATRIXSCALE_Y,  SETMATRIXSCALE_Z );
	break;
case FN_GetMatrixTranslation: //Sub Procedure
	rc_getMatrixTranslation( GETMATRIXTRANSLATION_MA,  &GETMATRIXTRANSLATION_X,  &GETMATRIXTRANSLATION_Y,  &GETMATRIXTRANSLATION_Z );
	break;
case FN_GetMatrixRotation: //Sub Procedure
	rc_getMatrixRotation( GETMATRIXROTATION_MA,  &GETMATRIXROTATION_X,  &GETMATRIXROTATION_Y,  &GETMATRIXROTATION_Z );
	break;
case FN_GetMatrixScale: //Sub Procedure
	rc_getMatrixScale( GETMATRIXSCALE_MA,  &GETMATRIXSCALE_X,  &GETMATRIXSCALE_Y,  &GETMATRIXSCALE_Z );
	break;
case FN_GetClipboardText$: //String Function
	 rc_push_str(rc_getClipboardText(  ));
	break;
case FN_SetClipboardText: //Sub Procedure
	rc_setClipboardText( SETCLIPBOARDTEXT_TXT$ );
	break;
case FN_HasClipboardText: //Number Function
	 rc_push_num(rc_hasClipboardText(  ));
	break;
case FN_ReadInput_Start: //Sub Procedure
	rc_readInput_Start(  );
	break;
case FN_ReadInput_Stop: //Sub Procedure
	rc_readInput_Stop(  );
	break;
case FN_ReadInput_GetText$: //String Function
	 rc_push_str(rc_readInput_GetText(  ));
	break;
case FN_ReadInput_SetText: //Sub Procedure
	rc_readInput_SetText( READINPUT_SETTEXT_TXT$ );
	break;
case FN_ReadInput_ToggleBackspace: //Sub Procedure
	rc_readInput_ToggleBackspace( READINPUT_TOGGLEBACKSPACE_FLAG );
	break;
case FN_CreateSprite: //Number Function
	 rc_push_num(rc_createSprite( CREATESPRITE_IMG,  CREATESPRITE_FRAME_W,  CREATESPRITE_FRAME_H ));
	break;
case FN_DeleteSprite: //Sub Procedure
	rc_deleteSprite( DELETESPRITE_SPRITE );
	break;
case FN_SetSpritePosition: //Sub Procedure
	rc_setSpritePosition( SETSPRITEPOSITION_SPRITE,  SETSPRITEPOSITION_X,  SETSPRITEPOSITION_Y );
	break;
case FN_TranslateSprite: //Sub Procedure
	rc_translateSprite( TRANSLATESPRITE_SPRITE,  TRANSLATESPRITE_X,  TRANSLATESPRITE_Y );
	break;
case FN_GetSpritePosition: //Sub Procedure
	rc_getSpritePosition( GETSPRITEPOSITION_SPRITE,  &GETSPRITEPOSITION_X,  &GETSPRITEPOSITION_Y );
	break;
case FN_SpriteX: //Number Function
	 rc_push_num(rc_spriteX( SPRITEX_SPRITE ));
	break;
case FN_SpriteY: //Number Function
	 rc_push_num(rc_spriteY( SPRITEY_SPRITE ));
	break;
case FN_SetSpriteRotation: //Sub Procedure
	rc_setSpriteRotation( SETSPRITEROTATION_SPRITE,  SETSPRITEROTATION_ANGLE );
	break;
case FN_RotateSprite: //Sub Procedure
	rc_rotateSprite( ROTATESPRITE_SPRITE,  ROTATESPRITE_ANGLE );
	break;
case FN_GetSpriteRotation: //Number Function
	 rc_push_num(rc_getSpriteRotation( GETSPRITEROTATION_SPRITE ));
	break;
case FN_SetSpriteScale: //Sub Procedure
	rc_setSpriteScale( SETSPRITESCALE_SPRITE,  SETSPRITESCALE_X,  SETSPRITESCALE_Y );
	break;
case FN_ScaleSprite: //Sub Procedure
	rc_scaleSprite( SCALESPRITE_SPRITE,  SCALESPRITE_X,  SCALESPRITE_Y );
	break;
case FN_GetSpriteScale: //Sub Procedure
	rc_getSpriteScale( GETSPRITESCALE_SPRITE,  &GETSPRITESCALE_X,  &GETSPRITESCALE_Y );
	break;
case FN_SetSpriteZ: //Sub Procedure
	rc_setSpriteZ( SETSPRITEZ_SPRITE,  SETSPRITEZ_Z );
	break;
case FN_SpriteZ: //Number Function
	 rc_push_num(rc_spriteZ( SPRITEZ_SPRITE ));
	break;
case FN_GetSpriteSize: //Sub Procedure
	rc_getSpriteSize( GETSPRITESIZE_SPRITE,  &GETSPRITESIZE_W,  &GETSPRITESIZE_H );
	break;
case FN_SpriteWidth: //Number Function
	 rc_push_num(rc_spriteWidth( SPRITEWIDTH_SPRITE ));
	break;
case FN_SpriteHeight: //Number Function
	 rc_push_num(rc_spriteHeight( SPRITEHEIGHT_SPRITE ));
	break;
case FN_SetSpriteVisible: //Sub Procedure
	rc_setSpriteVisible( SETSPRITEVISIBLE_SPRITE,  SETSPRITEVISIBLE_FLAG );
	break;
case FN_SpriteIsVisible: //Number Function
	 rc_push_num(rc_spriteIsVisible( SPRITEISVISIBLE_SPRITE ));
	break;
case FN_SetSpriteSolid: //Sub Procedure
	rc_setSpriteSolid( SETSPRITESOLID_SPRITE,  SETSPRITESOLID_FLAG );
	break;
case FN_SpriteIsSolid: //Number Function
	 rc_push_num(rc_spriteIsSolid( SPRITEISSOLID_SPRITE ));
	break;
case FN_SetSpriteType: //Sub Procedure
	rc_setSpriteType( SETSPRITETYPE_SPRITE,  SETSPRITETYPE_SPRITE_TYPE );
	break;
case FN_GetSpriteType: //Number Function
	 rc_push_num(rc_getSpriteType( GETSPRITETYPE_SPRITE ));
	break;
case FN_SetSpriteSource: //Sub Procedure
	rc_setSpriteSource( SETSPRITESOURCE_SPRITE,  SETSPRITESOURCE_IMG );
	break;
case FN_GetSpriteSource: //Number Function
	 rc_push_num(rc_getSpriteSource( GETSPRITESOURCE_SPRITE ));
	break;
case FN_CreateSpriteAnimation: //Number Function
	 rc_push_num(rc_createSpriteAnimation( CREATESPRITEANIMATION_SPRITE,  CREATESPRITEANIMATION_ANIM_LENGTH,  CREATESPRITEANIMATION_SPEED ));
	break;
case FN_SetSpriteFrame: //Sub Procedure
	rc_setSpriteFrame( SETSPRITEFRAME_SPRITE,  SETSPRITEFRAME_FRAME );
	break;
case FN_GetSpriteFrame: //Number Function
	 rc_push_num(rc_getSpriteFrame( GETSPRITEFRAME_SPRITE ));
	break;
case FN_SetSpriteAnimationFrame: //Sub Procedure
	rc_setSpriteAnimationFrame( SETSPRITEANIMATIONFRAME_SPRITE,  SETSPRITEANIMATIONFRAME_ANIMATION,  SETSPRITEANIMATIONFRAME_ANIM_FRAME,  SETSPRITEANIMATIONFRAME_FRAME );
	break;
case FN_GetSpriteAnimationFrame: //Number Function
	 rc_push_num(rc_getSpriteAnimationFrame( GETSPRITEANIMATIONFRAME_SPRITE,  GETSPRITEANIMATIONFRAME_ANIMATION,  GETSPRITEANIMATIONFRAME_ANIM_FRAME ));
	break;
case FN_SetSpriteAnimationLength: //Sub Procedure
	rc_setSpriteAnimationLength( SETSPRITEANIMATIONLENGTH_SPRITE,  SETSPRITEANIMATIONLENGTH_ANIMATION,  SETSPRITEANIMATIONLENGTH_ANIM_LENGTH );
	break;
case FN_GetSpriteAnimationLength: //Number Function
	 rc_push_num(rc_getSpriteAnimationLength( GETSPRITEANIMATIONLENGTH_SPRITE,  GETSPRITEANIMATIONLENGTH_ANIMATION ));
	break;
case FN_SetSpriteAnimationSpeed: //Sub Procedure
	rc_setSpriteAnimationSpeed( SETSPRITEANIMATIONSPEED_SPRITE,  SETSPRITEANIMATIONSPEED_ANIMATION,  SETSPRITEANIMATIONSPEED_SPEED );
	break;
case FN_GetSpriteAnimationSpeed: //Number Function
	 rc_push_num(rc_getSpriteAnimationSpeed( GETSPRITEANIMATIONSPEED_SPRITE,  GETSPRITEANIMATIONSPEED_ANIMATION ));
	break;
case FN_SetSpriteAnimation: //Sub Procedure
	rc_setSpriteAnimation( SETSPRITEANIMATION_SPRITE,  SETSPRITEANIMATION_ANIMATION,  SETSPRITEANIMATION_NUM_LOOPS );
	break;
case FN_GetSpriteAnimation: //Number Function
	 rc_push_num(rc_getSpriteAnimation( GETSPRITEANIMATION_SPRITE ));
	break;
case FN_GetSpriteCurrentAnimationFrame: //Number Function
	 rc_push_num(rc_getSpriteCurrentAnimationFrame( GETSPRITECURRENTANIMATIONFRAME_SPRITE ));
	break;
case FN_NumSpriteAnimationLoops: //Number Function
	 rc_push_num(rc_numSpriteAnimationLoops( NUMSPRITEANIMATIONLOOPS_SPRITE ));
	break;
case FN_SpriteAnimationIsPlaying: //Number Function
	 rc_push_num(rc_spriteAnimationIsPlaying( SPRITEANIMATIONISPLAYING_SPRITE ));
	break;
case FN_DeleteSpriteAnimation: //Sub Procedure
	rc_deleteSpriteAnimation( DELETESPRITEANIMATION_SPRITE,  DELETESPRITEANIMATION_ANIMATION );
	break;
case FN_getSpriteCenter: //Sub Procedure
	rc_getSpriteCenter( GETSPRITECENTER_SPR_ID,  &GETSPRITECENTER_X,  &GETSPRITECENTER_Y );
	break;
case FN_setSpriteLinearVelocity: //Sub Procedure
	rc_setSpriteLinearVelocity( SETSPRITELINEARVELOCITY_SPR_ID,  SETSPRITELINEARVELOCITY_X,  SETSPRITELINEARVELOCITY_Y );
	break;
case FN_getSpriteLinearVelocity: //Sub Procedure
	rc_getSpriteLinearVelocity( GETSPRITELINEARVELOCITY_SPR_ID,  &GETSPRITELINEARVELOCITY_X,  &GETSPRITELINEARVELOCITY_Y );
	break;
case FN_setSpriteAngularVelocity: //Sub Procedure
	rc_setSpriteAngularVelocity( SETSPRITEANGULARVELOCITY_SPR_ID,  SETSPRITEANGULARVELOCITY_AV );
	break;
case FN_getSpriteAngularVelocity: //Number Function
	 rc_push_num(rc_getSpriteAngularVelocity(  GETSPRITEANGULARVELOCITY_SPR_ID ));
	break;
case FN_applySpriteForce: //Sub Procedure
	rc_applySpriteForce( APPLYSPRITEFORCE_SPR_ID,  APPLYSPRITEFORCE_FX,  APPLYSPRITEFORCE_FY,  APPLYSPRITEFORCE_PX,  APPLYSPRITEFORCE_PY );
	break;
case FN_applySpriteCentralForce: //Sub Procedure
	rc_applySpriteCentralForce( APPLYSPRITECENTRALFORCE_SPR_ID,  APPLYSPRITECENTRALFORCE_X,  APPLYSPRITECENTRALFORCE_Y );
	break;
case FN_applySpriteTorque: //Sub Procedure
	rc_applySpriteTorque( APPLYSPRITETORQUE_SPR_ID,  APPLYSPRITETORQUE_TORQUE );
	break;
case FN_applySpriteLinearImpulse: //Sub Procedure
	rc_applySpriteLinearImpulse( APPLYSPRITELINEARIMPULSE_SPR_ID,  APPLYSPRITELINEARIMPULSE_IX,  APPLYSPRITELINEARIMPULSE_IY,  APPLYSPRITELINEARIMPULSE_PX,  APPLYSPRITELINEARIMPULSE_PY );
	break;
case FN_applySpriteAngularImpulse: //Sub Procedure
	rc_applySpriteAngularImpulse( APPLYSPRITEANGULARIMPULSE_SPR_ID,  APPLYSPRITEANGULARIMPULSE_IMPULSE );
	break;
case FN_getSpriteMass: //Number Function
	 rc_push_num(rc_getSpriteMass(  GETSPRITEMASS_SPR_ID ));
	break;
case FN_getSpriteInertia: //Number Function
	 rc_push_num(rc_getSpriteInertia(  GETSPRITEINERTIA_SPR_ID ));
	break;
case FN_getSpriteWorldPoint: //Sub Procedure
	rc_getSpriteWorldPoint( GETSPRITEWORLDPOINT_SPR_ID,  GETSPRITEWORLDPOINT_LX,  GETSPRITEWORLDPOINT_LY,  &GETSPRITEWORLDPOINT_X,  &GETSPRITEWORLDPOINT_Y );
	break;
case FN_getSpriteWorldVector: //Sub Procedure
	rc_getSpriteWorldVector( GETSPRITEWORLDVECTOR_SPR_ID,  GETSPRITEWORLDVECTOR_LX,  GETSPRITEWORLDVECTOR_LY,  &GETSPRITEWORLDVECTOR_X,  &GETSPRITEWORLDVECTOR_Y );
	break;
case FN_getSpriteLocalPoint: //Sub Procedure
	rc_getSpriteLocalPoint( GETSPRITELOCALPOINT_SPR_ID,  GETSPRITELOCALPOINT_WX,  GETSPRITELOCALPOINT_WY,  &GETSPRITELOCALPOINT_X,  &GETSPRITELOCALPOINT_Y );
	break;
case FN_getSpriteLocalVector: //Sub Procedure
	rc_getSpriteLocalVector( GETSPRITELOCALVECTOR_SPR_ID,  GETSPRITELOCALVECTOR_WX,  GETSPRITELOCALVECTOR_WY,  &GETSPRITELOCALVECTOR_X,  &GETSPRITELOCALVECTOR_Y );
	break;
case FN_getSpriteLinearVelocityFromLocalPoint: //Sub Procedure
	rc_getSpriteLinearVelocityFromLocalPoint( GETSPRITELINEARVELOCITYFROMLOCALPOINT_SPR_ID,  GETSPRITELINEARVELOCITYFROMLOCALPOINT_PX,  GETSPRITELINEARVELOCITYFROMLOCALPOINT_PY,  &GETSPRITELINEARVELOCITYFROMLOCALPOINT_X,  &GETSPRITELINEARVELOCITYFROMLOCALPOINT_Y );
	break;
case FN_getSpriteLinearVelocityFromWorldPoint: //Sub Procedure
	rc_getSpriteLinearVelocityFromWorldPoint( GETSPRITELINEARVELOCITYFROMWORLDPOINT_SPR_ID,  GETSPRITELINEARVELOCITYFROMWORLDPOINT_WX,  GETSPRITELINEARVELOCITYFROMWORLDPOINT_WY,  &GETSPRITELINEARVELOCITYFROMWORLDPOINT_X,  &GETSPRITELINEARVELOCITYFROMWORLDPOINT_Y );
	break;
case FN_getSpriteLinearDamping: //Number Function
	 rc_push_num(rc_getSpriteLinearDamping(  GETSPRITELINEARDAMPING_SPR_ID ));
	break;
case FN_setSpriteLinearDamping: //Sub Procedure
	rc_setSpriteLinearDamping( SETSPRITELINEARDAMPING_SPR_ID,  SETSPRITELINEARDAMPING_LINEARDAMPING );
	break;
case FN_getSpriteAngularDamping: //Number Function
	 rc_push_num(rc_getSpriteAngularDamping(  GETSPRITEANGULARDAMPING_SPR_ID ));
	break;
case FN_setSpriteAngularDamping: //Sub Procedure
	rc_setSpriteAngularDamping( SETSPRITEANGULARDAMPING_SPR_ID,  SETSPRITEANGULARDAMPING_ANGULARDAMPING );
	break;
case FN_getSpriteGravityScale: //Number Function
	 rc_push_num(rc_getSpriteGravityScale(  GETSPRITEGRAVITYSCALE_SPR_ID ));
	break;
case FN_setSpriteGravityScale: //Sub Procedure
	rc_setSpriteGravityScale( SETSPRITEGRAVITYSCALE_SPR_ID,  SETSPRITEGRAVITYSCALE_G_SCALE );
	break;
case FN_setSpriteBullet: //Sub Procedure
	rc_setSpriteBullet( SETSPRITEBULLET_SPR_ID,  SETSPRITEBULLET_FLAG );
	break;
case FN_spriteIsBullet: //Number Function
	 rc_push_num(rc_spriteIsBullet( SPRITEISBULLET_SPR_ID ));
	break;
case FN_setSpriteSleepAllowed: //Sub Procedure
	rc_setSpriteSleepAllowed( SETSPRITESLEEPALLOWED_SPR_ID,  SETSPRITESLEEPALLOWED_FLAG );
	break;
case FN_spriteSleepAllowed: //Number Function
	 rc_push_num(rc_spriteSleepAllowed( SPRITESLEEPALLOWED_SPR_ID ));
	break;
case FN_setSpriteAwake: //Sub Procedure
	rc_setSpriteAwake( SETSPRITEAWAKE_SPR_ID,  SETSPRITEAWAKE_FLAG );
	break;
case FN_spriteIsAwake: //Number Function
	 rc_push_num(rc_spriteIsAwake( SPRITEISAWAKE_SPR_ID ));
	break;
case FN_setSpriteFixedRotation: //Sub Procedure
	rc_setSpriteFixedRotation( SETSPRITEFIXEDROTATION_SPR_ID,  SETSPRITEFIXEDROTATION_FLAG );
	break;
case FN_spriteIsFixedRotation: //Number Function
	 rc_push_num(rc_spriteIsFixedRotation( SPRITEISFIXEDROTATION_SPR_ID ));
	break;
case FN_SetSpriteDensity: //Sub Procedure
	rc_setSpriteDensity( SETSPRITEDENSITY_SPR_ID,  SETSPRITEDENSITY_DENSITY );
	break;
case FN_GetSpriteDensity: //Number Function
	 rc_push_num(rc_getSpriteDensity( GETSPRITEDENSITY_SPR_ID ));
	break;
case FN_SetSpriteFriction: //Sub Procedure
	rc_setSpriteFriction( SETSPRITEFRICTION_SPR_ID,  SETSPRITEFRICTION_FRICTION );
	break;
case FN_GetSpriteFriction: //Number Function
	 rc_push_num(rc_getSpriteFriction( GETSPRITEFRICTION_SPR_ID ));
	break;
case FN_SetSpriteRestitution: //Sub Procedure
	rc_setSpriteRestitution( SETSPRITERESTITUTION_SPR_ID,  SETSPRITERESTITUTION_RESTITUTION );
	break;
case FN_GetSpriteRestitution: //Number Function
	 rc_push_num(rc_getSpriteRestitution( GETSPRITERESTITUTION_SPR_ID ));
	break;
case FN_SetSpriteRestitutionThreshold: //Sub Procedure
	rc_setSpriteRestitutionThreshold( SETSPRITERESTITUTIONTHRESHOLD_SPR_ID,  SETSPRITERESTITUTIONTHRESHOLD_THRESHOLD );
	break;
case FN_GetSpriteRestitutionThreshold: //Number Function
	 rc_push_num(rc_getSpriteRestitutionThreshold( GETSPRITERESTITUTIONTHRESHOLD_SPR_ID ));
	break;
case FN_GetSpriteAABB: //Sub Procedure
	rc_getSpriteAABB( GETSPRITEAABB_SPR_ID,  &GETSPRITEAABB_X1,  &GETSPRITEAABB_Y1,  &GETSPRITEAABB_X2,  &GETSPRITEAABB_Y2 );
	break;
case FN_SetGravity2D: //Sub Procedure
	rc_setGravity2D( SETGRAVITY2D_X,  SETGRAVITY2D_Y );
	break;
case FN_GetGravity2D: //Sub Procedure
	rc_getGravity2D( &GETGRAVITY2D_X,  &GETGRAVITY2D_Y );
	break;
case FN_SetWorld2DTimeStep: //Sub Procedure
	rc_setWorld2DTimeStep( SETWORLD2DTIMESTEP_TS );
	break;
case FN_SetWorld2DVelocityIterations: //Sub Procedure
	rc_setWorld2DVelocityIterations( SETWORLD2DVELOCITYITERATIONS_V );
	break;
case FN_SetWorld2DPositionIterations: //Sub Procedure
	rc_setWorld2DPositionIterations( SETWORLD2DPOSITIONITERATIONS_P );
	break;
case FN_GetWorld2DTimeStep: //Number Function
	 rc_push_num(rc_getWorld2DTimeStep(  ));
	break;
case FN_GetWorld2DVelocityIterations: //Number Function
	 rc_push_num(rc_getWorld2DVelocityIterations(  ));
	break;
case FN_GetWorld2DPositionIterations: //Number Function
	 rc_push_num(rc_getWorld2DPositionIterations(  ));
	break;
case FN_SetWorld2DAutoClearForces: //Sub Procedure
	rc_setWorld2DAutoClearForces( SETWORLD2DAUTOCLEARFORCES_FLAG );
	break;
case FN_GetWorld2DAutoClearForces: //Number Function
	 rc_push_num(rc_getWorld2DAutoClearForces(  ));
	break;
case FN_CastRay2D: //Number Function
	 rc_push_num(rc_castRay2D( CASTRAY2D_FROM_X,  CASTRAY2D_FROM_Y,  CASTRAY2D_TO_X,  CASTRAY2D_TO_Y ));
	break;
case FN_CastRay2D_All: //Number Function
	 rc_push_num(rc_castRay2D_All( CASTRAY2D_ALL_FROM_X,  CASTRAY2D_ALL_FROM_Y,  CASTRAY2D_ALL_TO_X,  CASTRAY2D_ALL_TO_Y ));
	break;
case FN_GetRayHit2D: //Sub Procedure
	rc_getRayHit2D( GETRAYHIT2D_INDEX,  &GETRAYHIT2D_SPR_ID,  &GETRAYHIT2D_X,  &GETRAYHIT2D_Y,  &GETRAYHIT2D_NORMAL_X,  &GETRAYHIT2D_NORMAL_Y );
	break;
case FN_createDistanceJoint: //Number Function
	 rc_push_num(rc_createDistanceJoint( CREATEDISTANCEJOINT_SPRITEA,  CREATEDISTANCEJOINT_SPRITEB,  CREATEDISTANCEJOINT_AX,  CREATEDISTANCEJOINT_AY,  CREATEDISTANCEJOINT_BX,  CREATEDISTANCEJOINT_BY,  CREATEDISTANCEJOINT_COLLIDE_CONNECT ));
	break;
case FN_createFrictionJoint: //Number Function
	 rc_push_num(rc_createFrictionJoint( CREATEFRICTIONJOINT_SPRITEA,  CREATEFRICTIONJOINT_SPRITEB,  CREATEFRICTIONJOINT_X,  CREATEFRICTIONJOINT_Y,  CREATEFRICTIONJOINT_COLLIDE_CONNECT ));
	break;
case FN_createGearJoint: //Number Function
	 rc_push_num(rc_createGearJoint( CREATEGEARJOINT_JOINTA,  CREATEGEARJOINT_JOINTB,  CREATEGEARJOINT_G_RATIO,  CREATEGEARJOINT_COLLIDE_CONNECT ));
	break;
case FN_createMotorJoint: //Number Function
	 rc_push_num(rc_createMotorJoint( CREATEMOTORJOINT_SPRITEA,  CREATEMOTORJOINT_SPRITEB,  CREATEMOTORJOINT_COLLIDE_CONNECT ));
	break;
case FN_createPrismaticJoint: //Number Function
	 rc_push_num(rc_createPrismaticJoint( CREATEPRISMATICJOINT_SPRITEA,  CREATEPRISMATICJOINT_SPRITEB,  CREATEPRISMATICJOINT_AX,  CREATEPRISMATICJOINT_AY,  CREATEPRISMATICJOINT_AXISX,  CREATEPRISMATICJOINT_AXISY,  CREATEPRISMATICJOINT_COLLIDE_CONNECT ));
	break;
case FN_createPulleyJoint: //Number Function
	 rc_push_num(rc_createPulleyJoint( CREATEPULLEYJOINT_SPRITEA,  CREATEPULLEYJOINT_SPRITEB,  CREATEPULLEYJOINT_GAX,  CREATEPULLEYJOINT_GAY,  CREATEPULLEYJOINT_GBX,  CREATEPULLEYJOINT_GBY,  CREATEPULLEYJOINT_AX,  CREATEPULLEYJOINT_AY,  CREATEPULLEYJOINT_BX,  CREATEPULLEYJOINT_BY,  CREATEPULLEYJOINT_J_RATIO,  CREATEPULLEYJOINT_COLLIDE_CONNECT ));
	break;
case FN_createRevoluteJoint: //Number Function
	 rc_push_num(rc_createRevoluteJoint( CREATEREVOLUTEJOINT_SPRITEA,  CREATEREVOLUTEJOINT_SPRITEB,  CREATEREVOLUTEJOINT_X,  CREATEREVOLUTEJOINT_Y,  CREATEREVOLUTEJOINT_COLLIDE_CONNECT ));
	break;
case FN_createWeldJoint: //Number Function
	 rc_push_num(rc_createWeldJoint( CREATEWELDJOINT_SPRITEA,  CREATEWELDJOINT_SPRITEB,  CREATEWELDJOINT_X,  CREATEWELDJOINT_Y,  CREATEWELDJOINT_COLLIDE_CONNECT ));
	break;
case FN_createWheelJoint: //Number Function
	 rc_push_num(rc_createWheelJoint( CREATEWHEELJOINT_SPRITEA,  CREATEWHEELJOINT_SPRITEB,  CREATEWHEELJOINT_AX,  CREATEWHEELJOINT_AY,  CREATEWHEELJOINT_AXISX,  CREATEWHEELJOINT_AXISY,  CREATEWHEELJOINT_COLLIDE_CONNECT ));
	break;
case FN_getJointWorldAnchorA: //Sub Procedure
	rc_getJointWorldAnchorA( GETJOINTWORLDANCHORA_JOINT_ID,  &GETJOINTWORLDANCHORA_X,  &GETJOINTWORLDANCHORA_Y );
	break;
case FN_getJointWorldAnchorB: //Sub Procedure
	rc_getJointWorldAnchorB( GETJOINTWORLDANCHORB_JOINT_ID,  &GETJOINTWORLDANCHORB_X,  &GETJOINTWORLDANCHORB_Y );
	break;
case FN_getJointReactionForce: //Sub Procedure
	rc_getJointReactionForce( GETJOINTREACTIONFORCE_JOINT_ID,  GETJOINTREACTIONFORCE_INV_DT,  &GETJOINTREACTIONFORCE_X,  &GETJOINTREACTIONFORCE_Y );
	break;
case FN_getJointReactionTorque: //Number Function
	 rc_push_num(rc_getJointReactionTorque(  GETJOINTREACTIONTORQUE_JOINT_ID,   GETJOINTREACTIONTORQUE_INV_DT ));
	break;
case FN_getJointLocalAnchorA: //Sub Procedure
	rc_getJointLocalAnchorA( GETJOINTLOCALANCHORA_JOINT_ID,  &GETJOINTLOCALANCHORA_X,  &GETJOINTLOCALANCHORA_Y );
	break;
case FN_getJointLocalAnchorB: //Sub Procedure
	rc_getJointLocalAnchorB( GETJOINTLOCALANCHORB_JOINT_ID,  &GETJOINTLOCALANCHORB_X,  &GETJOINTLOCALANCHORB_Y );
	break;
case FN_setJointLength: //Sub Procedure
	rc_setJointLength( SETJOINTLENGTH_JOINT_ID,  SETJOINTLENGTH_JLEN );
	break;
case FN_getJointLength: //Number Function
	 rc_push_num(rc_getJointLength(  GETJOINTLENGTH_JOINT_ID ));
	break;
case FN_setJointMinLength: //Sub Procedure
	rc_setJointMinLength( SETJOINTMINLENGTH_JOINT_ID,  SETJOINTMINLENGTH_JLEN );
	break;
case FN_getJointMinLength: //Number Function
	 rc_push_num(rc_getJointMinLength(  GETJOINTMINLENGTH_JOINT_ID ));
	break;
case FN_setJointMaxLength: //Sub Procedure
	rc_setJointMaxLength( SETJOINTMAXLENGTH_JOINT_ID,  SETJOINTMAXLENGTH_JLEN );
	break;
case FN_getJointMaxLength: //Number Function
	 rc_push_num(rc_getJointMaxLength(  GETJOINTMAXLENGTH_JOINT_ID ));
	break;
case FN_getJointCurrentLength: //Number Function
	 rc_push_num(rc_getJointCurrentLength(  GETJOINTCURRENTLENGTH_JOINT_ID ));
	break;
case FN_setJointStiffness: //Sub Procedure
	rc_setJointStiffness( SETJOINTSTIFFNESS_JOINT_ID,  SETJOINTSTIFFNESS_STIFFNESS );
	break;
case FN_getJointStiffness: //Number Function
	 rc_push_num(rc_getJointStiffness(  GETJOINTSTIFFNESS_JOINT_ID ));
	break;
case FN_setJointDamping: //Sub Procedure
	rc_setJointDamping( SETJOINTDAMPING_JOINT_ID,  SETJOINTDAMPING_DAMPING );
	break;
case FN_getJointDamping: //Number Function
	 rc_push_num(rc_getJointDamping(  GETJOINTDAMPING_JOINT_ID ));
	break;
case FN_setJointMaxForce: //Sub Procedure
	rc_setJointMaxForce( SETJOINTMAXFORCE_JOINT_ID,  SETJOINTMAXFORCE_FORCE );
	break;
case FN_getJointMaxForce: //Number Function
	 rc_push_num(rc_getJointMaxForce(  GETJOINTMAXFORCE_JOINT_ID ));
	break;
case FN_setJointMaxTorque: //Sub Procedure
	rc_setJointMaxTorque( SETJOINTMAXTORQUE_JOINT_ID,  SETJOINTMAXTORQUE_TORQUE );
	break;
case FN_getJointMaxTorque: //Number Function
	 rc_push_num(rc_getJointMaxTorque(  GETJOINTMAXTORQUE_JOINT_ID ));
	break;
case FN_setJointCorrectionFactor: //Sub Procedure
	rc_setJointCorrectionFactor( SETJOINTCORRECTIONFACTOR_JOINT_ID,  SETJOINTCORRECTIONFACTOR_FACTOR );
	break;
case FN_getJointCorrectionFactor: //Number Function
	 rc_push_num(rc_getJointCorrectionFactor(  GETJOINTCORRECTIONFACTOR_JOINT_ID ));
	break;
case FN_setJointRatio: //Sub Procedure
	rc_setJointRatio( SETJOINTRATIO_JOINT_ID,  SETJOINTRATIO_J_RATIO );
	break;
case FN_getJointRatio: //Number Function
	 rc_push_num(rc_getJointRatio(  GETJOINTRATIO_JOINT_ID ));
	break;
case FN_setJointLinearOffset: //Sub Procedure
	rc_setJointLinearOffset( SETJOINTLINEAROFFSET_JOINT_ID,  SETJOINTLINEAROFFSET_X,  SETJOINTLINEAROFFSET_Y );
	break;
case FN_getJointLinearOffset: //Sub Procedure
	rc_getJointLinearOffset( GETJOINTLINEAROFFSET_JOINT_ID,  &GETJOINTLINEAROFFSET_X,  &GETJOINTLINEAROFFSET_Y );
	break;
case FN_setJointAngularOffset: //Sub Procedure
	rc_setJointAngularOffset( SETJOINTANGULAROFFSET_JOINT_ID,  SETJOINTANGULAROFFSET_ANGLEOFFSET );
	break;
case FN_getJointAngularOffset: //Number Function
	 rc_push_num(rc_getJointAngularOffset(  GETJOINTANGULAROFFSET_JOINT_ID ));
	break;
case FN_getJointLocalAxisA: //Sub Procedure
	rc_getJointLocalAxisA( GETJOINTLOCALAXISA_JOINT_ID,  &GETJOINTLOCALAXISA_X,  &GETJOINTLOCALAXISA_Y );
	break;
case FN_getJointReferenceAngle: //Number Function
	 rc_push_num(rc_getJointReferenceAngle(  GETJOINTREFERENCEANGLE_JOINT_ID ));
	break;
case FN_getJointTranslation: //Number Function
	 rc_push_num(rc_getJointTranslation(  GETJOINTTRANSLATION_JOINT_ID ));
	break;
case FN_getJointSpeed: //Number Function
	 rc_push_num(rc_getJointSpeed(  GETJOINTSPEED_JOINT_ID ));
	break;
case FN_jointIsLimitEnabled: //Number Function
	 rc_push_num(rc_jointIsLimitEnabled( JOINTISLIMITENABLED_JOINT_ID ));
	break;
case FN_enableJointLimit: //Sub Procedure
	rc_enableJointLimit( ENABLEJOINTLIMIT_JOINT_ID,  ENABLEJOINTLIMIT_FLAG );
	break;
case FN_getJointLowerLimit: //Number Function
	 rc_push_num(rc_getJointLowerLimit(  GETJOINTLOWERLIMIT_JOINT_ID ));
	break;
case FN_getJointUpperLimit: //Number Function
	 rc_push_num(rc_getJointUpperLimit(  GETJOINTUPPERLIMIT_JOINT_ID ));
	break;
case FN_setJointLimits: //Sub Procedure
	rc_setJointLimits( SETJOINTLIMITS_JOINT_ID,  SETJOINTLIMITS_LOWER_LIMIT,  SETJOINTLIMITS_UPPER_LIMIT );
	break;
case FN_jointMotorIsEnabled: //Number Function
	 rc_push_num(rc_jointMotorIsEnabled( JOINTMOTORISENABLED_JOINT_ID ));
	break;
case FN_enableJointMotor: //Sub Procedure
	rc_enableJointMotor( ENABLEJOINTMOTOR_JOINT_ID,  ENABLEJOINTMOTOR_FLAG );
	break;
case FN_setJointMotorSpeed: //Sub Procedure
	rc_setJointMotorSpeed( SETJOINTMOTORSPEED_JOINT_ID,  SETJOINTMOTORSPEED_SPEED );
	break;
case FN_getJointMotorSpeed: //Number Function
	 rc_push_num(rc_getJointMotorSpeed(  GETJOINTMOTORSPEED_JOINT_ID ));
	break;
case FN_setJointMaxMotorForce: //Sub Procedure
	rc_setJointMaxMotorForce( SETJOINTMAXMOTORFORCE_JOINT_ID,  SETJOINTMAXMOTORFORCE_FORCE );
	break;
case FN_getJointMaxMotorForce: //Number Function
	 rc_push_num(rc_getJointMaxMotorForce(  GETJOINTMAXMOTORFORCE_JOINT_ID ));
	break;
case FN_getJointMotorForce: //Number Function
	 rc_push_num(rc_getJointMotorForce(  GETJOINTMOTORFORCE_JOINT_ID,   GETJOINTMOTORFORCE_INV_DT ));
	break;
case FN_setJointMaxMotorTorque: //Sub Procedure
	rc_setJointMaxMotorTorque( SETJOINTMAXMOTORTORQUE_JOINT_ID,  SETJOINTMAXMOTORTORQUE_TORQUE );
	break;
case FN_getJointMaxMotorTorque: //Number Function
	 rc_push_num(rc_getJointMaxMotorTorque(  GETJOINTMAXMOTORTORQUE_JOINT_ID ));
	break;
case FN_getJointMotorTorque: //Number Function
	 rc_push_num(rc_getJointMotorTorque(  GETJOINTMOTORTORQUE_JOINT_ID,   GETJOINTMOTORTORQUE_INV_DT ));
	break;
case FN_getJointGroundAnchorA: //Sub Procedure
	rc_getJointGroundAnchorA( GETJOINTGROUNDANCHORA_JOINT_ID,  &GETJOINTGROUNDANCHORA_X,  &GETJOINTGROUNDANCHORA_Y );
	break;
case FN_getJointGroundAnchorB: //Sub Procedure
	rc_getJointGroundAnchorB( GETJOINTGROUNDANCHORB_JOINT_ID,  &GETJOINTGROUNDANCHORB_X,  &GETJOINTGROUNDANCHORB_Y );
	break;
case FN_getJointLengthA: //Number Function
	 rc_push_num(rc_getJointLengthA(  GETJOINTLENGTHA_JOINT_ID ));
	break;
case FN_getJointLengthB: //Number Function
	 rc_push_num(rc_getJointLengthB(  GETJOINTLENGTHB_JOINT_ID ));
	break;
case FN_getJointCurrentLengthA: //Number Function
	 rc_push_num(rc_getJointCurrentLengthA(  GETJOINTCURRENTLENGTHA_JOINT_ID ));
	break;
case FN_getJointCurrentLengthB: //Number Function
	 rc_push_num(rc_getJointCurrentLengthB(  GETJOINTCURRENTLENGTHB_JOINT_ID ));
	break;
case FN_setJointOrigin: //Sub Procedure
	rc_setJointOrigin( SETJOINTORIGIN_JOINT_ID,  SETJOINTORIGIN_X,  SETJOINTORIGIN_Y );
	break;
case FN_getJointAngle: //Number Function
	 rc_push_num(rc_getJointAngle(  GETJOINTANGLE_JOINT_ID ));
	break;
case FN_getJointLinearSpeed: //Number Function
	 rc_push_num(rc_getJointLinearSpeed(  GETJOINTLINEARSPEED_JOINT_ID ));
	break;
case FN_getJointAngularSpeed: //Number Function
	 rc_push_num(rc_getJointAngularSpeed(  GETJOINTANGULARSPEED_JOINT_ID ));
	break;
case FN_DeleteJoint: //Sub Procedure
	rc_deleteJoint( DELETEJOINT_JOINT_ID );
	break;
case FN_CreateTileSet: //Number Function
	 rc_push_num(rc_createTileSet( CREATETILESET_IMG_ID,  CREATETILESET_TILE_W,  CREATETILESET_TILE_H ));
	break;
case FN_SetTileAnimationLength: //Sub Procedure
	rc_setTileAnimationLength( SETTILEANIMATIONLENGTH_TILESET,  SETTILEANIMATIONLENGTH_BASE_TILE,  SETTILEANIMATIONLENGTH_NUM_FRAMES );
	break;
case FN_GetTileAnimationLength: //Number Function
	 rc_push_num(rc_getTileAnimationLength( GETTILEANIMATIONLENGTH_TILESET,  GETTILEANIMATIONLENGTH_BASE_TILE ));
	break;
case FN_SetTileAnimationFrame: //Sub Procedure
	rc_setTileAnimationFrame( SETTILEANIMATIONFRAME_TILESET,  SETTILEANIMATIONFRAME_BASE_TILE,  SETTILEANIMATIONFRAME_ANIM_FRAME,  SETTILEANIMATIONFRAME_TILE_FRAME );
	break;
case FN_GetTileAnimationFrame: //Number Function
	 rc_push_num(rc_getTileAnimationFrame( GETTILEANIMATIONFRAME_TILESET,  GETTILEANIMATIONFRAME_BASE_TILE,  GETTILEANIMATIONFRAME_ANIM_FRAME ));
	break;
case FN_SetTileAnimationSpeed: //Sub Procedure
	rc_setTileAnimationSpeed( SETTILEANIMATIONSPEED_TILESET,  SETTILEANIMATIONSPEED_BASE_TILE,  SETTILEANIMATIONSPEED_SPEED );
	break;
case FN_GetTileAnimationSpeed: //Number Function
	 rc_push_num(rc_getTileAnimationSpeed( GETTILEANIMATIONSPEED_TILESET,  GETTILEANIMATIONSPEED_BASE_TILE ));
	break;
case FN_CreateTileMap: //Number Function
	 rc_push_num(rc_createTileMap( CREATETILEMAP_TILESET,  CREATETILEMAP_WIDTHINTILES,  CREATETILEMAP_HEIGHTINTILES ));
	break;
case FN_SetTileMapSize: //Sub Procedure
	rc_setTileMapSize( SETTILEMAPSIZE_TILEMAP,  SETTILEMAPSIZE_WIDTHINTILES,  SETTILEMAPSIZE_HEIGHTINTILES );
	break;
case FN_GetTileMapSize: //Sub Procedure
	rc_getTileMapSize( GETTILEMAPSIZE_TILEMAP,  &GETTILEMAPSIZE_WIDTHINTILES,  &GETTILEMAPSIZE_HEIGHTINTILES );
	break;
case FN_SetTile: //Sub Procedure
	rc_setTile( SETTILE_TILEMAP,  SETTILE_TILE,  SETTILE_X,  SETTILE_Y );
	break;
case FN_GetTile: //Number Function
	 rc_push_num(rc_getTile( GETTILE_TILEMAP,  GETTILE_X,  GETTILE_Y ));
	break;
case FN_FillTile: //Sub Procedure
	rc_fillTile( FILLTILE_TILEMAP,  FILLTILE_TILE,  FILLTILE_X,  FILLTILE_Y,  FILLTILE_WIDTHINTILES,  FILLTILE_HEIGHTINTILES );
	break;
case FN_DrawTileMap: //Sub Procedure
	rc_drawTileMap( DRAWTILEMAP_TILEMAP,  DRAWTILEMAP_X,  DRAWTILEMAP_Y,  DRAWTILEMAP_W,  DRAWTILEMAP_H,  DRAWTILEMAP_OFFSET_X,  DRAWTILEMAP_OFFSET_Y );
	break;
case FN_DeleteTileSet: //Sub Procedure
	rc_deleteTileSet( DELETETILESET_TILESET );
	break;
case FN_DeleteTileMap: //Sub Procedure
	rc_deleteTileMap( DELETETILEMAP_TILEMAP );
	break;
case FN_LoadMesh: //Number Function
	 rc_push_num(rc_loadMesh( LOADMESH_MESH_FILE$ ));
	break;
case FN_DeleteMesh: //Sub Procedure
	rc_deleteMesh( DELETEMESH_MESH );
	break;
case FN_CreateMesh: //Number Function
	 rc_push_num(rc_createMesh(  ));
	break;
case FN_AddMeshBuffer: //Sub Procedure
	rc_addMeshBuffer( ADDMESHBUFFER_MESH,  ADDMESHBUFFER_VERTEX_COUNT,  &ADDMESHBUFFER_VERTEX_DATA,  &ADDMESHBUFFER_NORMAL_DATA,  &ADDMESHBUFFER_UV_DATA,  ADDMESHBUFFER_INDEX_COUNT,  &ADDMESHBUFFER_INDEX_DATA );
	break;
case FN_LoadMeshFromArchive: //Number Function
	 rc_push_num(rc_loadMeshFromArchive( LOADMESHFROMARCHIVE_ARCHIVE$,  LOADMESHFROMARCHIVE_MESH_FILE$ ));
	break;
case FN_CreatePlaneMesh: //Number Function
	 rc_push_num(rc_createPlaneMesh( CREATEPLANEMESH_W,  CREATEPLANEMESH_H,  CREATEPLANEMESH_TILECOUNT_W,  CREATEPLANEMESH_TILECOUNT_H ));
	break;
case FN_LoadAN8: //Number Function
	 rc_push_num(rc_loadAN8( LOADAN8_AN8_FILE$ ));
	break;
case FN_LoadMeshFromAN8: //Number Function
	 rc_push_num(rc_loadMeshFromAN8( LOADMESHFROMAN8_AN8_PROJECT,  LOADMESHFROMAN8_AN8_SCENE$ ));
	break;
case FN_GetNumAN8Scenes: //Number Function
	 rc_push_num(rc_getNumAN8Scenes( GETNUMAN8SCENES_AN8_PROJECT ));
	break;
case FN_GetAN8SceneName$: //String Function
	 rc_push_str(rc_getAN8SceneName( GETAN8SCENENAME$_AN8_PROJECT,  GETAN8SCENENAME$_SCENE_NUM ));
	break;
case FN_CreateAnimatedActor: //Number Function
	 rc_push_num(rc_createAnimatedActor( CREATEANIMATEDACTOR_MESH ));
	break;
case FN_CreateOctreeActor: //Number Function
	 rc_push_num(rc_createOctreeActor( CREATEOCTREEACTOR_MESH ));
	break;
case FN_CreateCubeActor: //Number Function
	 rc_push_num(rc_createCubeActor( CREATECUBEACTOR_CUBE_SIZE ));
	break;
case FN_CreateSphereActor: //Number Function
	 rc_push_num(rc_createSphereActor( CREATESPHEREACTOR_RADIUS ));
	break;
case FN_CreateWaterActor: //Number Function
	 rc_push_num(rc_createWaterActor( CREATEWATERACTOR_MESH,  CREATEWATERACTOR_WAVEHEIGHT,  CREATEWATERACTOR_WAVESPEED,  CREATEWATERACTOR_WAVELENGTH ));
	break;
case FN_CreateLightActor: //Number Function
	 rc_push_num(rc_createLightActor(  ));
	break;
case FN_CreateBillboardActor: //Number Function
	 rc_push_num(rc_createBillboardActor(  ));
	break;
case FN_CreateTerrainActor: //Number Function
	 rc_push_num(rc_createTerrainActor( CREATETERRAINACTOR_HMAP_FILE$ ));
	break;
case FN_CreateParticleActor: //Number Function
	 rc_push_num(rc_createParticleActor( CREATEPARTICLEACTOR_PARTICLE_TYPE ));
	break;
case FN_DeleteActor: //Sub Procedure
	rc_deleteActor( DELETEACTOR_ACTOR );
	break;
case FN_GetActorTransform: //Sub Procedure
	rc_getActorTransform( GETACTORTRANSFORM_ACTOR,  GETACTORTRANSFORM_MATRIX );
	break;
case FN_SetActorPosition: //Sub Procedure
	rc_setActorPosition( SETACTORPOSITION_ACTOR,  SETACTORPOSITION_X,  SETACTORPOSITION_Y,  SETACTORPOSITION_Z );
	break;
case FN_TranslateActorLocal: //Sub Procedure
	rc_translateActorLocal( TRANSLATEACTORLOCAL_ACTOR,  TRANSLATEACTORLOCAL_X,  TRANSLATEACTORLOCAL_Y,  TRANSLATEACTORLOCAL_Z );
	break;
case FN_TranslateActorWorld: //Sub Procedure
	rc_translateActorWorld( TRANSLATEACTORWORLD_ACTOR,  TRANSLATEACTORWORLD_X,  TRANSLATEACTORWORLD_Y,  TRANSLATEACTORWORLD_Z );
	break;
case FN_GetActorPosition: //Sub Procedure
	rc_getActorPosition( GETACTORPOSITION_ACTOR,  &GETACTORPOSITION_X,  &GETACTORPOSITION_Y,  &GETACTORPOSITION_Z );
	break;
case FN_SetActorScale: //Sub Procedure
	rc_setActorScale( SETACTORSCALE_ACTOR,  SETACTORSCALE_X,  SETACTORSCALE_Y,  SETACTORSCALE_Z );
	break;
case FN_ScaleActor: //Sub Procedure
	rc_scaleActor( SCALEACTOR_ACTOR,  SCALEACTOR_X,  SCALEACTOR_Y,  SCALEACTOR_Z );
	break;
case FN_GetActorScale: //Sub Procedure
	rc_getActorScale( GETACTORSCALE_ACTOR,  &GETACTORSCALE_X,  &GETACTORSCALE_Y,  &GETACTORSCALE_Z );
	break;
case FN_SetActorRotation: //Sub Procedure
	rc_setActorRotation( SETACTORROTATION_ACTOR,  SETACTORROTATION_X,  SETACTORROTATION_Y,  SETACTORROTATION_Z );
	break;
case FN_RotateActor: //Sub Procedure
	rc_rotateActor( ROTATEACTOR_ACTOR,  ROTATEACTOR_X,  ROTATEACTOR_Y,  ROTATEACTOR_Z );
	break;
case FN_GetActorRotation: //Sub Procedure
	rc_getActorRotation( GETACTORROTATION_ACTOR,  &GETACTORROTATION_X,  &GETACTORROTATION_Y,  &GETACTORROTATION_Z );
	break;
case FN_SetActorVisible: //Sub Procedure
	rc_setActorVisible( SETACTORVISIBLE_ACTOR,  SETACTORVISIBLE_FLAG );
	break;
case FN_ActorIsVisible: //Number Function
	 rc_push_num(rc_actorIsVisible( ACTORISVISIBLE_ACTOR ));
	break;
case FN_SetActorAutoCulling: //Sub Procedure
	rc_setActorAutoCulling( SETACTORAUTOCULLING_ACTOR,  SETACTORAUTOCULLING_CULL_TYPE );
	break;
case FN_GetActorAutoCulling: //Number Function
	 rc_push_num(rc_getActorAutoCulling( GETACTORAUTOCULLING_ACTOR ));
	break;
case FN_AddActorShadow: //Sub Procedure
	rc_addActorShadow( ADDACTORSHADOW_ACTOR );
	break;
case FN_RemoveActorShadow: //Sub Procedure
	rc_removeActorShadow( REMOVEACTORSHADOW_ACTOR );
	break;
case FN_ActorExists: //Number Function
	 rc_push_num(rc_actorExists( ACTOREXISTS_ACTOR ));
	break;
case FN_CreateActorAnimation: //Number Function
	 rc_push_num(rc_createActorAnimation( CREATEACTORANIMATION_ACTOR,  CREATEACTORANIMATION_START_FRAME,  CREATEACTORANIMATION_END_FRAME,  CREATEACTORANIMATION_SPEED ));
	break;
case FN_SetActorAnimation: //Sub Procedure
	rc_setActorAnimation( SETACTORANIMATION_ACTOR,  SETACTORANIMATION_ANIMATION,  SETACTORANIMATION_NUM_LOOPS );
	break;
case FN_SetActorAnimationSpeed: //Sub Procedure
	rc_setActorAnimationSpeed( SETACTORANIMATIONSPEED_ACTOR,  SETACTORANIMATIONSPEED_ANIMATION,  SETACTORANIMATIONSPEED_SPEED );
	break;
case FN_SetActorAnimationFrames: //Sub Procedure
	rc_setActorAnimationFrames( SETACTORANIMATIONFRAMES_ACTOR,  SETACTORANIMATIONFRAMES_ANIMATION,  SETACTORANIMATIONFRAMES_START_FRAME,  SETACTORANIMATIONFRAMES_END_FRAME );
	break;
case FN_GetActorCurrentAnimation: //Number Function
	 rc_push_num(rc_getActorCurrentAnimation( GETACTORCURRENTANIMATION_ACTOR ));
	break;
case FN_GetActorAnimationSpeed: //Number Function
	 rc_push_num(rc_getActorAnimationSpeed( GETACTORANIMATIONSPEED_ACTOR,  GETACTORANIMATIONSPEED_ANIMATION ));
	break;
case FN_GetActorAnimationStartFrame: //Number Function
	 rc_push_num(rc_getActorAnimationStartFrame( GETACTORANIMATIONSTARTFRAME_ACTOR,  GETACTORANIMATIONSTARTFRAME_ANIMATION ));
	break;
case FN_GetActorAnimationEndFrame: //Number Function
	 rc_push_num(rc_getActorAnimationEndFrame( GETACTORANIMATIONENDFRAME_ACTOR,  GETACTORANIMATIONENDFRAME_ANIMATION ));
	break;
case FN_SetActorFrame: //Sub Procedure
	rc_setActorFrame( SETACTORFRAME_ACTOR,  SETACTORFRAME_FRAME );
	break;
case FN_GetActorFrame: //Number Function
	 rc_push_num(rc_getActorFrame( GETACTORFRAME_ACTOR ));
	break;
case FN_ActorAnimationIsPlaying: //Number Function
	 rc_push_num(rc_actorAnimationIsPlaying( ACTORANIMATIONISPLAYING_ACTOR ));
	break;
case FN_NumActorAnimationLoops: //Number Function
	 rc_push_num(rc_numActorAnimationLoops( NUMACTORANIMATIONLOOPS_ACTOR ));
	break;
case FN_SetActorMD2Animation: //Sub Procedure
	rc_setActorMD2Animation( SETACTORMD2ANIMATION_ACTOR,  SETACTORMD2ANIMATION_ANIM,  SETACTORMD2ANIMATION_NUM_LOOPS );
	break;
case FN_SetActorMD2AnimationByName: //Sub Procedure
	rc_setActorMD2AnimationByName( SETACTORMD2ANIMATIONBYNAME_ACTOR,  SETACTORMD2ANIMATIONBYNAME_ANIM_NAME$,  SETACTORMD2ANIMATIONBYNAME_NUM_LOOPS );
	break;
case FN_DeleteActorAnimation: //Sub Procedure
	rc_deleteActorAnimation( DELETEACTORANIMATION_ACTOR,  DELETEACTORANIMATION_ANIMATION );
	break;
case FN_SetGravity3D: //Sub Procedure
	rc_setGravity3D( SETGRAVITY3D_X,  SETGRAVITY3D_Y,  SETGRAVITY3D_Z );
	break;
case FN_GetGravity3D: //Sub Procedure
	rc_getGravity3D( &GETGRAVITY3D_X,  &GETGRAVITY3D_Y,  &GETGRAVITY3D_Z );
	break;
case FN_SetActorCollisionShape: //Sub Procedure
	rc_setActorCollisionShape( SETACTORCOLLISIONSHAPE_ACTOR,  SETACTORCOLLISIONSHAPE_SHAPE_TYPE,  SETACTORCOLLISIONSHAPE_MASS );
	break;
case FN_GetActorCollisionShape: //Number Function
	 rc_push_num(rc_getActorCollisionShape( GETACTORCOLLISIONSHAPE_ACTOR ));
	break;
case FN_SetActorSolid: //Sub Procedure
	rc_setActorSolid( SETACTORSOLID_ACTOR,  SETACTORSOLID_FLAG );
	break;
case FN_ActorIsSolid: //Number Function
	 rc_push_num(rc_actorIsSolid( ACTORISSOLID_ACTOR ));
	break;
case FN_GetActorCollision: //Number Function
	 rc_push_num(rc_getActorCollision( GETACTORCOLLISION_ACTOR1,  GETACTORCOLLISION_ACTOR2 ));
	break;
case FN_SetActorGravity: //Sub Procedure
	rc_setActorGravity( SETACTORGRAVITY_ACTOR,  SETACTORGRAVITY_X,  SETACTORGRAVITY_Y,  SETACTORGRAVITY_Z );
	break;
case FN_GetActorGravity: //Sub Procedure
	rc_getActorGravity( GETACTORGRAVITY_ACTOR,  &GETACTORGRAVITY_X,  &GETACTORGRAVITY_Y,  &GETACTORGRAVITY_Z );
	break;
case FN_setActorDamping: //Sub Procedure
	rc_setActorDamping( SETACTORDAMPING_ACTOR,  SETACTORDAMPING_LIN_DAMPING,  SETACTORDAMPING_ANG_DAMPING );
	break;
case FN_getActorLinearDamping: //Number Function
	 rc_push_num(rc_getActorLinearDamping( GETACTORLINEARDAMPING_ACTOR ));
	break;
case FN_getActorAngularDamping: //Number Function
	 rc_push_num(rc_getActorAngularDamping(  GETACTORANGULARDAMPING_ACTOR ));
	break;
case FN_getActorLinearSleepThreshold: //Number Function
	 rc_push_num(rc_getActorLinearSleepThreshold(  GETACTORLINEARSLEEPTHRESHOLD_ACTOR ));
	break;
case FN_getActorAngularSleepThreshold: //Number Function
	 rc_push_num(rc_getActorAngularSleepThreshold(  GETACTORANGULARSLEEPTHRESHOLD_ACTOR ));
	break;
case FN_applyActorDamping: //Sub Procedure
	rc_applyActorDamping( APPLYACTORDAMPING_ACTOR,  APPLYACTORDAMPING_TIMESTEP );
	break;
case FN_setActorMassProperties: //Sub Procedure
	rc_setActorMassProperties( SETACTORMASSPROPERTIES_ACTOR,  SETACTORMASSPROPERTIES_MASS,  SETACTORMASSPROPERTIES_INERTIA_X,  SETACTORMASSPROPERTIES_INERTIA_Y,  SETACTORMASSPROPERTIES_INERTIA_Z );
	break;
case FN_getActorLinearFactor: //Sub Procedure
	rc_getActorLinearFactor( GETACTORLINEARFACTOR_ACTOR,  &GETACTORLINEARFACTOR_X,  &GETACTORLINEARFACTOR_Y,  &GETACTORLINEARFACTOR_Z );
	break;
case FN_setActorLinearFactor: //Sub Procedure
	rc_setActorLinearFactor( SETACTORLINEARFACTOR_ACTOR,  SETACTORLINEARFACTOR_X,  SETACTORLINEARFACTOR_Y,  SETACTORLINEARFACTOR_Z );
	break;
case FN_getActorInverseMass: //Number Function
	 rc_push_num(rc_getActorInverseMass(  GETACTORINVERSEMASS_ACTOR ));
	break;
case FN_integrateActorVelocities: //Sub Procedure
	rc_integrateActorVelocities( INTEGRATEACTORVELOCITIES_ACTOR,  INTEGRATEACTORVELOCITIES_V_STEP );
	break;
case FN_applyActorCentralForceLocal: //Sub Procedure
	rc_applyActorCentralForceLocal( APPLYACTORCENTRALFORCELOCAL_ACTOR,  APPLYACTORCENTRALFORCELOCAL_X,  APPLYACTORCENTRALFORCELOCAL_Y,  APPLYACTORCENTRALFORCELOCAL_Z );
	break;
case FN_applyActorCentralForceWorld: //Sub Procedure
	rc_applyActorCentralForceWorld( APPLYACTORCENTRALFORCEWORLD_ACTOR,  APPLYACTORCENTRALFORCEWORLD_X,  APPLYACTORCENTRALFORCEWORLD_Y,  APPLYACTORCENTRALFORCEWORLD_Z );
	break;
case FN_getActorTotalForce: //Sub Procedure
	rc_getActorTotalForce( GETACTORTOTALFORCE_ACTOR,  &GETACTORTOTALFORCE_X,  &GETACTORTOTALFORCE_Y,  &GETACTORTOTALFORCE_Z );
	break;
case FN_getActorTotalTorque: //Sub Procedure
	rc_getActorTotalTorque( GETACTORTOTALTORQUE_ACTOR,  &GETACTORTOTALTORQUE_X,  &GETACTORTOTALTORQUE_Y,  &GETACTORTOTALTORQUE_Z );
	break;
case FN_getActorInverseInertiaDiagLocal: //Sub Procedure
	rc_getActorInverseInertiaDiagLocal( GETACTORINVERSEINERTIADIAGLOCAL_ACTOR,  &GETACTORINVERSEINERTIADIAGLOCAL_X,  &GETACTORINVERSEINERTIADIAGLOCAL_Y,  &GETACTORINVERSEINERTIADIAGLOCAL_Z );
	break;
case FN_setActorInverseInertiaDiagLocal: //Sub Procedure
	rc_setActorInverseInertiaDiagLocal( SETACTORINVERSEINERTIADIAGLOCAL_ACTOR,  SETACTORINVERSEINERTIADIAGLOCAL_X,  SETACTORINVERSEINERTIADIAGLOCAL_Y,  SETACTORINVERSEINERTIADIAGLOCAL_Z );
	break;
case FN_setActorSleepThresholds: //Sub Procedure
	rc_setActorSleepThresholds( SETACTORSLEEPTHRESHOLDS_ACTOR,  SETACTORSLEEPTHRESHOLDS_LINEAR,  SETACTORSLEEPTHRESHOLDS_ANGULAR );
	break;
case FN_applyActorTorqueLocal: //Sub Procedure
	rc_applyActorTorqueLocal( APPLYACTORTORQUELOCAL_ACTOR,  APPLYACTORTORQUELOCAL_X,  APPLYACTORTORQUELOCAL_Y,  APPLYACTORTORQUELOCAL_Z );
	break;
case FN_applyActorTorqueWorld: //Sub Procedure
	rc_applyActorTorqueWorld( APPLYACTORTORQUEWORLD_ACTOR,  APPLYACTORTORQUEWORLD_X,  APPLYACTORTORQUEWORLD_Y,  APPLYACTORTORQUEWORLD_Z );
	break;
case FN_applyActorForceLocal: //Sub Procedure
	rc_applyActorForceLocal( APPLYACTORFORCELOCAL_ACTOR,  APPLYACTORFORCELOCAL_X,  APPLYACTORFORCELOCAL_Y,  APPLYACTORFORCELOCAL_Z,  APPLYACTORFORCELOCAL_REL_X,  APPLYACTORFORCELOCAL_REL_Y,  APPLYACTORFORCELOCAL_REL_Z );
	break;
case FN_applyActorForceWorld: //Sub Procedure
	rc_applyActorForceWorld( APPLYACTORFORCEWORLD_ACTOR,  APPLYACTORFORCEWORLD_X,  APPLYACTORFORCEWORLD_Y,  APPLYACTORFORCEWORLD_Z,  APPLYACTORFORCEWORLD_REL_X,  APPLYACTORFORCEWORLD_REL_Y,  APPLYACTORFORCEWORLD_REL_Z );
	break;
case FN_applyActorCentralImpulseLocal: //Sub Procedure
	rc_applyActorCentralImpulseLocal( APPLYACTORCENTRALIMPULSELOCAL_ACTOR,  APPLYACTORCENTRALIMPULSELOCAL_X,  APPLYACTORCENTRALIMPULSELOCAL_Y,  APPLYACTORCENTRALIMPULSELOCAL_Z );
	break;
case FN_applyActorCentralImpulseWorld: //Sub Procedure
	rc_applyActorCentralImpulseWorld( APPLYACTORCENTRALIMPULSEWORLD_ACTOR,  APPLYACTORCENTRALIMPULSEWORLD_X,  APPLYACTORCENTRALIMPULSEWORLD_Y,  APPLYACTORCENTRALIMPULSEWORLD_Z );
	break;
case FN_applyActorTorqueImpulseLocal: //Sub Procedure
	rc_applyActorTorqueImpulseLocal( APPLYACTORTORQUEIMPULSELOCAL_ACTOR,  APPLYACTORTORQUEIMPULSELOCAL_X,  APPLYACTORTORQUEIMPULSELOCAL_Y,  APPLYACTORTORQUEIMPULSELOCAL_Z );
	break;
case FN_applyActorTorqueImpulseWorld: //Sub Procedure
	rc_applyActorTorqueImpulseWorld( APPLYACTORTORQUEIMPULSEWORLD_ACTOR,  APPLYACTORTORQUEIMPULSEWORLD_X,  APPLYACTORTORQUEIMPULSEWORLD_Y,  APPLYACTORTORQUEIMPULSEWORLD_Z );
	break;
case FN_applyActorImpulseLocal: //Sub Procedure
	rc_applyActorImpulseLocal( APPLYACTORIMPULSELOCAL_ACTOR,  APPLYACTORIMPULSELOCAL_X,  APPLYACTORIMPULSELOCAL_Y,  APPLYACTORIMPULSELOCAL_Z,  APPLYACTORIMPULSELOCAL_REL_X,  APPLYACTORIMPULSELOCAL_REL_Y,  APPLYACTORIMPULSELOCAL_REL_Z );
	break;
case FN_applyActorImpulseWorld: //Sub Procedure
	rc_applyActorImpulseWorld( APPLYACTORIMPULSEWORLD_ACTOR,  APPLYACTORIMPULSEWORLD_X,  APPLYACTORIMPULSEWORLD_Y,  APPLYACTORIMPULSEWORLD_Z,  APPLYACTORIMPULSEWORLD_REL_X,  APPLYACTORIMPULSEWORLD_REL_Y,  APPLYACTORIMPULSEWORLD_REL_Z );
	break;
case FN_clearActorForces: //Sub Procedure
	rc_clearActorForces( CLEARACTORFORCES_ACTOR );
	break;
case FN_updateActorInertiaTensor: //Sub Procedure
	rc_updateActorInertiaTensor( UPDATEACTORINERTIATENSOR_ACTOR );
	break;
case FN_getActorCenter: //Sub Procedure
	rc_getActorCenter( GETACTORCENTER_ACTOR,  &GETACTORCENTER_X,  &GETACTORCENTER_Y,  &GETACTORCENTER_Z );
	break;
case FN_getActorRotationQ: //Sub Procedure
	rc_getActorRotationQ( GETACTORROTATIONQ_ACTOR,  &GETACTORROTATIONQ_X,  &GETACTORROTATIONQ_Y,  &GETACTORROTATIONQ_Z,  &GETACTORROTATIONQ_W );
	break;
case FN_getActorLinearVelocityWorld: //Sub Procedure
	rc_getActorLinearVelocityWorld( GETACTORLINEARVELOCITYWORLD_ACTOR,  &GETACTORLINEARVELOCITYWORLD_X,  &GETACTORLINEARVELOCITYWORLD_Y,  &GETACTORLINEARVELOCITYWORLD_Z );
	break;
case FN_getActorAngularVelocityWorld: //Sub Procedure
	rc_getActorAngularVelocityWorld( GETACTORANGULARVELOCITYWORLD_ACTOR,  &GETACTORANGULARVELOCITYWORLD_X,  &GETACTORANGULARVELOCITYWORLD_Y,  &GETACTORANGULARVELOCITYWORLD_Z );
	break;
case FN_setActorLinearVelocityLocal: //Sub Procedure
	rc_setActorLinearVelocityLocal( SETACTORLINEARVELOCITYLOCAL_ACTOR,  SETACTORLINEARVELOCITYLOCAL_X,  SETACTORLINEARVELOCITYLOCAL_Y,  SETACTORLINEARVELOCITYLOCAL_Z );
	break;
case FN_setActorLinearVelocityWorld: //Sub Procedure
	rc_setActorLinearVelocityWorld( SETACTORLINEARVELOCITYWORLD_ACTOR,  SETACTORLINEARVELOCITYWORLD_X,  SETACTORLINEARVELOCITYWORLD_Y,  SETACTORLINEARVELOCITYWORLD_Z );
	break;
case FN_setActorAngularVelocityLocal: //Sub Procedure
	rc_setActorAngularVelocityLocal( SETACTORANGULARVELOCITYLOCAL_ACTOR,  SETACTORANGULARVELOCITYLOCAL_X,  SETACTORANGULARVELOCITYLOCAL_Y,  SETACTORANGULARVELOCITYLOCAL_Z );
	break;
case FN_setActorAngularVelocityWorld: //Sub Procedure
	rc_setActorAngularVelocityWorld( SETACTORANGULARVELOCITYWORLD_ACTOR,  SETACTORANGULARVELOCITYWORLD_X,  SETACTORANGULARVELOCITYWORLD_Y,  SETACTORANGULARVELOCITYWORLD_Z );
	break;
case FN_getActorVelocityInLocalPoint: //Sub Procedure
	rc_getActorVelocityInLocalPoint( GETACTORVELOCITYINLOCALPOINT_ACTOR,  GETACTORVELOCITYINLOCALPOINT_REL_X,  GETACTORVELOCITYINLOCALPOINT_REL_Y,  GETACTORVELOCITYINLOCALPOINT_REL_Z,  &GETACTORVELOCITYINLOCALPOINT_X,  &GETACTORVELOCITYINLOCALPOINT_Y,  &GETACTORVELOCITYINLOCALPOINT_Z );
	break;
case FN_getActorLinearVelocityLocal: //Sub Procedure
	rc_getActorLinearVelocityLocal( GETACTORLINEARVELOCITYLOCAL_ACTOR,  &GETACTORLINEARVELOCITYLOCAL_X,  &GETACTORLINEARVELOCITYLOCAL_Y,  &GETACTORLINEARVELOCITYLOCAL_Z );
	break;
case FN_getActorAngularVelocityLocal: //Sub Procedure
	rc_getActorAngularVelocityLocal( GETACTORANGULARVELOCITYLOCAL_ACTOR,  &GETACTORANGULARVELOCITYLOCAL_X,  &GETACTORANGULARVELOCITYLOCAL_Y,  &GETACTORANGULARVELOCITYLOCAL_Z );
	break;
case FN_getActorAABB: //Sub Procedure
	rc_getActorAABB( GETACTORAABB_ACTOR,  &GETACTORAABB_MIN_X,  &GETACTORAABB_MIN_Y,  &GETACTORAABB_MIN_Z,  &GETACTORAABB_MAX_X,  &GETACTORAABB_MAX_Y,  &GETACTORAABB_MAX_Z );
	break;
case FN_computeActorImpulseDenominator: //Number Function
	 rc_push_num(rc_computeActorImpulseDenominator(  COMPUTEACTORIMPULSEDENOMINATOR_ACTOR,   COMPUTEACTORIMPULSEDENOMINATOR_POS_X,   COMPUTEACTORIMPULSEDENOMINATOR_POS_Y,   COMPUTEACTORIMPULSEDENOMINATOR_POS_Z,   COMPUTEACTORIMPULSEDENOMINATOR_NORMAL_X,   COMPUTEACTORIMPULSEDENOMINATOR_NORMAL_Y,   COMPUTEACTORIMPULSEDENOMINATOR_NORMAL_Z ));
	break;
case FN_computeActorAngularImpulseDenominator: //Number Function
	 rc_push_num(rc_computeActorAngularImpulseDenominator(  COMPUTEACTORANGULARIMPULSEDENOMINATOR_ACTOR,   COMPUTEACTORANGULARIMPULSEDENOMINATOR_X,   COMPUTEACTORANGULARIMPULSEDENOMINATOR_Y,   COMPUTEACTORANGULARIMPULSEDENOMINATOR_Z ));
	break;
case FN_setActorAngularFactor: //Sub Procedure
	rc_setActorAngularFactor( SETACTORANGULARFACTOR_ACTOR,  SETACTORANGULARFACTOR_X,  SETACTORANGULARFACTOR_Y,  SETACTORANGULARFACTOR_Z );
	break;
case FN_getActorAngularFactor: //Sub Procedure
	rc_getActorAngularFactor( GETACTORANGULARFACTOR_ACTOR,  &GETACTORANGULARFACTOR_X,  &GETACTORANGULARFACTOR_Y,  &GETACTORANGULARFACTOR_Z );
	break;
case FN_computeActorGyroImpulseLocal: //Sub Procedure
	rc_computeActorGyroImpulseLocal( COMPUTEACTORGYROIMPULSELOCAL_ACTOR,  COMPUTEACTORGYROIMPULSELOCAL_DT,  &COMPUTEACTORGYROIMPULSELOCAL_X,  &COMPUTEACTORGYROIMPULSELOCAL_Y,  &COMPUTEACTORGYROIMPULSELOCAL_Z );
	break;
case FN_computeActorGyroImpulseWorld: //Sub Procedure
	rc_computeActorGyroImpulseWorld( COMPUTEACTORGYROIMPULSEWORLD_ACTOR,  COMPUTEACTORGYROIMPULSEWORLD_DT,  &COMPUTEACTORGYROIMPULSEWORLD_X,  &COMPUTEACTORGYROIMPULSEWORLD_Y,  &COMPUTEACTORGYROIMPULSEWORLD_Z );
	break;
case FN_getActorLocalInertia: //Sub Procedure
	rc_getActorLocalInertia( GETACTORLOCALINERTIA_ACTOR,  &GETACTORLOCALINERTIA_X,  &GETACTORLOCALINERTIA_Y,  &GETACTORLOCALINERTIA_Z );
	break;
case FN_SetActorSleepState: //Sub Procedure
	rc_setActorSleepState( SETACTORSLEEPSTATE_ACTOR,  SETACTORSLEEPSTATE_STATE );
	break;
case FN_CastRay3D: //Number Function
	 rc_push_num(rc_castRay3D( CASTRAY3D_FROM_X,  CASTRAY3D_FROM_Y,  CASTRAY3D_FROM_Z,  CASTRAY3D_TO_X,  CASTRAY3D_TO_Y,  CASTRAY3D_TO_Z ));
	break;
case FN_CastRay3D_All: //Number Function
	 rc_push_num(rc_castRay3D_All( CASTRAY3D_ALL_FROM_X,  CASTRAY3D_ALL_FROM_Y,  CASTRAY3D_ALL_FROM_Z,  CASTRAY3D_ALL_TO_X,  CASTRAY3D_ALL_TO_Y,  CASTRAY3D_ALL_TO_Z ));
	break;
case FN_GetRayHit3D: //Sub Procedure
	rc_getRayHit3D( GETRAYHIT3D_INDEX,  &GETRAYHIT3D_ACTOR_ID,  &GETRAYHIT3D_X,  &GETRAYHIT3D_Y,  &GETRAYHIT3D_Z,  &GETRAYHIT3D_NORMAL_X,  &GETRAYHIT3D_NORMAL_Y,  &GETRAYHIT3D_NORMAL_Z );
	break;
case FN_createPointConstraint: //Number Function
	 rc_push_num(rc_createPointConstraint(  CREATEPOINTCONSTRAINT_ACTORA,   CREATEPOINTCONSTRAINT_PXA,   CREATEPOINTCONSTRAINT_PYA,   CREATEPOINTCONSTRAINT_PZA ));
	break;
case FN_createPointConstraintEx: //Number Function
	 rc_push_num(rc_createPointConstraintEx(  CREATEPOINTCONSTRAINTEX_ACTORA,   CREATEPOINTCONSTRAINTEX_ACTORB,   CREATEPOINTCONSTRAINTEX_PXA,   CREATEPOINTCONSTRAINTEX_PYA,   CREATEPOINTCONSTRAINTEX_PZA,   CREATEPOINTCONSTRAINTEX_PXB,   CREATEPOINTCONSTRAINTEX_PYB,   CREATEPOINTCONSTRAINTEX_PZB ));
	break;
case FN_setPointPivotA: //Sub Procedure
	rc_setPointPivotA(  SETPOINTPIVOTA_CONSTRAINT_ID,   SETPOINTPIVOTA_X,   SETPOINTPIVOTA_Y,   SETPOINTPIVOTA_Z );
	break;
case FN_setPointPivotB: //Sub Procedure
	rc_setPointPivotB(  SETPOINTPIVOTB_CONSTRAINT_ID,   SETPOINTPIVOTB_X,   SETPOINTPIVOTB_Y,   SETPOINTPIVOTB_Z );
	break;
case FN_createHingeConstraint: //Number Function
	 rc_push_num(rc_createHingeConstraint(  CREATEHINGECONSTRAINT_ACTORA,   CREATEHINGECONSTRAINT_FRAMEA,   CREATEHINGECONSTRAINT_USEREFERENCEFRAMEA ));
	break;
case FN_createHingeConstraintEx: //Number Function
	 rc_push_num(rc_createHingeConstraintEx(  CREATEHINGECONSTRAINTEX_ACTORA,   CREATEHINGECONSTRAINTEX_ACTORB,   CREATEHINGECONSTRAINTEX_FRAMEA,   CREATEHINGECONSTRAINTEX_FRAMEB,   CREATEHINGECONSTRAINTEX_USEREFERENCEFRAMEA ));
	break;
case FN_createSlideConstraint: //Number Function
	 rc_push_num(rc_createSlideConstraint(  CREATESLIDECONSTRAINT_ACTORA,   CREATESLIDECONSTRAINT_FRAMEINB_MATRIX,   CREATESLIDECONSTRAINT_USELINEARREFERENCEFRAMEA ));
	break;
case FN_createSlideConstraintEx: //Number Function
	 rc_push_num(rc_createSlideConstraintEx(  CREATESLIDECONSTRAINTEX_ACTORA,   CREATESLIDECONSTRAINTEX_ACTORB,   CREATESLIDECONSTRAINTEX_FRAMEINA_MATRIX,   CREATESLIDECONSTRAINTEX_FRAMEINB_MATRIX,   CREATESLIDECONSTRAINTEX_USELINEARREFERENCEFRAMEA ));
	break;
case FN_createConeConstraint: //Number Function
	 rc_push_num(rc_createConeConstraint(  CREATECONECONSTRAINT_ACTORA,   CREATECONECONSTRAINT_RBAFRAME_MATRIX ));
	break;
case FN_createConeConstraintEx: //Number Function
	 rc_push_num(rc_createConeConstraintEx(  CREATECONECONSTRAINTEX_ACTORA,   CREATECONECONSTRAINTEX_ACTORB,   CREATECONECONSTRAINTEX_RBAFRAME_MATRIX,   CREATECONECONSTRAINTEX_RBBFRAME_MATRIX ));
	break;
case FN_deleteConstraint: //Sub Procedure
	rc_deleteConstraint(  DELETECONSTRAINT_CONSTRAINT_ID );
	break;
case FN_getConstraintFrameOffsetA: //Sub Procedure
	rc_getConstraintFrameOffsetA(  GETCONSTRAINTFRAMEOFFSETA_CONSTRAINT_ID,  & GETCONSTRAINTFRAMEOFFSETA_X,  & GETCONSTRAINTFRAMEOFFSETA_Y,  & GETCONSTRAINTFRAMEOFFSETA_Z,  & GETCONSTRAINTFRAMEOFFSETA_RX,  & GETCONSTRAINTFRAMEOFFSETA_RY,  & GETCONSTRAINTFRAMEOFFSETA_RZ );
	break;
case FN_getConstraintFrameOffsetB: //Sub Procedure
	rc_getConstraintFrameOffsetB(  GETCONSTRAINTFRAMEOFFSETB_CONSTRAINT_ID,  & GETCONSTRAINTFRAMEOFFSETB_X,  & GETCONSTRAINTFRAMEOFFSETB_Y,  & GETCONSTRAINTFRAMEOFFSETB_Z,  & GETCONSTRAINTFRAMEOFFSETB_RX,  & GETCONSTRAINTFRAMEOFFSETB_RY,  & GETCONSTRAINTFRAMEOFFSETB_RZ );
	break;
case FN_useConstraintFrameOffset: //Sub Procedure
	rc_useConstraintFrameOffset(  USECONSTRAINTFRAMEOFFSET_CONSTRAINT_ID,   USECONSTRAINTFRAMEOFFSET_FLAG );
	break;
case FN_getHingeAngle: //Number Function
	 rc_push_num(rc_getHingeAngle(  GETHINGEANGLE_CONSTRAINT_ID ));
	break;
case FN_getHingeAngleEx: //Number Function
	 rc_push_num(rc_getHingeAngleEx(  GETHINGEANGLEEX_CONSTRAINT_ID,   GETHINGEANGLEEX_T_MATRIXA,   GETHINGEANGLEEX_T_MATRIXB ));
	break;
case FN_getConstraintBreakingImpulseThreshold: //Number Function
	 rc_push_num(rc_getConstraintBreakingImpulseThreshold(  GETCONSTRAINTBREAKINGIMPULSETHRESHOLD_CONSTRAINT_ID ));
	break;
case FN_getConstraintAFrame: //Number Function
	 rc_push_num(rc_getConstraintAFrame(  GETCONSTRAINTAFRAME_CONSTRAINT_ID,   GETCONSTRAINTAFRAME_MA ));
	break;
case FN_getConstraintBFrame: //Number Function
	 rc_push_num(rc_getConstraintBFrame(  GETCONSTRAINTBFRAME_CONSTRAINT_ID,   GETCONSTRAINTBFRAME_MA ));
	break;
case FN_setHingeAxis: //Sub Procedure
	rc_setHingeAxis(  SETHINGEAXIS_CONSTRAINT_ID,   SETHINGEAXIS_X,   SETHINGEAXIS_Y,   SETHINGEAXIS_Z );
	break;
case FN_setConstraintBreakingImpulseThreshold: //Sub Procedure
	rc_setConstraintBreakingImpulseThreshold(  SETCONSTRAINTBREAKINGIMPULSETHRESHOLD_CONSTRAINT_ID,   SETCONSTRAINTBREAKINGIMPULSETHRESHOLD_THRESHOLD );
	break;
case FN_setConstraintFrames: //Sub Procedure
	rc_setConstraintFrames(  SETCONSTRAINTFRAMES_CONSTRAINT_ID,   SETCONSTRAINTFRAMES_FRAMEA_MATRIX,   SETCONSTRAINTFRAMES_FRAMEB_MATRIX );
	break;
case FN_setHingeLimit: //Sub Procedure
	rc_setHingeLimit(  SETHINGELIMIT_CONSTRAINT_ID,   SETHINGELIMIT_LOW,   SETHINGELIMIT_HIGH,   SETHINGELIMIT_SOFTNESS,   SETHINGELIMIT_BIAS_FACTOR,   SETHINGELIMIT_RELAXATION_FACTOR );
	break;
case FN_setConeLimit: //Sub Procedure
	rc_setConeLimit(  SETCONELIMIT_CONSTRAINT_ID,   SETCONELIMIT_SWINGSPAN1,   SETCONELIMIT_SWINGSPAN2,   SETCONELIMIT_TWISTSPAN,   SETCONELIMIT_SOFTNESS,   SETCONELIMIT_BIAS_FACTOR,   SETCONELIMIT_RELAXATION_FACTOR );
	break;
case FN_getHingeLimitBiasFactor: //Number Function
	 rc_push_num(rc_getHingeLimitBiasFactor(  GETHINGELIMITBIASFACTOR_CONSTRAINT_ID ));
	break;
case FN_getHingeLimitRelaxationFactor: //Number Function
	 rc_push_num(rc_getHingeLimitRelaxationFactor(  GETHINGELIMITRELAXATIONFACTOR_CONSTRAINT_ID ));
	break;
case FN_getHingeLimitSign: //Number Function
	 rc_push_num(rc_getHingeLimitSign(  GETHINGELIMITSIGN_CONSTRAINT_ID ));
	break;
case FN_getHingeSolveLimit: //Number Function
	 rc_push_num(rc_getHingeSolveLimit(  GETHINGESOLVELIMIT_CONSTRAINT_ID ));
	break;
case FN_useHingeReferenceFrameA: //Sub Procedure
	rc_useHingeReferenceFrameA(  USEHINGEREFERENCEFRAMEA_CONSTRAINT_ID,   USEHINGEREFERENCEFRAMEA_FLAG );
	break;
case FN_getConstraintAppliedImpulse: //Number Function
	 rc_push_num(rc_getConstraintAppliedImpulse(  GETCONSTRAINTAPPLIEDIMPULSE_CONSTRAINT_ID ));
	break;
case FN_getConstraintFixedActor: //Number Function
	 rc_push_num(rc_getConstraintFixedActor(  GETCONSTRAINTFIXEDACTOR_CONSTRAINT_ID ));
	break;
case FN_getPointPivotA: //Sub Procedure
	rc_getPointPivotA(  GETPOINTPIVOTA_CONSTRAINT_ID,  & GETPOINTPIVOTA_X,  & GETPOINTPIVOTA_Y,  & GETPOINTPIVOTA_Z );
	break;
case FN_getPointPivotB: //Sub Procedure
	rc_getPointPivotB(  GETPOINTPIVOTB_CONSTRAINT_ID,  & GETPOINTPIVOTB_X,  & GETPOINTPIVOTB_Y,  & GETPOINTPIVOTB_Z );
	break;
case FN_getConstraintActorA: //Number Function
	 rc_push_num(rc_getConstraintActorA(  GETCONSTRAINTACTORA_CONSTRAINT_ID ));
	break;
case FN_getConstraintActorB: //Number Function
	 rc_push_num(rc_getConstraintActorB(  GETCONSTRAINTACTORB_CONSTRAINT_ID ));
	break;
case FN_setConstraintSolverIterations: //Sub Procedure
	rc_setConstraintSolverIterations(  SETCONSTRAINTSOLVERITERATIONS_CONSTRAINT_ID,   SETCONSTRAINTSOLVERITERATIONS_NUM );
	break;
case FN_getConeBiasFactor: //Number Function
	 rc_push_num(rc_getConeBiasFactor(  GETCONEBIASFACTOR_CONSTRAINT_ID ));
	break;
case FN_getConeDamping: //Number Function
	 rc_push_num(rc_getConeDamping(  GETCONEDAMPING_CONSTRAINT_ID ));
	break;
case FN_getConeFixThresh: //Number Function
	 rc_push_num(rc_getConeFixThresh(  GETCONEFIXTHRESH_CONSTRAINT_ID ));
	break;
case FN_getConeLimit: //Number Function
	 rc_push_num(rc_getConeLimit(  GETCONELIMIT_CONSTRAINT_ID,   GETCONELIMIT_LIMIT_INDEX ));
	break;
case FN_getConstraintLimitSoftness: //Number Function
	 rc_push_num(rc_getConstraintLimitSoftness(  GETCONSTRAINTLIMITSOFTNESS_CONSTRAINT_ID ));
	break;
case FN_getConstraintSolverIterations: //Number Function
	 rc_push_num(rc_getConstraintSolverIterations(  GETCONSTRAINTSOLVERITERATIONS_CONSTRAINT_ID ));
	break;
case FN_getConeAnglePoint: //Sub Procedure
	rc_getConeAnglePoint(  GETCONEANGLEPOINT_CONSTRAINT_ID,   GETCONEANGLEPOINT_ANGLE,   GETCONEANGLEPOINT_C_LEN,  & GETCONEANGLEPOINT_X,  & GETCONEANGLEPOINT_Y,  & GETCONEANGLEPOINT_Z );
	break;
case FN_getConstraintAngularOnly: //Number Function
	 rc_push_num(rc_getConstraintAngularOnly(  GETCONSTRAINTANGULARONLY_CONSTRAINT_ID ));
	break;
case FN_getConeSolveSwingLimit: //Number Function
	 rc_push_num(rc_getConeSolveSwingLimit(  GETCONESOLVESWINGLIMIT_CONSTRAINT_ID ));
	break;
case FN_getConeSolveTwistLimit: //Number Function
	 rc_push_num(rc_getConeSolveTwistLimit(  GETCONESOLVETWISTLIMIT_CONSTRAINT_ID ));
	break;
case FN_getConeSwingSpan1: //Number Function
	 rc_push_num(rc_getConeSwingSpan1(  GETCONESWINGSPAN1_CONSTRAINT_ID ));
	break;
case FN_getConeSwingSpan2: //Number Function
	 rc_push_num(rc_getConeSwingSpan2(  GETCONESWINGSPAN2_CONSTRAINT_ID ));
	break;
case FN_getConeTwistAngle: //Number Function
	 rc_push_num(rc_getConeTwistAngle(  GETCONETWISTANGLE_CONSTRAINT_ID ));
	break;
case FN_getConeTwistLimitSign: //Number Function
	 rc_push_num(rc_getConeTwistLimitSign(  GETCONETWISTLIMITSIGN_CONSTRAINT_ID ));
	break;
case FN_getConeTwistSpan: //Number Function
	 rc_push_num(rc_getConeTwistSpan(  GETCONETWISTSPAN_CONSTRAINT_ID ));
	break;
case FN_setConstraintAngularOnly: //Sub Procedure
	rc_setConstraintAngularOnly(  SETCONSTRAINTANGULARONLY_CONSTRAINT_ID,   SETCONSTRAINTANGULARONLY_FLAG );
	break;
case FN_setConeDamping: //Sub Procedure
	rc_setConeDamping(  SETCONEDAMPING_CONSTRAINT_ID,   SETCONEDAMPING_DAMPING );
	break;
case FN_setConeFixThresh: //Sub Procedure
	rc_setConeFixThresh(  SETCONEFIXTHRESH_CONSTRAINT_ID,   SETCONEFIXTHRESH_FIXTHRESH );
	break;
case FN_getSlideAnchorA: //Sub Procedure
	rc_getSlideAnchorA(  GETSLIDEANCHORA_CONSTRAINT_ID,  & GETSLIDEANCHORA_X,  & GETSLIDEANCHORA_Y,  & GETSLIDEANCHORA_Z );
	break;
case FN_getSlideAnchorB: //Sub Procedure
	rc_getSlideAnchorB(  GETSLIDEANCHORB_CONSTRAINT_ID,  & GETSLIDEANCHORB_X,  & GETSLIDEANCHORB_Y,  & GETSLIDEANCHORB_Z );
	break;
case FN_getSlideAngDepth: //Number Function
	 rc_push_num(rc_getSlideAngDepth(  GETSLIDEANGDEPTH_CONSTRAINT_ID ));
	break;
case FN_getSlideAngularPos: //Number Function
	 rc_push_num(rc_getSlideAngularPos(  GETSLIDEANGULARPOS_CONSTRAINT_ID ));
	break;
case FN_getSlideDampingDirAng: //Number Function
	 rc_push_num(rc_getSlideDampingDirAng(  GETSLIDEDAMPINGDIRANG_CONSTRAINT_ID ));
	break;
case FN_getSlideDampingDirLin: //Number Function
	 rc_push_num(rc_getSlideDampingDirLin(  GETSLIDEDAMPINGDIRLIN_CONSTRAINT_ID ));
	break;
case FN_getSlideDampingLimAng: //Number Function
	 rc_push_num(rc_getSlideDampingLimAng(  GETSLIDEDAMPINGLIMANG_CONSTRAINT_ID ));
	break;
case FN_getSlideDampingLimLin: //Number Function
	 rc_push_num(rc_getSlideDampingLimLin(  GETSLIDEDAMPINGLIMLIN_CONSTRAINT_ID ));
	break;
case FN_getSlideDampingOrthoAng: //Number Function
	 rc_push_num(rc_getSlideDampingOrthoAng(  GETSLIDEDAMPINGORTHOANG_CONSTRAINT_ID ));
	break;
case FN_getSlideDampingOrthoLin: //Number Function
	 rc_push_num(rc_getSlideDampingOrthoLin(  GETSLIDEDAMPINGORTHOLIN_CONSTRAINT_ID ));
	break;
case FN_getSlideLinearPos: //Number Function
	 rc_push_num(rc_getSlideLinearPos(  GETSLIDELINEARPOS_CONSTRAINT_ID ));
	break;
case FN_getSlideLinDepth: //Number Function
	 rc_push_num(rc_getSlideLinDepth(  GETSLIDELINDEPTH_CONSTRAINT_ID ));
	break;
case FN_getSlideLowerAngLimit: //Number Function
	 rc_push_num(rc_getSlideLowerAngLimit(  GETSLIDELOWERANGLIMIT_CONSTRAINT_ID ));
	break;
case FN_getSlideLowerLinLimit: //Number Function
	 rc_push_num(rc_getSlideLowerLinLimit(  GETSLIDELOWERLINLIMIT_CONSTRAINT_ID ));
	break;
case FN_getSlideRestitutionDirAng: //Number Function
	 rc_push_num(rc_getSlideRestitutionDirAng(  GETSLIDERESTITUTIONDIRANG_CONSTRAINT_ID ));
	break;
case FN_getSlideRestitutionDirLin: //Number Function
	 rc_push_num(rc_getSlideRestitutionDirLin(  GETSLIDERESTITUTIONDIRLIN_CONSTRAINT_ID ));
	break;
case FN_getSlideRestitutionLimAng: //Number Function
	 rc_push_num(rc_getSlideRestitutionLimAng(  GETSLIDERESTITUTIONLIMANG_CONSTRAINT_ID ));
	break;
case FN_getSlideRestitutionLimLin: //Number Function
	 rc_push_num(rc_getSlideRestitutionLimLin(  GETSLIDERESTITUTIONLIMLIN_CONSTRAINT_ID ));
	break;
case FN_getSlideRestitutionOrthoAng: //Number Function
	 rc_push_num(rc_getSlideRestitutionOrthoAng(  GETSLIDERESTITUTIONORTHOANG_CONSTRAINT_ID ));
	break;
case FN_getSlideRestitutionOrthoLin: //Number Function
	 rc_push_num(rc_getSlideRestitutionOrthoLin(  GETSLIDERESTITUTIONORTHOLIN_CONSTRAINT_ID ));
	break;
case FN_getSlideSoftnessDirAng: //Number Function
	 rc_push_num(rc_getSlideSoftnessDirAng(  GETSLIDESOFTNESSDIRANG_CONSTRAINT_ID ));
	break;
case FN_getSlideSoftnessDirLin: //Number Function
	 rc_push_num(rc_getSlideSoftnessDirLin(  GETSLIDESOFTNESSDIRLIN_CONSTRAINT_ID ));
	break;
case FN_getSlideSoftnessLimAng: //Number Function
	 rc_push_num(rc_getSlideSoftnessLimAng(  GETSLIDESOFTNESSLIMANG_CONSTRAINT_ID ));
	break;
case FN_getSlideSoftnessLimLin: //Number Function
	 rc_push_num(rc_getSlideSoftnessLimLin(  GETSLIDESOFTNESSLIMLIN_CONSTRAINT_ID ));
	break;
case FN_getSlideSoftnessOrthoAng: //Number Function
	 rc_push_num(rc_getSlideSoftnessOrthoAng(  GETSLIDESOFTNESSORTHOANG_CONSTRAINT_ID ));
	break;
case FN_getSlideSoftnessOrthoLin: //Number Function
	 rc_push_num(rc_getSlideSoftnessOrthoLin(  GETSLIDESOFTNESSORTHOLIN_CONSTRAINT_ID ));
	break;
case FN_getSlideSolveAngLimit: //Number Function
	 rc_push_num(rc_getSlideSolveAngLimit(  GETSLIDESOLVEANGLIMIT_CONSTRAINT_ID ));
	break;
case FN_getSlideSolveLinLimit: //Number Function
	 rc_push_num(rc_getSlideSolveLinLimit(  GETSLIDESOLVELINLIMIT_CONSTRAINT_ID ));
	break;
case FN_getSlideUpperAngLimit: //Number Function
	 rc_push_num(rc_getSlideUpperAngLimit(  GETSLIDEUPPERANGLIMIT_CONSTRAINT_ID ));
	break;
case FN_getSlideUpperLinLimit: //Number Function
	 rc_push_num(rc_getSlideUpperLinLimit(  GETSLIDEUPPERLINLIMIT_CONSTRAINT_ID ));
	break;
case FN_getSlideUseFrameOffset: //Number Function
	 rc_push_num(rc_getSlideUseFrameOffset(  GETSLIDEUSEFRAMEOFFSET_CONSTRAINT_ID ));
	break;
case FN_setSlideDampingDirAng: //Sub Procedure
	rc_setSlideDampingDirAng(  SETSLIDEDAMPINGDIRANG_CONSTRAINT_ID,   SETSLIDEDAMPINGDIRANG_N );
	break;
case FN_setSlideDampingDirLin: //Sub Procedure
	rc_setSlideDampingDirLin(  SETSLIDEDAMPINGDIRLIN_CONSTRAINT_ID,   SETSLIDEDAMPINGDIRLIN_N );
	break;
case FN_setSlideDampingLimAng: //Sub Procedure
	rc_setSlideDampingLimAng(  SETSLIDEDAMPINGLIMANG_CONSTRAINT_ID,   SETSLIDEDAMPINGLIMANG_N );
	break;
case FN_setSlideDampingLimLin: //Sub Procedure
	rc_setSlideDampingLimLin(  SETSLIDEDAMPINGLIMLIN_CONSTRAINT_ID,   SETSLIDEDAMPINGLIMLIN_N );
	break;
case FN_setSlideDampingOrthoAng: //Sub Procedure
	rc_setSlideDampingOrthoAng(  SETSLIDEDAMPINGORTHOANG_CONSTRAINT_ID,   SETSLIDEDAMPINGORTHOANG_N );
	break;
case FN_setSlideDampingOrthoLin: //Sub Procedure
	rc_setSlideDampingOrthoLin(  SETSLIDEDAMPINGORTHOLIN_CONSTRAINT_ID,   SETSLIDEDAMPINGORTHOLIN_N );
	break;
case FN_setSlideLowerAngLimit: //Sub Procedure
	rc_setSlideLowerAngLimit(  SETSLIDELOWERANGLIMIT_CONSTRAINT_ID,   SETSLIDELOWERANGLIMIT_N );
	break;
case FN_setSlideLowerLinLimit: //Sub Procedure
	rc_setSlideLowerLinLimit(  SETSLIDELOWERLINLIMIT_CONSTRAINT_ID,   SETSLIDELOWERLINLIMIT_N );
	break;
case FN_setSlideRestitutionDirAng: //Sub Procedure
	rc_setSlideRestitutionDirAng(  SETSLIDERESTITUTIONDIRANG_CONSTRAINT_ID,   SETSLIDERESTITUTIONDIRANG_N );
	break;
case FN_setSlideRestitutionDirLin: //Sub Procedure
	rc_setSlideRestitutionDirLin(  SETSLIDERESTITUTIONDIRLIN_CONSTRAINT_ID,   SETSLIDERESTITUTIONDIRLIN_N );
	break;
case FN_setSlideRestitutionLimAng: //Sub Procedure
	rc_setSlideRestitutionLimAng(  SETSLIDERESTITUTIONLIMANG_CONSTRAINT_ID,   SETSLIDERESTITUTIONLIMANG_N );
	break;
case FN_setSlideRestitutionLimLin: //Sub Procedure
	rc_setSlideRestitutionLimLin(  SETSLIDERESTITUTIONLIMLIN_CONSTRAINT_ID,   SETSLIDERESTITUTIONLIMLIN_N );
	break;
case FN_setSlideRestitutionOrthoAng: //Sub Procedure
	rc_setSlideRestitutionOrthoAng(  SETSLIDERESTITUTIONORTHOANG_CONSTRAINT_ID,   SETSLIDERESTITUTIONORTHOANG_N );
	break;
case FN_setSlideRestitutionOrthoLin: //Sub Procedure
	rc_setSlideRestitutionOrthoLin(  SETSLIDERESTITUTIONORTHOLIN_CONSTRAINT_ID,   SETSLIDERESTITUTIONORTHOLIN_N );
	break;
case FN_setSlideSoftnessDirAng: //Sub Procedure
	rc_setSlideSoftnessDirAng(  SETSLIDESOFTNESSDIRANG_CONSTRAINT_ID,   SETSLIDESOFTNESSDIRANG_N );
	break;
case FN_setSlideSoftnessDirLin: //Sub Procedure
	rc_setSlideSoftnessDirLin(  SETSLIDESOFTNESSDIRLIN_CONSTRAINT_ID,   SETSLIDESOFTNESSDIRLIN_N );
	break;
case FN_setSlideSoftnessLimAng: //Sub Procedure
	rc_setSlideSoftnessLimAng(  SETSLIDESOFTNESSLIMANG_CONSTRAINT_ID,   SETSLIDESOFTNESSLIMANG_N );
	break;
case FN_setSlideSoftnessLimLin: //Sub Procedure
	rc_setSlideSoftnessLimLin(  SETSLIDESOFTNESSLIMLIN_CONSTRAINT_ID,   SETSLIDESOFTNESSLIMLIN_N );
	break;
case FN_setSlideSoftnessOrthoAng: //Sub Procedure
	rc_setSlideSoftnessOrthoAng(  SETSLIDESOFTNESSORTHOANG_CONSTRAINT_ID,   SETSLIDESOFTNESSORTHOANG_N );
	break;
case FN_setSlideSoftnessOrthoLin: //Sub Procedure
	rc_setSlideSoftnessOrthoLin(  SETSLIDESOFTNESSORTHOLIN_CONSTRAINT_ID,   SETSLIDESOFTNESSORTHOLIN_N );
	break;
case FN_setSlideUpperAngLimit: //Sub Procedure
	rc_setSlideUpperAngLimit(  SETSLIDEUPPERANGLIMIT_CONSTRAINT_ID,   SETSLIDEUPPERANGLIMIT_N );
	break;
case FN_setSlideUpperLinLimit: //Sub Procedure
	rc_setSlideUpperLinLimit(  SETSLIDEUPPERLINLIMIT_CONSTRAINT_ID,   SETSLIDEUPPERLINLIMIT_N );
	break;
case FN_ConstraintExists: //Number Function
	 rc_push_num(rc_constraintExists( CONSTRAINTEXISTS_CONSTRAINT_ID ));
	break;
case FN_SetCameraPosition: //Sub Procedure
	rc_setCameraPosition( SETCAMERAPOSITION_X,  SETCAMERAPOSITION_Y,  SETCAMERAPOSITION_Z );
	break;
case FN_GetCameraPosition: //Sub Procedure
	rc_getCameraPosition( &GETCAMERAPOSITION_X,  &GETCAMERAPOSITION_Y,  &GETCAMERAPOSITION_Z );
	break;
case FN_TranslateCamera: //Sub Procedure
	rc_translateCamera( TRANSLATECAMERA_X,  TRANSLATECAMERA_Y,  TRANSLATECAMERA_Z );
	break;
case FN_SetCameraRotation: //Sub Procedure
	rc_setCameraRotation( SETCAMERAROTATION_X,  SETCAMERAROTATION_Y,  SETCAMERAROTATION_Z );
	break;
case FN_GetCameraRotation: //Sub Procedure
	rc_getCameraRotation( &GETCAMERAROTATION_X,  &GETCAMERAROTATION_Y,  &GETCAMERAROTATION_Z );
	break;
case FN_RotateCamera: //Sub Procedure
	rc_rotateCamera( ROTATECAMERA_X,  ROTATECAMERA_Y,  ROTATECAMERA_Z );
	break;
case FN_SetCameraFOV: //Sub Procedure
	rc_setCameraFOV( SETCAMERAFOV_FOV );
	break;
case FN_GetCameraFOV: //Number Function
	 rc_push_num(rc_getCameraFOV(  ));
	break;
case FN_SetCameraAspectRatio: //Sub Procedure
	rc_setCameraAspectRatio( SETCAMERAASPECTRATIO_ASPECT );
	break;
case FN_GetCameraAspectRatio: //Number Function
	 rc_push_num(rc_getCameraAspectRatio(  ));
	break;
case FN_SetCameraFarValue: //Sub Procedure
	rc_setCameraFarValue( SETCAMERAFARVALUE_ZF );
	break;
case FN_GetCameraFarValue: //Number Function
	 rc_push_num(rc_getCameraFarValue(  ));
	break;
case FN_SetCameraNearValue: //Sub Procedure
	rc_setCameraNearValue( SETCAMERANEARVALUE_ZN );
	break;
case FN_GetCameraNearValue: //Number Function
	 rc_push_num(rc_getCameraNearValue(  ));
	break;
case FN_SetProjectionMatrix: //Sub Procedure
	rc_setProjectionMatrix( SETPROJECTIONMATRIX_MATA,  SETPROJECTIONMATRIX_PROJECTION_TYPE );
	break;
case FN_GetProjectionMatrix: //Sub Procedure
	rc_getProjectionMatrix( GETPROJECTIONMATRIX_MATA );
	break;
case FN_GetWorldToViewportPosition: //Sub Procedure
	rc_getWorldToViewportPosition( GETWORLDTOVIEWPORTPOSITION_X,  GETWORLDTOVIEWPORTPOSITION_Y,  GETWORLDTOVIEWPORTPOSITION_Z,  &GETWORLDTOVIEWPORTPOSITION_VX,  &GETWORLDTOVIEWPORTPOSITION_VY );
	break;
case FN_AddSceneSkyBox: //Sub Procedure
	rc_addSceneSkyBox( ADDSCENESKYBOX_IMG_TOP,  ADDSCENESKYBOX_IMG_BOTTOM,  ADDSCENESKYBOX_IMG_LEFT,  ADDSCENESKYBOX_IMG_RIGHT,  ADDSCENESKYBOX_IMG_FRONT,  ADDSCENESKYBOX_IMG_BACK );
	break;
case FN_AddSceneSkyDome: //Sub Procedure
	rc_addSceneSkyDome( ADDSCENESKYDOME_IMG );
	break;
case FN_AddSceneSkyDomeEx: //Sub Procedure
	rc_addSceneSkyDomeEx( ADDSCENESKYDOMEEX_IMG,  ADDSCENESKYDOMEEX_HORIRES,  ADDSCENESKYDOMEEX_VERTRES,  ADDSCENESKYDOMEEX_TXPERCENTAGE,  ADDSCENESKYDOMEEX_SPHEREPERCENTAGE,  ADDSCENESKYDOMEEX_RADIUS );
	break;
case FN_RemoveSceneSky: //Sub Procedure
	rc_removeSceneSky(  );
	break;
case FN_SetWorld3DMaxSubSteps: //Sub Procedure
	rc_setWorld3DMaxSubSteps( SETWORLD3DMAXSUBSTEPS_STEPS );
	break;
case FN_SetWorld3DTimeStep: //Sub Procedure
	rc_setWorld3DTimeStep( SETWORLD3DTIMESTEP_TS );
	break;
case FN_GetWorld3DMaxSubSteps: //Number Function
	 rc_push_num(rc_getWorld3DMaxSubSteps(  ));
	break;
case FN_GetWorld3DTimeStep: //Number Function
	 rc_push_num(rc_getWorld3DTimeStep(  ));
	break;
case FN_SetSceneFog: //Sub Procedure
	rc_setSceneFog( SETSCENEFOG_COLOR,  SETSCENEFOG_FOG_TYPE,  SETSCENEFOG_START_VAL,  SETSCENEFOG_END_VAL,  SETSCENEFOG_DENSITY,  SETSCENEFOG_PIXELFOG,  SETSCENEFOG_RANGEFOG );
	break;
case FN_GetSceneFog: //Sub Procedure
	rc_getSceneFog( &GETSCENEFOG_COLOR,  &GETSCENEFOG_FOG_TYPE,  &GETSCENEFOG_START_VAL,  &GETSCENEFOG_END_VAL,  &GETSCENEFOG_DENSITY,  &GETSCENEFOG_PIXELFOG,  &GETSCENEFOG_RANGEFOG );
	break;
case FN_ClearScene: //Sub Procedure
	rc_clearScene(  );
	break;
case FN_startParticleEmitter: //Sub Procedure
	rc_startParticleEmitter(  STARTPARTICLEEMITTER_ACTOR );
	break;
case FN_stopParticleEmitter: //Sub Procedure
	rc_stopParticleEmitter(  STOPPARTICLEEMITTER_ACTOR );
	break;
case FN_setParticleDirection: //Sub Procedure
	rc_setParticleDirection(  SETPARTICLEDIRECTION_ACTOR,   SETPARTICLEDIRECTION_X,   SETPARTICLEDIRECTION_Y,   SETPARTICLEDIRECTION_Z );
	break;
case FN_getParticleDirection: //Sub Procedure
	rc_getParticleDirection(  GETPARTICLEDIRECTION_ACTOR,  & GETPARTICLEDIRECTION_X,  & GETPARTICLEDIRECTION_Y,  & GETPARTICLEDIRECTION_Z );
	break;
case FN_useParticleEveryMeshVertex: //Sub Procedure
	rc_useParticleEveryMeshVertex(  USEPARTICLEEVERYMESHVERTEX_ACTOR,   USEPARTICLEEVERYMESHVERTEX_FLAG );
	break;
case FN_particleIsUsingEveryMeshVertex: //Number Function
	 rc_push_num(rc_particleIsUsingEveryMeshVertex(  PARTICLEISUSINGEVERYMESHVERTEX_ACTOR ));
	break;
case FN_setParticleNormalDirectionMod: //Sub Procedure
	rc_setParticleNormalDirectionMod(  SETPARTICLENORMALDIRECTIONMOD_ACTOR,   SETPARTICLENORMALDIRECTIONMOD_ND_MOD );
	break;
case FN_getParticleNormalDirectionMod: //Number Function
	 rc_push_num(rc_getParticleNormalDirectionMod(  GETPARTICLENORMALDIRECTIONMOD_ACTOR ));
	break;
case FN_useParticleNormalDirection: //Sub Procedure
	rc_useParticleNormalDirection(  USEPARTICLENORMALDIRECTION_ACTOR,   USEPARTICLENORMALDIRECTION_FLAG );
	break;
case FN_particleIsUsingNormalDirection: //Number Function
	 rc_push_num(rc_particleIsUsingNormalDirection(  PARTICLEISUSINGNORMALDIRECTION_ACTOR ));
	break;
case FN_setParticleMesh: //Sub Procedure
	rc_setParticleMesh(  SETPARTICLEMESH_ACTOR,   SETPARTICLEMESH_MESH );
	break;
case FN_setMinParticlesPerSecond: //Sub Procedure
	rc_setMinParticlesPerSecond(  SETMINPARTICLESPERSECOND_ACTOR,   SETMINPARTICLESPERSECOND_MINPARTICLESPERSECOND );
	break;
case FN_getMinParticlesPerSecond: //Number Function
	 rc_push_num(rc_getMinParticlesPerSecond(  GETMINPARTICLESPERSECOND_ACTOR ));
	break;
case FN_setMaxParticlesPerSecond: //Sub Procedure
	rc_setMaxParticlesPerSecond(  SETMAXPARTICLESPERSECOND_ACTOR,   SETMAXPARTICLESPERSECOND_MAXPARTICLESPERSECOND );
	break;
case FN_getMaxParticlesPerSecond: //Number Function
	 rc_push_num(rc_getMaxParticlesPerSecond(  GETMAXPARTICLESPERSECOND_ACTOR ));
	break;
case FN_setParticleMinStartColor: //Sub Procedure
	rc_setParticleMinStartColor(  SETPARTICLEMINSTARTCOLOR_ACTOR,   SETPARTICLEMINSTARTCOLOR_COLOR );
	break;
case FN_getParticleMinStartColor: //Number Function
	 rc_push_num(rc_getParticleMinStartColor(  GETPARTICLEMINSTARTCOLOR_ACTOR ));
	break;
case FN_setParticleMaxStartColor: //Sub Procedure
	rc_setParticleMaxStartColor(  SETPARTICLEMAXSTARTCOLOR_ACTOR,   SETPARTICLEMAXSTARTCOLOR_COLOR );
	break;
case FN_getParticleMaxStartColor: //Number Function
	 rc_push_num(rc_getParticleMaxStartColor(  GETPARTICLEMAXSTARTCOLOR_ACTOR ));
	break;
case FN_setParticleMinLife: //Sub Procedure
	rc_setParticleMinLife(  SETPARTICLEMINLIFE_ACTOR,   SETPARTICLEMINLIFE_MINLIFE );
	break;
case FN_getParticleMinLife: //Number Function
	 rc_push_num(rc_getParticleMinLife(  GETPARTICLEMINLIFE_ACTOR ));
	break;
case FN_setParticleMaxLife: //Sub Procedure
	rc_setParticleMaxLife(  SETPARTICLEMAXLIFE_ACTOR,   SETPARTICLEMAXLIFE_MAXLIFE );
	break;
case FN_getParticleMaxLife: //Number Function
	 rc_push_num(rc_getParticleMaxLife(  GETPARTICLEMAXLIFE_ACTOR ));
	break;
case FN_setParticleMaxAngle: //Sub Procedure
	rc_setParticleMaxAngle(  SETPARTICLEMAXANGLE_ACTOR,   SETPARTICLEMAXANGLE_MAXANGLE );
	break;
case FN_getParticleMaxAngle: //Number Function
	 rc_push_num(rc_getParticleMaxAngle(  GETPARTICLEMAXANGLE_ACTOR ));
	break;
case FN_setParticleMinStartSize: //Sub Procedure
	rc_setParticleMinStartSize(  SETPARTICLEMINSTARTSIZE_ACTOR,   SETPARTICLEMINSTARTSIZE_W,   SETPARTICLEMINSTARTSIZE_H );
	break;
case FN_getParticleMinStartSize: //Sub Procedure
	rc_getParticleMinStartSize(  GETPARTICLEMINSTARTSIZE_ACTOR,  & GETPARTICLEMINSTARTSIZE_W,  & GETPARTICLEMINSTARTSIZE_H );
	break;
case FN_setParticleMaxStartSize: //Sub Procedure
	rc_setParticleMaxStartSize(  SETPARTICLEMAXSTARTSIZE_ACTOR,   SETPARTICLEMAXSTARTSIZE_W,   SETPARTICLEMAXSTARTSIZE_H );
	break;
case FN_getParticleMaxStartSize: //Sub Procedure
	rc_getParticleMaxStartSize(  GETPARTICLEMAXSTARTSIZE_ACTOR,  & GETPARTICLEMAXSTARTSIZE_W,  & GETPARTICLEMAXSTARTSIZE_H );
	break;
case FN_setParticleCenter: //Sub Procedure
	rc_setParticleCenter(  SETPARTICLECENTER_ACTOR,   SETPARTICLECENTER_X,   SETPARTICLECENTER_Y,   SETPARTICLECENTER_Z );
	break;
case FN_getParticleCenter: //Sub Procedure
	rc_getParticleCenter(  GETPARTICLECENTER_ACTOR,  & GETPARTICLECENTER_X,  & GETPARTICLECENTER_Y,  & GETPARTICLECENTER_Z );
	break;
case FN_setParticleRadius: //Sub Procedure
	rc_setParticleRadius(  SETPARTICLERADIUS_ACTOR,   SETPARTICLERADIUS_RADIUS );
	break;
case FN_getParticleRadius: //Number Function
	 rc_push_num(rc_getParticleRadius(  GETPARTICLERADIUS_ACTOR ));
	break;
case FN_setParticleRingThickness: //Sub Procedure
	rc_setParticleRingThickness(  SETPARTICLERINGTHICKNESS_ACTOR,   SETPARTICLERINGTHICKNESS_RINGTHICKNESS );
	break;
case FN_getParticleRingThickness: //Number Function
	 rc_push_num(rc_getParticleRingThickness(  GETPARTICLERINGTHICKNESS_ACTOR ));
	break;
case FN_setParticleBox: //Sub Procedure
	rc_setParticleBox(  SETPARTICLEBOX_ACTOR,   SETPARTICLEBOX_MIN_X,   SETPARTICLEBOX_MIN_Y,   SETPARTICLEBOX_MIN_Z,   SETPARTICLEBOX_MAX_X,   SETPARTICLEBOX_MAX_Y,   SETPARTICLEBOX_MAX_Z );
	break;
case FN_getParticleBox: //Sub Procedure
	rc_getParticleBox(  GETPARTICLEBOX_ACTOR,  & GETPARTICLEBOX_MIN_X,  & GETPARTICLEBOX_MIN_Y,  & GETPARTICLEBOX_MIN_Z,  & GETPARTICLEBOX_MAX_X,  & GETPARTICLEBOX_MAX_Y,  & GETPARTICLEBOX_MAX_Z );
	break;
case FN_setParticleNormal: //Sub Procedure
	rc_setParticleNormal(  SETPARTICLENORMAL_ACTOR,   SETPARTICLENORMAL_X,   SETPARTICLENORMAL_Y,   SETPARTICLENORMAL_Z );
	break;
case FN_getParticleNormal: //Sub Procedure
	rc_getParticleNormal(  GETPARTICLENORMAL_ACTOR,  & GETPARTICLENORMAL_X,  & GETPARTICLENORMAL_Y,  & GETPARTICLENORMAL_Z );
	break;
case FN_setParticleLength: //Sub Procedure
	rc_setParticleLength(  SETPARTICLELENGTH_ACTOR,   SETPARTICLELENGTH_P_LEN );
	break;
case FN_getParticleLength: //Number Function
	 rc_push_num(rc_getParticleLength(  GETPARTICLELENGTH_ACTOR ));
	break;
case FN_useParticleOutlineOnly: //Sub Procedure
	rc_useParticleOutlineOnly(  USEPARTICLEOUTLINEONLY_ACTOR,   USEPARTICLEOUTLINEONLY_FLAG );
	break;
case FN_particleIsUsingOutlineOnly: //Number Function
	 rc_push_num(rc_particleIsUsingOutlineOnly(  PARTICLEISUSINGOUTLINEONLY_ACTOR ));
	break;
case FN_getParticleType: //Number Function
	 rc_push_num(rc_getParticleType(  GETPARTICLETYPE_ACTOR ));
	break;
case FN_lightIsCastingShadow: //Number Function
	 rc_push_num(rc_lightIsCastingShadow( LIGHTISCASTINGSHADOW_ACTOR ));
	break;
case FN_getLightType: //Number Function
	 rc_push_num(rc_getLightType( GETLIGHTTYPE_ACTOR ));
	break;
case FN_getLightRadius: //Number Function
	 rc_push_num(rc_getLightRadius( GETLIGHTRADIUS_ACTOR ));
	break;
case FN_setLightType: //Sub Procedure
	rc_setLightType( SETLIGHTTYPE_ACTOR,  SETLIGHTTYPE_LIGHT_TYPE );
	break;
case FN_setLightRadius: //Sub Procedure
	rc_setLightRadius( SETLIGHTRADIUS_ACTOR,  SETLIGHTRADIUS_RADIUS );
	break;
case FN_setLightShadowCast: //Sub Procedure
	rc_setLightShadowCast( SETLIGHTSHADOWCAST_ACTOR,  SETLIGHTSHADOWCAST_FLAG );
	break;
case FN_SetLightAmbientColor: //Sub Procedure
	rc_setLightAmbientColor( SETLIGHTAMBIENTCOLOR_ACTOR,  SETLIGHTAMBIENTCOLOR_COLOR );
	break;
case FN_GetLightAmbientColor: //Number Function
	 rc_push_num(rc_getLightAmbientColor( GETLIGHTAMBIENTCOLOR_ACTOR ));
	break;
case FN_SetLightAttenuation: //Sub Procedure
	rc_setLightAttenuation( SETLIGHTATTENUATION_ACTOR,  SETLIGHTATTENUATION_L_CONSTANT,  SETLIGHTATTENUATION_L_LINEAR,  SETLIGHTATTENUATION_L_QUADRATIC );
	break;
case FN_GetLightAttenuation: //Sub Procedure
	rc_getLightAttenuation( GETLIGHTATTENUATION_ACTOR,  &GETLIGHTATTENUATION_CONSTANT,  &GETLIGHTATTENUATION_LINEAR,  &GETLIGHTATTENUATION_QUADRATIC );
	break;
case FN_SetLightDiffuseColor: //Sub Procedure
	rc_setLightDiffuseColor( SETLIGHTDIFFUSECOLOR_ACTOR,  SETLIGHTDIFFUSECOLOR_COLOR );
	break;
case FN_GetLightDiffuseColor: //Number Function
	 rc_push_num(rc_getLightDiffuseColor( GETLIGHTDIFFUSECOLOR_ACTOR ));
	break;
case FN_SetLightFalloff: //Sub Procedure
	rc_setLightFalloff( SETLIGHTFALLOFF_ACTOR,  SETLIGHTFALLOFF_FALLOFF );
	break;
case FN_GetLightFalloff: //Number Function
	 rc_push_num(rc_getLightFalloff( GETLIGHTFALLOFF_ACTOR ));
	break;
case FN_SetLightInnerCone: //Sub Procedure
	rc_setLightInnerCone( SETLIGHTINNERCONE_ACTOR,  SETLIGHTINNERCONE_ANGLE );
	break;
case FN_GetLightInnerCone: //Number Function
	 rc_push_num(rc_getLightInnerCone( GETLIGHTINNERCONE_ACTOR ));
	break;
case FN_SetLightOuterCone: //Sub Procedure
	rc_setLightOuterCone( SETLIGHTOUTERCONE_ACTOR,  SETLIGHTOUTERCONE_ANGLE );
	break;
case FN_GetLightOuterCone: //Number Function
	 rc_push_num(rc_getLightOuterCone( GETLIGHTOUTERCONE_ACTOR ));
	break;
case FN_SetLightSpecularColor: //Sub Procedure
	rc_setLightSpecularColor( SETLIGHTSPECULARCOLOR_ACTOR,  SETLIGHTSPECULARCOLOR_COLOR );
	break;
case FN_GetLightSpecularColor: //Number Function
	 rc_push_num(rc_getLightSpecularColor( GETLIGHTSPECULARCOLOR_ACTOR ));
	break;
case FN_GetTerrainPatchAABB: //Sub Procedure
	rc_getTerrainPatchAABB( GETTERRAINPATCHAABB_ACTOR,  GETTERRAINPATCHAABB_PATCHX,  GETTERRAINPATCHAABB_PATCHZ,  &GETTERRAINPATCHAABB_MINX,  &GETTERRAINPATCHAABB_MINY,  &GETTERRAINPATCHAABB_MINZ,  &GETTERRAINPATCHAABB_MAXX,  &GETTERRAINPATCHAABB_MAXY,  &GETTERRAINPATCHAABB_MAXZ );
	break;
case FN_GetTerrainPatchLOD: //Number Function
	 rc_push_num(rc_getTerrainPatchLOD( GETTERRAINPATCHLOD_ACTOR,  GETTERRAINPATCHLOD_PATCHX,  GETTERRAINPATCHLOD_PATCHZ ));
	break;
case FN_GetTerrainHeight: //Number Function
	 rc_push_num(rc_getTerrainHeight( GETTERRAINHEIGHT_ACTOR,  GETTERRAINHEIGHT_PATCHX,  GETTERRAINHEIGHT_PATCHZ ));
	break;
case FN_GetTerrainCenter: //Sub Procedure
	rc_getTerrainCenter( GETTERRAINCENTER_ACTOR,  &GETTERRAINCENTER_X,  &GETTERRAINCENTER_Y,  &GETTERRAINCENTER_Z );
	break;
case FN_SetTerrainLODDistance: //Sub Procedure
	rc_setTerrainLODDistance( SETTERRAINLODDISTANCE_ACTOR,  SETTERRAINLODDISTANCE_LOD,  SETTERRAINLODDISTANCE_DISTANCE );
	break;
case FN_ScaleTerrainTexture: //Sub Procedure
	rc_scaleTerrainTexture( SCALETERRAINTEXTURE_ACTOR,  SCALETERRAINTEXTURE_SCALE,  SCALETERRAINTEXTURE_SCALE2 );
	break;
case FN_SetTerrainCameraMovementDelta: //Sub Procedure
	rc_setTerrainCameraMovementDelta( SETTERRAINCAMERAMOVEMENTDELTA_ACTOR,  SETTERRAINCAMERAMOVEMENTDELTA_DELTA );
	break;
case FN_SetTerrainCameraRotationDelta: //Sub Procedure
	rc_setTerrainCameraRotationDelta( SETTERRAINCAMERAROTATIONDELTA_ACTOR,  SETTERRAINCAMERAROTATIONDELTA_DELTA );
	break;
case FN_SetTerrainPatchLOD: //Sub Procedure
	rc_setTerrainPatchLOD( SETTERRAINPATCHLOD_ACTOR,  SETTERRAINPATCHLOD_PATCHX,  SETTERRAINPATCHLOD_PATCHZ,  SETTERRAINPATCHLOD_LOD );
	break;
case FN_createMaterial: //Number Function
	 rc_push_num(rc_createMaterial(  ));
	break;
case FN_deleteMaterial: //Sub Procedure
	rc_deleteMaterial(  DELETEMATERIAL_MATERIAL_ID );
	break;
case FN_setActorMaterial: //Sub Procedure
	rc_setActorMaterial(  SETACTORMATERIAL_ACTOR,   SETACTORMATERIAL_MATERIAL_NUM,   SETACTORMATERIAL_MATERIAL_ID );
	break;
case FN_getActorMaterial: //Number Function
	 rc_push_num(rc_getActorMaterial(  GETACTORMATERIAL_ACTOR,   GETACTORMATERIAL_MATERIAL_NUM ));
	break;
case FN_copyActorMaterial: //Number Function
	 rc_push_num(rc_copyActorMaterial(  COPYACTORMATERIAL_ACTOR,   COPYACTORMATERIAL_MATERIAL_NUM ));
	break;
case FN_copyMaterial: //Number Function
	 rc_push_num(rc_copyMaterial(  COPYMATERIAL_SMATERIAL_ID ));
	break;
case FN_setMaterialTextureCanvas: //Sub Procedure
	rc_setMaterialTextureCanvas(  SETMATERIALTEXTURECANVAS_MATERIAL_ID,   SETMATERIALTEXTURECANVAS_LEVEL,   SETMATERIALTEXTURECANVAS_CANVAS_ID );
	break;
case FN_setMaterialAmbientColor: //Sub Procedure
	rc_setMaterialAmbientColor(  SETMATERIALAMBIENTCOLOR_MATERIAL_ID,   SETMATERIALAMBIENTCOLOR_COLOR );
	break;
case FN_getMaterialAmbientColor: //Number Function
	 rc_push_num(rc_getMaterialAmbientColor(  GETMATERIALAMBIENTCOLOR_MATERIAL_ID ));
	break;
case FN_setMaterialAntiAliasing: //Sub Procedure
	rc_setMaterialAntiAliasing(  SETMATERIALANTIALIASING_MATERIAL_ID,   SETMATERIALANTIALIASING_AA );
	break;
case FN_getMaterialAntiAliasing: //Number Function
	 rc_push_num(rc_getMaterialAntiAliasing(  GETMATERIALANTIALIASING_MATERIAL_ID ));
	break;
case FN_setMaterialBackfaceCulling: //Sub Procedure
	rc_setMaterialBackfaceCulling(  SETMATERIALBACKFACECULLING_MATERIAL_ID,   SETMATERIALBACKFACECULLING_FLAG );
	break;
case FN_getMaterialBackfaceCulling: //Number Function
	 rc_push_num(rc_getMaterialBackfaceCulling(  GETMATERIALBACKFACECULLING_MATERIAL_ID ));
	break;
case FN_setMaterialBlendFactor: //Sub Procedure
	rc_setMaterialBlendFactor(  SETMATERIALBLENDFACTOR_MATERIAL_ID,   SETMATERIALBLENDFACTOR_BF );
	break;
case FN_getMaterialBlendFactor: //Number Function
	 rc_push_num(rc_getMaterialBlendFactor(  GETMATERIALBLENDFACTOR_MATERIAL_ID ));
	break;
case FN_setMaterialBlendMode: //Sub Procedure
	rc_setMaterialBlendMode(  SETMATERIALBLENDMODE_MATERIAL_ID,   SETMATERIALBLENDMODE_BLEND_MODE );
	break;
case FN_getMaterialBlendMode: //Number Function
	 rc_push_num(rc_getMaterialBlendMode(  GETMATERIALBLENDMODE_MATERIAL_ID ));
	break;
case FN_setMaterialColorMask: //Sub Procedure
	rc_setMaterialColorMask(  SETMATERIALCOLORMASK_MATERIAL_ID,   SETMATERIALCOLORMASK_COLOR_MASK );
	break;
case FN_getMaterialColorMask: //Number Function
	 rc_push_num(rc_getMaterialColorMask(  GETMATERIALCOLORMASK_MATERIAL_ID ));
	break;
case FN_setMaterialColorMode: //Sub Procedure
	rc_setMaterialColorMode(  SETMATERIALCOLORMODE_MATERIAL_ID,   SETMATERIALCOLORMODE_COLOR_MODE );
	break;
case FN_getMaterialColorMode: //Number Function
	 rc_push_num(rc_getMaterialColorMode(  GETMATERIALCOLORMODE_MATERIAL_ID ));
	break;
case FN_setMaterialDiffuseColor: //Sub Procedure
	rc_setMaterialDiffuseColor(  SETMATERIALDIFFUSECOLOR_MATERIAL_ID,   SETMATERIALDIFFUSECOLOR_COLOR );
	break;
case FN_getMaterialDiffuseColor: //Number Function
	 rc_push_num(rc_getMaterialDiffuseColor(  GETMATERIALDIFFUSECOLOR_MATERIAL_ID ));
	break;
case FN_setMaterialEmissiveColor: //Sub Procedure
	rc_setMaterialEmissiveColor(  SETMATERIALEMISSIVECOLOR_MATERIAL_ID,   SETMATERIALEMISSIVECOLOR_COLOR );
	break;
case FN_getMaterialEmissiveColor: //Number Function
	 rc_push_num(rc_getMaterialEmissiveColor(  GETMATERIALEMISSIVECOLOR_MATERIAL_ID ));
	break;
case FN_setMaterialFog: //Sub Procedure
	rc_setMaterialFog(  SETMATERIALFOG_MATERIAL_ID,   SETMATERIALFOG_FLAG );
	break;
case FN_getMaterialFog: //Number Function
	 rc_push_num(rc_getMaterialFog(  GETMATERIALFOG_MATERIAL_ID ));
	break;
case FN_setMaterialFrontfaceCulling: //Sub Procedure
	rc_setMaterialFrontfaceCulling(  SETMATERIALFRONTFACECULLING_MATERIAL_ID,   SETMATERIALFRONTFACECULLING_FLAG );
	break;
case FN_getMaterialFrontfaceCulling: //Number Function
	 rc_push_num(rc_getMaterialFrontfaceCulling(  GETMATERIALFRONTFACECULLING_MATERIAL_ID ));
	break;
case FN_setMaterialGouraudShading: //Sub Procedure
	rc_setMaterialGouraudShading(  SETMATERIALGOURAUDSHADING_MATERIAL_ID,   SETMATERIALGOURAUDSHADING_FLAG );
	break;
case FN_materialIsGouraudShaded: //Number Function
	 rc_push_num(rc_materialIsGouraudShaded(  MATERIALISGOURAUDSHADED_MATERIAL_ID ));
	break;
case FN_materialIsAplhaBlend: //Number Function
	 rc_push_num(rc_materialIsAplhaBlend(  MATERIALISAPLHABLEND_MATERIAL_ID ));
	break;
case FN_materialIsTransparent: //Number Function
	 rc_push_num(rc_materialIsTransparent(  MATERIALISTRANSPARENT_MATERIAL_ID ));
	break;
case FN_setMaterialLighting: //Sub Procedure
	rc_setMaterialLighting(  SETMATERIALLIGHTING_MATERIAL_ID,   SETMATERIALLIGHTING_FLAG );
	break;
case FN_materialIsLit: //Number Function
	 rc_push_num(rc_materialIsLit(  MATERIALISLIT_MATERIAL_ID ));
	break;
case FN_setMaterialType: //Sub Procedure
	rc_setMaterialType(  SETMATERIALTYPE_MATERIAL_ID,   SETMATERIALTYPE_MAT_TYPE );
	break;
case FN_getMaterialType: //Number Function
	 rc_push_num(rc_getMaterialType(  GETMATERIALTYPE_MATERIAL_ID ));
	break;
case FN_setMaterialNormalize: //Sub Procedure
	rc_setMaterialNormalize(  SETMATERIALNORMALIZE_MATERIAL_ID,   SETMATERIALNORMALIZE_FLAG );
	break;
case FN_materialIsNormalized: //Number Function
	 rc_push_num(rc_materialIsNormalized(  MATERIALISNORMALIZED_MATERIAL_ID ));
	break;
case FN_setMaterialPointCloud: //Sub Procedure
	rc_setMaterialPointCloud(  SETMATERIALPOINTCLOUD_MATERIAL_ID,   SETMATERIALPOINTCLOUD_FLAG );
	break;
case FN_materialIsPointCloud: //Number Function
	 rc_push_num(rc_materialIsPointCloud(  MATERIALISPOINTCLOUD_MATERIAL_ID ));
	break;
case FN_setMaterialFlag: //Sub Procedure
	rc_setMaterialFlag(  SETMATERIALFLAG_MATERIAL_ID,   SETMATERIALFLAG_MATERIAL_FLAG,   SETMATERIALFLAG_F_VALUE );
	break;
case FN_getMaterialFlag: //Number Function
	 rc_push_num(rc_getMaterialFlag(  GETMATERIALFLAG_MATERIAL_ID,   GETMATERIALFLAG_MATERIAL_FLAG ));
	break;
case FN_setMaterialTexture: //Sub Procedure
	rc_setMaterialTexture(  SETMATERIALTEXTURE_MATERIAL_ID,   SETMATERIALTEXTURE_LEVEL,   SETMATERIALTEXTURE_IMG_ID );
	break;
case FN_setMaterialShininess: //Sub Procedure
	rc_setMaterialShininess(  SETMATERIALSHININESS_MATERIAL_ID,   SETMATERIALSHININESS_SHININESS );
	break;
case FN_getMaterialShininess: //Number Function
	 rc_push_num(rc_getMaterialShininess(  GETMATERIALSHININESS_MATERIAL_ID ));
	break;
case FN_setMaterialSpecularColor: //Sub Procedure
	rc_setMaterialSpecularColor(  SETMATERIALSPECULARCOLOR_MATERIAL_ID,   SETMATERIALSPECULARCOLOR_COLOR );
	break;
case FN_getMaterialSpecularColor: //Number Function
	 rc_push_num(rc_getMaterialSpecularColor(  GETMATERIALSPECULARCOLOR_MATERIAL_ID ));
	break;
case FN_setMaterialThickness: //Sub Procedure
	rc_setMaterialThickness(  SETMATERIALTHICKNESS_MATERIAL_ID,   SETMATERIALTHICKNESS_THICKNESS );
	break;
case FN_getMaterialThickness: //Number Function
	 rc_push_num(rc_getMaterialThickness(  GETMATERIALTHICKNESS_MATERIAL_ID ));
	break;
case FN_setMaterialWireframe: //Sub Procedure
	rc_setMaterialWireframe(  SETMATERIALWIREFRAME_MATERIAL_ID,   SETMATERIALWIREFRAME_FLAG );
	break;
case FN_materialIsWireframe: //Number Function
	 rc_push_num(rc_materialIsWireframe(  MATERIALISWIREFRAME_MATERIAL_ID ));
	break;
case FN_setActorTexture: //Sub Procedure
	rc_setActorTexture(  SETACTORTEXTURE_ACTOR,   SETACTORTEXTURE_LAYER,   SETACTORTEXTURE_IMAGE_ID );
	break;
case FN_getActorMaterialCount: //Number Function
	 rc_push_num(rc_getActorMaterialCount(  GETACTORMATERIALCOUNT_ACTOR ));
	break;
case FN_setActorMaterialFlag: //Sub Procedure
	rc_setActorMaterialFlag(  SETACTORMATERIALFLAG_ACTOR,   SETACTORMATERIALFLAG_FLAG,   SETACTORMATERIALFLAG_FLAG_VALUE );
	break;
case FN_getActorMaterialFlag: //Number Function
	 rc_push_num(rc_getActorMaterialFlag(  GETACTORMATERIALFLAG_ACTOR,   GETACTORMATERIALFLAG_MATERIAL,   GETACTORMATERIALFLAG_FLAG ));
	break;
case FN_setActorMaterialType: //Sub Procedure
	rc_setActorMaterialType(  SETACTORMATERIALTYPE_ACTOR,   SETACTORMATERIALTYPE_MATERIAL_TYPE );
	break;
case FN_getActorMaterialType: //Number Function
	 rc_push_num(rc_getActorMaterialType(  GETACTORMATERIALTYPE_ACTOR,   GETACTORMATERIALTYPE_MATERIAL ));
	break;
case FN_MaterialExists: //Number Function
	 rc_push_num(rc_materialExists( MATERIALEXISTS_MATERIAL ));
	break;

