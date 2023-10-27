#include <stdio.h>

struct Element {
    int row;
    int col;
    int value;
};

void fastTranspose(struct Element input[], struct Element output[], int rows, int cols, int terms) {
    int count[cols], start[cols];
    int i, j;

    for (i = 0; i < cols; i++) {
        count[i] = 0;
    }

    for (i = 0; i < terms; i++) {
        count[input[i].col]++;
    }


    start[0] = 0;
    for (i = 1; i < cols; i++) {
        start[i] = start[i - 1] + count[i - 1];
    }

    for (i = 0; i < terms; i++) {
        j = start[input[i].col];
        output[j].row = input[i].col;
        output[j].col = input[i].row;
        output[j].value = input[i].value;
        start[input[i].col]++;
    }
}

int main() {
    int rows, cols, terms;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    printf("Enter the number of non-zero terms: ");
    scanf("%d", &terms);

    struct Element input[terms];


    printf("Enter the elements (row, column, value):\n");
    for (int i = 0; i < terms; i++) {
        scanf("%d %d %d", &input[i].row, &input[i].col, &input[i].value);
    }

    struct Element output[terms];


    fastTranspose(input, output, rows, cols, terms);

    printf("Fast Transpose of the matrix:\n");
    for (int i = 0; i < terms; i++) {
        printf("%d %d %d\n", output[i].row, output[i].col, output[i].value);
    }

    return 0;
}

