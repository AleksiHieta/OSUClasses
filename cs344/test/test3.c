#include <stdio.h>  // for perror
#include <stdlib.h>   // for exit
#include <unistd.h>   // for execv


int process(int val1, int *val2){
  int temp = val1;
  val1 = *val2;
  *val2 = temp;
  return val1;
}

int main(void) {
  int i = 1;
  int j = 10;

  j = process(i, &j);
  /* value of i and j here */
  printf("i = %d\n", i);
  printf("j = %d\n", j);

}


