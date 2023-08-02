#include "Stack.h"

int main() 
{
    Stack stack;
    init(&stack);
    push(&stack, 5);
    push(&stack, 2);
    printf("Pop: %d\n", pop(&stack));
    printf("Pop: %d\n", pop(&stack));
    printf("Pop: %d\n", pop(&stack));
    destroy(&stack);
    return 0;
}