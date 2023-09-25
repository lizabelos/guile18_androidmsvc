function(GenerateResourcesQRC)

    # Generate resources.qrc
    file(GLOB_RECURSE Guile_Resources "${CMAKE_CURRENT_SOURCE_DIR}/../ice-9/*")

    set(Guile_Resources_List "")

    # For each file
    foreach (Guile_Resource ${Guile_Resources})
        # Get the file name
        get_filename_component(Guile_Resource_Name ${Guile_Resource} NAME)
        # Get the file path
        get_filename_component(Guile_Resource_Path ${Guile_Resource} PATH)
        # Remove the path prefix
        string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}" "" Guile_Resource_Path ${Guile_Resource_Path})
        # Remove the ..
        string(REPLACE ".." "" Guile_Resource_Path ${Guile_Resource_Path})
        # Remove the leading / if any
        string(REGEX REPLACE "^/" "" Guile_Resource_Path ${Guile_Resource_Path})
        string(REGEX REPLACE "^/" "" Guile_Resource_Path ${Guile_Resource_Path})
        # Add the file to the resources
        # list(APPEND Guile_Resources_List "<file alias=\"${Guile_Resource_Path}/${Guile_Resource_Name}\">${Guile_Resource}</file>")
        set(Guile_Resources_List "${Guile_Resources_List}<file alias=\"${Guile_Resource_Path}/${Guile_Resource_Name}\">${Guile_Resource}</file>\n")
    endforeach ()

    # Generate the qrc file
    configure_file("${CMAKE_CURRENT_SOURCE_DIR}/resources.qrc.in" "${CMAKE_CURRENT_BINARY_DIR}/resources.qrc" @ONLY)

    # add the qrc to the texmacs target
    target_sources(qguile PUBLIC "${CMAKE_CURRENT_BINARY_DIR}/resources.qrc")

endfunction()



set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Default CMAKE_BUILD_TYPE is Debug
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

find_package(Qt6 COMPONENTS Core Gui Widgets QUIET)
if(NOT Qt6_FOUND)
      find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
      set(Qt_LIBS Qt5::Core Qt5::Gui Qt5::Widgets)
else()
      set(Qt_LIBS Qt6::Core Qt6::Gui Qt6::Widgets)
endif()

qt_add_executable(qguile main.cpp MainWindow.h)

target_link_libraries(qguile PRIVATE ${Qt_LIBS} guile)
GenerateResourcesQRC()