#ifndef BINTREE_H
#define BINTREE_H
#include "global.h"

class Tree{
	private:
		ItemPtr root;
	public:
		Tree();
		bool isEmpty();
		bool addItem(ItemPtr newItem, StorePtr newStore);
		void PrintItem(ItemPtr item);
		void PrintTree();
	private:
		void PrintAll(ItemPtr item);
};

#endif
