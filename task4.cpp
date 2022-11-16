#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/sendfile.h>
#include <sys/random.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include<errno.h>
#include<fcntl.h>
#define BUFFER_SIZE 8
int main() {
int fOut, fIn;
printf("\nI/O test with sendfile() and related system calls.\n\n");
// Grab a BUFFER_SIZE buffer.
// The buffer will have random data in it but we don't care about that.
printf("Allocating 64 MB buffer: ");
char *buffer = (char *) malloc(BUFFER_SIZE);
printf("DONE\n");
// Write the buffer to fOut
printf("Writing data to first buffer: ");
fOut = open("buffer1", O_RDONLY);
write(fOut, &buffer,BUFFER_SIZE);
close(fOut);
printf("DONE\n");
printf("Copying data from first file to second: ");
fIn = open("buffer1", O_RDONLY);
fOut = open("buffer2", O_RDONLY);
sendfile(fOut, fIn, 0, BUFFER_SIZE);
close(fIn);
close(fOut);
printf("DONE\n");
printf("Freeing buffer:"); 
free(buffer);
printf("DONE\n");
printf("Deleting files: ");
unlink("buffer1");
unlink("buffer2");
printf("DONE\n");
return 0;
}
