#include "myshell.h"


void execute_command(char *input){
	char *token;
	char *delim = "\n";
	token=strtok(input, delim);

	//execute command for changing directory
	if (token!=NULL){
		if (strcmp(token, "cd") == 0){
		       token=strtok(NULL, delim);
			change_directory(token);
		}
		else if (strcmp(token, "clr") == 0){ //clear page
		       token=strtok(NULL, delim);
			clr();
		}
		else if (strcmp(token, "dir") == 0){ //directory 
		       token=strtok(NULL, delim);
			dir();
		}
		else if (strcmp(token, "environ") == 0){ //environmentvaribles
		       token=strtok(NULL, delim);
			environ();
		}
		else if (strcmp(token, "echo") == 0){ //echo
		       token=strtok(NULL, delim);
			echo();
		}
		else if (strcmp(token, "help") == 0){ //help
		       token=strtok(NULL, delim);
			help();
		}
		else if (strcmp(token, "pause") == 0){ //pause
		       token=strtok(NULL, delim);
			pause();
		}
		else if (strcmp(token, "quit") == 0){ //quit
		       token=strtok(NULL, delim);
			quit();
		}
		else{
			perror("command not found"); // error message
		}
		
}
}

int main(){
	char input [1024]; //size of input

	while(1){
		printf("MyShell>"); //mimics shell input cursor
		if(fgets(input, sizeof(input), stdin) == NULL){
			break;
		}
		execute_command(NULL);
	}
	return 0;
}


