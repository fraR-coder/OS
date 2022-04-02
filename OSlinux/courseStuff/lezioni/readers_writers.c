#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

int nR=0;
sem_t R,W;
typedef struct t{
    char linea[100];
    char nome[50];
}thread_s;

void funzione(){

    return;
}

void* reader(void* args){
    thread_s *s=(thread_s*) args;
    FILE *f=fopen(s->nome,"r");
    char line[100];
    
    
 
        
        sem_wait(&R);
        nR++;
        if(nR==1){
            sem_wait(&W);
        }
        sem_post(&R);


        while(fgets(line,100,f)!=NULL){
            funzione();



            sem_wait(&R);
            nR--;
            if(nR==0){
                sem_post(&W);
            }
            sem_post(&R);
           
        }

  


}
void* writer(void* args){
    thread_s *s=(thread_s*) args;

   
        
        sem_wait(&W);

        printf("%s",s->linea);

        sem_post(&W);
        
    

}

int main(int argc, char** argv)
{
    thread_s t;
    pthread_t vett[2];
    sem_init(&R,0,1);
    sem_init(&W,0,1);

    strcpy(t.nome,argv[1]);

    pthread_create(&vett[0],NULL,reader,(void*)&t);
    
    pthread_create(&vett[1],NULL,writer,(void*)&t);




    pthread_join(vett[0],NULL);
    pthread_join(vett[1],NULL);


    return 0;

}