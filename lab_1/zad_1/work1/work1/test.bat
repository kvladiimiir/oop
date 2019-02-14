@echo off
chcp 1251

set PROGRAM="%~1"

set OUT="%TEMP%\out.txt"

:: Тестируем поиск с одним совпадением
echo Simple test
call %PROGRAM% input.txt "Hello"> %OUT% 
if errorlevel 1 goto err
fc %OUT% output.txt 
if errorlevel 1 goto err
echo Simple test complete success

:: Тестируем поиск с несколькими совпадениями
echo Many result test
call %PROGRAM% input_many_result.txt "I"> %OUT% 
if errorlevel 1 goto err
fc %OUT% output_many_result.txt 
if errorlevel 1 goto err
echo Many result test complete success

:: Тестируем поиск с русским языком
echo Russian result test
call %PROGRAM% input_many_result.txt "Не мысля гордый"> %OUT% 
if errorlevel 1 goto err
fc %OUT% output_russian.txt 
if errorlevel 1 goto err
echo Russian result test complete success

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1
