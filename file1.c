#include "monty_header.h"




/**
 * createNode - creates a new node
 * @n: the value of the nodem
 * Return: new node
 */

stackStrct_t *createNode(int n)
{
		stackStrct_t *new = NULL;

		new = malloc(sizeof(stackStrct_t));
		if (new == NULL)
		{
			fprintf(stderr, "%s", variable(4));
			exit(EXIT_FAILURE);
		}
		new->n = n;
		new->next = NULL;
		new->prev = NULL;

		return (new);
}



/**
 * pall - prints alml the values on the stackm
 * @stack: double pointer to the head of the stackm
 * @line_number: the current line numberm
 */
void pall(stackStrct_t **stack, unsigned int line_number)
{
		stackStrct_t *tmp = NULL;
		(void)line_number;

		tmp = *stack;

		while (tmp != NULL)
		{
			fprintf(stdout, variable(5), tmp->n);
			tmp = tmp->next;
		}
}

/**
 * pint - prints the value atm the top of the stacknn
 * @stack: double pointer to the head of the stackn
 * @line_number: the current line numbern
 */

void pint(stackStrct_t **stack, unsigned int line_number)
{
		if (!*stack || !stack)
		{
			fprintf(stderr, variable(6), line_number);
			freeClosedFiles(stack);
			exit(EXIT_FAILURE);
		}
		else
			fprintf(stdout, variable(5), (*stack)->n);

}

/**
 * pop - removes the top element of the stack.m
 * @stack: double pointer to the head of the stackn
 * @line_number: the current line numberm
 */
void pop(stackStrct_t **stack, unsigned int line_number)
{
		stackStrct_t *temp;

		if (!*stack)
		{
			fprintf(stderr, variable(7), line_number);
			freeStack(*stack);
			exit(EXIT_FAILURE);
		}

		else
		{
			temp = (*stack)->next;
			free(*stack);
			if (temp)
				temp->prev = NULL;
			*stack = temp;
		}
}



/**
 * nop - functionm
 * @stack: double pointer to the head of the listn
 * @line_number: the current line number,
 */

void nop(stackStrct_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
