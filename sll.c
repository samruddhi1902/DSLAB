#include <stdio.h>
#include <stdlib.h>


struct node 
{
    int data;
    struct node* link;
};
struct node*head,*tail=NULL;

void addnode(int data)
{
    struct node*newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->link=NULL;

    if(head==NULL)
    {
        head=newnode;
        tail=newnode;

    }
    else{
        tail->link=newnode;
        tail=newnode;
    }
}

void printlist()
{
    struct node*temp=head;
    if(head==NULL)
    {
        printf("LINKED LIST EMPTY");

    }
    printf("NODES:");
    while(temp!=NULL)
    {
        printf("%d   ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

void insertbeg(int data)
{
    //create newnode and head=newnode
    
    struct node*newnode=malloc(sizeof(struct node));;
    newnode->data=data;
    newnode->link=head;

    head=newnode;
}
void insertend(int data)
{
    //create a newnode
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->link = NULL;
    
    if (head== NULL)
    {
        head = newnode;
    }
    else
    {
        //create a temp node that points to head
        struct node *temp = head;
        while(temp->link!=NULL)
        {
            temp=temp->link;//traverse till last node
        }
        temp->link=newnode;//update the link of last node
    }

}

void insertatpos(int pos,int data)
{
    //create a temp pointer that points to head
    //create a temp node that stores data
    struct node*ptr=head;
    struct node*ptr2=malloc(sizeof(struct node));
    ptr2->data=data;
    ptr2->link=NULL;
    
    if(pos==1)
    {
    ptr2->link=head;
    head=ptr2;
    }
    else
    {
        while(pos!=1)
        {
            ptr=ptr->link;//traverse
            pos--;
        }
        ptr2->link=ptr->link;//update the temp node link to previous nodes link
        ptr->link=ptr2;//update previous nodes link as ptr2
    }

}

void deletebeg()
{
    struct node*temp=head;//temp=head
    head=head->link;//update head as link of next node
    free(temp);//free node
}

void deleteend()
{
    struct node*temp=head;
    struct node*temp2=head;
    while(temp->link!=NULL)
    {
        temp2=temp;//previous node
        temp=temp->link;
    }
    temp2->link=NULL;
    free(temp);
    
}

void deleteatpos(int pos) {
    if (head==NULL) {
        printf("Linked list is empty. Nothing to delete.\n");
        return;
    }

    if (pos == 1) 
    {
        struct node *temp = head;
        head = (head)->link;
        free(temp);
        return;
    }
    struct node *current = head;
    struct node *prev = NULL;

    while (pos!=1) {
        prev = current;
        current = current->link;
        pos--;
    }
    prev->link = current->link;
    free(current);
}





int main()
{
    int n,i,data;
    printf("enter the number of nodes to input:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        addnode(data);
    }
    printlist();
    
    insertbeg(5);
    printlist();
    insertend(25);
    printlist();
    insertatpos(3,45);
    printlist();
    deletebeg();
    printlist();
    deleteend();
    printlist();
    deleteatpos(3);
    printlist();

//case 1:


}
