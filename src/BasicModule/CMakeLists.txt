# CMakeLists.txt
# https://learn.microsoft.com/en-us/cpp/build/customize-cmake-settings?view=msvc-170
# https://stackoverflow.com/questions/76268455/how-to-use-cmake-to-build-a-project-with-c23-standard-library-moduleimport-st
# https://stackoverflow.com/questions/64889383/how-to-enable-stdclatest-in-cmake
# https://stackoverflow.com/questions/57300495/how-to-use-c20-modules-with-cmake
# https://www.kitware.com/import-std-in-cmake-3-30/
#
# NOTE THE USE OF "cmakeExecutable": "A:\\Program Files\\CMake\\bin\\cmake.exe" in CMakePresets.json
#
cmake_minimum_required(VERSION 3.29)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "0e5b6991-d74f-4b3d-a41c-cf096e0b2508") 
project(modules-example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_MODULE_STD 1)

add_executable(demo)
target_sources(demo
    PUBLIC
    main.cpp
)
target_sources(demo
  PUBLIC
    FILE_SET all_my_modules TYPE CXX_MODULES FILES
    a.cppm
)
target_compile_features(demo PRIVATE cxx_std_23) 
