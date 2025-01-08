# set minimum required version of cmake to avoid errors
cmake_minimum_required(VERSION 3.22)

# project name + defining used languages
project(TEMP C) 

# collect library source files
file(GLOB_RECURSE ${PROJECT_NAME}_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

# defining include dir for library
set(${PROJECT_NAME}_INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/inc/")

# create a static library
add_library(${PROJECT_NAME} SHARED "${${PROJECT_NAME}_SRC_FILES}")

# in order to allow main to use .h -> make it interface
target_include_directories(${PROJECT_NAME} PUBLIC "${${PROJECT_NAME}_INC_DIR}")