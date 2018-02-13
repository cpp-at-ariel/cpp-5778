MAINNAME= init_demo

#########################################################
# compiler stuff 
#########################################################
CXX= clang++-5.0
CXXFLAGS=-std=c++17 $(CFLAGS) -g -D_GLIBCXX_DEBUG -Wall -Wvla #-Werror

CEXELINKFLAGS=
CXXTESTLINKFLAGS= -lgtest -lgtest_main -pthread
##########################################################


##########################################################
# sources files
##########################################################
SRCSEXENOMAIN= C.cpp
SRCSEXEMAIN= $(MAINNAME).cpp
##########################################################


#######################
# executables name
#######################
EXE= $(MAINNAME)
#######################


#########################################################
# actions
#########################################################
all: $(EXE)
	./$(MAINNAME)

$(EXE): $(subst .cpp,.o,$(SRCSEXENOMAIN)) $(subst .cpp,.o,$(SRCSEXEMAIN)) 
	$(CXX) $(CFLAGS) $(CEXELINKFLAGS) $^ -o $@

clean:
	rm *.o $(EXE) -f

depend: $(SRCSEXENOMAIN) $(SRCSEXEMAIN) 
	makedepend -Y -- $(CXXFLAGS) -- $^

##############################################
# installs that should be done once
##############################################
installonce: gtestinstall makedependinstall valgrindinstall

gtestinstall: 
	sudo apt-get install libgtest-dev
	sudo apt-get install cmake
	cd /usr/src/gtest; \
	sudo cmake CMakeLists.txt; \
	sudo make; \
	sudo cp *.a /usr/lib
	sudo chmod u+r /usr/lib/libgtest.a
	sudo chmod u+r /usr/lib/libgtest_main.a

makedependinstall:
	sudo apt-get install xutils-dev

valgrindinstall:
	sudo apt-get install valgrind
##############################################

.PHONY: all clean depend installonce gtestinstall makedependinstall valgrindinstall


# DO NOT DELETE THIS LINE -- make depend depends on it.

C.o: C.hpp
init_demo.o: C.hpp
