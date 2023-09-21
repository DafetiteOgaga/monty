#include "monty_header.h"


/**
 * main - entry pointn
 * @argc: argument countern
 * @argv: argument vectorn
 * Return: success || failuren
 */
int main(int argc, char **argv)
{

		if (argc != 2)
		{
			printErr1();
		}
		else
		{
			executeMontyFunc(argv[1]);
		}

		return (EXIT_SUCCESS);

}
