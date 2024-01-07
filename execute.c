#include "monty.h"

/**
* execute - Entry point of the program
* @file: Argv[1] (filename to be read passed as argument)
* --------------- Description ---------------
* Handle the argument <filename> passed to the program
* Open the file and read the lines
* Return: Always 0 if sucess or EXIT_FAILURE
*/
void execute(char *file)
{
	FILE *file_that_will_be_read; /* pointer to the file that will be read */
	char *line = NULL; /* store the each line read from the file */

	size_t BUFSIZE = 0; /* store the size of the buffer allocated by getline */
	ssize_t char_read; /* store the number of characters read return by getline */
	int line_number = 1; /* store the line number to keep track of process */

	int exectution_status = 0; /* store the status of the execution */

	my_stack_t *stack = NULL; /* pointer to NULL is the head of the stack */

	file_that_will_be_read = fopen(file, "r"); /* open the file in read mode */
	if (file_that_will_be_read == NULL) /* Error : If the file can't be open */
	{ /* print the error message */
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE); /* quit the program on failure */
	}
	/* loop through the file until there are no more lines (EOF) */
	while ((char_read = getline(&line, &BUFSIZE, file_that_will_be_read)) != -1)
	{
		/* if the line is not empty and not a comment we can parse it */
		if (line[0] != '\n' && line[0] != '#')
		{
			/* call the parseLine function and store the what it return */
			exectution_status = parseLine(line, &stack, line_number);
			/* if the parseLine function not return 0 means it failed */
			if (exectution_status != 0)
			{
				free(line); /* free the memory allocated for the line */
				frees(&stack); /* free all the memory allocated for the stack */
				fclose(file_that_will_be_read); /* close the file */
				exit(EXIT_FAILURE); /* quit the program on failure */
			}
		}
		line_number++; /* increment the line number to keep track of process */
	}
	free(line); /* free the memory allocated for the line */
	frees(&stack); /* free all the memory allocated for the stack */
	fclose(file_that_will_be_read); /* close the file */
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
	char *opcode = NULL; /* store the opcode (ex: push, pall, pint) */
	char *arg_value = NULL; /* store the argument (ex: 1, 2, 3) */

	/* get the opcode and argument */
	opcode = strtok(line, " \n\t\r"); /* divide the line with the delimiter */
	/* NULL is passed to strtok to continue from the last position */
	arg_value = strtok(NULL, " \n\t\r"); /* divide the line with the delimiter */

	/* if the opcode is NULL or a comment we exit sucessfully to skip the line */
	if (opcode == NULL || opcode[0] == '#')
		return (EXIT_SUCCESS);

	/* call the handle function and store the what it return */
	return (handle(opcode, arg_value, stack, line_number));
	/* we return the value of handle function to the execute function */
	/* if not 0 means it failed */
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
	/* Series of if statements to check the opcode passed as argument */
	if (strcmp(opcode, "push") == 0) /* if the opcode is push */
	{
		if (arg_value == NULL) /* check if there is an argument if not error */
		{
			dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
			return (EXIT_FAILURE); /* quit the program on failure */
		}
		for (size_t i = 0; i < strlen(arg_value); i++) /* check if all is a number */
		{
			if (arg_value[i] == '-') /* if [i] = '-' we skip it */
				i++;
			if (!isdigit(arg_value[i])) /* if [i] is not a digit we send an error */
			{
				dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE); /* quit the program on failure */
			}
		} /* all the characters are digits, we can convert the argument to integer */
		argument_int = atoi(arg_value); /* use atoi to convert to integer */
		push(stack, argument_int, line_number); /* call the push function */
	}
	else if (strcmp(opcode, "pall") == 0) /* if the opcode is pall */
		pall(stack, line_number); /* print all the values on the stack */
	else if (strcmp(opcode, "pint") == 0) /* if the opcode is pint */
		pint(stack, line_number); /* print the value at the top of the stack */
	else if (strcmp(opcode, "pop") == 0) /* if the opcode is pop */
		pop(stack, line_number); /* remove the top element of the stack */
	else if (strcmp(opcode, "swap") == 0) /* if the opcode is swap */
		swap(stack, line_number); /* swap the top two elements of the stack */
	else if (strcmp(opcode, "add") == 0) /* if the opcode is add */
		add(stack, line_number); /* add the top two elements of the stack */
	else if (strcmp(opcode, "nop") == 0) /* if the opcode is nop */
		nop(stack, line_number); /* do nothing */
	else /* if the opcode is not valid */
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_number, opcode);
		return (EXIT_FAILURE); /* quit the program on failure */
	}
	return (EXIT_SUCCESS); /* return 0 so the program can continue */
}
