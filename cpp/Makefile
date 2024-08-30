
CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g 

%: %*.cpp
	$(CXX) $(CPPFLAGS) $< -o $@.out

all:
	@echo "Specify a problem number i.e 'make 217'"

clean:
	$(RM) *.out

.PHONY: all clean