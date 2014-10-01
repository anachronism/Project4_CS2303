//By Max

#include "global.h"
#include "item.h"

//Constructors.
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

//Compares the member item to a new item.
//returns -1 if member item is earlier than new item, 0 if they are the same
// and 1 if member item is later than new item.
int Item::id_compare(ItemPtr newItem){
  string current = getName();
  string new_id = newItem->getName();

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

//Setters and getters
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