#include "stdio.h"
#include "string.h"
struct Student
{
    char ID[20];
    char name[10];
    double score;
}
    stu[12]={
        {"0800301105", "JACK", 95},{"0800201505", "LUN", 85},{"0400820115", "MARY", 75.5},
        {"0400850122", "KATE", 78.9},{"0500201011", "LILI", 88},{"0800401105", "JACK", 96},
        {"0600830105", "JAN", 98.4},{"0952520012", "SAM", 75},{"9721000045", "OSCAR", 64},
        {"0700301105", "JACK", 97},{"0458003312", "ZOE", 68.9},{"0400830211", "BOBI", 87.6}
};

void sort(struct Student *p,int n){
    int i,j;
    struct Student temp;
    for (int i = 1 ; i <n ;i++) {
        temp=stu[i];
        for(j=i-1;j>=0 && strcmp((p+j)->ID,temp.ID)>0;j--)
            stu[j+i]=stu[j];
        stu[j+1]=temp;
    }
}
int search(struct Student *p,char *s,int n){
    int low=0,height= n - 1,mid;
    while (low <= height){
        mid = (low + height) / 2;
        if (strcmp((p+mid)->ID,s)==0)
            return mid;
        else if (strcmp((p+mid)->ID,s)<0)
            low =mid+1;
        else
            height= mid - 1;
    }
    return -1;
}
int  main()
{
    int i;
    struct Student *p=stu;
    sort(p,12);
    for (int i = 0; i < 12;i++)
        printf("%s\n",stu[i].ID);
    printf("0700301105µÄÏÂ±ê:%d",search(p,"0700301105",12));
    return 0;
}
