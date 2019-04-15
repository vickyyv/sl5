/* Exp6: Write a program to solve travelling salesman problem and to print the path and the cost using branch and bound*/
#include<stdio.h>
int parent_cost,r,no_of_nodes;
int c[10][10],temp[10][10],visited[10],path[10];
void disp(int x[10][10]);
void copy(int x[10][10],int y[10][10]);
void cal_cost(int set[],int n);
int check_reduced();
int flag=1;
int main()
{
	int i,j,set[10];
	printf("Enter the no. of nodes in the graph\n");
	scanf("%d",&no_of_nodes);
	for(i=1;i<=no_of_nodes;i++)
	{
		for(j=1;j<=no_of_nodes;j++)
		{
			if(i!=j)
			{
				printf("Enter the cost of edge between ");
				printf("%d - %d:",i,j);
				scanf("%d",&c[i][j]);
			}
			else
				c[i][j]=99;
		}
	}
	visited[1]=1;
	path[r]=1;
	r++;
	disp(c);
	copy(temp,c);
	int root_cost=check_reduced();
	parent_cost=root_cost;
	copy(c,temp);
	printf("Reduced cost matrix:\n");
	disp(c);
	int p=0;
	for(i=1;i<=no_of_nodes;i++)
	{
		if(visited[i]!=1)
		{
			set[p]=i;
			p++;
		}
	}
	cal_cost(set,p);
	printf("\nMinimum cost: %d",parent_cost);
	printf("\nResultant path: ");
	for(i=0;i<r;i++)
		printf("%d-->",path[i]);
	printf("1");
	return 0;
}
void disp(int x[10][10])
{
	int i,j;
	for(i=1;i<=no_of_nodes;i++)
	{
		printf("\t");
		for(j=1;j<=no_of_nodes;j++)
			printf("%d\t",x[i][j]);
		printf("\n");
	}
}
void copy(int x[10][10],int y[10][10])
{
	int i,j;
	for(i=1;i<=no_of_nodes;i++)
	{
		for(j=1;j<=no_of_nodes;j++)
		{
			x[i][j]=y[i][j];
		}
	}
}
int find_min(int g[10],int n,int q[10])
{
	int i;
	int min=g[0];
	int node=q[0];
	for(i=1;i<n;i++)
	{
		if(min>g[i])
		{
			min=g[i];
			node=q[i];
		}
	}
	path[r]=node;
	r++;
	visited[node]=1;
	return(min);	
}
int check_reduced()
{
	int i,j;
	int min,sum=0;
	for(i=1;i<=no_of_nodes;i++)
	{
		min=999;
		for(j=1;j<=no_of_nodes;j++)
		{
			if(temp[i][j]<min)
			min=temp[i][j];
		}
		if(min!=0 && min!=99)
		{
			for(j=1;j<=no_of_nodes;j++)
			{
				if(i!=j && temp[i][j]!=99)
					temp[i][j]=temp[i][j]-min;
			}
			sum=sum+min;
		}
	}
	for(j=1;j<=no_of_nodes;j++)
	{
		min=999;
		for(i=1;i<=no_of_nodes;i++)
		{
			if(temp[i][j]<min)
			min=temp[i][j];
		}
		if(min!=0 && min!=99)
		{
			for(i=1;i<=no_of_nodes;i++)
			{
				if(j!=i && temp[i][j]!=99)
				temp[i][j]=temp[i][j]-min;
			}
			sum=sum+min;
		}
	}
	printf("\n\n");
	disp(temp);
	printf("\nsum : %d",sum);
	return(sum);	
}
void cal_cost(int set[],int n)
{
	int i,j,k;
	int g[10],q[10];
	for(i=0;i<n;i++)
	{
		copy(temp,c);
		for(j=0;j<r;j++)
		{
			for(k=1;k<=no_of_nodes;k++)
			{
				temp[path[j]][k]=99;
				if(j!=0)
				temp[k][path[j]]=99;
			}
		}
		for(k=1;k<=no_of_nodes;k++)
			temp[k][set[i]]=99;
		temp[set[i]][1]=99;
		int ans=check_reduced();
		g[i]=parent_cost+ans+c[path[r]][set[i]];
		printf("\ncost : %i",g[i]);
		q[i]=set[i];
	}
	parent_cost=find_min(g,n,q);
	int p=0;
	for(i=1;i<=no_of_nodes;i++)
	{
		if(visited[i]!=1)
		{
			set[p]=i;
			p++;
		}
	}
	if(p!=0)
		cal_cost(set,p);
}





