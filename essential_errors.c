#include "monty.h"

/**
 * usage_error - prints to stderr usage error msg
*/
void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	free_all_and_exit();
}

/**
 * open_error - prints to stderr open error msg
 * @file_name: the opcode file name
*/
void open_error(char *file_name)
{
	fprintf(stderr, "Error: Can't open file %s\n", file_name);
	free_all_and_exit();
}

/**
 * malloc_error - prints to stderr malloc error msg
*/
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_all_and_exit();
}
