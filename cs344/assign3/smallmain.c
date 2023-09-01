/********************************
 *
 *	Author: Aleksi Hieta
 *
 *	Date: 10/24/2021
 *	Class: CS 344
 *
 * *****************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <signal.h>
#include <fcntl.h>

void getInput(char*[], int*, char[], char[], int);
void othercommand(char*[], int*, struct sigaction, int*, char[], char[]);
void exitStatus(int);

int main(){
	int running = 1;

	int exitStat = 0;
	int backgrnd = 0;

	char inFile[100] = "";
	char outFile[100] = "";
	char* command[100];

	int i;
	for (i=0; i<100; i++){
		command[i] = NULL;
	}

	struct sigaction sigint = {0};
	sigint.sa_handler = SIG_IGN;
	sigfillset(&sigint.sa_mask);
	sigint.sa_flags = 0;
	sigaction(SIGINT, &sigint, NULL);

	struct sigaction sigtstp = {0};
	sigtstp.sa_handler = NULL;
	sigfillset(&sigint.sa_mask);
	sigtstp.sa_flags = 0;
	sigaction(SIGINT, &sigtstp, NULL);


	int pid = getpid();

	do{	
		getInput(command, &backgrnd, inFile, outFile, pid);

		//Check # comment or blank line
		if('#' == command[0][0] || '\0' == command[0][0]){
			//printf("Comment or blank\n");
			//fflush(stdout);
			continue;
		}

		//cd command
		else if(strcmp("cd", command[0]) == 0){
			//printf("CD found\n");
			//fflush(stdout);
			if(command[1]){
				//chdir returns -1 if dir not exist
				if(chdir(command[1]) == -1){
					printf("Dir not found\n");
					fflush(stdout);
				}
			}
			else{
				chdir(getenv("HOME"));
			}
		}

		//exit command
		else if(strcmp("exit", command[0]) == 0){
			running = 0;
		}

		//status print
		else if(strcmp("status", command[0]) == 0){
			exitStatus(exitStat);
		}

		//All other commands
		else{
			othercommand(command, &exitStat, sigint, &backgrnd, inFile, outFile);
		}

		//Reset command taken in for another time
		for(i = 0; command[i]; i++){
			command[i] = NULL;
		}
		backgrnd = 0;
		inFile[0] = '\0';
		outFile[0] = '\0';
	}while (running);

	return 0;
}

void getInput(char* arr[], int* backgrnd, char inName[], char outName[], int PID){
	char inputstring[100];
	
	printf(": ");
	fflush(stdout);
	fgets(inputstring, 100, stdin);

	int found = 0;
	int i;
	for(i = 0; (!found) && i<100; i++){
		if(inputstring[i] == '\n'){
			inputstring[i] = '\0';
			found = 1;
		}
	}

	if(strcmp(inputstring, "") == 0){
		arr[0] = strdup("");
		return;
	}

	char space[2] = " ";
	char* token = strtok(inputstring, space);

	for(i = 0; token; i++){
		//input detected
		if(strcmp(token, "<") == 0){
			token = strtok(NULL, space);
			strcpy(inName, token);
		}
		//output detected
		else if(strcmp(token, ">") == 0){
			token = strtok(NULL, space);
			strcpy(outName, token);
		}
		//backgrnd set
		else if(strcmp(token, "&") == 0){
			*backgrnd = 1;
		}
		else{
			arr[i] = strdup(token);
			int j;
			for(j = 0; arr[i][j]; j++){
				if((arr[i][j] == '$') && (arr[i][j+1] == '$')){
					arr[i][j] = '\0';
					snprintf(arr[i], 100, "%s%d", arr[i], PID);
				}
			}
		}
		token = strtok(NULL, space);
	}
}

void othercommand(char* arr[], int* exitStat, struct sigaction sig, int* backgrnd, char inThing[], char outThing[]){
	int input;
	int output;
	int result;
	pid_t spawnPID = -5;

	spawnPID = fork();
	switch(spawnPID){
		case -1:
			perror("Breach\n");
			exit(1);
			break;
		case 0:
			sig.sa_handler = SIG_DFL;
			sigaction(SIGINT, &sig, NULL);
	
			//Input openable and exists
			if(strcmp("", inThing)){
				input = open(inThing, O_RDONLY);
				if(input == -1){
					exit(1);
				}
				result = dup2(input, 0);
				if(result = -1){
					exit(2);
				}
				fcntl(input, F_SETFD, FD_CLOEXEC);
			}

			//Output openable
			if(strcmp("", outThing)){
				output = open(outThing, O_WRONLY | O_CREAT);
				if(output == -1){
					exit(1);
				}
				result = dup2(output, 1);
				if(result == -1){
					exit(2);
				}
				fcntl(output, F_SETFD, FD_CLOEXEC);
			}


	
			//EXECUTE COMMAND	
			if(execvp(arr[0], (char* const*)arr)){
				printf("%s: no such file or directory\n", arr[0]);
				fflush(stdout);
			}

			break;
		default:
			if(*backgrnd){
				pid_t realPID = waitpid(spawnPID, exitStat, WNOHANG);
				printf("background PID: %d\n", spawnPID);
				fflush(stdout);
			}
			else{
				pid_t realPID = waitpid(spawnPID, exitStat, 0);
			}
		while((spawnPID = waitpid(-1, exitStat, WNOHANG)) > 0){
			;
		}
	}
}

void exitStatus(int method){
	if(WIFEXITED(method)){
		printf("exit value %d\n", WEXITSTATUS(method));
		fflush(stdout);
	}
	else{
		printf("terminated by sig %d\n", WTERMSIG(method));
		fflush(stdout);
	}
}


