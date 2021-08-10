#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int validate(char *hex);
int valueOf(char symbol);
char* hexToAscii(char hex[]);

int main(void)
{
	char hex[559];
	
	printf("Enter hex code to be converted to text: ");
    scanf("%558[^\n]s", hex);
	if(validate(hex))
	{
		char* text = hexToAscii(hex);
		printf("The hex encoded text is:\n %s", text);
		free(text);
	}
	else
	{
		printf("The input should be a hex number, containing 0..9 and A..F.\n");
	}
}

char* hexToAscii(char hex[])
{
	int hexLength = strlen(hex);
	char* text = NULL;
        
	if(hexLength > 0)
	{
		int symbolCount;
		int oddHexCount = hexLength % 2 == 1;
		if(oddHexCount)
			symbolCount = (hexLength / 2) + 1;
		else
			symbolCount = hexLength / 2;
		
		text = malloc(symbolCount + 1);
		
		int lastIndex = hexLength - 1;
		for(int i = lastIndex; i >= 0; --i)
		{
			if(((lastIndex - i) % 2 != 0))
			{
				int dec = 16 * valueOf(hex[i]) + valueOf(hex[i+1]);
				if(oddHexCount)
					text[i/2+1] = dec;
				else
					text[i/2] = dec;
			}
			else if(i == 0)
			{
				int dec = valueOf(hex[0]);
				text[0] = dec;
			}
		}
		text[symbolCount] = '\n';
    }
    return text;
}
  
int valueOf(char symbol)
{
	switch(symbol)
	{
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		case 'A':
		case 'a': return 10;
		case 'B':
		case 'b': return 11;
		case 'C':
		case 'c': return 12;
		case 'D':
		case 'd': return 13;
		case 'E':
		case 'e': return 14;
		case 'F':
		case 'f': return 15;
		default:
		{
			printf("Cannot decode that symbol: %c", symbol);
			return -1;
		}
	}
}

int validate(char* hex)
{
	printf("Validating: ");
	while(*hex)
	{
		printf("%c", *hex);
		switch(*hex)
		{
			case '0': 
			case '1': 
			case '2': 
			case '3': 
			case '4': 
			case '5': 
			case '6': 
			case '7': 
			case '8': 
			case '9': 
			case 'A':
			case 'a': 
			case 'B':
			case 'b': 
			case 'C':
			case 'c': 
			case 'D':
			case 'd': 
			case 'E':
			case 'e': 
			case 'F':
			case 'f': break;
			default:
			{
				printf(" ..Failed.\n");
				return 0;
			}
		}
		++hex;
	}
	printf(" ..OK.\n");
	return 1;
}
