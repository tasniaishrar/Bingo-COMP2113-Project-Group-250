#include <iostream>
#include "isValidSize.h"
using namespace std;


bool isValidSize(int size, int max){ //to check if the board size is valid
    if (size%2==1 && size>=3 && size<=max){
        return true;
    }
    return false;
}