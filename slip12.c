 Q1
    
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
1 5 0 5 4 6
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

Total cost of spanning tree=15 

  
    Q2 OR
    
 
#include<stdio.h>
#define MAX 10
void degree(int adj[][MAX],int x,int n)
{
    int i,incount=0,outcount=0;
    for(i=0;i<n;i++)
    {
        if(adj[x][i]==1)
        outcount++;
         if(adj[i][x]==1)
        incount++;
    }
    printf("the indegree of the node %d is %d \n",x,incount++);
    printf("the outdegree of the node %d is %d \n\n",x,outcount++);
}
void main()
{
    int adj[MAX][MAX],n,i,j;
    setbuf(stdout,NULL);
    printf("enter total number of vertices in graph : ");
    scanf("%d",&n);
    printf("enter 1: if edge is present else enter 2: \n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    {
        printf("enter edge from %d to %d = ",i,j);
        scanf("%d",&adj[i][j]);
    }
    for(i=0;i<n;i++)
    {
        degree(adj,i,n);
    }
}

o/p
   enter total number of vertices in graph : 2
enter 1: if edge is present else enter 2: 
enter edge from 0 to 0 = 0
enter edge from 0 to 1 = 1
enter edge from 1 to 0 = 1
enter edge from 1 to 1 = 0
the indegree of the node 0 is 1 
the outdegree of the node 0 is 1 

the indegree of the node 1 is 1 
the outdegree of the node 1 is 1    
     