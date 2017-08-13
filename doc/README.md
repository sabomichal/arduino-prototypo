## setup
- install cmake - https://cmake.org/download/
- install mingw (windows only) - https://sourceforge.net/projects/mingw/files/latest/download?source=files
- install arduino ide - https://www.arduino.cc/en/Main/Software
- set ARDUINO_SDK_PATH
- add mingw\bin to path

## build
```
mkdir cmake-build-debug
cd cmake-build-debug
cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - MinGW Makefiles" ..
cmake --build cmake-build-debug --target all -- -j 4
```

## TODO
- [non blocking ultrasonic](http://www.instructables.com/id/Non-blocking-Ultrasonic-Sensor-for-Arduino/)