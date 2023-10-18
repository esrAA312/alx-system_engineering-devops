#include "main.h"

int main(void)
{
	int arg_count = 0, exit_status = 0;
	char *home_directory = getenv("HOME"), command[MAX_COMMAND_LENGTH],
	current_directory[MAX_COMMAND_LENGTH], *args[MAX_COMMAND_LENGTH], *token;
	bool enough = false;
	ssize_t read_bytes;
	size_t command_length;

	if (home_directory == NULL)
	{
		perror("getenv");
		exit(EXIT_FAILURE); }
	if (getcwd(current_directory, sizeof(current_directory)) == NULL)
	{
		perror("getcwd");
		exit(EXIT_FAILURE); }
	while (!enough && 1)
	{
		if (isatty(STDIN_FILENO) == 0)
			enough = true;
		write(STDOUT_FILENO, "$ ", 2);
		read_bytes = read(STDIN_FILENO, command, sizeof(command));
		if (read_bytes < 0)
		{
			perror("read");
			exit(EXIT_FAILURE); }
		else if (read_bytes == 0)
			exit(exit_status);
		command_length = (size_t)read_bytes;
		if (command_length > 0 && command[command_length - 1] == '\n')
		{
			command[command_length - 1] = '\0';
			command_length--; }
		token = strtok(command, " ");
		while (token != NULL)
		{
			args[arg_count] = token;
			token = strtok(NULL, " ");
			arg_count++ ; }
		args[arg_count] = NULL;
		if (arg_count > 0)
		{
			if (is_built_in_command(args[0]))
			{
				if (strcmp(args[0], "cd") == 0)
					handle_cd(args, arg_count);
				else if (strcmp(args[0], "exit") == 0)
					handle_exit(args, arg_count);
				else if (strcmp(args[0], "env") == 0)
					handle_env();
				else if (strcmp(args[0], "ls") == 0)
					handle_ls(args, arg_count); }
			else
				execute_external_command(args);
		} }
	return (0); }
