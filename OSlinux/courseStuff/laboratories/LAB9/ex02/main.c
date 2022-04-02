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


// processes, uso pipes
int* a, *bcd, *ef, *g, *i, *h; 

int* semInit(int* S){
    S=malloc(2*sizeof(int));
    pipe(S);
    return S;
}

void semSignal(int* S){
    char x='x';
    if(write(S[1],"x",sizeof(char))!=1){
        printf("error");
        exit(1);
    }
}

void semWait(int* S){
    char x;
    if (read(S[0],&x,sizeof(char))!=1){
        printf("error");
        exit(1);
    }
}

void semDestroy(int* S){
    free(S);
}


void pA(){
    
    semWait(a);
    sleep(1);
    printf("    A\n");
    semSignal(bcd);
    semSignal(bcd);
    semSignal(bcd);

    exit(0);
}
void pB(){

    semWait(bcd);
    sleep(1);
    printf("B   ");
    semSignal(i);
    exit(0);   
    
}
void pC(){ 
       
    semWait(bcd);
    sleep(2);
    printf("C   ");
    semSignal(ef);
    semSignal(ef);
    exit(0);
}
void pD(){
    semWait(bcd);
    sleep(3);
    printf("D\n");
    sleep(3);
    semSignal(h);
    exit(0);
}
void pE(){
  
    semWait(ef);
    sleep(2);
    printf("  E  ");
    
    semSignal(g);
    exit(0);
}
void pF(){
   
    semWait(ef);
    sleep(3);
    printf(" F  \n");
    semSignal(g);
    exit(0);
}
void pG(){
      semWait(g);
      semWait(g);
      sleep(1);
      printf("    G   ");
      semSignal(i);
      exit(0);
}
void pH(){
    semWait(h);
    sleep(1);
    printf("H\n");
    semSignal(i);
    exit(0);
}
void pI(){
    semWait(i);
    semWait(i);
    semWait(i);
    sleep(1);
    printf("    I\n");
    
    semSignal(a);
    

}

int main(int argc, char** argv)
{   
    int pIDA,pIDB,pIDC,pIDD, pIDE,pIDF,pIDG,pIDH;

    a=semInit(a);
    bcd=semInit(bcd);
    ef=semInit(ef);
    g=semInit(g);
    h=semInit(h);
    i=semInit(i);

    semSignal(a);

while(1){
    printf("-----------------------------------------------------\n");
       pIDA=fork();
    if (pIDA!=0) {
       pIDB=fork();
       if (pIDB!=0) {
         pIDC=fork(); 
         if (pIDC!=0) {
              pIDD=fork();
              if (pIDD!=0) {
                  pIDH=fork();
                  if (pIDH!=0) {
                      pI();
                    } else
                      pH();    
               } else
                pD();   
           }else {
                pIDE=fork();
                if (pIDE!=0)
                   pC();
                else {
                      pIDF=fork();
                      if (pIDF!=0) {
                         pE();  
                       } else {
                            pIDG=fork();
                            if (pIDG!=0)  
                                pF();
                            else pG(); 
                          }     
                   }   
            }   
          }else
            pB();                        
    }else pA();
}





    return 0;
}