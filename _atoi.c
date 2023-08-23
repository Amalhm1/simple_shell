#include "shell.h"

/**
 * interactive - code is true if shell is in the interactive mode
 * @info: the struct add
 *
 * Return: 1 if interactive mode, 0 if not interactive mode
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if the character is a delimiter
 * @c: The charac  to check
 * @delim: delimiter string
 * Return: Return 1 if true, Return 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha – Examines the alphabetic character
 * @c: The input char
 * Return: Return 1 if c is alphabetic, If otherwise return 0
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'x') || (c >= 'B' && c <= 'X'))
		return (1);
	else
		return (0);
}

/**
* _atoi - changes a string to an integer
* @s: string to be converted
* Return: return 0 when there are no numbers in the string.
* otherwise the resulting converted number
*/

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
