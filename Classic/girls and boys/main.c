#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,i,j;
    while(1)
    {
        scanf("%d %d",&a,&b);
        if(a==(-1)&&b==(-1))
        {
            break;
        }
        else
        {
            if(b>a)
            {
                b=b+a;
                a=b-a;
                b=b-a;
            }
           if(a==b||a==(b-1))
           {
               printf("1\n");
           }
           else if(a==0||b==0)
           {
               printf("%d\n",a);
           }
           else
           {
            if(a%2==0)
            {
                c=a/2;
                 if(b==c||b==(c-1))
                {
                    printf("2\n");
                }
                else if(b==1)
                {
                    printf("%d\n",c);
                }
                else if(b>1&&b<(c-1))
                {
                    printf("%d\n",a/b);
                }
                else if(b>c)
                {
                    printf("1\n");
                }
            }
            else
            {
                c=(a+1)/2;
                if(b==c||b==(c-1))
                {
                    printf("2\n");
                }
                else if(b==1)
                {
                    printf("%d\n",c);
                }
                else if(b>1&&b<(c-1))
                {
                    printf("%d\n",a/b);
                }
                else if(b>c)
                {
                    printf("1\n");
                }
            }
           }
        }
    }
    return 0;
}
