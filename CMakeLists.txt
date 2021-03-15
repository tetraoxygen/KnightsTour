cmake_minimum_required(VERSION 3.16)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(knights_tour)

add_executable(knights_tour src/main.cpp)

set_property(TARGET knights_tour PROPERTY CXX_STANDARD 14)

install(TARGETS knights_tour)

IF (WIN32 AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	target_link_libraries(knights_tour -static)
ENDIF()