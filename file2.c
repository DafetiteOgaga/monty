#include "monty.h"


/**
 * swap - swaps the top two elements of the stack.j
 * @stack: double pointer to the head of the listj
 * @line_number: line numbern
 */

void swap(stackStrct_t **stack, unsigned int line_number)
{
		stackStrct_t *val12;
		int tmp = 0;

		val12 = *stack;
		if (val12 == NULL || val12->next == NULL)
		{
			fprintf(stderr, variable(8), line_number);
			freeStack(*stack);
			exit(EXIT_FAILURE);
		}
		else
		{
			tmp = val12->n;
			val12->n = val12->next->n;
			val12->next->n = tmp;
		}
}

/**
 * add - adds the top two elements of the stack.n
 * @stack: double pointer to the head of the stackn
 * @line_number: the line numbern
 */

void add(stackStrct_t **stack, unsigned int line_number)
{
		stackStrct_t *val12 = NULL;
		int sum = 0;

		if (!*stack || !(*stack)->next)
		{
			fprintf(stderr, variable(9), line_number);
			freeStack(*stack);
			exit(EXIT_FAILURE);
		}
		val12 = (*stack)->next;
		sum = (*stack)->n;
		sum += (*stack)->next->n;
		pop(stack, line_number);
		val12->n = sum;
}

/**
 * pchar - adds the top two elements of the stack.n
 * @stack: double pointer to the head of stackb
 * @line_number: the line numbern
 */

void pchar(stackStrct_t **stack, unsigned int line_number)
{
		if (!*stack)
		{
			fprintf(stderr, variable(10), line_number);
			exit(EXIT_FAILURE);
		}
		if ((*stack)->n >= 0 && (*stack)->n <= 127)
			printf(variable(11), (*stack)->n);
		else
		{
			fprintf(stderr, variable(12), line_number);
			freeStack(*stack);
			exit(EXIT_FAILURE);
		}

}

/**
 * sub - substracts the top two elements of the stack.n
 * @stack: double pointer to the head of the stackn
 * @line_number: the line numbern
 */

void sub(stackStrct_t **stack, unsigned int line_number)
{
		stackStrct_t *val12 = NULL;
		int sum = 0;

		if (!*stack || !(*stack)->next)
		{
			fprintf(stderr, variable(13), line_number);
			freeStack(*stack);
			exit(EXIT_FAILURE);
		}
		val12 = (*stack)->next;
		sum = val12->n;
		sum -= (*stack)->n;
		pop(stack, line_number);
		val12->n = sum;
}
