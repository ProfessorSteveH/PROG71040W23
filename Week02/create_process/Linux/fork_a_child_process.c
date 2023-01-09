// PROG71040 W23 - Week02 - Prof SteveH
//
// compile with gcc -o fork_a_child_process fork_a_child_process.c
//
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN	1024

int main()
{
	int parentID = getpid();		// get the ID of this process

	char programName[MAXLEN];
	printf("[ParentID: %d] enter name of program to start (make sure to put a \"./\" before any program that is in this directory): ", parentID);
	fgets(programName, MAXLEN, stdin);
	if(strlen(programName) <= 1)
		exit(EXIT_FAILURE);
	
	int childID = fork();		// fork this process
	if(childID == 0)		// check which process "I" am...
	{
		execlp(programName, programName, (char*)0);	// if the child, replace the running
													// program with this new one
													// curiously, this execution "vanishes"
													// so the next line is not ever run
		printf("error:  %s cannot be found or executed\n", programName);
	}
	else
	{
		waitpid(childID, 0, 0);
		printf("child program %s has finished\n", programName);
	}
}
