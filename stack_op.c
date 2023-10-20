#include "main.h"

/**
 * add_stack - adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */


void add_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *p;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	p = head;
	head = *new_node;
	head->next = p;
	p->prev = head;
}

/**
 * print_stack - adds anode to stack.
 * @stack: Pointer to a pointer to top node.
 * @line_num: line number of opcode.
 */
void print_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *i;
	(void) line_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	i = *stack;
	while (i != NULL)
	{
		printf("%d\n", i->n);
		i = i->next
	}
}

/**
 * pop_t - add a node to stack.
 * @stack: pointer to a pointer to the top of node.
 * line_num: Integer representing the line number of opcode.
 *
 */
void pop_t(stack_t **stack, unsigned int line num)
{
	stack_t *i;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_num);
	i = *stack;
	*stack = i->next
		if (*stack != NULL)
			(*stack)->prev = NULL;
	free(i);
}

/**
 * print_t - Print the top node of stack.
 * @stack: pointer to a pointer to the top of node.
 * line_num: Integer representing the line number of opcod
 */
void print_t(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		 more_err(6, line_num);
	printf("%d\n", (*stack)->n);
}
