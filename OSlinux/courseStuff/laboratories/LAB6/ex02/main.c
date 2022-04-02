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

#define N 200

int main(int argc, char** argv)
{

    int pid;
    int fd1[2];
    int fd2[2];
    int a=0;
    char s[]="stringa";
    pipe(fd1);
    pipe(fd2);
    pid=fork();   
    if(pid){
        //father
        close(fd2[1]);
        close(fd1[0]);
        while(a<5){
            printf("Father PID : %d\n",getpid());
            write(fd1[1],s,sizeof(s));
            a++;
            read(fd2[0],s,sizeof(s));
        }
        strcpy(s,"end");
    }
    else{
        //child
        close(fd2[0]);
        close(fd1[1]);
        printf("entrato nel child\n");
        
        while(1){
            if(strcmp(s,"end")){
                exit(0);
            } 
            read(fd1[0],s,sizeof(s));
            printf("Child PID : %d\n",getpid());
            write(fd2[1],s,sizeof(s));
        }
    }
    
    wait(NULL);

    return 0;

}