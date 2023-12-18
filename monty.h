#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void f_open(char *file_name);
int f_ligne(char *buffer, int line_number, int format);
void f_read(FILE *);
void find_function(char *, char *, int, int);
void call_f(op_func, char *, char *, int, int);

stack_t *create_node(int n);
void free_nodes(void);
void f_push(stack_t **, unsigned int);
void f_pall(stack_t **, unsigned int);
void f_pint(stack_t **, unsigned int);
void f_pop(stack_t **, unsigned int);
void f_swap(stack_t **, unsigned int);
void f_add(stack_t **, unsigned int);
void f_nop(stack_t **, unsigned int);

#endif
