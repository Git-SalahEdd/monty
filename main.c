#include "monty.h"

/**
 * isnum - checks if a string is a number
 * @i: string to check
 *
 * Return: 1 if true, 0 if false
 */

int isnum(char *i)
{
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
 * @str: string to print
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
	char *delim = " \t\n\r", *line = NULL;
	FILE *bytecodes;
	size_t len = 0;
	ssize_t read;
	int line_num = 1, n;

	if (ac != 2)
		err("USAGE: monty file\n");

	file = av[1];
	bytecodes = fopen(file, "r");
	if (!bytecodes)
		err("Error: Can't open file %s\n", file);

	while ((read = getline(&line, &len, bytecodes)) != -1)
	{
		word1 = strtok(line, delim);
		word2 = strtok(NULL, delim);
		if (!isnum(word2))
			err("L%d: usage: push integer\n", line_num);
		n = atoi(word2);
		if (strcmp(word1, "push") == 0)
			push(n);
		else if (strcmp(word1, "pall") == 0)
			pall();
		else
			err("L%d: unknown instruction %s\n", line_num, word1);
		free(line);
		line_num++;
	}
	fclose(bytecodes);
	return (EXIT_SUCCESS);
}
