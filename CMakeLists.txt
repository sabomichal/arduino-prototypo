#=============================================================================#
# Author: QueezyTheGreat                                                      #
# Date:   26.04.2011                                                          #
#                                                                             #
# Description: Arduino CMake example                                          #
#                                                                             #
#=============================================================================#
set(ARDUINO_SDK_PATH "D:/bin/Arduino")
set(ARDUINO_CXX_FLAGS "${ARDUINO_C_FLAGS} -fno-threadsafe-statics -fno-exceptions")

#set(CMAKE_VERBOSE_MAKEFILE True)
set(CMAKE_TOOLCHAIN_FILE cmake/ArduinoToolchain.cmake)
set(CMAKE_CXX_STANDARD 14)

cmake_minimum_required(VERSION 2.8)

#====================================================================#
#  Setup Project                                                     #
#====================================================================#
project(ArduinoExample C CXX ASM)

add_definitions(-DARDUINO_ARCH_AVR=1)
set(ARDUINO_DEFAULT_BOARD micro) # Default Board ID, when not specified
set(ARDUINO_DEFAULT_PORT com4) # Default Port, when not specified

print_board_list()
print_programmer_list()

add_subdirectory(prototypo)   #add the example directory into build