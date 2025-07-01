cmake_minimum_required(VERSION 4.0.3)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_MODULE_STD ON)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
	set(CXXFLAGS "--stdlib=libc++")
	set(CMAKE_CXX_COMPILER_CLANG_SCAN_DEPS:FILEPATH "/usr/bin/clang-scan-deps")
endif()

project("example"
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS ON)

add_executable(main main.cpp)
