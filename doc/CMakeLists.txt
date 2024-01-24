cmake_minimum_required(VERSION 3.16)

# list all texi files
file(GLOB_RECURSE TEXI_FILES *.texi)

# make all texi with makeinfo
find_program(MAKEINFO makeinfo)

if(NOT MAKEINFO)
  message(FATAL_ERROR "makeinfo not found")
endif()

# create a target to build all texi files
add_custom_target(
  texi
  COMMAND ${MAKEINFO} --no-split ${TEXI_FILES}
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMENT "Building texi files"
  VERBATIM
)