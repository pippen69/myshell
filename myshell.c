#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>
#include "myshell.h"

//change directory 
void cd_command(char *directory){

	if (directory== NULL){
	char cwd [1024]; 
	if (getcwd(cwd,sizeof(cwd)) != NULL){
	printf("%s\n", cwd);
	}
	else {
	perror("getcwd()error");
	}
	
	}else{
	if (chdir(directory) !=0){
	perror("chdir() error");
	}else{
	setenv("PWD", directory, 1);//update pwd
	}
}
}

//clear
	void clear_command(){
	system ("clear || cls");
	}
	
//change directory
	void lsdir_command(char *directory){
	if (directory == NULL){
	directory = "no";
	}
	DIR *dir = opendir(directory);
	if (dir){
	struct dirent *enter;
	while ((enter = readdir(dir)) != NULL){
	printf ("%s\n", enter->d_name);
	}
	closedir(dir);
	}else{
	perror("opendir() error");
	}
	}
//environment varible
	void environ_command(){
	extern char **environ; //extern is used for storing a class outside 
	char **env = environ;
	while (**env != '\0'){
	printf("%s\n", *env);
	env++;
	}
	}

void echo_command(char *comment){
printf("%s\n", comment);
}

void help_command(){
printf("help command list");
printf("cd - change directory");
printf("clear - clear page");
printf("lsdir - list contents in the directory ");
printf("environ - go to environment");
printf("echo - repeats what you said  ");
printf("help - help directory (you are here!)");
printf("pause - pause process ");
printf("quit - quit shell ");
}

void pause_command(){
printf("press enter to continue");
fflush(stdout);
while(getchar()!= '\n');
}

void quit_command(){
printf("exit shell");
exit(0);
}
	
int main(){
	char input [1024];
	while(1){
		printf("MyShell>");
		if(fgets(input, sizeof(input), stdin) == NULL){
			break;
		}
	//tokenize the input
	char *token;
	token=strtok(input, "\n");
	char *arg = strtok (NULL,"/n");
		//execute command
	if (token!=NULL){
		if (strcmp(token, "cd") == 0){
			cd_command(arg);
		}
		else if (strcmp(token, "clear") == 0){
			clear_command();
		}
		else if (strcmp(token, "lsdir") == 0){
			lsdir_command(arg);
		}
		else if (strcmp(token, "environ") == 0){
			environ_command();
		}
		else if (strcmp(token, "echo") == 0){
			echo_command(arg);
		}
		else if (strcmp(token, "help") == 0){
			help_command();
		}
		else if (strcmp(token, "pause") == 0){
			pause_command();
		}
		else if (strcmp(token, "quit") == 0){
			quit_command();
		}
		else{
			perror("command not found");
		}
		
	}
	}
	return 0;
}
