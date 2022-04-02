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

void producer(char* nomeFile){
    char s[100];
    printf("inserisci stringhe\n");

    FILE* file=fopen(nomeFile,"r");
    assert(file!=NULL);


    int targetPid;
    fscanf(file,"%d",&targetPid);
    fclose(file);

    file=fopen(nomeFile,"w");


    do{
        
        fscanf(stdin,"%s",s);
         

        if(strcmp(s,"end")==0){
            break;
        }
       

       fprintf(file,"%s",s);   
        
    }while (strcmp(s,"end")!=0);
    fclose(file);

    printf("ora mando segnale\n");
    

    kill(targetPid,SIGUSR1);

   
   
}



void consumer(char * nomeFile){
    char c;
    char s[1000];
    int i=0;

    FILE* file=fopen(nomeFile,"w");
    assert(file!=NULL);

    int pid=getpid();
    printf("pid to kill = %d",pid);
    fprintf(file,"%d\n",pid);
    fclose(file);

    printf("consumer sta aspettando\n");
    pause();
    printf("consumer partito\n");

     file=fopen(nomeFile,"r");


    do{
        c=fgetc(file);
        if(c==EOF) break;

        if(isalpha(c)){
            c=toupper(c);
        }
        s[i]=c;
        i++;
           
    }while(c!=EOF);
    
    fclose(file);
    file=fopen(nomeFile,"w");
   
    fprintf(file,"%s",s);
    fclose(file);
    
    
}

void mySig(int sig){

    //printf("myyy signaaal aaaa \n");
    return;
}



int main(int argc, char** argv)
{
    int pid;
    int sig;
    assert(argc==2);
    char s[2000];
    if (signal(SIGUSR1, mySig) == SIG_ERR) {
        fprintf (stderr, "Signal Handler Error.\n");
        return (1);
    }

    
    
    pid=fork();
    

    if(pid){
       sleep(2);
        printf("padre pid=%d\n",getpid());
        int pid2=fork();
        if(pid2){
            printf("pid padre2=%d pid padre del padre2 %d\n",getpid(),getppid());
        }

        else{
            printf("pid child2 %d pid padre di child2 %d\n",getpid(),getppid());
            producer(argv[1]);

        }





    }
    else{
        printf("pid child %d  pid parent %d\n",getpid(),getppid());
        consumer(argv[1]);
        
    }
  
   
wait(NULL);

wait(NULL);


    return 0;

}