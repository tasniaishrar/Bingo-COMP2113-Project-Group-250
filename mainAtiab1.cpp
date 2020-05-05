#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include <iomanip>
using namespace std;

bool isValidSize(int size, int max){
    if (size%2==1 && size>=3 && size<=max){
        return true;
    }
    return false;
}

void getInput(int& size, int& price){
    cout<<"Enter the size of the card (odd numbers between 3-25): ";
    cin>>size;

    while (!isValidSize(size, 25)){ //prompts user to input size until it is within range
        cout<<"Card size out of range! Enter a odd number between [3, 25]: ";
        cin>>size;
    }
    
    ifstream fin; fin.open("BoardPriceChart.txt"); //fetches the price chart file

    if (fin.fail()){
        cout<<"Error in opening file!"<<endl; //error message displayed if unable to open 
        exit(1);
    }

    int count=0;
    string line;
    while (getline(fin,line)){ //price chart file read by fetching each line until the end
        if (count==size-2 && size<=53){ //fetches price for all card sizes which are <= 53
            size_t pos=line.find(" "); //all characters before the space is removed from the line since price comes after the space
            line.erase(0,pos+1);
            price=stoi(line);
        }
        
        else if(size>53 && count==50){ //fetches price for all card sizes which are more than 53
            size_t pos=line.find(" ");
            line.erase(0,pos+1);
            price=stoi(line);
        }
        count++;
    }
    fin.close();

    cout<<"Enter the amount of money you have: ";
    int money; cin>>money;
    
    if (money>price){
        int change; change=money-price; //change calculated
        cout<<endl<<"You received "<<change<<" dollars change. Let's start the game of bingo!"<<endl;
    }
    else if (price>money){
        while (price>money){ //prompts user to input price until money>=price
            int shortage=price-money; //shortage calculated
            cout<<"You need "<<shortage<<" more dollars to get started. Please provide a larger amount: ";
            cin>>money;
        }
        if (money>price){
            int change; change=money-price;
            cout<<endl<<"You received "<<change<<" dollars change. Let's start the game of bingo!"<<endl;
        }
        else{
            cout<<endl<<"Let's start the game of bingo!"<<endl;
        }
    }
    else{
        cout<<endl<<"Let's start the game of bingo!"<<endl;
    }
}

int generateNumber(){
    return rand()%75 + 1;
}

void printCard(int** card, int size){
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            cout<<setw(4)<<left<<card[i][j];
        }
        cout<<endl;
    }
}

void generateCard(int** card, int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; ++j){
            if (i==size/2 && j==size/2)
                card[i][j]=0;
            else
                card[i][j]=generateNumber(); //generates random numbers for the card
        }
    }

    cout<<endl<<"Card:"<<endl;
    printCard(card, size);
}

void nextNumber(int** card, int size, int& zeros){
    int newNum=generateNumber();
    cout<<endl<<"Next number is: "<<newNum;

    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            if (card[i][j]==newNum){
                card[i][j]=0;
                zeros++;
            }
        }
    }

    cout<<endl<<"Updated card:"<<endl;
    printCard(card, size);
}

void autoCheck(bool& gameEnd, int zeros, int size){
    if (zeros==size*size){
        gameEnd=true;
    }
}

void checkCols(bool& gameEnd, int** card, int size){
    for (int col=0; col<size; col++){
        int temp=0;
        for (int row=0; row<size; row++){
            temp+=card[row][col];
        }
        if (temp==0){
            gameEnd=true;
        }
    }
}

void checkRows(bool& gameEnd, int** card, int size){
    for (int row=0; row<size; row++){
        int temp=0;
        for (int col=0; col<size; col++){
            temp+=card[row][col];
        }
        if (temp==0){
            gameEnd=true;
        }
    }
}

void checkDiag1(bool& gameEnd, int** card, int size){
    int temp=0;
    for (int row=0; row<size; row++){
        for (int col=0; col<size; col++){
            if (row==col){
                temp+=card[row][col];
            }
        }
    }
    if (temp==0){
        gameEnd=true;
    }
}

void checkDiag2(bool& gameEnd, int** card, int size){
    int temp=0;
    for (int row=0; row<size; row++){
        for (int col=0; col<size; col++){
            if (row==size-col-1){
                temp+=card[row][col];
            }
        }
    }
    if (temp==0){
        gameEnd=true;
    }
}

int main(){
    srand(time(0));

    int size, price;
    getInput(size, price);

    int** card = new int* [size];
    for (int i=0; i<size; ++i){
        card[i]=new int[size];
    }
    generateCard(card,size);

    int zeros=1;
    bool gameEnd=false;
    while (!gameEnd){
        nextNumber(card, size, zeros);
        checkRows(gameEnd, card, size);
        checkCols(gameEnd, card, size);
        checkDiag1(gameEnd, card, size);
        checkDiag2(gameEnd, card, size);
    }


    delete [] card; //frees the allocated space
    return 0;
}