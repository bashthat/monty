#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdarg.h>
#include <errno.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>

#define OPCODES { \
	{"push", op_push},\
	{"pall", op_pall},\
	{"pint", op_pint},\
	{"pop", op_pop},\
	{"swap", op_swap},\
	{"add", op_add},\
	{"nop", op_nop},\
}

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
} stack_t;


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
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct cmd_s - command struct
 * @op: operation
 * @arg: argument of the function
 * @mode: the stack mode or queue mode
 * @line_number: the line in thought
 * @head: head of the linked list
 * @tail: tail of the linked list
 */

typedef struct cmd_s
{
	char *op;
	int arg;
	int *mode;
	unsigned int line_number;
	stack_t **head;
	stack_t **tail;
} relish;

/**
 * a lit of curated functions for the monty interpreter.
 * @ip: input = ip
 * @relish: relishing the command to parse.
 */

void eval(char *line, stack_t **x, stack_t **y, int *mode, unsigned int ln);
int parse(char *line, relish *ip);
void push(relish *ip);
void pall(relish *ip);
void pint(relish *ip);
void pop(relish *ip);
void swap(relish *ip);
void nop(relish *ip);
void addop(relish *ip);

#endif /*_MONTY_H_*/
