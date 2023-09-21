#include "monty_header.h"


/**
 * freeStack - free stackk
 * @stack: stackk
 */

void freeStack(stackStrct_t *stack)
{
stackStrct_t *list = NULL;

		list = stack;

		if (list != NULL)
		{
			freeStack(list->next);
			free(list);
		}

}

/**
 * freeClosedFiles - Free all and close filesn
 * @stack: Stackm
 */

void freeClosedFiles(stackStrct_t **stack)
{
	cmnds_t cmd = {NULL, NULL};
	stackStrct_t *tmp = *stack;

	while (tmp)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	fclose(cmd.fd);
	free(cmd.line);
}

/**
 * variable - prints message
 * @num: ninput
 * Return: str
 */
char *variable(int num)
{
	char *res;

	if (num <= 10)
		res = variable1(num);
	else
		res = variable2(num);
	return (res);
}

/**
 * variable1 - prints message
 * @num: ninput
 * Return: str
 */
char *variable1(int num)
{
	char *strrr;

	if (num == 0)
		strrr = "USAGE: monty file\n";
	else if (num == 1)
		strrr = "Error: Can't open file %s\n";
	else if (num == 2)
		strrr = "L%u: usage: push integer\n";
	else if (num == 3)
		strrr = "L%u: unknown instruction %s\n";
	else if (num == 4)
		strrr = "Error: malloc failed\n";
	else if (num == 5)
		strrr = "%d\n";
	else if (num == 6)
		strrr = "L%d: can't pint, stack empty\n";
	else if (num == 7)
		strrr = "L%u: can't pop an empty stack\n";
	else if (num == 8)
		strrr = "L%d: can't swap, stack too short\n";
	else if (num == 9)
		strrr = "L%d: can't add, stack too short\n";
	else if (num == 10)
		strrr = "L%u: can't pchar, stack empty\n";

	return (strrr);
}

/**
 * variable2 - prints message
 * @num: ninput
 * Return: str
 */
char *variable2(int num)
{
	char *strrr;

	if (num == 11)
		strrr = "%c\n";
	else if (num == 12)
		strrr = "L%u: can't pchar, value out of range\n";
	else if (num == 13)
		strrr = "L%d: can't sub, stack too short\n";
	else if (num == 14)
		strrr = "L%d: can't div, stack too short\n";
	else if (num == 15)
		strrr = "L%u: division by zero\n";
	else if (num == 16)
		strrr = "L%d: can't mul, stack too short\n";
	else if (num == 17)
		strrr = "L%d: can't mod, stack too short\n";
	else if (num == 18)
		strrr = "L%u: division by zero\n";
	else if (num == 19)
		strrr = " \n\t\r";
	else if (num == 20)
		strrr = "push";
	return (strrr);
}
