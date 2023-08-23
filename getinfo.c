#include "shell.h"

/**
 * clear_info - initializes info_t struct
 * @info: struct address
 */

void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
* set_info - Sets up the info_t structure
* @info: The address of the struct
* @av: The vector of arg
*/
void set_info(info_t *info, char **av)
{
	int i = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info - releases the info_t struct fields
 * @info: address of the structure
 * @all: Set to 'true' if all fields need to be freed
 */
void free_info(info_t *info, int all)
{
	free(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->environ);
			info->environ = NULL;
		free((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		putchar(BUF_FLUSH);
	}
}
