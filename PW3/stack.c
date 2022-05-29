#include "stack.h"


struct Stack createStack() {
    struct Stack stack;

    stack.count = 0;
    stack.size = 0;
    stack.elems = NULL;

    return stack;
}

void pushToStack(struct Stack *stack, int element) {
    if (stack->size == 0) {
        stack->elems = (int*)malloc(sizeof(int) * 1);
        stack->size++;
    }

    if (stack->size == stack->count) {
        int *temp = (int *)malloc(sizeof(int) * stack->size * 2);

        for (int i = 0; i < stack->size; i++)
            temp[i] = stack->elems[i];
        
        stack->size *= 2;
        free(stack->elems);
        stack->elems = temp;
    }

    stack->elems[stack->count++] = element;
}

void popFromStack(struct Stack *stack) {
    if (stack->count == 0)
        return;
    
    stack->count--;
}

int *topOfStack(struct Stack stack) {
    if (stack.elems == NULL)
        return NULL;
    
    return stack.elems + stack.count - 1;
}

void clearStack(struct Stack *stack) {
    if (stack->elems == NULL)
        return;

    free(stack->elems);
    stack->count = 0;
    stack->size = 0;
}

void printStack(struct Stack stack) {
    for (int i = 0; i < stack.count; i++)
        printf("%d ", stack.elems[i]);
    printf("\n");
}

bool stackIsEmpty(struct Stack stack) {
    return stack.count == 0;
}
