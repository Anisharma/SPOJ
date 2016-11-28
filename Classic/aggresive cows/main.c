#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,i=0;
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        int b,c;
        scanf("%d  %d",&b,&c);
        int d[b],j=0,k=0;
        for(j=0;j<b;j++)
        {
            scanf("%d",&d[j]);
        }
        for(j=0;j<b;j++)
        {
            for(k=(j+1);k<b;k++)
            {
                if(d[j]>d[k])
                {
                    d[j]=d[j]+d[k];
                    d[k]=d[j]-d[k];
                    d[j]=d[j]-d[k];
                }
            }
        }



    }
    return 0;
}
