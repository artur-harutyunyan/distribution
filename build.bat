@echo off

set CURRENT_PATH=%cd%

if (%QTDIR%)==() set QTDIR=C:\Qt\4.7.2

if (%Configuration%)==() set Configuration=debug
if (%PlatformArchitecture%)==() set PlatformArchitecture=64
if (%DEVELOPMENT%)==() set DEVELOPMENT=yes

if (%BUILD_OUTPUT%)==() set BUILD_OUTPUT=%CURRENT_PATH%\build\%Configuration%x%PlatformArchitecture%

rem Set Qt paths
set PATH=%QTDIR%\bin;%PATH%;%BUILD_OUTPUT%\bin
set QMAKESPEC=win32-msvc2010

rem Set VS2010 paths
call "%VS100COMNTOOLS%\..\..\VC\vcvarsall.bat" amd64

rem echo environment variables
echo -- Configuration set to %Configuration%
echo -- PlatformArchitecture set to %PlatformArchitecture%
echo -- QTDIR set to %QTDIR%
echo -- QMAKESPEC set to %QMAKESPEC%
echo -- BUILD_OUTPUT set to %BUILD_OUTPUT%
echo -- PATH set to %PATH%
rem -----------------------------------------------------------------------------------------

qmake distribution.pro BUILD_OUTPUT="%BUILD_OUTPUT%" CONFIG+=%Configuration%
nmake
pause