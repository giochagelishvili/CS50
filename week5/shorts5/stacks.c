#include <stdio.h>
#include <stdlib.h>

// Array capacity
const int CAPACITY = 10;

// Define stack
typedef struct _stack
{
    int array[CAPACITY];
    int top;
}
stack;

// Function declaration
void push(stack *s, int data);
int pop(stack *s);

int main(void)
{
    // Declare stack
    stack s;
    // Set top of the stack to 0
    s.top = 0;

    // Push 10 ints into the stack
    for (int i = 0; i < 10; i++)
    {
        push(&s, i + 1);
        printf("%i ", s.array[i]);
    }
    printf("\n");

    for (int j = 0; j < 10; j++)
    {
        pop(&s);
    }

    for (int k = 0; k < 10; k++)
    {
        push(&s, k + 10);
        printf("%i ", s.array[k]);
    }
}

// Push an element in the stack
void push(stack *s, int data)
{
    s->array[s->top] = data;
    s->top++;
}

int pop(stack *s)
{
    int x = s->array[s->top - 1];
    s->top--;

    return x;
}