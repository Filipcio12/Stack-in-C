#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    size_t top;
    size_t size;
    int* data;
} Stack;

void init(Stack* s);
void destroy(Stack* s);
void push(Stack* s, int element);
int pop(Stack* s);
bool isEmpty(Stack* s);

int main()
{
    printf("Hello World");

    return 0;
}

void init(Stack* s)
{
    s->top = 0;
    s->size = 0;
    s->data = 0;
}
