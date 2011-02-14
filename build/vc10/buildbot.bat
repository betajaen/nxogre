@echo off

:: ----------------------------------------------------
IF "%1" == "version" GOTO Version
IF "%1" == "unitybuild" GOTO UnityBuild
IF "%1" == "makesdk" GOTO MakeSDK 
EXIT

:: ----------------------------------------------------
:: Version
:: ----------------------------------------------------
:Version
IF NOT EXIST ../.developer EXIT
ruby buildbot.rb %1 %2 %3 %4
EXIT
:: ----------------------------------------------------

:: ----------------------------------------------------
:: Version
:: ----------------------------------------------------
:UnityBuild
IF NOT EXIST ../.developer EXIT
ruby buildbot.rb %1 %2 %3 %4
EXIT
:: ----------------------------------------------------






:: ----------------------------------------------------
:: MakeSDK
:: ----------------------------------------------------
:MakeSDK
echo [BuildBot] Copying dlls, libs and headers to SDK directory.
xcopy "%2\*.lib" "..\..\sdk" /Q /R /Y /T /I
xcopy "%2\*.lib" "..\..\sdk" /Q /R /Y
xcopy "%2\*.dll" "..\..\sdk" /Q /R /Y
xcopy "..\source\NxOgre*.h" "..\..\sdk" /Q /R /Y
xcopy "..\source\NxOgre*.rb" "..\..\sdk" /Q /R /Y
EXIT
:: ----------------------------------------------------


:: ----------------------------------------------------
