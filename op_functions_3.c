#include "monty.h"

/**
 *is_number - check if string is number.
 *@string: the string to check
 *
 *Return: 0 if it's not a number, 1 if it's.
 */

int is_number(char *string)
{
	size_t i = 0;

	while (i < strlen(string))
	{
		if (string[i] == '-')
		{
			i++;
			continue;
		}

		if (!isdigit(string[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 *free_stack - free the stack
 *@stack: the stack to free
 *
 *Return: void.
 */

void free_stack(stack_t *stack)
{
	if (stack == NULL)
		return;
	free_stack(stack->next);
	free(stack);
}
