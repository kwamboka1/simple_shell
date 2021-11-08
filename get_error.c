#include "main.h"

/**
 * get_error - calls the error according the builtin, syntax or permission
 * @datas: data structure that contains arguments
 * @eval: error value
 * Return: error
 */
int get_error(data_shell *datas, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = error_env(datas);
		break;
	case 126:
		error = error_path_126(datas);
		break;
	case 127:
		error = error_not_found(datas);
		break;
	case 2:
		if (_strcmp("exit", datas->args[0]) == 0)
			error = error_exit_shell(datas);
		else if (_strcmp("cd", datas->args[0]) == 0)
			error = error_get_cd(datas);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	datas->status = eval;
	return (eval);
}
