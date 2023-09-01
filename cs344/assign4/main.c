/*************************************
 *
 *	Assignment 4
 *
 *	Author: Aleksi Hieta
 *
 *	Date: 11/3/21
 *
 *	Description: Consumer Producer Pipeline
 *
 ************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

pthread_mutex_t mutex_buffer1;
pthread_mutex_t mutex_buffer2;
pthread_mutex_t mutex_buffer3;
pthread_mutex_t mutex_buffer_in_out;

pthread_cond_t buffer1_full = PTHREAD_COND_INITIALIZER; 
pthread_cond_t buffer1_empty = PTHREAD_COND_INITIALIZER; 
pthread_cond_t buffer2_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t buffer2_empty = PTHREAD_COND_INITIALIZER; 
pthread_cond_t buffer3_full = PTHREAD_COND_INITIALIZER; 
pthread_cond_t buffer3_empty = PTHREAD_COND_INITIALIZER; 
pthread_cond_t buffer_io_full = PTHREAD_COND_INITIALIZER; 
pthread_cond_t buffer_io_empty = PTHREAD_COND_INITIALIZER; 

int all_done = 0;

//input to lines
char *buffer1[BUFFER_SIZE];
int buffer1_count = 0;
int buffer1_prod_idx = 0;
int buffer1_cons_idx = 0;

//lines to plus
char *buffer2[BUFFER_SIZE];
int buffer2_count = 0;
int buffer2_prod_idx = 0;
int buffer2_cons_idx = 0;

//plus to output
char *buffer3[BUFFER_SIZE];
int buffer3_count = 0;
int buffer3_prod_idx = 0;
int buffer3_cons_idx = 0;


//Full tracking
int input_output_count = 0;

void* producer(void* args){
	int input_bool = 1;
	while(input_bool == 1){
		char* line = NULL;
		line = (char *)malloc(1000*sizeof(char));
		memset((char*) line, '\0', sizeof(*line));

		char* f_line;

		pthread_mutex_lock(&mutex_buffer_in_out);

		while(input_output_count == 1){
			pthread_cond_wait(&buffer_io_empty, &mutex_buffer_in_out);
		}
	
		f_line = fgets(line, 1000, stdin);
		input_output_count++;
		
		//signal something is in buffer and unlock mutex
		pthread_cond_signal(&buffer_io_full);
		pthread_mutex_unlock(&mutex_buffer_in_out);

		if(f_line == NULL){
			input_bool = 0;
			all_done = 1;
		}
		
		if(strcmp(line, "STOP\n") == 0){
			input_bool = 0;
			all_done = 1;
		}

		//lock mutex
		pthread_mutex_lock(&mutex_buffer1);

		while(buffer1_count == 1){
			pthread_cond_wait(&buffer1_empty, &mutex_buffer1);
		}
		//set to buffer 1
		buffer1[buffer1_prod_idx] = strdup(line);
		buffer1_prod_idx = (buffer1_prod_idx + 1) % BUFFER_SIZE;
		buffer1_count++;

		//signal and unlock
		pthread_cond_signal(&buffer1_full);
		pthread_mutex_unlock(&mutex_buffer1);

	}
	return NULL;
}

void* line_part(void* args){
	int line_bool = 1;
	while(line_bool == 1){
		char* end_line = NULL;
		end_line = (char *)malloc((1100)*sizeof(char));
		memset(end_line, '\0', 1100);

		char* space_line = NULL;
		space_line = (char *)malloc((1100)*sizeof(char));
		memset(space_line, '\0', 1100);
		
		//lock buffer
		pthread_mutex_lock(&mutex_buffer1);
	
		while(buffer1_count == 0){
			pthread_cond_wait(&buffer1_full, &mutex_buffer1);
		}	
		//check for STOP
		if(strcmp(buffer1[buffer1_cons_idx], "STOP\n") == 0){
			line_bool = 0;
		}
		//copy from buffer
		strcpy(space_line, buffer1[buffer1_cons_idx]);
		buffer1_cons_idx = (buffer1_cons_idx + 1) % BUFFER_SIZE;
		buffer1_count--;

		pthread_cond_signal(&buffer1_empty);

		//unlock
		pthread_mutex_unlock(&mutex_buffer1);

		//replace new line
		int i;
		for(i = 0; i < strlen(space_line); ++i){
			if(space_line[i] == '\n'){
				space_line[i] = ' ';
			}
		}
		
		//lock 2
		pthread_mutex_lock(&mutex_buffer2);

		while(buffer2_count == 1){
			pthread_cond_wait(&buffer2_empty, &mutex_buffer2);
		}
		//put in second buffer
		buffer2[buffer2_prod_idx] = strdup(space_line);
		buffer2_prod_idx = (buffer2_prod_idx + 1) % BUFFER_SIZE;
		buffer2_count++;

		pthread_cond_signal(&buffer2_full);
		pthread_mutex_unlock(&mutex_buffer2);

	}
	return NULL;
}

void* plussub_part(void* args){
	int plus_bool = 1;
	while(plus_bool == 1){
		char* plus_line = NULL;
		plus_line = (char *)malloc((1100)*sizeof(char));
		memset(plus_line, '\0', 1100);

		//lock buffer
		pthread_mutex_lock(&mutex_buffer2);

		while(buffer2_count == 0){
			pthread_cond_wait(&buffer2_full, &mutex_buffer2);
		}
		//copy to buffer2
		strcpy(plus_line, buffer2[buffer2_cons_idx]);
		buffer2_cons_idx = (buffer2_cons_idx + 1) % BUFFER_SIZE;
		buffer2_count--;
		
		pthread_cond_signal(&buffer2_empty);
		pthread_mutex_unlock(&mutex_buffer2);

		//check for STOP
		if(strcmp(plus_line, "STOP\n") == 0){
			plus_bool = 0;
		}

		//convert ++ to ^
		char* working_line = NULL;
		working_line = (char *)malloc((strlen(plus_line)+1)*sizeof(char));
		memset(working_line, '\0', strlen(plus_line)+1);
		memcpy(working_line, plus_line, strlen(plus_line));

		int plus_count = 0;
		int plus_idx = 0;
		while(plus_idx < strlen(working_line)){
			int convert_plus = strncmp(&working_line[plus_idx], "++", 2);
			if(convert_plus == 0){
				plus_count++;
				plus_idx++;
			}
			plus_idx++;
		}

		long plus_length = plus_count;
		plus_idx = 0;
		
		char* modif_plus_line = NULL;
		modif_plus_line = (char *)malloc((strlen(plus_line)-plus_length)*sizeof(char));
		memset(modif_plus_line, '\0', strlen(plus_line)-plus_length);

		if(plus_count == 0){
			memcpy(modif_plus_line, plus_line, strlen(plus_line));
		}
		else{
			strcpy(modif_plus_line, "");
			int i;
			for(i = 0; i < plus_count; ++i){
				int loop_bool = 1;
				while(loop_bool == 1){
					int convert_plus = strncmp(&working_line[plus_idx], "++", 2);
					if(convert_plus == 0){
						strncat(modif_plus_line, working_line, plus_idx);
						strcat(modif_plus_line, "^");
						working_line = working_line + plus_idx + 2;
						loop_bool = 0;
					}
					plus_idx++;
				}
				plus_idx = 0;
			}
			if(strlen(working_line) != 0){
				strcat(modif_plus_line, working_line);
			}
		}


		pthread_mutex_lock(&mutex_buffer3);
		while(buffer3_count == 1){
			pthread_cond_wait(&buffer3_empty, &mutex_buffer3);
		}

		//copy to buffer 3
		buffer3[buffer3_prod_idx] = strdup(modif_plus_line);
		buffer3_prod_idx = (buffer3_prod_idx + 1) % BUFFER_SIZE;
		buffer3_count++;

		//signal and unlock
		pthread_cond_signal(&buffer3_full);
		pthread_mutex_unlock(&mutex_buffer3);

	}
	return NULL;
}

void* consumer(void* args){
	char* output_line = NULL;
	output_line = (char *)malloc((10000)*sizeof(char));
	memset(output_line, '\0', 10000);

	int all_lines = 0;

	int output_bool = 1;
	while(output_bool == 1){
		pthread_mutex_lock(&mutex_buffer3);
		while(buffer3_count == 0){
			pthread_cond_wait(&buffer3_full, &mutex_buffer3);
		}

		//check STOP
		if(strcmp(buffer3[buffer3_cons_idx], "STOP\n") == 0){
			output_bool = 0;
		}
		//add to end of output line		
		strcat(output_line, buffer3[buffer3_cons_idx]);

		buffer3_cons_idx = (buffer3_cons_idx + 1) % BUFFER_SIZE;
		buffer3_count--;

		pthread_cond_signal(&buffer3_empty);
		pthread_mutex_unlock(&mutex_buffer3);

		pthread_mutex_lock(&mutex_buffer_in_out);
		while(input_output_count == 0){
			pthread_cond_wait(&buffer_io_full, &mutex_buffer_in_out);
		}
		input_output_count--;
		
		if(strlen(output_line) >= 80){
			int num_lines = strlen(output_line)/80;
			int i;
			for(i = all_lines; i < num_lines; ++i){
				char line[81];
				memset(line, '\0', sizeof(line));
				int j;
				for(j = 0; j < 80; ++j){
					line[j] = output_line[i*80+j];
				}
				//BIG PRINT
				printf("%s\n", line);
			}
			all_lines = num_lines;
			fflush(NULL);
		}
		pthread_cond_signal(&buffer_io_empty);
		pthread_mutex_unlock(&mutex_buffer_in_out);

		if(all_done && buffer1_count == 0 && buffer2_count == 0 && buffer3_count == 0){
			exit(1);
		}		
	}
	return NULL;
}

int main(int argc, char* argv[]){
	srand(time(NULL));

	pthread_mutex_init(&mutex_buffer1, NULL);
	pthread_mutex_init(&mutex_buffer2, NULL);
	pthread_mutex_init(&mutex_buffer3, NULL);
	pthread_mutex_init(&mutex_buffer_in_out, NULL);

	pthread_t input_t;
	pthread_t lines_t;
	pthread_t plussub_t;
	pthread_t output_t;

	//Create threads
	//producer -> line_part -> plussub_part -> consumer
	pthread_create(&input_t, NULL, producer, NULL);
	pthread_create(&lines_t, NULL, line_part, NULL);
	pthread_create(&plussub_t, NULL, plussub_part, NULL);
	pthread_create(&output_t, NULL, consumer, NULL);
	int i;

	//Join threads
	pthread_join(input_t, NULL);
	pthread_join(lines_t, NULL);
	pthread_join(plussub_t, NULL);
	pthread_join(output_t, NULL);


	//Check and run threads
	/*
	for(i = 0; i < THREAD_NUM; i++){
		if(i % 2 == 0){
			if(pthread_create(&th[i], NULL, &producer, NULL) != 0){
				perror("Failed to create thread");
			}
		}
		else{
			if(pthread_create(&th[i], NULL, &consumer, NULL) != 0){
				perror("Failed");
			}
		}
	}
	for(i = 0; i < THREAD_NUM; i++){
		if(pthread_join(th[i], NULL) != 0){
			perror("Failed");
		}
	}
	*/

/*
	sem_destroy(&sem_empty);
	sem_destroy(&sem_full);

	pthread_mutex_destroy(&mutex_buffer);
*/
	return 0;
}
