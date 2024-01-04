#include "monty.h"

/**
 * execute_instruction - Entry point of the program
 * @line: Instruction to be executed (line read from the file)
 * @stack: Pointer to the head of the stack
 * @line_number: Line number of the instruction
 * --------------- Description ---------------
 * Execute the instruction passed as argument
 * Return: Always 0 if sucess or EXIT_FAILURE
 */
int execute_instruction(char *line, my_stack_t **stack, int line_number)
{
	char *opcode = NULL; /* store the opcode */
	char *arg_value = NULL; /* store the argument */

	/* get the opcode and argument */
	opcode = strtok(line, " \n\t\r");
	arg_value = strtok(NULL, " \n\t\r");

	/* if the opcode is NULL or a comment, skip the line */
	if (opcode == NULL || opcode[0] == '#')
		return (EXIT_SUCCESS);

	/* handle opcode-specific logic */
	return (handle(opcode, arg_value, stack, line_number));
}

/**
 * handle - Entry point of the program
 * @opcode: Opcode to be executed
 * @arg_value: Argument passed to the function
 * @stack: Pointer to the head of the stack
 * @line_number: Line number of the instruction
 * --------------- Description ---------------
 * Handle the opcode passed as argument
 * Return: Always 0 if sucess or EXIT_FAILURE
 */
int handle(char *opcode, char *arg_value, my_stack_t **stack, int line_number)
{
	int argument_int = 0; /* store the argument converted to integer */

	if (strcmp(opcode, "push") == 0)
	{
		if (arg_value == NULL) /* if the argument is NULL */
		{
			dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
			return (EXIT_FAILURE); /* quit the program on failure */
		}
		for (size_t i = 0; i < strlen(arg_value); i++)
		{
			if (arg_value[i] == '-') /* handle the negative number */
				i++;
			if (!isdigit(arg_value[i]))
			{
				dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE); /* quit the program on failure */
			}
		}
		argument_int = atoi(arg_value); /* convert the argument to integer */
		push(stack, argument_int, line_number); /* push the argument to the stack */
	}
	else if (strcmp(opcode, "pall") == 0)
		pall(stack, line_number); /* print all the values on the stack */
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_number);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
		nop(stack, line_number);
	else
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_number, opcode);
		return (EXIT_FAILURE); /* quit the program on failure */
	}
	return (EXIT_SUCCESS);
}
