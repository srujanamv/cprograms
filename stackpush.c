#include<stdio.h>
#define MAX 5
int stack[MAX],top=-1;
void push(int stack[], int item)
{
if(top==(MAX-1))
{
 printf("the stack overflow\n");
}
else
{
stack[++top]=item;
printf("%d\n",item);
}
}
        
int main()
{
 int item;

    printf("enter the items of the stack:");
    scanf("%d",&item);
      push(stack, item);

return 0;
}