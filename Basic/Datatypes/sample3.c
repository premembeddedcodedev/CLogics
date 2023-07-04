#include <stdio.h>
int main()
{
  int x = 10;
  static int y = x; //--> initialiser should not be variable - always assign constant
  
  if(x == y)
     printf("Equal");
  else if(x > y)
     printf("Greater");
  else
     printf("Less");
  
  getchar();
  return 0;
}
