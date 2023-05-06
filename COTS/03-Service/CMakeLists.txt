cmake_minimum_required(VERSION 3.15)

# Set the name of the module
set(MODULE_NAME service)

# Specify the source files for this module
set(SOURCES
	TM4C123GH6PM.h
)

# Create a library target for this module
add_library(${MODULE_NAME} ${SOURCES})

# Add any necessary include directories here
target_include_directories(${MODULE_NAME} PUBLIC .)
