#include<stdio.h>
int str_len(char str1[]){
    int i=0;
    while(str1[i]!='\0'){
    i++;
    }
    return i;
}
int strcat(char str1[],char str2[]){
    int i=0,j=0;
    while(str1[i]!='\0'){
        i++;
    }
    while(str2[j]!='\0'){
        str1[i]=str2[j];
        i++,j++;
    }
    str1[i]='\0';
    return str1[i];
}
int strcmp(char str1[],char str2[]){
    int i=0;
    while (str1!='\0' &&str2!='\0')
    {
        if(str1[i]!=str2[i]){
        return str1[i]-str2[i];
    }
        i++;
    }
        return str1[i]-str2[i];
}
void str_rev(char str1){
    int i=0,j=str_len(str1)-1;
    char temp;
    while (i<j)
    {
        temp=str1[i];
        str1[i]=str1[j];
        str1[j]=temp;
        i++,j--;
    }
}
void main(){
    char str1[100],str2[200];
    int choice=0;
    while(choice<6){
        printf("\nenter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:  printf("\nenter the string:");
                gets(str1);//scanf("%s",str1);
                  printf("\nthe length of string is: %d",str_len(str1));
            break;
        case 2:  printf("\nenter the first string:");
                  gets(str1);//scanf("%s",str1);
                  printf("\nenter the second string:");
                  gets(str2);
                  printf("\nthe concatinated string is: %d",strcat(str1,str2));
            break;
            case 3:  printf("enter the first string:");
                  gets(str1);
                  printf("enter the second string:");
                  gets(str2);
                 if(strcmp(str1,str2)==0)
                 printf("strings are equal");
                 else
                 printf("strings are nor equal");
            break;
        case 4:  printf("enter the string:");
                  gets(str1);
                 printf("\nthe reverse of string is: %d",str_rev(str1));
            break;
            
        default: printf("invalid choice\n");
            break;
        }
    }
}
