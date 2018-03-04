CC = gcc
CXX = g++
RM = rm -f
NEWLINE = echo \n
CPPFLAGS= -g -std=gnu++11
LDFLAGS=-g -std=gnu++11
#LDLIBS=$(shell root-config --libs)
OUTPUT=p3

#PROG = algorithms/human/*.cpp algorithms/minimax/*.cpp algorithms/minimax/heuristic_functions/*.cpp algorithms/minimax/successor_functions/*.cpp game/*.cpp player/*.cpp src/*.cpp algorithms/minimax/hash_tables/*.cpp
PROG = $(wildcard */*.cpp) $(wildcard */*/*.cpp) $(wildcard */*/*/*.cpp)
OBJS=$(subst .cc,.o,$(PROG))

all: prog

prog: $(OBJS)
		$(NEWLINE)
		$(CXX) $(LDFLAGS) -o $(OUTPUT) $(OBJS)
	
clean:
		$(RM) *.o