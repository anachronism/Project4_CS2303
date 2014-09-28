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
  struct node **left;
  struct node **right;
} Item;

typedef Item *ItemPtr;
