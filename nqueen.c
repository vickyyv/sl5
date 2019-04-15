#include<stdio.h>
#include<math.h>

int n,arr[10],count=1;

void nqueen(int k,int n);
void display();
int place(int k,int i);
int main()
{
int i,j,k;
printf("\n Enter ChessBoard Size:");
scanf("%d",&n);
arr[n];
nqueen(1,n);
return 0;
}

void nqueen(int k,int n)
{
int i;
for(i=1;i<=n;++i)
{

	if(place(k,i))
	{
		arr[k]=i;
                if(k==n)
		{      
			display();
		}
		else
		{   
			nqueen(k+1,n);
		}
	}
}

}



int place(int k,int i)
{
int j;
for(j=1;j<=k-1;++j)
{
 if(arr[j]==i || (abs(arr[j]-i)==abs(j-k)) )
	return 0;
	
}
return 1;
}



void display()
{
int m,l;
printf("\n solution:%d\n",count++);

 for(m=1;m<=n;m++)
  printf("\tC%d",m);
 for(m=1;m<=n;m++)
 {
  printf("\n\nR%d",m);
  for(l=1;l<=n;l++) //for nxn board
  {
   if(arr[m]==l)
    printf("\tQ"); //queen at i,j position
   else
    printf("\t-"); //empty slot
  }
 }
}

