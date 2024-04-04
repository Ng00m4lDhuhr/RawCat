#!/bin/bash
#   | sets language to C++
#   |      | output the compiled code to a file named rawcat
#   |      |         | include the rawcat header files
#   |      |         |             
g++ -x c++ -o rawcat -I ./include/ src/main.cpp src/rawcat.cpp
#                                  |            |
#                                  | source files to compile
