CC = gcc
CXX = g++
RM = rm -f
CPPFLAGS= -g -std=gnu++11
LDFLAGS=-g -std=gnu++11
LDLIBS=$(shell root-config --libs)

PROG = ConnectFour.cpp main.cpp
OBJS=$(subst .cc,.o,$(PROG))

all: prog

prog: $(OBJS)
		$(CXX) $(LDFLAGS) -o p3 $(OBJS) $(LDLIBS)
	
clean:
		$(RM) *.o