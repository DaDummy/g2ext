cls

call "%VS90COMNTOOLS%\vsvars32.bat"

cls

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