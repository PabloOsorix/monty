#include "monty.h"


/**
 * push - push node to the top of the stack
 *@head: the stack header
 *@line_number: the line number
 *
 *Return: void
 */
void push(stack_t **head, unsigned int line_number)
{
	stack_t *new;
	char *token = strtok(NULL, DELIM);

	if (!token)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*head);
		fclose(file_read);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*head);
		fclose(file_read);
		free(new);
		exit(EXIT_FAILURE);
	}
	if (!is_number(token))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*head);
		free(new);
		fclose(file_read);
		exit(EXIT_FAILURE);
	}
	new->n = atoi(token);
	new->next = *head;
	new->prev = NULL;
	*head = new;
	if (new->next != NULL)
		(new->next)->prev = new;
}


/**
 * pall - prints all the values on the stack, starting from
 * the top of the stack
 *@h: the stack
 *@line_number: the line number
 *
 *Return: void
 */
void pall(stack_t **h, unsigned int line_number)
{
	stack_t *tmp = *h;

	while (tmp)
	{
		fprintf(stdout, "%d\n", (tmp)->n);
		tmp = (tmp)->next;
	}
	(void)line_number;
}
