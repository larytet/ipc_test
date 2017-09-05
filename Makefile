CFLAGS=-std=c++11 -Wall
TARGETS=front_end sorter

target: $(TARGETS)


front_end: front_end.cpp common.hpp 
	g++ $(CFLAGS)  front_end.cpp -o front_end
	

sorter: sorter.cpp common.hpp 
	g++ $(CFLAGS) sorter.cpp -o sorter


all: target
		
# End of rule 'all'

clean: 
	@rm -f $(TARGETS)

