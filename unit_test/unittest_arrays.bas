Include "unittest_lib.bas"

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
Dim type_array_copy1D_smaller[3] As Test_Type3
Dim type_array_copy1D_bigger[19] As Test_Type3

type_array[0].tst_t[3,4,7].t2_var1[5,3].txt_var2$[7] = "test type array Case One"
type_array[0].tst_t[3,4,7].t2_var1[5,3].y[4,2] = 42
type_array[9].tst_t[6,4,8].t2_var1[5,3].txt_var2$[7] = "test type array Case Two"
type_array[0].tst_t[3,4,7].v1[4] = 29.54
type_array[9].txt_var1$[5,6] = "test type array Case Three"

ArrayCopy(num_array1D, num_array_copy1D_smaller)
ArrayCopy(num_array1D, num_array_copy1D_bigger)

ArrayCopy(str_array1D, str_array_copy1D_smaller)
ArrayCopy(str_array1D, str_array_copy1D_bigger)

ArrayCopy(type_array, type_array_copy1D_smaller)
ArrayCopy(type_array, type_array_copy1D_bigger)

Print "num_array_copy1D_smaller[] Size:  expected=7,0,0,  returned="; ArraySize(num_array_copy1D_smaller,1); ","; ArraySize(num_array_copy1D_smaller,2); ","; ArraySize(num_array_copy1D_smaller,3)
Print "num_array_copy1D_smaller[0] Value:  expected=-4,  returned="; num_array_copy1D_smaller[0]
Print "num_array_copy1D_smaller[1] Value:  expected=12,  returned="; num_array_copy1D_smaller[1]
Print "num_array_copy1D_smaller[6] Value:  expected=99,  returned="; num_array_copy1D_smaller[6]
Print ""
Print "num_array_copy1D_bigger[] Size:  expected=7,0,0,  returned="; ArraySize(num_array_copy1D_bigger,1); ","; ArraySize(num_array_copy1D_bigger,2); ","; ArraySize(num_array_copy1D_bigger,3)
Print "num_array_copy1D_bigger[0] Value:  expected=-4,  returned="; num_array_copy1D_bigger[0]
Print "num_array_copy1D_bigger[1] Value:  expected=12,  returned="; num_array_copy1D_bigger[1]
Print "num_array_copy1D_bigger[6] Value:  expected=99,  returned="; num_array_copy1D_bigger[6]
Print ""
Print dash_line$
Print ""

Print "str_array_copy1D_smaller[] Size:  expected=11,0,0,  returned="; ArraySize(str_array_copy1D_smaller,1); ","; ArraySize(str_array_copy1D_smaller,2); ","; ArraySize(str_array_copy1D_smaller,3)
Print "str_array_copy1D_smaller[0] Value:  expected=\qzero\q,  returned=\q"; str_array_copy1D_smaller[0];"\q"
Print "str_array_copy1D_smaller[4] Value:  expected=\qFoUr\q,  returned=\q"; str_array_copy1D_smaller[4];"\q"
Print "str_array_copy1D_smaller[10] Value:  expected=\qten\q,  returned=\q"; str_array_copy1D_smaller[10];"\q"
Print ""
Print "str_array_copy1D_bigger[] Size:  expected=11,0,0,  returned="; ArraySize(str_array_copy1D_bigger,1); ","; ArraySize(str_array_copy1D_bigger,2); ","; ArraySize(str_array_copy1D_bigger,3)
Print "str_array_copy1D_smaller[0] Value:  expected=\qzero\q,  returned=\q"; str_array_copy1D_bigger[0];"\q"
Print "str_array_copy1D_smaller[4] Value:  expected=\qFoUr\q,  returned=\q"; str_array_copy1D_bigger[4];"\q"
Print "str_array_copy1D_smaller[10] Value:  expected=\qten\q,  returned=\q"; str_array_copy1D_bigger[10];"\q"
Print ""
Print dash_line$
Print ""

Print "type_array_copy1D_smaller[] Size:  expected=10,0,0,  returned="; ArraySize(type_array_copy1D_smaller,1); ","; ArraySize(type_array_copy1D_smaller,2); ","; ArraySize(type_array_copy1D_smaller,3)
Print "type_array_copy1D_smaller[] Number Member Value:  expected=42,  returned="; type_array_copy1D_smaller[0].tst_t[3,4,7].t2_var1[5,3].y[4,2]
Print "type_array_copy1D_smaller[] Number Member Value:  expected=29.54,  returned="; type_array_copy1D_smaller[0].tst_t[3,4,7].v1[4]
Print "type_array_copy1D_smaller[] String Member Value:  expected=\qtest type array Case Two\q,  returned=\q"; type_array_copy1D_smaller[9].tst_t[6,4,8].t2_var1[5,3].txt_var2$[7];"\q"
Print ""
Print "type_array_copy1D_bigger[] Size:  expected=10,0,0,  returned="; ArraySize(type_array_copy1D_bigger,1); ","; ArraySize(type_array_copy1D_bigger,2); ","; ArraySize(type_array_copy1D_bigger,3)
Print "type_array_copy1D_bigger[] Number Member Value:  expected=42,  returned="; type_array_copy1D_bigger[0].tst_t[3,4,7].t2_var1[5,3].y[4,2]
Print "type_array_copy1D_bigger[] Number Member Value:  expected=29.54,  returned="; type_array_copy1D_bigger[0].tst_t[3,4,7].v1[4]
Print "type_array_copy1D_bigger[] String Member Value:  expected=\qtest type array Case Two\q,  returned=\q"; type_array_copy1D_bigger[9].tst_t[6,4,8].t2_var1[5,3].txt_var2$[7];"\q"
Print ""
Print dash_line$
Print ""

