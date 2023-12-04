@echo off
setlocal enabledelayedexpansion

set /p classInfo=Enter the class name and optional parent class (if any, separate with a space): 

rem Extract class name and parent class name (if provided)
for /f "tokens=1,* delims= " %%a in ("!classInfo!") do (
    set className=%%a
    set parentClassName=%%b
)

if "!className!" == "" (
    echo Error: Class name cannot be empty.
    exit /b 1
)

set headerFile=Asteroids/Include/%className%.h
set cppFile=Asteroids/Source/%className%.cpp

if exist %headerFile% (
    echo Error: Header file %headerFile% already exists.
    exit /b 1
)

if exist %cppFile% (
    echo Error: C++ file %cppFile% already exists.
    exit /b 1
)

rem Create header file
echo #pragma once > %headerFile%
if not "!parentClassName!" == "" (
    echo. >> %headerFile%
    echo #include "%parentClassName%.h" >> %headerFile%
)
echo. >> %headerFile%

if not "!parentClassName!" == "" (
    echo class %className% : public %parentClassName% >> %headerFile%
)
if "!parentClassName!" == "" (
    echo class %className% >> %headerFile%
)
echo { >> %headerFile%
echo public: >> %headerFile%
echo     %className%(); >> %headerFile%
echo     // Add more members and functions as needed >> %headerFile%
echo private: >> %headerFile%
echo     // Add private members as needed >> %headerFile%
echo }; >> %headerFile%

rem Create cpp file
echo #include "%className%.h" > %cppFile%
echo. >> %cppFile%
echo %className%::%className%() >> %cppFile%
echo { >> %cppFile%
echo     // Constructor implementation goes here >> %cppFile%
echo } >> %cppFile%

echo Class %className% created successfully.

rem Call vs2022.bat
call vs2022.bat
