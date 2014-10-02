
all: Prog4

Prog4: prog4.o 
	g++ -o Prog4 prog4.o
	
prog4.o: prog4.cpp tree.o store_functions.o item.o
	g++ -c -g -Wall -o prog4.o prog4.cpp

tree.o: binTree.cpp binTree.h
	g++ -c -g -Wall -o tree.o binTree.cpp

store_functions.o: store_functions.cpp
	g++ -c -g -Wall -o store_functions.o store_functions.cpp
	
item.o: item.cpp item.h
	g++ -c -g -Wall -o item.o item.cpp

clean:
	rm *.o
