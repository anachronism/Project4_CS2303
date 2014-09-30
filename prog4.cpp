
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

	  //emacs is messing with the whitespaces so I changed these, you can
	  //change them back.
	case 0:
	  {
	    Item L1 = {"L1", NULL, NULL, NULL};
	    Item L2 = {"L2", NULL, NULL, NULL};
	    Item M2 = {"M2", NULL, NULL, NULL};
	    Item L2_2 = {"L2", NULL, NULL, NULL};
	    
	    cout<<"Compare L1 and L2: "<< id_compare(&L1, &L2) << endl; //should return -1
	    cout<<"Compare M2 and L2: "<< id_compare(&M2, &L2)<<endl; //should return 1
	    cout<<"Compare L2 and L2: "<< id_compare(&L2, &L2_2) <<endl; //should return 0
	  }
	  break;
	case 1:
	  cout << "store_compare test here\n";
	  {
	    Store s0 = {0,0,0, 4, NULL};
	    Store s1 = {1, 1, 1, 3, NULL};
	    Store s2 = {2, 2, 1, 3, NULL};
	    Store s3 = {1, 1, 1, 3, NULL};

	    cout<<"Compare 4 items and 3 items: "<<store_compare(&s0, &s1) << endl;
	    cout<<"Compare 3 items and 4 items: "<<store_compare(&s1, &s0)<<endl;
	    cout<<"Compare 3 items and 3 items (diff location): "<<store_compare(&s1, &s2)<<endl;
	    cout<<"Compare 3 items and 3 items (same location): "<<store_compare(&s1, &s3)<<endl;
	  }
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
	cout <<"Choice of 0 currently tests: id_compare\n";
	cout << "Choice of 1 currently tests: store_compare" << endl;
	cout <<"Please enter a test choice:";
}
