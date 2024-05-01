
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
    
#include <stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 10

int h[TABLE_SIZE]={NULL};

void insert()
{
 int key,index,i,flag=0,hkey;
 printf("\nenter a value to insert into hash table\n");
 scanf("%d",&key);
 hkey=key%TABLE_SIZE;
 for(i=0;i<TABLE_SIZE;i++)
    {
     index=(hkey+i)%TABLE_SIZE;
     if(h[index] == NULL)
     {
        h[index]=key;
         break;
     }
    }
    if(i == TABLE_SIZE)
     printf("\nelement cannot be inserted\n");
}

void search()
{
 int key,index,i,flag=0,hkey;
 printf("\nenter search element\n");
 scanf("%d",&key);
 hkey=key%TABLE_SIZE;
 for(i=0;i<TABLE_SIZE; i++)
 {
    index=(hkey+i)%TABLE_SIZE;
    if(h[index]==key)
    {
      printf("value is found at index %d",index);
      break;
    }
  }
  if(i == TABLE_SIZE)
    printf("\n value is not found\n");
}

void display()
{
  int i;
  printf("\nelements in the hash table are \n");
  for(i=0;i< TABLE_SIZE; i++)
  printf("\nat index %d \t value =  %d",i,h[i]);
}

main()
{
    int opt,i;
    while(1) {
        printf("\nPress 1. Insert\t 2. Display \t3. Search \t4.Exit \n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:exit(0);
        }
    }
}

o/p
    Press 1. Insert	 2. Display 	3. Search 	4.Exit 
1

enter a value to insert into hash table
10

Press 1. Insert	 2. Display 	3. Search 	4.Exit 
1

enter a value to insert into hash table
12

Press 1. Insert	 2. Display 	3. Search 	4.Exit 
1

enter a value to insert into hash table
11

Press 1. Insert	 2. Display 	3. Search 	4.Exit 
1

enter a value to insert into hash table
22

Press 1. Insert	 2. Display 	3. Search 	4.Exit 
1

enter a value to insert into hash table
45

Press 1. Insert	 2. Display 	3. Search 	4.Exit 
2

elements in the hash table are 

at index 0 	 value =  10
at index 1 	 value =  11
at index 2 	 value =  12
at index 3 	 value =  22
at index 4 	 value =  0
at index 5 	 value =  45
at index 6 	 value =  0
at index 7 	 value =  0
at index 8 	 value =  0
at index 9 	 value =  0
Press 1. Insert	 2. Display 	3. Search 	4.Exit 
3

enter search element
45
value is found at index 5
Press 1. Insert	 2. Display 	3. Search 	4.Exit 

    
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

o/p
    Level of 1 is 3
 Level of 2 is 2
 Level of 3 is 1
 Level of 4 is 3
 Level of 5 is 2
