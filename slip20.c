 Q1
  
#include<stdio.h>
#include<stdlib.h>
int i,j,k,a,b,u,v,n,ne=1;
int min,mincost=0,cost[9][9],parent[9];
int find(int);
int uni(int,int);
void main()
{
printf("\n\t implementation of kruskal's algorithm\n");
printf("\nenter the no. of vertices:");
scanf("%d",&n);
printf("\nenter the cost adjacency matrix:\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&cost[i][j]);
if(cost[i][j]==0)
cost[i][j]=999;
}
}
printf("the edges of minimum cost spanning tree are\n");
while(ne<n)
{
for(i=1,min=999;i<=n;i++)
{
for(j=1;j<=n;j++)
{
if(cost[i][j]<min)
{
min=cost[i][j];
a=u=i;
b=v=j;
}
}
}
u=find(u);
v=find(v);
if(uni(u,v))
{
printf("%d edges (%d,%d)=%d\n",ne++,a,b,min);
mincost+=min;
}
cost[a][b]=cost[b][a]=999;
}
printf("\n\tminimum cost %d\n",mincost);
}
int find(int i)
{
while(parent[i])
i=parent[i];
return i;
}
int uni(int i,int j)
{
if(1!=j)
{
parent[j]=i;
return 1;
}
return 0;
}            

  o/p
     implementation of kruskal's algorithm

enter the no. of vertices:6

enter the cost adjacency matrix:
0 3 1 6 0 0 
3 0 5 0 3 0
1 5 0 5 6 4
6 0 5 0 0 2
0 3 6 0 0 6
0 0 4 2 6 0
the edges of minimum cost spanning tree are
1 edges (1,3)=1
2 edges (4,6)=2
3 edges (1,2)=3
4 edges (2,5)=3
5 edges (3,6)=4

	minimum cost 13

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