Q1
    
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
   
 