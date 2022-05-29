#include <stdio.h>
#include "stack.h"

int main() {
    struct Stack stack = createStack();
    struct Stack temp = createStack();

    pushToStack(&stack, 67);
    pushToStack(&stack, 91);
    pushToStack(&stack, 101);
    pushToStack(&stack, 25);

    while (!stackIsEmpty(stack)) {
        int elem = *topOfStack(stack);
        popFromStack(&stack);

        while (!stackIsEmpty(temp) && *topOfStack(temp) > elem) {
            int fromTemp = *topOfStack(temp);
            popFromStack(&temp);

            pushToStack(&stack, fromTemp);
        }

        pushToStack(&temp, elem);
    }

    printStack(temp);

    clearStack(&stack);
    clearStack(&temp);

    return 0;
}
