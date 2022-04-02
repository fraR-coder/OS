#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>


int main() {
   int i=0;

    for (i=2; i>=1; i--) {

      if (!fork ())
        printf ("%d\n", -i);

      else
        printf ("%d\n", i);
        
    }


   return 0;
}