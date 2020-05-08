#include <iostream>
#include "winCombo.h"
using namespace std;

bool checkRows(int** card, int size){ //checks for horizontal bingo
    for (int row=0; row<size; row++){
        int temp=0;
        for (int col=0; col<size; col++){
            temp+=card[row][col];
        }
        if (temp==0){ //if the value of the sum is 0, it returns true since sum of all zeros is 0
            return true;
        }
    }
    return false;
}

bool checkCols(int** card, int size){ //checks for vertical bingo
    for (int col=0; col<size; col++){
        int temp=0;
        for (int row=0; row<size; row++){
            temp+=card[row][col];
        }
        if (temp==0){
            return true;
        }
    }
    return false;
}
//checks for two types of diagonal bingos
bool checkDiag1(int** card, int size){ 
    int temp=0;
    for (int row=0; row<size; row++){
        for (int col=0; col<size; col++){
            if (row==col){
                temp+=card[row][col];
            }
        }
    }
    if (temp==0){
        return true;
    }
    return false;
}

bool checkDiag2(int** card, int size){
    int temp=0;
    for (int row=0; row<size; row++){
        for (int col=0; col<size; col++){
            if (row==size-col-1){
                temp+=card[row][col];
            }
        }
    }
    if (temp==0){
        return true; 
    }
    return false;
}