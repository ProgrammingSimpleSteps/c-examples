#include <stdio.h>

void printNumbers();
void sumEvens();
void findMax();

int main()
{
	printNumbers();
	sumEvens();
	//findMax();

	return 0;
}

void printNumbers()
{
    int i;
    for(i = 1; i <= 10; i++)
    {
        printf("%d ", i);
    }
}

void sumEvens()
{
	int i = 10;
	int sum = 0;
	for(; i < 31; i = i + 2)
	{
		sum += i;
	}
	printf("The sum of the even numbers between 9 and 31 is %d.\n", sum);
}

void findMax()
{	
	int count, i, currentNumber, max;
	printf("How many numbers do you want to compare? ");
	scanf("%d", &count);
	scanf("%d", &max);
	for(i = count; i > 1; i--)
	{
		scanf("%d", &currentNumber);
		if(currentNumber > max)
			max = currentNumber;
	}
	printf("The biggest number is %d\n", max);
}