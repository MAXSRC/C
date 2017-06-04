#include <stdio.h>  
#include <time.h>  
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
  
/* 
[chenndao@localhost log]$ ./maplogread 3000000.txt 
Finished, total lines is 3000000  
total costed time 0 sec 
[chenndao@localhost log]$ ./maplogread 3000000.txt 
Finished, total lines is 3000000  
total costed time 1 secs 
*/  
  
int main( int argc, char *argv[] )  {  
  	
  	// if ( argc != 2 )  {  
   //    	printf("usage: \n maplogread intel.txt\n");  
   //    	return 0;  
   //  }  
    
  	char *memory = NULL;  
  	int file_length = 0;  
  	char *start_address = 0;  
  	int line_num = 0;  
  	int time_start = time(NULL);
	int costs;
  	// int fd = open( argv[1], O_RDONLY );  
  	int fd = open( "intel.txt", O_RDONLY );  

  	if ( fd > 0 ) {  
      	file_length = lseek(fd, 1, SEEK_END);  
		printf("file_length:%d\n", file_length);
      	memory = mmap( start_address, file_length, PROT_READ, MAP_SHARED, fd, 0 );  
  
      	int i = 0;  
      	for ( ; i < file_length; i++ ) {  
      		if ( memory[i] == '\n' ){  
          		++line_num;  
        	}  
    	}  
      	close( fd );  
      	munmap( memory, file_length );
		costs = time(NULL) - time_start;
      	printf("Finished, total lines is %d \n total costed time %d sec\n time:%ld\n", line_num, costs, time(NULL));  
      	//printf("total costed time %d sec\n", time(NULL) - time_start);  
    }  

  	return 0;  
}  
