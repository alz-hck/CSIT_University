#!/bin/bash

find . -type f ! -name "*.cpp" -exec rm -f {} +
find . -type d -mindepth 1 -exec rm -rf {} +

