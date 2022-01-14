#include "monty.h"

/**
 *select_opcodes - Function that copares the op codes with an array
 *that contains function to execute in case of match with op_codes.
 *@token: op_case tokenize which we´ll compare to select function.
 *Return: in case of match return the function else: return NULL.
 */

void (*select_opcodes(char *token))(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t op_codes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{NULL, NULL}};

	while (op_codes[i].opcode != NULL)
	{
		if (strcmp(op_codes[i].opcode, token) == 0)
		{
			return (op_codes[i].f);
		}
		i++;
	}
	return (NULL);
}
