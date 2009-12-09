RMDIR /S /Q msvc\Debug
RMDIR /S /Q msvc\Release
RMDIR /S /Q msvc\DebugStatic
RMDIR /S /Q msvc\ReleaseStatic
RMDIR /S /Q msvc\Minimal
RMDIR /S /Q msvc\MinimalStatic
RMDIR /S /Q msvc\MinimalDebug
RMDIR /S /Q ..\sdk

DEL msvc\*.ncb
DEL msvc\*.user
DEL msvc\*.suo /A:H
