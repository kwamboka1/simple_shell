#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

/**
 * read_s2 - string to accept the command keyed in by user
 * @line: The string to be read
 *
 */
void read_s2(char *line)
{
	int **size;

	/**read one line*/
	getline(&line, &size, stdin);
	free(line);
}
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char s1[100], *s2[];

	/** environment variable */
	char *envp[] = {(char *) "PATH=/bin", 0};

	while (1)	/**repeat forever*/
	{
		write(1, "#cisfun$ ", 9);	/**display prompt on screen*/
		read_s2(s2);	/**read input from terminal*/
		if (fork() != 0)	/**parent*/
			wait(NULL);	/**wait for child*/
		else
		{
			strcpy(s1, "/bin/");
			strcat(s1, s2);
			execve(s1, s2, envp);	/**execute command*/
		}
		if (strcmp(s2, "exit") == 0)
			break;
	}
	return (0);
}
