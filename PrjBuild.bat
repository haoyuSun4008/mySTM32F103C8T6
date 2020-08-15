@echo off
rem taskkill /f /im UV4.exe

E:\Keil\UV4\UV4 -r prjOne.uvproj -o Build_Out.txt

for /f "delims=" %%i in (Build_Out.txt) do (set PassFlg=%%i)

if "%PassFlg%" EQU "Target not created" (
    echo *** Build Not Ok ***
    echo *** Old Prg is downloading ***
    E:\Keil\UV4\UV4 -f prjOne.uvproj -o Download_Out.txt
) else (
    echo *** Build Ok ***
    echo *** New Prg is downloading ***
    E:\Keil\UV4\UV4 -f prjOne.uvproj -o Download_Out.txt
)

for /f "delims=" %%i in (Download_Out.txt) do (set PassFlg=%%i)

if "%PassFlg%" EQU "Erase Done.Programming Done.Verify OK.Application running ..." (
    echo *** Download Ok ***
) else (
    echo *** Download Not Ok ***
)

rem taskkill /f /im UV4.exe

pause