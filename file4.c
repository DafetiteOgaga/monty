#include "monty.h"


/* int value; */
/**
 * push - pushes a new node with the given value to the stackn
 * @stack: double pointer to the head of the stackn
 * @line_number: value to be pushedn
 */

void push(stackStrct_t **stack, unsigned int line_number)
{
		int value;
		stackStrct_t *new = NULL;
		(void)line_number;

		value = 0;
		new = createNode(value);

		new->next = *stack;
		if (*stack != NULL)
			(*stack)->prev = new;
		*stack = new;
}

/**
 * getOpcodeFunc - gets the opcode functionn
 * @stack: pointer to the stack or queuen
 * @arg: the commandn
 * @val12: the valuen
 * @line_number: the line numbern
 * Return: 0 on success || 1 if not a digit || -1 on errorn
 */

int getOpcodeFunc(stackStrct_t **stack, char *arg, char *val12,
					int line_number)
{
	int value;
	int i = 0;

	instructionStrct_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{NULL, NULL}
	};
	while (op[i].opcode)
	{
		if (!strcmp(arg, op[i].opcode))
		{
			if (!strcmp(arg, variable(20)))
			{
				if (digitChk(val12) == 1)
					value = atoi(val12);
				else
				{
					value = 1;
					return (value);
				}
			}
			op[i].f(stack, (unsigned int)line_number);
			break;
		}
		i++;
	}
	if (!op[i].opcode)
		return (-1);
	return (0);
}

