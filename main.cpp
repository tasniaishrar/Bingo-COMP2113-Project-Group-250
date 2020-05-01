#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
using namespace std;

void getInput(int& size, int& price){

  cout<<"Enter the size of the board you wish to play with: ";
  cin>>size;
  while (size<5){
    cout<<"Board size out of range! Please enter a board size between 5 and 50: ";
    cin>>size;
  }

  ifstream fin; fin.open("BoardPriceChart.txt");
  if(fin.fail()) {
      cout<<"Error in opening file!"<<endl;
      exit(1);
  }
  int count=0;
  string line;
  while (!fin.eof()){
    getline(fin,line);
    if (count==size-4 && size<=53){
      size_t pos=line.find(" ");
      line.erase(0,pos+1);
      price=stoi(line);
    }
    else if(size>53 && count==50){
      size_t pos=line.find(" ");
      line.erase(0,pos+1);
      price=stoi(line);
    }
    count++;
  }
  cout<<"Enter the amount of money you have: ";
  int money; cin>>money;
  if (money>price){
    int change; change=money-price;
    cout<<"You received "<<change<<" dollars change. Let's start the game of bingo!"<<endl;
  }
  else if (price>money){
    while (price>money){
      int shortage=price-money;
      cout<<"You need "<<shortage<<" more dollars to get started. Please provide a larger amount: ";
      cin>>money;
    }
    if (money>price){
      int change; change=money-price;
      cout<<"You received "<<change<<" dollars change. Let's start the game of bingo!"<<endl;
    }
    else {
      cout<<"Let's start the game of bingo!"<<endl;
    }
  }
  else {
    cout<<"Let's start the game of bingo!"<<endl;
  }
  fin.close();

}



int main(){
  int size, price;

  getInput(size, price);
  return 0;
}

