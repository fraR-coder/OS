#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include<sys/wait.h>


int main(int argc, char** argv) {
   
    int i=1;
     printf("P%d\n",i);
    sleep(2);
    
    pid_t pid=fork();

    if(pid){
        printf("P%d\n",2);
        sleep(2);

        pid=fork();

        if(pid){
            printf("P%d\n",4);
            wait(NULL);
        }
        else{
            printf("P%d\n",5);
            
            exit(1);
        }
         sleep(3);
         printf("P%d\n",7);
         wait(NULL);
         sleep(3);
         printf("P%d\n",9);
         

    }
    else{
        printf("P%d\n",3);
        sleep(3);
        pid=fork();

        if(pid){
            printf("|\n");
            wait(NULL);
        }
        else{
            printf("P%d\n",6);
            exit(1);
        }
        sleep(2);
        printf("P%d\n",8);
        exit(1);
    }
      


   return 0;
}