#ifndef MYSHELL_H
#define MYSHELL_H 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

//header file contains all declarations and constants

	//change directory
	void change_directory(char *path);
	
	// clear screen
	void clr();
	
	//see contents in directory 
	void dir();
	
	//list environment strings
	void environ();
	
	//echo
	void echo();
	
	//help
	void help();
	
	//pause
	void my_pause();
	
	//quit
	void quit();
	



#endif
