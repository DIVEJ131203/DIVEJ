#include <stdio.h>
#include <stdlib.h>
//#include "ListFunctions.h"

typedef struct node {
    int val;
    struct node *next;
} node ;

typedef struct node Node;
void insertNode(Node *,int);
void display(Node *);
void input(Node *, int);
void deleteNode(Node **,Node *);


void insertNode(Node * prev,int x) {
    Node * new = (Node *) malloc(sizeof(Node));
    new->val = x;
    new->next = prev->next;
    prev->next = new;
}

void display(Node *node) {
    while(node != NULL) {
        printf("%d ",node->val);
        node = node->next;
    }
    printf("\n");
}

void input(Node *node,int n) {
    int i,temp;
    for (i=0;i<n;i++) {
        printf("Enter value to add ");
        scanf("%d",&temp);
        if (i == 0) {
            node->val = temp;
            node->next = NULL;
            continue;
        }
        insertNode(node,temp);
        node = node->next;
    }
}

void deleteNode(Node ** list, Node * tbd) {
    if (*list == tbd) {
        *list = (*list)->next;
    }
    else {
        Node * temp = (Node *) malloc(sizeof(Node));
        temp = *list;
        while (temp->next != NULL) {
            if (temp->next == tbd) {
                temp->next = tbd->next;
                break;
            }
            temp = temp->next;
        }
    }
    free(tbd);
}



void deleteDuplicates(Node *list) {
    if (list == NULL) {
        printf("List is empty");
        return;
    }
    Node * iter1 = (Node *) malloc(sizeof(Node));
    Node * iter2 = (Node *) malloc(sizeof(Node));
    iter1 = (list)->next;
    iter2 = (list)->next;
    while (iter1->next != NULL) {
        int x = iter1->val;
        iter2 = iter1->next;
        while (iter2 != NULL) {
            if (iter2->val != x) 
                break;
            else 
                iter2 = iter2 -> next;
        }
        if (iter2 == NULL) {
            iter1->next = NULL;
            break;
        }
        else if (iter2 != iter1->next) {
            iter1->next = iter2;
        }
        iter1 = iter1->next;
    }
}

int main() {
    int n,x;
    Node * list = (Node *) malloc(sizeof(Node));
    printf("Enter length of list ");
    scanf("%d",&n);
    printf("Enter input for list:\n");
    input(list,n);
    Node * head = (Node *) malloc(sizeof(Node));
    head->next = list;
    printf("After removing duplicates: ");
    deleteDuplicates(head);
    display(head->next);
}
