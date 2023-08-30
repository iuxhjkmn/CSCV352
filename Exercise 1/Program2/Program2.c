

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[])
{
  int fahr, kelvin;
  time_t t;

  /* Intializes random number generator */
  srand((unsigned) time(&t));

  for (int i = 0; i < 10; ++i)
  {
      
      fahr = rand() % 300;
      
      kelvin = 5 * (fahr+459.67) / 9;

      printf("%d\t%d\n", fahr, kelvin);
  }

  return 0;
}
