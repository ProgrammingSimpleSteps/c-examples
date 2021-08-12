#include <stdio.h>

void exitFromNestedLoops(int rows, int columns);
void loopUsingGoto();

int main()
{
	//exitFromNestedLoops(12,12);
	loopUsingGoto();
	return 0;
}

void exitFromNestedLoops(int rows, int columns)
{
	int row, column;
	for(row = 0; row < rows; row++)
	{
		for(column = 0; column < columns; column++)
		{
			if((row+column) > 20)
				goto exit;
			printf("%2d ", row + column);
		}
		printf("\n");
	}
	exit:
	printf("Exit\n");
}

void loopUsingGoto()
{
	int i = 0;
begin:
	printf("i = %d\n", i);
	i++;
	if(i >= 10)
		goto end;
	goto begin;
end:
	printf("quit\n");
}