#include <stdio.h>
#include <stdlib.h>
typedef struct stack{
	int front,rear;
	char * arr;
}queue;
void display(queue * q)
{
	int i;
	printf("\tThe queue contains: ");
	for(i=q->front;i<=q->rear;i++)
	{
		printf(" %c ",q->arr[i]);
	}
	printf("\n");
}
int is_empty(queue * q)
{
	if(q->rear<0)
		return 1;
	return 0;
}
void push(queue * q,char node)
{
	if(q->front<0)
	{
		q->front=0;
		q->rear=0;
		q->arr[q->rear]=node;
	}
	else
	{
		q->rear+=1;
		q->arr[q->rear]=node;
	}
}
char pop(queue * q)
{
	char c=q->arr[q->front];
	q->front+=1;
	if(q->front==q->rear+1)
	{
		q->front=-1;
		q->rear=-1;
	}
	return c;
}
void bfs(int **adj_mat,int v)
{
	queue * q=malloc(sizeof(queue));
	q->front=-1;
	q->rear=-1;
	q->arr=malloc(v*sizeof(char));
	char s;
	printf("Enter source: ");
	scanf(" %c",&s);
	push(q,s);
	int i,j;
	int *visited=calloc(v,sizeof(int));
	visited[v]=1;
	while(!is_empty(q))
	{
		char curr=pop(q);
		int z=(int)curr-(int)'a';
		visited[z]=1;
		printf("\nVisited: %c",curr);
		int src=(int)curr-(int)'a';
		for(i=0;i<v;i++)
		{
			if(adj_mat[src][i] && !visited[i])
			{
				visited[i]=1;
				char new=(char)(i+(int)'a');
				push(q,new);
			}
		}
		display(q);
	}
	
}
void main()
{
	int v,i;
	printf("Enter number of vertices of the graph (numbered 'a' to 'z'): ");
	scanf("%d",&v);
	char ans='y';
	int ** adj_mat=calloc(v,sizeof(int*));
	for(i=0;i<v;i++)
		adj_mat[i]=calloc(v,sizeof(int));
	char s,d;
	while(ans=='y'||ans=='Y')
	{
		printf("Enter any two connected vertices: ");
		scanf(" %c %c",&s,&d);
		int src=(int)s-(int)'a';
		int dest=(int)d-(int)'a';
		adj_mat[src][dest]=1;
		adj_mat[dest][src]=1;
		printf("Is there any more connections?(Y/N): ");
		scanf(" %c",&ans);
	}
	bfs(adj_mat,v);
}
