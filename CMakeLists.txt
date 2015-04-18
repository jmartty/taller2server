cmake_minimum_required(VERSION 2.8)

# Project define
project(server C CXX)

# Source files
file(GLOB MODULES_SRC 
	"modules/*.h"
	"modules/*.cpp"
)

file(GLOB SERVER_SRC
	"src/*.h"
	"src/*.cpp"
)

# Includes
include_directories(libs/rocksdb/include libs/jsoncpp libs/mongoose modules)

# Execs
add_executable(server ${SERVER_SRC} ${MODULES_SRC})
add_definitions(-std=c++11 -Wall)

# Libraries
# rocksdb
add_library(rocksdb SHARED IMPORTED)
set_target_properties(rocksdb PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/libs/rocksdb/librocksdb.a)
target_link_libraries(server rocksdb pthread rt snappy gflags z bz2)

# Incluimos la parte de testing
enable_testing()
include(CTest)

set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)
set(CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage -g -O0 --coverage ${CMAKE_CXX_FLAGS}")

add_subdirectory(tests)

# Build
install(TARGETS server DESTINATION bin)
