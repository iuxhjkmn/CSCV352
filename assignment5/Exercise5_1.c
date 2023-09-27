/*Exercise5_1
Write a file case conversion program that accepts the name of two files as command line parameters. 
The first parameter is the source file, and the second parameter is the output file. 
The program converts the source file to upper case by reading the text from the source file, 
converting the characters to upper case, and writing the converted text to the output file. 
Use the toupper() function from ctype.h for case conversion. Open both the input file and the output 
file in text mode using fopen(). Make sure to check the return value from fopen(). If one or the other 
file does not open, the program must print a message to the console and exit.
The program should be used as follows:
        ./Exercise5_1 <source_file> <output_file>
Take a screenshot showing the terminal after the program runs. The screenshot should show the output of your 
program. Name the screenshot either Exercise5_1.jpg or Exercise5_1.png, depending on the image type of the 
screenshot file.
When complete, turn in your source code file using the filename Exercise5_1.c 
and your screenshot file named according to the above instruction.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *in, *out;// create a in and out file variable for pointer;
    int ch;//character in in file
    long offset;

    in = fopen("hh.txt", "r+");//open the infile in read and write mode
    out = fopen("hhh.txt", "w" );//open the file in write mode because we are wirte the ch in

    if ( in == NULL || out == NULL )//we want to make sure the files are valid
    {
        printf("error:  unable to open file\n");//print out error message
        exit(1);//exit the program if no valid file
    }

    offset = ftell(in);//define the last location in the file 
    while (1)//while we are not done getting chs
    {
        ch = fgetc(in);//get ch out from infile

        if (ch == EOF)//check if the ch is EOF
            break;

        if( !isalpha( ch ) )//make sure we only want words or letters
        {
            fputc( ch, out );//write the ch to outfile
        }
        else if (isupper(ch))//see if ch is upper 
        {
            fputc(tolower(ch), out );//write the ch to outfile
        }
        else if (islower(ch))//see if ch is lower
        {
            fputc(toupper(ch), out);//write the ch to outfile
        }
    }

    fclose(in);//close in file
    fclose(out);//close out file

    return 0;
}