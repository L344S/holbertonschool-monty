#include "header.h"

/**
* main - Entry point of the program
* @argc: Argument count (number of arguments)
* @argv: Argument vector (array of strings passed as arguments)
*
* --------------- Description ---------------
* If the user does not give any file or more than one argument
* to your program print the error message
*
* Return: Always 0 if sucess or EXIT_FAILURE
*/

int main(int argc, char **argv)
{
	(void)argv; /* gestion temporaire d'erreur de compilation */
	/* Error : If there are more than 2 arguments */
	if (argc != 2)
	{
		/* Print the error message in STDERR */
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE); /* quit the program on failure */
	}

	return (0); /* return 0 if sucess so the program can continue */
}
