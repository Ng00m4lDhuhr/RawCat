#!/bin/bash
# -x sets language to C++
#          -o output the compiled code to a file named rawcat
#                    -I include the rawcat header files
# 				   files to compile
g++ -x c++ -o rawcat -I ./include/ src/main.cpp src/rawcat.cpp
