#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>  
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
    assert(argc==2);
    int n=atoi(argv[1]);
    int* v= (int*)malloc(n*sizeof(int));
    printf("con %d bit ottengo:\n",n);
    for(int i=0;i<n;i++){

        if(fork()){
            //padre aggiunge 0
            v[i]=0;
           
        }
        else{
            //child aggiunge 1
            v[i]=1;
        }



    }
    for(int i=0;i<n;i++){
        printf("%d",v[i]);

    }
    printf("\n");
    

wait(NULL);

    return 0;

}