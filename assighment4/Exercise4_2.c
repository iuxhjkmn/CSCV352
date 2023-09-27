#include <stdio.h>
#include <string.h>


int main ()
{
    int year;//create variable year
    printf("Please enter the year you want to check: \n");
    scanf("%d", &year);//get the user input
    if (year%4 != 0)//check the first condition
    {
        printf("%d is a common year!\n", year);
    }else if (year%100 != 0)//check the second condition
    {
        printf("%d is a leap year!\n",year);
    }else if(year%400 != 0)//check the third condition
    {
        printf("%d is a common year!\n",year);
    }else//if none above included, then must be a leap year.
    {
        printf("%d is a leap year!\n",year);
    }
}