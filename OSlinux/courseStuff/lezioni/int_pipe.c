#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
 
int main (int argc, char** argv) {
   
  int vett[2];
  assert(pipe(vett)==0);

      int y=3;
      int r=0;
    
    if(fork()){
      int q=read(vett[1],&r,sizeof(int));
      printf("Q=%d\n",q);
      printf("R=%d\n",r);
    }
    else{

      int w=write(vett[0],&y,sizeof(int));
       printf("W=%d\n",w);
      

    }
      
      

       
 
  return (0);
}
