#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>


int main(int argc, char** argv) {
   
    int i=0;
    int n,t;
    int Ntot;
    assert(argc==3);
    n=atoi(argv[1]);
    t=atoi(argv[2]);
    Ntot=2^n;

    for(i=0;i<n;i++){

        if(!fork()){
            if(i==n-1){
                sleep(t);
                printf("child    %d\n",i);
            }
        }

       else{
            if(i==n-1){
                sleep(t);
                printf("parent    %d\n",i);
            }
        } 


    }




   return 0;
}