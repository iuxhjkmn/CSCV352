/*Exercise5_3
Write a program that populates an array of student records by loading student information from a binary file. 
The input file must be passed into your program as the first command line parameter.
After reading the information, the program must use the student record data to calculate the average grade for 
all students in the class and then display each student’s grade and then the class average. The output of the 
program should be formatted as follows:
Name                            Email                       Grade 
---------------------------------------------------------------------------------
<last name>, <first name>       <email>                       <grade>
Class Average: <average grade>
Make sure to print the name in <last name>, <first name> order. The following structure and associated constants 
must be used to represent the student:
#define MAX_NAME 60 #define MAX_EMAIL_ADDRESS 250
#pragma pack(1) typedef struct {
char firstName[MAX_NAME];
char lastName[MAX_NAME];
char middleName[MAX_NAME];
char emailAddress[MAX_EMAIL_ADDRESS];
int grade; // on a 100% scale
} StudentInformation;
Note the use of #pragma pack(1) to remove any padding the compiler might use when defining the structure. 
Student records in the file should be read in binary mode, reading individual student entries one by one with fread(). 
This means that each student record entry in the file takes up sizeof(StudentInformation) bytes. Make sure to check the 
return value from fopen(). If one or the other file does not open, the program must print a message to the console and exit.
A sample input file is provided.
Take a screenshot showing the terminal after the program runs using the provided input file as input. 
The screenshot should show the output of your program. Name the screenshot either Exercise5_3.jpg or Exercise5_3.png, 
depending on the image type of the screenshot file.
When complete, turn in your source code file using the filename Exercise5_3.c and your screenshot file named according to the above instruction.
*/