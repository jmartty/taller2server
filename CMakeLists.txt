cmake_minimum_required(VERSION 2.8)

# Project define
project(server)
enable_testing()

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
include_directories(libs/rocksdb/include libs/jsoncpp libs/mongoose)

# Execs
add_executable(server ${SERVER_SRC} ${MODULES_SRC})
add_definitions(-std=c++11 -Wall)

# Libraries
# rocksdb
add_library(rocksdb SHARED IMPORTED)
set_target_properties(rocksdb PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/rocksdb/librocksdb.a)
target_link_libraries(server rocksdb pthread rt snappy gflags z bz2)

# Build
install(TARGETS server DESTINATION bin)
