/*****************************************
 *
 *	File: keygen.c
 *
 *	Date: 11/28/2021
 *	
 *	Author: Aleksi Hieta
 *
******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char* argv[]){
	srand(time(NULL));

	if(argc != 2){
		fprintf(stderr, "Try Again");
		exit(1);
	}

	int key_length = atoi(argv[1]);

	int key_letter;
	int i;
	for(i = 0; i < key_length; i++){
		key_letter = rand() % 27;

		if(key_letter != 26){
			printf("%c", 'A'+(char)key_letter);
		}
		else{
			printf("%c", ' ');
		}

	}
	printf("\n");

	return 0;
}

