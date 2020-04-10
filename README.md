# COMP2113 Course Project (Group 250)

## Team members
1. RAHMAN Tasnia Ishrar • 3035...
2. ZAKARIA Atiab Bin • 3035718230

## Game description and rules
User inputs the amount of money they have and the number of cards they want to purchase. Each card costs $5 (in-game currency). Error will be generated until user can afford the specified number of cards. Next, user will be prompted to define the size of the (square) card they want to play with.

Specified number of randomly generated cards of the specified size will be displayed on the screen. Two options are available to user: 1. “Next Number” and 2. “Claim Bingo”. “Next Number” will generate and display a random number and replace that number on all the boards with an asterisk. User has to keep track if there are any whole rows, columns or diagonals of asterisks and select “Claim Bingo”. Program will check the claim and display congratulatory/error message depending on the result of the check. The game will be reset with a new card if the claim was false. Program will automatically show congratulatory message only when any one of the cards are full of asterisks. User will have the option to save a log of the game at the end.

## Requirements fulfillment
1. Generation of random game sets or events
    - Generate random numbers to fill the cards initially.
    - Generate a random number when ‘Next number’ is selected.
    
2. Data structures for storing game status
    - 2D arrays
    
3. Dynamic memory management
   - Since the size of the card is only found at runtime, dynamically allocated arrays will need to be used to store the card’s values.
   
4. File input/output (e.g., for loading/saving game status)
    - The whole game status can be output to a file for future reference.
    
5. Program codes in multiple files
    - Separate different functions into different files
