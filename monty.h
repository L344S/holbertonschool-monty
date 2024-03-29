#ifndef MONTY_H
#define MONTY_H

/* ---------- Libraries ---------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>


/* ---------- Structures ---------- */

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
		int n;

		struct stack_s *prev;
		struct stack_s *next;
} my_stack_t;

/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
		char *opcode;

		void (*f)(my_stack_t **stack, unsigned int line_number);

} instruction_t;


/* ---------- Prototypes ---------- */

/* execute.c */
void execute(char *file);
int parseLine(char *line, my_stack_t **stack, int line_number);
int handle(char *opcode, char *arg_value, my_stack_t **stack, int line_number);
/* opcode.c */
void push(my_stack_t **stack, int argument, unsigned int line_number);
void pall(my_stack_t **stack, unsigned int line_number);
void pint(my_stack_t **stack, unsigned int line_number);
void pop(my_stack_t **stack, unsigned int line_number);
void swap(my_stack_t **stack, unsigned int line_number);
/* opcode2.c */
void add(my_stack_t **stack, unsigned int line_number);
void nop(my_stack_t **stack, unsigned int line_number);
/* frees.c */
void frees(my_stack_t **stack);

#endif
