#include <stdio.h>
int main ()
{
   long int a;
   int b;
   b=0;a=4;
   do 
   {
     b++;
     a=(a+1)*2;
   }
   while (b<8);
   printf("%ld",a);
   return 0;
}