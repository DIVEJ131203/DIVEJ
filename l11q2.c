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
typedef struct {
    Node ** nodesList;
    int front,rear;
} Queue;
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
//

void insertQ(Queue *q, Node * node) {
    if (q->front == -1)
        q->front = 0;
    q->nodesList[++(q->rear)] = node;
}

Node * deleteQ(Queue *q) {
    Node * item = (Node *) malloc(sizeof(Node));
    item = q->nodesList[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    else 
        q->front++;
    return item;
}

void iterPreOrder(Node ** tree) {
    Node * temp = (Node *) malloc(sizeof(Node));
    Stack s;
    s.tos = -1;
    push(&s,*tree);
    while (s.tos != -1) {
        temp = pop(&s);
        printf("%d ",temp->val);
        if (temp->right != NULL)
            push(&s,temp->right);
        if (temp->left != NULL)
            push(&s,temp->left);
    }
}

void iterPostOrder(Node **tree) {
    Stack s;
    s.tos = -1;
    Node * temp = (Node *) malloc(sizeof(Node));
    Node * temp2 = (Node *) malloc(sizeof(Node));
    temp = *tree;
    do {
        while (temp != NULL) {
            if (temp->right != NULL)
                push(&s,temp->right);
            push(&s,temp);
            temp = temp->left;
        }

        temp = pop(&s);
        if ((temp->right != NULL) && (s.nodes[s.tos] == (temp->right))) {
            temp2 = pop(&s);
            push(&s,temp);
            temp = temp2;
        }   
        else {
            printf("%d ", temp->val);
            temp = NULL;
        }
    } while(s.tos != -1);
}

void iterInOrder(Node **tree) {
    Stack s;
    s.tos = -1;
    Node * temp = (Node *) malloc(sizeof(Node));
    temp = *tree;
    do {
        if (temp != NULL) {
            push(&s,temp);
            temp = temp->left;
        }
        else {
            if (s.tos != -1) {
                temp = pop(&s);
                printf("%d ",temp->val);
                temp = temp->right;
            }
            else 
                break;
        }
    } while(1);
}

void iterLevelOrder(Node **tree) {
    Queue q;
    q.nodesList = (Node **) malloc(20 * sizeof(Node *));
    q.front = -1;
    q.rear = -1;
    Node * temp = (Node *) malloc(sizeof(Node));
    temp = *tree;
    while (temp != NULL) {
        printf("%d ",temp->val);
        if (temp->left != NULL)
            insertQ(&q,temp->left);
        if (temp->right != NULL)
            insertQ(&q,temp->right);
        if (q.front == -1)
            temp = NULL;
        else
            temp = deleteQ(&q);
    }
}

int main() {
    Node * tree = (Node *) malloc(sizeof(Node));
    createBT(&tree);
    printf("Pre Order : ");
    iterPreOrder(&tree);
    printf("\nPost Order : ");
    iterPostOrder(&tree);
    printf("\nInOrder : ");
    iterInOrder(&tree);
    printf("\nLevel Order : ");
    iterLevelOrder(&tree);
}

