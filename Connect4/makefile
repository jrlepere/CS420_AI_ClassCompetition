CC = gcc
CXX = g++
RM = rm -f
CPPFLAGS= -g -std=gnu++11
LDFLAGS=-g -std=gnu++11
LDLIBS=$(shell root-config --libs)
OUTPUT=p3

PROG = algorithms/human/*.cpp algorithms/minimax/*.cpp algorithms/minimax/heuristic_functions/*.cpp algorithms/minimax/successor_functions/*.cpp game/*.cpp player/*.cpp src/*.cpp
OBJS=$(subst .cc,.o,$(PROG))

all: prog

prog: $(OBJS)
		$(CXX) $(LDFLAGS) -o $(OUTPUT) $(OBJS) $(LDLIBS)
	
clean:
		$(RM) *.o