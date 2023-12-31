/*Exercise5_2
Write a program that outputs a user-specified portion of a text file. The program has three parameters which are:
• the name of the file to display,
• the byte offset to begin printing from, and
• the number of bytes to print.
The usage of the program must be implemented as follows:
      ./Exercise5_2. <filename> <starting_offset> <max_chars_to_print>
Where filename is the name of an existing text file, starting_offset is the position in the file to begin printing from, 
and max_chars_to_print is the maximum number of characters to output to the screen. The file should stop printing if the 
end of file is reached before the maximum number of characters are displayed.
The program should open the specified file and begin printing the file’s contents starting at the specified position. 
The program should stop printing when reaching:
- the maximum number of characters specified by the user, or
- the end of the file.
Once the printing is complete, the program should exit.
Take a screenshot showing the terminal after the program runs. The screenshot should show the output of your program. 
Name the screenshot either Exercise5_2.jpg or Exercise5_2.png, depending on the image type of the screenshot file.
When complete, turn in your source code file using the filename Exercise5_2.c and your screenshot file named according 
to the above instruction.
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
      if (argc != 4)
      {
      //check if we pass the right number of arguments
            return 1;

      }
      char *extraChars = NULL;
      long startingOffset;
      if((startingOffset = strtol(argv[2], &extraChars, 10) ==0 && argv[2][0] != '0') || *extraChars != 0)
      {
            printf("Invalid input, exiting program");
            return 1;
      }

      FILE *in = fopen(argv[1], "rb");//open the infile in read binary mode
      if ( in == NULL)//we want to make sure the files are valid
      {
            printf("error:  unable to open file\n");//print out error message
            return 1;//exit the program if no valid file
      }
      long last = ftell(in);//file length
      long count;
      char ch;
      long maxmum = strtol(argv[3], &extraChars, 10);
      fseek(in, startingOffset, SEEK_SET);
      for (count = startingOffset; count <= maxmum; count++ )
      {
            fseek(in, +count, SEEK_SET);//from start point to end point
            ch = getc(in);
            if (ch != EOF)
                  putchar(ch);
      }
     
      putchar('\n');
      fclose(in);

}