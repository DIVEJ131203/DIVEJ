#include<stdio.h>
#include<string.h>

int main()
{
    char str1[100], str2[100];
    printf("enter the string 1\n");
    scanf("%s",&str1);
    printf("enter the string 2\n");
    scanf("%s",&str2);
    strcat(str1,str2);
    printf("String obtained on concatenation is %s\n",str1);


    return 0;
}
