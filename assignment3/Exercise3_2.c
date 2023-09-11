/* 
Exercise3_2
Write a program that prompts the user for the price of up to 8 items they are purchasing from their favorite online store. 
Stop prompting when the user hits enter or has entered the price for 8 items. Then prompt the user for the local sales tax rate 
(which may be a real number such as 7.5) and calculate the sales tax for the whole purchase.
Display the total purchase price before tax and after tax.
Take a screenshot showing the terminal after the program runs. 
The screenshot should show the output of your program. Name the screenshot either Exercise3_2.jpg or 
Exercise3_2.png, depending on the image type of the screenshot file.
When complete, turn in your source code file using the filename Exercise3_2.c and your screenshot file named according to the above instruction.
*/

#include <stdio.h>
int main(void)
{
    char userinput[100];//variable used to store user input
    float Subtotal=0,total=0;
    float tax;
    float items[8];//variable use store users' input in a foat form
    int n = 8;
    int i =0;
    while (i <n) //won't stop until 8 tiems reached or the user want to quit
    {
        printf("Please enter your number: \n");
        fgets(userinput, sizeof(userinput),stdin);//get the user input
        sscanf(userinput,"%f", &items[0]);//transform the input 
        if ((userinput[0])=='\n')// check if the user want to quit
        {
            printf("Your are now done enter price:\n");
            break;//break if they want to quit
        }
        else
        {
            printf("You enterd $%.2f\n",items[0]);
            Subtotal +=*items;//update the subtotal
        }
        i ++;//update the controller
    }
    //print out results
    printf("Enter sales tax rate percentage: \n");
    scanf("%f", &tax);
    printf("###############################\n");
    printf("Subtotal: %9.2f\n", Subtotal);
    printf("Tax:%15.2f\n", (tax/100)*Subtotal);
    total = Subtotal + Subtotal*(tax/100);
    printf("Total:%13.2f\n", total);

    return 0;
}
