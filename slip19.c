 #include <stdio.h>
#include <stdlib.h>
// Structure for a binary tree node
typedef struct Node {
int data;
struct Node *left;
struct Node *right;
} Node;
// Function to create a new node
Node* createNode(int value) {
Node* newNode = (Node*)malloc(sizeof(Node));
newNode->data = value;
newNode->left = newNode->right = NULL;
return newNode;
}
// Function to insert a value into the BST
Node* insert(Node* root, int value) {
if (root == NULL) {
return createNode(value);
}
if (value < root->data) {
root->left = insert(root->left, value);
} else if (value > root->data) {
root->right = insert(root->right, value);
}
return root;
}
// Function to search for a value in the BST
Node* search(Node* root, int value) {
if (root == NULL || root->data == value) {
return root;
}
if (value < root->data) {
return search(root->left, value);
} else {
return search(root->right, value);
}
}
// Function to perform inorder traversal of the BST
void inorder(Node* root) {
if (root != NULL) {
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
}
// Function to perform preorder traversal of the BST
void preorder(Node* root) {
if (root != NULL) {
printf("%d ", root->data);
preorder(root->left);
preorder(root->right);
}
}
// Function to perform postorder traversal of the BST
void postorder(Node* root) {
if (root != NULL) {
postorder(root->left);
postorder(root->right);
printf("%d ", root->data);
}
}
void main() {
Node* root = NULL;
int choice, value;
Node* result;
do {
printf("\nBinary Search Tree Operations\n");
printf("1. Insert\n");
printf("2. Search\n");
printf("3. Inorder Traversal\n");
printf("4. Preorder Traversal\n");
printf("5. Postorder Traversal\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:printf("Enter the value to insert: ");
scanf("%d", &value);
root = insert(root, value);
break;
case 2:printf("Enter the value to search: ");
scanf("%d", &value);
result = search(root, value);
if (result != NULL) {
printf("Value %d found in the tree.\n", value);
} else {
printf("Value %d not found in the tree.\n", value);
}
break;
case 3:printf("\nInorder Traversal: ");
inorder(root);
break;
case 4:printf("\nPreorder Traversal: ");
preorder(root);
break;
case 5:printf("\nPostorder Traversal: ");
postorder(root);
break;
default:printf("Invalid choice. Please enter a valid option.\n");
}
} while (choice != 6);
}


    Q2
   
 #include<stdio.h>
#include<malloc.h>
#define MAX 10
struct n
{
 int data;
 struct n *link;
};
 typedef struct n NODE;
 NODE *getnode(int);
 NODE *findlist(NODE *);
 void display(NODE*[],int);
 void main()
{
 NODE *ptr,*temp,*h[10];
 int n,a[10][10],i,j;
 printf("\n enter total number of vertices:");
 scanf("%d",&n);
 printf("\n enter entries of an adjacency list:\n");
 for(i=0;i<n;i++)
{
 for(j=0;j<n;j++)
{
 printf("\n enter a[%d][%d]:",i,j);
 scanf("%d",&a[i][j]);
}
}
//start of adjacency list program
 for(i=0;i<n;i++)
 h[i]=NULL;
 for(i=0;i<n;i++)
{
 for(j=0;j<n;j++)
{
 if(a[i][j]==1)
{
 temp=getnode(j+1);
 if(h[i]==NULL)
 h[i]=temp;
 else
{
 ptr=findlist(h[i]);
 ptr->link=temp;
}
}
}
}
printf("\n the adjacency list looks like...\n");
 display(h,n);
}
 NODE *getnode(int j)
{
 NODE *temp;
 temp=(NODE *)malloc(sizeof(NODE));
 temp->data=j;
 temp->link=NULL;
 return(temp);
}
NODE *findlist(NODE *h)
{
 NODE *ptr;
 for(ptr=h;ptr->link!=NULL;ptr=ptr->link);
 return(ptr);
}
void display(NODE *h[10],int n)
{
 NODE *ptr;
 int i;
 for(i=0;i<n;i++)
{
 printf("V%d",i+1);
 ptr=h[i];
 if(ptr==NULL)
 printf("NULL");
 while(ptr!=NULL)
{
 printf("->V%d",ptr->data);
 ptr=ptr->link;
}
 printf("\n");
}
}

  o/p
     enter total number of vertices:3

 enter entries of an adjacency list:

 enter a[0][0]:0

 enter a[0][1]:1

 enter a[0][2]:1

 enter a[1][0]:0

 enter a[1][1]:0

 enter a[1][2]:1

 enter a[2][0]:1

 enter a[2][1]:0

 enter a[2][2]:0

 the adjacency list looks like...
V1->V2->V3
V2->V3
V3->V1

   
   Q2 OR
   
#include <stdio.h>
 
int n, i, j, visited[10], queue[10], front = -1, rear = -1;
int adj[10][10];
 void bfs(int v)
{
    for (i = 1; i<= n; i++)
        if (adj[v][i] && !visited[i])
            queue[++rear] = i;
    if (front <= rear)
    {
        visited[queue[front]] = 1;
        bfs(queue[front++]);
    }
}
 void main()
{
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (i = 1; i<= n; i++)
    {
        queue[i] = 0;
        visited[i] = 0;
    }
    printf("Enter graph data in matrix form:    \n");
    for (i = 1; i<= n; i++)
        for (j = 1; j <= n; j++)
        {
            printf(" enter a[%d][%d]:",i,j);
            scanf("%d", &adj[i][j]);
        }
    printf("Enter the starting vertex: ");
    scanf("%d", &v);
    bfs(v);
    printf("The node which are reachable are:    \n");
    for (i = 1; i<= n; i++)
        if (visited[i])
            printf("%d\t", i);
        else
            printf("BFS is not possible. Not all nodes are reachable");
    return 0;
}

  o/p
      Enter the number of vertices: 3
Enter graph data in matrix form:    
 enter a[1][1]:0
 enter a[1][2]:1
 enter a[1][3]:1
 enter a[2][1]:1
 enter a[2][2]:0
 enter a[2][3]:0
 enter a[3][1]:1
 enter a[3][2]:0
 enter a[3][3]:0
Enter the starting vertex: 1
The node which are reachable are:    
1	2	3	      