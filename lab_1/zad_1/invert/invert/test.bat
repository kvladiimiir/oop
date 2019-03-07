@echo off

chcp 1251

set PROGRAM="%~1"

set OUT="%TEMP%\out.txt"

echo simple test is started
call %PROGRAM% input.txt > %OUT%
fc %OUT% output.txt
if errorlevel 1 goto err
echo simple test complete

echo NoArg test is started
call %PROGRAM% > %OUT%
if not errorlevel 1 goto err
echo NoArg test complete

echo EmptyString test is started
call %PROGRAM% ''> %OUT%
if not errorlevel 1 goto err
echo EmptyString test complete

echo MoreArgs test is started
call %PROGRAM% input.txt oiu sda> %OUT%
if not errorlevel 1 goto err
echo MoreArgs test complete

echo NoFile test is started
call %PROGRAM% iFsput.txt> %OUT%
if not errorlevel 1 goto err
echo NoFile test complete

echo NullDec test is started
call %PROGRAM% input_null_dec.txt> %OUT%
if not errorlevel 1 goto err
echo NullDec test complete

echo All tests passed
exit / B 0

:err
echo Program testing failed
exit / B 1