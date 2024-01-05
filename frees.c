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
	/* Create a pointer to the current node in the stack */
	my_stack_t *current_node = *stack;

	/* Loop through the stack until there are no more nodes */
	while (current_node != NULL)
	{
		/* Move the stack pointer to the next node */
		*stack = (*stack)->next;
		/* Free the memory allocated to the current node */
		free(current_node);
		/* Update the current node pointer to the new top of the stack */
		current_node = *stack;
	}
}
