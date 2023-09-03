/*Write a program that produces the following output:
        U2, R.E.M., Counting Crows, Matchbox Twenty
        Counting Crows, Matchbox Twenty
        U2, R.E.M.
Have the program use two user-defined functions in addition to main(): one named eighties() that prints “U2, R.E.M.” once, and one named nineties() that prints “Counting Crows, Matchbox Twenty” once. The band group names must be printed within the respective function. Let main() control the printing process and take care of any additional printing or formatting tasks.
Turn your program in as Exercise2_1.c.
*/
#include <stdio.h>

/* define the function and what the function will do*/
void eighties(void)//first function to print the first part
{
    printf("U2, R.E.M.");
}
void nighties(void)//second function to print the second part of string
{
    printf("Counting Crows, Matchbox Twenty");
}
/*call the function in main function with some modification on the printing result*/
int main (void)
{
    eighties ();// call defined functions to print out idea results
    printf(", ");
    nighties ();
    printf("\n");
    nighties ();
    printf ("\n");
    eighties ();

    return 0;
}
