#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int capacity;
    int top;
    int *arr;
}Stack;

Stack* createStack(int capacity) {
    Stack* stack = malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->arr = malloc(capacity * sizeof(int));
    stack->top = -1;

    return stack;
}

int isFull(const Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(const Stack* stack) {
    return stack->top == -1;
}

void push(Stack** stack, int val) {
    if (isFull(*stack)) {
        return;
    }
    (*stack)->top++;
    int idx = (*stack)->top;
    (*stack)->arr[idx] = val;
}

int pop(Stack** stack) {
    if (isEmpty(*stack)) {
        printf("Stack is Empty :(\n");
        exit(1);
    }
    int item = (*stack)->arr[(*stack)->top];
    (*stack)->top--;
    return item;
}

void delete(Stack* stack) {
    free(stack->arr);
    free(stack);
}

void print(Stack* stack) {
    int stackSize = stack->top + 1;
    int *arr = malloc(sizeof(int) * stackSize);
    int i = 0;
    while (!isEmpty(stack)) {
        arr[i++] = pop(&stack);
    }

    for (int j = stackSize - 1; j >= 0; j--) {
        printf("%d ", arr[j]);
        push(&stack, arr[j]);
    }
    printf("\n");

    free(arr);
}


int main() {
    Stack *stack = createStack(5);
    push(&stack, 1);
    push(&stack, 2);
    /* printf("%d \n", pop(&stack)); */
    /* printf("%d \n", pop(&stack)); */
    delete(stack);

    return 0;
}
