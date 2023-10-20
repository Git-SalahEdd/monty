#include "monty.h"

/**
 * switch_opcodes - switch for opcodes
 * @head: the head of the linked list
 * @word: the first word
 * @line_num: line number being operated on
 */

void switch_opcodes(stack_t **head, char *word, int line_num)
{
	int n;
	char *num;

	if (strcmp(word, "push") == 0)
	{
		num = strtok(NULL, " \t\n\r");
		if (!isnum(num))
			err("L%d: usage: push integer\n", line_num);
		n = atoi(num);
		push(head, n);
	}
	else if (strcmp(word, "pall") == 0)
		pall(*head);
	else
		err("L%d: unknown instruction %s\n", line_num, word);
}

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
	char *file, *word1;
	char line[1024];
	FILE *bytecodes;
	int line_num = 1;
	stack_t *head = NULL;

	if (ac != 2)
		err("USAGE: monty file\n");

	file = av[1];
	bytecodes = fopen(file, "r");
	if (!bytecodes)
		err("Error: Can't open file %s\n", file);

	while (fgets(line, sizeof(line), bytecodes))
	{
		word1 = strtok(line, " \n\t\r");
		if (!word1)
		{
			line_num++;
			continue;
		}
		switch_opcodes(&head, word1, line_num);
		line_num++;
	}
	fclose(bytecodes);
	free_stack(head);
	return (EXIT_SUCCESS);
}
