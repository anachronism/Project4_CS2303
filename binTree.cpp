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
bool Tree::isEmpty()
{
	return (root==NULL);
}

//Adds new item to tree
bool Tree::insert(ItemPtr newItem, StorePtr newStore){
  
  //Placeholder while the function doesn't exist
  return true;
}

//Print a single item
void Tree::PrintItem(ItemPtr item) 
{
	cout << "Printing item:\n" << "ItemID:" << item->name /*add something here to print event list*/
	<< endl << "Left Item ID:" << item->left->name << endl << "Right Item ID:" << item->right->name << endl;
}

//Print Entire Tree
void Tree::PrintTree(){
	PrintAll(root);
}

//Print everything below a point in the tree
void Tree::PrintAll(ItemPtr item)
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
