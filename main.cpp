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
  while (size<5){ //prompts user to input size until it is within range
    cout<<"Board size out of range! Please enter a board size between 5 and 50: ";
    cin>>size;
  }
  ifstream fin; fin.open("BoardPriceChart.txt"); //fetches the price chart file
  if(fin.fail()) {
      cout<<"Error in opening file!"<<endl; //error message displayed if unable to open 
      exit(1);
  }
  int count=0;
  string line;
  while (!fin.eof()){ //price chart file read until the end
    getline(fin,line); //fetches each line
    if (count==size-4 && size<=53){ //fetches price for all card sizes which are <= 53
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
  cout<<"Enter the amount of money you have: ";
  int money; cin>>money;
  if (money>price){
    int change; change=money-price; //change calculated
    cout<<"You received "<<change<<" dollars change. Let's start the game of bingo!"<<endl;
  }
  else if (price>money){
    while (price>money){ //prompts user to input price until money>=price
      int shortage=price-money; //shortage calculated
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
void generateCard(int** card,int size){
  card= new int*[size]; //dynamically allocates a 2D-array for the bingo card
  for (int i=0; i<size; ++i){
    card[i]=new int[size];
  }
  int upperLimit=4*size*size; 
  srand(time(0));
  for(int j=0; j<size; ++j){
    for(int k=0; k<size; ++k){
      card[j][k]=rand()%upperLimit+1; //generates random numbers for the card
    }
  }
  for(int a=0; a<size; ++a){ //prints the card after formatting
    int count=1;
    for(int b=0; b<size; ++b){
      if (count==size){
        cout<<card[a][b]<<endl;
      }
      else {
        int temp, digits=0;
        temp=card[a][b];
        while (temp!=0){
          digits++;
          temp/=10;
        }
        if (digits==4){
          cout<<card[a][b]<<" ";
        }
        else if(digits==3){
          cout<<card[a][b]<<"  ";
        }
        else if(digits==2){
          cout<<card[a][b]<<"   ";
        }
        else{
          cout<<card[a][b]<<"    ";
        }
      }
      count++;
    }
  }
}



int main(){
  int size, price;
  getInput(size, price);
  int** card= new int*[size];
  for (int i=0; i<size; ++i){
    card[i]=new int[size];
  }
  generateCard(card,size);
  delete [] card; //frees the allocated space
  return 0;
}



