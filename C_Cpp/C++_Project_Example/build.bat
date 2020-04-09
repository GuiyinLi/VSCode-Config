@echo off
cd .\build
cmake -G "MinGW Makefiles" .. > TriffleInfo
minGW32-make
