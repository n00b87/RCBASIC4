Sub cat( cat_name$ )
	Print""
	Print "---------------------["; UCase$(cat_name$); " Test]---------------------"
End Sub


cat("Console I/O")

FPrint("Single Line")
FPrint("Two\nLines")
Print ""
user_input$ = Input$("Enter Something: ")
Print ""
Print "You type: "; user_input$


cat("Arrays")
Dim num_array1D[7]
Dim str_array1D$[11]
Dim usr_array1D[22] As Empty

Dim num_array2D[4, 6]
Dim str_array2D$[3, 9]
Dim usr_array2D[2,5] As Empty

Dim num_array3D[13,11,6]
Dim str_array3D[11,22,7]
Dim usr_array3D[12,5,14] As Empty

Print "*** ArrayDim() Test ***"
Print ""

Print "num_array1D[] dimensions:  expected=1,  returned="; ArrayDim(num_array1D)
Print "str_array1D[] dimensions:  expected=1,  returned="; ArrayDim(str_array1D)
Print "usr_array1D[] dimensions:  expected=1,  returned="; ArrayDim(usr_array1D)

Print ""

Print "num_array2D[] dimensions:  expected=2,  returned="; ArrayDim(num_array2D)
Print "str_array2D[] dimensions:  expected=2,  returned="; ArrayDim(str_array2D)
Print "usr_array2D[] dimensions:  expected=2,  returned="; ArrayDim(usr_array2D)

Print ""

Print "num_array3D[] dimensions:  expected=3,  returned="; ArrayDim(num_array3D)
Print "str_array3D[] dimensions:  expected=3,  returned="; ArrayDim(str_array3D)
Print "usr_array3D[] dimensions:  expected=3,  returned="; ArrayDim(usr_array3D)

Print ""

Print "*** ArraySize() Test ***"
Print ""

Print "num_array1D[] Size:  expected=7,0,0,  returned="; ArraySize(num_array1D,1); ","; ArraySize(num_array1D,2); ","; ArraySize(num_array1D,3)
Print "str_array1D[] Size:  expected=11,0,0,  returned="; ArraySize(str_array1D,1); ","; ArraySize(str_array1D,2); ","; ArraySize(str_array1D,3)
Print "usr_array1D[] Size:  expected=22,0,0,  returned="; ArraySize(usr_array1D,1); ","; ArraySize(usr_array1D,2); ","; ArraySize(usr_array1D,3)

Print ""

Print "num_array2D[] Size:  expected=4,6,0,  returned="; ArraySize(num_array2D,1); ","; ArraySize(num_array2D,2); ","; ArraySize(num_array2D,3)
Print "str_array2D[] Size:  expected=3,9,0,  returned="; ArraySize(str_array2D,1); ","; ArraySize(str_array2D,2); ","; ArraySize(str_array2D,3)
Print "usr_array2D[] Size:  expected=2,5,0,  returned="; ArraySize(usr_array2D,1); ","; ArraySize(usr_array2D,2); ","; ArraySize(usr_array2D,3)

Print ""

Print "num_array3D[] Size:  expected=13,11,6,  returned="; ArraySize(num_array3D,1); ","; ArraySize(num_array3D,2); ","; ArraySize(num_array3D,3)
Print "str_array3D[] Size:  expected=11,22,7,  returned="; ArraySize(str_array3D,1); ","; ArraySize(str_array3D,2); ","; ArraySize(str_array3D,3)
Print "usr_array3D[] Size:  expected=12,5,14,  returned="; ArraySize(usr_array3D,1); ","; ArraySize(usr_array3D,2); ","; ArraySize(usr_array3D,3)

Print ""

Print "*** ArrayCopy() Test ***"
Print ""

Dim num_array_copy1D_smaller[3]
Dim num_array_copy1D_bigger[21]

Dim str_array_copy1D_smaller$[3]
Dim str_array_copy1D_bigger$[21]

num_array1D[0] = -4
num_array1D[1] = 12
num_array1D[2] = 9
num_array1D[6] = 99

str_array1D$[0] = "zero"
str_array1D$[4] = "FoUr"
str_array1D$[9] = "NINE"
str_array1D$[10] = "ten"

Type Test_Type1
	Dim x[5]
	Dim y[7,5]
	Dim txt_var1$
	Dim txt_var2$[14]
End Type

Type Test_Type2
	Dim t2_var1[7,5] As Test_Type1
	Dim v1[25]
	Dim txt_var1$
End Type

Type Test_Type3
	Dim tst_t[7,5,9] As Test_Type2
	Dim tst_t2 As Test_Type2
	Dim x, y[6,5], z[21]
	Dim txt_var1$[8,7]
End Type

Dim type_array[10] As Test_Type3
Dim type_array_copy_smaller[3]
Dim type_array_copy_bigger[19]

type_array[0].tst_t[3,4,7].t2_var1[5,3].txt_var2$[7] = "test type array Case One"
type_array[0].tst_t[3,4,7].t2_var1[5,3].y[4,2] = 42
type_array[9].tst_t[6,4,8].t2_var1[5,3].txt_var2$[7] = "test type array Case Two"
type_array[0].tst_t[3,4,7].v1[4] = 29.54
type_array[9].txt_var1$[5,6] = "test type array Case Three"

ArrayCopy(num_array1D, num_array_copy1D_smaller)
ArrayCopy(num_array1D, num_array_copy1D_bigger)

ArrayCopy(str_array1D, str_array_copy1D_smaller)
ArrayCopy(str_array1D, str_array_copy1D_bigger)

Print "test type"
ArrayCopy(type_array, type_array_copy_smaller)
Print "Not Dead yet"
ArrayCopy(type_array, type_array_copy_bigger)

Print "num_array1D[] Size:  expected=7,0,0,  returned="; ArraySize(num_array1D,1); ","; ArraySize(num_array1D,2); ","; ArraySize(num_array1D,3)
Print "str_array1D[] Size:  expected=11,0,0,  returned="; ArraySize(str_array1D,1); ","; ArraySize(str_array1D,2); ","; ArraySize(str_array1D,3)
Print "usr_array1D[] Size:  expected=22,0,0,  returned="; ArraySize(usr_array1D,1); ","; ArraySize(usr_array1D,2); ","; ArraySize(usr_array1D,3)



'Testing User Types
Type TestType1
	Dim x, y[5]
	Dim txt$[7]
	Dim t2$
End Type

Type TestType2
	Dim a
	Dim b[12] As TestType1
	Dim c As TestType1
End Type

Type TestType3
	Dim r[6] As TestType2
	Dim c As TestType1
End Type


Dim v[20] As TestType3

v[4].r[2].b[11].txt$[4] = "hello"

Print "Testing User Defined Types"
Print "------------------------------"
For i = 0 to ArraySize(v[4].r[2].b[11].txt$, 1)-1
	Print "txt["; i; "] = "; v[4].r[2].b[11].txt$[i]
Next


Print ""
Print "Testing Graphics and Physics"
'Testing Graphics
OpenWindow("Test Window", 640, 480, 0, 0)

Dim w, h

GetWindowSize(w, h)

Print "Win Size = "; w;", "; h

canvas1 = OpenCanvas(640, 480, 0, 0, 640, 480, 0)
canvas2 = OpenCanvas(640, 480, 0, 0, 640, 480, 0)

SetCanvasZ(canvas2, 0)

SetCanvas3D(canvas1, true)

fnt$ = "NotoSansJP-VariableFont_wght.ttf"
hud_font = loadFont(fnt, 12)

Canvas(canvas2)

SetColor(RGB(255,255,255))
Dim hud_txt$[9]
hud_txt$[0] = "W/A/S/D Keys to Move"
hud_txt$[1] = "R/F Keys to Move Up/Down"
hud_txt$[2] = "Arrow Keys to Rotate Camera"
hud_txt$[3] = "Z Key to Rotate Character"
hud_txt$[4] = "X Key to Move Character Forward"
hud_txt$[5] = "C Key to Move Character Up"

For i = 0 to 5
	DrawText(hud_txt$[i], 10, 10+(i*15))
Next

Canvas(canvas1)

mesh1 = LoadMesh("media/sydney.md2")

actor1 = CreateMeshActor(mesh1)
actor1_texture = LoadImage("media/sydney.bmp")
mat = CreateMaterial()
SetMaterialTexture(mat, 0, actor1_texture)
SetMaterialLighting(mat, false)
SetActorMaterial(actor1, 0, mat)

a_mat = GetActorMaterial(actor1, 0)
SetMaterialLighting(a_mat, false)

SetActorSolid(actor1, true)
SetActorCollisionShape(actor1, 4, 25)
TranslateActor(actor1, 0, 150, 0)


level = LoadMeshFromArchive("media/map-20kdm2.pk3", "20kdm2.bsp")
actor2 = CreateMeshOctreeActor(level)
SetActorSolid(actor2, true)
SetActorCollisionShape(actor2, 7, 0)


Dim ax, ay, az

Canvas(canvas1)
SetActorPosition(actor1, 1160, 399, 2122)
SetActorRotation(actor1, 0, 0, 0)

SetCameraPosition(984, 488, 2303)
SetCameraRotation(23, 1216, 0)

init = true
i = 0

Dim vx, vy, vz
mass = 8
GetActorLocalInertia(actor1, vx, vy, vz)
SetActorMassProperties(actor1, mass, vx, vy, vz)
SetActorGravity(actor1, 0, -100, 0)

While Not Key(K_ESCAPE)

	SetActorAngularVelocityWorld(actor1, 0, 0, 0)

	If Key(K_W) Then
		Canvas(canvas1)
		TranslateCamera(0,0,10)
    ElseIf Key(K_S) Then
		Canvas(canvas1)
		TranslateCamera(0,0,-10)
	End If

	If Key(K_A) Then 
		Canvas(canvas1)
		TranslateCamera(-10,0,0)
	ElseIf Key(K_D) Then
		Canvas(canvas1)
		TranslateCamera(10,0,0)
	End If

	If Key(K_R) Then
		Canvas(canvas1)
		Dim crx, cry, crz
		GetCameraPosition(crx, cry, crz)
		SetCameraPosition(crx, cry+10, crz)
	ElseIf Key(K_F) Then
		Canvas(canvas1)
		'TranslateCameraW(0, -10, 0) - Haven't added this function yet
		Dim crx, cry, crz
		GetCameraPosition(crx, cry, crz)
		SetCameraPosition(crx, cry-10, crz)
	End If


	If Key(K_UP) Then
		Canvas(canvas1)
		RotateCamera(1, 0, 0)
	ElseIf Key(K_DOWN) Then
		Canvas(canvas1)
		RotateCamera(-1, 0, 0)
	End If

	If Key(K_LEFT) Then
		Canvas(canvas1)
		Dim crx, cry, crz
		GetCameraRotation(crx, cry, crz)

		RotateCamera(-1*crx, 0, 0)
		RotateCamera(0, -1, 0)
		RotateCamera(crx, 0, 0)
	ElseIf Key(K_RIGHT) Then
		Canvas(canvas1)
		Dim crx, cry, crz
		GetCameraRotation(crx, cry, crz)
		SetCameraRotation(crx, cry+1, crz)
	End If

	If Key(K_Z) Then
		SetActorAngularVelocityLocal(actor1, 0, 10, 0)
	End If

	If Key(K_X) Then
		SetActorLinearVelocityLocal(actor1, 60, 0, 0)
	End If

	If Key(K_C) Then
		SetActorLinearVelocityLocal(actor1, 0, 60, 0)
	End If

	Update()
Wend
