/*me: Matthew Toro
 * Class: CS344 Operating Systems
 *  * Assignment: Program 4
 *   * Due Date: 8/18/2017
 *    * Description: Client program that sends plaintext to server and receives ciphertext back from the server 
 *     **/
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <errno.h>


int checkCharacters(char * str);
void error(const char * message, int exitValue);

int main(int argc, char* argv[])
{
   int plainTextFileFD;
   char plainTextStr[75000];
   memset(plainTextStr, '\0', sizeof(plainTextStr));


   plainTextFileFD = open(argv[1], O_RDONLY);
   int plainTextBytes = read(plainTextFileFD, plainTextStr, (size_t) sizeof(plainTextStr));


   int badCharCheck = checkCharacters(plainTextStr); 
   if (badCharCheck == 0)
   {
	error("ERROR: bad character in file\n", 1);
   }

   int keyFileFD;
   char keyStr[75000];
   memset(keyStr, '\0', sizeof(keyStr));

 
   lseek(keyFileFD, 0, SEEK_SET);
   keyFileFD = open(argv[2], O_RDONLY);
   int keyBytes = read(keyFileFD, keyStr, (size_t) sizeof(keyStr));
   
   
   badCharCheck = checkCharacters(keyStr);
   if (badCharCheck == 0)
   {
	error("ERROR: bad character in file\n", 1);
   }

  
   if (keyBytes < plainTextBytes)
   {
	error("ERROR: bytes in key is less than bytes in file\n", 1);
   }	

   char * completeMessage = malloc((strlen(plainTextStr) + strlen(keyStr) + 6) * sizeof(char));
   memset(completeMessage, '\0', sizeof(completeMessage));
   strcpy(completeMessage, "e\n");
   strcat(completeMessage, plainTextStr);
   strcat(completeMessage, keyStr);
   strcat(completeMessage, "@@\n\0");


   int portNum = atoi(argv[3]);

   struct sockaddr_in serverAddress;
   serverAddress.sin_family = AF_INET;
   serverAddress.sin_port = htons(portNum);

   struct hostent* serverHostInfo;
   serverHostInfo = gethostbyname("localhost");
   if (serverHostInfo == NULL)
   {
	free(completeMessage);
	error("ERROR: no such host\n", 2);
   }

   memcpy((char*)&serverAddress.sin_addr.s_addr, (char*) serverHostInfo->h_addr, serverHostInfo->h_length);


   int socketFD = socket(AF_INET, SOCK_STREAM, 0);
   if (socketFD < 0)
   {
	free(completeMessage);
	error("ERROR: error opening socket\n", 2);
   }


   if (connect(socketFD, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0)
   {
	free(completeMessage);
	error("ERROR: error  connecting\n", 2);
   }


   int totalBytes = (int) strlen(completeMessage);
   int currentBytes = 0;
   int leftoverBytes = totalBytes;
   while(currentBytes < totalBytes)
   {
	ssize_t bytesSent;
	bytesSent = send(socketFD, completeMessage + currentBytes, leftoverBytes, 0);
	if (bytesSent < 0)
	{
	   free(completeMessage);
	   error("ERROR: error writing to socket", 2);
	}
	currentBytes += (int) bytesSent;
	leftoverBytes -= (int) bytesSent;
   }	  


   char go[6], merge[3];
   memset(go, '\0', sizeof(go));
   memset(merge, '\0', sizeof(merge));
   strcpy(go, "pause");
   int bytesRead;
   while (strcmp(go, "pause") == 0)
   {
	bytesRead = recv(socketFD, merge, sizeof(merge), 0);
	strcpy(go, merge);
   }


   char cipherText[75000], readBuffer[100];
   memset(cipherText, '\0', sizeof(cipherText));
   int charsRead;

   while(strstr(cipherText, "@@") == NULL)
   {
	memset(readBuffer, '\0', sizeof(readBuffer));
	charsRead = recv(socketFD, readBuffer, sizeof(readBuffer), 0);
	if (charsRead < 0)
	{
	   fprintf(stderr, "ERROR: error receiving data\n");
		
	   break;
	}
	strcat(cipherText, readBuffer);
   }

   char* token = strtok(cipherText, "-");
   if (token[0] == 'e')
   {
	token = strtok(NULL, "-");
	int terminalLocation = strstr(token, "@@") - token;
	token[terminalLocation] = '\n';
	token[terminalLocation + 1] = '\0';
	write(1, token, strlen(token));
   }
   else
   {
	error("REJECTION: otp_enc rejects otp_dec_d\n", 2);
   }
   close(socketFD);
   
   free(completeMessage);
   return 0;
}


int checkCharacters(char * str)
{

   int index;

   for (index = 0; index < strlen(str) - 1; index++)
   {
	if (str[index] < 65)
	{
	   if (str[index] != 32)
	   {
		return 0;
	   }
	}
	else if (str[index] > 90)
	{
	   return 0;
	}   
   }
   return 1;
}


void error(const char* message, int exitValue)
{
   fprintf(stderr, message);
   exit(exitValue);
}


