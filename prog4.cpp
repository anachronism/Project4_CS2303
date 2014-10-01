
#include <iostream>
#include <string.h>
#include "global.h"
#include "binTree.h"
#include "item.h"
#include "binTree.cpp"
//#include "id_compare.cpp"
#include "store_functions.cpp"
#include "item.cpp"

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
	    ItemPtr L1 = new Item("L1");
	    ItemPtr L2 = new Item("L2");
	    ItemPtr M2 = new Item("M2");
	    ItemPtr L2_2 = new Item("L2");
	    
	    cout<<"Compare " << (L1->getName()) << " and " << (L2->getName()) <<": "<< L1->id_compare(L2) << endl; //should return -1
	    cout<<"Compare M2 and L2: "<< M2->id_compare(L2)<<endl; //should return 1
	    cout<<"Compare L2 and L2: "<< L2->id_compare(L2_2) <<endl; //should return 0
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
	case 2: //test addItem
	  cout<<"Testing addItem";
		{
		ItemPtr L1 = new Item("L1");
	    ItemPtr L2 = new Item("L2");
	    ItemPtr M2 = new Item("M2");
	    ItemPtr L2_2 = new Item("L2");
		
		Store s0 = {0,0,0, 4, NULL};
	    Store s1 = {1, 1, 1, 3, NULL};
	    Store s2 = {2, 2, 1, 3, NULL};
	    Store s3 = {1, 1, 1, 3, NULL};
		
		item.Tree.addItem((*L1), s0);
		item.Tree.printTree();
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
		if (x==16)
			Sentinel++;
		cin>>y;
		if (y==16)
			Sentinel++;
		cin>>z;
		if (z==16)
			Sentinel++;
		if (Sentinel==3){
			break;
		} else {
			Sentinel=0;
		}
		cin>>itemNumber;
		for (counter = 0; counter < itemNumber; counter++)
		{
			cin>>name;
			cin>>itemCount;
			/*
			Store tempStore = {x, y, z, itemCount, NULL};
			//make pointer to tempStore
			Item tempItem = new Item(name);
			tree.addItem(tempItem, tempStore); */
		}
	} //end for
} //end ReadData

void instructions() //Author: Alexi
{
	cout <<"Choice of 0 currently tests: id_compare\n";
	cout << "Choice of 1 currently tests: store_compare" << endl;
	cout <<"Please enter a test choice:";
}

