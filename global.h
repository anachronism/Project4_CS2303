#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>
#include <string>
using namespace std;

#define GLOBALDEBUG 1

typedef struct store{
  int x, y, z, itemCount;
  struct store *nextStore;
} Store;

typedef Store *StorePtr;


typedef struct item{
  string name;
  StorePtr *stores;
  struct item *left;
  struct item *right;
} Item;

typedef Item *ItemPtr; 

ItemPtr create_item(string name); 

int id_compare(ItemPtr currentNode, ItemPtr newNode); 
int store_compare(StorePtr currentStore, StorePtr newStore);

#endif
