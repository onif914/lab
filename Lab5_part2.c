/*
 ============================================================================
 Name        : notes
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 *   Functions - Usage Example
 *
 *   0) Display Title and Instructions
 *
 *   1) Generate a random number
 *      a. store random number (compNum)
 *
 *   2) ASk user to guess a number
 *      a. valid numbers: 1 - 10  (integers only)
 *      b. Check for valid input
 *      c. store user input (userNum)
 *
 *   3) Compare user input to random number
 *
 *   4) Display Results
 *   	a. Provide hints (too high / low)
 *
 *   5) Start over if guessed wrong
 */	
 
 /*
 *  	Game Rules: 
 *  	The ship length is between 1-4;
 *	The ship doesn't go out of gaming board and ship would not extend beyond the end of board
 *	Player needs to hit whold ship to sink it, and they have 5 chances
 *  	Player can try until they used up all 5 torpedos.
 *	
 *	
 *
 */

// Function Prototypes
void displayTitle(void);
int generateRandomNum(int range);
int getUserInput(void);
int computeResult(int userNum, int start_position, int end_position, char ship[]);


int main(void) {
	int compNum, userNum, res;
    	char ship[11] = "..........";//display the guess result
	res = 0;
	
    	int count = 0;//The player tries to guess the location for 5 times
	//	  0) Display Title and Instructions
	displayTitle();

	//	 *   1) Generate a ship: ship size, ship start position and end position
	int ship_size_range = 4;//range: (1-4)
	int ship_size = generateRandomNum(ship_size_range);
	int start_location_range = 10 - ship_size_range;
	int start_position = generateRandomNum(start_location_range);
	int end_position = start_position + ship_size - 1;//array start form 0, size start from 1
	
	while(res == 0 && count < 5) {
		//	 *   2) ASk user to guess a number
		userNum = getUserInput();
        	count++;
		//	 *   3) Compare user input to random number
		res = computeResult(userNum, start_position,end_position,ship);
		// start over if guess is wrong
	}
	if(res == 1)//Sink the ship successfully
	{
	    printf("Good Job!\n");
	}
	else
	{
	    printf("You have tried 5 times. Game over!\n");
	    
	}
	//Print the answer to the real ship location.
	printf("Ship Location:\n");
	char real_ship[11] = "..........";
	for(int i = start_position; i<=end_position; i++)
	{
		real_ship[i] = '-';
	}
	printf("%s\n", real_ship);
	return EXIT_SUCCESS;
}

void displayTitle(void) {
	printf("Sink the battleship !\n\n");
	printf("The fire a torpedo...enter a number from 0 to 9, you have 5 chances.");
	printf("\n");
}

int generateRandomNum(int range) {
	int num;
	// seed random number generator
	srand(clock());
	// pick random number
	num = (rand() % range)+1;
	return num;
}

int getUserInput(void) {
	int num;

	while (1) {
		printf("Enter a number between 0 and 9: ");
		fflush(stdout);
		scanf("%d", &num);
		if ((num >= 0) && (num < 10)) {
			break;
		}
	}
	return num;
}

int computeResult(int userNum, int start_position, int end_position, char ship[]) 
{
	if (userNum >= start_position && userNum <=end_position) 
	{
		printf("Boom, A Hit!\n");
		ship[userNum] = 'H';
		printf("%s \n",ship);
		for(int i = start_position; i<= end_position; i++)// check whether the user has shoot the whole ship
		{
			if(ship[i] != 'H')
			{
				return 0;
			}
		}
		return 1;//The whole ship has been shoot by player, return 1
	}
	else 
	{
		printf("Missed, try again.\n");
		ship[userNum] = 'm';
		printf("%s \n",ship);
	}
	return 0;//Missed, return 0;
}
