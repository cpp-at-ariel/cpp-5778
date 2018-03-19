# A generic makefile for running single-file C++ projects.
#
# AUTHOR: Erel Segal-Halevi

CXX=clang++-5.0
RM=rm -f
CPPFLAGS=-std=c++17 
VALGRIND_FLAGS=
# VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all

ifndef MAIN
  MAIN=./main.cpp
endif

MAINEXECUTABLE=$(subst .cpp,,$(MAIN)).exe

SOURCES=$(MAIN)

all: $(MAINEXECUTABLE)
	valgrind --tool=memcheck $(VALGRIND_FLAGS) $(MAINEXECUTABLE)

$(MAINEXECUTABLE): $(SOURCES)
	$(CXX) $(CPPFLAGS) $(SOURCES) -o $(MAINEXECUTABLE)

clean:
	$(RM) *.exe a.out
