#include <stdio.h>
#include <stdlib.h>
int main()
{
  int **a;
  a = (int**)malloc(sizeof(int*)*10);
  for( int i=0;i<10;i++)
  {
      a[i]=(int *)malloc(sizeof(int)*10);
      for(int j=0;j<10;j++)
      {

      }
  }
    return 0;
}
