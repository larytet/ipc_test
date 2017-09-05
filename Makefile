
CFLAGS=-std=c++11 -Wall

front_end: front_end.cpp common.hpp 
	g++ $(CFLAGS)  front_end.cpp -o front_end
	

sorter: sorter.cpp common.hpp 
	g++ $(CFLAGS) sorter.cpp -o sorter


all: front_end sorter
clean: 
	rm front_end sorter

