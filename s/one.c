#include "main.h"

int is_built_in_command(const char *command)
{
for (int i = 0;
	i < sizeof(built_in_commands) / sizeof(built_in_commands[0]); i++)
{
if (strcmp(command, built_in_commands[i]) == 0)
return (1);
		    }
	    return 0;
}

void display_prompt(void)
{
	    write(STDOUT_FILENO, "$ ", 2);
}

ssize_t custom_read(char *buffer, size_t length)
{
	    return read(STDIN_FILENO, buffer, length);
}
