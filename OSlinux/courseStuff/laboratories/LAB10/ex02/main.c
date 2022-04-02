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
#include <pthread.h>

void* tf(void* arg){
  
    //printf("ciao ciao\n");

    return NULL ;
}

int main(int argc, char** argv)
{   
    pthread_t tid;
     printf("%ld\n",tid);
    pthread_create(&tid,NULL,tf,NULL);

    printf("%ld",pthread_self());

    

    printf("hola hola\n");

    return 0;

}