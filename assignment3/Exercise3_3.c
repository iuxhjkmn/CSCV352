/* 
Exercise3_3
Write a program that reads data from standard input as a stream of characters until the program encounters the End-of-File or EOF. 
The program then reports the average number of letters per word from the data that was read. Don’t include whitespaces in calculations for word 
length.Test the program by piping the contents of the provided Exercise3_3.txt file as input into your program.
Take a screenshot showing the terminal after the program runs with the test file. The screenshot should show the output of your program. 
Name the screenshot either Exercise3_3.jpg or Exercise3_3.png, depending on the image type of the screenshot file.
When complete, turn in your source code file using the filename Exercise3_3.c and your screenshot file named according to the above instruction.
*/

#include <stdio.h>
int main(void)
{
    char ch;// words in file
    char filename[100];//store file name
    FILE *fp;//file variable
    int nWords = 0, nLetters = 0;//create variables to store data
    printf("Enter the file name: \n");
    gets(filename);//get the filename as input
    fp = fopen(filename, "r");//open the file
    if (fp != NULL)//run only when file is real not NULL
    {
        while ((ch = fgetc(fp)) != EOF)//loop until reaching the end point of file
        {
            if (ch== '\n')//check each word
            {
                nWords ++;//update the number of words
            }
            else if (ch == ' ')
            {
                nWords ++;
            }
            else{
                nLetters ++;//update total number of letters
            }
        }
    }
    else
    {
        printf("Invalid filename, now exiting the program!");
        return 1;//exit if no file read
    }
    //print out results
    printf("The total word count is: %15d\n", nWords);
    printf("The average word length is: %10d\n", nLetters/nWords);
    fclose(fp);
    return 0;
}

