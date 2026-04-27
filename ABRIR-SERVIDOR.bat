@echo off
title SmokeWorld Control Panel
color 0A

set "SERVER_DIR=E:\_SMOKEWORLD\_SmokeWorld_SERVER\_SmokeWorld_rAthena"

:menu
cls
echo ====================================
echo         SMOKEWORLD PANEL
echo ====================================
echo.
echo 1 - Iniciar Servidores
echo 2 - Parar Servidores
echo 3 - Reiniciar Tudo
echo 4 - Status
echo 5 - Reiniciar Apenas MAP
echo 0 - Sair
echo.
set /p op=Escolha uma opcao: 

if "%op%"=="1" goto start
if "%op%"=="2" goto stop
if "%op%"=="3" goto restart
if "%op%"=="4" goto status
if "%op%"=="5" goto restartmap
if "%op%"=="0" exit

goto menu


:start
cls
echo Iniciando servidores...

wt -w 0 new-tab --title "LOGIN" cmd /k "cd /d %SERVER_DIR% && logserv.bat on"
wt -w 0 new-tab --title "CHAR" cmd /k "cd /d %SERVER_DIR% && charserv.bat on"
wt -w 0 new-tab --title "WEB" cmd /k "cd /d %SERVER_DIR% && webserv.bat on"
wt -w 0 new-tab --title "MAP" cmd /k "cd /d %SERVER_DIR% && mapserv.bat on"

echo.
pause
goto menu


:stop
cls
echo Parando servidores...

taskkill /f /im login-server.exe >nul 2>&1
taskkill /f /im char-server.exe >nul 2>&1
taskkill /f /im web-server.exe >nul 2>&1
taskkill /f /im map-server.exe >nul 2>&1

echo Servidores finalizados.
pause
goto menu


:restart
cls
echo Reiniciando tudo...

taskkill /f /im login-server.exe >nul 2>&1
taskkill /f /im char-server.exe >nul 2>&1
taskkill /f /im web-server.exe >nul 2>&1
taskkill /f /im map-server.exe >nul 2>&1

timeout /t 2 >nul

wt -w 0 new-tab --title "LOGIN" cmd /k "cd /d %SERVER_DIR% && logserv.bat on"
wt -w 0 new-tab --title "CHAR" cmd /k "cd /d %SERVER_DIR% && charserv.bat on"
wt -w 0 new-tab --title "WEB" cmd /k "cd /d %SERVER_DIR% && webserv.bat on"
wt -w 0 new-tab --title "MAP" cmd /k "cd /d %SERVER_DIR% && mapserv.bat on"

echo Reiniciado com sucesso.
pause
goto menu


:restartmap
cls
echo Reiniciando apenas MAP...

taskkill /f /im map-server.exe >nul 2>&1
timeout /t 2 >nul

wt -w 0 new-tab --title "MAP" cmd /k "cd /d %SERVER_DIR% && mapserv.bat on"

echo MAP reiniciado.
pause
goto menu


:status
cls
echo Status atual:
echo.

tasklist | find "login-server.exe"
tasklist | find "char-server.exe"
tasklist | find "web-server.exe"
tasklist | find "map-server.exe"

echo.
pause
goto menu