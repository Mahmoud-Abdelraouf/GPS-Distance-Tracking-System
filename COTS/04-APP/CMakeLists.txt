cmake_minimum_required(VERSION 3.15)

# Set the name of the module
set(MODULE_NAME main)

# Specify the source files for this module
set(SOURCES
	main.c main.h
)

add_subdirectory(../05-LIB bin/05-LIB)

# Create a library target for this module
add_library(${MODULE_NAME} ${SOURCES})

# Add any necessary include directories here
target_include_directories(${MODULE_NAME} PUBLIC .)
target_include_directories(${MODULE_NAME} PRIVATE ../05-LIB)
