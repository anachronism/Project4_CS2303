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

typedef store *StorePtr;

typedef struct item{
  string name;
  StorePtr *stores;
  struct node **left;
  struct node **right;
} Item;

typedef item *ItemPtr;

int id_compare(ItemPtr currentNode, ItemPtr newNode);
int store_compare(StorePtr currentStore, StorePtr newStore);

#endif
