cmake_minimum_required(VERSION 2.8)

project(DoxyFiller)

set(CMAKE_INCLUDE_CURRENT_DIR ON) # Разрешаем работу с собственной папкой

set(FILE_STRUCTURE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/FileStructure)

include_directories(
    ${FILE_STRUCTURE_PATH}
    )

file(GLOB_RECURSE SRC_H
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
    ${FILE_STRUCTURE_PATH}/*.h
    )

file(GLOB_RECURSE SRC_CPP
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${FILE_STRUCTURE_PATH}/*.cpp
    )

add_executable(${PROJECT_NAME} WIN32 ${SRC_H} ${SRC_CPP})
