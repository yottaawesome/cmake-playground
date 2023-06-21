cmake_minimum_required(VERSION 3.20)

project(ProjectName) # becomes the SLN name

include (GenerateExportHeader)

#list(APPEND source_list source.hpp source.cpp)
add_library(MyLibrary SHARED source.hpp source.cpp)

GENERATE_EXPORT_HEADER(
    MyLibrary
    BASE_NAME MyLibrary # becomes the DLL name
    EXPORT_MACRO_NAME MyLibrary_EXPORT
    EXPORT_FILE_NAME MyLibrary_Export.h
)
