#ifndef MYSHELL_H
#define MYSHELL_H 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER 2000
#define MAX_ARGS 100

//header file contains all declarations and constants

	//change directory
	void cd_command(char *directory);
	
	// clear screen
	void clear_command();
	
	//see contents in directory 
	void lsdir_command(char *directory);
	
	//list environment strings
	void environ_command();
	
	//echo
	void echo_command(char *comment);
	
	//help
	void help_command();
	
	//pause
	void pause_command();
	
	//quit
	void quit_command();
	



#endif
