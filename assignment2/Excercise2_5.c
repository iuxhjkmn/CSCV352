/*Exercise2_5
*/
#include <stdio.h>

/* */
int main (void)
{
    float hourlywage, groceries, utilities, phone, others, rent,income;//define variables;
    int hours;
    printf("what is your hourly wage? $\n");
    scanf("%f", &hourlywage);//ask for wage
    printf("How many hours per week do you work?\n");
    scanf("%d",&hours);//ask for hours
    if (hours > 40)//depends on the user's input to decide how much the weekly pay is
    {
        income = 40*hourlywage + (hours-40)*hourlywage*1.5;//more than 40 hours
    }
    else{
        income = hourlywage*hours;//less or == 40 hours
    }
    printf("How much do you spend on groceries each week?\n");
    scanf("%f", &groceries);// ask for groceries
    printf("What is your monthly utility bill?\n");
    scanf("%f", &utilities);// utilities
    printf("what is your monthly cell phone bill?\n");
    scanf("%f", &phone);//phone
    printf("What other expense do you have this month?\n");
    scanf("%f", &others);//other
    printf("How much is your rent?\n");
    scanf("%f", &rent);//rent
    if (income*4 >=groceries+utilities+phone+others+rent)//get the monthly pay by *4 
    {
        printf("Yes, you got this!!!!!!\n");//print the message
    }
    else{
        printf("OOPs, you can't pay the rent this month!!");//print the message
    }
    return 0;
}