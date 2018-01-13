cmake_minimum_required(VERSION 3.2)
project(examples)

set(CMAKE_CXX_STANDARD 11)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

add_executable(header header.cpp)
target_link_libraries(header ${CURL_LIBRARIES})

add_executable(multipart-formpost multipart-formpost.cpp)
target_link_libraries(multipart-formpost ${CURL_LIBRARIES})

add_executable(simple simple.cpp)
target_link_libraries(simple ${CURL_LIBRARIES})
