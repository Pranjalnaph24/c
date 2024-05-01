 Q1
  
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
0 0 0 0 0 0 0
0 0 0 0 0 1 0
