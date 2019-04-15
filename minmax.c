#include<stdio.h>
#include<stdlib.h>
int min,max;
void min_max(int a[30],int i,int j)
{
int min1,max1,mid;
if(i==j)
{
min=max=a[i];
}
else if(i==j-1)
{
if(a[i]>a[j])
{
max=a[i];
min=a[j];
}
else
{
max=a[j];
min=a[i];
}
}
else
{
mid=(i+j)/2;
min_max(a,i,mid-1);
min1=min;
max1=max;
min_max(a,mid,j);
if(max1>max)
max=max1;
if(min1<min)
min=min1;
}
}
int main()
{
int i,n,a[30];
printf("Enter the number of elements\n");
scanf("%d",&n);
printf("Enter elements\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
min_max(a,0,n-1);
printf("The minimum element is--->%d\n",min);
printf("The maximum element is--->%d\n",max);
return 0;
}
