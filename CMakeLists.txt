cmake_minimum_required(VERSION 2.8)

project(DoxyFiller)
include_directories(FileStructure/)
set(SRC tdirtreeviewer.cpp tbriefcppfilder.cpp FileStructure/tclassinfo.cpp FileStructure/tfunctioninfo.cpp advancedstringfunctions.cpp FileStructure/tsourcefile.cpp)
add_executable(${PROJECT_NAME} "main.cpp" ${SRC})
