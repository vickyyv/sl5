

#include<stdio.h>
int a[100],n,tp;
void bubble()
{
  int i,j;
  int temp;
  for(i=0;i<n-1;i++)
     for(j=0;j<n-i-1;j++)
        if(a[j] > a[j+1])
        {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
        
    for(i=0;i<n;i++)
   {
      printf("%d\t",a[i]);
   }
}

void tapes(int i)
{
   int b[10],j;
   int num=0;
   int sum=0,avg=0;
  //printf("num:%d",num);
    for(j=0;j<n;j++)
    {
    
        if(j % tp == i)
        {
            b[num]=a[j];
            num++;
        }
    }

   printf("\n");
   for(i=0;i<num;i++)
   {
      printf("%d\t",b[i]);
   }
  for(i=0;i<num;i++)
   {
      for(j=0;j<=i;j++)
      {
          sum = sum + b[j];
      }
   }
   
    avg = sum/num;
   
    printf("\nMean Retrieval Time:%d and \t Total Time:%d",avg,sum);
   
    
    
}
void main()
{

printf("No of files and ntp:\n");
scanf("%d%d",&n,&tp);

printf("Enter files:\n");
int i;
for(i=0;i<n;i++)
scanf("%d",&a[i]);
bubble();

for(i=0;i<tp;i++)
{
printf("Tape%d",i+1);

tapes(i);
}

}


