#include<stdio.h>

void charDemo();
void intDemo();
void floatDemo();
void doubleDemo();

int main(void)
{
	charDemo();
	intDemo();
	floatDemo();
	doubleDemo();
}

void charDemo()
{
	printf("Interpreting chars as characters: ");
	printf("%c %c %c", 'a', '1', ';');
	printf("\n\n");
	printf("Interpreting ints as characters: ");
    printf("%c, %c, %c", 65, 32, 66);
	printf("\n\n");
	printf("Char arithmetic: ");
    printf("%c %c %c", 'a', 'a'+1, 'a'+2);
	printf("\n============================\n");
}

void intDemo()
{
	printf("Interpreting int as int: ");
	printf("%d", 5);
	printf("\n\n");
	printf("Using a calculation as an int: ");
	printf("%d", 5+6);
	printf("\n\n");
	printf("Interpreting chars as int: ");
	printf("%d %d %d", 'A', 'Z', 'a');
	printf("\n============================\n");
}

void floatDemo()
{
	printf("Printing a float value: ");
	printf("%f", 9.95f);
	printf("\n\n");
	printf("Using a float with fixed precision: ");
	printf("%.2f", 9.95f);
	printf("\n\n");
	printf("Float overflow - lost precision: ");
	printf("%f", 9.9876543210f);
	printf("\n============================\n");
}

void doubleDemo()
{
	printf("Double doesn't overflow with the same value, but printf doesn't show it all: ");
	printf("%lf", 9.9876543210d);
	printf("\n\n");
	printf("Printing a double with higher precision: ");
	printf("%.10lf", 9.9876543210d);
	printf("\n\n");
	printf("Using double by default(no 'd' specificator: ");
	printf("%lf", 9.9876543210);
	printf("\n============================\n");
}
