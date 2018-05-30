# Battle System
[![Build Status](https://travis-ci.org/ShelbyZ/BattleSystem.svg?branch=master)](https://travis-ci.org/ShelbyZ/BattleSystem)
[![Build status](https://ci.appveyor.com/api/projects/status/ijaw7cb51cbwxvq4/branch/master?svg=true)](https://ci.appveyor.com/project/ShelbyZ/battlesystem/branch/master)
[![codecov](https://codecov.io/gh/ShelbyZ/BattleSystem/branch/master/graph/badge.svg)](https://codecov.io/gh/ShelbyZ/BattleSystem)
[![Coverage Status](https://coveralls.io/repos/github/ShelbyZ/BattleSystem/badge.svg)](https://coveralls.io/github/ShelbyZ/BattleSystem)

**Battle System** is a library to allow fighting on 1..* entities versus a player party consisting on 1..* controlled entites.

## Arena

**Arena** is a driver program to allow simulated runs of a battle via a command-line interface

## Battle_System

- Register player party
- Register enemy party
- Register victory/loss condition(s)
- Start a battle
- Issue notification of single entity (player/enemy) turn
- Check victory/loss condition(s) at end of round

## Quick Start

Prerequisites:

- Git
- CMake 3.5+
- Google Test
- C++17 or later compiler

To get started:

```bash
> git clone https://github.com/ShelbyZ/BattleSystem
> cd BattleSystem
```

### Depedencies

Currently the depedencies are:

- [googletest](https://github.com/google/googletest)

**Note** - code coverage requires a few additional and is only supported for Linux.

### Google Test

There are two shared platform options:

- Clone and Build https://github.com/google/googletest and ensure that libraries can be found in the search path
- [vcpkg](https://github.com/Microsoft/vcpkg)

For Linux platforms it is possible to pull in the libgtest-dev package and build the source:

```bash
apt-get install libgtest-dev
cd /usr/src/gtest
cmake .
make
export GTEST_ROOT=$(pwd)
```

#### vcpkg

This project includes **vcpkg** as a submodule and can be accessed by:

```bash
git submodule init
git submodule update
```

Feel free to follow the [Quick Start](https://github.com/Microsoft/vcpkg#quick-start) for getting started with **vcpkg**.  Once that is complete, install **Google Test** for the intended build target:

```bash
# .\vcpkg\vcpkg install gtest:x86-windows
# .\vcpkg\vcpkg install gtest:x64-windows
# .\vcpkg\vcpkg install gtest:x64-linux

# installs the environment default (win=x86,linux=x64)
.\vcpkg\vcpkg install gtest
```

**Note** - vcpkg does not currently contain a triplet definition for Linux 32-bit builds

### Code Coverage

Code coverage requires:

- [lcov](http://ltp.sourceforge.net/coverage/lcov.php)
- [gcovr](https://gcovr.com/)

### Building

Currently only MSVC and GCC have been tests, but Clang **should work** as well.

By default building tests and code coverage are disabled.  To enable them pass, supply the following parameters to the cmake command:

- -DBUILD_TESTS=ON
- -DCOVERAGE=ON

Or change the root **CMakeLists.txt** where the options are defined.

#### Windows

It is possible to use either CMake via the command line or Visual Studio 2017 via **Open Folder/CMake**.

**Command Line**
```powershell
SET GENERATOR=Ninja
SET PLATFORM=x86
SET CONFIGURATION=Debug

cmake -G "%GENERATOR%" -DCMAKE_TOOLCHAIN_FILE=./vcpkg/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=%PLATFORM%-windows -DBUILD_TESTS=ON .
cmake --build . --config %CONFIGURATION%
ctest -C %CONFIGURATION% -V
```

**Visual Studio 2017**
Make sure to install the [Test Adapter for Google Test](https://marketplace.visualstudio.com/items?itemName=VisualCPPTeam.TestAdapterforGoogleTest) to have tests discovered in the **Test Explorer** window.

#### Linux

```bash
# Can replace Debug with Release
cmake -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTS=ON -DCOVERAGE=ON .
make
make BattleSystem_coverage
```

## TODO

- Fill out compilers
