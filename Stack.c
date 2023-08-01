#include "Stack.h"

void init(Stack* s)
{
    s->top = 0;
    s->size = 0;
    s->data = NULL;
}

void destroy(Stack* s) 
{
    free(s->data);
}

void push(Stack* s, int element)
{
    if (s->top >= s->size) {
        size_t newSize = (s->size + 1) * 2;
        int* newData = (int*)realloc(s->data, newSize * sizeof(int));
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
    //assert(s->top > 0);
    if (!(s->top > 0)) {
        free(s->data);
        fprintf(stderr, "Can't pop from an empty stack.");
        abort();
    }
    return s->data[--s->top];
}

bool isEmpty(Stack* s)
{
    if (s->top <= 0) {
        return 1;
    }
    return 0;
}