#include <stdio.h>
#include "source2.c"

int main()
{
	extern int callCount;
	printf("%d\n", callCount);
	someFunction();
	printf("%d\n", callCount);
    return 0;
}
