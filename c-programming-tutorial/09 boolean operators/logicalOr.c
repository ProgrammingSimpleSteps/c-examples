#include<stdio.h>

int main(void)
{
    int num1;
    int num2;
	
    printf("This program returns true if the first OR the second number is not 0.\n");
	
    printf("Enter num1 :");
    scanf(" %d", &num1);
	
    printf("Enter num2 :");
    scanf(" %d", &num2);

    if(num1 || num2)
        printf("Yes, at least one of the nubmers is non-zero.\n");
    else
        printf("No, both nubmers are zeros.\n");
		
    return 0;
}
