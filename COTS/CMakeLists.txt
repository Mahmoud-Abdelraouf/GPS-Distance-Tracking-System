# Set minimum version of CMake
cmake_minimum_required(VERSION 3.15)

# Set the project name and version
project(Embedded-GPS VERSION 1.0)

# Set the path to the compiler toolchain file
set(CMAKE_TOOLCHAIN_FILE "/usr/bin/arm-none-eabi-gcc.cmake")

# Add directories containing source files
add_subdirectory(01-MCAL/01-DIO)
add_subdirectory(01-MCAL/02-STK)
add_subdirectory(01-MCAL/03-UART)
add_subdirectory(02-HAL/01-LCD)
add_subdirectory(02-HAL/02-LED)
add_subdirectory(02-HAL/03-GPS)
add_subdirectory(04-APP)
add_subdirectory(05-LIB)

# Add executable target
add_executable(${PROJECT_NAME}.elf 04-APP/main.c)

# Link all libraries and object files
target_link_libraries(${PROJECT_NAME}.elf
    01-MCAL/01-DIO 01-MCAL/02-STK 01-MCAL/03-UART 02-HAL/01-LCD
    02-HAL/01-LCD 02-HAL/02-LED 02-HAL/03-GPS 03-SERVICE 04-APP 05-LIB
)

# Set linker options
set_target_properties(${PROJECT_NAME}.elf PROPERTIES
    LINK_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${CMAKE_CURRENT_SOURCE_DIR}/linker_script.ld"
)

# Create hex file
add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
)
