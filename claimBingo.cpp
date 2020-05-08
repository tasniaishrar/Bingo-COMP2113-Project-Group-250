#include <iostream>
#include "winCombo.h"
#include "claimBingo.h"
using namespace std;


bool claimBingo(int** card, int size,int price){
    if (checkRows(card, size) || checkCols(card, size) || checkDiag1(card, size) || checkDiag2(card, size)){ //checks if the claim is true if any one of the win combinations satisfy
        cout<<endl<<"*** Congratulations. YOU WIN! ***"<<endl;
        cout<<"As a reward, you got "<<price*2<<" dollars! :D"<<endl; //displays congratulatory message and reward money
        return true;
    }
    cout<<endl<<"*** False claim! YOU LOSE. ***"<<endl; 
    cout<<endl<<"As a penalty, you lose "<<price*2<<" dollars"<<endl; //displays the amount of money penalized
    return true;
}