#include <stdio.h>
#include<math.h>
int last(int d,int e)
{
    int j;
    j=pow(d,e);
    return j%10;
}

int main()
{
    int a,i=0,l=0;
    scanf("%d",&a);
    long long int b[a][2],k;
    int c[a];
    for(i=0;i<a;i++)
    {
        scanf("%lld %lld",&b[i][0],&b[i][1]);

        if(b[i][1]>4)
        {
            k=b[i][1];
            while(k>0)
            {
               l=k%4;
              k=k/4;
            }
            c[i]=last(b[i][0],l);

        }
        else
        {
            c[i]=last(b[i][0],b[i][1]);
        }
    }

    for(i=0;i<a;i++)
    {
        printf("\n%d",c[i]);
    }
    return 0;
}
