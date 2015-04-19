include(FindPkgConfig)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/modules)
set(GTEST_LIB "${PROJECT_SOURCE_DIR}/libs/gmock/gtest/libgtest.a")
set(GMOCK_LIB "${PROJECT_SOURCE_DIR}/libs/gmock/libgmock.a")

include_directories(${SRC_DIR} "${PROJECT_SOURCE_DIR}/libs/gmock/include" "${PROJECT_SOURCE_DIR}/libs/gmock/gtest/include")

file(GLOB MODULES_SRC
	"${PROJECT_SOURCE_DIR}/modules/*.h"
	"${PROJECT_SOURCE_DIR}/modules/*.cpp"
)

add_executable(testdatabase database/testsmain.cpp ${MODULES_SRC} "${PROJECT_SOURCE_DIR}/libs/mongoose/mongoose.c")

target_link_libraries(testdatabase ${GTEST_LIB})
target_link_libraries(testdatabase ${GMOCK_LIB})
target_link_libraries(testdatabase rocksdb pthread rt snappy gflags z bz2)

add_test(TestDatabase testdatabase)
