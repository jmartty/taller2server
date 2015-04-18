cmake_minimum_required(VERSION 2.8)

project(server)
enable_testing()

file(GLOB MODULES_SRC 
	"modules/*.h"
	"modules/*.cpp"
)

file(GLOB SERVER_SRC
	"src/*.h"
	"src/*.cpp"
)

add_executable(server ${SERVER_SRC} ${MODULES_SRC})
add_definitions(-std=c++11 -Wall)

install(TARGETS server DESTINATION bin)
