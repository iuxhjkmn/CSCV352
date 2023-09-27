#include <stdio.h>
#include <string.h>
#define ADULT_TICKET_PRICE 69.00//define constant value
#define CHILD_TICKET_PRICE 35.00
int PurchaseTickets(double *pRemainingCash, int adultTickets, int childTickets);//define the function
int main (void)
{
    double *pRemainingCash;//define parameters
    int adultTickets, childTickets;
    PurchaseTickets(pRemainingCash, adultTickets, childTickets);//call the function in main
}

int PurchaseTickets(double *pRemainingCash,int adultTickets, int childTickets)
{//create the function, this function takes three parameters
//*pRemainingCash is the pointer to the location where the remaining cash is at
//number of tickets for both adult and child 
    int Cash;
    printf("How much money do you have to purchase tickets?\n");
    scanf("%d",&Cash);//get the cash the user has
    printf("How many adult tickets would you like to purchase?\n");
    scanf("%d", &adultTickets);//number of dult tickets
    printf("How many child tickets would you like to purchase?\n");
    scanf("%d", &childTickets); //get the number of child tickets
    int total_Ticket = adultTickets + childTickets;  //get the total tickets
    double remaining = (Cash - (ADULT_TICKET_PRICE*adultTickets + CHILD_TICKET_PRICE*childTickets));//calculate remaining
    pRemainingCash = &remaining;//sign the location of remaining to our pointer parameter

    if ((Cash - (ADULT_TICKET_PRICE*adultTickets + CHILD_TICKET_PRICE*childTickets))<0){//check the condition
        printf("You do not have enough money to purchase the tickets.");// if not enough money
    }
    else{
        printf("You have purchased %d tickets, and you have $%.2lf remainning.", total_Ticket, *pRemainingCash);//when enough, print out the
        //total tickets and remaining of cash.
    }
    return 0;//this function returns 0.
}
