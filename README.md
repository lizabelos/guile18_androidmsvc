# Guile 1.8.8

This project is an updated Guile 1.8.8 version, that aims to : 
 - Be compatible with recent and newer systems. This includes MSVC 64 bits, and Android.
 - To be dependency free.
 - To be easaly embeddable in other projects.

## Build status

| Platform         | Status                                                                                                                                                |
|------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------|
| Mac (Latest)     | ![Build Status](https://github.com/lizabelos/guile18_androidmsvc/actions/workflows/cmake.yml/badge.svg?branch=main&event=push&label=macos-latest) |
| Windows (Latest) | ![Build Status](https://github.com/lizabelos/guile18_androidmsvc/actions/workflows/cmake.yml/badge.svg?branch=main&event=push&label=windows-latest)               |
| Ubuntu 20.04     | ![Build Status](https://github.com/lizabelos/guile18_androidmsvc/actions/workflows/cmake.yml/badge.svg?branch=main&event=push&label=ubuntu-20.04)                 |
| Ubuntu 18.04     | ![Build Status](https://github.com/lizabelos/guile18_androidmsvc/actions/workflows/cmake.yml/badge.svg?branch=main&event=push&label=ubuntu-18.04)                 |
| Ubuntu 16.04     | ![Build Status](https://github.com/lizabelos/guile18_androidmsvc/actions/workflows/cmake.yml/badge.svg?branch=main&event=push&label=ubuntu-16.04)                 |

## Building

This version of Guile use CMake as a build system.
On any system, you can build Guile with the following commands :

    mkdir build
    cd build
    cmake ..
    cmake --build .

## Embedding

### 1. Clone this repository in a subdirectory of your project (e.g. `thirdparty/guile`)
### 2. Add the following lines to your CMakeLists.txt file :

    add_subdirectory(thirdparty/guile)

### 3. You can now use the `guile` target in your project :

    add_executable(my_executable my_executable.c)
    target_link_libraries(my_executable PUBLIC guile)


## Using Guile with Qt

If you are building a Qt Application with Guile (for example for an Android application), enable the `USE_GUILE_QT` option when configuring Guile :

    set(USE_GUILE_QT ON CACHE BOOL "Use Guile with Qt" FORCE)

Using Qt resources, Guile will automatically embed ice9 into your application.