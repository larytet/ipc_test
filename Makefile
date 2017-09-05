CFLAGS=-std=c++11 -Wall
TARGETS=front_end sorter

all: $(TARGETS)
		
# End of rule 'all'

front_end: front_end.cpp common.hpp 
	g++ $(CFLAGS)  front_end.cpp -o front_end
	

sorter: sorter.cpp common.hpp 
	g++ $(CFLAGS) sorter.cpp -o sorter


clean: 
	@rm $(TARGETS)

