
   Q1
   
  
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
   Enter no. of vertices:5

Enter the adjacency matrix:
0 1 2 0 1
1 5 9 6 2
5 2 3 0 1 
1 0 1 0 1
0 1 0 1 0

spanning tree matrix:

0	1	0	0	1	
1	0	0	0	0	
0	0	0	0	1	
0	0	0	0	1	
1	0	1	1	0	

Total cost of spanning tree=1003

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
