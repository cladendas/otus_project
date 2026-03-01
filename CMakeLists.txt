cmake_minimum_required(VERSION 3.20)
project(logService CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost 1.71.0 REQUIRED COMPONENTS filesystem system json)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME}  ${SOURCES})

target_link_libraries(${PROJECT_NAME} Boost::filesystem Boost::system Boost::json)
