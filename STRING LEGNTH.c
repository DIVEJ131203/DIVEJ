#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    int len;
    printf("enter the string\n");
    scanf("%s",&str);
    len= strlen(str);
    printf("length of given string is %d",len);
    return 0;
}
