@echo off
echo [C++ Builder] PROGRAM THREAD @ Info: Building...
if not exist bin md bin
c++ index.cpp -o "bin/index.exe"
if exist bin/index.exe goto success else goto fail
:fail
echo [C++ Builder] PROGRAM THREAD @ Error: Build failed.
exit
:success
echo [C++ Builder] PROGRAM THREAD @ Info: Build finished - opening the program...
call "bin/index.exe" -fmv -fmT