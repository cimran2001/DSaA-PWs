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

void insertToStack(struct Stack *stack, int element, int index);
void deleteFromStack(struct Stack *stack, int index);


int main() {
    struct Stack stack = createStack();

    pushToStack(&stack, 67);
    pushToStack(&stack, 91);
    pushToStack(&stack, 101);
    pushToStack(&stack, 25);

    insertToStack(&stack, 69, 2);
    printStack(stack);

    deleteFromStack(&stack, 2);
    printStack(stack);

    clearStack(&stack);
}



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

void insertToStack(struct Stack *stack, int element, int index) {
    if (index < 0 || index > stack->count)
        return;

    if (index == stack->count) {
        pushToStack(stack, element);
        return;
    }

    stack->count++;
    for (int i = stack->count - 1; i > index; i--)
        stack->elems[i] = stack->elems[i - 1];
    stack->elems[index] = element;
}

void deleteFromStack(struct Stack *stack, int index) {
    if (index < 0 || index >= stack->count)
        return;

    stack->count--;
    for (int i = index; i < stack->count; i++)
        stack->elems[i] = stack->elems[i + 1];
}
