#include <iostream>
#include <stdlib.h>
#define MAXSTACKSIZE 7

struct Stack
{
    int data[MAXSTACKSIZE];
    int top;
};

// pre-declare `struct Stack*` type as st
typedef struct Stack st;

void printStackData(st *stack);
void pushManyData(st *stack, int data[], int size);
void popAllStackData(st *stack);

st *createEmptyStack()
{
    st *emptyStack = (st *)malloc(sizeof(struct Stack));
    emptyStack->top = -1;

    return emptyStack;
}

// create function which the stack is overflow??

void pushData(st *stack, int data)
{
    if (stack->top >= MAXSTACKSIZE - 1)
    {
        printf("ERROR: Stack Overflow!!\n");
        return;
    }

    // ! run and debug this
    int nextInd = stack->top + 1;
    stack->top = stack->top + 1;

    stack->data[nextInd] = data;

    printf("++ Pushed num - %d to %d stack!\n", data, stack->top);
}

void popData(st *stack)
{
    if (stack->top <= -1)
    {
        printf("ERROR: No data to pop!!\n");
        return;
    }

    printf("-- Popped %d from %d stack!\n", stack->data[stack->top], stack->top);

    stack->data[stack->top] = 0;
    stack->top--;
}

int main()
{
    st *myStack = createEmptyStack();

    pushData(myStack, 10);
    pushData(myStack, 20);
    pushData(myStack, 30);
    pushData(myStack, 40);
    pushData(myStack, 50);
    pushData(myStack, 60);
    pushData(myStack, 70);
    pushData(myStack, 80);
    pushData(myStack, 90);
    pushData(myStack, 100);

    printf("==============================\n");

    //     popData(myStack);
    //     popData(myStack);
    //     popData(myStack);
    //     popData(myStack);
    //     popData(myStack);
    //     popData(myStack);
    //     popData(myStack);
    //    popData(myStack);

    // pop all stack data
    popAllStackData(myStack);

    // push many data to stack
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof data / sizeof data[0];

    pushManyData(myStack, data, size);

    // print all stack data
    printStackData(myStack);

    return 0;
}

void printStackData(st *stack)
{
    if (stack->top <= -1)
    {
        printf("ERROR: No data to print!!\n");
        return;
    }

    for (int i = 0; i <= stack->top; i++)
    {

        printf("Data at %d - %d\n", stack->top - i, stack->data[stack->top - i]);
    }

    printf("==================================================\n");
}

void pushManyData(st *stack, int data[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (stack->top >= MAXSTACKSIZE)
        {
            return;
        }

        pushData(stack, data[i]);
    }
    printf("==================================================\n");
}

void popAllStackData(st *stack)
{
    while (stack->top > -1)
    {
        popData(stack);
    }

    printf("Popped all data from stack!  Stack's top is %d!\n", stack->top);
    printf("==================================================\n");
}