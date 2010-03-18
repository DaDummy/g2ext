@echo off

if "%1"=="dadummy" goto skipcls1
cls
:skipcls1

echo =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
echo.
echo                  G2Ext build script
echo.
echo =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
echo.

echo.
echo Building...
echo.

call build_g2ext.cmd %1

call build_starter.cmd %1

call build_examples.cmd %1

call build_docs.cmd %1

call build_copy.cmd %1

if "%1"=="dadummy" goto skipcls2
cls
:skipcls2

echo =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
echo.
echo                         DONE!
echo.
echo =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
echo.