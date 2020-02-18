REM ----- CODE COVERAGE -----
call conda activate htm
del /f/q/s tmp_ceedling > NUL
rmdir tmp_ceedling
call ruby .ceedling\bin\ceedling gcov:all utils:gcov
call conda deactivate
call start "" tmp_ceedling\artifacts\gcov\GcovCoverageResults.html