# Problem Solving Template for C++

This template provides several built-in useful features for problem solving with c++. Such as

- room for your own libraries
- [AtCoder library](https://github.com/atcoder/ac-library) included by default
- flexible and IDE-friendly compilation upon [cmake](https://cmake.org/)
- library management powered by [vcpkg](https://github.com/microsoft/vcpkg)
- basic standard input/output automated testing

## Prerequisites

- c++ compiler
- cmake >= 3.17
- git

## Preparation

1. Download vcpkg by git submodule.
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

1. Generate cmake build system and install vcpkg dependencies.

   ```sh
   cmake .
   ```

## Solve problems

1. Create cpp file in [`solutions`](solutions) directory and update cmake

   ```sh
   # You can start with `solution/example.cpp`.
   cp solutions/example.cpp solutions/cf553.cpp

   # keeping file inside nested directory is also ok EXCEPT that file name must be unique.
   mkdir -p solutions/codeforce
   cp solutions/example.cpp solutions/codeforce/cf553.cpp
   cmake .
   ```

1. Solve the problem!

1. Compile code with [cmake](https://cmake.org/) and run.

   ```sh
   cmake --build . --target cf553
   ./build/cf553
   ```

## Run test case

1.  Add test input and expected output respectively as `{solution_filename}.in` `{solution_filename}.out` besides `{solution_filename}.cpp`. For example, if solution file is `solutions/cf553.cpp`,

    `solutions/cf553.in`

    ```sh
    5 2 1
    5 3
    4 2
    6 4
    3 2
    2 2
    ```

    `solutions/cf553.out`

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

## Write and use your own library

Just write your libraries inside [`include`](include) directory and use it in your solution.
Codes inside [`include`](include) directory is included by default.
For example, suppose that you just implemented header-only `include/dijkstra.hpp`, by then

```c++
// inside solution.cpp
#include <dijkstra.hpp>

...
```

## Add and use vcpkg package

[AtCoder library](https://github.com/atcoder/ac-library) which is included by default can be used right away.

```c++
// inside solution.cpp
#include <atcoder/fenwicktree>

using namespace atcoder;

fenwick_tree<int> fw(2 << 20);
fw.add(1, 10)
```

Add desired package in `dependencies` array in [`vcpkg.json`](vcpkg.json). Suppose that you want to add [abseil](https://abseil.io). Then,

1. add `"abseil"` inside `"dependencies"` key of `vcpkg.json`
1. run `cmake .`
1. done!

   ```cpp
   // inside solution.cpp
   #include <absl/container/btree_set.h>

   using namespace absl;

   btree_set<std::string> set1;
   ```
