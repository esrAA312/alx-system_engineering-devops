#include "main.h"

int is_built_in_command(const char *command)
{
	char *built_in_commands[] = {
		"cd", "exit", "env", "ls"};
	int i = 0;

	while (built_in_commands[i] != NULL)
	{
		if (strcmp(command, built_in_commands[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
