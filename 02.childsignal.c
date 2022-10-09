#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void handler()     		//signal handler to execute our logic rather than default one.
{
	printf("Don't Worry! Handler is here!!!!\n");
}
int main()
{
	int processId;

	signal(SIGCHLD,handler);	//registers signal handler
	
	processId=fork();               //Creates a child process and stores processID
	switch(processId){
	
		case 0:                             //child process
			printf("Child is here!\n");
			exit(EXIT_SUCCESS);
		default:			   //parent process

			printf("Parent is here!\n");
			printf("Child's PID is %d\n",processId);
			wait(NULL);
	}

	return 0;
}
