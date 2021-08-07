#include<stdio.h>
#include<stdlib.h>

char* decimalToBinary(long decimal);

int main(void)
{
	int decimal = 14;
	char* binary = decimalToBinary(decimal);
	printf("%d in decimal is %s in binary\n", decimal, binary);
	
	return 0;
}

char* decimalToBinary(long decimal)
{
	char *binary = malloc(65);
	if(binary == NULL)
		exit(1);
	binary += 64;
	*binary = '\0';
	if(decimal == 0)
	{
		--binary;
		*binary = '0';
	}
	else
	{
		while(decimal > 0)
		{
			--binary;
			*binary = decimal % 2 + '0';
			decimal = decimal / 2;
		}
	}
	return binary;
}
