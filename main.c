#include "monty.h"

/**
 * isnum - checks if a string is a number
 * @i: string to check
 *
 * Return: 1 if true, 0 if false
 */

int isnum(char *i)
{
	if (!i)
		return (0);
	if (*i == '-')
		i++;
	while (*i)
	{
		if (*i < '0' || *i > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * err - prints error to the stderr
 * @format: string to print
 *
 * Return: void
 */

void err(char *format, ...)
{
	va_list argp;

	va_start(argp, *format);
	vfprintf(stderr, format, argp);
	va_end(argp);
	exit(EXIT_FAILURE);
}

/**
 * main - run monty functions
 * @ac: argument count
 * @av: argument vector
 *
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure
 */

int main(int ac, char *av[])
{
	char *file, *word1, *word2;
	char *delim = " \t\n\r";
	char line[1024];
	FILE *bytecodes;
	int line_num = 1, n;
	stack_t *head = NULL;

	if (ac != 2)
		err("USAGE: monty file\n");

	file = av[1];
	bytecodes = fopen(file, "r");
	if (!bytecodes)
		err("Error: Can't open file %s\n", file);

	while (fgets(line, sizeof(line), bytecodes))
	{
		word1 = strtok(line, delim);
		if (!word1)
		{
			line_num++;
			continue;
		}

		if (strcmp(word1, "push") == 0)
		{
			word2 = strtok(NULL, delim);
			if (!isnum(word2))
				err("L%d: usage: push integer\n", line_num);
			n = atoi(word2);
			push(&head, n);
		}
		else if (strcmp(word1, "pall") == 0)
			pall(head);
		else
			err("L%d: unknown instruction %s\n", line_num, word1);
		line_num++;
	}
	fclose(bytecodes);
	free_stack(head);
	return (EXIT_SUCCESS);
}
