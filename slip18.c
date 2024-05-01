  Q1    

#include<stdio.h>
#include<malloc.h>
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
 printf("\n enter entries of an adjacency matrix:\n");
 for(i=0;i<n;i++)
{
 for(j=0;j<n;j++)
{
 printf("\n enter a[%d][%d]:",i,j);
 scanf("%d",&a[i][j]);
}
}
 printf("\n enter adjacency matrix is....\n");
 for(i=0;i<n;i++)
{
 for(j=0;j<n;j++)
{
 printf("\t%d",a[i][j]);
}
printf("\n");
}
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

  o/p
      enter total number of vertices:3

 enter entries of an adjacency matrix:

 enter a[0][0]:0

 enter a[0][1]:1

 enter a[0][2]:0

 enter a[1][0]:1

 enter a[1][1]:0

 enter a[1][2]:1

 enter a[2][0]:0 

 enter a[2][1]:1

 enter a[2][2]:0

 enter adjacency matrix is....
	0	1	0
	1	0	1
	0	1	0

   Q2
   
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

   Q2 OR
   

#include<stdio.h>
#include<stdlib.h>
#define infinity 1000
#define MAX 20
int G[MAX][MAX],spanning[MAX][MAX],n;
int main()
{
int i,j,total_cost;
printf("Enter no. of vertices:");
scanf("%d",&n);
printf("\nEnter the adjacency matrix:\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&G[i][j]);
total_cost=prims();
printf("\nspanning tree matrix:\n");
for(i=0;i<n;i++)
{
printf("\n");
for(j=0;j<n;j++)
printf("%d\t",spanning[i][j]);
}
printf("\n\nTotal cost of spanning tree=%d",total_cost);
return 0;
}
int prims()
{
int cost[MAX][MAX];
int u,v,min_distance,distance[MAX],from[MAX];
int visited[MAX],no_of_edges,i,min_cost,j;
//create cost[][] matrix,spanning[][]
for(i=0;i<n;i++)
for(j=0;j<n;j++)
{
if(G[i][j]==0)
cost[i][j]=infinity;
else
cost[i][j]=G[i][j];
spanning[i][j]=0;
}
//initialise visited[],distance[] and from[]
distance[0]=0;
visited[0]=1;
for(i=1;i<n;i++)
{
distance[i]=cost[0][i];
from[i]=0;
visited[i]=0;
}
min_cost=0; //cost of spanning tree
no_of_edges=n-1; //no. of edges to be added
while(no_of_edges>0)
{
//find the vertex at minimum distance from the tree
min_distance=infinity;
for(i=1;i<n;i++)
if(visited[i]==0&&distance[i]<min_distance)
{
v=i;
min_distance=distance[i];
}
u=from[v];
//insert the edge in spanning tree
spanning[u][v]=distance[v];
spanning[v][u]=distance[v];
no_of_edges--;
visited[v]=1;
//updated the distance[] array
for(i=1;i<n;i++)
if(visited[i]==0&&cost[i][v]<distance[i])
{
distance[i]=cost[i][v];
from[i]=v;
}
min_cost=min_cost+cost[u][v];
}
return(min_cost);
}

  o/p
        Enter no. of vertices:6

Enter the adjacency matrix:
0 3 1 6 0 0 
3 0 5 0 3 0
1 5 0 5 6 4
6 0 5 0 0 2
0 3 6 0 0 6
0 0 4 2 6 0

spanning tree matrix:

0	3	1	0	0	0	
3	0	0	0	3	0	
1	0	0	0	0	4	
0	0	0	0	0	2	
0	3	0	0	0	0	
0	0	4	2	0	0	
	