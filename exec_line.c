#include "main.h"

/**
 * exec_line - finds builtins and commands
 *
 * @datas: data relevant (args)
 * Return: 1 on success.
 */
int exec_line(data_shell *datas)
{
	int (*builtin)(data_shell *datas);

	if (datas->args[0] == NULL)
		return (1);

	builtin = get_builtin(datas->args[0]);

	if (builtin != NULL)
		return (builtin(datas));

	return (cmd_exec(datas));
}
