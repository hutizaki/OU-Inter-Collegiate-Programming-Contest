@echo off
setlocal enabledelayedexpansion
cd /d "%~dp0"

set "PY="
python --version >nul 2>&1 && set "PY=python"
if not defined PY py --version >nul 2>&1 && set "PY=py"
if not defined PY (
    echo Python 3 is required. Install from python.org or Microsoft Store.
    pause
    exit /b 1
)

%PY% -c "import questionary" >nul 2>&1
if %errorlevel% neq 0 (
    echo Missing dependency: questionary
    set /p "REPLY=Install dependencies? (y/n) "
    if /i "!REPLY:~0,1!"=="y" (
        %PY% -m pip install -r cli-tool/REQUIREMENTS.txt
        if errorlevel 1 (
            echo Install failed. Run "pip install -r cli-tool/REQUIREMENTS.txt" from repo root when ready.
            pause
            exit /b 1
        )
    ) else (
        echo Run "pip install -r cli-tool/REQUIREMENTS.txt" from repo root when ready.
        pause
        exit /b 0
    )
)

%PY% cli-tool/START_NEW_PROBLEM.py
pause
