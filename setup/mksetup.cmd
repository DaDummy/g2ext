@echo off
echo Generating version header...
subwcrev .\ g2ext.in g2ext.nsi
makensis.exe /V1 g2ext.nsi