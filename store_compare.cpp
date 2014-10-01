//Written by Max Li

#include "global.h"

// If stores are the same, return 0, if the new store has more items than the current store, return 
// 1 to tell the outer function to insert before the current store, if current store has less count 
// than new store then return -1 to tell the outer function to check the next store.  Any remaining 
// functionality yet to be implemented.

int store_compare(StorePtr currentStore, StorePtr newStore){
  if(currentStore->x == newStore->x && currentStore->y == newStore->y && currentStore->z == newStore->z)
    return 0;
  else if(currentStore->itemCount <= newStore->itemCount){
    return 1;
  }
  else{        //if(currentStore->itemCount > newStore->itemCount)
    return -1;
  }
}


void removeStore(StorePtr *sPtr,StorePtr toRemove){
  StorePtr newPtr;
  StorePtr previousPtr;
  StorePtr currentPtr;

  if(*sPtr == toRemove){
    tempPtr = *sPtr;
    *sPtr = (*sPtr)->nextStore;
    free(tempPtr);
  }
  else{
    previousPtr = *sPtr;
    currentPtr = (*sPtr)->nextPtr;

    while(currentPtr != NULL && currentPtr != toRemove){
      previousPtr = currentPtr;
      currentPtr = currentPtr->nextPtr;
    }
    if(currentPtr != NULL){
      temp = currentPtr;
      previousPtr->nextPtr = currentPtr->nextPtr;
      free(tempPtr);
    }
  }
}
