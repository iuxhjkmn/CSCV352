/*****************************************************
 *
 *  CSCV352 - Program1.c
 *
 *  Student:  <Kang Zheng>
 *
******************************************************/
#include <stdio.h>

///////////////////////////////////////////////////////
//                CONSTANTS
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               typedefs and structures
//////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               globalVariables
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//                FunctionPrototypes
///////////////////////////////////////////////////////

/*****************************************************
 *
 *  Function:  main()
 *
 *  Parameters:
 *
 *      argc - main parameter for argument count
 *      argv - main parameter for argument values
 *
******************************************************/
char *reason()
{
  return "fun";
}
int main(int argc, char *argv[]) 
{

  printf("---- CSCV 352 Fall 2023 ----\n\n");

  printf("Hello Students, \n");

  printf("Welcome to the world of C programming!\n");

  printf("We like to program in C because it is %s.\n", reason);
  
  return 0;
}
