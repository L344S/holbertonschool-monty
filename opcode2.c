#include "monty.h"

/**
* add - Entry point of the program
* @stack: Pointer to the head of the stack
* @line_number: Line number of the instruction
* --------------- Description ---------------
* Add the top two elements of the stack
* Return: Always 0 if success or EXIT_FAILURE
*/
void add(my_stack_t **stack, unsigned int line_number)
{
	/* Create a temporary pointer */
	my_stack_t *temp;
	/* Check if the stack is empty or has only one element */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* add the value to the second element of the top of the stack */
	(*stack)->next->n += (*stack)->n;
	/* store the address of the top of the stack in the temporary pointer */
	temp = *stack;
	/* update the stack pointer to the next node */
	*stack = (*stack)->next;
	/* free the memory allocated to the top of the stack */
	free(temp);
}

/**
* nop - Entry point of the program
* @stack: Pointer to the head of the stack
* @line_number: Line number of the instruction
* --------------- Description ---------------
* Doesn't do anything
* Return: Nothing
*/
void nop(my_stack_t **stack, unsigned int line_number)
{
	/* unused parameters */
	(void)stack;
	(void)line_number;
	/* do nothing */
}
