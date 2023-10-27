#include<stdio.h>
#include<string.h>

int main()
{   int comp;
    char str1[100], str2[100];
    printf("enter the string 1\n");
    scanf("%s",&str1);
    printf("enter the string 2\n");
    scanf("%s",&str2);
    comp=strcmp(str1,str2);
    if(comp==0)
    {
        printf("strings are same");
    }
    else printf("strings are not same");

    return 0;
}
