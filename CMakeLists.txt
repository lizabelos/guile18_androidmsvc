cmake_minimum_required(VERSION 3.16)
project(guile_liza VERSION 1.8.8 LANGUAGES C CXX)
set(GUILE_MAJOR_VERSION ${guile_liza_VERSION_MAJOR})
set(GUILE_MINOR_VERSION ${guile_liza_VERSION_MINOR})
set(GUILE_MICRO_VERSION ${guile_liza_VERSION_PATCH})
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)
set (CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(cmake/AutotoolCheck.cmake)

find_package(Threads REQUIRED)
find_package(Math REQUIRED)

include_directories(${CMAKE_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR})
configure_file (${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.h.cmake                 ${CMAKE_CURRENT_BINARY_DIR}/config.h)
add_definitions(-DHAVE_CONFIG_H)
configure_file (${CMAKE_CURRENT_SOURCE_DIR}/cmake/libguile/gen-scmconfig.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/libguile/gen-scmconfig.h)
configure_file (${CMAKE_CURRENT_SOURCE_DIR}/cmake/libguile/version.h.cmake       ${CMAKE_CURRENT_BINARY_DIR}/libguile/version.h)
configure_file (${CMAKE_CURRENT_SOURCE_DIR}/cmake/libguile/libpath.h.cmake       ${CMAKE_CURRENT_BINARY_DIR}/libguile/libpath.h)


add_library(guile STATIC)
# use -fno-strict-aliasing
target_compile_options(guile PUBLIC -fno-strict-aliasing)

option(GUILE_ENABLE_CHECK_PTR OFF)
if (GUILE_ENABLE_CHECK_PTR)
    target_compile_definitions(guile PUBLIC GUILE_ENABLE_CHECK_PTR)
endif()

#target_compile_options(guile PUBLIC -Werror -Wall -Wextra)
#target_link_options(guile PUBLIC -Werror -Wall -Wextra)

option(GUILE_ENABLE_SANITIZE OFF)
if (GUILE_ENABLE_SANITIZE)
    target_compile_options(guile PUBLIC -fsanitize=address)
    target_link_options(guile PUBLIC -fsanitize=address)
endif()

target_sources(guile
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/alist.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/alloca.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/arbiters.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/async.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/backtrace.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/boolean.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/chars.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/continuations.c
        #        conv-integer.i.c
        #        conv-uinteger.i.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/convert.c
        #        convert.i.c
        #        coop-pthreads.c
        #        coop.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/cpp_err_symbols.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/cpp_errno.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/cpp_sig_symbols.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/cpp_signal.c
        # ${CMAKE_CURRENT_SOURCE_DIR}/libguile/debug-malloc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/debug.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/deprecated.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/deprecation.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/discouraged.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/dynl.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/dynwind.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/environments.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/eq.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/error.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/eval.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/evalext.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/extensions.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/feature.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/filesys.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/fluids.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/fports.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/futures.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/gc-card.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/gc-freelist.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/gc-malloc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/gc-mark.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/gc-segment.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/gc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/gc_os_dep.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/gdbint.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/gh_data.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/gh_eval.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/gh_funcs.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/gh_init.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/gh_io.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/gh_list.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/gh_predicates.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/goops.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/gsubr.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/guardians.c
        # ${CMAKE_CURRENT_SOURCE_DIR}/libguile/guile.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/hash.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/hashtab.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/hooks.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/i18n.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/inet_aton.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/init.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/inline.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/ioext.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/keywords.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/lang.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/list.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/load.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/macros.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/mallocs.c
        #        memmove.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/mkstemp.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/modules.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/net_db.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/null-threads.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/numbers.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/objects.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/objprop.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/options.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/pairs.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/ports.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/posix.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/print.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/procprop.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/procs.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/properties.c
        #        putenv.c
        #        quicksort.i.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/ramap.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/random.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/rdelim.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/read.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/regex-posix.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/root.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/rw.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/scmsigs.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/script.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/simpos.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/smob.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/socket.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/sort.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/srcprop.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/srfi-13.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/srfi-14.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/srfi-4.c
        #        srfi-4.i.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/stackchk.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/stacks.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/stime.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/strerror.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/strings.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/strorder.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/strports.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/struct.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/symbols.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/threads.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/throw.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/unif.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/values.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/variable.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/vectors.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/version.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/vports.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/weaks.c

        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/eval.cpp


        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/mini-gmp.c
        ${CMAKE_CURRENT_SOURCE_DIR}/libguile/mini-mpq.c

        ${CMAKE_CURRENT_SOURCE_DIR}/test-suite/test-asmobs-lib.c
        )
if (WIN32)
    target_sources(guile PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/libguile/win32-dirent.c
            ${CMAKE_CURRENT_SOURCE_DIR}/libguile/win32-socket.c
            ${CMAKE_CURRENT_SOURCE_DIR}/libguile/win32-uname.c
            )
endif ()
target_include_directories(guile PRIVATE ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(guile PUBLIC Threads::Threads)

# use O0
target_compile_options(guile PUBLIC -O0)

# Add executable
add_executable(guileinterpreter libguile/guile.c)

set_target_properties(guileinterpreter PROPERTIES OUTPUT_NAME "guile")

target_link_libraries(guileinterpreter PUBLIC guile)

# Fix undefined reference to `__imp_WSAGetLastError' with mingw
if (MINGW)
    target_link_libraries(guile PUBLIC ws2_32)
endif ()

# if we have regex, link it
find_library(regex regex)
if (regex)
    target_compile_definitions(guile PUBLIC HAVE_REGCOMP)
    target_link_libraries(guile PUBLIC regex)
endif ()

# if we have dl, link it
find_library(dl dl)
if (dl)
    target_link_libraries(guile PUBLIC dl)
endif ()

find_package(Intl)
if (Intl_FOUND)
    target_compile_definitions(guile PUBLIC HAVE_INTL)
    target_link_libraries(guile PUBLIC Intl::Intl)
    target_compile_definitions(guile PUBLIC HAVE_INTL)
endif ()

find_package(Ltdl)
if (Ltdl_FOUND)
    target_compile_definitions(guile PUBLIC HAVE_LTDL)
    target_link_libraries(guile PUBLIC Ltdl::Ltdl)
    target_compile_definitions(guile PUBLIC HAVE_LTDL)
endif ()


### Tests

# The directory test-suite/tests contains a bunch of test files
enable_testing()
# For each test file, run guileinterpreter with the test file as input
file(GLOB TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/test-suite/tests/*.test)
foreach (test_file ${TEST_FILES})
    get_filename_component(test_name ${test_file} NAME_WE)
    add_test(NAME ${test_name}
            COMMAND ${CMAKE_CURRENT_BINARY_DIR}/guile -e main -s guile-test ${test_name}.test
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/test-suite
    )
endforeach ()

# find sh
find_program(SH sh /bin /usr/bin /usr/local/bin C:/msys64/usr/bin C:/tools/msys64/usr/bin)

file(GLOB TEST_FILES_STANDARD ${CMAKE_CURRENT_SOURCE_DIR}/test-suite/standalone/*)
foreach (test_file ${TEST_FILES_STANDARD})
    get_filename_component(test_name ${test_file} NAME_WE)
    # if the file end with .in, continue
    if (test_file MATCHES ".in$")
        continue()
    endif ()
    # if the file start with test-
    if (NOT test_name MATCHES "test-")
        continue()
    endif ()
    # if the file does not end with .c, this means its a shell script
    if (NOT test_file MATCHES ".c$")
        add_test(NAME ${test_name}
                COMMAND ${SH} ${test_file}
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        )
        continue()
    endif ()
    # build the test file
    add_executable(${test_name} ${test_file})
    target_link_libraries(${test_name} PUBLIC guile)
    # run the test file
    add_test(NAME ${test_name}
            COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${test_name}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
endforeach ()


### Interpreter
# An option to enable the qt gui
option(GUILE_ENABLE_QTGUI OFF)
if (GUILE_ENABLE_QTGUI)
    add_subdirectory(qguile)
endif ()

# Specify installation paths
include(GNUInstallDirs)

# Install the library
install(TARGETS guile
    EXPORT guile_liza-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Install header files
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/libguile/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/libguile
    FILES_MATCHING PATTERN "*.h"
)

# Install libguile.h
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/libguile.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Install guile-config, guile-snarf, and guile-tools from ./tools to bin directory
install(PROGRAMS ${CMAKE_CURRENT_SOURCE_DIR}/tools/guile-config
    DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(PROGRAMS ${CMAKE_CURRENT_SOURCE_DIR}/tools/guile-snarf
    DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(PROGRAMS ${CMAKE_CURRENT_SOURCE_DIR}/tools/guile-tools
    DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Install guileinterpreter as bin/guile
install(TARGETS guileinterpreter
    DESTINATION ${CMAKE_INSTALL_BINDIR}
    RENAME guile
)

# Install the directory ice-9 to share/guile/1.8
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ice-9
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/guile/1.8
)

# Export targets for use by downstream projects
install(EXPORT guile_liza-targets
    FILE guile_liza-targets.cmake
    NAMESPACE guile_liza::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/guile_liza
)

# Create and install a package configuration file
include(CMakePackageConfigHelpers)
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/guile_liza-config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/guile_liza-config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/guile_liza
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/guile_liza-config.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/guile_liza
)
