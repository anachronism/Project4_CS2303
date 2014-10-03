#ifndef STOREFUNCTION_CPP
#define STOREFUNCTION_CPP
#include "global.h"
#include "item.h"
#include "item.cpp"
bool debugAddStore = false;

// If stores are the same, return 0, if the new store has more items than the current store, return 
// 1 to tell the outer function to insert before the current store, if current store has less count 
// than new store then return -1 to tell the outer function to check the next store.  Any remaining 
// functionality yet to be implemented.

int store_compare(StorePtr currentStore, StorePtr newStore){ //Author: Max
  if (currentStore == NULL){
	return -2;
  } else if (currentStore->x == newStore->x && currentStore->y == newStore->y && currentStore->z == newStore->z) {
    return 0;
  } else if(currentStore->itemCount <= newStore->itemCount){
    return 1;
  }
  else{        //if(currentStore->itemCount > newStore->itemCount)
    return -1;
  }
}

//Given a pointer to the head pointer, inserts a new store in
//decreasing item count order.
//void addStore(StorePtr *sPtr, StorePtr newStore) //Author: Max
void addStore(ItemPtr itPtr, StorePtr newStore)
{
  int store_comp;
  StorePtr previousPtr;
  StorePtr currentPtr;
  StorePtr *sPtr;
  sPtr = itPtr->getStores();

  previousPtr = NULL;
	if (debugAddStore){ //Test to see if sPtr is null
		cout<<"Printing sPtr:\n";
		if (sPtr == NULL){
			cout << "sPtr is Null\n";
		} else {
			printStore(*sPtr);
		}
		cout<<"Printing newStore:\n";
		printStore(newStore);
	}
	if (sPtr==NULL){ //if Null then Store ** is NULL so trying to use *sPtr, meaning a Store *, makes a seg fault
		sPtr = new StorePtr();
		(*sPtr) = newStore;
		/////
		cout<<"1"<<endl;
		//currentPtr=NULL;
	} else {
		currentPtr = *sPtr;

		store_comp = store_compare(currentPtr, newStore);
		
		//test
		cout<<store_comp<<endl;
			
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
			addStore(itPtr, newStore);
		}
		//Elsewise, insert the store normally.
		else if(store_comp == 1){
		  
		  //////
		  //cout<<newStore.name<<endl;
		  previousPtr->nextStore = newStore;
		  newStore->nextStore = currentPtr;
		}
		else
		{
		  cout<<"Something went wrong in addStore." << endl;
		  cout<<endl;
		}
	}

	itPtr->setStores(*sPtr);
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

void printStore(StorePtr store){  //Author: Alexi
	if (store == NULL){
		cout<<"StorePtr is NULL"; 
	} else {
		cout<<"Store's Position is x:" << store->x <<" y:" << store->y <<" z:" << store->z <<endl;
		cout<<"Store's itemCount is:" << store->itemCount<<endl;
	}
}

void printStoreList(StorePtr *store){ //Author: Alexi
	StorePtr curr;
	StorePtr prev;
	
	prev = NULL;
	
	if (store == NULL){
		cout << "Store List is empty\n";
	} else {
		curr = *store;
		while (curr!=NULL){
			printStore(curr);
			prev = curr;
			curr = curr->nextStore;
		}
		cout<< "Hit end of store list\n";
	}

}
#endif
