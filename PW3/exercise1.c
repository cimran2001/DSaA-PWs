#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"


int main() {
    struct Stack stack = createStack();

    const char *parentheses = "(()){}[()]";

    for (int i = 0; i < strlen(parentheses); i++) {
        switch (parentheses[i])
        {
        case '{': case '(': case '[':
            pushToStack(&stack, parentheses[i]);
            break;
        
        case '}': {
            int *top = topOfStack(stack);
            if (top == NULL || *top != '{')
                pushToStack(&stack, parentheses[i]);
            else 
                popFromStack(&stack);
        }
            break;
        case ')': {
            int *top = topOfStack(stack);
            if (top == NULL || *top != '(')
                pushToStack(&stack, parentheses[i]);
            else 
                popFromStack(&stack);
        }
            break;
        case ']': {
            int *top = topOfStack(stack);
            if (top == NULL || *top != '[')
                pushToStack(&stack, parentheses[i]);
            else 
                popFromStack(&stack);
        }
            break;
        default:
            break;
        }
    }

    printf("%sBalanced\n", stackIsEmpty(stack) ? "" : "Not ");
    clearStack(&stack);

    return 0;
}
