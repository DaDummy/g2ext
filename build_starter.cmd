@echo off

setlocal

if "%1"=="dadummy" goto skipcls1
cls
:skipcls1

call "%VS90COMNTOOLS%\vsvars32.bat"
call "%VS100COMNTOOLS%\vsvars32.bat"

if "%1"=="dadummy" goto skipcls2
cls
:skipcls2

echo =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
echo.
echo               Building G2Ext starter
echo.
echo =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
echo.

msbuild libg2extutils.sln /t:Rebuild /p:Configuration=Debug
msbuild libg2extutils.sln /t:Rebuild /p:Configuration=Release
;msbuild starter.sln /t:Rebuild /p:Configuration=Debug
;msbuild starter.sln /t:Rebuild /p:Configuration=Release
msbuild starter.sln /t:Rebuild /p:Configuration="Debug (dev)"
msbuild starter.sln /t:Rebuild /p:Configuration="Release (dev)"