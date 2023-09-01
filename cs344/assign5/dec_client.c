/**************************************
 *
 *	File: dec_client.c
 *
 *	Date: 11/28/2021
 *
 *
*************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void error(const char *message){
	perror(message);
	exit(0);
}

long get_length(char* filename){
	FILE *file = fopen(filename, "r");
	fpos_t idx;
	long length;

	fgetpos(file, &idx);
	if(fseek(file, 0, SEEK_END) || (length = ftell(file)) == -1){
		perror("file length\n");
	}
	fsetpos(file, &idx);

	return length;
}

void send_file(char *filename, int sockfd, int file_len){
	int fd = open(filename, 'r');
	char buffer[1000];
	bzero(buffer, sizeof(buffer));
	int bytes_read;
	int bytes_written;

	while(file_len > 0){
		bytes_read = read(fd, buffer, sizeof(buffer));
		if(bytes_read == 0){
			break;
		}
		if(bytes_read < 0){
			perror("Error reading file");
			exit(1);
		}
		file_len -= bytes_read;
	}	
	char* p;
	p = buffer;
	while(bytes_read > 0){
		bytes_written = write(sockfd, p, bytes_read);
		if(bytes_written < 0){
			perror("Error writing socket");
			exit(1);
		}
		bytes_read -= bytes_written;
		p += bytes_written;
	}
	return;
}

int receive_file(int sockfd){
	int n;
	char buffer[1000];
	bzero(buffer, sizeof(buffer));

	while(1){
		int bytes_read;
		bytes_read = read(sockfd, buffer, sizeof(buffer));
		if(bytes_read == 0){
			break;
		}
		if(bytes_read < 0){
			error("error reading file");
		}
		n = write(1, buffer, bytes_read);
		if(n < 0){
			error("error writing socket");
		}
	}
}

int main(int argc, char* argv[]){
	int client_sockfd, port_num, n, otp_val, textfd;
	struct sockaddr_in serv_addr;
	struct hostent* server;

	FILE *fp;
	const char hostname[] = "localhost";

	char buffer[1000];
	bzero(buffer, sizeof(buffer));
	
	if(argc != 4){
		fprintf(stderr, "error\n");
	}
	
	port_num = atoi(argv[3]);
	client_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(client_sockfd < 0){
		perror("Error opening socket");
		exit(1);
	}
	
	server = gethostbyname(hostname);
	if(server == NULL){
		perror("Host DNE");
		exit(1);
	}

	otp_val = 1;
	setsockopt(client_sockfd, SOL_SOCKET, SO_REUSEADDR, &otp_val, sizeof(int));

	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(port_num);

	if(connect(client_sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
		perror("connection error");
		exit(1);
	}

	char auth[] = "dec_bs";
	write(client_sockfd, buffer, sizeof(buffer));
	if(strcmp(buffer, "dec_d_bs") != 0){
		fprintf(stderr, "bad port");
		exit(2);
	}
	
	long infile_len = get_length(argv[1]);
	long key_len = get_length(argv[2]);
	if(infile_len > key_len){
		fprintf(stderr, "Key is too short\n");
		exit(1);
	}

	send_file(argv[1], client_sockfd, infile_len);
	send_file(argv[2], client_sockfd, key_len);

	n = read(client_sockfd, buffer, sizeof(buffer));
	if(n < 0){
		perror("error reading socket");
		exit(1);
	}
	printf("%s\n", buffer);
	close(client_sockfd);
	return 0;

}
