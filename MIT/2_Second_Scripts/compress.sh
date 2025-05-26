#!/usr/bin/bash

find "$1" -type f -name "*.cpp" -exec zip -j cpp_files.zip {} +


