#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int readMovieFile(Node_t *head, char* cmdstring);
void print1(Node_t *head, int year);
void print2(Node_t *head);
void print3(Node_t *head, char* input_language);
void parse_languages(char *tmp_language_string, char* tmp_language);

void flush();

int main(int argc, char **argv) {
	if(argc < 1)
		return 0;

	int j;
	int strsize = 0;
	for(j = 1; j<argc; j++){
		strsize += strlen(argv[j]);
		if(argc > j+1)
			strsize++;
	}
	char *cmdstring;
	cmdstring = malloc(strsize);
	cmdstring[0] = '\0';
	for(j = 1; j<argc; j++){
		strcat(cmdstring, argv[j]);
		if(argc > j+1)
			strcat(cmdstring, " ");
	}
	//ABOVE READS COMMAND LINE CSV FILE NAME

	printf("\n%s\n", cmdstring);

	//DECLARE LINKED LIST
	Node_t * head = NULL;
	head = (Node_t*) malloc(sizeof(Node_t));
	if (head == NULL){
		return 1;
	}
	head->Movie.title = "Title";
	head->Movie.year = 0;
	head->Movie.languages = "Language";
	head->Movie.rating = 0.0;
	head->next = NULL;

	//READ FILE
	int isOK = 0;
	isOK = readMovieFile(head, cmdstring);

	//print_list(head); //PRINT WHOLE LIST
/*
	char *temp_languages[5] = {"English", "Spanish", "Scandinavian"};
	//max number of languages is 5

	movie Movie1 = {"Yo mama", 2004, temp_languages, 6.9};	//declare movie struct

	//EXAMPLE PRINT FUNCTIONS FOR ALL VARIABLES

	printf("Title is: %s\n", Movie1.title);
	printf("Year is: %d \n", Movie1.year);
	printf("Languages: %s, %s, %s\n", Movie1.languages[0], Movie1.languages[1], Movie1.languages[2]);
	printf("Rating: %.1f\n", Movie1.rating);

	//not knowing how long list of languages is
	printf("All languages are:");
	int i = 0;
	while(Movie1.languages[i] != NULL) {
		printf(" %s", Movie1.languages[i]);
		i++;
	}
	printf("\n");
*/
	//what movie would you like
	//ask for Title, Year, Languages, and/or Rating

	int input;
	int input_bool = 1; // bool for input
	int running = 1; //changed to 0 when want to exit
	while(running){
		while(input_bool) {						//section to take input
			printf("1. Show movies released in the specified year\n");
			printf("2. Show highest rated movie for each year\n");
			printf("3. Show the title and year of release of all movies in a specific language\n");
			printf("4. Exit from the program\n");
			printf("\nEnter a choice from 1 to 4: "); 
			scanf("%d", &input);
			if(input>0 && input<5){
				input_bool = 0;
			}
			else {
				printf("Bad Input\n");
			}		
		}
		input_bool = 1;

		int yearChoice;
		char languageChoice[20]; //assume no language is more than 20 char
		switch(input){							//cases 1-4	
			case 1:
				printf("Enter the year from which you want to see movies: ");
				scanf("%d", &yearChoice);
				printf("%d\n", yearChoice);
				print1(head, yearChoice);
				break;
			case 2:
				//printf("highest ratings chosen\n");
				print2(head);
				break;
			case 3:
				flush();					
				printf("Enter the language for which you want to see movies: ");
				fgets(languageChoice, 20, stdin);
				printf("%s\n", languageChoice);
				print3(head, languageChoice);
				break;
			case 4:
				//Exit
				//printf("Exiting program\n");
				exit(0);
				break;
		}
	}
	return 0;
}

void flush(){
	int c;
	while((c = getchar()) != '\n' && c != EOF)
		;
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

/*
void parse_languages(char *tmp_language_string, char* tmp_language[5]){
	char curr_letter;
	char *curr_word;
	int p = 0;
	int end_loop = 1;
	int o = 0;
	while(end_loop){
		curr_letter = tmp_language_string[p];
		printf("%c\n", curr_letter);
		if(curr_letter == '['){
			;
		}
		else if(curr_letter == ';'){
			tmp_language[o] = strdup(curr_word);
			curr_word = "";	
		}
		else if(curr_letter == ']'){
			end_loop = 0;
		}
		else if(curr_letter == ' '){
			end_loop = 0;
		}
		else{
			//strncat(curr_word, &curr_letter, 1);
		}
		p++;
	}
	for(p = 0; p < 5; p++){
		printf("%s\n", tmp_language[p]);
	}
}
*/

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
				printf("%s\n", curr->Movie.title);
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






