#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int a,i=0,j=0,k=0;
    char b[200];
    while(1)
    {
       scanf("%d",&a);
       if(a==0)
       {
           break;
       }
       else
       {
           scanf("%d",b);
           for(i=0;i<a;i++)
           {
               for(j=0; ;j=j+2)
               {
                 printf("%d",b[i+a*j-1]);
                 printf("%d",b[i+a*j]) ;
               }
           }
       }

    }

    return 0;
}
