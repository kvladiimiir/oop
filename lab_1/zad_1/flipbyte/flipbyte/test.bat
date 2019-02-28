@echo off 

chcp 1251 

set PROGRAM="%~1" 

set OUT="%TEMP%\out.txt" 

echo simple test started
call %PROGRAM% 6 > %OUT% 
fc %OUT% output.txt 
if errorlevel 1 goto err 
echo simple test complete 

echo second test started
call %PROGRAM% 61 > %OUT% 
fc %OUT% output_2.txt 
if errorlevel 1 goto err 
echo second test complete 

echo params test started
call %PROGRAM% > %OUT% 
if not errorlevel 1 goto err
echo params test complete 

echo big input_num test started
call %PROGRAM% 500 > %OUT% 
if not errorlevel 1 goto err
echo big input_num test complete 

echo string test started
call %PROGRAM% "World" > %OUT% 
if not errorlevel 1 goto err
echo string test complete 

echo All tests passed 
exit / B 0 

:err 
echo Program testing failed 
exit / B 1