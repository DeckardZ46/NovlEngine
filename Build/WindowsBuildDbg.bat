@echo off
xmake f -m debug
xmake

echo Build finished.
SET choice=
SET /p choice=Do you want to run it? (y/n): 
IF NOT '%choice%'=='' SET choice=%choice:~0,1%
IF '%choice%'=='Y' GOTO yes
IF '%choice%'=='y' GOTO yes
IF '%choice%'=='N' GOTO no
IF '%choice%'=='n' GOTO no
IF '%choice%'=='' GOTO no
ECHO "%choice%" is not valid
ECHO.
GOTO end

:yes
xmake run 
GOTO end

:no
GOTO end

:end