@echo off
cd /d "%~dp0.."
python START_NEW_PROBLEM.py
if errorlevel 1 (
    py START_NEW_PROBLEM.py
)
pause
