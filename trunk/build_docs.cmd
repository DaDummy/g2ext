@echo off

echo Cleaning/creating build folder...
rmdir /S /Q temp
mkdir temp

if "%1"=="dadummy" goto skipcls1
cls
:skipcls1

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