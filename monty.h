#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

extern char *opGlobal[];

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number, char *opcode, FILE *fd);
} instruction_t;

void free_list(stack_t *head);
void find_op(FILE *fd);
void opcode_exe(stack_t **stack, unsigned int line, char *opcode, FILE *fd);
int main(int argc, char *argv[]);
void OPpush(stack_t **stack, unsigned int line_num, char *opcode, FILE *fd);
stack_t *add_node(stack_t **head, const int n, char *opcode, FILE *fd);
void errorEXIT(stack_t **stack, unsigned int line_num, char *opcode, FILE *fd);
size_t pallHelper(const stack_t *h);
void OPpall(stack_t **stack, unsigned int line_num, char *opcode, FILE *fd);
void OPpint(stack_t **stack, unsigned int line_num, char *opcode, FILE *fd);
void OPswap(stack_t **stack, unsigned int line_num, char *opcode, FILE *fd);
void OPpop(stack_t **stack, unsigned int line_num, char *opcode, FILE *fd);
void OPnop(stack_t **stack, unsigned int line_num, char *opcode, FILE *fd);
void OPadd(stack_t **stack, unsigned int line_num, char *opcode, FILE *fd);

#endif
