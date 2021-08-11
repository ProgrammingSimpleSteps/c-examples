#include<stdio.h>

void workingWithFloat();
void floatPrecision();

int main(void)
{
	printf("Working with the float data type\n\n");
	workingWithFloat();
	printf("\n\nMax precision demo:\n\n");
	floatPrecision();
	return 0;
}

void workingWithFloat()
{
	float balance = 1000.55753f;
    float amount;
    printf("Your balance: $%.2f\n", balance);
    printf("How much would you like to withdraw?");
    scanf("%f", &amount);
    if(amount > 0 && amount <= balance)
    {
        balance = balance - amount;
    }
    printf("The new balance is $%.2f", balance);

}

void floatPrecision()
{
	float ok1 = 1234567.0f;
	float ok2 = 1234.5678f;
	float ok3 = 0.12345678f;
	
	float overflow1 = 12345678.9f;
	float overflow2 = 1234.56789f;
	float overflow3 = 0.123456789f;
	
	printf("The following are OK and will work properly:\n");
	printf("1234567.0f: %7.1f\n", ok1);
	printf("1234.5678f: %4.4f\n", ok2);
	printf("0.12345678f: %0.8f\n", ok3);
	
	printf("\nThe following will overflow and will lose data/precision:\n");
	printf("12345678.0f: %8.1f\n", overflow1);
	printf("1234.56789f: %4.5f\n", overflow2);
	printf("0.123456789f: %0.9f\n", overflow3);
}
