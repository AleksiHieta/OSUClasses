#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	struct dirent **namelist;
	int i,n;
	char* tmp = "movies_sample_1.csv";
	char* ret;

	n = scandir(".", &namelist, 0, alphasort);
	if (n < 0)
		perror("scandir");
	else {
		for (i = 0; i < n; i++) {
			if(strstr(namelist[i]->d_name, tmp) != NULL){
				printf("%s\n", namelist[i]->d_name);
			}
			free(namelist[i]);
		}
	}
	free(namelist);

	return 0;
}
