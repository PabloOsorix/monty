#include <stdio.h>
#include "monty.h"
FILE *file_read = NULL;

/**
 * main - This is the bytecodes interpreter.
 *@argc: Total number of arguments in argv.
 *@argv: arguments that entry by the interactive or no
 *interactive mode.
 *Return: EXIT_SUCCESS in sucess or EXIT_FAILED in case of failed.
 */
int main (int argc, char *argv[])
{
	char buffer[1024], *file_name = NULL;
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
				free_stack(stack);
				fclose(file_read);
				return (EXIT_FAILURE);
			}
			select_op(&stack, i);
		}
	}

	free_stack(stack);
	fclose(file_read);
	return(EXIT_SUCCESS);
}
