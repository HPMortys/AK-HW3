all: core

core: main.o  
	g++ main.o  -o main

main.o: main.cpp
	g++ -c main.cpp
	
clean:
	rm -rf *.o 
