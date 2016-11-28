#include <stdio.h>
#include <stdlib.h>
voidjk funct(int *b);
int n;
int main()
{
    int j;
    printf("size of array");
    scanf("%d",&n);
    int *a;
    a=malloc(sizeof(int)*n);
    printf("enter numbers");
    for(j=0;j<n;j++)
    {
        scanf("%d",&a[j]);
    }
    funct(a );
    return 0;
}
void funct(int *b)
{int j;
    for(j=0;j<n;j++)
    {
    printf("%d",b[j]*10);
    }
}
