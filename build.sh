#!/bin/sh

set -ex

mkdir -p bin

cc -Wall -Wextra -o bin/rlgl src/main.c src/colors.c src/window.c -lraylib -lm

cd bin

# copy all fragment and vertex shaders to bin
cp ../shaders/*.frag .
cp ../shaders/*.vert .

