#include "monty.h"


/**
 * pint - prints the value at the top of the stack, followed by a new line.
 *@head: Pointer to the top of the stack (double linked list).
 *@line_number: line number of read_file.
 *Return: None, it's void.
 */

void pint(stack_t **head, unsigned int line_number)
{

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit (EXIT_FAILURE);
	}
	fprintf(stdout, "%d", (*head)->n);
}

/**
 * pop - removes the top element of the stack
 *@head: This is a pointer to head of the stack.
 *@line_number: Number of line.
 *Return: void
 */

void pop(stack_t **head, unsigned int line_number)
{
	stack_t *delete_tnode;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	delete_tnode = *head;
	(*head) = (*head)->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(delete_tnode);

}

/**
 * swap - swaps the top two elements of the stack.
 *@head: Pointer to the head of the stack (double linked list).
 *@line_number: number of line of the read_file.
 *Return: None, is a void.
 */

void swap(stack_t **head, unsigned int line_number)
{
	int i = 0;
	if ((*head) == NULL || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%d can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = i;
}

/**
 * add - adds the top two elements of the stack.
 *@head: Pointer to a head of the stack (double linked list).
 *@line_number: number line of the read_file.
 *Return: None, is a void.
 */

void add(stack_t **head, unsigned int line_number)
{
	int sum = 0;
	stack_t *delete_tnode;

	if ((*head) == NULL || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%d can't add, stack too short\n", line_number);
		exit (EXIT_FAILURE);
	}
	sum = (*head)->n + (*head)->next->n;
	delete_tnode = *head;
	(*head)->next->n = sum;
	*head = delete_tnode->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(delete_tnode);
}

/**
 *nop - doesn't do anything.
 *@head: Pointer to the head of the stack (double linked list)
 *@line_number: number line of file read_file.
 *Return: None, is a void.
 */

void nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

}
