#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,i=0,j=0;
    while(i==0)
    {
        scanf("%d",&a);
        if(a==0)
        {
            break;
        }
        else
        {  j=0;
            while(a>0)
            {
                j=j+a*a;
                a--;
            }
            printf("%d\n",j);
        }
    }
    return 0;
}
