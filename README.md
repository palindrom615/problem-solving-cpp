# Coding Competition Template for C++

## Prerequisites

* c++ >= 17
* cmake >= 3.17
* boost-algorithm >= 1.60

## How to

### Start coding

To add solution for `cf553`,
 
```bash
cp solutions/{example.cpp,cf553.cpp}
```

and it's ready to start solving problem with `cf553.cpp` file.

Adding directories inside `solutions` (e.g. `solutions/codeforce/cf553.cpp`) is 
also good, except target name(i.e. c++ file name) must be unique.

### Run source code

```bash
cmake .
cmake --build . --target cf553
./build/cf553
```

Beloved IDEs that supports CMake integration might also work.

### Run test case

1. Add test input and expected output respectively as `cf553.in` `cf553.out` 
beside `cf553.cpp`
    ```bash
    cat << EOF > solutions/cf553.in
    5 2 1
    5 3
    4 2
    6 4
    3 2
    2 2
    EOF
    
    cat << EOF > solutions/cf553.out
    2 5
    TT
    EOF
    ```
1. Run test
    ```
    cmake --build . --target cf553_test
    ./build/cf553_test
    ```

### Add common utils

Header-only might be enough now; Add utils inside `includes` directory. Assume
that `includes/dijkstra.hpp` is implemented. Now the header file can be
used inside solution like:
   
```c++
...
#include <dijkstra.hpp>

...
```
