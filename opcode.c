#include "monty.h"

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
	/* Create a new node */
	my_stack_t *new_node = NULL;

	(void)line_number; /* unused variable */

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(my_stack_t));
	if (new_node == NULL) /* if malloc fails */
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/* Initialize the new node with the argument passed to the function */
	new_node->n = argument;
	/* Initialize the new node with the next node in the stack */
	new_node->prev = NULL;
	/* Initialize the new node with the next node in the stack */
	new_node->next = *stack;
	/* If the stack is not empty, initialize the previous node with the new node*/
	if (*stack != NULL)
		(*stack)->prev = new_node;
	/* Update the stack pointer to the new node */
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
	/* arguments unused */
	(void)line_number;
	/* Create a pointer to the current node in the stack (top/head) */
	my_stack_t *current_node = *stack;
	/* Loop through the stack until there are no more nodes */
	while (current_node != NULL)
	{
		printf("%d\n", current_node->n); /* Print the value of the member n */
		current_node = current_node->next; /* Move the stack pointer to next node */
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
	/*  check if the stack is empty */
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* print the value at the top of the stack */
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
	/* Create a temporary pointer to the top of the stack */
	my_stack_t *temp;
	/* check if the stack is empty */
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* store the address of the top of the stack in the temporary pointer */
	temp = *stack;
	/* update the stack pointer to the next node */
	*stack = (*stack)->next;
	/* free the memory allocated to the top of the stack */
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
	/* Create a temporary variable to store the value */
	int temp;
	/* check if the stack is empty or has only one element */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* store the value of the top of the stack in the temporary variable */
	temp = (*stack)->n;
	/* swap the value of the top of the stack with the next node */
	(*stack)->n = (*stack)->next->n;
	/* swap the value of the next node with the temporary variable */
	(*stack)->next->n = temp;
}

