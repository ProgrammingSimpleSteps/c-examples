#include<stdio.h>
#include<string.h>

#define INVALID_INPUT 0
#define VALID_INPUT 1
#define VALID_PREFIX 3

unsigned long hexToDecimal(char *hex, int length, int validation);
int validate(char *hex, int length);
int valueOf(char digit);

int main(void)
{
	char hex[17];
	int length;
	unsigned long decimal;
	
	scanf("%16s", hex);
	length = strlen(hex);
    int validation = validate(hex, length);
	if(validation)
	{
		decimal = hexToDecimal(hex, length - 1, validation-1);
		printf("%s in hexadecimal is %lu in decimal\n", hex, decimal);
	}
	
	return 0;
}

unsigned long hexToDecimal(char *hex, int lastPosition, int startPosition)
{
	int position;
	unsigned long decimal = 0;
	unsigned long weight = 1;
	hex += lastPosition;
	weight = 1;
	for(position = startPosition; position <= lastPosition; ++position, --hex)
	{
		int coefficient = valueOf(*hex);
		if(coefficient >= 0)
		{
			decimal += weight * coefficient;
			weight *= 16;
		}
		else
		{
			return 0;
		}
	}
	
	return decimal;
}

int validate(char *hex, int length)
{
    int result = VALID_INPUT;
    if(length > 2)
    {
        if(hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
        {
            hex += 2;
            result = VALID_PREFIX;
        }
    }
    while(*hex != '\0')
    {
        if(*hex < '0' || (*hex > '9' && *hex < 'A') || (*hex > 'F' && *hex < 'a') || *hex > 'f')
        {
            printf("The input should be a hexadecimal number, containing only digits(0-9) and the first 6 letters(a-f).\n");
            result = INVALID_INPUT;
            break;
        }
        else
        {
            hex++;
        }
    }
    
    return result;
}

int valueOf(char digit)
{
    switch(digit)
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
            printf("Cannot decode that symbol: %c", digit);
            return -1;
        }
    }
}
