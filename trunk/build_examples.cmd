@echo off

setlocal

if "%1"=="dadummy" goto skipcls1
cls
:skipcls1

call "%VS90COMNTOOLS%\vsvars32.bat"

if "%1"=="dadummy" goto skipcls2
cls
:skipcls2

echo =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
echo.
echo                   Building examples
echo.
echo =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
echo.

cd examples
msbuild examples.sln /t:Rebuild /p:Configuration=Debug
msbuild examples.sln /t:Rebuild /p:Configuration=Release
cd ..