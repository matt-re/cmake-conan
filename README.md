# App to test CMake and Conan
A simple C++ application to test CMake and Conan for personal development.

## Build

### Debug
```
cmake -S . -B build/debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build/debug
./build/debug/rpn
```

### Release
```
cmake -S . -B build/release -DCMAKE_BUILD_TYPE=Release
cmake --build build/release
./build/release/rpn
```

