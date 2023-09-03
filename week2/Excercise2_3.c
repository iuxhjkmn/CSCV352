/*Exercise2_3
Write a program that asks the user to enter a height in centimeters and then displays the height in centimeters and in feet and inches. Fractional centimeters and inches should
be allowed, and the program should allow the user to continue entering heights until a nonpositive value is entered. Assume 2.54 centimeters to an inch. A sample run should look like this:
Enter a height in centimeters (<=0 to quit): 182 182.0 cm = 5 feet, 11.7 inches
Enter a height in centimeters (<=0 to quit): 168.7 168.7 cm = 5 feet, 6.4 inches
Enter a height in centimeters (<=0 to quit): 0 bye
Turn your program in as Exercise2_3.c.
*/
#include <stdio.h>
#define CM_TO_INCH 2.54 //create instant value for later use
#define IN_TO_FOOT 12

/*call the function in main function with some modification on the printing result*/
int main (void)
{
    float height_cm, height_in,height_left_in;//define variables 
    int height_ft;
    printf("Hi, please enter your height in cm, (Or enter 0 to quit):");
    while (1)//while the user doesn't want to stop
    {
        scanf("%f",&height_cm);//get the user input for height

        if (height_cm <=0)
        {
            printf("BYe\n");
            return 0;
        }
        height_in = height_cm/CM_TO_INCH;// convert values
        height_ft = (height_in/IN_TO_FOOT);
        height_left_in= height_in - (IN_TO_FOOT*height_ft);
        printf("Hi, you are %.1f cm = %d feet, %.1f inches\n\n", height_cm, height_ft, height_left_in);//show result
    }
    return 0;
}