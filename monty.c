#include <stdio.h>
#include "monty.h"
#define DELIM " \t\n"

/**
 * main - This is the bytecodes interpreter.
 *@argc: Total number of arguments in argv.
 *@argv: arguments that entry by the interactive or no
 *interactive mode.
 *Return: EXIT_SUCCESS in sucess or EXIT_FAILED in case of failed.
 */
int main (int argc, char *argv[])
{
	FILE *file_read = NULL;
	char *buffer = malloc(sizeof(char) * 1024), *file_name = NULL;
	char *token = NULL;
	unsigned int i;
	stack_t *stack = NULL;
	void (*select_op)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	if (buffer ==  NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit (EXIT_FAILURE);
	}
	file_name = argv[1];
	file_read = fopen(file_name, "r");
	if (file_read == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		free(stack);
		free(buffer);
		return (EXIT_FAILURE);
	}
	for (i = 1; fgets(buffer, sizeof(buffer), file_read) != NULL; i++)
	{
		token = strtok(buffer, DELIM);
		if (token != NULL)
		{
			select_op = select_opcodes(token);
			if (select_op == NULL)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", i, token);
				free(stack);
				free(buffer);
				fclose(file_read);
				return (EXIT_FAILURE);
			}
			select_op(&stack, i);
		}
	}
	free(buffer);
	free(stack);
	free(token);
	fclose(file_read);
	return(EXIT_SUCCESS);
}
