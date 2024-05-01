 Q1
  
 #include <stdio.h>
#include <stdlib.h>
/* A tree node structure */
typedef struct node {
int data;
struct node* left;
struct node* right;
} node;
// Helper function for getLevel(). It returns level of the
// data if data is present in tree, otherwise returns 0.
int getLevelUtil(node* node, int data, int level)
{
if (node == NULL)
return 0;
if (node->data == data)
return level;
int downlevel
= getLevelUtil(node->left, data, level + 1);
if (downlevel != 0)
return downlevel;
downlevel = getLevelUtil(node->right, data, level + 1);
return downlevel;
}
/* Returns level of given data value */
int getLevel(node* node, int data)
{
return getLevelUtil(node, data, 1);
}
// Utility function to create a new Binary Tree node
node* newNode(int data)
{
node* temp = (node*)malloc(sizeof(node));
temp->data = data;
temp->left = NULL;
temp->right = NULL;
return temp;
}
/* Driver code */
void main()
{
node* root;
int x;
// Constructing tree given in the above figure
root = newNode(3);
root->left = newNode(2);
root->right = newNode(5);
root->left->left = newNode(1);
root->left->right = newNode(4);
for (x = 1; x <= 5; x++) {
int level = getLevel(root, x);
if (level)
printf(" Level of %d is %d\n", x,getLevel(root, x));
else
printf(" %d is not present in tree \n", x);
}
}

o/p
   Level of 1 is 3
 Level of 2 is 2
 Level of 3 is 1
 Level of 4 is 3
 Level of 5 is 2


 Q2
 
 #include<stdio.h>
void main()
{
int heap[10],no,i,j,c,root,temp;
printf("\n enter no of elements:");
scanf("%d",&no);
printf("\n enter the nos :");
for(i=0;i<no;i++)
scanf("%d",&heap[i]);
for(i=1;i<no;i++){
c=i;
do{
root = (c-1)/2;
if(heap[root]<heap[c]){
temp=heap[root];
heap[root]=heap[c];
heap[c]=temp;
}
c=root;
}while(c!=0);
}
printf("heap array:");
for(i=0;i<no;i++)
printf("%d\t",heap[i]);
for(j=no-1;j>=0;j--){
temp=heap[0];
heap[0]=heap[j];
heap[j]=temp;
root=0;
do{
c=2*root+1;
if((heap[c]<heap[c+1])&& c < j-1)
c++;
if(heap[root]<heap[c]&& c<j){
temp=heap[root];
heap[root]=heap[c];
heap[c]=temp;
}
root=c;
}
while(c<j);
}
printf("\n the sorted array is :");
for(i=0;i<no;i++)
printf("\t %d",heap[i]);
}  

o/p
   enter no of elements:3

 enter the nos :1
8
3
heap array:8	1	3	
 the sorted array is :	 1	 3

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
