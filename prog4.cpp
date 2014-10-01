
#include <iostream>
#include <string.h>
#include "global.h"
#include "binTree.h"
#include "item.h"
#include "binTree.cpp"
//#include "id_compare.cpp"
#include "store_compare.cpp"
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
			sentcount=0;
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

/*

//Given a pointer to the head pointer, inserts a new store in
//decreasing item count order.
void addStore(StorePtr *sPtr, StorePtr newStore) //Author: Max
{  
  int store_comp;
  StorePtr previousPtr;
  StorePtr currentPtr;

  previousPtr = NULL;
  currentPtr = *sPtr;

  store_comp = store_compare(currentPtr, newStore);

  while(store_comp == -1 && currentPtr != NULL){
    previousPtr = currentPtr;
    currentPtr = currentPtr->nextStore;
    store_comp = store_compare(currentPtr, newStore);
  }
 
  //Check conditions for the while to end.
  //If at front of list (and not the same as the front of the list, place in the front. 
  if(previousPtr == NULL && store_compare(currentPtr, newStore) != 0){
    newStore->nextStore = *sPtr;
    *sPtr = newStore;
  }

  //If the store location of the current store is the same as the new one, 
  //add the number of items in the current store to the new store and 
  //call the function again.
  else if(store_comp == 0){

    Store alteredStore = *newStore;
    (newStore->itemCount) += (currentPtr->itemCount);
    removeStore(sPtr, currentPtr);       
    addStore(sPtr, newStore);

  }

  //Elsewise, insert the store normally.
  else if(store_comp == 1){

    previousPtr->nextStore = newStore;
    newStore->nextStore = currentPtr;

  }

  else
    {
      cout<<"Something went wrong in addStore." << endl;
      cout<<endl;
    }
  
}
*/
