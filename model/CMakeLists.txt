CMAKE_MINIMUM_REQUIRED(VERSION 3.19)

add_library(curves SHARED
        Base.h
        Circle.h
        Ellipse.h
        Helix.h
        )

set_target_properties(curves PROPERTIES LINKER_LANGUAGE CXX)