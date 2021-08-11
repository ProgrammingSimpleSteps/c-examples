#include<stdio.h>

void printNumbers(void);
void infiniteLoop(void);
void readFile(void);

int main(void)
{
	//printNumbers();
	//infiniteLoop();
	readFile();

	return 0;
}

void printNumbers(void)
{
	int i = 1;
	while(i <= 10)
	{
		printf("%d\n", i);
		++i;
	}
}

void infiniteLoop(void)
{
	while(1)
	{

	}
}

void readFile(void)
{
	FILE *fp = fopen("numbers.txt", "r");
	int symbol;
	if (fp == NULL)
	{
        perror("Cannot open file numbers.txt");
        return;
    }
	else
	{
		while ((symbol = fgetc(fp)) != EOF)
		{
			printf("%c", symbol);
		}
		fclose(fp);
	}
}