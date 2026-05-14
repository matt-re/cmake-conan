# App to test CMake and Conan
A simple C++ application to test CMake and Conan for personal development.

Depends on [GMP](https://gmplib.org/), pulled in via Conan. See
[`THIRD-PARTY-NOTICES`](THIRD-PARTY-NOTICES) for license and attribution.

## Build

Conan is configured with `[layout] cmake_layout`, which generates CMake
presets and a per-config build tree under `build/<Config>/`.

### Debug
```
conan install . -s build_type=Debug --build=missing
cmake --preset conan-debug
cmake --build --preset conan-debug
./build/Debug/rpn
```

### Release
```
conan install . -s build_type=Release --build=missing
cmake --preset conan-release
cmake --build --preset conan-release
./build/Release/rpn
```
