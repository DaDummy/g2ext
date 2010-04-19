@echo off
echo Generating version header...
subwcrev .\ g2ext.in g2ext.nsi
mkdir out
makensis.exe /V1 g2ext.nsi