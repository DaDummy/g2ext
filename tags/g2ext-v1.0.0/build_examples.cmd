@echo off

cls

call "%VS90COMNTOOLS%\vsvars32.bat"

cls

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