#include<stdio.h>
#include<string.h>
int main()
{
    int i=0,j=0,f,g;
    char b[100],c[100],d[102],e[102];
     for(i=0;i<100;i++)
    {
        b[i]=0;
        c[i]=0;
    }
    for(i=0;i<102;i++)
    {
        d[i]=0;
        e[i]=0;
    }
    for(i=0;i<10;i++)
    {
        gets(b);
        gets(c);
        f = strlen(b);
        g = strlen(c);
        printf("%d\n%d\n",f,g);
        printf("%c\n",b[0]);
        for(j=(f);j>0;j--)
        {
          d[j]=(b[j-1]+c[j-1-(f-g)])%10+d[j];
          d[j-1]=(b[j-1]+c[j-1-(f-g)])/10+d[j-1];
        }
        printf("%s",d);
    }
    return 0;
}
