#include "monty.h"

execution_env_t execution_env = EXECUTION_ENV_INITIALIZER;

/**
 * main - Entry point for Monty Interpreter
 * @argc: number of arguments
 * @argv: array of character pointers to arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
*/
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		usage_error();
	}

	return (execute_operations(argv[1]));
}
