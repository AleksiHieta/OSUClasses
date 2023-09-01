#include <stdio.h>  // for perror
#include <stdlib.h>   // for exit
#include <unistd.h>   // for execv

int* fillArray(int size){
  int i;
  int* ptr = (int*) malloc(sizeof(int) * size);
  for(i = 0; i < size; i++){
    *(ptr+i) = i;
  }
  return ptr;
}


int main(void){
	fillArray(3);



}

