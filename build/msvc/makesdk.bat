
xcopy "%1\*.lib" "..\..\sdk" /Q /R /Y /T /I
xcopy "%1\*.lib" "..\..\sdk" /Q /R /Y
if %4 EQU 0 goto no_dll
xcopy "%1\*.dll" "..\..\sdk" /Q /R /Y
:no_dll
xcopy "source\NxOgre*.h" "..\..\sdk" /Q /R /Y
xcopy "..\source\NxOgre*.h" "..\..\sdk" /Q /R /Y

cd ../../sdk
echo *.* > ".gitignore"
echo Instructions for including and linking > "README_%1.txt"
echo -------------------------------------- >> "README_%1.txt"
echo These are the following parameters you should append to your project linker settings.  >> "README_%1.txt"
echo.  >> "README_%1.txt"
echo * Additional Include Directories (.h) %cd%  >> "README_%1.txt"
echo * Additional Library Directories (.lib) %cd%  >> "README_%1.txt"
echo * Additional Dependencies - %3 >> "README_%1.txt"
echo. >> "README_%1.txt"
if %4 EQU 1 goto dll
goto lib
:dll
echo Then copy the file %cd%\%2 to your application directory.  >> "README_%1.txt"
goto fin
:lib
echo No need to copy anything into your application directory as you are using the Static version >> "README_%1.txt"

:fin
echo. >> "README_%1.txt"
echo For a first time user, you should follow one of the many tutorials at http://nxogre.org or have a look at Cake to set up your application.  >> "README_%1.txt"
cd ../build/msvc