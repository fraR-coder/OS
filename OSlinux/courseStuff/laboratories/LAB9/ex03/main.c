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

sem_t a,bcd,ef,g,h,i;


void* pA(void* arg){
    sem_wait(&a);
    printf("    A\n");
    sem_post(&bcd);
    sem_post(&bcd);
    sem_post(&bcd);

   pthread_exit(NULL);
}

void* pB(void* arg){
    sem_wait(&bcd);
    sleep(1);
    printf("B   ");
    sem_post(&i);
   pthread_exit(NULL);
}

void* pC(){ 
       
    sem_wait(&bcd);
    sleep(2);
    printf("C   ");
    sem_post(&ef);
    sem_post(&ef);
    pthread_exit(NULL);
}
void* pD(){
    sem_wait(&bcd);
    sleep(3);
    printf("D\n");
    sem_post(&h);
    
    pthread_exit(NULL);
}
void* pE(){
  
    sem_wait(&ef);
    sleep(2);
    printf("  E  ");
    
    sem_post(&g);
    pthread_exit(NULL);
}
void* pF(){
   
    sem_wait(&ef);
    sleep(3);
    printf(" F  \n");
    sem_post(&g);
    pthread_exit(NULL);
}
void* pG(){
      sem_wait(&g);
      sem_wait(&g);
      sleep(1);
      printf("    G   ");
      sem_post(&i);
      pthread_exit(NULL);
}
void* pH(){
    sem_wait(&h);
    sleep(4);
    printf("H\n");
    sem_post(&i);
    pthread_exit(NULL);
}
void* pI(){
    sem_wait(&i);
    sem_wait(&i);
    sem_wait(&i);
    sleep(1);
    printf("    I\n");
    
    sem_post(&a);
    
    pthread_exit(NULL);

}

int main(int argc, char** argv)
{   
    int n=9;
    pthread_t *threads=malloc(n*sizeof(pthread_t));
    int j;
    sem_init(&a,0,1);
    sem_init(&bcd,0,0);
    sem_init(&ef,0,0);
    sem_init(&g,0,0);
    sem_init(&h,0,0);
    sem_init(&i,0,0);

    while(1){
        printf("-----------------------------\n");
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

        
    }
   
    

    return 0;

}