@ECHO OFF

if "%~1" == "" goto :missingProjectPath
if not exist %1 goto :invalidProjectPath

cd %1
if not exist CMakeLists.txt goto :missingCMakeLists

if not exist build mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug -S ../ -B . -G "MinGW Makefiles"
mingw32-make.exe

cd ..
goto :eof

:missingProjectPath
    echo ERROR: Missing project path argument!
    goto :eof

:invalidProjectPath
    echo ERROR: Invalid project path argument!
    goto :eof

:missingCMakeLists
    echo ERROR: Missing CMakeLists for selected program!
    goto :eof