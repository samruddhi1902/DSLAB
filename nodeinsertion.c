#include <stdio.h> 
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

void forward_traversal(struct Node *ptr) {

    while (ptr != NULL)
    {
        printf("Value of Node: %d\n", ptr->data);
        ptr = ptr->next;
    }
    
};

struct Node * start_insert(struct Node *head, int data) {

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->data = data;
    ptr->next = head;
    ptr->prev = NULL;

    head->prev = ptr;

    return ptr;
}

struct Node * between_insert(struct Node *head, int data, int index) {
   
   struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
   struct Node *p = head;

    int i = 0;
    while (i != index-1 && p != NULL)
    {
        p = p->next;
        i++;
    }
    
    ptr->data = data;
    ptr->next = p->next;
    ptr->prev = p;

    if (p->next != NULL) {
        p->next->prev = ptr;
    }

    p->next = ptr;

    return head;
}

struct Node * end_insert(struct Node *head, int data) {
    
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }

    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = p;

    p->next = ptr;

    return head;
}

int main() {

    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 20;
    head->prev = NULL;
    head->next = second;

    second->data = 40;
    second->prev = head;
    second->next = third;

    third->data = 60;
    third->prev = second;
    third->next = NULL;

    printf("Forward traveral of all the nodes before any insertion: \n");
    forward_traversal(head);

    // head = start_insert(head, 10);
    // head = between_insert(head, 50, 2);
    head = end_insert(head, 70);

    printf("\nDouble linked list after insertion: \n");
    forward_traversal(head);
    
    return 0;
}