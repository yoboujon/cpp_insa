echo off
cmake --build build
cd build/Debug
cpp_insa.exe
cd ../..