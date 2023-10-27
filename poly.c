#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(struct Node** head, int coefficient, int exponent) {
    struct Node* newNode = createNode(coefficient, exponent);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* temp1 = poly1;
    struct Node* temp2 = poly2;

    do {
        if (temp1->exponent > temp2->exponent) {
            insertNode(&result, temp1->coefficient, temp1->exponent);
            temp1 = temp1->next;
        } else if (temp1->exponent < temp2->exponent) {
            insertNode(&result, temp2->coefficient, temp2->exponent);
            temp2 = temp2->next;
        } else {
            int coefficient = temp1->coefficient + temp2->coefficient;
            int exponent = temp1->exponent;
            insertNode(&result, coefficient, exponent);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    } while (temp1 != poly1 && temp2 != poly2);

    while (temp1 != poly1) {
        insertNode(&result, temp1->coefficient, temp1->exponent);
        temp1 = temp1->next;
    }

    while (temp2 != poly2) {
        insertNode(&result, temp2->coefficient, temp2->exponent);
        temp2 = temp2->next;
    }

    return result;
}

// Function to subtract two polynomials
struct Node* subtractPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* temp1 = poly1;
    struct Node* temp2 = poly2;

    do {
        if (temp1->exponent > temp2->exponent) {
            insertNode(&result, temp1->coefficient, temp1->exponent);
            temp1 = temp1->next;
        } else if (temp1->exponent < temp2->exponent) {
            insertNode(&result, -temp2->coefficient, temp2->exponent);
            temp2 = temp2->next;
        } else {
            int coefficient = temp1->coefficient - temp2->coefficient;
            int exponent = temp1->exponent;
            insertNode(&result, coefficient, exponent);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    } while (temp1 != poly1 && temp2 != poly2);

    while (temp1 != poly1) {
        insertNode(&result, temp1->coefficient, temp1->exponent);
        temp1 = temp1->next;
    }

    while (temp2 != poly2) {
        insertNode(&result, -temp2->coefficient, temp2->exponent);
        temp2 = temp2->next;
    }

    return result;
}

// Function to multiply two polynomials
struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* temp1 = poly1;
    struct Node* temp2 = poly2;

    do {
        struct Node* temp = temp2;
        do {
            int coefficient = temp1->coefficient * temp->coefficient;
            int exponent = temp1->exponent + temp->exponent;
            insertNode(&result, coefficient, exponent);
            temp = temp->next;
        } while (temp != poly2);
        temp1 = temp1->next;
    } while (temp1 != poly1);

    return result;
}

// Function to display a polynomial
void displayPolynomial(struct Node* poly) {
    struct Node* temp = poly;
    if (temp == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    do {
        printf("%dx^%d ", temp->coefficient, temp->exponent);
        temp = temp->next;
    } while (temp != poly);
    printf("\n");
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;
    int choice, coefficient, exponent;

    do {
        printf("1. Enter polynomial 1\n");
        printf("2. Enter polynomial 2\n");
        printf("3. Add polynomials\n");
        printf("4. Subtract polynomials\n");
        printf("5. Multiply polynomials\n");
        printf("6. Display result\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter coefficient and exponent for polynomial 1 (separated by space): ");
                scanf("%d %d", &coefficient, &exponent);
                insertNode(&poly1, coefficient, exponent);
                break;
            case 2:
                printf("Enter coefficient and exponent for polynomial 2 (separated by space): ");
                scanf("%d %d", &coefficient, &exponent);
                insertNode(&poly2, coefficient, exponent);
                break;
            case 3:
                result = addPolynomials(poly1, poly2);
                printf("Addition result: ");
                displayPolynomial(result);
                break;
            case 4:
                result = subtractPolynomials(poly1, poly2);
                printf("Subtraction result: ");
                displayPolynomial(result);
                break;
            case 5:
                result = multiplyPolynomials(poly1, poly2);
                printf("Multiplication result: ");
                displayPolynomial(result);
                break;
            case 6:
                printf("Polynomial 1: ");
                displayPolynomial(poly1);
                printf("Polynomial 2: ");
                displayPolynomial(poly2);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
