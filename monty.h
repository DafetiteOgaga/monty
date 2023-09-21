#ifndef _MONTY_H_
#define _MONTY_H_

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>


/**
 * struct cmnds - cmd
 * @fd: file descriptor
 * @line: line
 */

typedef struct cmnds
{
	FILE *fd;
	char *line;
} cmnds_t;

extern cmnds_t cmd;
extern int value;

/**
 * struct stackStrct - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stackStrct
{
	int n;
	struct stackStrct *prev;
	struct stackStrct *next;
} stackStrct_t;

/**
 * struct instructionStrct - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instructionStrct
{
	char *opcode;
	void (*f)(stackStrct_t **stack, unsigned int line_number);
} instructionStrct_t;



void executeMontyFunc(char *argv);
int getOpcodeFunc(stackStrct_t **stack, char *arg, char *val, int line_number);
void push(stackStrct_t **stack, unsigned int line_number);
void pall(stackStrct_t **stack, unsigned int line_number);
void pint(stackStrct_t **stack, unsigned int line_number);
void pop(stackStrct_t **stack, unsigned int line_number);
void nop(stackStrct_t **stack, unsigned int line_number);
void swap(stackStrct_t **stack, unsigned int line_number);
void add(stackStrct_t **stack, unsigned int line_number);
void sub(stackStrct_t **stack, unsigned int line_number);
void pchar(stackStrct_t **stack, unsigned int line_number);
void divide(stackStrct_t **stack, unsigned int line_number);
void mul(stackStrct_t **stack, unsigned int line_number);
void mod(stackStrct_t **stack, unsigned int line_number);
void freeStack(stackStrct_t *stack);
void freeClosedFiles(stackStrct_t **stack);
void printErr1(void);
void printErr2(char *file);
void pushErr(FILE *fd, char *line, stackStrct_t *stack,
				int line_number);
void unknownErrHandler(FILE *fd, char *line, stackStrct_t *stack,
						char *val, int line_number);
int digitChk(char *c);
stackStrct_t *createNode(int n);
char *variable(int num);
char *variable1(int num);
char *variable2(int num);
#endif
