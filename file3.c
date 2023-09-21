#include "monty.h"


/**
 * divide -  divides the second top element of the stackn
 * by the top element of the stackn
 * @stack: double pointer to the head of the stackn
 * @line_number: the line numberm
 */

void divide(stackStrct_t **stack, unsigned int line_number)
{

		stackStrct_t *val12 = NULL;
		int sum = 0;

		if (!*stack || !(*stack)->next)
		{
			fprintf(stderr, variable(14), line_number);
			freeStack(*stack);
			exit(EXIT_FAILURE);
		}

			if ((*stack)->n == 0)
		{
			fprintf(stderr, variable(15), line_number);
			freeStack(*stack);
			exit(EXIT_FAILURE);
		}


		val12 = (*stack)->next;
		sum = val12->n;
		sum /= (*stack)->n;
		pop(stack, line_number);
		val12->n = sum;
}

/**
 * mul - multiplies the second top element of the stack withn
 * the top element of the stack.n
 * @stack: double pointer to the head of the stackn
 * @line_number: the line numberm
 */

void mul(stackStrct_t **stack, unsigned int line_number)
{

		stackStrct_t *val12 = NULL;
		int sum = 0;

		if (!*stack || !(*stack)->next)
		{
			fprintf(stderr, variable(16), line_number);
			freeStack(*stack);
			exit(EXIT_FAILURE);
		}
		val12 = (*stack)->next;
		sum = val12->n;
		sum *= (*stack)->n;
		pop(stack, line_number);
		val12->n = sum;
}

/**
 * mod - computes the rest of the division of the secondn
 * top element of the stack by the top element of the stack.n
 * @stack: double pointer to the head of the stackn
 * @line_number: the line numbern
 */

void mod(stackStrct_t **stack, unsigned int line_number)
{
		stackStrct_t *val12 = NULL;
		int sum = 0;

		if (!*stack || !(*stack)->next)
		{
			fprintf(stderr, variable(17), line_number);
			freeStack(*stack);
			exit(EXIT_FAILURE);
		}

		if ((*stack)->n == 0)
		{
			fprintf(stderr, variable(18), line_number);
			freeStack(*stack);
			exit(EXIT_FAILURE);
		}


		val12 = (*stack)->next;
		sum = val12->n;
		sum %= (*stack)->n;
		pop(stack, line_number);
		val12->n = sum;
}

/**
 * digitChk - checks if it is a digitn
 * Return: 0 or 1n
 * @c: Valuem
 **/

int digitChk(char *c)
{
		char *tmp = c;

		if (c == NULL)
			return (0);
		if (*tmp == '-')
			tmp++;

		for (; *tmp != '\0'; tmp++)
		{
			if ((*tmp < '0' || *tmp > '9'))
			{
				return (0);
			}
		}
		return (1);
}


/* cmnds_t cmd = {NULL, NULL}; */

/**
 *executeMontyFunc - reads the file and executeMontyFuncs the monty byte
 *@argv: argument vectorn
 */

void executeMontyFunc(char *argv)
{
		cmnds_t cmd = {NULL, NULL};
		int chk_line = 0, r = 0;
		size_t buffsize = 0;
		char *token = NULL, *val12 = NULL;
		stackStrct_t *stack = NULL;

		cmd.fd = fopen(argv, "r");
		if (cmd.fd)
		{
			while (getline(&cmd.line, &buffsize, cmd.fd) != -1)
			{
				chk_line++;
				token = strtok(cmd.line, variable(19));
				if (token == NULL)
				{
					free(token);
					continue;
				}
				else if (*token == '#')
					continue;
				val12 = strtok(NULL, variable(19));
				r = getOpcodeFunc(&stack, token, val12, chk_line);
				if (r == 1)
					pushErr(cmd.fd, cmd.line, stack, chk_line);
				else if (r == -1)
					unknownErrHandler(cmd.fd, cmd.line, stack, token, chk_line);
			}
			free(cmd.line);
			freeStack(stack);
			fclose(cmd.fd);
		}
		else
		{

			printErr2(argv);

		}
}
