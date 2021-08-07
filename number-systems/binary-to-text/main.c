#include<stdio.h>
#include<stdlib.h>
#include<string.h>

unsigned long binaryToDecimal(char *binary, int length);
void binaryToText(char *binary, int binaryLength, char *text, int symbolCount);
void formatBinary(char *input, int length, char *output);
int validate(char *binary);

int main(void)
{
	char binary[559];
	int binaryLength;
	
    scanf("%558[^\n]s", binary);
	binaryLength = strlen(binary);
	if(validate(binary))
	{
        int symbolCount = binaryLength / 8 + 1;
        char *text = malloc(symbolCount + 1);
        char *formattedBinary = malloc(binaryLength + 1);
        if(text == NULL || formattedBinary == NULL)
            exit(1);
        if(binaryLength % 8 == 0)
            --symbolCount;
            
        formatBinary(binary, binaryLength, formattedBinary);
        binaryToText(formattedBinary, strlen(formattedBinary), text, symbolCount);
		printf("%s in binary is the following text:\n%s\n", binary, text);
        
        free(text);
        free(formattedBinary);
	}
	else
	{
		printf("The input should be a binary number, containing only zeros(0) and ones(1).\n");
	}
	
	return 0;
}

void binaryToText(char *binary, int binaryLength, char *text, int symbolCount)
{
    int i;
    for(i = 0; i < binaryLength; i+=8, binary += 8)
    {
        char *byte = binary;
        byte[8] = '\0';
        *text++ = binaryToDecimal(byte, 8);
    }
    text -= symbolCount;
}

unsigned long binaryToDecimal(char *binary, int length)
{
	int i;
	unsigned long decimal = 0;
	unsigned long weight = 1;
	binary += length - 1;
	weight = 1;
	for(i = 0; i < length; ++i, --binary)
	{
		if(*binary == '1')
			decimal += weight;
		weight *= 2;
	}
	
	return decimal;
}

void formatBinary(char *input, int length, char *output)
{
    while(*input)
    {
        if(*input == '0' || *input == '1')
        {
            *output++ = *input++;
        }
        else
        {
            ++input;
            --length;
        }
    }
    output -= length;
}

int validate(char *binary)
{
	while(*binary)
	{
		if((*binary != '0') && (*binary != '1') && (*binary != ' '))
			return 0;
        ++binary;
	}
	return 1;
}
