cmake_minimum_required(VERSION 3.10)
project(The_basics_of_OOP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable (Single_Responsibility_Principle
  ${CMAKE_CURRENT_SOURCE_DIR}/Single_Responsibility_Principle.cpp # Явный путь
)

set_target_properties(Single_Responsibility_Principle PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug/bin
)

set_property(TARGET Single_Responsibility_Principle PROPERTY COMPILE_WARNING_AS_ERROR ON)

if(MSVC)
  target_compile_options(Single_Responsibility_Principle PRIVATE /W4 /WX)
else()
  target_compile_options(Single_Responsibility_Principle PRIVATE -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference)
endif()

