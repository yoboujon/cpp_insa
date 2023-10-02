echo off
cmake --build build --target %1
cd build/Debug
%1.exe
cd ../..