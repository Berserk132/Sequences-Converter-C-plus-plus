cmake_minimum_required(VERSION 3.12)
project(DNA)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DNA
        DNA.cpp
        DNA.h
        main.cpp
        Protein.cpp
        Protein.h
        RNA.cpp
        RNA.h
        Sequence.cpp
        Sequence.h)
