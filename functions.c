#include "header.h"

/**
* push - Entry point of the program
* @stack: Pointer to the head of the stack
* @argument: Argument passed to the function
* @line_number: Line number of the instruction
* --------------- Description ---------------
* Push an element to the stack
* Return: Always 0 if sucess or EXIT_FAILURE
*/
void push(my_stack_t **stack, int argument, unsigned int line_number)
{
	my_stack_t *new_node = NULL;

	(void)line_number;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = argument;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
* pall - Entry point of the program
* @stack: Pointer to the head of the stack
* @line_number: Line number of the instruction
* --------------- Description ---------------
* Print all the values on the stack
* Return: Always 0 if sucess or EXIT_FAILURE
*/
void pall(my_stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	my_stack_t *current_node = *stack;

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}

/**
* pint - Entry point of the program
* @stack: Pointer to the head of the stack
* @line_number: Line number of the instruction
* --------------- Description ---------------
* Print the value at the top of the stack
* Return: Always 0 if success or EXIT_FAILURE
*/
void pint(my_stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
* pop - Entry point of the program
* @stack: Pointer to the head of the stack
* @line_number: Line number of the instruction
* --------------- Description ---------------
* Remove the top element of the stack
* Return: Always 0 if success or EXIT_FAILURE
*/
void pop(my_stack_t **stack, unsigned int line_number)
{
	my_stack_t *temp;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
* swap - Entry point of the program
* @stack: Pointer to the head of the stack
* @line_number: Line number of the instruction
* --------------- Description ---------------
* Swap the top two elements of the stack
* Return: Always 0 if success or EXIT_FAILURE
*/
void swap(my_stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

