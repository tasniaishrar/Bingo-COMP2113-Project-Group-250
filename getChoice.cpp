#include <iostream>
#include "getChoice.h"
using namespace std;

int getChoice(){
    cout<<"Choose a number from 1. NEXT MOVE or 2. CLAIM BINGO!: "; 
    int choice; cin>>choice; //prompts the user to input what move they would like to take
    while (true){ //loop to prompt the user to input choice until it is valid
        if (choice==1 || choice==2){ 
            break;
        }
        else{
            cout<<"Invalid choice! Choose again [1 or 2]: ";
            cin>>choice;
        }
    }
    return choice; 
}
