#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int cqueue[MAX], front=-1,rear=-1;
void enqueue(){
    int item;
    if(front==0 && rear==(MAX-1)||rear==(front-1)){
        printf("\noverflow");
    }
else{
    printf("enter the item to isert:");
    scanf("%d",&item);
    if(rear==-1){
        rear++;front++;
    }
    else{
        rear=(rear+1)%MAX;
    }
        cqueue[rear]=item;
    
}

}
void dequeue(){
    if(front==-1){
        printf("\nunderflow");
    }
    else if(front==rear)
    {
        front=-1;rear=-1;
    }
    else{
        front=(front+1)%MAX;
    }
}
void display(){
    if(front==-1){
printf("\nqueue is  empty:");
}
printf("queue elements:\n");
 int i=front;
 while(i!=rear){
    printf("%d",cqueue[i]);
    i=(i+1)%MAX;
 }
 printf("%d",cqueue[rear]);
}
void main(){
    int ch;
    while(1){
        printf("\n1.enqueue\t2.dequeue\t3.display\t4.exit\n");
        printf("enter your choice:\n");
        scanf("%d", &ch);
        switch(ch){
            case 1:enqueue();
            break;
            case 2:dequeue();
            break;
            case 3:display();
            break;
            case 4:exit(0);
            break;
            default : printf("invalid choice\n");
        }
    }
        
}