#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <stdbool.h>

extern char **environ;
#define MAX_COMMAND_LENGTH 1024
const char *built_in_commands[] = {
	"cd",
	"exit",
	"env",
	"ls",
};

void execute_external_command(char *args[], int *exit_status);
void handle_ls(char *args);
void handle_env(void);
void handle_exit(char *args[], int *exit_status);
void handle_cd(char *args[]);
ssize_t custom_read(char *buffer, size_t length);
void display_prompt(void);
int is_built_in_command(const char *command);
#endif
