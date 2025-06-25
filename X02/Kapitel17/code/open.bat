ECHO OFF
open
IF ERRORLEVEL 1 GOTO FATAL

IF ERRORLEVEL 0 ECHO Open erfolgreich gelaufen
GOTO ENDE

:FATAL
ECHO Fehler bei Open, Returnstatus = 1
:ENDE
