# CMakeLists.txt
# https://learn.microsoft.com/en-us/cpp/build/customize-cmake-settings?view=msvc-170
# https://stackoverflow.com/questions/76268455/how-to-use-cmake-to-build-a-project-with-c23-standard-library-moduleimport-st
# https://stackoverflow.com/questions/64889383/how-to-enable-stdclatest-in-cmake
# https://stackoverflow.com/questions/57300495/how-to-use-c20-modules-with-cmake
# https://www.kitware.com/import-std-in-cmake-3-30/
#
# NOTE THE USE OF "cmakeExecutable": "A:\\Program Files\\CMake\\bin\\cmake.exe" in CMakePresets.json
#
cmake_minimum_required(VERSION 4.0.3) # 4.0.2 is broken

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_MODULE_STD ON)
set(CMAKE_CXX_STANDARD 23)
project(BasicModule)

set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS ON)

# Collect all .ixx submodules from submodules/
file(GLOB SUBMODULE_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/submodules/*.ixx")

add_executable(BasicModule)
target_sources(BasicModule
        PRIVATE
        main.cpp
        PUBLIC
        FILE_SET cxx_modules TYPE CXX_MODULES FILES
        testmodule.ixx 
        a.cppm
        ${SUBMODULE_SOURCES}
)
