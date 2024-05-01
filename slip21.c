Q1
   
 #include<stdio.h>
#define INFINITY 9999
#define MAX 10
void dijkstra(int G[MAX][MAX],int n,int startnode);
int main()
{
int G[MAX][MAX],i,j,n,u;
printf("enter no. of vertices:");
scanf("%d",&n);
printf("\nenter the adjacency matrix:\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&G[i][j]);
printf("\nenter the starting node:");
scanf("%d",&u);
dijkstra(G,n,u);
return 0;
}
void dijkstra(int G[MAX][MAX],int n,int startnode)
{
int cost[MAX][MAX],distance[MAX],pred[MAX];
int visited[MAX],count,mindistance,nextnode,i,j;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
if(G[i][j]==0)
cost[i][j]=INFINITY;
else
cost[i][j]=G[i][j];
for(i=0;i<n;i++)
{
distance[i]=cost[startnode][i];
pred[i]=startnode;
visited[i]=0;
}
distance[startnode]=0;
visited[startnode]=1;
count=1;
while(count<n-1)
{
mindistance=INFINITY;
for(i=0;i<n;i++)
if(distance[i]<mindistance && !visited[i])
{
mindistance=distance[i];
nextnode=i;
}
visited[nextnode]=1;
for(i=0;i<n;i++)
if(!visited[i])
if(mindistance+cost[nextnode][i]<distance[i])
{
distance[i]=mindistance+cost[nextnode][i];
pred[i]=nextnode;
}
count++;
}
for(i=0;i<n;i++)
if(i!=startnode)
{
printf("\n distance of node %d=%d",i,distance[i]);
printf("\n Path=%d",i);
j=i;
do
{
j=pred[j];
printf("<-%d",j);
}while(j!=startnode);
}
}

  o/p
      enter no. of vertices:5

enter the adjacency matrix:
0 10 3 0 0 
0 0 1 2 0 
0 4 0 8 2 
0 0 0 0 7
0 0 0 9 0

enter the starting node:0

 distance of node 1=7
 Path=1<-2<-0
 distance of node 2=3
 Path=2<-0
 distance of node 3=9
 Path=3<-1<-2<-0
 distance of node 4=5
 Path=4<-2<-0
 
   Q2
   
 #include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *left;
struct node *right;
};
int getLeafCount(struct node *node){
if(node==NULL)
return 0;
if(node->left==NULL && node->right==NULL)
return 1;
else
return getLeafCount(node->left)+getLeafCount(node->right);
}
int getNodeCount(struct node *node){
if(node==NULL)
return 0;
else
return 1+getNodeCount(node->left)+getNodeCount(node->right);
}
struct node* newnode(int data){
struct node* node=(struct node*)malloc(sizeof(struct node));
node->data=data;
node->left=NULL;
node->right=NULL;
return(node);
}
void main(){
struct node *root=newnode(1);
root->left = newnode(2);
root->right = newnode(3);
root->left->left = newnode(4);
root->left->right = newnode(5);
printf("leaf count of the tree is %d",getLeafCount(root));
printf("\nTotal node count of the tree is %d",getNodeCount(root));
}

  o/p
       leaf count of the tree is 3
       Total node count of the tree is 5
       
       
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

Total cost of spanning tree=13 
          