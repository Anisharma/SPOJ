#include <stdio.h>
#include<math.h>
int main()
{
    int a,i=0,j=0,k=0,l=0;
    while(1)
    {
        scanf("%d",&a);
        if(a==(-1))
        {
            break;
        }
        else
        {    j=0;
             l=0;
            int b[a];
            for(i=0;i<a;i++)
            {
                scanf("%d",&b[i]);
                j=j+b[i];
            }
            if(j%a!=0)
            {
                printf("-1\n");
                continue;
            }
            else
            {
                k=j/a;
                for(i=0;i<a;i++)
                {
                    if(b[i]>k)
                    {
                        l=l+(b[i]-k);
                    }
                }
                printf("%d\n",l);
            }
        }
    }
    return 0;
}
