/*****************************************************
 *
 *  CSCV352 - Exercise4_1.c
 *
 *  Sample Solution
 *
******************************************************/
#include <stdio.h>
#include <string.h>


///////////////////////////////////////////////////////
//                CONSTANTS
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               typedefs and structures
//////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               globalVariables
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//                FunctionPrototypes
///////////////////////////////////////////////////////
int strend(char *s, char *t);
char* TrimRight(char* str, const char* trimChars);

/*****************************************************
 *
 *  Function:  main()
 *
 *  Parameters:
 *
 *      argc - main parameter for argument count
 *      argv - main parameter for argument values
 *
******************************************************/
int main(int argc, char *argv[]) 
{
    char baseString[1000];
	char findString[1000];

    // Obtain the string to search
	printf("Enter a string: ");
	fgets(baseString, sizeof(baseString), stdin);
	TrimRight(baseString, NULL);

    // Obtain the string to search for
	printf("Enter string to search for: ");
	fgets(findString, sizeof(findString), stdin);
	TrimRight(findString, NULL);

    // strend returns 1 if there is a match
	if (strend(baseString, findString))
	{
		printf("Search string was found!!\n");
	}
	else
	{
		printf("Search string was not found.\n");
	}
}

/*****************************************************
 *
 *  Function:  strend()
 *
 *  Parameters:
 *
 *      s - string to search
 *      t - string to search for
 *
******************************************************/
int strend(char *s, char *t)
{
	int retVal = 0;//create return value variable
	while (*s++){//while not reach the last letter yet
        if (*t == *s){// if we find two letters match within these two strings
            while ((*s++ == *t++) && (*t != '\0'));//then we see if the next one is also the same and, the character is not null
			// means there are still more in the test string
			if (*s == '\0' && *t == '\0')//when both reach the end marker, which is a null
			return 1;//we return 1 to show that we find the matching string
		return 0;//otherwise, no matching string found
        }
    }
    
    /* YOUR IMPLMENTATION GOES HERE */

	return retVal;
} 

/******************************************************************************
 *
 * TrimRight()
 *
 * Removes characters from the end of a string, defaults to whitespace
 * characters is trimChars is null.
 *
 *****************************************************************************/
char* TrimRight(char* str, const char* trimChars)
{
	int i;

	if (trimChars == NULL)
	{
		trimChars = "\t\n\v\f\r ";
	}

	i = strlen(str) - 1;
	while (i >= 0 && strchr(trimChars, str[i]) != NULL)
	{
		str[i] = '\0';
		i--;
	}

	return str;
}