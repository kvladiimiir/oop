@echo off

set PROGRAM="%~1"

set OUT="%TEMP%\out.txt"

:: “естируем поиск с одним совпадением
echo Simple test
call %PROGRAM% input.txt "Hello"> %OUT% 
if errorlevel 1 goto err
fc %OUT% output.txt 
if errorlevel 1 goto err
echo Simple test complete success

:: “естируем поиск с несколькими совпадени€ми
echo Many result test
call %PROGRAM% input_many_result.txt "I"> %OUT% 
if errorlevel 1 goto err
fc %OUT% output_many_result.txt 
if errorlevel 1 goto err
echo Many result test complete success


:: “естируем поиск когда не найдено совпадений
echo No result test
call %PROGRAM% input_no_result.txt "Good"> %OUT% 
if errorlevel 1 goto err
fc %OUT% output_no_result.txt 
if errorlevel 1 goto err
echo No result test complete success

:: “естируем поиск с пустой строкой поиска
echo Empty file test
call %PROGRAM% input_empty_file.txt "Good"> %OUT% 
if errorlevel 1 goto err
fc %OUT% output_empty_file.txt 
if errorlevel 1 goto err
echo Empty file test complete success

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1
