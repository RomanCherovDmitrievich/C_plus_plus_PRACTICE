cmake_minimum_required(VERSION 3.10)
project(Behavioral)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable (Template_Method
  ${CMAKE_CURRENT_SOURCE_DIR}/Template_Method.cpp # Явный путь
)

set_target_properties(Template_Method PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug/bin
)

set_property(TARGET Template_Method PROPERTY COMPILE_WARNING_AS_ERROR ON)

if(MSVC)
  target_compile_options(Template_Method PRIVATE /W4 /WX)
else()
  target_compile_options(Template_Method PRIVATE -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference)
endif()

