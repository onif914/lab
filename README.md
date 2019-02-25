# lab5
## Part One
### 1. ship size
#### Strings are actually one-dimensional array of characters terminated by a null character '\0'.
#### If you define:
```
char greeting[] = "Hello";
```
#### The actually storage has one more character than the word "Hello."
```
char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
```
#### Therefore, The size of ship array is 11:
```
char ship[11] = ".........." //10 dots
```
* Actually, if defining 10 and print it out,  the result will be 10 dots with a weird character at the end"..........@" 

### 2.in this code, function names:
#### initBoard() --- generateRandomNum(void);
#### showGameBoard() + updateBoard() --- computeResult();

### 3. An example of passing array to function
```
float average(float age[]);
int main()
{
	float avg, age[] = {23.4, 55, 22.6, 3, 40.5, 18};
	avg = average(age); // Only name of an array is passed as an argument
	printf("Average age = %.2f", avg);
	return 0;
}
float average(float age[])
{
	int i;
	float avg, sum = 0.0;
	for (i = 0; i < 6; ++i) {
		sum += age[i];
	}
	avg = (sum / 6);
	return avg;
}
```
## Part Two
### This part is not realized in the code
'''
For example,inagame with only five maximum guesses,you can’t win if you miss the first two tries and the ship is four spaces long.
'''
