#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	pid_t processId;
	
	processId=fork();               //Creates a child process and stores processID
	switch(processId){
	
		case 0:                             //child process
			printf("Child is here!\n");
			while (1){
				printf("My Parent's PID is %d\n",getppid());
				sleep(1);
			}
			
			exit(EXIT_SUCCESS);
		default:			   //parent process

			printf("Parent is here!\n");
			printf("PID of child is %d\n",processId);
			sleep(2);
	}

	return 0;
}