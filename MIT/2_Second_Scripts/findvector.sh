#!/usr/bin/bash

find . -type f -name "*.cpp" -exec grep -l "#include <vector>" {} +
