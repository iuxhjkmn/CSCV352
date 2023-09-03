/*Exercise2_4
Write a program that creates two seven-element arrays of type double and uses a loop to let the user enter values for each of 
the seven elements of the first array.
Have the program set the elements of the second array to the cumulative totals of the elements of the first array. For example, 
the fourth element of the second array should equal the sum of the first four elements of the first array, and the fifth element of
the second array should equal the sum of the first five elements of the first array. (It’s possible to do this with either nested or 
multiple loops, but by using the fact that the fifth element of the second array equals the fourth element of the second array plus 
the fifth element of the first array, you can avoid multiple loops and just use a single loop for this task.)
Finally, use two loops to display the contents of the two arrays, with the first array displayed on one line and with each element of
the second array displayed below the corresponding element of the first array.
Turn your program in as Exercise2_4.c.
*/
#include <stdio.h>
#define ARRAY_SIZE 7

/* I tried to firgue out why my index never gets updated everyone after looping, but it just never worked. I appreciate if you could explain why 
it doesn't work. Thank you*/
int main (void)
{
    double firstArray[ARRAY_SIZE],secondArray[ARRAY_SIZE];//define the two arrays areused here
    int sum = 0;//the sum used to be added to the second array
    printf("Enter your %d numbers:",ARRAY_SIZE);
    for (int index =0; index<ARRAY_SIZE; index++)//we are supposedly add seven numberrs to the first array.
    {
        scanf("%1f", &firstArray[index]);//each entry will update the index number unless the first entry failed?
    }

    printf("your have entered the numbers as below: \n");
    for (int index=0; index < ARRAY_SIZE; index++)//loop through each element in the first array
    {
        sum+=firstArray[index];//get the relavant values from the first array and sum them up 
        secondArray[index]=sum;//add to the second one
        printf("%15.3f", firstArray[index]);
    }
    printf("\n");//print out the second array
    for (int index=0; index <ARRAY_SIZE; index++)
    {
        printf("%15.3f", secondArray[index]);
    }
    return 0;
}