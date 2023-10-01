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
        printf("Usage: %s <filename> <starting_offset> <max_chars_to_print>\n", argv[0]);
        return 1;
    }

    char *endPtr;
    long startingOffset = strtol(argv[2], &endPtr, 10);
    if (*endPtr != '\0' || startingOffset < 0)
    {
        printf("Invalid starting offset, exiting program\n");
        return 2;
    }

    long maxCharsToPrint = strtol(argv[3], &endPtr, 10);
    if (*endPtr != '\0' || maxCharsToPrint <= 0)
    {
        printf("Invalid max_chars_to_print value, exiting program\n");
        return 3;
    }

    FILE *in = fopen(argv[1], "r");
    if (in == NULL)
    {
        printf("Error: Unable to open file %s\n", argv[1]);
        return 4;
    }

    fseek(in, startingOffset, SEEK_SET);
    char *buffer = (char *)malloc(maxCharsToPrint + 1); // +1 for null terminator
    if (buffer == NULL)
    {
        printf("Memory allocation failed, exiting program\n");
        fclose(in);
        return 5;
    }

    size_t bytesRead = fread(buffer, 1, maxCharsToPrint, in);
    buffer[bytesRead] = '\0'; // Null-terminate the string

    printf("%s", buffer);

    free(buffer);
    

    fclose(in);

    return 0;
}
