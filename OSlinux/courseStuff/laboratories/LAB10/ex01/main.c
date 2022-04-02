#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>
#include <semaphore.h>

#define N 50
#define T 3

sem_t C, W, R;
int finish=0;

typedef struct thread{
    FILE* fi,*fo;
    char line[1000];
}tstruct;

void* read_lines(void* args){
    tstruct *s=(tstruct*) args;
    FILE* f=s->fi;
    while(1){
       
        sem_wait(&R);

        if(fgets(s->line,100,f)==NULL){
            finish=1;
            sem_post(&C);
            break;
        }
        
        sem_post(&C);
        
        
    }

    pthread_exit(NULL);
}
void* convert_lines(void* args){
    tstruct *s=(tstruct*) args;
    int i;
    int j;
    while (1){
         
        sem_wait(&C);
        if(finish==1){
            
            sem_post(&W);
            break;
        } 
        char line[100];
        j=0;
        strcpy(line,s->line);

        for(i=(int)strlen(s->line)-2;i>=0;i--){
            s->line[j]=toupper(line[i]);
            j++;
        }
        if(j!=0)
        s->line[j]='\n';
        

        sem_post(&W);
        
    }
    
    pthread_exit(NULL);
}
void* write_lines(void* args){
    tstruct *s=(tstruct*) args;
    FILE* f=s->fo;

    while(1){
       

        sem_wait(&W);
        if(finish==1) break;
       

        fprintf(f,"%s",s->line);
        
        sem_post(&R);
    }

    pthread_exit(NULL);

}

int main(int argc, char** argv)
{   
    //semaphores

    sem_init(&C,0,0);  
    sem_init(&W,0,0);
    sem_init(&R,0,1);

    //files
    assert(argc==3);
    char string1[N], string2[N];
    FILE *fin,*fout;
    strcpy(string1,argv[1]);
    strcpy(string2,argv[2]);
    //printf("1:%s\n2:%s\n",string1,string2);
    fin=fopen(string1,"r");
    fout=fopen(string2,"w");
    assert(fin!=NULL);
    assert(fout!=NULL);

    //threads
    pthread_t *threads=malloc(T*sizeof(pthread_t));
    tstruct *s=malloc(T*sizeof(tstruct));

    s[0].fi=fin;s[0].fo=fout;
    pthread_create(&threads[0],NULL,read_lines,(void*)&s[0]);
    

    pthread_create(&threads[1],NULL,convert_lines,(void*)&s[0]);

    pthread_create(&threads[2],NULL,write_lines,(void*)&s[0]);
        


    for(int i=0;i<T;i++){
        pthread_join(threads[i],NULL);
    }
    fclose(fin);
    fclose(fout);

    return 0;

}