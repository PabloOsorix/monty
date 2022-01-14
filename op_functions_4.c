#include "monty.h"

/**
 *mod - This function computes the rest of the division of the second 
 top element of the stack by the top element of the stack.
 * @head: Pointer to the head of the stack.
 * @line_number: Current line of the file_read.
 * Return: None, is void.
 */
void _mod(stack_t **head, unsigned int line_number)
{

    int _mod = 0;
	stack_t *delete_tnode = NULL;	

	if ((*head) == NULL || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
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
	_mod = (*head)->next->n % (*head)->n ;
	(*head)->next->n = _mod;
	delete_tnode = *head;
	*head = delete_tnode->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(delete_tnode);
}