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
	my_stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
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
	(void)stack;
	(void)line_number;
}
