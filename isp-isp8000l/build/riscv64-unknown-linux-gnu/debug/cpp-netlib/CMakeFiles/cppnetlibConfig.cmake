# - Config file for the cppnetlib package
# It defines the following variables
#  CPPNETLIB_INCLUDE_DIRS - include directories for cppnetlib
#  CPPNETLIB_LIBRARIES    - libraries to link against
#  CPPNETLIB_EXECUTABLE   - the bar executable

# Compute paths
get_filename_component(CPPNETLIB_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(CPPNETLIB_INCLUDE_DIRS "${CPPNETLIB_CMAKE_DIR}/../../../include;/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/dist/riscv64-unknown-linux-gnu/debug/include")

# Our library dependencies (contains definitions for IMPORTED targets)
if(    NOT TARGET cppnetlib-client-connections
   AND NOT TARGET cppnetlib-server-parsers
   AND NOT TARGET cppnetlib-uri
   AND NOT CPPNETLIB_BINARY_DIR)
  include("${CPPNETLIB_CMAKE_DIR}/cppnetlibTargets.cmake")
endif()

# These are IMPORTED targets created by cppnetlibTargets.cmake
set(CPPNETLIB_LIBRARIES
    cppnetlib-client-connections
    cppnetlib-server-parsers
    cppnetlib-uri)
#set(CPPNETLIB_EXECUTABLE ...) # maybe the examples?
