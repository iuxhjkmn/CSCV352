/*Exercise2_2
Write a program that requests two integer values from the user. The program then calculates c in the following formula:
c=a3+b
where a and b are the two numbers that the user entered. The program must print to the console the calculated value of c.
The program must also include error checking. If the user does not enter a valid integer, the program must print a message for 
the user and exit without performing the calculation.
*/
#include <stdio.h>

/*call the function in main function with some modification on the printing result*/
int main (void)
{
    int a, b,c;//create variables 
    int e;

    printf("Please enter your first integer: ");//ask the user to put number in
    if (scanf("%d %d",&a, &b) !=2)//founction to add the nubers
    {
        printf("Invalid input, no integer found. Exiting program\n");// remin dthe user there is a error
        return 1;
    }
    else //trying to know if there is anything else in there besides interger.
    {
        while ((e=getchar())!= '\n' && e != EOF)
        {
            printf("Invalid input, extra characters found in input buffer after the integer. Exiting program\n");
            return 1;

        }
       
    }
    
    printf("%s%s%s", "a^3 + ", "b = ", "c\n");//print out the result
    printf("%d^3 + %d = %d\n",a,b,a*a*a+b);
    return 0;
}