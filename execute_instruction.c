#include "header.h"

/**
* execute_instruction - Entry point of the program
* @line: Instruction to be executed (line read from the file)
* @stack: Pointer to the head of the stack
* @line_number: Line number of the instruction
*
* --------------- Description ---------------
* Execute the instruction passed as argument
*
* Return: Always 0 if sucess or EXIT_FAILURE
*/

int execute_instruction(char *line, my_stack_t **stack, int line_number)
{
	char *opcode = NULL; /* store the opcode */

	char *argument_value = NULL; /* store the argument */

	int argument_int = 0; /* store the argument converted to integer */

	/* get the opcode */
	opcode = strtok(line, " \n\t\r");
	argument_value = strtok(NULL, " \n\t\r");

	/* if the opcode is NULL */
	if (opcode == NULL || opcode[0] == '#')
	{
		/* if it's an empty line or a comment */
		return (EXIT_SUCCESS); /* skip the line */
	}

	if (strcmp(opcode, "push") == 0)
	{
		/* if the argument is NULL */
		if (argument_value == NULL)
		{
			/* print the error message in STDERR */
			dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
			return (EXIT_FAILURE); /* quit the program on failure */
		}

		argument_int = atoi(argument_value); /* convert the argument to integer */
		/* push the argument to the stack */
		push(stack, argument_int, line_number);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number); /* print all the values on the stack */
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
    /*
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, line_number);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap(stack, line_number);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add(stack, line_number);
	}
	else if (strcmp(opcode, "nop") == 0)
	{
		nop(stack, line_number);
	}
    */
	else
	{
		/* print the error message in STDERR */
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_number, opcode);
		return (EXIT_FAILURE); /* quit the program on failure */
	}
	return (EXIT_SUCCESS);
}
