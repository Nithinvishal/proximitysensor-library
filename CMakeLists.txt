cmake_minimum_required(VERSION 3.13)

# Set C and C++ standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Board type
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(proximitysensor C CXX ASM)

# Initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# Add source files
add_executable(proximitysensor
    proximitysensor.c
    vcnl4040.cpp
)

# Enable USB output (for printf)
pico_enable_stdio_usb(proximitysensor 1)
pico_enable_stdio_uart(proximitysensor 0)

# Link libraries
target_link_libraries(proximitysensor
    pico_stdlib
    hardware_i2c
)

# Include current folder for headers
target_include_directories(proximitysensor PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Create .uf2 and .bin files
pico_add_extra_outputs(proximitysensor)
