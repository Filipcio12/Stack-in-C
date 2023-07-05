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
    s->data[top++] = element;
}
