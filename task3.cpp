#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include<errno.h>
#include<fcntl.h>
extern int errno;
int main(int argc, const char *argv[])
{
	int fd = access("sample.txt", F_OK);
	if(fd == -1)
	{
		printf("Error Number : %d\n", errno);
		perror("Error Description : ");
	}
	else
	{
		printf("No Error\n");
	}
	return 0;
}
