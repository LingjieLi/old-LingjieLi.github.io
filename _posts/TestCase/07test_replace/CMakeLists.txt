cmake_minimum_required(VERSION 3.0.0)
project(testReplace VERSION 0.1.0)

include(CTest)
enable_testing()

set(EXECUTABLE_OUTPUT_PATH,${PROJECT_BINARY_DIR}/../bin)
add_executable(testReplace.o main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
