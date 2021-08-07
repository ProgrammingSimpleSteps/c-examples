#include <stdio.h>

void compareChars(char symbol_1, char symbol_2);
void firstExample();
void printAlphabet();

int main()
{
	printf("First example:\n");
	firstExample();
	printf("\n\n");
	
	printf("Comparing chars:\n");
	compareChars('a', 'b');
	printf("\n\n");
	
	printf("Printing the alphabet and the ASCII codes:\n");
	printAlphabet();
	printf("\n\n");

	return 0;
}

void firstExample()
{
	char symbol = 'A';

	printf("%c", symbol);
}

void compareChars(char symbol_1, char symbol_2)
{
	if(symbol_1 < symbol_2)
	{
		printf("%c is before %c", symbol_1, symbol_2);
	}
	else if(symbol_1 > symbol_2)
	{
		printf("%c is before %c", symbol_2, symbol_1);
	}
	else
	{
		printf("The symbols are the same");
	}
}

void printAlphabet()
{
	char letter;
	for(letter = 'A'; letter <= 'Z'; letter++)
	{
		printf("The code of %c is %d \n", letter, letter);
	}
}