#include<stdio.h>
int main()
{
    int i,j,key,a[10],n;
printf("enter the size of the array:");
scanf("%d",&n);
printf("enter the array elements:");
for(i=0;i<n;i++)
{
    scanf("%d",&a[i]);
}
for(i=1;i<n;i++)
{
    j=i-1;
key=a[i];

while(j>=0 && a[j]>key)
{
    a[j+1]=a[j];
    j--;
}
a[j+1]=key;
}
printf("sorted array elements:");
for(i=0;i<n;i++)
{
printf("%d\n",a[i]);
}
return 0;
}
