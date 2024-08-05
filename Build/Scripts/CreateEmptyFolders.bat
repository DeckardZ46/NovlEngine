:: This script is for creating empty folders 
:: When integrating third party libs :)
:: Path that will be created are below:
::├─bin
::│  └─windows
::│      └─x64
::└─include

@echo off
:start
SET choice=
SET /p choice=Do you want to create empty folders for a new lib? (y/n): 
IF NOT '%choice%'=='' SET choice=%choice:~0,1%
IF '%choice%'=='Y' GOTO yes
IF '%choice%'=='y' GOTO yes
IF '%choice%'=='N' GOTO no
IF '%choice%'=='n' GOTO no
IF '%choice%'=='' GOTO no
ECHO "%choice%" is not valid
ECHO.
GOTO start

:no
GOTO end

:yes
mkdir "bin"
cd "bin"

mkdir "windows"
cd "windows"

mkdir "x64"
 
cd ..
cd ..

mkdir "include"
GOTO end

:end
pause