cmake_minimum_required(VERSION 4.0.3) # 4.0.2 is broken

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_MODULE_STD ON)
set(CMAKE_CXX_STANDARD 23)
project(test)

set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS ON)

# Collect all .ixx submodules from submodules/
file(GLOB SUBMODULE_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/submodules/*.ixx")
add_executable(test)
add_subdirectory(submodules2)
target_sources(test
        PRIVATE
        main.cpp
        PUBLIC
        FILE_SET cxx_modules TYPE CXX_MODULES FILES
        testmodule.ixx
        ${SUBMODULE_SOURCES}
        ${SUBMODULE_SOURCES2}
)

