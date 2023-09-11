/* 
Exercise3_5
Write a program that reads characters from the standard input to end-of-file. 
For each character read, have the program print the ASCII value of the character in hexadecimal form and report whether or not the character is a letter. 
If it is a letter, also report its numerical location in the alphabet. For example, c and C would both be letter 3. 
Your implementation must incorporate a function that takes a character as an argument and returns the numerical location 
in the alphabet if the character is a letter or returns –1 if the character is not a letter.
Take a screenshot showing the terminal after the program runs. The screenshot should show the output of your program. 
Name the screenshot either Exercise3_5.jpg or Exercise3_5.png, depending on the image type of the screenshot file.
When complete, turn in your source code file using the filename Exercise3_5.c and your screenshot file named according to the above instruction.
*/

#include <stdio.h>
int GetLetterPosition(char ch);//call the function
int main(void)
{
    printf("enter the character: \n");
    char ch;
    while ((ch=getchar()) != '\n' && ch != EOF)
    {// won't stop the loop until we are done getting every letter
 //we only want letters not space or new line
        
        int location = GetLetterPosition(ch);//variable to stroe the location
        //print out the results
        printf("The letter is : ");
        putchar(ch);
        printf(". ");
        printf("The location is at %d\n", location);

    }
    return 0;
}
int GetLetterPosition(char ch)
{//create a function to loop through the string that the user put in
    int pos;
    if (ch >= 'A' && ch <= 'Z')//check if the letter is capital or not
    {
        for (int pos = 'A'; pos <= 'Z'; pos++)
        {
            if(ch ==pos)//check if it is the same letter
            {
                break;
            }
        }
    }
    else if (ch >= 'a' && ch <= 'z')//when they are in low case, but i don't why this loop never run
    {
        for (int pos = 'a'; pos<= 'z'; pos++)
        {
            if (ch =pos)
            {
                break;
            }
        }
    }
    else
    {
        pos+=ch;
        return pos;//return the position we are looking for
    }
}

