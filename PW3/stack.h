#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack {
    int *elems;
    int size;

    int count;
};

struct Stack createStack();
void pushToStack(struct Stack *stack, int element);
void popFromStack(struct Stack *stack);
int *topOfStack(struct Stack stack);
void clearStack(struct Stack *stack);
void printStack(struct Stack stack);
bool stackIsEmpty(struct Stack stack);

#endif
