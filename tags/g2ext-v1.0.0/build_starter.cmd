@echo off

cls

call "%VS90COMNTOOLS%\vsvars32.bat"

cls

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