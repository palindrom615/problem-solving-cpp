# Coding Competition Template for C++

## Prerequisites

- c++ >= 17
- cmake >= 3.17
- git

## How to

### Prepare prequisites

1. Download [vcpkg](https://vcpkg.io/en/index.html) with git submodule.
   ```sh
   git submodule init
   git submodule update
   ```
1. Bootstrap vcpkg.

   ```sh
   # for macOS & linux
   ./vcpkg/bootstrap-vcpkg.sh --disable-metrics

   # for windows
   ./vcpkg/bootstrap-vcpkg.bat --disable-metrics
   ```

1. (optional) Install `boost-algorithm` library:
   This is needed to run [test](#run-test-case)!
   ```sh
   ./vcpkg/vcpkg install boost-algorithm
   ```
1. Generate cmake build system.
   ```sh
   cmake .
   ```

### Start solving problems

1. Create cpp file in `solutions` directory.

   ```sh
   # You can start with `solution/example.cpp`.
   cp solutions/example.cpp solutions/cf553.cpp

   # keeping file inside nested directory is also ok EXCEPT that, file name must be unique.
   mkdir -p solutions/codeforce
   cp solutions/example.cpp solutions/codeforce/cf553.cpp
   ```

1. Solve the problem!

1. Compile your code with [cmake](https://cmake.org/) and run.

   ```sh
   cmake --build . --target cf553
   ./build/cf553
   ```

   Beloved IDEs that supports CMake integration might also work.

### Run test case

1.  Add test input and expected output respectively as `cf553.in` `cf553.out` besides `cf553.cpp`.

    `cf553.in`

    ```sh
    5 2 1
    5 3
    4 2
    6 4
    3 2
    2 2
    ```

    `cf553.out`

    ```
    2 5
    TT
    ```

1.  Build and run test.
    The test is defined as `{solution_filename}_test` by cmake.
    ```
    cmake --build . --target cf553_test
    ./build/cf553_test
    ```

### Add common utils

Header-only library inside `includes` directory is automatically linked.
Suppose that `includes/dijkstra.hpp` is implemented. The header file can be
used inside solution like:

```c++
...
#include <dijkstra.hpp>

...
```
