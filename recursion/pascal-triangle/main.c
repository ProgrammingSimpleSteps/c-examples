#include <stdio.h>

int main(void)
{
	printf("This program will output the Pascal triangle.\n");
	printf("Enter lines count:");
	int lines;
	scanf(" %d", &lines);
	
	int size = (lines * (lines+1)) / 2;
	int pascalArray[size];

	for(int line = 0; line < lines; ++line)
	{
		int lineEnd = (line * (line + 1)) / 2 - 1;
		int lineStart = lineEnd - line;
		
		for(int index = line; index <= lineEnd; ++index)
		{
			int left = 0;
			int right = 0;
			int leftIndex = index - (line + 1);
			int rightIndex = index - line;
			
			if(leftIndex >= 0)
				left = pascalArray[leftIndex];
			//if(rightIndex  )
				right = pascalArray[rightIndex];
			pascalArray[index] = left + right;
			printf("%d ", pascalArray[index]);
		}
		printf("\n");
	}
}
