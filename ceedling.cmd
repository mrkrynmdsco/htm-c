REM ----- TDD -----
del /f/q/s tmp_ceedling > NUL
rmdir tmp_ceedling
call ruby .ceedling\bin\ceedling %*
