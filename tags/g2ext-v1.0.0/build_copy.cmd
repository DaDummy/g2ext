@echo off

cls

echo =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
echo.
echo                    Moving files
echo.
echo =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
echo.

rmdir /S /Q build

mkdir build
mkdir build\bin
mkdir build\bin\debug
mkdir build\bin\release
mkdir build\docs
mkdir build\examples
mkdir build\examples\bin
mkdir build\examples\bin\debug
mkdir build\examples\bin\release
mkdir build\api
mkdir build\api\g2
mkdir build\common
mkdir build\_work

copy *.txt 			build\
copy Debug\g2ext.dll 			build\bin\debug\
copy Debug\g2ext.pdb 			build\bin\debug\
copy Release\g2ext.dll 			build\bin\release\
copy Release\g2ext.pdb 			build\bin\release\
copy Debug\g2ext_starter.exe 		build\bin\debug\
copy Debug\g2ext_starter_dev.exe 	build\bin\debug\
copy Release\g2ext_starter.exe 		build\bin\release\
copy Release\g2ext_starter_dev.exe 	build\bin\release\
copy Debug\g2ext_starter.exe 		build\bin\debug\
copy Debug\g2ext_starter_dev.exe 	build\bin\debug\
copy Release\g2ext_starter.exe 		build\bin\release\
copy Release\g2ext_starter_dev.exe 	build\bin\release\
copy bugtrap\BugTrapU.dll 		build\bin\debug\
copy bugtrap\BugTrapU.dll 		build\bin\release\
copy libinject\bin\libinject.dll	build\bin\debug\
copy libinject\bin\libinject.dll	build\bin\release\

copy examples\*.sln			build\examples\

copy examples\Debug\*.dll 		build\examples\bin\debug\
copy examples\Release\*.dll		build\examples\bin\release\

mkdir build\examples\empty_example\

copy examples\empty_example\*.vcproj 		build\examples\empty_example\
copy examples\empty_example\*.cpp 		build\examples\empty_example\
copy examples\empty_example\*.h 		build\examples\empty_example\
copy examples\empty_example\*.def 		build\examples\empty_example\
copy examples\empty_example\*.ini 		build\examples\empty_example\

copy examples\empty_example\*.ini 		build\examples\bin\debug\
copy examples\empty_example\*.ini		build\examples\bin\release\

mkdir build\examples\empty_example\

copy examples\external_example\*.vcproj 	build\examples\external_example\
copy examples\external_example\*.cpp 		build\examples\external_example\
copy examples\external_example\*.h 		build\examples\external_example\
copy examples\external_example\*.def 		build\examples\external_example\
copy examples\external_example\*.ini 		build\examples\external_example\
	
copy examples\externals_example\*.ini 		build\examples\bin\debug\
copy examples\externals_example\*.ini		build\examples\bin\release\

copy temp\docs\g2ext.chm 		build\docs\
copy api\*.* 				build\api\
copy api\g2\*.* 			build\api\g2\
copy common\*.* 			build\common\

copy temp\*.vdf				build\data\

xcopy /s _work\*.* 			build\_work\
xcopy /s boost\*.*			build\boost\
xcopy /s dx7sdk\*.*			build\dx7sdk\