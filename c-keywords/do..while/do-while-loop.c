#include <stdio.h>

void printMenu();
void handleMenuChoice(int menuChoice);
unsigned long calculateFactorial(int number);

int main()
{
	int menuChoice = 0;
	do
	{
		printMenu();
		scanf("%d", &menuChoice);
		handleMenuChoice(menuChoice);
	}while(menuChoice != 0);

	return 0;
}

void printMenu()
{
	printf("========== MENU ==========\n");
	printf("Input a number to take action:\n");
	printf("1. Input a number to calculate its factorial\n");
	printf("0. Exit\n");
	printf("========== MENU ==========\n");
	printf("Menu choice = ");
}

void handleMenuChoice(int menuChoice)
{
	int number;
	unsigned long factorial;
	if(menuChoice == 1)
	{
		printf("number = ");
		scanf("%d", &number);
		factorial = calculateFactorial(number);
		printf("%d! = %lu \n", number, factorial);
	}
}

unsigned long calculateFactorial(int number)
{
	unsigned long factorial = 1;
	do
	{
		factorial *= number;
		number--;
	}while(number > 0);

	return factorial;
}