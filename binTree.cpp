#ifndef BINTREE_CPP
#define BINTREE_CPP

#include "global.h"
#include "binTree.h"
#include "item.h"
#include "item.cpp"
#include <iostream>
#include <string.h>
#include "store_functions.cpp"
void addStore(ItemPtr itPtr, StorePtr newStore);

bool debugAdd = true;
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
  if (debugAdd)
	cout<<"Beginning to add item" << newItem->getName() << endl;
  ItemPtr curr = NULL;
  ItemPtr prev;
  int idComp;
  bool equal = false;
  
  curr = root; //Start at root of tree
  prev = NULL;
  
  if (debugAdd){
	bool empty = isEmpty();
	cout << "Is tree Empty?: " << empty <<endl ;
  }
  while (curr!=NULL and !equal) //Loops till end of tree
  {
    idComp = curr->id_compare(newItem);
	if (debugAdd)
		cout << "idCompare of" << (curr->getName()) <<" and "<< (newItem->getName()) <<" generates value of: " << idComp <<endl;
	prev = curr;
	
	switch(idComp)
	{
		case -1: //If id is lower
			curr=curr->getLeft();
			break;
		case 0: //if id is same
			//addStore((*curr).getStores, newStore);
			addStore(curr, newStore);
			equal=true;
			break;
		case 1: //If id is greater
		  curr=curr->getRight();
			break;
		default:
			cout<<"There's something wrong with id_compare";
			break;
	}
  } //end while
  if (prev==NULL) //If tree is empty
  {
	root = newItem;
	addStore(root, newStore);
  } else if (!equal) { 
	idComp = prev->id_compare(newItem); //compares previous and new
	switch (idComp) {
		case -1:
		  //addStore((*newItem).getStores(), newStore);
		  addStore(newItem, newStore);
		  prev->setLeft(newItem);
		  break;
		case 1:
		  //addStore((*newItem).getStores(), newStore);
		  addStore(newItem, newStore);
		  prev->setRight(newItem);
		  break;
		default:
			cout<<"There's something wrong with second id_compare";
			break;
	}
	
  }
  
  //Needs to be completed and tested
  return true;
}

//Print a single item
void Tree::PrintItem(ItemPtr item) //Author: Alexi
{
  string leftName, rightName;
  leftName = (item->getLeft())->getName();
  rightName = (item->getRight())->getName();
  
  cout << "Printing item:\n" << "ItemID:" << item->getName(); /*add something here to print event list*/
  cout << endl << "Left Item ID:" << leftName << endl << "Right Item ID:" << rightName << endl;
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
		if (item->getLeft() ==NULL && item->getRight() == NULL){
			(*item).printItem();
		} else if (item->getLeft() == NULL) {
			(*item).printItem();
			PrintAll (item->getRight());
		} else if (item->getRight()==NULL) {
			PrintAll(item->getLeft());
			(*item).printItem();
		} else {
			PrintAll(item->getLeft());
			(*item).printItem();
			PrintAll (item->getRight());
		}
	} else {
		cout << "Nothing at this point in tree" <<endl;
	}
}

ItemPtr Tree::getRoot(){
	return root;
}

#endif
