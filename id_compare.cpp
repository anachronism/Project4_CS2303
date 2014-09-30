#include "global.h"
#include "item.h"
//Function written by Max Li

//Compares the id's of two items.   

int id_compare(ItemPtr currentNode, ItemPtr newNode){
  string current = currentNode->name;
  string new_id = newNode->name;
  
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
