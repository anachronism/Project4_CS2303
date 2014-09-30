#include "global.h"
#include "item.h"

Item::Item(){
  name = "NULL";
  stores = NULL;
  left = NULL;
  right = NULL;
}


Item::Item(string newName){
  name = newName;
  stores = NULL;
  left = NULL;
  right = NULL;
}


int Item::id_compare(ItemPtr newNode){
  string current = getName();
  string new_id = newNode->getName();

  if ( current.compare(new_id) < 0){  //if new is lower than current
    return -1;
  }
  else if(current.compare(new_id) == 0){ // if new is the same as current
    return 0;
  }
  else {  //if new is higher than current
    return 1;
  }

}


string Item::getName(){
  return name;
}

void Item::setName(string newName){
  name = newName;
}

ItemPtr Item::getLeft(){
  return left;
}

ItemPtr Item::getRight(){
  return right;
}

void Item::setLeft(ItemPtr newPtr){
  left = newPtr;
}

void Item::setRight(ItemPtr newPtr){
  right = newPtr;
}
