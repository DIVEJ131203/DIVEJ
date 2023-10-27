
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert postfix expression to infix expression
void postfixToInfix(char postfix[]) {
    char stack[100][100];  // Assuming a maximum of 100 elements in the stack
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) {
            // If the character is an operand, push it onto the stack as a single-character string
            char operand[2];
            operand[0] = postfix[i];
            operand[1] = '\0';
            strcpy(stack[++top], operand);
        } else if (isOperator(postfix[i])) {
            // If the character is an operator, pop the top two elements from the stack
            char operand2[100];
            char operand1[100];
            strcpy(operand2, stack[top--]);
            strcpy(operand1, stack[top--]);

            // Create a fully parenthesized infix expression and push it onto the stack
            char infixExpression[100];
            sprintf(infixExpression, "(%s%c%s)", operand1, postfix[i], operand2);
            strcpy(stack[++top], infixExpression);
        }
    }

    if (top == 0) {
        printf("Fully Parenthesized Infix Expression: %s\n", stack[top]);
    } else {
        printf("Invalid postfix expression\n");
        exit(1);
    }
}

int main() {
    char postfix[100];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    postfixToInfix(postfix);

    return 0;
}
