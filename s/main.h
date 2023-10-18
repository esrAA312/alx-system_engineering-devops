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
extern char *built_in_commands[];

void execute_external_command(char *args[]);
void handle_ls(char *args[], int co);
void handle_env(void);
void handle_exit(char *args[], int co);
void handle_cd(char *args[], int co);
int is_built_in_command(const char *command);
#endif
