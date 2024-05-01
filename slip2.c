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

//o/p
   Enter the no of vertices: 7
Enter theadjacencymrix: 
0 1 1 1 0 0 0
0 0 0 0 1 1 0
0 1 0 1 1 0 1
0 0 0 0 0 1 1
0 0 0 0 0 0 0
0 0 0 0 0 1 0
0 0 0 1 0 1 0


//Q2
 
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