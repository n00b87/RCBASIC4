Type test_type
	Dim w
End Type

Type ano
	Dim t[8] as test_type
	Dim n
End Type

x[4].t.w = 13

Dim x[6] as ano
Dim y[4] as ano
Dim z[4] as ano

ArrayCopy(x, y)
