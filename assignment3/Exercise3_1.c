/* 
Exercise3_1
Write a program that reads text from standard input until encountering either the ~ character or the ^ character and 
then reports the number of spaces read, the number of newline characters read, the number of period (.) characters read, and the number of all other characters read.
Test the program by piping the contents of the provided Exercise3_1.txt file as input into your program.
Take a screenshot showing the terminal after the program runs with the provided test file. The screenshot should show the output of your program. 
Name the screenshot either Exercise3_1.jpg or Exercise3_1.png, depending on the image type of the screenshot file.
When complete, turn in your source code file using the filename Exercise3_1.c and your screenshot file named according to the above instruction. 
*/

#include <stdio.h>

int main(void)
{//create variables 
    char ch;
    char filename[100]; //store file name
    FILE *fp;//file variable
    int nSpace = 0; int nLine = 0; int nPeriod = 0; int allOther = 0;
    printf("Enter File Name: ");
    gets(filename);
    fp=fopen(filename, "r");//open the file
    if (fp != NULL)
    {
        while ((ch=fgetc(fp))!= EOF)// check every characters in the file and update our data
        {////////////////////////////QUESTION: I spent a long time trying to use ch = fgetc(fp)!= '~' && c != '^', but it won't work
        ///////////////////////its says comparison between pointer and int, so i had to use EOF. So what is ch then if I am using fgetc(fp), is that a pointer?
            if (ch==' ')////////////ALSOO, I tried to use switch and case, but it didn't work neither. 
            {
                nSpace ++;
            }
            else if (ch == '\n')//check each condition
            {   
                nLine ++;
            }
            else if (ch == '.')
            {
                nPeriod ++;
            }
            else
            {
                allOther ++;
            }
            
        }
        //print out the results
        printf("we have found the following: \n");
        printf("Space: %d\n", nSpace);
        printf("New Line:%d\n", nLine);
        printf("Period: %d\n", nPeriod);
        printf("All Characters: %d\n", allOther);
        fclose(fp);

    }
    else
    {
        printf("no file found");
    }
    
    return 0;
}
