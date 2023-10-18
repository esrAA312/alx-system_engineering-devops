#include "main.h"

void handle_cd(char *args[])
{
	int  arg_count = 0;
	char *home_directory = getenv("HOME");
char current_directory[MAX_COMMAND_LENGTH];

	if (arg_count == 1 || strcmp(args[1], "~") == 0)
	{
		if (chdir(home_directory) != 0)
		{
			perror("chdir");
		} else
		{
			if (setenv("PWD", home_directory, 1) != 0)
			{
				perror("setenv");
				exit(EXIT_FAILURE);
			}
		}
	} else if (strcmp(args[1], "-") == 0)
	{
		if (chdir(current_directory) != 0)
			perror("chdir");
		else
		{
			if (setenv("PWD", current_directory, 1) != 0)
			{
				perror("setenv");
				exit(EXIT_FAILURE); }
		}
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("chdir"); }
		else
		{
			char new_directory[MAX_COMMAND_LENGTH];
		if (getcwd(new_directory, sizeof(new_directory)) == NULL)
		{
				perror("getcwd");
				exit(EXIT_FAILURE);
			}
			if (setenv("PWD", new_directory, 1) != 0)
			{
				perror("setenv");
				exit(EXIT_FAILURE);
			}
		}
	}
}
