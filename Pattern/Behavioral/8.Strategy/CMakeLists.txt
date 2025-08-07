cmake_minimum_required(VERSION 3.10)
project(SOLID)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable (Strategy
  ${CMAKE_CURRENT_SOURCE_DIR}/Strategy.cpp # Явный путь
)

set_target_properties(Strategy PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug/bin
)

set_property(TARGET Strategy PROPERTY COMPILE_WARNING_AS_ERROR ON)

if(MSVC)
  target_compile_options(Strategy PRIVATE /W4 /WX)
else()
  target_compile_options(Strategy PRIVATE -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference)
endif()

