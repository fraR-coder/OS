#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>  
#include <dirent.h>
#include <string.h>
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
void producer(int fw){
    char s[100];
    printf("inserisci stringhe\n");


    do{
        
        fscanf(stdin,"%s",s);
        

        

        write(fw,s,sizeof(s));

         if(strcmp(s,"end")==0){
            break;
        }
       
        
    }while (strcmp(s,"end")!=0);
   

    
    


   
   
}



void consumer(int fr){
    char c;
    char s[1000];
    int i=0;

while(1){
    read(fr,s,sizeof(s));
     if(strcmp(s,"end")==0){
            break;
        }
   
    for(i=0;i<strlen(s);i++){
        c=s[i];

        if(isalpha(c)){
            c=toupper(c);
        }
        s[i]=c;
        
    }
    
    printf("%s\n",s);
}
    
}





int main(int argc, char** argv)
{
    int pid;
    char s[2000];
    int fd[2];


    
    assert(pipe(fd)==0);
    //0=reading 1=writing
    pid=fork();
    

    if(pid){
       sleep(2);
        //printf("padre pid=%d\n",getpid());
        int pid2=fork();
        if(pid2){
           // printf("pid padre2=%d pid padre del padre2 %d\n",getpid(),getppid());
        }

        else{
            //printf("pid child2 %d pid padre di child2 %d\n",getpid(),getppid());
            producer(fd[1]);

        }


    }
    else{
       // printf("pid child %d  pid parent %d\n",getpid(),getppid());

        consumer(fd[0]);
        
    }
  
   
wait(NULL);

wait(NULL);


    return 0;

}