#include "monty.h"

/**
 * f_open - opens a file
 * @f_name: the file name
 */

void f_open(char *f_name)
{
	FILE *f = fopen(f_name, "r");

	if (f_name == NULL || f == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", f_name);

	f_read(f);
	fclose(f);
}


/**
 * f_read - reads a file
 * @f: pointer to file descriptor
 */

void f_read(FILE *f)
{
	int n, type = 0;
	char *ligne = NULL;
	size_t size = 0;

	for (n = 1; getline(&ligne, &size, f) != -1; n++)
	{
		type = f_ligne(ligne, n, type);
	}
	free(ligne);
}


/**
 * f_ligne - Separates each line into tokens to determine
 * which function to call
 * @ligne: line from the file
 * @n: line number
 * @type: format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the op_code is stack. 1 if queue.
 */

int f_ligne(char *ligne, int n, int type)
{
	char *op_code, *str;

	if (ligne == NULL)
		fprintf(stderr, "Error: malloc failed\n");

	op_code = strtok(ligne, "\n ");
	if (op_code == NULL)
		return (type);
	str = strtok(NULL, "\n ");

	if (strcmp(op_code, "stack") == 0)
		return (0);
	if (strcmp(op_code, "queue") == 0)
		return (1);

	find_function(op_code, str, n, type);
	return (type);
}

/**
 * call_f - Calls the required function.
 * @f: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @str: string representing a numeric value.
 * @n: line numeber for the instruction.
 * @type: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_f(op_func f, char *op, char *str, int n, int type)
{
	stack_t *node;
	int flag = 1;
	int i;

	if (strcmp(op, "push") == 0)
	{
		if (str != NULL && str[0] == '-')
		{
			str = str + 1;
			flag = -1;
		}
		if (str == NULL)
			fprintf(stderr, "L%d: usage: push integer\n", n);
		for (i = 0; str[i] != '\0'; i++)
		{
			if (isdigit(str[i]) == 0)
				fprintf(stderr, "L%d: usage: push integer\n", n);
		}
		node = create_node(atoi(str) * flag);
		if (type == 0)
			f(&node, n);
		if (type == 1)
			f_push(&node, n);
	}
	else
		f(&head, n);
}

/**
 * find_function - find the appropriate function for the op_code
 * @op_code: op_code
 * @str: argument of op_code
 * @type:  storage format. If 0 Nodes will be entered as a stack.
 * @n: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_function(char *op_code, char *str, int n, int type)
{
	int i;
	int flag;

	instruction_t list[] = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{NULL, NULL}
	};

	if (op_code[0] == '#')
		return;

	for (flag = 1, i = 0; list[i].opcode != NULL; i++)
	{
		if (strcmp(op_code, list[i].opcode) == 0)
		{
			call_f(list[i].f, op_code, str, n, type);
			flag = 0;
		}
	}
	if (flag == 1)
		fprintf(stderr, "L%d: unknown instruction %s\n", n, op_code);
}

