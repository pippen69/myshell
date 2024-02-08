# Zainab Nomani - 100784761 - Operating Systems - Lab2
# Navdeep Virdi - 100827233
all: myshell
myshell: myshell.c utility.c
	gcc -o myshell myshell.c utility.c -I.

