@echo off
chcp 1251
set PROGRAM="%~1"

set OUT="%TEMP%\out.txt"

echo Simple test
call %PROGRAM% input.txt output.txt > %OUT% 
if errorlevel 1 goto err
fc %OUT% output.txt 
if errorlevel 1 goto err
echo Simple test complete success


echo All tests complete
exit /B

:err
echo Program testing failed
exit /B