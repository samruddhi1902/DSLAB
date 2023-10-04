#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* head = NULL;
struct node* tail = NULL;

void addnode(int data) {
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->link = NULL;

    if (head == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        tail->link = newnode;
        tail = newnode;
    }
}

void printlist() {
    struct node* temp = head;
    if (head == NULL) {
        printf("LINKED LIST EMPTY\n");
    } else {
        printf("NODES: ");
        while (temp != NULL) {
            printf("%d   ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

void insertbeg(int data) {
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->link = head;
    head = newnode;
    printlist();
}

void insertend(int data) {
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->link = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node* temp = head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newnode;
    }
    printlist();
}

void insertatpos(int pos, int data) {
    struct node* ptr = head;
    struct node* ptr2 = malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->link = NULL;

    if (pos == 1) {
        ptr2->link = head;
        head = ptr2;
    } else {
        while (pos != 1) {
            ptr = ptr->link;
            pos--;
        }
        ptr2->link = ptr->link;
        ptr->link = ptr2;
    }
    printlist();
}

void deletebeg() {
    if (head == NULL) {
        printf("Linked list is empty. Nothing to delete.\n");
        return;
    }
    struct node* temp = head;
    head = head->link;
    free(temp);
    printlist();
}

void deleteend() {
    if (head == NULL) {
        printf("Linked list is empty. Nothing to delete.\n");
        return;
    }
    struct node* temp = head;
    struct node* temp2 = head;
    while (temp->link != NULL) {
        temp2 = temp;
        temp = temp->link;
    }
    temp2->link = NULL;
    free(temp);
    printlist();
}

void deleteatpos(int pos) {
    if (head == NULL) {
        printf("Linked list is empty. Nothing to delete.\n");
        return;
    }

    if (pos == 1) {
        struct node* temp = head;
        head = head->link;
        free(temp);
    } else {
        struct node* current = head;
        struct node* prev = NULL;

        while (pos != 1) {
            prev = current;
            current = current->link;
            pos--;
        }
        prev->link = current->link;
        free(current);
    }
    printlist();
}

void reverse_list() {
    struct node *prevnode, *currentnode, *nextnode;
    prevnode = NULL;
    currentnode = head;
    nextnode = head;

    while (nextnode != NULL) {
        nextnode = nextnode->link;
        currentnode->link = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    head = prevnode;

    printf("\nThe linked list after reversing: ");
    printlist();
}

int main() {
     int n,i,data2;
    printf("enter the number of nodes to input:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data2);
        addnode(data2);
    }
    printlist();
    int choice, data, pos;

    do {
        printf("\n1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific position\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete from a specific position\n");
        printf("7. Reverse the linked list\n");
        printf("8. Print the linked list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertbeg(data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertend(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertatpos(pos, data);
                break;
            case 4:
                deletebeg();
                break;
            case 5:
                deleteend();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteatpos(pos);
                break;
            case 7:
                reverse_list();
                break;
            case 8:
                printlist();
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