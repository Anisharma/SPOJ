#include <stdio.h>
#include <stdlib.h>

int main()
{
   while(1)
   {
       float a,b;
       int i;
       scanf(".2%f",&a);
       if(a==0.00)
       {
           break;
       }
       else
       {
        b=0.00;
        i=1;
        while(b<a)
          {
          b=b+(float)(1/(i+1));
          i++;
          }
         printf("%d card(s)\n",(i+1));
       }

   }
    return 0;
}
