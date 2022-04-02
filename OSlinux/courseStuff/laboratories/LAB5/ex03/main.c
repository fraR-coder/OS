#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>  
#include <dirent.h>
#include <string.h>
#include <signal.h>

void child(pid_t pid){
    
    fprintf (stdout, "Child Running: pid=%d, fatherPid=%d\n",getpid (), pid);

    while(1){
        
        printf("child woke up\n");
        sleep(2);
        kill(pid,SIGUSR1);
        pause();
    }
}



void father(pid_t pid){

    fprintf (stdout, "Father Running: pid=%d, childPid=%d\n",  getpid (), pid);
    while(1){
        pause();
        printf("father woke up\n");
        sleep(2);
        kill(pid,SIGUSR1);
    }


}

void mySig(int sig){

    //printf("myyy signaaal aaaa \n");
    return;
}

int main(int argc, char** argv)
{
    pid_t pid;
    int sig;

    if (signal(SIGUSR1, mySig) == SIG_ERR) {
        fprintf (stderr, "Signal Handler Error.\n");
        return (1);
    }



    pid=fork();

    if(pid==0){
        child(getppid());
    }
    else{
       father(pid);
    }
   




    return 0;

}