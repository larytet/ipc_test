CFLAGS=-std=c++11 -Wall
TARGETS=front_end sorter

target: $(TARGETS)


front_end: front_end.cpp common.hpp common.cpp
	g++ $(CFLAGS)  common.cpp front_end.cpp -o front_end
	

sorter: sorter.cpp common.hpp  common.cpp
	g++ $(CFLAGS)  common.cpp sorter.cpp -o sorter


all: target
		
# End of rule 'all'

clean: 
	@rm -f $(TARGETS)

