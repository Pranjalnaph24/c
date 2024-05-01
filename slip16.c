Q1
     
 
#include<stdio.h>
#define nV 4
#define INF 999
void printMatrix(int matrix[][nV]);
void floydWarshall(int graph[4][4])
{
int matrix[nV][nV],i,j,k;
for(i=0;i<nV;i++)
for(j=0;j<nV;j++)
matrix[i][j]=graph[i][j];
for(k=0;k<nV;k++)
{
for(i=0;i<nV;i++)
{
for(j=0;j<nV;j++)
{
if(matrix[i][k]+matrix[k][j]<matrix[i][j])
matrix[i][j]=matrix[i][k]+matrix[k][j];
}
}
}
printMatrix(matrix);
}
void printMatrix(int matrix[][nV])
{
int i,j;
for(i=0;i<nV;i++)
{
for(j=0;j<nV;j++)
{
if(matrix[i][j]==INF)
printf("%4d",INF);
else
printf("%4d",matrix[i][j]);
}
printf("\n");
}
}
int main()
{
int graph[nV][nV]={{0,9,-4,INF},{6,0,INF,2},{INF,5,0,INF},{INF,INF,1,0}};
floydWarshall(graph);
}

 o/p
       0   1  -4   3
       6   0   2   2
      11   5   0   7
      12   6   1   0
      
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
5
heap array:8	1	5	
 the sorted array is :	 1	 5	 8  
     
      
      Q2 OR
      

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