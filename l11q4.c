#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int val;
    struct node * left;
    struct node * right;
} node ;

typedef struct node Node;

typedef struct {
    Node * nodes[100];
    int tos;
} Stack;

void push(Stack * s, Node * x) {
    s->nodes[++(s->tos)] = x;
}

Node * pop(Stack * s) {
    return (s->nodes[(s->tos)--]);
}

Node * createNode(int x) {
    Node * new = (Node *) malloc(sizeof(Node));
    new->val = x;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void inOrder(Node *tree) {
    if (tree != NULL) {
        inOrder(tree->left);
        printf("%d ",tree->val);
        inOrder(tree->right);
    }
}

void postOrder(Node *tree) {
    if (tree != NULL) {
        postOrder(tree->left);
        postOrder(tree->right);
        printf("%d ",tree->val);
    }
}

void preOrder(Node *tree) {
    if (tree != NULL) {
        printf("%d ",tree->val);
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void createBT(Node ** tree) {
    Node * iter = (Node *) malloc(sizeof(Node));
    Node * root = (Node *) malloc(sizeof(Node));
    Stack nodeStack;
    nodeStack.tos = -1;
    iter = NULL;
    int x;
    int inp = 0;
    printf("Enter value of root ");
    scanf("%d",&x);
    iter = createNode(x);
    push(&nodeStack,iter);
    root = iter;
    *tree = iter;

    printf("\n1. Enter left, 2. Enter right, 3. Move up, -1. Exit");

    do {
        printf("\nEnter choice ");
        scanf("%d",&inp);
        if (inp == 1) {
            printf("Enter value to insert ");
            scanf("%d",&x);
            Node * temp = createNode(x);
            push(&nodeStack,iter);
            iter->left = temp;
            iter = iter->left;
            printf("Moved left");
        }
        else if (inp == 2) {
            printf("Enter value to insert ");
            scanf("%d",&x);
            Node * temp = createNode(x);
            push(&nodeStack,iter);
            iter->right = temp;
            iter = iter->right;
            printf("Moved right");
        }
        else if (inp == 3) {
            if (nodeStack.tos == 0) {
                printf("Already at root");
            }
            else {
                iter = pop(&nodeStack);
                printf("Moved up");
            }
        }
        else 
            inp = -1;
    } while(inp != -1);
}

Node * copy(Node * node) {
    if (node == NULL)
        return NULL;
    Node * new = createNode(node->val);
    new->left = copy(node->left);
    new->right = copy(node->right);

    return new;
}

int eqCheck(Node * node1, Node * node2) {
    if (node1 == NULL && node2 == NULL) 
        return 1;
    if (node1 == NULL || node2 == NULL) 
        return 0;
    if (node1->val != node2->val) 
        return 0;
    return eqCheck(node1->left, node2->left) && eqCheck(node1->right, node2->right);
}


int main() {
    Node * tree = (Node *) malloc(sizeof(Node));
    Node * treeCopy = (Node *) malloc(sizeof(Node));
    createBT(&tree);
    printf("Inorder : ");
    inOrder(tree);
    treeCopy = copy(tree);
    printf("\nInorder of copy: ");
    inOrder(treeCopy);
    int check = eqCheck(tree,treeCopy);
    if (check)
        printf("\nBinary trees are equal");
    else
        printf("\nBinary trees are not equal");
}
