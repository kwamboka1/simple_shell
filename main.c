#include "main.h"

/**
 * free_data - frees data structure
 *
 * @datas: data structure
 * Return: no return
 */
void free_data(data_shell *datas)
{
	unsigned int i;

	for (i = 0; datas->_environ[i]; i++)
	{
		free(datas->_environ[i]);
	}

	free(datas->_environ);
	free(datas->pid);
}

/**
 * set_data - Initialize data structure
 *
 * @datas: data structure
 * @av: argument vector
 * Return: no return
 */
void set_data(data_shell *datas, char **av)
{
	unsigned int i;

	datas->av = av;
	datas->input = NULL;
	datas->args = NULL;
	datas->status = 0;
	datas->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	datas->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		datas->_environ[i] = _strdup(environ[i]);
	}

	datas->_environ[i] = NULL;
	datas->pid = aux_itoa(getpid());
}

/**
 * main - Entry point
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	data_shell datas;
	(void) ac;

	signal(SIGINT, get_sigint);
	set_data(&datas, av);
	shell_loop(&datas);
	free_data(&datas);
	if (datas.status < 0)
		return (255);
	return (datas.status);
}
