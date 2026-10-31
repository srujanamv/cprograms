#include<stdio.h>
#include<stdlib.h>
char str[200],pat[30],rep[50],ans[90];
int i,j,k,c,m,flag=0;
void stringmatch(){
    i=j=c=m=0;
    while(str[c]!='\0'){
        if(str[m]==pat[i]){
        i++,m++;
        if(pat[i]=='\0'){
          flag=1;
          for(k=0;rep[k]!='\0';k++,j++){
            ans[j]=rep[k];
          }
          i=0;c=m;
        }
    }
        else
        {
            ans[j]=str[c];
            j++;c++;
            m=c;
        }
      ans[j]='\0';
    }
}
void main(){
    printf("enter main string:");
    gets(str);
    printf("enter pat string:");
    gets(pat);
    printf("enter the replace string:");
    gets(rep);
    stringmatch(str,pat,rep);
if(flag==1)
printf("the resultent string is:%s ",ans);
else 
printf("string not found");
}