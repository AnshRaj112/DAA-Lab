@echo off
echo Compiling prims_simple.c...
gcc -Wall -Wextra -std=c99 -O2 -o prims_simple.exe prims_simple.c
if %errorlevel% neq 0 (
    echo Compilation failed!
    pause
    exit /b 1
)

echo Compilation successful!
echo.
echo Testing with input: 9 vertices, starting vertex 1
echo.
echo 9
echo 1
) | prims_simple.exe

echo.
echo Test completed!
pause
