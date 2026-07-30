@echo off

winget list --name "MSYS2" >nul 2>&1
set MSYS2=%errorlevel%

winget list --name "LLVM MinGW" >nul 2>&1
set MinGW=%errorlevel%

if %MSYS2% EQU 0 (
    cmake -G "MSYS Makefiles" -S .. -B ..\build
) else if %MinGW% EQU 0 (
    cmake -G "MinGW Makefiles" -S .. -B ..\build
) else (
    echo C++ compiler not found!
)
