#include "repCheck.h"
#include <iostream>
using namespace std;

bool repCheck(int tmp, int arrLength, int* randomNumList,int pos){ //this function checks for repeatiting values in the card
    int count=0;
    for (int i=0; i<arrLength; ++i){ //loops through the array that contains the existing values in the card
      if (tmp==randomNumList[i]){
        count++;
      }
    }
    if (count==0){ //if the randomly generated number is not in the card
        randomNumList[pos]=tmp; //it is appended to the array
        return false; //false-no repetition
    }
    return true;

}