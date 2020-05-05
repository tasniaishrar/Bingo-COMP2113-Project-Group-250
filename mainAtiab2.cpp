#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
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
    cout<<"Enter the size of the card [odd numbers between 3-25]: ";
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

int generateNumber1_75(){
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
                card[i][j]=generateNumber1_75(); //generates random numbers for the card
        }
    }

    cout<<endl<<"Card:"<<endl;
    printCard(card, size);
}

void nextMove(int** card, int size, int& zeros){
    int n1=generateNumber1_75(), n2=generateNumber1_75();
    //cout<<endl<<"Next numbers are: "<<n1<<" "<<n2;

    int sum=n1+n2, diff, prod=n1*n2, quo;

    if (abs(n1-n2)>0)
        diff=abs(n1-n2);
    else
        diff=n1;
    
    if (n1>n2)
        quo=n1/n2;
    else
        quo=n2/n1;
    
    if (sum>75)
        sum=sum%75+1;
    if (diff>75)
        diff=diff%75+1;
    if (prod>75)
        prod=prod%75+1;
    if (quo>75)
        quo=quo%75+1;

    cout<<endl<<"Numbers being replaced are: "
        <<sum<<" "
        <<diff<<" "
        <<prod<<" "
        <<quo<<endl;

    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            if (card[i][j]==sum){
                card[i][j]=0;
                zeros++;
            }
            if (card[i][j]==diff){
                card[i][j]=0;
                zeros++;
            }
            if (card[i][j]==prod){
                card[i][j]=0;
                zeros++;
            }
            if (card[i][j]==quo){
                card[i][j]=0;
                zeros++;
            }
        }
    }

    //cout<<endl<<"Updated card:"<<endl;
    printCard(card, size);
}

bool autoCheck(int zeros, int size){
    if (zeros==size*size){
        cout<<endl<<"*** Game over! NO BINGO CLAIMED. ***"<<endl;
        return true;
    }
    return false;
}

bool checkRows(int** card, int size){
    for (int row=0; row<size; row++){
        int temp=0;
        for (int col=0; col<size; col++){
            temp+=card[row][col];
        }
        if (temp==0){
            return true;
        }
    }
    return false;
}

bool checkCols(int** card, int size){
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

bool claimBingo(int** card, int size){
    if (checkRows(card, size) || checkCols(card, size) || checkDiag1(card, size) || checkDiag2(card, size)){
        cout<<endl<<"*** Congratulations. YOU WIN! ***"<<endl;
        return true;
    }
    cout<<endl<<"*** False claim! YOU LOSE. ***"<<endl;
    return true;
}

int getChoice(){
    cout<<"Choose a number from 1. NEXT MOVE or 2. CLAIM BINGO!: ";
    int choice; cin>>choice;
    while (true){
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

int main(){
    srand(time(0));

    int size, price;
    getInput(size, price);

    int** card = new int* [size];
    for (int i=0; i<size; ++i){
        card[i]=new int[size];
    }
    generateCard(card, size);

    int zeros=1;
    bool gameEnd=false;
    while (!gameEnd){
        int choice=getChoice();
        if (choice==1){
            nextMove(card, size, zeros);
        }
        else{
            gameEnd=claimBingo(card, size);
        }
        gameEnd=autoCheck(zeros, size);
    }

    delete [] card; //frees the allocated space
    return 0;
}