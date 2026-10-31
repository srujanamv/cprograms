#include<stdio.h>
#include<stdlib.h>
typedef struct{
    char*name;
    int date;
    char*description;
}Day;
void create(Day*week,int size){
for(int i=0;i<size;i++){
week[i].name=(char*)malloc(20*sizeof(char));
week[i].description=(char*)malloc(100*sizeof(char));
}
}
void read(Day*week,int size){
    for(int i=0;i<size;i++){
        printf("enter the name of theday\n");
        scanf("%s",week[i].name);
        printf("enter the date");
          scanf("%d",&week[i].date);
printf("enter the description");
          scanf("%s",week[i].description);   
    }
}
void display(Day*week,int size){
    printf("enter the week activity details\n");
    for( int i=0;i<size;i++){
        printf("day:%s\tdate:%d\tactivity:%s\n", week[i].name,week[i].date,week[i].description);
    }
}
void main(){
    int size;
    printf("enter the number of of days in the week\n");
    scanf("%d",&size);
   Day*week=(Day*)malloc(sizeof(Day));
   create(week,size);
   read(week,size);
   display(week,size);
for( int i=0;i<size;i++){
    free(week[i].name);
    free(week[i].description);
}
free(week);
}