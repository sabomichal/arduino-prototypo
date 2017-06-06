#====================================================================#
#  Dependencies                                                      #
#====================================================================#
set(Servo_RECURSE True)
set(Ultrasonic_RECURSE True)
#include_directories(${CMAKE_SOURCE_DIR}/libraries)
link_directories(${CMAKE_SOURCE_DIR}/libraries)
#link_directories(${ARDUINO_SDK}/libraries)

#====================================================================#
# IRobot static library
#====================================================================#
generate_arduino_library(carbot_lib
        SRCS CarBot.cpp
        HDRS CarBot.h IRobot.h)

#====================================================================#
# CarBot firmware
#====================================================================#
generate_arduino_firmware(carbot
        SRCS main.cpp
        LIBS carbot_lib
        ARDLIBS Ultrasonic Servo)
