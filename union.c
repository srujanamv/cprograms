#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
struct node*link;
}NODE;
NODE  *llone,*lltwo,*unionll,*interll;
NODE* insert(NODE **first,int num){
    NODE *newnode=(NODE*)malloc(sizeof(NODE));
    newnode->data=num;
    newnode->link=*first;
    *first=newnode;
    return *first;
}
int search(NODE *first, int num){
    while(first!=NULL){
        if(first->data==num){
            return 1;
        }
        first=first->link;
    }
    return 0;
}
NODE* findunion(NODE*llone ,NODE*lltwo){
    unionll=NULL;
    NODE*temp=llone;
    while(temp!=NULL){
        insert(&unionll,temp->data);
        temp=temp->link;
    }
    while(lltwo!=NULL){
        if(!search(llone,lltwo->data)){
            insert(&unionll,lltwo->data);
        }
        lltwo=lltwo->link;
    }
    return unionll;
    }
    NODE* intersection(NODE *llone, NODE *lltwo){
        interll=NULL;
        while(llone!=NULL){
            if(search(lltwo,llone->data))
            {
                insert(&interll,llone->data);
            }
            llone=llone->link;
        }
        return interll;
    }
    void printlist(NODE *cur){
        while(cur!=NULL){
            printf("-->%d",cur->data);
            cur=cur->link;
        }
    }
    void main()
{
    int i,llonecount,lltwocount,temp;
    printf("\n enter number of nodes in first linked list");
    scanf("%d",&llonecount);
    printf("\n enter data of first linked list");
    for(i=0;i<llonecount;i++){
        scanf("%d",&temp);
        insert(&llone,temp);
    }
    printlist(llone);
    printf("\n enter number of nodes in  second linked list");
    scanf("%d",&lltwocount);
    printf("\n enter data of second linked list");
    for(i=0;i<lltwocount;i++){
        scanf("%d",&temp);
        insert(&lltwo,temp);
    }
    printlist(lltwo);
    findunion(llone,lltwo);
    intersection(llone,lltwo);
    printf("\n union linked list \n");
    printlist(unionll);
    printf("\n insection linked list\n");
    printlist(interll);
    }



