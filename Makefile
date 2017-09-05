
front_end: front_end.cpp common.hpp 
	g++ -Wall front_end.cpp -o front_end
	

sorter: sorter.cpp common.hpp 
	g++ -Wall sorter.cpp -o sorter


all: front_end sorter

