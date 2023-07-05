#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

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
    Stack stack;
    init(&stack);
    push(&stack, 5);
    push(&stack, 2);
    printf("%d", pop(&stack));
    printf("%d", pop(&stack));
    printf("%d", pop(&stack));
    destroy(&stack);
    return 0;
}

void init(Stack* s)
{
    s->top = 0;
    s->size = 0;
    s->data = 0;
}

void destroy(Stack* s) 
{
    free(s->data);
}

void push(Stack* s, int element)
{
    if (s->top >= s->size) {
        size_t newSize = (s->size + 1) * 2;
        int* newData = realloc(s->data, newSize * sizeof(int));
        if (newData) {
            s->data = newData;
        }
        else {
            free(s->data);
            abort();
        }
        s->size = newSize;
    }
    s->data[s->top++] = element;
}

int pop(Stack* s) 
{
    assert(s->top > 0);
    return s->data[--s->top];
}

bool isEmpty(Stack* s)
{
    if (s->top <= 0) {
        return 1;
    }
    return 0;
}
