#include "monty.h"

/**
 * update_mode - update the mode of linked list (stack or queue)
 * @opcode: string the read from file
 * Return: 0 in case stack mode, 1 in case queue mode
*/
void update_mode(char *opcode)
{
	if (!strcmp(opcode, "stack"))
	{
		execution_env.mode = STACK_MODE;
	}
	else if (!strcmp(opcode, "queue"))
	{
		execution_env.mode = QUEUE_MODE;
	}
}
