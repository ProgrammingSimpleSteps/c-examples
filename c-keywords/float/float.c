#include<stdio.h>

int main(void)
{
	float ok1 = 1234567.0f;
	float ok2 = 1234.5678f;
	float ok3 = 0.12345678f;
	
	float overflow1 = 12345678.9f;
	float overflow2 = 1234.56789f;
	float overflow3 = 0.123456789f;
	
	printf("\nThe following are OK and will work properly:\n");
	printf("1234567.0f: %7.1f\n", ok1);
	printf("1234.5678f: %4.4f\n", ok2);
	printf("0.12345678f: %0.8f\n", ok3);
	
	printf("\nThe following will overflow and will lose data/precision:\n");
	printf("12345678.0f: %8.1f\n", overflow1);
	printf("1234.56789f: %4.5f\n", overflow2);
	printf("0.123456789f: %0.9f\n", overflow3);
}
