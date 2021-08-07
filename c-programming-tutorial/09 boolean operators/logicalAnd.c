#include<stdio.h>

int main(void)
{
    int age;
    char gender;
	
    printf("This program demonstrates how we can use logical AND to combine two conditions in a single statement.\n");
	
    printf("Enter your age:");
    scanf("%d", &age);
	
    printf("Enter your gender, m/f: ");
    scanf(" %c[^\n]", &gender);

    if(age < 30 && gender == 'f')
        printf("Yes, this is a female under 30.\n");
    else
        printf("No, this is not a female under 30.\n");
		
    return 0;
}
