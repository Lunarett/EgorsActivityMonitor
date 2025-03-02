@echo off

echo [Step 1] Generating Visual Studio project files with Premake...
ThirdParty\premake\premake5.exe vs2022

IF %ERRORLEVEL% NEQ 0 (
    echo [Error] Premake failed to generate project files.
    pause
    exit /b 1
)

echo [Step 2] Locating MSBuild.exe...
for /f "tokens=*" %%i in ('"C:\Program Files (x86)\Microsoft Visual Studio\Installer\vswhere.exe" -latest -products * -requires Microsoft.Component.MSBuild -find MSBuild\**\Bin\MSBuild.exe') do set MSBUILD=%%i

IF NOT EXIST "%MSBUILD%" (
    echo [Error] MSBuild.exe not found!
    pause
    exit /b 1
)

echo [Step 3] Building the solution...
"%MSBUILD%" EgorsActivityMonitor.sln /p:Configuration=Debug

IF %ERRORLEVEL% NEQ 0 (
    echo [Error] MSBuild failed to build the solution.
    pause
    exit /b 1
)

echo [Success] Build complete!
pause
