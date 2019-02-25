# lab5
Strings are actually one-dimensional array of characters terminated by a null character '\0'.
If you define:
## char greeting[] = "Hello";
The actually storage has one more character than the word "Hello."
## char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
Therefore, The size of ship array is 11:
## char ship[11] = ".........."

* Actually, if defining 10 will give result "..........@" 
