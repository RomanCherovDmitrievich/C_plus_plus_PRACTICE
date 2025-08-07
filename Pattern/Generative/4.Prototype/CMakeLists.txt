cmake_minimum_required(VERSION 3.10)
project(Generative)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable (Prototype
  ${CMAKE_CURRENT_SOURCE_DIR}/Prototype.cpp # Явный путь
)

set_target_properties(Prototype PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug/bin
)

set_property(TARGET Prototype PROPERTY COMPILE_WARNING_AS_ERROR ON)

if(MSVC)
  target_compile_options(Prototype PRIVATE /W4 /WX)
else()
  target_compile_options(Prototype PRIVATE -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference)
endif()

