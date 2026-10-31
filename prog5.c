#include<stdio.h>
#include<stdlib.h>
# define MAX 5
int stack[MAX] ,top=-1,status=0,item;
void push(int stack[],int item){
    if(top==(MAX-1)){
        printf("\noverflow");
    }
    else
        stack[++top]=item;
status++;
    
}
int pop()
{
    if(top==-1){
        printf("\nunderflow");
    }
    else{
        return stack[top--];
    status--;
}
}
int palindrome(int stack[]){
    int temp;
    temp=status;
    for(int i=0;i<temp;i++)
    if(stack[i]!=pop()){
        return 0;
    }
    else
    return 1;
}
void display(int stack[])
{
    if(top==-1){
        printf("\n stack is empty");
    }
    else
    {
        for( int i=top;i>=0;i--){
            printf("|%d|\n",stack[i]);
        }

    }
}
void main(){
    int ch;
    while(1)
    {
        printf("\n1.push\t2.pop\t3.palindrome\t4.display\t5.exit\n");
        printf("\nenter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter the item\n");
            scanf("%d",&item);
            push(stack,item);
            break;
            case 2:printf("\nthe popped value is=%d",pop());
            break;
            case 3: if(palindrome(stack)==1){
                printf("\npalindrome");
            }
                else
                printf("\n not a palindrome");
                break;
                case 4:display(stack);
                break;
                case 5:exit(0);
                break;
                default:printf("\n inavlid choice");
                break;
            }

        }
    }
