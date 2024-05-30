cmake_minimum_required(VERSION 3.16)

set(NAME OverloadingInsertionOperator)

project(${NAME} LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)

file(GLOB_RECURSE PROJECT_SOURCES 
    ${PROJECT_SOURCE_DIR}/src/*.cpp 
    ${PROJECT_SOURCE_DIR}/src/*.hpp
    ${PROJECT_SOURCE_DIR}/src/*.tpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

# tests target #
# find_package(Catch2 3 REQUIRED)
# add_executable(tests tests/tests.cpp src/solution.cpp)
# target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)


