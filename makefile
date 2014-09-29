all: Prog4

Prog4: prog4.o 
	g++ -o Prog4 prog4.o
	
prog4.o: prog4.cpp tree.o id_compare.o store_compare.o
	g++ -o prog4.o prog4.cpp

tree.o: binTree.cpp binTree.h
	g++ -o tree.o binTree.cpp

id_compare.o: id_compare.cpp
	g++ -o id_compare.o id_compare.cpp

store_compare.o: store_compare.cpp
	g++ -o store_compare.o store_compare.cpp
	
clean:
	rm *.o