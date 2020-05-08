#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "getInput.h"
#include "isValidSize.h"
using namespace std;


void getInput(int& size, int& price){ 
    cout<<"Enter the size of the card [odd numbers between 3-23]: ";
    cin>>size;

    while (!isValidSize(size, 23)){ //prompts user to input size until it is within range
        cout<<"Card size out of range! Enter a odd number between [3, 23]: ";
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
        if (count==size-2 && size<=53){ //fetches price for all card sizes which are <= 53 since the last line of the price chart is '>53'
            size_t pos=line.find(" "); //all characters before the space is removed from the line since price comes after the space
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
        cout<<endl<<"You received "<<change<<" dollars change. Let's get started!"<<endl;
    }
    else if (price>money){
        while (price>money){ //prompts user to input price until money>=price
            int shortage=price-money; //shortage calculated
            cout<<"You need "<<shortage<<" more dollars to get started. Please provide a larger amount: ";
            cin>>money;
        }
        if (money>price){
            int change; change=money-price;
            cout<<endl<<"You received "<<change<<" dollars change. Let's get started!"<<endl;
        }
        else{
            cout<<endl<<"Let's get started!"<<endl;
        }
    }
    else{
        cout<<endl<<"Let's get started!"<<endl;
    }
}