#include "monty.h"


/**
 * printErr1 - prints an usage error message
 * Return: FAILURE
 */

void printErr1(void)
{
	fprintf(stderr, "%s", variable(0));
	exit(EXIT_FAILURE);

}

/**
 *printErr2 - prints an open file error message
 *@file: filej
 * Return: FAILURE
 */

void printErr2(char *file)
{
	fprintf(stderr, variable(1), file);
	exit(EXIT_FAILURE);

}

/**
 * pushErr - handles a push error
 * @fd: file desciptork
 * @line: bufferl
 * @stack:  stack or queuem
 * @line_number: line number of the commandn
 */

void pushErr(FILE *fd, char *line, stackStrct_t *stack, int line_number)
{
		fprintf(stderr, variable(2), line_number);
		fclose(fd);
		free(line);
		freeStack(stack);
		exit(EXIT_FAILURE);
}

/**
 * unknownErrHandler - Error handler for unknown instructions
 * @fd: file descriptorm
 * @line: bufferm
 * @stack:  stack or queuem
 * @line_n: line number of the commandn
 * @val12: instructionm
 */

void unknownErrHandler(FILE *fd, char *line, stackStrct_t *stack,
						char *val12, int line_n)
{
		fprintf(stderr, variable(3), line_n, val12);
		fclose(fd);
		free(line);
		freeStack(stack);
		exit(EXIT_FAILURE);
}
