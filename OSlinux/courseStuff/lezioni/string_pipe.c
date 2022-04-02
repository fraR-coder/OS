#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

#define N 20
int main (int argc, char** argv) {
   
  int vett[2];
  assert(pipe(vett)==0);

  char* stringa ="hola mundo";
   
  
  if(fork()){
    close(vett[0]);
    char x[N];
    int q=read(vett[1],x,N*sizeof(char));
    printf("Q=%d\n",q);
    printf("R=%s\n",x);
  }
  else{
    close(vett[1]);
    int w=write(vett[0],stringa,(strlen(stringa)+1)*sizeof(char));
    printf("W=%d\n",w);
      

    }
      
      

       
 
  return (0);
}
