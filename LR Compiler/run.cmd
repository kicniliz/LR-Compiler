@ECHO OFF

ECHO removing old files
del LR_Compiler.exe

ECHO compiling new files
g++ -o LR_Compiler LR_Compiler.cpp

ECHO running new files
.\LR_Compiler.exe

ECHO file exited