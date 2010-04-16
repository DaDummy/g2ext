@echo off

echo Cleaning/creating build folder...
rmdir /S /Q temp
mkdir temp

cls

echo =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
echo.
echo                Building documentation
echo.
echo =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
echo.

cd doxygen
doxygen g2ext.conf
hhc ..\temp\docs\html\index.hhp
cd ..