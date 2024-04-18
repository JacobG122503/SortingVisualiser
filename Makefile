Program: Program.o Algorithms.o
	g++ Program.o Algorithms.o -o Program -lncurses

clean:
	rm -f Program *~ core *.o 

brun: Program.o Algorithms.o 
	g++ Program.o Algorithms.o -o Program -lncurses
	./Program

Program.o: Program.cpp 
	g++ -Wall -Werror -g Program.cpp -c 

Algorithms.o: Algorithms.cpp Algorithms.h
	g++ -Wall -Werror -g Algorithms.cpp -c

