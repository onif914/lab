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
 *
 */

// Function Prototypes
void displayTitle(void);
int generateRandomNum(void);
int getUserInput(void);
int computeResult(int userNum, int compNum, char ships[]);


int main(void) {
	int compNum, userNum, res;
    char ships[11] = "..........";//display the guess result
	res = 0;
	
    int count = 0;//The player tries to guess the location for 3 times
	//	  0) Display Title and Instructions
	displayTitle();

	//	 *   1) Generate a random number
	compNum = generateRandomNum();

	while(res == 0 && count < 3) {

		//	 *   2) ASk user to guess a number
		userNum = getUserInput();
       		count++;

		//	 *   3) Compare user input to random number
		res = computeResult(userNum, compNum,ships);

		// start over if guess is wrong
	}
	if(res == 1)
	{
	    printf("Good Job!\n");
	}
	else
	{
	    printf("You have tried 3 times. Game over!");
	}
	return EXIT_SUCCESS;
}

void displayTitle(void) {
	printf("Sink the battleship !\n\n");
	printf("The fire a torpedo...enter a number from 0 to 9, you have 3 chances.");
	printf("\n");
}

int generateRandomNum(void) {
	int num;
	// seed random number generator
	srand(clock());
	// pick random number
	num = (rand() % 10);
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

int computeResult(int userNum, int compNum, char ships[]) {
	if (userNum == compNum) {
		printf("Boom, A Hit!\n");
		ships[userNum] = 'H';
		printf("%s \n",ships);
		return 1;//Hit return 1
	}
	else {
		if (userNum > compNum)
		    printf("Missed, try Left.\n");
		else
		    printf("Missed, try right.\n");
		ships[userNum] = 'm';
		printf("%s \n",ships);
	}
	return 0;//Missed return 0;
}
