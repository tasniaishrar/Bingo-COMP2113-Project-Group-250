#include <iostream>
#include <cmath>
#include "generateNumber.h"
#include "printCard.h"
#include "nextMove.h"
using namespace std;


void nextMove(int** card, int size, int& zeros){
    int n1=generateNumber(size), n2=generateNumber(size); //generates two random numbers
    cout<<endl<<"Numbers that should be replaced if present in the card: "<<endl;
    cout<<"First generated number: "<<n1<<endl;
    cout<<"Second generated number: "<<n2<<endl; //prints them 

    int sum, diff, prod, div;

    if (abs(n1-n2)>0){ //difference of the two random numbers
        diff=abs(n1-n2);
        cout<<"Difference: "<<diff<<endl;
    }

    else{
        cout<<"Difference: OUT OF RANGE"<<endl;
    }
    

    if (n1>n2 && n1%n2==0){ //division of the two random numbers
        div=n1/n2;
        cout<<"Division: "<<div<<endl;
    }

    else if (n2>n1 && n2%n1==0){
        div=n2/n1;
        cout<<"Division: "<<div<<endl;
    }

    else{
        cout<<"Division: OUT OF RANGE"<<endl;
    }
    
    if ((n1+n2)<=((size*size)+50)){ //sum of the two random numbers
        sum=n1+n2;
        cout<<"Sum: "<<sum<<endl;
    }

    else{
        cout<<"Sum: OUT OF RANGE"<<endl;
    }

    if ((n1*n2)<=(size*size)+50){ //product of the two random numbers
        prod=n1*n2;
        cout<<"Product: "<<prod<<endl;        
    }

    else{
        cout<<"Product: OUT OF RANGE"<<endl;
    }

    for (int i=0; i<size; i++){ //replaces the aforementioned values in the card with a '0' if present
        for (int j=0; j<size; j++){
            if (card[i][j]==n1){
                card[i][j]=0;
                zeros++; //increments the number of zeros for the autoCheck function
            }
            if (card[i][j]==n2){
                card[i][j]=0;
                zeros++;
            }                      
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
            if (card[i][j]==div){
                card[i][j]=0;
                zeros++;
            }
        }
    }

    printCard(card, size); //prints the updated card
}