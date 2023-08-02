#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10
#define GROWTH_FACTOR 2

void init(Stack* s) {
    s->data = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    if (s->data == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    s->capacity = INITIAL_CAPACITY;
    s->size = 0;
}

void destroy(Stack* s) {
    free(s->data);
    s->data = NULL;
    s->capacity = 0;
    s->size = 0;
}

void push(Stack* s, int element) {
    if (s->size == s->capacity) {
        int newCapacity = s->capacity * GROWTH_FACTOR;
        int* newData = (int*)realloc(s->data, newCapacity * sizeof(int));
        if (newData == NULL) {
            printf("Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }
        s->data = newData;
        s->capacity = newCapacity;
    }
    s->data[s->size] = element;
    s->size++;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Error: Stack is empty\n");
        abort();
    }
    int element = s->data[s->size - 1];
    s->size--;
    return element;
}

bool isEmpty(Stack* s) {
    return s->size == 0;
}
