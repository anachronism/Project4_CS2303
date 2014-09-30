#include "global.h"
//Function written by Max Li

//Compares the id's of two items.  

int id_compare(ItemPtr currentNode, ItemPtr newNode){
  string current = currentNode->name;
  string new = newNode->name;
  
  //If current is earlier in ascii (hopefully all caps or all lowercase)
  if(current[0] > new[0]){
    return -1;
  }
  else if(current[0] < new[0]){
    return 1;
  }
  else{ //if current[0] == new[0]
    if(current[1] > new[1]){
      return -1;
    }
    else if(current[1] < new[1]){
      return 1;
    }
    else{
      return 0;
    }
  }


} 
