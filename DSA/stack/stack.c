#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int size;
    int top;
    int* arr;
} Stack;

Stack* createStack(int size)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->size = size;
    stack->arr = (int*)calloc(size, sizeof(int));
    stack->top = -1;

    return stack;
}

int pop(Stack* stack)
{
    if (stack->top == -1) {
        printf("Underflow\n");
        return -1;
    } else {
        return stack->arr[stack->top--];
    }
}

void push(Stack* stack, int n)
{
    if (stack->top >= stack->size) {
        printf("Overflow\n");
    } else {
        stack->arr[++stack->top] = n;
    }
}

void display(Stack* stack)
{
    printf("Stack: ");
    if (stack->top == -1) {
        printf("Empty\n");
    } else {
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->arr[i]);
        }
    }
    printf("\n");
}

void freeStack(Stack** stack)
{
    free((*stack)->arr);
    free(*stack);
    *stack = NULL;
}

int main(void)
{
    Stack* stack = createStack(10);
    display(stack);
    push(stack, 5);
    display(stack);
    push(stack, 7);
    display(stack);
    push(stack, 9);
    display(stack);
    pop(stack);
    display(stack);
    freeStack(&stack);
    return 0;
}
