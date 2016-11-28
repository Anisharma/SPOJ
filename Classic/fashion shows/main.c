#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,i=0,j=0,k=0,l=0,x,y,z=0,m;
    scanf("%d",&a);
     int b[a],c[a];
    for(i=0;i<a;i++)
    {
        scanf("%d",&b[i]);
        m=b[i];
        int *d;
        int *e;
        d=malloc(m*sizeof(int));
        e=malloc(m*sizeof(int));
        for(j=0;j<m;j++)
        {
            scanf("%d",&d[j]);
        }
        for(j=0;j<m;j++)
        {
            scanf("%d",&e[j]);
        }


        for(k=0;k<m;k++)
        {
           for(l=k+1;l<m;l++)
           {
             if(d[k]>d[l])
             {
                 x=d[k];
                 d[k]=d[l];
                 d[l]=x;
             }
             if(e[k]>e[l])
             {
                 y=e[k];
                 e[k]=e[l];
                 e[l]=y;
             }
           }
        }
         z=0;
        for(j=0;j<m;j++)
        {

            z=z+(e[j]*d[j]);
        }
        c[i]=z;
    }
    for(i=0;i<a;i++)
    {
        printf("%d\n",c[i]);
    }

    return 0;
}
