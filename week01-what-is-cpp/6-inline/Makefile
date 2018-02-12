CXX=clang++-5.0
CXXFLAGS=-std=c++17 --assemble -fno-asynchronous-unwind-tables -fno-dwarf2-cfi-asm

ifndef MAIN
  MAIN=./main.cpp
endif

all: 
	$(CXX) $(CXXFLAGS) $(MAIN)
