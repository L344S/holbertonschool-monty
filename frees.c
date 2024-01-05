#include "monty.h"

/**
* frees - Entry point of the program
* @stack: Pointer to the head of the stack
* --------------- Description ---------------
* Free the memory allocated for the stack
* Return: Always 0 if sucess or EXIT_FAILURE
*/
void frees(my_stack_t **stack)
{
	my_stack_t *current_node = *stack;

	while (current_node != NULL)
	{
		*stack = (*stack)->next;
		free(current_node);
		current_node = *stack;
	}
}
