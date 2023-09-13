#include <stdio.h>
#include <stdlib.h>

struct node {
  int data; 
  struct node *right;
  struct node *left; 
};


struct node* new_node(int x) {
  struct node *temp;
  temp = malloc(sizeof(struct node));
  temp -> data = x;
  temp -> left= NULL;
  temp -> right = NULL;

  return temp;
}


// insertion
struct node* insert(struct node * root, int x) {
 
  if (root == NULL)
    return new_node(x);
  else if (x > root -> data) 
    root -> right= insert(root -> right, x);
  else 
    root -> left= insert(root -> left, x);
  return root;
}

void inorder(struct node *root) {
  if (root != NULL) 
  {
    inorder(root -> left); 
    printf(" %d ", root -> data); 
    inorder(root -> right); 
  }
}

int main() {
  struct node *root;
  root = new_node(20);
  insert(root, 5);
  insert(root, 1);
  insert(root, 15);
  insert(root, 42);
  
  inorder(root);
  printf("\n");


  return 0;
}
