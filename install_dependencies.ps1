# Function to execute a command and handle errors
function Execute-Command {
    param (
        [string]$Command,
        [string]$ErrorMessage
    )

    # Execute the command
    Invoke-Expression $Command
    if ($LASTEXITCODE -ne 0) {
        Write-Host $ErrorMessage -ForegroundColor Red
        exit 1
    }
}

# Set project root
$projectRoot = "B:/trips/trips_renderer"
Set-Location $projectRoot

# Define paths
$libE57Repo = "https://github.com/asmaloney/libE57Format.git"
$libE57SourceDir = "$projectRoot/external/libE57Format"
$buildDir = "$libE57SourceDir/E57-build"
$installDir = "$projectRoot/external/e57install"

Write-Host "Installing dependencies using vcpkg..." -ForegroundColor Yellow
# Install Xerces-C using vcpkg
Execute-Command "C:/vcpkg/vcpkg install xerces-c:x64-windows" "XercesC installation failed."

# Clone libE57Format repository
if (-not (Test-Path $libE57SourceDir)) {
    Write-Host "Cloning libE57Format repository..." -ForegroundColor Yellow
    Execute-Command "git clone $libE57Repo $libE57SourceDir" "Failed to clone libE57Format repository."
} else {
    Write-Host "libE57Format already cloned. Pulling latest changes..." -ForegroundColor Yellow
    Set-Location $libE57SourceDir
    Execute-Command "git pull origin master" "Failed to pull latest changes from libE57Format repository."
}

# Create build directory
if (-not (Test-Path $buildDir)) {
    Write-Host "Creating build directory..." -ForegroundColor Yellow
    New-Item -ItemType Directory -Force -Path $buildDir | Out-Null
}

# Navigate to build directory
Set-Location $buildDir

# Configure and build libE57Format using CMake
Write-Host "Configuring libE57Format..." -ForegroundColor Yellow
Execute-Command "cmake $libE57SourceDir -G 'Visual Studio 17 2022' -A x64 -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$installDir -DCMAKE_TOOLCHAIN_FILE='C:/vcpkg/scripts/buildsystems/vcpkg.cmake'" "CMake configuration failed for libE57Format."

Write-Host "Building libE57Format..." -ForegroundColor Yellow
Execute-Command "cmake --build . --config Release --parallel" "Build failed for libE57Format."

Write-Host "Installing libE57Format..." -ForegroundColor Yellow
Execute-Command "cmake --install . --config Release" "Installation failed for libE57Format."

# Verify the installation
Write-Host "Verifying libE57Format installation..." -ForegroundColor Yellow
if (Test-Path "$installDir/include/E57Foundation.h") {
    Write-Host "Installation verified successfully!" -ForegroundColor Green
} else {
    Write-Host "Installation verification failed!" -ForegroundColor Red
}

# Return to project root
Set-Location $projectRoot
Write-Host "libE57Format installation complete!" -ForegroundColor Green
