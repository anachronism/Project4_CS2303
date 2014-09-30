#ifndef BINTREE_CPP
#define BINTREE_CPP

#include "global.h"
#include "binTree.h"
#include <iostream>
#include <string.h>

//default constructor
Tree::Tree()
{
	root=NULL;
	return;
}

//checks if Tree is empty
bool Tree::isEmpty() //Author: Alexi
{
	return (root==NULL);
}

//Adds new item to tree
bool Tree::addItem(ItemPtr newItem, StorePtr newStore){ //Author: Alexi
  ItemPtr curr;
  ItemPtr prev;
  int idComp;
  
  curr = root; //Start at root of tree
  prev = NULL;
  
  /*
  while (curr!=NULL) //Loops till end of tree
  {
	idComp = id_compare(curr, newItem);
	prev = curr;
	
	switch(idComp)
	{
		case -1: //If id is lower
			curr=curr->left;
		case 0: //if id is same
			//NEED TO FIGURE OUT WHAT TO DO HERE
			break;
		case 1: //If id is greater
			curr=curr->right;
			break;
		default:
			cout<<"There's something wrong with id_compare";
			break;
	}
  } //end while
  
  if (prev==NULL)
  {
	root = newItem;
  } else { 
	//Need to work on logic
	idComp = id_compare(prev, newItem); 
	
  }
  */
  //Needs to be completed and tested
  return true;
}

//Print a single item
void Tree::PrintItem(ItemPtr item) //Author: Alexi
{
	cout << "Printing item:\n" << "ItemID:" << item->name /*add something here to print event list*/
	<< endl << "Left Item ID:" << item->left->name << endl << "Right Item ID:" << item->right->name << endl;
}

//Print Entire Tree
void Tree::PrintTree(){ //Author: Alexi
	PrintAll(root);
}

//Print everything below a point in the tree
void Tree::PrintAll(ItemPtr item) //Author: Alexi
{
	if (item != NULL)
	{
		PrintAll(item->left);
		PrintItem(item);
		PrintAll (item->right);
	} else {
		cout << "Nothing at this point in tree" <<endl;
	}
}

#endif
