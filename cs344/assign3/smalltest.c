/******************************************************************
 * me: smallsh.c
 * Author: Brent Irwin
 *  * Date: 21 May 2017
 *   * Description: Main file for smallsh, CS 344 Program 3
 *   ***************************************************************/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>

#define INPUTLENGTH 2048

int allowBackground = 1;

void getInput(char*[], int*, char[], char[], int);
void execCmd(char*[], int*, struct sigaction, int*, char[], char[]);
void catchSIGTSTP(int);
void printExitStatus(int);

/* ---------------------- Main function --------------------- */ 
/*	main() gets the input, checks for blanks or comments, processes
 *	 *	CD, EXIT, and STATUS, and then executes the command if the input
 *	  *	didn't call for any of the other functions.
 *	   * ---------------------------------------------------------- */

int main() {

	int pid = getpid();
	int cont = 1;
	int i;
	int exitStatus = 0;
	int background = 0;

	char inputFile[256] = "";
	char outputFile[256] = "";
	char* input[512];
	for (i=0; i<512; i++) {
		input[i] = NULL;
	}

	
	
	
	struct sigaction sa_sigint = {0};
	sa_sigint.sa_handler = SIG_IGN;
	sigfillset(&sa_sigint.sa_mask);
	sa_sigint.sa_flags = 0;
	sigaction(SIGINT, &sa_sigint, NULL);

	
	struct sigaction sa_sigtstp = {0};
	sa_sigtstp.sa_handler = catchSIGTSTP;
	sigfillset(&sa_sigtstp.sa_mask);
	sa_sigtstp.sa_flags = 0;
	sigaction(SIGTSTP, &sa_sigtstp, NULL);

	do {
		
		getInput(input, &background, inputFile, outputFile, pid);

		
		if (input[0][0] == '#' ||
					input[0][0] == '\0') {
			continue;
		}
		
		
		else if (strcmp(input[0], "exit") == 0) {
			cont = 0;
		}
	
		
		else if (strcmp(input[0], "cd") == 0) {
			
			if (input[1]) {
				if (chdir(input[1]) == -1) {
					printf("Directory not found.\n");
					fflush(stdout);
				}
			} else {
			
				chdir(getenv("HOME"));
			}
		}

		
		else if (strcmp(input[0], "status") == 0) {
			printExitStatus(exitStatus);
		}

		
		else {
			printf("Executing Command\n");
			execCmd(input, &exitStatus, sa_sigint, &background, inputFile, outputFile);
		}

		
		for (i=0; input[i]; i++) {
			input[i] = NULL;
		}
		background = 0;
		inputFile[0] = '\0';
		outputFile[0] = '\0';

	} while (cont);
	
	return 0;
}

/***************************************************************
 *  * 			void getInput(char*[], int, char*, char*, int)
 *   *
 *    * Prompts the user and parses the input into an array of words
 *     *
 *      * INPUT:
 *       *		char*[512] arr		The output array
 *        *		int* background	Is this a background process? boolean
 *         *		char* inputName	Name of an input file
 *          *		char* outputName	Name of an output file
 *           *		int pid				PID of smallsh
 *            *
 *             *	OUTPUT:
 *              *		void - n/a
 *               ***************************************************************/
void getInput(char* arr[], int* background, char inputName[], char outputName[], int pid) {
	
	char input[INPUTLENGTH];
	int i, j;

	
	printf(": ");
	fflush(stdout);
	fgets(input, INPUTLENGTH, stdin);

	
	int found = 0;
	for (i=0; !found && i<INPUTLENGTH; i++) {
		if (input[i] == '\n') {
			input[i] = '\0';
			found = 1;
		}
	}

	
	if (!strcmp(input, "")) {
		arr[0] = strdup("");
		return;
	}

	
	const char space[2] = " ";
	char *token = strtok(input, space);

	for (i=0; token; i++) {
		
		if (!strcmp(token, "&")) {
			*background = 1;
		}
		
		else if (!strcmp(token, "<")) {
			token = strtok(NULL, space);
			strcpy(inputName, token);
		}
		
		else if (!strcmp(token, ">")) {
			token = strtok(NULL, space);
			strcpy(outputName, token);
		}
		
		else {
			arr[i] = strdup(token);
			
			for (j=0; arr[i][j]; j++) {
				if (arr[i][j] == '$' &&
					 arr[i][j+1] == '$') {
					arr[i][j] = '\0';
					snprintf(arr[i], 256, "%s%d", arr[i], pid);
				}
			}
		}
		
		token = strtok(NULL, space);
	}
}

/***************************************************************
 *  * 			void execCmd(char*[], int*, struct sigaction, int*, char[], char[])
 *   *
 *    * Executes the command parsed into arr[]
 *     *
 *      * INPUT:
 *       * 	char* arr[]				The array with command information
 *        *		int* childExitStatus	The success status of the command
 *         *		struct sigaction sa	The sigaction for SIGINT
 *          *		int* background		Is it a background process? boolean
 *           *		char inputName[]		The name of the input file
 *            *		char outputName[]		The name of the output file
 *             *
 *              * OUTPUT:
 *               *		void - n/a
 *               ***************************************************************/
void execCmd(char* arr[], int* childExitStatus, struct sigaction sa, int* background, char inputName[], char outputName[]) {
	
	int input, output, result;
	pid_t spawnPid = -5;

	
	
	spawnPid = fork();
	switch (spawnPid) {
		
		case -1:	;
			printf("Case -1\n");
			perror("Hull Breach!\n");
			exit(1);
			break;
		
		case 0:	;
			printf("Case 0\n");
			sa.sa_handler = SIG_DFL;
			sigaction(SIGINT, &sa, NULL);

			
			if (strcmp(inputName, "")) {
				printf("Case 0 Input\n");	
				input = open(inputName, O_RDONLY);
				if (input == -1) {
					perror("Unable to open input file\n");
					exit(1);
				}
				
				result = dup2(input, 0);
				if (result == -1) {
					perror("Unable to assign input file\n");
					exit(2);
				}
				
				fcntl(input, F_SETFD, FD_CLOEXEC);
			}

			
			if (strcmp(outputName, "")) {
				printf("Case 0 Input\n");	
				
				output = open(outputName, O_WRONLY | O_CREAT | O_TRUNC, 0666);
				if (output == -1) {
					perror("Unable to open output file\n");
					exit(1);
				}
				
				result = dup2(output, 1);
				if (result == -1) {
					perror("Unable to assign output file\n");
					exit(2);
				}
				
				fcntl(output, F_SETFD, FD_CLOEXEC);
			}
			
			
			if (execvp(arr[0], (char* const*)arr)) {
				printf("%s: no such file or directory\n", arr[0]);
				fflush(stdout);
				exit(2);
			}
		
			break;
		
		default:	;
			printf("Default\n");
			
			if (*background && allowBackground) {
				pid_t actualPid = waitpid(spawnPid, childExitStatus, WNOHANG);
				printf("background pid is %d\n", spawnPid);
				fflush(stdout);
			}
			
			else {
				pid_t actualPid = waitpid(spawnPid, childExitStatus, 0);
			}

		
		while ((spawnPid = waitpid(-1, childExitStatus, WNOHANG)) > 0) {
			printf("child %d terminated\n", spawnPid);
			printExitStatus(*childExitStatus);
			fflush(stdout);
		}
	}
}

/***************************************************************
 *  * 			void catchSIGTSTP(int)
 *   *
 *    * When SIGTSTP is called, toggle the allowBackground boolean.
 *     *
 *      * I didn't know how to pass my own variables into this, so I made
 *       * allowBackground a global variable. I know that's bad form.
 *        *
 *         * INPUT:
 *          * 	int signo		Required, according to the homework. Isn't used.
 *           *
 *            * OUTPUT:
 *             * 	void - n/a
 *             ***************************************************************/
void catchSIGTSTP(int signo) {

	
	if (allowBackground == 1) {
		char* message = "Entering foreground-only mode (& is now ignored)\n";
		write(1, message, 49);
		fflush(stdout);
		allowBackground = 0;
	}

	
	else {
		char* message = "Exiting foreground-only mode\n";
		write (1, message, 29);
		fflush(stdout);
		allowBackground = 1;
	}
}

/***************************************************************
 *  * 			void printExitStatus(int)
 *   *
 *    * Calls the exit status
 *     *
 *      * INPUT:
 *       * 	int childExitMethod	Child Exit Method
 *        *
 *         * OUTPUT:
 *          * 	void - n/a
 *          ***************************************************************/
void printExitStatus(int childExitMethod) {
	
	if (WIFEXITED(childExitMethod)) {
		
		printf("exit value %d\n", WEXITSTATUS(childExitMethod));
	} else {
		
		printf("terminated by signal %d\n", WTERMSIG(childExitMethod));
	}
}


