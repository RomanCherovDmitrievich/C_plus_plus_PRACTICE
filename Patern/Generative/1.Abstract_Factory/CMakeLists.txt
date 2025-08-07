cmake_minimum_required(VERSION 3.10)
project(SOLID)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable (Abstract_Factory
  ${CMAKE_CURRENT_SOURCE_DIR}/Abstract_Factory.cpp # Явный путь
)

set_target_properties(Abstract_Factory PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug/bin
)

set_property(TARGET Abstract_Factory PROPERTY COMPILE_WARNING_AS_ERROR ON)

if(MSVC)
  target_compile_options(Abstract_Factory PRIVATE /W4 /WX)
else()
  target_compile_options(Abstract_Factory PRIVATE -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference)
endif()

