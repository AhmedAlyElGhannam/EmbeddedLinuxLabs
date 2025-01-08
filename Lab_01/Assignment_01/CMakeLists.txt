# set minimum required version of cmake to avoid errors
cmake_minimum_required(VERSION 3.22)

# project name + defining used languages 
project(LOG_UNIT_CONV C)

# collect all .c files
file(GLOB ${PROJECT_NAME}_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.c)

# defining a list of MCAL libraries that will be used to build HAL libraries
set(LOG_VALS
	TEMP
	#PRESSURE	
)

# looping over all libs to build them
foreach(log_val ${LOG_VALS})
	add_subdirectory(
	    "${CMAKE_CURRENT_SOURCE_DIR}/${log_val}/"
	    "${CMAKE_BINARY_DIR}/${log_val}/"
	)
endforeach()

# setting compiler flags for C
add_compile_options(-Wall -Os -g)

# compiling and getting .elf file
add_executable(${PROJECT_NAME}.elf "${${PROJECT_NAME}_SRC_FILES}") # main target
target_link_libraries(${PROJECT_NAME}.elf PRIVATE ${LOG_VALS})