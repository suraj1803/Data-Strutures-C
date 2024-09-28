#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int capacity;
    int top;
    int *arr;
}Stack;

/* creates a stack and initialize its capacity and all other members like top index, array etc*/
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

int top(Stack* stack) {
    return stack->arr[stack->top];
}

/* deletes all the resources used by Stack like dynamically alllocate array and the stack itself */
void delete(Stack* stack) {
    free(stack->arr);
    free(stack);
}


/* creates a stack from array */
Stack* createStackFromArray(int *arr, int size) {
    Stack* stack = createStack(2*size);
    for (int i = 0; i < size; i++) {
        push(&stack, arr[i]);
    }

    return stack;
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
    int n;
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);
    Stack* stack = createStackFromArray(arr, n);
    print(stack);
    pop(&stack);
    pop(&stack);
    print(stack);
    printf("%d\n", top(stack));
    pop(&stack);
    print(stack);

    delete(stack);
    free(arr);

    return 0;
}
