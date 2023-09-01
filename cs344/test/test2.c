#include <stdio.h>  // for perror
#include <stdlib.h>   // for exit
#include <unistd.h>   // for execv
#include <string.h>

int main(){
char* str1 = "Foo";
char* str2 = "FooBar";
int n = strlen(str1) < strlen(str2) ? strlen(str1) : strlen(str2);
printf("%d, %d\n", n, strncmp(str1, str2, n));

return 0;

}
