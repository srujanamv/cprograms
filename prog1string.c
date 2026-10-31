#include<stdio.h> 
#include<stdlib.h>
 int str_len(char str1[])
{
    int i=0;
    while(str1[i]!='\0')
    {
        i++;
    }
    return i;

}
void str_cat(char str1[], char str2[])
{
 int  i= str_len(str1),j=0;
while( str2[j]!='\0')
{
str1[i]=str2[j];
i++;j++;
}
str1[i]='\0';
}
int str_cmp(char str1[],char str2[]){
  int  i=0,j=0;
  while(str1[i]!='\0' && str2[j]!='\0'){
  if(str1[i]!=str2[j]){
      return str1[i]-str2[j];
  }   
  i++;j++;
}
  return str1[i]-str2[j];
}

void str_rev( char str1[])
{
int i=0,j=str_len(str1)-1;
while(i<j){
    int temp=str1[i];
    str1[i]=str1[j];
str1[j]=temp;
i++;j--;
}
}
void main()
{
    int choice;
    char str1[100],str2[100];
    while (1)
    {
        printf("\n1.string length\n 2.string concatination\n3.string comparsion\n 4.string reverse\n5.exit\n enter your choice:");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("enter the string to find the length ");
        scanf("%s", str1);
        printf("string lenth=%d\n",str_len(str1));
        break;
        case 2: printf("enter the string 1:");
        scanf("%s", str1);
        printf("enter the string 2:");
        scanf("%s", str2);
        str_cat(str1,str2);
        printf("concatinated string=%s\n",(str1));
        break;
        case 3: printf("enter the string 1:   ");
        scanf("%s", str1);
        printf("enter the string 2:");
        scanf("%s", str2);
if(str_cmp(str1,str2)==0){
    printf("both strings are same");
}
    else{
        printf("strings are not same\n");
    }
    break;
    case 4: printf("enter the string to  reverse");
        scanf("%s", str1);
        rev_str(str1);
        printf("reversed string=%s\n", str1);
        break;
case 5:exit(0);
break;
default:printf("invalid choice\n");
break;
}

        

        }
    
}


    