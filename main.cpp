#include <iostream>
#include <ctime>

#include "getInput.h" 
#include "generateCard.h"
#include "getChoice.h"
#include "nextMove.h"
#include "claimBingo.h"
#include "autoCheck.h"

using namespace std;

int main(){
    srand(time(0)); //seed for all the random generations in the program

    int size, price;
    cout<<"*****WELCOME TO A NEW VARIANT OF BINGO!*****"<<endl; //welcome message
    cout<<"Before you get started, we would like you to know that Bingo is a game of luck, "<<endl;
    cout<<"patience and persistance. The larger the size of your card, the more the prize  "<<endl;
    cout<<"money (and you will need to stay more patient :P). Remember, there are penalties for"<<endl;
    cout<<"false bingo claims. Good luck!"<<endl;
    getInput(size, price);

    int** card = new int* [size]; //2D dynamically allocated array to store the bingo card
    for (int i=0; i<size; ++i){
        card[i]=new int[size];
    }
    generateCard(card, size);

    int zeros=1;
    bool gameEnd=false, gameOver=false;
    while (gameEnd==false && gameOver==false){ //until a bingo is claimed or the entire card is filled with zeros, program continues
        int choice=getChoice();
        if (choice==1){ //1 denotes user wants more numbers to be generated
            nextMove(card, size, zeros);
        }
        else{ //2 denotes that the user has claimed bingo
            gameEnd=claimBingo(card, size, price);
        }
        gameOver=autoCheck(zeros, size,price);
    }

    delete [] card; //frees the allocated space
    return 0;
}