#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left, *right;
};
struct node *newNode (int item)
{
  struct node *temporary = (struct node *) malloc (sizeof (struct node));
  temporary->data = item;
  temporary->left = temporary->right = NULL;
  return temporary;
}
void preorder (struct node *root)
{
  if (root != NULL)
    {
      printf ("%d ", root->data);
      preorder (root->left);
      preorder (root->right);
    }
}
void postorder (struct node *root)
{
    if(root !=NULL){
        
    }
}
struct node *insert (struct node *node, int data)
{
  if (node == NULL)
    return newNode (data);
  if (data < node->data)
    node->left = insert (node->left, data);
  else if (data > node->data)
    node->right = insert (node->right, data);

  return node;
}

int main ()
{
  struct node *root = NULL;
  root = insert (root, 9);
  insert (root, 7);
  insert (root, 5);
  insert (root, 8);
  insert (root, 14);
  insert (root, 11);
  insert (root, 16);

  printf ("The preorder is :\n");
  preorder (root);

  return 0;
}