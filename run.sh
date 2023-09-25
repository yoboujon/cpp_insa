#!/bin/bash

# check target name cmake
#return an error if not successful
if [ $# -eq 0 ]; then
  echo "Usage: $0 <target_name>"
  exit 1
fi

target_name="$1"
cmake --build build --target "$target_name"
"./build/$target_name"