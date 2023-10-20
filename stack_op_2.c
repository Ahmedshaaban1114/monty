#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Integer representing the line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}

/**
 * swap_node - Swap the top two elements of stack.
 * @stack: Pointer to a pointer to top node of stack.
 * @line_num: Integer representing the line number of of the opcode.
 */
void swap_node(stack_t **stack, unsigned int line_num)
{
	stack_t *i;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, line_num, "swap");
	i = (*stack)->next;
	(*stack)->next = i->next;
	if (i->next != NULL)
		i->next->prev = *stack;
	i-> = *stack;
	(*stack)->prev = i;
	i->prev = NULL;
	*stack = i;
}

/**
 * add_node - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Integer representing the line number of of the opcode.
 */
void add_node(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, line_num, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_node - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Integer representing the line number of of the opcode.
 */
void sub_node(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_error(8, line_num, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_node - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void div_nodes(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, line_num, "div");

	if ((*stack)->n == 0)
		more_error(9, line_num);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
