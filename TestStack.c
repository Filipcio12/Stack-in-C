#include "Stack.h"

int main() 
{
    Stack stack;
    init(&stack);
    push(&stack, 5);
    push(&stack, 2);
    printf("%d", pop(&stack));
    printf("%d", pop(&stack));
    destroy(&stack);
    return 0;
}