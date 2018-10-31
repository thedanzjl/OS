#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main () {

   printf("%c", 'H');
   sleep(1);

   printf("%c", 'e');
   sleep(1);

   printf("%c", 'l');
   sleep(1);

   printf("%c", 'l');
   sleep(1);

   printf("%c", 'o');
   sleep(1);

   printf("\n"); // line buffer writes to output when sees next line char.

   return(0);
}