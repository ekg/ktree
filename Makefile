# options
CC = g++
CXX						= g++
CFLAGS                          = -ffast-math -O9 -funroll-loops -DNDEBUG
#CFLAGS				= -O3 -fomit-frame-pointer -funroll-loops
CXXFLAGS			= -O3 -fomit-frame-pointer
CPPFLAGS			= -Wall
LDFLAGS				= 
LDLIBS				= 
#TARGET_ARCH		=

# targets
.PHONY: all
all: ktree
ktree: ktree.o main.o
	$(CXX) ktree.o main.o -o ktree

distclean: clean
clean:
	$(RM) ktree ktree.o main.o

# dependencies
#kmertree: kmertree.cpp kmertree.hpp main.cpp Makefile
