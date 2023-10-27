#include <stdio.h>
#include <stdlib.h>

// Define a structure for the stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// Function to create a new stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

// Function to convert a decimal number to any base
void decimalToBase(int decimalNumber, int base) {
    struct Stack* stack = createStack(1000);

    while (decimalNumber > 0) {
        int remainder = decimalNumber % base;
        push(stack, remainder);
        decimalNumber /= base;
    }

    printf("Equivalent number in base %d: ", base);

    while (!isEmpty(stack)) {
        printf("%d", pop(stack));
    }

    printf("\n");
}

int main() {
    int decimalNumber, base;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    printf("Enter the base to convert to: ");
    scanf("%d", &base);

    if (base < 2 || base > 16) {
        printf("Base should be between 2 and 16.\n");
        return 1;
    }

    decimalToBase(decimalNumber, base);

    return 0;
}
