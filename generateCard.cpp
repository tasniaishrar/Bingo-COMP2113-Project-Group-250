#include <iostream>
#include "generateCard.h"
#include "generateNumber.h"
#include "printCard.h"
#include "repCheck.h"
using namespace std;

void generateCard(int** card, int size){
    int tmp;
    int arrLength=(size*size)+1; //dynamically allocated array to store all the randomly generated numbers in the card to check for repetition
    int *randomNumList= new int[arrLength];
    randomNumList[0]=100;
    int pos=1;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; ++j){  
            if (i==size/2 && j==size/2){ //'0' for free space
                card[i][j]=0;
            }
            else {
                bool status=true;
                while(status==true){ //loop to make sure none of the numbers in the card are repeated
                    tmp=generateNumber(size); //generates random numbers for the card
                    card[i][j]=tmp;
                    status=repCheck(tmp,arrLength,randomNumList,pos); 
                }
            }
            pos++;
        }
    }      
    cout<<endl<<"Your Card:"<<endl;
    printCard(card, size); //calls the function to print the card
    delete [] randomNumList; //frees the allocated space
}
