#include <iostream>
#include <iomanip>
#include "printCard.h"
using namespace std;



void printCard(int** card, int size){ 
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            cout<<setw(4)<<left<<card[i][j]; //prints the card by formatting
        }
        cout<<endl;
    }
}