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
		new->next->prev = new;
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
	(void)line_number;
	}
}

/**
 * sub - This opcode subtracts the top element
 * of the stack from the second top element of the stack.
 * @head: Pointer to head of the stack.
 * @line_number: line number of the file.
 */
void sub(stack_t **head, unsigned int line_number)
{
	stack_t *delete_tnode = NULL;

	if ((*head) == NULL || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(*head);
		fclose(file_read);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n -= (*head)->n ;
	delete_tnode = *head;
	*head = delete_tnode->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(delete_tnode);
}

/**
 * div - This function divides the second top element of the 
 * stack by the top element of the stack.
 * @head: Pointer to the head of the stack 
 * @line_number: Line number in the read_file.
 *Return: None is void 
 */ 
 
void _div(stack_t **head, unsigned int line_number)
{
	int _div = 0;
	stack_t *delete_tnode = NULL;	

	if ((*head) == NULL || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(*head);
		fclose(file_read);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*head);
		fclose(file_read);
		exit(EXIT_FAILURE);
	} 
	_div = (*head)->next->n / (*head)->n ;
	(*head)->next->n = _div;
	delete_tnode = *head;
	*head = delete_tnode->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(delete_tnode);
}

/**
 * mul - This funtion multiplies the second top element of 
 * the stack with the top element of the stack.
 * @head: Pointer to the head of the stack.
 * @line_number: current line of the file_read.
 * Return: None is a void.
 */

void _mul(stack_t **head, unsigned int line_number)
{
	int _mul = 0;
	stack_t *delete_tnode = NULL;

	if ((*head) == NULL || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(*head);
		fclose(file_read);
		exit(EXIT_FAILURE);
	}
	_mul = (*head)->next->n * (*head)->n ;
	(*head)->next->n = _mul;
	delete_tnode = *head;
	*head = delete_tnode->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(delete_tnode);	




}

