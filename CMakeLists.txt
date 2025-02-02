CMAKE_MINIMUM_REQUIRED(VERSION 3.11)
PROJECT(astar)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_VERBOSE_MAKEFILE OFF)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

ADD_LIBRARY(astar
    ${PROJECT_SOURCE_DIR}/src/Model.cpp
    ${PROJECT_SOURCE_DIR}/src/Util.cpp
)

TARGET_INCLUDE_DIRECTORIES(astar
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/third_party/googletest
)

# ADD_COMPILE_OPTIONS("-fsanitize=address")
# LINK_LIBRARIES("-fsanitize=address")
SET(CMAKE_BUILD_TYPE "Release")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
# SET(CMAKE_BUILD_TYPE "Debug")
# SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g3 -ggdb")

# ADD_EXECUTABLE(random_case_run ${PROJECT_SOURCE_DIR}/tests/random_case_run.cpp)
# TARGET_LINK_LIBRARIES(random_case_run astar)

# ADD_EXECUTABLE(test_astar ${PROJECT_SOURCE_DIR}/tests/test_astar.cpp)
# LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/third_party/googletest)
# TARGET_LINK_LIBRARIES(test_astar libgtest.a libgtest_main.a pthread astar)




