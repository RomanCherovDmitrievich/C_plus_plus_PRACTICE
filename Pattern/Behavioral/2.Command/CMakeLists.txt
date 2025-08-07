cmake_minimum_required(VERSION 3.10)
project(Behavioral)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable (Command
  ${CMAKE_CURRENT_SOURCE_DIR}/Command.cpp # Явный путь
)

set_target_properties(Command PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug/bin
)

set_property(TARGET Command PROPERTY COMPILE_WARNING_AS_ERROR ON)

if(MSVC)
  target_compile_options(Command PRIVATE /W4 /WX)
else()
  target_compile_options(Command PRIVATE -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference)
endif()

