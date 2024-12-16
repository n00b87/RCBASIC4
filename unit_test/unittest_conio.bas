Include "unittest_lib.bas"

cat("Console I/O")

FPrint("Single Line")
Print "\n"
FPrint("Two\nLines")
Print "\n"
user_input$ = Input$("Enter Something: ")
Print ""
Print "You type: "; user_input$
