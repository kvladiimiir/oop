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

:: Тестируем поиск с русским текстом
echo Russian result test
call %PROGRAM% input_many_result.txt "Не мысля гордый"> %OUT% 
if errorlevel 1 goto err
fc %OUT% output_russian.txt 
if errorlevel 1 goto err
echo Russian result test complete success

:: Тестируем поиск когда не найдено совпадений
echo No result test
call %PROGRAM% input_no_result.txt "Good"> %OUT% 
if not errorlevel 1 goto err
fc %OUT% output_no_result.txt 
if errorlevel 1 goto err
echo No result test complete success

:: Тестируем поиск с пустой строкой поиска
echo Empty string test
call %PROGRAM% input.txt ""> %OUT% 
if not errorlevel 1 goto err
fc %OUT% output_empty_string.txt 
if errorlevel 1 goto err
echo Empty string test complete success

:: Тестируем поиск с большим количеством аргументов
echo Arguments test
call %PROGRAM% input.txt "fdd" "sdfsd"> %OUT% 
if not errorlevel 1 goto err
fc %OUT% output_many_arguments.txt 
if errorlevel 1 goto err
echo Arguments test complete success

:: Тестируем поиск с несуществующим файлом
echo Arguments test
call %PROGRAM% input_121212.txt "Hello"> %OUT% 
if not errorlevel 1 goto err
fc %OUT% output_no_file.txt 
if errorlevel 1 goto err
echo Arguments test complete success

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1
