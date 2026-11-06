# Priority service queue

[![C++ CI](https://github.com/PADOALEX/HomeWork_by_PADO/actions/workflows/ci.yml/badge.svg)](https://github.com/PADOALEX/HomeWork_by_PADO/actions/workflows/ci.yml)

An educational service queue: higher urgency first, then ascending ticket number for FIFO ordering within a priority. Console input recovers from invalid choices and exits at EOF.

## Build and run

Install Visual Studio 2022 or later with the Desktop development with C++ workload, CMake 3.20+ and Python 3.12+ for regression tests. Run from the repository root on Windows:

```powershell
cmake -S . -B build
cmake --build build --config Release
ctest --test-dir build -C Release --output-on-failure
.\build\Release\app.exe
```

The original Visual Studio solution remains available. The CMake executable is named `app`; executable location depends on the selected generator. Automated tests use temporary directories for file-based scenarios and verify behavior with bounded subprocess timeouts.

## Scope

This is a single-user academic program, without a database, authentication or deployment. The original Windows console interface is preserved. Source text and console output now use UTF-8; CMake sets the MSVC source encoding explicitly.
