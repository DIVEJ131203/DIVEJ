#include<stdio.h>
struct student{
    char name[50];
    int rollno;
    int marks;
}s[5];
int main()
{
    int i;
    printf("Enter information of all the students:\n");
    for (i=0;i<5;i++)
    {
        s[i].rollno=i+1;
        printf("ENTER credentials for ROLL NO. %d\n",s[i].rollno);
        printf("NAME:");
        scanf("%s",s[i].name);
        printf("MARKS out of 100: ");
        scanf("%d",&s[i].marks);
        printf("\n");
    }
    printf("***************DISPLAYING INFORMATION OF STUDENT ENTERED BY USER***************\n");
    for(i=0;i<5;i++)
    {

        printf("ROLL NO.%d\n",s[i].rollno);
        printf("NAME:%s\n",s[i].name);
         printf("MARKS:%d\n",s[i].marks);
         printf("\n");
    }
    return 0;
}
