cmake_minimum_required(VERSION 3.6)
project(data_structures_practice)

set(CMAKE_CXX_STANDARD 11)

# ds
set(DS_DIR ds)
set(DS_HEADER_DIR ${DS_DIR}/include)
add_subdirectory(${DS_DIR})

# googletest
set(GOOGLE_TEST_DIR googletest)
set(GOOGLE_TEST_HEADER_DIRS
        ${GOOGLE_TEST_DIR}/googletest/include
        ${GOOGLE_TEST_DIR}/googlemock/include)
add_subdirectory(${GOOGLE_TEST_DIR})

set(SOURCE_FILES gtest-stack-tests.cpp gtest-binary-tree-tests.cpp gtest-stack-expression-validator-tests.cpp)
add_executable(data_structures_practice ${SOURCE_FILES})
target_link_libraries(data_structures_practice ds gtest gtest_main)
include_directories(
        ${DS_HEADER_DIR}
        ${GOOGLE_TEST_HEADER_DIRS})