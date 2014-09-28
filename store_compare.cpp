#include "global.h"


//If stores are the same, return 0, if current store has more than new store return 1, if 
// current store has less count than new store then return -1
//Any remaining functionality yet to be implemented.

int store_compare(StorePtr currentStore, StorePtr newStore){
  if(currentStore->x == newStore->x && currentStore->y == newStore->y && currentStore->z == newStore->z)
    return 0;
  else if(currentStore->countNum > newStore->countNum){
    return 1;
  }
  else if(currentStore->countNum < newStore->countNum){
    return -1;
  }
}
