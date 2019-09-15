#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
char buf[32] = "i am a lovely bunny!";
int main(){
	
	int fd = 10;
	int len = 0;
	int f = open("1.txt",O_APPEND);
	printf("fd is %d\n",f);
	printf("buf to write is %s\n",buf);
	char buf2[30];
	read(f, buf2, 32);
	printf("read buf is %s\n", buf2);
	read(0, buf2, 32);
	len = write(f, buf2, 10);
	
    printf("len is %d\n", len);
	
	
	return 0;

}