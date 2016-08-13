rmdir %CD%\listing /S /Q
rmdir %CD%\output /S /Q
@echo off
for /f %%F in ('dir /b /a-d ^| findstr /vile ".uvproj .uvopt .md .cmd"') do del "%%F"
pause