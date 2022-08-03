# wizlightcpp

## Project Overview
A cpp application to manage and control the [Wiz](https://www.wizconnected.com/en-us) light devices. wizlightcpp is licensed under the MIT license; see LICENSE in the source distribution for details.

## About Wiz
WiZ is an IoT platform for smart lighting solutions and smart services. WiZ delivers a Wi-Fi-based smart system that controls plug & play devices with our user-friendly and feature-rich app, and that connects to existing Wi-Fi networks. It also provides ways to dynamic change the light color. [Source](https://www.wizconnected.com/en-us/about-wiz)

## Prerequisites
Before building, you'll need to install following dependencies

    cmake
    libjansson-dev

## Building
wizlightcpp should work with any Linux distribution and added cross compilation support.

    Tested on:
        X86_64
        Arm
        
### Checking out the wizlightcpp
To check out the wizlightcpp repository:

    git clone https://github.com/sribalajism/wizlightcpp.git
    
### Build
Use cmake tools to build the wizlightcpp. Run the following commands to build:

    mkdir build
    cd build
    cmake ..
    
### Cross Compilation
In order to cross compile this module, use the cmake-tookchains file available in the [toolchain](https://github.com/sribalajism/wizlightcpp/tree/master/cmake/toolchain) directory. Update the arm_toolchain.cmake file with your toolchain details. Refer the sample version in this [example](https://github.com/sribalajism/wizlightcpp/tree/master/cmake/toolchain/example).
To cross-compile, run the following commands:

    mkdir build_arm
    cd build_arm
    cmake  -DCMAKE_TOOLCHAIN_FILE=<path_to_toolchain_cmake_file>/arm_toolchain.cmake ..
        
## Supported Features
Following features are supported now:

    Toggle light
    Get Status
    Get Device Info
    Reboot
    Get User Configuration
    Get Wifi Configuration
    Get System Configuration
