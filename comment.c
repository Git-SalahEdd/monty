#include "monty.h"

/**
 * is_comment - checks if a line is a comment
 * @word: the first word on that line
 *
 * Return: 1 if true, 0 if false
 */

int is_comment(char *word)
{
	if (*word == '#')
		return (1);
	return (0);
}
