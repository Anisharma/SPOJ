#include <stdio.h>
int main()
{
    int b[3],i;
    while(1)
    {
        scanf("%d %d %d",&b[0],&b[1],&b[2]);
        if(b[0]==0&&b[1]==0&&b[2]==0)
        {
            break;
        }
        else if(b[0]==b[1]||b[1]==b[2]||b[2]==b[0])
        {
            continue;
        }
        else
        {
            if(b[0]==0||b[1]==0||b[2]==0)
            {    i=(b[2]+b[1]-b[0]);
                printf("AP %d\n",i);
            }
            else
            {
                if((b[1]-b[0])==(b[2]-b[1]))
                {     i=(b[2]+b[1]-b[0]);
                    printf("AP %d\n",i);
                }
                else
                {   i=b[2]*b[1]/b[0];
                    printf("GP %d\n",i);
                }
            }
        }
    }
    return 0;
}
