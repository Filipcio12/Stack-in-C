#include "Stack.h"
#include <stdio.h>

int main() {
    Stack stack;
    init(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Pop: %d\n", pop(&stack));
    printf("Pop: %d\n", pop(&stack));
    printf("Pop: %d\n", pop(&stack));

    destroy(&stack);

    return 0;
}
