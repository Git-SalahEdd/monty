#include "monty.h"

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
	vfprintf(stderr, str, argp);
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
	char *file, line = NULL;
	FILE *bytecodes;
	size_t len = 0;
	ssize_t read;
	int line_num = 1;
	char *bytes[2];

	if (ac != 2)
		err("USAGE: monty file\n");

	file = argv[1];
	bytecodes = fopen(file, "r");
	if (!bytecode)
		err("Error: Can't open file %s\n", file);

	while ((read = getline(&line, &len, bytecodes)) != -1)
	{
	}
}
