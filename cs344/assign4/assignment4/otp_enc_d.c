/* Name: Matthew Toro
 * Class: CS344 Operating Systems
 *  * Assignment: Program 4
 *   * Due Date: 8/18/2017
 *    * Description: Daemon that receives plain text from client, encrypts it, and sends it back 
 *     * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <sys/ioctl.h>

int main(int argc, char* argv[])
{
   
   struct sockaddr_in serverAddress;
   memset((char*)&serverAddress, '\0', sizeof(serverAddress));
   int portNum = atoi(argv[1]);
   serverAddress.sin_family = AF_INET;
   serverAddress.sin_port = htons(portNum);
   serverAddress.sin_addr.s_addr = INADDR_ANY;

 
   int listenSocketFD = socket(AF_INET, SOCK_STREAM, 0);
   if (listenSocketFD < 0)
   {
	fprintf(stderr, "Error: error opening socket");
	exit(2);
   }
   
  
   if (bind(listenSocketFD, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
   {
	fprintf(stderr, "Error: error on binding");
	exit(2);
   }
   
   listen(listenSocketFD, 5);

   
   while(1)
   {
	
	
	struct sockaddr_in clientAddress; 
	socklen_t sizeOfClientInfo = sizeof(clientAddress); 
	int establishedConnectionFD = accept(listenSocketFD, (struct sockaddr *)&clientAddress, &sizeOfClientInfo);
	if (establishedConnectionFD < 0)
	{
	   fprintf(stderr, "Error: error on accept");
	}
	else
	{
	   
	   pid_t spawnPid = -5;
	   int childPID_actual;
	   int childExitMethod = -5;
	   spawnPid = fork();
	   switch (spawnPid)
	   {
	   	case -1:
	   	{
		   fprintf(stderr, "ERROR: fork failed\n");
		   close(establishedConnectionFD);
	   	   break;
	   	}
	   	case 0:
	   	{
			
	   		char completeMessage[150000], readBuffer[10];
	   		memset(completeMessage, '\0', sizeof(completeMessage));
	   		int charsRead;
			
	   		while (strstr(completeMessage, "@@") == NULL)
	   		{
				memset(readBuffer, '\0', sizeof(readBuffer));
				charsRead = recv(establishedConnectionFD, readBuffer, sizeof(readBuffer) - 1, 0);
				if (charsRead < 0)
				{
	   	   			fprintf(stderr, "error reading from socket");
	   	   			break ;
				}
				strcat(completeMessage, readBuffer);
	   		}
	   		int terminalLocation = strstr(completeMessage, "@@") - completeMessage;
	   		completeMessage[terminalLocation] = '\0';

	   		
	   		char * token = strtok(completeMessage, "\n");
	   		if (token[0] == 'e')
	   		{
				
				token = strtok(NULL, "\n");
				char * plainTextStr = malloc(strlen(token) * sizeof(char));
				memset(plainTextStr, '\0', sizeof(plainTextStr));
				strcpy(plainTextStr, token);

				
				token = strtok(NULL, "\n");
				char * keyStr = malloc(strlen(token) * sizeof(char));
				memset(keyStr, '\0', sizeof(keyStr));
				strcpy(keyStr, token);
  
				
				char * cipherText = malloc(((int) strlen(plainTextStr) + 5) * sizeof(char));
				memset(cipherText, '\0', sizeof(cipherText));
				strcpy(cipherText, "e-");
				char letters[27] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
				char merge[2];

				
				int i;
				for (i = 0; i < strlen(plainTextStr); i++)
				{
		   			int plainTextIndex, keyIndex, trueIndex;
					
		   			if (plainTextStr[i] == 32)
						plainTextIndex = 0;
		   			else if (plainTextStr[i] >= 65 && plainTextStr[i] <= 90)
						plainTextIndex = plainTextStr[i] - 64;
					
		   			if (keyStr[i] == 32)
						keyIndex = 0;
		   			else if (keyStr[i] >= 65 && keyStr[i] <= 90)
						keyIndex = keyStr[i] - 64;

					
		   			if (plainTextIndex + keyIndex > 26)
						trueIndex = (plainTextIndex + keyIndex) % 27;
		   			else
						trueIndex = plainTextIndex + keyIndex;
		   			memset(merge, '\0', sizeof(merge));
		   			merge[0] = letters[trueIndex];
		   			strcat(cipherText, merge);
				}
				
				strcat(cipherText, "@@\0");

				  
				char go[3];
				memset(go, '\0', sizeof(go));
				strcpy(go, "go");
				send(establishedConnectionFD, go, sizeof(go), 0);

				
				int totalBytes = strlen(plainTextStr) + 5;
				int currentBytes = 0;
				int leftoverBytes = totalBytes;
				while(currentBytes < totalBytes)
				{
					charsRead = send(establishedConnectionFD, cipherText + currentBytes, leftoverBytes, 0);
					if (charsRead < 0)
					{
						fprintf(stderr, "Server: error writing to socket\n");
						break;
					}
					currentBytes += (int) charsRead;
					leftoverBytes -= (int) charsRead;
				}

				int checkSend = -5;
				do
				{
					ioctl(establishedConnectionFD, TIOCOUTQ, &checkSend);
				} while (checkSend > 0);
				close(establishedConnectionFD);
				
				exit(0); 
	   		}
	   		else
	   		{
				
				char errMsg[19];
				memset(errMsg, '\0', sizeof(errMsg));
				strcpy(errMsg, "w-Wrong Program@@\n");
				int totalBytes = strlen(errMsg);
				int currentBytes = 0;
				int leftoverBytes = totalBytes;
				int charsRead;
				while(currentBytes < totalBytes)
				{
					charsRead = send(establishedConnectionFD, errMsg + currentBytes, leftoverBytes, 0);
					if (charsRead < 0)
					{
						fprintf(stderr, "Server: error writing to socket\n");
						break;
					}
					currentBytes += (int) charsRead;
					leftoverBytes -= (int) charsRead;
				}
				close(establishedConnectionFD); 
				exit(1);
	   		}
	   	  	break;
	   	}
	   	default:
	   	{
			
			close(establishedConnectionFD);
			childPID_actual = waitpid(-1, &childExitMethod, WNOHANG);
	   	  	break;
	   	}	  
	   }
	}
   }
   close(listenSocketFD); 
   return 0;
}


