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
			exectution_status = execute_instruction(line, &stack, line_number);
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
