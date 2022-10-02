pushd ..\build
call clean.bat
call build.bat
popd
EXIT /B %ERRORLEVEL%