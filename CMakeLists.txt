cmake_minimum_required(VERSION 3.17.0 FATAL_ERROR)

project ("C++_PRACTICE" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

#Настройка для моего Mac OS
###############################################################33
#### Настройка путей для "stdlib.h"
if(APPLE AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # Полный набор путей для GCC на macOS
    set(GCC_INCLUDE_DIRS
        /opt/homebrew/Cellar/gcc/15.1.0/include/c++/15
        /opt/homebrew/Cellar/gcc/15.1.0/include/c++/15/aarch64-apple-darwin23
        /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include
        /usr/local/include
        /usr/include
    )
    
    # Добавляем как системные директории
    foreach(DIR ${GCC_INCLUDE_DIRS})
        if(EXISTS ${DIR})
            include_directories(SYSTEM ${DIR})
            add_compile_options(-isystem ${DIR})
        endif()
    endforeach()
    
    # Специфичные флаги для GCC
    add_compile_options(
        -Wno-implicit-function-declaration
        -D__STDC_WANT_LIB_EXT1__=0
    )
    
    # Пути для линковки
    link_directories(/opt/homebrew/Cellar/gcc/15.1.0/lib/gcc/15)
endif()

####### Настройка путей для  "_bonus.h"
if(APPLE AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # Отключаем проблемные системные заголовки
    add_compile_options(
        -D__STDC_WANT_LIB_EXT1__=0
        -isystem /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include
        -Wno-implicit-function-declaration
    )
    include_directories(
        /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include
    )
endif()
#######

if(APPLE)
    add_compile_options(-D__STDC_WANT_LIB_EXT1__=0)
    message(STATUS "Disabling __STDC_WANT_LIB_EXT1__ for MacOS build")
endif()

##########################################################################

# Настройки сборки файлов
if(MSVC)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})
  set(SHORT_RPATH "./")
  set(CMAKE_DOCUMENTS_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/Doc)
else()
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/bin)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/lib)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/lib)
  set(SHORT_RPATH "../lib")
  set(CMAKE_DOCUMENTS_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/doc)
endif()


#Настройка для библиотек
option(BUILD_SHARED_LIBS "Собирать динамические библиотеки" ON)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Output dir (bin): ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "Output dir (lib): ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")

#Настройка автотестов
option(AIRPORT_TESTING "Переменная, которая включает построение и запуск автотестов в момент сборки." ON)
option(AIRPORT_COVERAGE "Переменная, которая включает сбор метрик покрытия unit-тестами." ON)

#set(GTEST_VERSION "release-1.12.1" CACHE STRING "Google test version 1.12.1")
set(GTEST_VERSION "main" CACHE STRING "Google test main version")
enable_testing()

#Подключённые директории
add_subdirectory(Patern)
#add_subdirectory(SOLID)
#add_subdirectory(The_basics_of_OOP)
 
