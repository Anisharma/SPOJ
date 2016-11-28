#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,siz;
    int *v;
    scanf("%d",&siz);
    v=malloc(siz*sizeof(int));
    for(i=0;i<siz;i++)
    {
        scanf("%d",&v[i]);
    }
    for(i=0;i<siz;i++)
    {
        printf("%d\n",v[i]);
    }
    return 0;
}
