//Written by Max Li
#ifndef STOREFUNCTION_CPP
#define STOREFUNCTION_CPP
#include "global.h"

bool debugAddStore = true;

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

//Given a pointer to the head pointer, inserts a new store in
//decreasing item count order.
void addStore(StorePtr *sPtr, StorePtr newStore) //Author: Max
{
  int store_comp;
  StorePtr previousPtr;
  StorePtr currentPtr;

  previousPtr = NULL;
	if (debugAddStore){ //Test to see if sPtr is null
		if (sPtr == NULL){
			cout << "sPtr is Null\n";
		} else {
			cout << "sPtr is not Null\n";
		}
	}
	if (sPtr==NULL){ //if Null then Store ** is NULL so trying to use *sPtr, meaning a Store *, makes a seg fault
		currentPtr=NULL;
	} else {
		currentPtr = *sPtr;
	}

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

void removeStore(StorePtr *sPtr,StorePtr toRemove){ //author: Max
  StorePtr tempPtr;
  StorePtr previousPtr;
  StorePtr currentPtr;

  if(*sPtr == toRemove){
    tempPtr = *sPtr;
    *sPtr = (*sPtr)->nextStore;
    free(tempPtr);
  }
  else{
    previousPtr = *sPtr;
    currentPtr = (*sPtr)->nextStore;

    while(currentPtr != NULL && currentPtr != toRemove){
      previousPtr = currentPtr;
      currentPtr = currentPtr->nextStore;
    }
    if(currentPtr != NULL){
      tempPtr = currentPtr;
      previousPtr->nextStore = currentPtr->nextStore;
      free(tempPtr);
    }
  }
}
#endif
