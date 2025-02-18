cmake_minimum_required(VERSION 3.28)
project(Fractal)

set(CMAKE_CXX_STANDARD 26)

add_executable(Fractal main.cpp
        BitmapFileHeader.h
        BitmapInfoHeader.h
        Bitmap.cpp
        Bitmap.h
        Mandelbrot.cpp
        Mandelbrot.h)
