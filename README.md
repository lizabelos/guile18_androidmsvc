# Guile++

This project is fork of Guile 1.8.8 version, that aims to : 
 - Be compatible with recent and newer systems. This includes MSVC 64 bits, and Android.
 - To be dependency free.
 - To be easily embeddable in other projects.

## Status

| Platform         | Build Status                                                                                                                                        | Test Pass |
|------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------|----------|
| Mac (Latest)     | ![Build Status](https://github.com/lizabelos/guile18_androidmsvc/actions/workflows/cmake.yml/badge.svg?branch=main&event=push&label=macos-latest)   |          |
| Windows (Latest) | ![Build Status](https://github.com/lizabelos/guile18_androidmsvc/actions/workflows/cmake.yml/badge.svg?branch=main&event=push&label=windows-latest) |          |
| Ubuntu 20.04     | ![Build Status](https://github.com/lizabelos/guile18_androidmsvc/actions/workflows/cmake.yml/badge.svg?branch=main&event=push&label=ubuntu-20.04)   |          |
| Ubuntu 18.04     | ![Build Status](https://github.com/lizabelos/guile18_androidmsvc/actions/workflows/cmake.yml/badge.svg?branch=main&event=push&label=ubuntu-18.04)   |          |
| Ubuntu 16.04     | ![Build Status](https://github.com/lizabelos/guile18_androidmsvc/actions/workflows/cmake.yml/badge.svg?branch=main&event=push&label=ubuntu-16.04)   |          |

## Building

This version of Guile use CMake as a build system. 
Autoconf was designed for Unix systems, and is difficult to use on MSVC. That is why we prefer to use CMake, which has a cross-platform easy syntax, can generate not only Makefile but also Visual Studio projects, Xcode projects, and many others, and can be easily integrated to Android and iOS project. 

On any system, you can build Guile with the following commands :

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Embedding

This Guile version has been designed to be embeddable in other CMake projects.

#### 1. Clone this repository in a subdirectory of your project (e.g. `thirdparty/guile`)
#### 2. Add the following lines to your CMakeLists.txt file :

```cmake
add_subdirectory(thirdparty/guile)
```

#### 3. You can now use the `guile` target in your project :

```cmake
add_executable(my_executable my_executable.c)
target_link_libraries(my_executable PUBLIC guile)
```

## Using Guile with Qt

If you are building a Qt Application with Guile (for example for an Android application), enable the `USE_GUILE_QT` option when configuring Guile :

```cmake
set(USE_GUILE_QT5 ON CACHE BOOL "Use Guile with Qt" FORCE)
# or
set(USE_GUILE_QT6 ON CACHE BOOL "Use Guile with Qt" FORCE)
```

Using Qt resources, Guile will automatically embed ice9 into your application. You can use te embedded ice9 by adding `scm_use_embedded_ice9();` to your C++ code :
```cpp
#include <libguile.hpp>

int main(int argc, char **argv) {
    scm_use_embedded_ice9();
    scm_boot_guile(argc, argv, inner_main, nullptr);
    return 0;
}
```

Note that `scm_use_embedded_ice9();` has the priority to the `GUILE_LOAD_PATH` environment variable.

## The new C++ callback API (experimental)

The new C++ callback API is a new way to call C++ code from Guile code. It is a replacement for the old `scm_c_define_gsubr` API.
The new API allows to use member functions as callbacks, to use lambdas, and to capture variables in the lambdas.
```cpp
register_callback("testfn8", [](SCM args) {
        printf("testfn8 called\n");
        return SCM_UNSPECIFIED;
    }, 8);
scm_c_eval_string("(testfn8 1 2 3 4 5 6 7 8)");
```

## What is not working with this version of Guile ?

We do not plan to implement the following features :
 - Futures
 - i18n (gettext)
 - ioext
 - everything related to posix (exemple: filesys, regex)
 - net_db, socket
 - dynamic linking
 - extensions

We do not plan to re-active the following features :
 - threads