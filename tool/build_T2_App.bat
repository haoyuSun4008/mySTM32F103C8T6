

@echo off
Setlocal enabledelayedexpansion


echo --------------------------------------pre-handle--------------------------------------


::-----------comments:   clean output

.\tool\clean_output.exe


::-----------comments:   get keil path

for /f "delims=" %%a in (.\tool\0_keilpath.txt) do (
set keilpath=%%a
)

if exist "%keilpath%\C166\bin\C166.exe" (echo "keil path right!") else ( 
echo "keil path wrong keil path wrong keil path wrong"
echo "keil            keil path wrong           wrong"
echo "keil            keil path wrong           wrong"
echo "keil            keil path wrong           wrong"
echo "keil            keil path wrong           wrong"
echo "keil path wrong keil path wrong keil path wrong"
goto END
)


::-----------comments:     copy compiler files
::-----------comments:     move c,lib,h into \output\

for /f "delims=" %%a in ('dir .\CODE\BSW\*.c/b/s/a-d') do copy /y "%%a" "%~dp0\output\%%~nxa"
for /f "delims=" %%a in ('dir .\CODE\BSW\*.h/b/s/a-d') do copy /y "%%a" "%~dp0\output\%%~nxa"

for /f "delims=" %%a in ('dir .\CODE\ASW\T2\*.c/b/s/a-d') do copy /y "%%a" "%~dp0\output\%%~nxa"
for /f "delims=" %%a in ('dir .\CODE\ASW\T2\*.h/b/s/a-d') do copy /y "%%a" "%~dp0\output\%%~nxa"

for /f "delims=" %%a in ('dir .\CODE\CSW\T2_APP\*.c/b/s/a-d') do copy /y "%%a" "%~dp0\output\%%~nxa"
for /f "delims=" %%a in ('dir .\CODE\CSW\T2_APP\*.h/b/s/a-d') do copy /y "%%a" "%~dp0\output\%%~nxa"

for /f "delims=" %%a in ('dir .\CODE\MCAL\*.h/b/a-d') do copy /y ".\CODE\MCAL\%%a" "%~dp0\output\%%~nxa"
for /f "delims=" %%a in ('dir .\CODE\MCAL\T2\*.c/b/s/a-d') do copy /y "%%a" "%~dp0\output\%%~nxa"
for /f "delims=" %%a in ('dir .\CODE\MCAL\T2\*.h/b/s/a-d') do copy /y "%%a" "%~dp0\output\%%~nxa"

for /f "delims=" %%a in ('dir .\CODE\PRJ\T2_APP\*.h/b/s/a-d') do copy /y "%%a" "%~dp0\output\%%~nxa"
for /f "delims=" %%a in ('dir .\CODE\*.h/b/a-d') do copy /y ".\CODE\%%a" "%~dp0\output\%%~nxa"

for /f "delims=" %%a in ('dir .\CODE\*.A66/b/s/a-d') do copy /y "%%a" "%~dp0\output\%%~nxa"

echo --------------------------------------compile C--------------------------------------


::-----------comments:   compile c files

for %%i in (.\output\*.c) do ( echo %%i
"%keilpath%\C166\bin\C166" %%i MODV2 LARGE MODV2 MAC DEBUG CODE
if !errorlevel! GEQ 2 goto ERROR)


echo --------------------------------------compile A66--------------------------------------


::-----------comments:   compile A66 files

"%keilpath%\C166\bin\A166" .\output\START_V3.A66 MODV2 SEGMENTED MODV2 SET (LARGE)




echo --------------------------------------link--------------------------------------


::-----------comments:   find obj

cd .\output

ren START_V3.obj START_V3.oj2

cd ..\

dir .\output\*.obj /B>obj_name.txt

dir .\output\*.lib /B>>obj_name.txt


::-----------comments:   get link.bat

echo cd .\output\ >"link.bat"

set /p="%keilpath%\C166\bin\L166 "<nul>>"link.bat"

set /p=START_V3.obj<nul>>"link.bat"

(for /f "delims=" %%i in ('type "obj_name.txt"') do (
    set /p =, %%i<nul
))>>"link.bat"


::------------------comments:  link for boot

::echo  TO "ehb_t2" CLASSES (ICODE (0xC00000-0xC0EFFF), FCODE (0xC00000-0xC0EFFF), FCONST (0xC00000-0xC0EFFF), HCONST (0xC00000-0xC0EFFF), XCONST (0xC00000-0xC0EFFF), NCONST (0xC04000-0xC07FFF), NDATA (0xE00000-0xE03FFF), NDATA0 (0xE00000-0xE03FFF), SDATA (0xC000-0xDFFF, 0xF600-0xFDFF), SDATA0 (0xC000-0xDFFF, 0xF600-0xFDFF), IDATA (0xF600-0xFDFF), IDATA0 (0xF600-0xFDFF), FDATA (0xA000-0xDFFF, 0xE00000-0xE03FFF), FDATA0 (0xA000-0xDFFF, 0xE00000-0xE03FFF), HDATA (0xA000-0xDFFF, 0xE00000-0xE03FFF), HDATA0 (0xA000-0xDFFF, 0xE00000-0xE03FFF), XDATA (0xA000-0xDFFF, 0xE00000-0xE03FFF), XDATA0 (0xA000-0xDFFF, 0xE00000-0xE03FFF)) CINITTAB (0xC00000-0xC0EFFF) >>"link.bat"


::------------------comments:  link for app

echo  TO "ehb_t2" VECTAB (0xC10000) CLASSES (ICODE (0xC10000-0xC4FFFF), FCODE (0xC10000-0xC4FFFF), FCONST (0xC10000-0xC4FFFF), HCONST (0xC10000-0xC4FFFF), XCONST (0xC10000-0xC4FFFF), NCONST (0xC10000-0xC13FFF), NDATA (0xE00000-0xE03FFF), NDATA0 (0xE00000-0xE03FFF), SDATA (0xC000-0xDFFF, 0xF600-0xFDFF), SDATA0 (0xC000-0xDFFF, 0xF600-0xFDFF), IDATA (0xF600-0xFDFF), IDATA0 (0xF600-0xFDFF), FDATA (0xA000-0xDFFF, 0xE00000-0xE03FFF), FDATA0 (0xA000-0xDFFF, 0xE00000-0xE03FFF), HDATA (0xA000-0xDFFF, 0xE00000-0xE03FFF), HDATA0 (0xA000-0xDFFF, 0xE00000-0xE03FFF), XDATA (0xA000-0xDFFF, 0xE00000-0xE03FFF), XDATA0 (0xA000-0xDFFF, 0xE00000-0xE03FFF))  CINITTAB (0xC10000-0xC4FFFF)                       >>"link.bat"
echo if !errorlevel! GEQ 2 exit /b 2 >>"link.bat"


cd .\output
ren START_V3.oj2 START_V3.obj
cd ..\


call link.bat


if !errorlevel! GEQ 2 (
cd ..\
del obj_name.txt
del link.bat
goto ERROR
)


cd ..\
del obj_name.txt
del link.bat


echo --------------------------------------generate H86--------------------------------------

cd .\output\

"%keilpath%\C166\bin\OH166" ehb_t2 [H167]

cd ..\


echo --------------------------------------generate s19--------------------------------------

copy .\tool\H86toS19LOCAL.exe .\output\H86toS19LOCAL.exe

cd .\output\

H86toS19LOCAL.exe ehb_t2.h86

cd ..\

del /q /s .\output\*.A66
del /q /s .\output\*.c
del /q /s .\output\*.h
del /q /s .\output\*.LST
del /q /s .\output\*.OBJ
del /q /s .\output\*.exe

goto END

:ERROR
.\tool\clean_output.exe
.\tool\echo_err.exe

:END
pause
