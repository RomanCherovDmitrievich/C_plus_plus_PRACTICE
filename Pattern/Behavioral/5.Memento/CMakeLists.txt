cmake_minimum_required(VERSION 3.10)
project(Behavioral)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable (Memento
  ${CMAKE_CURRENT_SOURCE_DIR}/Memento.cpp # Явный путь
)

set_target_properties(Memento PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug/bin
)

set_property(TARGET Memento PROPERTY COMPILE_WARNING_AS_ERROR ON)

if(MSVC)
  target_compile_options(Memento PRIVATE /W4 /WX)
else()
  target_compile_options(Memento PRIVATE -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference)
endif()

