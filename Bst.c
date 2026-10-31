#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int item;
    struct node *llink,*rlink;
}NODE;
NODE *getnode(){
    NODE*x;
    x=(NODE*)malloc(sizeof(NODE));
    printf("enter the data\n");
    scanf("%d",x->item);
    x->llink=x->rlink=NULL;
return x;
}
NODE *insert(NODE *root){
NODE *temp,*cur,*prev;
temp=getnode();
if(root==NULL)
root=temp;
else{
    cur=root;prev=NULL;
    while(cur!=NULL){
        prev=NULL;
        if(cur->item>temp->item)
        cur=cur->llink;
        else
        cur=cur->rlink;
    }
    if(temp->item>prev->item)
    prev->rlink=temp;
    else
    prev->llink=temp;
}
return root;

}
void search(NODE *root){
    NODE *cur;
    int item;
    printf("enter the item to be searched\n");
    scanf("%d",&item);
    if(root==NULL)
    printf("tree is empty");
    else{
        cur=root;
        while(cur!=NULL){
            if(cur->item==item)
            break;
            if(cur->item>item)
            cur=cur->llink;
            else
            cur=cur->rlink;
        }
        if(cur!=NULL){
            printf("item found\n");
        }
        else{
            printf("item not found\n");
        }
    
    }
}
 void preorder(NODE*root){
    if(root==NULL)return;
        printf("%d",root->item);
        preorder(root->llink);
        preorder(root->rlink);
}
void inorder(NODE *root){
    if(root==NULL)return;
        inorder(root->llink);
        printf("%d",root->item);
        inorder(root->rlink);
}
void postorder(NODE *root){
    if(root==NULL)return;
        postorder(root->llink);
        postorder(root->rlink);
         printf("%d",root->item);
    
}
int findheight(NODE *root){
    if(root==NULL){
    return -1;
    }
    else{
        int lheight=findheight(root->llink);
     int rheight=findheight(root->rlink);
     if(lheight>rheight)
     return (lheight+1);
     else
     return (rheight+1);
    }
}
int main(){
    NODE*root=NULL;
    int ch,n,ht;
    while(ch<6){
        printf("1.insert\t2.search\t3.traverse\t4.height\t5.exit\n");
        printf("enter your choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("enter the no of nodes\n");
            scanf("%d",&n);
            printf("enter the tree data\n");
            for(int i=0;i<n;i++){
                root=insert(root);
            }
            break;
            case 2:search(root);
            break;
            case 3: printf("preorder traversal\n");
            preorder(root);
            printf("Inorder traversal\n");
            inorder(root);
            printf("postorder traversal\n");
            postorder(root);
            break;
            case 4:ht=findheight(root);
            printf("the height of the tree is=%d",ht);
            break;
            case 5:exit(0);
            default :printf("invalid choice\n");
            break;
        }
    }
    return 0;
}