
#include <stdio.h>
#include<math.h>
#define size 10 //maximum 10 cities
int n,npow,g[size][100],p[size][100],adj[size][size];

int tsp(int source,int set)
{
	printf("\nInside tsp");
	int masked,mask,result=999,temp,i;
	if(g[source][set]!=-1)
		return g[source][set];
	for(i=0;i<n;i++)
	{   
	    printf("\n-------------------------------------------------------------");
	    printf("\n1<<i=%d", 1 << i);
		mask = (npow - 1) - (1 << i);
		printf("\nMask Bit=%d", mask);
		masked=set&mask; //remove ith vertex from this set
		printf("\nMasked Bit=%d", masked);
		printf("\nSet Bit Value=%d", set);
		if(masked != set) // check ith vertex is not present in set
		{
			temp = adj[source][i] + tsp(i,masked);
			printf("\ntemp value=%d",temp);
			if(temp<result)
			{
				result=temp,p[source][set]=i;
			}
		}
	}
	return g[source][set]=result;//return minimum
}

void TSP()
{
	printf("\nInside TSP");
	int i,j, result;
	for(i=0;i<n;i++)
	{
    		for(j=0;j<npow;j++) 
	            	{
			g[i][j]=p[i][j]=-1; 
		}
	}
	printf("\nInitial g matrix is\n");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<npow;j++)
		{
			printf(" %d",g[i][j]);
		}
	}
	printf("\nInitial p matrix is\n");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<npow;j++)
		{
			printf(" %d",p[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
    		g[i][0]=adj[i][0];
	}
	printf("\nUpdated g matrix is\n");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<npow;j++)
		{
			printf(" %d",g[i][j]);
		}
	}
	result = tsp(0,npow-2);//npow-2 to exclude source vertex
	printf("Tour cost:%d\n",result);
	/*printf("Tour path:\n0 ");
	getpath(0,npow-2);
	printf("0\n");*/
}

int main(void)
{
	int i,j;
	printf("Enter number of cities\n");
	scanf("%d",&n);
	npow=(int)pow(2,n);//bit number required to represent all possible sets
	printf("npow = %d   ",npow);
	printf("\nEnter the adjacency matrix\n");
	for(i=0;i<n;i++)for(j=0;j<n;j++)
	{
		scanf("%d",&adj[i][j]);
	}
	printf("\nEntered adjacency matrix is\n");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			printf("\t%d",adj[i][j]);
		}
	}
	TSP();
	return 0;
}




