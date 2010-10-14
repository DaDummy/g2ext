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
echo                 Building G2Ext core
echo.
echo =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
echo.

msbuild libg2extutils.sln /t:Rebuild /p:Configuration=Debug
msbuild libg2extutils.sln /t:Rebuild /p:Configuration=Release
msbuild g2ext.sln /t:Rebuild /p:Configuration=Debug
msbuild g2ext.sln /t:Rebuild /p:Configuration=Release
"msbuild g2ext.sln /t:Rebuild /p:Configuration=Debug (spacer)"
"msbuild g2ext.sln /t:Rebuild /p:Configuration=Release (spacer)"