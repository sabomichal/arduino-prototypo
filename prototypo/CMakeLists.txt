#====================================================================#
#  Dependencies                                                      #
#====================================================================#
#set(Servo_RECURSE True)
#set(Ultrasonic_RECURSE True)
#set(VarSpeedServo_RECURSE True)
link_directories(${CMAKE_SOURCE_DIR}/libraries)

#====================================================================#
# CarBot static library
#====================================================================#
generate_arduino_library(carbot_lib
        SRCS Prototypo.cpp AutonomousStrategy.cpp
        HDRS Prototypo.h CarBot.h MovingStrategy.h AutonomousStrategy.h)

#====================================================================#
# Prototypo firmware
#====================================================================#
generate_arduino_firmware(carbot
        SRCS main.cpp
        LIBS carbot_lib
        ARDLIBS Ultrasonic VarSpeedServo)
