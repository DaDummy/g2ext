@echo off

if "%1"=="dadummy" goto skipcls1
cls
:skipcls1

echo =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
echo.
echo                    Building vdf
echo.
echo =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
echo.

mkdir build
mkdir build\data

attrib -R -S -H -A .\data /S /D

start /W /D .\ .\GothicVDFS.exe .\g2ext.vm