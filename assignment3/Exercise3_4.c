/* 
Exercise3_4
Write a program the calculates interest earned on money in a bank savings account or in another type of investment such as a bond or Certificate of Deposit (CD). 
The program prompts the user for the following information and in the following order:
• Present Value (PV):
• Interest Rate (r):
• Time (t):
the initial deposit amount
the annual interest rate earned
the number of years the money is in the account
Make sure to collect information in order of: Present Value, Interest Rate, and Time.
The program calculates and then displays the value of the account after the specified number of years pass. A simple interest rate calculation should be used:
Future Value (FV) = PV(1 + rt)
Take a screenshot showing the terminal after the program runs. The screenshot should show the output of your program. 
Name the screenshot either Exercise3_4.jpg or Exercise3_4.png, depending on the image type of the screenshot file.
When complete, turn in your source code file using the filename Exercise3_4.c and your screenshot file named according to the above instruction.

*/

#include <stdio.h>
int getInt(void);//get int number from user as well as checks the input to make sure its valid
float getFloat(void);// get float input from user
int main(void)
{
    float futureV, interestR;// create vaiables 
    int presentV, time;

    printf("Enter the initial deposit amout: \n");
    presentV = getInt();// call the function to get the first user input
    printf("Enter the annual interest rate earned: \n");
    interestR = getFloat();//call the function to get the interest rate
    printf("Enter the number of years the money is in the account: \n");
    time = getInt();// get the years by calling this function
    futureV = presentV*(1+((interestR/100)*time));//formula to get the interesetc
    printf("After %d years of investment, you are expecting to get $ %.2f\n", time, futureV);

}
int getInt(void)//get a positive int number from the user
{
    int input;
    int ch;//used to check input buffer
    while (1)
    {//check the input are only int numbers and they are greater than 0
        if ((scanf("%d", &input) != 1) || (input < 0) || ((ch = getchar()) != '\n' && ch != EOF))
        {
            printf("Invalid input, only integers are allowed, try again: \n");
            while ((ch = getchar()) != '\n' && ch != EOF){}//flush input buffer
        }
        else
        {
            return input;//the input we need 
        }
    }
}
float getFloat(void)// get a positive float number form the user
{
    float input;
    int ch; //used to check the input buffer
    while (1)
    {
        //check the input if they are we needed or not and we are making sure that only float 
        //are used here as input
        if ((scanf("%f", &input) != 1) || (input<0) || ((ch = getchar()) != '\n' && ch != EOF))
        {
            printf("Invalid input. Please enter a float and tru again: \n");
            while ((ch = getchar()) != '\n' && ch != EOF){}//flush input buffer, no garbage read in the next buffer
        }
        else
        {
            return input;//valid input
        }
    }

}
