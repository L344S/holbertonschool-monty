#include "monty.h"

/**
* execute - Entry point of the program
* @file: Argv[1] (file to be read passed as argument)
* --------------- Description ---------------
* Handle the argument <filename> passed to the program
* Read the file and execute the instructions inside it
* Return: Always 0 if sucess or EXIT_FAILURE
*/
void execute(char *file)
{
	FILE *file_that_will_be_read; /* pointer to the file that will be read */
	char *line = NULL; /* store the line read from the file */

	size_t BUFSIZE = 0; /* size of the buffer */
	ssize_t char_read; /* store the number of characters read return by getline */
	int line_number = 1; /* store the line number to keep track of process */

	int exectution_status = 0; /* store the status of the execution */

	my_stack_t *stack = NULL; /* pointer to the head of the stack */

	file_that_will_be_read = fopen(file, "r"); /* open the file in read mode */
	if (file_that_will_be_read == NULL) /* Error : If the file can't be open */
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE); /* quit the program on failure */
	}
	while ((char_read = getline(&line, &BUFSIZE, file_that_will_be_read)) != -1)
	{
		if (line[0] != '\n' && line[0] != '#')
		{
			exectution_status = parseLine(line, &stack, line_number);
			/* if the execution fail */
			if (exectution_status == EXIT_FAILURE)
			{
				/* free the memory allocated for the line */
				free(line);
				/* free the memory allocated for the stack */
				frees(&stack);
				/* close the file */
				fclose(file_that_will_be_read);
				/* quit the program on failure */
				exit(EXIT_FAILURE);
			}
		}
		line_number++; /* increment the line number */
	}
	free(line);
	frees(&stack);
	fclose(file_that_will_be_read);
}

/**
 * parseLine - Entry point of the program
 * @line: Instruction to be executed (line read from the file)
 * @stack: Pointer to the head of the stack
 * @line_number: Line number of the instruction
 * --------------- Description ---------------
 * Execute the instruction passed as argument
 * Return: Always 0 if sucess or EXIT_FAILURE
 */
int parseLine(char *line, my_stack_t **stack, int line_number)
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
