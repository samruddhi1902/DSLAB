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

struct Node * start_delete(struct Node *head) {

    struct Node *ptr = head;
    
    head = head->next;
    head->prev = NULL;
    free(ptr);

    return head;

}

struct Node * between_delete(struct Node *head, int index) {

    struct Node *p = head;
    struct Node *q = head->next;

    for (int i = 0; i < index-1 && q != NULL; i++)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;

    if (q->next != NULL)
    {
        q->next->prev = p;
    }
    
    free(q);

    return head;
}

struct Node * end_delete(struct Node *head) {
    
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    
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

    printf("Forward traveral of all the nodes before any deletion: \n");
    forward_traversal(head);

    // head = start_delete(head);
    // head = between_delete(head, 1);
    head = end_delete(head);

    printf("\nDouble linked list after deletion: \n");
    forward_traversal(head);
    
    return 0;
}
