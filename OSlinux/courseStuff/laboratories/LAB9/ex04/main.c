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
#include <semaphore.h>
#include <pthread.h>

//      A  <--------
//   /  |  \       ^
//  /   |   \      |
// B    C    D     |
// |   / \   |     |
// |  /   \  |     |
// | E    F  |     |
// |  \   /  |     |
// |   \ /   |     |
// |    G    H     |
//  \   |   /      |
//   \  |  /       |
//      I  ---------


// threads

sem_t a,b,c,d,e,f,g,h,i;


void* pA(void* arg){
    while (1){

    sem_wait(&a);
    printf("-----------------------------\n");
    printf("    A\n");
    sem_post(&b);
    sem_post(&c);
    sem_post(&d);

    }
}

void* pB(void* arg){
    while(1){
    sem_wait(&b);
    sleep(1);
    printf("B   ");
    sem_post(&i);
   }
}

void* pC(){ 
     while(1){  
    sem_wait(&c);
    sleep(2);
    printf("C   ");
    sem_post(&e);
    sem_post(&f);
    }
}
void* pD(){
     while(1){  
    sem_wait(&d);
    sleep(3);
    printf("D\n");
    sem_post(&h);
    
    }
}
void* pE(){
   while(1){  
    sem_wait(&e);
    sleep(2);
    printf("  E  ");
    
    sem_post(&g);
    }
}
void* pF(){
    while(1){  
    sem_wait(&f);
    sleep(3);
    printf(" F  \n");
    sem_post(&g);
    }
}
void* pG(){
     while(1){  
      sem_wait(&g);
      sem_wait(&g);
      sleep(1);
      printf("    G   ");
      sem_post(&i);
      }
}
void* pH(){
     while(1){  
    sem_wait(&h);
    sleep(4);
    printf("H\n");
    sem_post(&i);
    }
}
void* pI(){
     while(1){  
    sem_wait(&i);
    sem_wait(&i);
    sem_wait(&i);
    sleep(1);
    printf("    I\n");
    
    sem_post(&a);
    
    }

}

int main(int argc, char** argv)
{   
    int n=9;
    pthread_t *threads=malloc(n*sizeof(pthread_t));
    int j;
    sem_init(&a,0,1);
    sem_init(&b,0,0);
    sem_init(&c,0,0);
    sem_init(&d,0,0);
    sem_init(&f,0,0);
    sem_init(&e,0,0);
    sem_init(&g,0,0);
    sem_init(&h,0,0);
    sem_init(&i,0,0);

    
        
        pthread_create(&threads[0],NULL,pA,NULL);
        pthread_create(&threads[1],NULL,pB,NULL);
        pthread_create(&threads[2],NULL,pC,NULL);
        pthread_create(&threads[3],NULL,pD,NULL);
        pthread_create(&threads[4],NULL,pE,NULL);
        pthread_create(&threads[5],NULL,pF,NULL);
        pthread_create(&threads[6],NULL,pG,NULL);
        pthread_create(&threads[7],NULL,pH,NULL);
        pthread_create(&threads[8],NULL,pI,NULL);

        for(j=0;j<n;j++)    
        pthread_join(threads[j],NULL);

        
    
   
    

    return 0;

}