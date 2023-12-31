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

int search(Node * list, int x) {
    while (list != NULL) {
        if (list->val == x)
            return 1;
        list = list->next;
    }
    return 0;
}

void getUnion(Node *list1, Node *list2, Node *un) {
    int i = 0;
    Node * unHead = (Node *) malloc(sizeof(Node));
    unHead = un;
    while(list1 != NULL) {
        if (i == 0) {
            i=1;
            un->val = list1->val;
            un->next = NULL;
        }
        else {
            if (search(unHead,list1->val) == 0) {
                insertNode(un,list1->val);
                un = un->next;
            }
        }
        list1 = list1->next;
    }
    while(list2 != NULL) {
        if (search(unHead,list2->val) == 0) {
            insertNode(un,list2->val);
            un = un->next;
        }
        list2 = list2->next;
    }
}

void intersection(Node * list1, Node * list2, Node *inter) {
    int i=0;
    //list1 is smaller list
    while(list1 != NULL) {
        if (search(list2,list1->val)) {
            if (i == 0) {
                i=1;
                inter->val = list1->val;
                inter->next = NULL;
            }
            else {
                insertNode(inter,list1->val);
                inter = inter->next;
            }
        }
        list1 = list1->next;
    }
}

int main() {
    int n1,n2,x;
    printf("Enter number of elements in list 1: ");
    scanf("%d",&n1);
    printf("Enter number of elements in list 2: ");
    scanf("%d",&n2);
    Node * list1 = (Node *) malloc(sizeof(Node));
    Node * list2 = (Node *) malloc(sizeof(Node));
    Node * intersectionList = (Node *) malloc(sizeof(Node));
    Node * unionList = (Node *) malloc(sizeof(Node));

    printf("Enter elements for list1:\n");
    input(list1,n1);
    printf("The list is: ");
    display(list1);
    printf("Enter elements for list2:\n");
    input(list2,n2);
    printf("The list is: ");
    display(list2);
    printf("Union is: ");
    getUnion(list1,list2,unionList);
    display(unionList);
    printf("Intersection is: ");
    if (n1 <= n2)
        intersection(list1,list2,intersectionList);
    else
        intersection(list2,list1,intersectionList);
    display(intersectionList);
}
