#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <dirent.h>

typedef struct {
	char *title;
	int year;
	char *languages;
	float rating;
} movie;		//name of struct for declare

typedef struct linkedlist {
	movie Movie;
	//int val;
	struct linkedlist *next;
} Node_t;

void push(Node_t * head, char *title, int year, char *languages, float rating){		//new node to linked list
	Node_t * current = head;
	while(current->next != NULL){
		current = current->next;
	}
	current->next = (Node_t *) malloc(sizeof(Node_t));
	current->next->Movie.title = strdup(title);
	current->next->Movie.year = year;
	current->next->Movie.languages = strdup(languages);
	current->next->Movie.rating = rating;
	current->next->next = NULL;
}

void print_list(Node_t * head){			//example print of list
	Node_t * current = head;
	while(current != NULL){
		if(current->Movie.year == 0)
			;
		else{
			printf("%s ", current->Movie.title);
			printf("%d ", current->Movie.year);
			printf("%s ", current->Movie.languages);
			printf("%.1f\n", current->Movie.rating);
		}	
		current = current->next;
	}
}

int setup_list(Node_t *head);
int readMovieFile(Node_t *head, char* cmdstring);
void print1(Node_t *head, int year);
void print2(Node_t *head);
void print3(Node_t *head, char* input_language);
void parse_languages(char *tmp_language_string, char* tmp_language);

void flush();

//void cr_directory(Node_t *head);


int main() {
	srand(time(NULL));

	//DECLARE LINKED LIST

	int input;
	int input_bool = 1; // bool for input
	int file_process = 0;
	int file_process_bool = 1; //bool for second set of choices
	int running = 1; //changed to 0 when want to exit
	while(running){
		while(input_bool) {						//section to take input
			printf("\n1. Select file to process\n");
			printf("2. Exit the program\n");
			printf("\nEnter a choice 1 or 2: "); 
			scanf("%d", &input);
			if(input>0 && input<3){
				input_bool = 0;
			}
			else {
				printf("Bad Input\n");
			}		
		}
		input_bool = 1;

		if(input == 2){
			exit(0);
		}
	
	
		while(file_process_bool){
			printf("\nWhich file do you want to process?\n");
			printf("Enter 1 to pick the largest file\n");
			printf("Enter 2 to pick the smallest file\n");
			printf("Enter 3 to specify the name of a file\n");
			printf("\nEnter a choice from 1 to 3: "); 
			scanf("%d", &file_process);
			if(file_process>0 && file_process<4){
				file_process_bool = 0; //Exit while loop
			}
			else {
				printf("Bad Input\n");
			}		
		}
		file_process_bool = 1;


		struct dirent **namelist;
	        int i,n;
		char* tmp;
		char* ret;

		char fileNameChoice[30]; //assume filename is more than 30 char
		int thing_exists; //token to choose to make directory or not
		thing_exists = 0;
		//Switch Case is for finding correct file to be written to a new directory
		if(1){						//cases 1-3	
			if(file_process == 1){
				n = scandir(".", &namelist, 0, alphasort);
			        if (n < 0){
			                perror("scandir");
				}
			        else {
					int file_exists = -1;
				
					long int max_file_size = 0;	
			                for (i = 0; i < n; i++) {
			                        if(strstr(namelist[i]->d_name, "movies_") != NULL){
							FILE *fp1 = fopen(namelist[i]->d_name, "r");
							if (fp1 == NULL){
								;
							}
							fseek(fp1, 0L, SEEK_END);
							if(ftell(fp1) > max_file_size){
								strcpy(fileNameChoice, namelist[i]->d_name);
								max_file_size = ftell(fp1);
							}
							fclose(fp1);
			                        }
			                        free(namelist[i]);
			                }
				}

				//printf("(1 Chosen) Now processing the chosen file named %s\n", fileNameChoice);
				//biggest
			}
			if(file_process == 2){
				n = scandir(".", &namelist, 0, alphasort);
			        if (n < 0){
			                perror("scandir");
				}
			        else {
					int file_exists = -1;
				
					long int min_file_size = 99999999999;	
			                for (i = 0; i < n; i++) {
			                        if(strstr(namelist[i]->d_name, "movies_") != NULL){
							FILE *fp1 = fopen(namelist[i]->d_name, "r");
							if (fp1 == NULL){
								;
							}
							fseek(fp1, 0L, SEEK_END);
							if(ftell(fp1) < min_file_size){
								printf("New file Substituted\n");
								strcpy(fileNameChoice, namelist[i]->d_name);
								min_file_size = ftell(fp1);
							}
							fclose(fp1);
			                        }
			                        free(namelist[i]);
			                }
				}

				//printf("(2 Chosen) Now processing the chosen file named %s\n", fileNameChoice);
				//smallest
			}
			if(file_process == 3){
				flush();					
				printf("Enter the complete file name: ");
				scanf("%s",fileNameChoice);
				//printf("%s", fileNameChoice);
			}
				//function to find file name specifically
				//printf("About to copy string");
				//strcpy(tmp, fileNameChoice);
				//printf("string copied\n");
				n = scandir(".", &namelist, 0, alphasort);
			        if (n < 0){
			                perror("scandir");
				}
			        else {
					int file_exists = -1;
			                for (i = 0; i < n; i++) {
			                        file_exists = strcmp(namelist[i]->d_name, fileNameChoice);
						//printf("%d\n", 
						if(file_exists == 0){
			                                thing_exists = 1;
							printf("Now Processing the chosen file named %s\n", namelist[i]->d_name);
							//readMovieFile(head, fileNameChoice);
							
			                        }
			                        free(namelist[i]);
			                }
					//printf("%d\n", file_exists);
				}
				//free(namelist);
				//printf("%s", fileNameChoice);
				if(thing_exists == 1){	
					printf("(2 Chosen) Now processing the chosen file named %s\n", fileNameChoice);
					Node_t* head;
					head = (Node_t*) malloc(sizeof(Node_t));
					if (head == NULL){
						return 1;
					}
					head->Movie.title = "Title";
					head->Movie.year = 0;
					head->Movie.languages = "Language";
					head->Movie.rating = 0.0;
					head->next = NULL;

					//printf("READING MOVIE FILE AND ALL IS GOOD\n");
					readMovieFile(head, fileNameChoice);




					//Create New Random Directory
					int r = rand() % 100000;
					char sr[10];
					sprintf(sr, "%d", r);
					char* dir_pre = "hietaa.movies.";
					char* directory_name = (char *) malloc(1+strlen(dir_pre)+strlen(sr));
					strcpy(directory_name, dir_pre);
					strcat(directory_name, sr);
					//printf("%s", directory_name);
					mkdir(directory_name, 0777);	
					
					printf("Created directory with name %s\n", directory_name);			
	
					//Make File in new Directory for each year
					int file_year; //iterate through 1900 to 2021	
					
					for(file_year = 1900; file_year < 2022; file_year++){
						//FUNCTION TO FIND IF YEAR IS APPLICABLE
						int file_year_good = 0;
						Node_t * curr = head;
						while(curr != NULL){
							if(curr->Movie.year == 0){
								curr = curr->next;
							}
							else{
								if(curr->Movie.year == file_year){
									file_year_good = 1;
								}
								curr = curr->next;
							}
						}
						//Create file and write titles of years
						if(file_year_good){	
							FILE *fp;
							
							char sfile_year[10];
							sprintf(sfile_year, "%d", file_year);
							char* slash = "/";
							char* first_half = (char *) malloc(1+strlen(slash)+strlen(sfile_year));
							strcpy(first_half, slash);
							strcat(first_half, sfile_year);
						
							char* second_half = ".txt";
							char* full_year_file = (char *) malloc(1+strlen(first_half)+strlen(second_half));
							strcpy(full_year_file, first_half);
							strcat(full_year_file, second_half);
							
							char* dir_and_file = (char *) malloc(1+strlen(directory_name)+strlen(full_year_file));
							strcpy(dir_and_file, directory_name);
							strcat(dir_and_file, full_year_file);
							
							fp = fopen(dir_and_file, "w+");
					
							curr = head;
							while(curr != NULL){
								if(curr->Movie.year == 0){
									curr = curr->next;
								}
								else{
									if(curr->Movie.year == file_year){
										fprintf(fp, curr->Movie.title); //write title to file
										fprintf(fp, "\n");
									}
									curr = curr->next;
								}
							}	
						}
					}
				}
				else{
					printf("The file %s was not found. Try Again\n", fileNameChoice);
				}
		}
	}
	return 0;
}

void flush(){
	int c;
	while((c = getchar()) != '\n' && c != EOF)
		;
}

int setup_list(Node_t *head){
	head = (Node_t*) malloc(sizeof(Node_t));
	if (head == NULL){
		return 1;
	}
	head->Movie.title = "Title";
	head->Movie.year = 0;
	head->Movie.languages = "Language";
	head->Movie.rating = 0.0;
	head->next = NULL;

	return 0;
}

int readMovieFile(Node_t *head, char* cmdstring) {	//take in head of linked list and string name of CSV file
	FILE *the_file = fopen(cmdstring, "r");
	if(the_file == NULL){
		printf("Unable to open file");
		exit(1);
	}	
	
	char line[200]; //line length

	int type = 0;
	while(fgets(line, sizeof(line), the_file)){
		char *token;
		char* tmp_title;
		int tmp_year;
		char* tmp_language_string;
		//char* tmp_languages[5];
		float tmp_rating;

		token = strtok(line, ",");

		while(token != NULL){
			//printf("%s\n", token);
			//printf("%d\n", type);
			//token = strtok(NULL, ",");
			
			switch(type){
				case(0):
					tmp_title = token;
					//printf("%s\n", tmp_title);
					type++;
					break;
				case(1):
					tmp_year = atoi(token);
					//printf("%d\n", tmp_year);
					type++;
					break;

				case(2):
					tmp_language_string = token;
					//printf("%s\n", tmp_languages);
					type++;
					break;
				case(3):
					tmp_rating = atof(token);
					//printf("%.1f\n", tmp_rating);
					type = 0;
					//printf("%s, %d, %s, %.1f\n", tmp_title, tmp_year, tmp_languages, tmp_rating);
					push(head, tmp_title, tmp_year, tmp_language_string, tmp_rating);

					break;
			}
			token = strtok(NULL, ",");
								
		}
	}
}

void print1(Node_t *head, int year){
	int year_found = 0;
	Node_t * curr = head;
	while(curr != NULL){
		if(curr->Movie.year == 0){
			curr = curr->next;
		}
		else{
			if(curr->Movie.year == year){
				year_found = 1;
				printf("%s\n", curr->Movie.title); //spot to adjust for printing in file
			}
			else{
				;
			}
			curr = curr->next;
		}
	}
	if(year_found == 0){
		printf("No data about movies released in the year %d\n", year);
	}
	printf("\n");	
}

void print2(Node_t *head){
	Node_t * curr = head;
	int recorded_years[] = {5000};
	int s = 0;	
	while(curr != NULL){
		//printf("In first While Loop\n");
		if(curr->Movie.year == 0){
			curr = curr->next;
			//printf("Detected bad year\n");
		}
		else{
			Node_t * currcurr = head;
			int curr_is_biggest = 1;
			while(currcurr != NULL){
				if(curr->Movie.year == currcurr->Movie.year){
					if(curr->Movie.rating < currcurr->Movie.rating){
						curr_is_biggest = 0;
					}	
				}
				currcurr = currcurr->next;
			}
			if(curr_is_biggest){	
				printf("%d ", curr->Movie.year);
				printf("%.1f ", curr->Movie.rating);
				printf("%s\n", curr->Movie.title);			
			}
			curr = curr->next;
		}
	}
}

void print3(Node_t *head, char* input_language){
	Node_t * curr = head;
	int recorded_years[] = {5000};
	int s = 0;
	int movie_with_language_found = 0;	
	while(curr != NULL){
		//printf("In first While Loop\n");
		if(curr->Movie.year == 0){
			curr = curr->next;
			//printf("Detected bad year\n");
		}
		else{
			//if string is found
			int f;
			int g;
			int still_good = 0;
			//printf("%d ", strlen(curr->Movie.languages));
			//printf("%d\n", strlen(input_language));
			for(f = 0; f < (strlen(curr->Movie.languages)-strlen(input_language)); f++){
				for(g = 0; g < strlen(input_language); g++){
					//printf("%c %c\n", input_language[g], curr->Movie.languages[f+g]);
					if(input_language[g] == curr->Movie.languages[f+g]){
						still_good = 1;
					}
				}
				if(still_good){
					printf("%d ", curr->Movie.year);
					printf("%s\n", curr->Movie.title);
					movie_with_language_found = 1;
					break;	
				}
			}		
			curr = curr->next;
		}
	}
	if(movie_with_language_found){
		printf("No data about movies released in %s\n", input_language);
	}
}






