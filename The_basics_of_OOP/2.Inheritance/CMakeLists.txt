cmake_minimum_required(VERSION 3.10)
project(The_basics_of_OOP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable (ExampleInheritance
  ${CMAKE_CURRENT_SOURCE_DIR}/ExampleInheritance.cpp # Явный путь
)

set_target_properties(ExampleInheritance PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug/bin
)

set_property(TARGET ExampleInheritance PROPERTY COMPILE_WARNING_AS_ERROR ON)

if(MSVC)
  target_compile_options(ExampleInheritance PRIVATE /W4 /WX)
else()
  target_compile_options(ExampleInheritance PRIVATE -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference)
endif()

