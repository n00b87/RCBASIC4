Include "unittest_lib.bas"

cat("Strings")

Dim txt$

Print "txt$=\q\q"
Print ""
Print "txt  Len:  Expected=0   Returned="; Len(txt$)
Print "txt  Size:  Expected=0   Returned="; Size(txt$)

Print ""

txt = "hello world"

Print "txt$=\q"; txt; "\q"
Print ""
Print "txt  Len:  Expected=11   Returned="; Len(txt$)
Print "txt  Size:  Expected=11   Returned="; Size(txt$)

Print ""

txt = "こんにちは世界"

Print "txt$=\q"; txt; "\q"
Print ""
Print "txt  Len:  Expected=7   Returned="; Len(txt$)
Print "txt  Size:  Expected=21   Returned="; Size(txt$)

Print ""

Print "txt  ASC: Expected=12371  Returned="; Asc(txt)

txt = "ABCDE"
Print "txt$=\q"; txt; "\q"
Print ""
Print "txt  ASC: Expected=65  Returned="; Asc(txt)
Print ""

txt = "B"
Print "txt$=\q"; txt; "\q"
Print ""
Print "txt  ASC: Expected=66  Returned="; Asc(txt)
Print ""


txt = ""
Print "txt$=\q"; txt; "\q"
Print ""
Print "txt  ASC: Expected=0  Returned="; Asc(txt)
Print ""

Print "Chr$:  Expected=\q界\q"; "  Returned=\q"; Chr$(30028); "\q"
Print ""

txt = "ちは世界"

txt = Insert(txt, "ん", 3)

Print "Insert$:  Expected=\qちは世ん界\q"; "  Returned=\q"; Insert(txt, "ん", 3); "\q"
Print ""

i = InStr(txt, "ん")

Print "InStr$:  Expected=3"; "  Returned="; i
Print ""

Print "LCase$:  Expected=\qhello world\q"; "  Returned=\q"; LCase$("HELLO world"); "\q"
Print "LCase$:  Expected=\q\q"; "  Returned=\q"; LCase$(""); "\q"
Print ""

Print "UCase$:  Expected=\qHELLO WORLD\q"; "  Returned=\q"; UCase$("HELLO world"); "\q"
Print "UCase$:  Expected=\q\q"; "  Returned=\q"; UCase$(""); "\q"
Print ""

txt = "hello world"
Print "Left$:  Expected=\qhel\q"; "  Returned=\q"; Left$(txt, 3); "\q"
txt = "ちは世ん界"
Print "Left$:  Expected=\qちは世\q"; "  Returned=\q"; Left$(txt, 3); "\q"
txt = ""
Print "Left$:  Expected=\q\q"; "  Returned=\q"; Left$(txt, 3); "\q"
Print ""


txt = "hello world"
Print "Right$:  Expected=\qrld\q"; "  Returned=\q"; Right$(txt, 3); "\q"
txt = "ちは世ん界"
Print "Right$:  Expected=\q世ん界\q"; "  Returned=\q"; Right$(txt, 3); "\q"
txt = ""
Print "Right$:  Expected=\q\q"; "  Returned=\q"; Right$(txt, 3); "\q"
Print ""


txt = "hello world"
Print "Mid$:  Expected=\qlo w\q"; "  Returned=\q"; Mid$(txt, 3, 4); "\q"
txt = "ちは世ん界"
Print "Mid$:  Expected=\qは世\q"; "  Returned=\q"; Mid$(txt, 1, 2); "\q"
txt = ""
Print "Mid$:  Expected=\q\q"; "  Returned=\q"; Mid$(txt, 1, 2); "\q"
Print ""


txt = "     hello world   "
Print "LTrim$:  Expected=\qhello world  \q"; "  Returned=\q"; LTrim$(txt); "\q"
txt = "     ちは世ん界  "
Print "LTrim$:  Expected=\qちは世ん界  \q"; "  Returned=\q"; LTrim$(txt); "\q"
txt = "       "
Print "LTrim$:  Expected=\q\q"; "  Returned=\q"; LTrim$(txt); "\q"
txt = ""
Print "LTrim$:  Expected=\q\q"; "  Returned=\q"; LTrim$(txt); "\q"
Print ""

txt = "     hello world   "
Print "RTrim$:  Expected=\q     hello world\q"; "  Returned=\q"; RTrim$(txt); "\q"
txt = "     ちは世ん界  "
Print "RTrim$:  Expected=\q     ちは世ん界\q"; "  Returned=\q"; RTrim$(txt); "\q"
txt = "      "
Print "RTrim$:  Expected=\q\q"; "  Returned=\q"; RTrim$(txt); "\q"
txt = ""
Print "RTrim$:  Expected=\q\q"; "  Returned=\q"; RTrim$(txt); "\q"
Print ""


txt = "     hello world   "
Print "Trim$:  Expected=\qhello world\q"; "  Returned=\q"; Trim$(txt); "\q"
txt = "     ちは世ん界  "
Print "Trim$:  Expected=\qちは世ん界\q"; "  Returned=\q"; Trim$(txt); "\q"
txt = "    "
Print "Trim$:  Expected=\q\q"; "  Returned=\q"; Trim$(txt); "\q"
txt = ""
Print "Trim$:  Expected=\q\q"; "  Returned=\q"; Trim$(txt); "\q"
Print ""


txt = "     hello world   "
Print "Replace$:  Expected=\qheppo worpd\q"; "  Returned=\q"; Replace$(txt,"l", "p"); "\q"
txt = "     ちは世ん界  "
Print "Replace$:  Expected=\q     ちhelloん界  \q"; "  Returned=\q"; Replace$(txt, "は世", "hello"); "\q"
txt = "    "
Print "Replace$:  Expected=\qz \q"; "  Returned=\q"; Replace$(txt, "   ", "z"); "\q"
txt = ""
Print "Replace$:  Expected=\q\q"; "  Returned=\q"; Replace$(txt, "", "zzz"); "\q"
Print ""


txt = "     hello world   "
Print "ReplaceSubstr$:  Expected=\q   ghjillo world   \q"; "  Returned=\q"; ReplaceSubstr$(txt,"ghji",3); "\q"
txt = "     ちは世ん界  "
Print "ReplaceSubstr$:  Expected=\q   ghji世ん界  \q"; "  Returned=\q"; ReplaceSubstr$(txt, "ghji", 3); "\q"
txt = "    "
Print "ReplaceSubstr$:  Expected=\q z  \q"; "  Returned=\q"; ReplaceSubstr$(txt, "z", 1); "\q"
txt = ""
Print "ReplaceSubstr$:  Expected=\q\q"; "  Returned=\q"; ReplaceSubstr$(txt, "zzz", 0); "\q"
Print ""


txt = "     hello world   "
Print "Reverse$:  Expected=\q   dlrow olleh     \q"; "  Returned=\q"; Reverse$(txt); "\q"
txt = "     ちは世ん界  "
Print "Reverse$:  Expected=\q  界ん世はち     \q"; "  Returned=\q"; Reverse$(txt); "\q"
txt = "    "
Print "Reverse$:  Expected=\q    \q"; "  Returned=\q"; Reverse$(txt); "\q"
txt = ""
Print "Reverse$:  Expected=\q\q"; "  Returned=\q"; Reverse$(txt); "\q"
Print ""

Print "StringFill$:  Expected=\qzzz\q"; "  Returned=\q"; StringFill$("z", 3); "\q"
Print "StringFill$:  Expected=\q\q"; "  Returned=\q"; StringFill$("", 3); "\q"
Print "StringFill$:  Expected=\q界ん界ん界ん界ん\q"; "  Returned=\q"; StringFill$("界ん", 4); "\q"
Print "StringFill$:  Expected=\q\q"; "  Returned=\q"; StringFill$("AB", 0); "\q"

Print ""
Print "Str$:  Expected=\q21\q"; "  Returned=\q"; Str$(21); "\q"
Print "Str$:  Expected=\q-1\q"; "  Returned=\q"; Str$(-1); "\q"
Print "Str$:  Expected=\q0\q"; "  Returned=\q"; Str$(0); "\q"
Print "Str$:  Expected=\q3.1234\q"; "  Returned=\q"; Str$(3.1234); "\q"

Print ""
Print "Str_F$:  Expected=\q21.000000\q"; "  Returned=\q"; Str_F$(21); "\q"
Print "Str_F$:  Expected=\q-1.000000\q"; "  Returned=\q"; Str_F$(-1); "\q"
Print "Str_F$:  Expected=\q0.000000\q"; "  Returned=\q"; Str_F$(0); "\q"
Print "Str_F$:  Expected=\q3.123400\q"; "  Returned=\q"; Str_F$(3.1234); "\q"

Print ""
Print "Str_S$:  Expected=\q2.100000e+01\q"; "  Returned=\q"; Str_S$(21); "\q"
Print "Str_S$:  Expected=\q-1.000000e+00\q"; "  Returned=\q"; Str_S$(-1); "\q"
Print "Str_S$:  Expected=\q0.000000e+00\q"; "  Returned=\q"; Str_S$(0); "\q"
Print "Str_S$:  Expected=\q3.123400e+00\q"; "  Returned=\q"; Str_S$(3.1234); "\q"
Print ""

Print "Tally:  Expected=4"; "  Returned="; Tally("tallyhotallyhotallyhotallyho", "tally")
Print "Tally:  Expected=0"; "  Returned="; Tally("tallyhotallyhotallyhotallyho", "yes")
Print "Tally:  Expected=3"; "  Returned="; Tally("界ん界ん界ん界ん", "界ん界")
Print "Tally:  Expected=2"; "  Returned="; Tally("tallyhotallyhotallyho", "hotally")

/'
function Val(n$)
function BufferFromString(s$, ByRef buffer)
function StringFromBuffer$(ByRef buffer, buffer_size)
'/
