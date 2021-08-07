#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int inputArrayAuto(int array[]);
int inputArrayManual(int array[]);
void copyArray(int fromArray[], int toArray[], int size);
void checkArraySorted(int array[], int size);
void bubbleSortBasic(int array[], int size);
void bubbleSortComparisons(int array[], int size);
void bubbleSortPassesComparisons(int array[], int size);
void shakerSort(int array[], int size);
void printArray(int array[], int size);

int main(void)
{
	int array[100];
	int array2[100];
	int array3[100];
	int array4[100];
	//int size = inputArrayManual(array);
	int size = inputArrayAuto(array);

	copyArray(array, array2, size);
	copyArray(array, array3, size);
	copyArray(array, array4, size);

	//printf("The unsorted array is:");
	//printArray(array, size);
	//printf("\n\n");

	bubbleSortBasic(array, size);
	checkArraySorted(array, size);
	//printf("The sorted array is:");
	//printArray(array, size);
	//printf("\n");

	bubbleSortComparisons(array2, size);
	checkArraySorted(array2, size);
	//printf("The sorted array is:");
	//printArray(array2, size);
	//printf("\n");

	bubbleSortPassesComparisons(array3, size);
	checkArraySorted(array3, size);
	//printf("The sorted array is:");
	//printArray(array3, size);
	//printf("\n\n");

	shakerSort(array4, size);
	checkArraySorted(array4, size);
	//printf("The sorted array is:");
	//printArray(array4, size);
	//printf("\n\n");
}

void copyArray(int fromArray[], int toArray[], int size)
{
	for(int i = 0; i < size; ++i)
		toArray[i] = fromArray[i];
}

int inputArrayAuto(int array[])
{
	int size;
	do
	{
		printf("Enter the size of the array, a number between 1 and 100:");
		scanf(" %d", &size);
	}while(size < 1 || size > 100);

	srand(time(NULL));   // Initialization, should only be called once.
	for(int i = 0; i < size; ++i)
		array[i] = rand();
	return size;
}

int inputArrayManual(int array[])
{
	int size;
	do
	{
		printf("Enter the size of the array, a number between 1 and 100:");
		scanf(" %d", &size);
	}while(size < 1 || size > 100);

	for(int i = 0; i < size; ++i)
	{
		printf("array[%d] = ", i);
		scanf(" %d", &array[i]);
	}
	return size;
}

void checkArraySorted(int array[], int size)
{
	for(int i = 0; i < size - 1; ++i)
	{
		if(array[i] > array[i+1])
		{
			printf("ARRAY IS NOT SORTED at index %d!!!", i);
			exit(1);
		}
	}
}

void printArray(int array[], int size)
{
	for(int i = 0; i < size; ++i)
		printf(" %d", array[i]);
}

void bubbleSortBasic(int array[], int size)
{
	int iterations = 0;
	int temp;
	for(int pass = 1; pass < size; ++pass)
	{
		for(int i = 0; i < size - 1; ++i)
		{
			++iterations;
			if(array[i] > array[i+1])
			{
				temp = array[i+1];
				array[i+1] = array[i];
				array[i] = temp;
			}
		}
	}
	printf("Basic bubble sort finished, using %d iterations.\n", iterations);
}

void bubbleSortComparisons(int array[], int size)
{
	int iterations = 0;
	int temp;
	for(int pass = 1; pass < size; ++pass)
	{
		int swapMade = 0;	//	false
		for(int i = 0; i < size - 1; ++i)
		{
			++iterations;
			if(array[i] > array[i+1])
			{
				temp = array[i+1];
				array[i+1] = array[i];
				array[i] = temp;
				swapMade = 1;
			}
		}
		if(!swapMade)
			break;
	}
	printf("Bubble sort, optimized for comparisons in one pass finished, using %d iterations.\n", iterations);
}

void bubbleSortPassesComparisons(int array[], int size)
{
	int iterations = 0;
	int temp;
	for(int pass = 1; pass < size; ++pass)
	{
		int swapMade = 0;	//	false
		for(int i = 0; i < size - pass; ++i)
		{
			++iterations;
			if(array[i] > array[i+1])
			{
				temp = array[i+1];
				array[i+1] = array[i];
				array[i] = temp;
				swapMade = 1;
			}
		}
		if(!swapMade)
			break;
	}
	printf("Bubble sort, optimized for number of passes and comparisons in one pass finished, using %d iterations.\n", iterations);
}

void shakerSort(int array[], int size)
{
	int iterations = 0;
	int temp;
	int swapMade;
	for(int pass = 1; pass < size; ++pass)
	{
		swapMade = 0;	//	false
		int i = 0;
		for(; i < size - pass; ++i)	//	Rabbits
		{
			++iterations;
			if(array[i] > array[i+1])
			{
				temp = array[i+1];
				array[i+1] = array[i];
				array[i] = temp;
				swapMade = 1;	//	true
			}
		}
		if(!swapMade)
			break;

		--i;
		swapMade = 0;	//	false
		for( ;i > pass; --i)	//	Turtles
		{
			++iterations;
			if(array[i] < array[i-1])
			{
				temp = array[i-1];
				array[i-1] = array[i];
				array[i] = temp;
				swapMade = 1;	//	true
			}
		}
		if(!swapMade)
			break;
	}
	printf("Shaker sort, optimized for number of passes and comparisons in one pass finished, using %d iterations.\n", iterations);
}
