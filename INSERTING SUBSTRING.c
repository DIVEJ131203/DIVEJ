
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
     char S1[50], S2[15];
     int index, i, l1, l2;
     printf("Enter String :--> ");
     gets(S1);
     printf("Enter Substring :--> ");
     gets(S2);
     printf("Enter Index :--> ");
     scanf("%d", &index);
     l1 = strlen(S1);
     l2 = strlen(S2);
     if(index > l1)
     {
          printf("Invalid Index");
          exit(0);
     }
     for(i = l1;i >= index; i--)
          S1[i + l2] = S1[i];
     for(i = 0;i < l2; i++)
          S1[index + i] = S2[i];
     printf("\nAfter Insertion :--> %s", S1);
}
