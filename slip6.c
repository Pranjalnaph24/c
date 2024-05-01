 Q1
  
#include<stdio.h>
int a[10][10],n,indegree[10];
void find_indegree()
{
int i,j,sum;
for(j=0;j<n;j++)
{
sum=0;
for(i=0;i<n;i++)
sum+=a[i][j];
indegree[j]=sum;
}
}
void topology()
{
int i,u,v,t[10],s[10],top=-1,k=0;
find_indegree();
for(i=0;i<n;i++)
{
if(indegree[i]==0)
s[++top]=i;
}
while(top!=-1)
{
u=s[top--];
t[k++]=u;
for(v=0;v<n;v++)
{
if(a[u][v]==1)
{
indegree[v]--;
if(indegree[v]==0)
s[++top]=v;
}
}
}
printf("The topological order is:");
for(i=0;i<n;i++)
printf("\t%d",t[i]+1);
}
void main()
{
int i,j;
printf("Enter the no of vertices: ");
scanf("%d",&n); printf("Enter theadjacencymrix: \n"); 
for(i=0;i<n;i++) {for(j=0;j<n;j++) 
scanf("%d",&a[i][j]); }topology();
}

o/p
   Enter the no of vertices: 7
Enter theadjacencymrix: 
0 1 1 1 0 0 0
0 0 0 0 1 1 0
0 1 0 1 1 0 1
0 0 0 0 1 0 1
0 0 0 0 0 1 1
0 0 0 0 0 0 
0 0 0 0 0 0 0
 0 0 0 0 0 0 0
The topological order is:	1	3	4	2	5	7	6
   
   Q2
   
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

/*o/p:-
enter no. of vertices:5
enter the adjacency matrix:
0 10 3 0 0
0 0 1 2 0
0 4 0 8 2
0 0 0 0 7
0 0 0 9 0

enter the starting node:0
 distance of node1=7
 Path=1<-2<-0
 distance of node 2=3
 Path=2<-0
 distance of node 3=9
 Path=3<-1<-2<-0
 distance of node 4=5
 Path=4<-2<-0
 
   Q2 OR  
   
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

 enter a[0][0]:1

 enter a[0][1]:0

 enter a[0][2]:1

 enter a[1][0]:0

 enter a[1][1]:1

 enter a[1][2]:0

 enter a[2][0]:1

 enter a[2][1]:0

 enter a[2][2]:1

 enter adjacency matrix is....
	1	0	1
	0	1	0
	1	0	1
  