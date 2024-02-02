CMAKE_MINIMUM_REQUIRED(VERSION 3.19)

add_library(curves INTERFACE
        Base.h
        Circle.h)

set_target_properties(curves PROPERTIES LINKER_LANGUAGE CXX)