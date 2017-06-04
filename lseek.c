#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){

	int handle = open("lseek.txt", O_RDONLY);
	
	int len = lseek(handle, 0, SEEK_END);
	int i = 0;
	char ch;

	lseek(handle, 0, SEEK_SET);
	for ( ; i < len; i++){
		read(handle, &ch, 1);
		printf("%d:%c\n", i, ch);
	}
	printf("len :%d\n", len);
	close(handle);
	return 0;

}

