cmake_minimum_required(VERSION 3.15)

# Set the name of the module
set(MODULE_NAME lcd)

# Specify the source files for this module
set(SOURCES
    LCD_program.c
    LCD_private.h
    LCD_interface.h
    LCD_config.h
)

# Create a library target for this module
add_library(${MODULE_NAME} ${SOURCES})

# Add any necessary include directories here
target_include_directories(${MODULE_NAME} PUBLIC .)
