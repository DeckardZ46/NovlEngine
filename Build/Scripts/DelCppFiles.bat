::This Script is for Deleting cpp files recursively 
::You can run it when integrating third party libs to reduce wasting time on deleting them manually 
::BE CAUTION TO RUN THIS SCRIPT, it will delete ALL cpp files under this path

@echo off
setlocal
for /r . %%f in (*) do (
    if %%~xf==.cpp (
        echo %%f
    )
)

:start

echo BE CAUTION TO RUN THIS SCRIPT!!!
echo This script is for DELETING cpp files recursively

SET choice=
SET /p choice=Do you want to delete above files ? (y/n): 
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
for /r . %%f in (*) do (
    if %%~xf==.cpp (
        del %%f
    )
)
GOTO end

:end
pause