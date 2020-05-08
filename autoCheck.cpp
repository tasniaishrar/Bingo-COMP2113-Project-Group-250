#include <iostream>
#include "autoCheck.h"
using namespace std;


bool autoCheck(int zeros, int size,int price){ //if the entire card is filled with zeros, game ends automatically
    if (zeros==size*size){
        cout<<endl<<"*** Game over! NO BINGO CLAIMED. ***"<<endl;
        cout<<"You could have won "<<price*2<<" dollars :("<<endl;
        return true;
    }
    return false;
}