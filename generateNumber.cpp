#include <random>
#include <iostream>
#include "generateNumber.h"


int generateNumber(int size){ //this is to generate random numbers
    int upperLimit=(size*size)+50; //upper limit is adjusted according to the card size
    return rand()%upperLimit + 1;
}

