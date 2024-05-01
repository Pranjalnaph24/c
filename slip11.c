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
void DFS(int);
int G[10][10],visited[10],n;  
void main()
{
int i,j;
printf("Enter number of vertices:");
scanf("%d",&n);
printf("\nEnteradjecency matrix of the graph: \n");
  
for(i=0;i<n;i++)
{
       for(j=0;j<n;j++)
       {
         printf(" enter a[%d][%d]:",i,j);
         scanf("%d",&G[i][j]);
       }
}
   for(i=0;i<n;i++)
          visited[i]=0;
        DFS(0);
}
void DFS(int i)
{
    int j;
    printf("\n%d",i);
    visited[i]=1;
for(j=0;j<n;j++)
{
       if(!visited[j]&&G[i][j]==1)
            DFS(j);
}
}

o/p
   Enter number of vertices:4

Enteradjecency matrix of the graph: 
 enter a[0][0]:0
 enter a[0][1]:1
 enter a[0][2]:0
 enter a[0][3]:0
 enter a[1][0]:1
 enter a[1][1]:1
 enter a[1][2]:1
 enter a[1][3]:1
 enter a[2][0]:0
 enter a[2][1]:1
 enter a[2][2]:0
 enter a[2][3]:0
 enter a[3][0]:0
 enter a[3][1]:1
 enter a[3][2]:0
 enter a[3][3]:0

0
1
2
3
