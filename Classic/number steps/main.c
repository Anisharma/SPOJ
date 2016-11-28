#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
    int a,i=0,j=0,k=0;
    scanf("%d",&a);
    int b[a][2];
    for(i=0;i<a;i++)
    {
        scanf("%d %d",&b[i][0],&b[i][1]);
    }
    for(i=0;i<a;i++)
    {
      j=abs(b[i][0]-b[i][1]);
      if(j==0||j==2)
      {
        if(b[i][0]%2==0&&b[i][1]%2==0)
        {
            printf("%d\n",(b[i][0]+b[i][1]));
        }
        else
        {
            printf("%d\n",(b[i][0]+b[i][1]-1));
        }
      }
      else
      {
           printf("No Number\n");
      }

    }
    return 0;
}
