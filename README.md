# lab5
Strings are actually one-dimensional array of characters terminated by a null character '\0'.
If you define:
## char greeting[] = "Hello";
The actually storage has one more character than the word "Hello."
## char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
Therefore, when defining the array for ships, I defined:
## char ship[11] = ".........."
