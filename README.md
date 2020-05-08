# COMP2113 Course Project (Group 250)

## Team members
1. RAHMAN Tasnia Ishrar • 3035718187 -BEng Year 1
2. ZAKARIA Atiab Bin • 3035718230 -BEng Year 1 

## Game description and rules
User inputs the amount of money they have and the size of the card they want to purchase. The size input has to be in the range [3,23] and it has to be an odd number. We have chosen 23 as a reasonable upper limit because of screen size limitations. We have specified it to be odd because there must be a free size denoted by a '0' on the card. Each size range of the card has a specific price (in-game currency). Error will be generated until user can afford the specified size of card and the size input is within the aforementioned range. 

The randomly generated card of the specified size will be displayed on the screen. Two options are available to user: 1. “Next Numbers” and 2. “Claim Bingo”. “Next Numbers” will generate and display two random numbers. The two randomly generated numbers, their sum, difference, product and quotient (if any one is divisible by another) is replaced with a '0' on the card. 

User has to keep track if there are any whole rows, columns or diagonals of zeros and select “Claim Bingo”. Program will check the claim and display congratulatory/error message depending on the result of the check. If the claim is valid, the program will display the prize money the player wins, which will be set according to the size range of the card. If the claim is false, the user will be penalized with a certain amount of money. 

If the card is full of zeros but the user still does not claim bingo, an automatic message such as "You could've won $ xyz. We hope you will claim bingo in due time in the next game. Good luck!" will be generated.

## Requirements fulfillment
1. Generation of random game sets or events
    - Generate random numbers to fill the card initially.
    - Generate two random number when ‘Next numbers’ is selected.
    
2. Data structures for storing game status
    - 2D arrays
    
3. Dynamic memory management
   - Since the size of the card is only found at runtime, a dynamically allocated 2D array will need to be used to store the card’s values.
   - Since the size of the card is only found at runtime and the card's value cannot be repeated, a dynamically allocated array has to be used to store values that is already present in the card.
   
4. File input/output (e.g., for loading/saving game status)
    - The card price chart will be in a different text file. It will be fetched in the main program to calculate the amount of change         the user will receive or to check if the user can afford the specified size of card.
5. Program codes in multiple files
    - All the functions are in different files 


## Functions Implemented
1. main
2. getInput: To take input for the size of board and calculate its price from the chart. It also calculates change, shortages etc.
3. autoCheck: Used to end the game automatically if the entire card is filled with zeros.
4. generateNumber: To generate random numbers within a specified range.
5. claimBingo: To check if the user's bingo claim is true or false. 
6. getChoice: To evaluate the user's next move.
7. isValidSize: To check if the card size is valid.
8. winCombo: To check for row, column and diagonal bingos.
9. repCheck: To prevent repetition of values in the card.
10. printCard: To print the card (both initial and updated).
11. nextMove: Generates two random numbers. Calculates arithmetic operations with them (+, -, *, /) and updates the card with zeros if those values are present.
12. generateCard: Fills the specified size of card with random, unique numbers.


## Instructions for running the program
1. Use the following command: g++ -pedantic-errors -std=c++11 *.cpp -o main
2. Run the program in full screen to view the cards properly (especially for cards with a large size)

