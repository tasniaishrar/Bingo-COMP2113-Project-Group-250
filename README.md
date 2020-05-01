# COMP2113 Course Project (Group 250)

## Team members
1. RAHMAN Tasnia Ishrar • 3035718187
2. ZAKARIA Atiab Bin • 3035718230

## Game description and rules
User inputs the amount of money they have and the size of the card they want to purchase. The size input has to be more than or equal to 5 (5x5 card) and less than or equal to 50 (50x50 card). Each size range of the card has a specific price (in-game currency). Error will be generated until user can afford the specified size of card and the size input is within the aforementioned range. 

The randomly generated card of the specified size will be displayed on the screen. Two options are available to user: 1. “Next Number” and 2. “Claim Bingo”. “Next Number” will generate and display a random number and replace that number on the card with an asterisk. User has to keep track if there are any whole rows, columns or diagonals of asterisks and select “Claim Bingo”. Program will check the claim and display congratulatory/error message depending on the result of the check. If the claim is valid, the program will display the prize money the player wins, which will be set according to the size range of the card. The game will be reset with a new card if the claim was false (as a penalty). If the card is full of asterisks but the user still does not claim bingo, an automatic message such as "You could've won $ xyz. We hope you will claim bingo in due time in the next game. Good luck!" will be generated.
User will have the option to save a log of the game at the end.

## Requirements fulfillment
1. Generation of random game sets or events
    - Generate random numbers to fill the card initially.
    - Generate a random number when ‘Next number’ is selected.
    
2. Data structures for storing game status
    - 2D arrays
    
3. Dynamic memory management
   - Since the size of the card is only found at runtime, dynamically allocated arrays will need to be used to store the card’s values.
   
4. File input/output (e.g., for loading/saving game status)
    - The whole game status can be output to a file for future reference.
    
5. Program codes in multiple files
    - The card price chart will be in a different text file. It will be fetched in the main program to calculate the amount of change         the user will receive or to check if the user can afford the specified size of card.
