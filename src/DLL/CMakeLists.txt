# See https://gitlab.kitware.com/cmake/community/-/wikis/doc/tutorials/BuildingWinDLL
# See https://computingonplains.wordpress.com/building-c-applications-with-cmake-and-visual-studio-code/
cmake_minimum_required(VERSION 3.20)

project(ProjectName) # becomes the SLN name

include (GenerateExportHeader)

list(APPEND source_list source.hpp source.cpp)
add_library(MyLibrary SHARED ${source_list})
# can also do: add_library(MyLibrary SHARED source.hpp source.cpp)

# See https://cmake.org/cmake/help/latest/module/GenerateExportHeader.html
GENERATE_EXPORT_HEADER(
    MyLibrary
    BASE_NAME MyLibrary # becomes the DLL name
    EXPORT_MACRO_NAME MyLibrary_EXPORT
    EXPORT_FILE_NAME MyLibrary_Export.h
)

add_compile_definitions(BLAH=1) #define macro
add_definitions(/FI"build/MyLibrary_Export.h") #include this file in all translation units
target_compile_features(MyLibrary PUBLIC cxx_std_20)