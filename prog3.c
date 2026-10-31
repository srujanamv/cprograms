#include<stdio.h>
#include<stdlib.h>
char str[100],pat[50],ans[100],rep[50];
int i,j,m,c,k,flag=0;
void string_match(){
    i=j=m=c=0;
    while(str[c]!='\0'){
        if(str[m]==pat[i]){
            i++;m++;
            if(pat[i]!='\0'){
                flag=1;
                for(k=0;rep!='\0';k++,j++)
                ans[j]=rep[k];
                i=0;
                c=m;
            }

        }
        else{
            ans[j]=str[c];
            j++;c++;
            m=c;

        }
    }
ans[j]='\0';
}