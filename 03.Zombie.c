#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int processId;

	
	processId=fork();               //Creates a child process and stores processID
	switch(processId){
	
		case 0:                             //child process
			printf("Child is here!\n");
			exit(EXIT_SUCCESS);
		default:			   //parent process

			printf("Parent is here!\n");
			printf("PID of child is %d\n",processId);
			sleep(100);
			wait(NULL);
	}

	return 0;
}
