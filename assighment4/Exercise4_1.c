/*****************************************************
 *
 *  CSCV352 - Exercise4_1.c
 * Exercise4_1
Write the function int strend(s, t), which returns 1 if the string t occurs at the end of the string s, 
and returns zero otherwise. Implement the function using the provided Exercise4_1.c file. 
The provided program tests your function by first prompting the user for the string to search and then 
promoting the user for the string to search for. The program calls your strend() with the user’s input and 
displays a message indicating that the string was found or was not found. The strend() function must not 
print any information to the console. The only output from this program should be from the provided program.
Take a screenshot showing the terminal after the program runs. The screenshot should show the output of your program. 
Name the screenshot either Exercise4_1.jpg or Exercise4_1.png, depending on the image type of the screenshot file.
When complete, turn in your source code file using the filename Exercise4_1.c and your screenshot file named according 
to the above instruction.
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
	int retVal = 0;
	int i = 0;
	while (i<strlen(t))
	{
		if (strlen(t) > strlen(s))
		{
			return retVal;
		}
		else
		{

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