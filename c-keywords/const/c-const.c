#include <stdio.h>

void typical_constants();
void modify_constant_with_pointer();
void pointer_to_constant();
void constant_pointer_to_var();

int main()
{
	typical_constants();
	modify_constant_with_pointer();
	pointer_to_constant();
	constant_pointer_to_var();

    return 0;
}

void typical_constants()
{
	// Creating typical constants
	const float pi = 3.14;
	int const size = 10;
	//Uncomment the next row to generate an error. You can't modify a constant
	//size = 15;
	printf("%f\n", pi);
	printf("%d\n", size);
}

void modify_constant_with_pointer()
{
	int const size = 10;
	//Modify a constant through a pointer
	int* ptr_size = &size;
	(*ptr_size)++;
	printf("%d\n", size);
}

void pointer_to_constant()
{
	const float pi = 3.14;
	const float gravity = 9.8;
	// Pointer to a constant - we can change the pointer itself to another variable.
	// We cannot change the contents of the variable to which it points
	const float* ptr_to_constant = &pi;
//	*ptr_to_constant = 0;	// We cannot modify the content of a pointer to constant.
    printf("%f\n", *ptr_to_constant);
	ptr_to_constant = &gravity;
    printf("%f\n", *ptr_to_constant);
}

void constant_pointer_to_var()
{
	int number = 4;
	int count = 0;
	int* const constant_ptr = &count;
	count = 5;
	(*constant_ptr)++;
	printf("%d\n", count);
	//constant_ptr = &count;	// Cannot change the assignment of a constant pointer
}