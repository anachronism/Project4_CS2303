
#include <iostream>
#include <string.h>
#include "global.h"
#include "binTree.h"
#include "binTree.cpp"
#include "id_compare.cpp"
#include "store_compare.cpp"

void ReadData(Tree tree);
void instructions();

//use mainly as a driver function
int main () //Author: Alexi
{
	Tree *itemTree; 
	itemTree = new Tree();
	
	int testChoice;
	instructions();
	cin>>testChoice;
	//driver test function
	switch (testChoice) 
	{
		case 0:
			break;
		default:
			cout<<"Improper or no test chosen\n";
			break;
	}
	
	//code for after testing is complete	
	//ReadData(*itemTree);
	//itemTree->PrintTree();
	
	return 0;
}

void ReadData(Tree tree) //Author: Alexi
{
	int Sentinel = 0, counter = 0, itemCount;
	string name;
	
	while (Sentinel != 2)  //Going to represent 16 16 16, need to rework logic slightly
	{
		int x, y, z, itemNumber;
		cout << "Reading in data\n";
		cin>>x;
		cin>>y;
		cin>>z;
		cin>>itemNumber;
		for (counter = 0; counter < itemNumber; counter++)
		{
			cin>>name;
			cin>>itemCount;
			/*
			Store tempStore = {x, y, z, itemCount, NULL};
			Item tempItem = {name, NULL, NULL, NULL};
			insert(tree, tempItem, tempStore); */
		}
	} //end for
} //end ReadData

void instructions() //Author: Alexi
{
	cout <<"Choice of 0 currently tests: Nothing\n";
	cout <<"Please enter a test choice:";
}
