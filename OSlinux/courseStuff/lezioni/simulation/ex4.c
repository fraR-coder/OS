#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define max 100

typedef struct v{
    int *vett;
    int n;
}vett_s;

void stampa_array(int* V,int n) {
  int i;

  for (i=0; i<n; i++) {
    printf("%d ", V[i]);
  }
  printf("\n");
}


int* merge(int* v1, int *v2, int n1 ,int n2){

    int * v=malloc((n1+n2)*sizeof(int));

    int i=0;
    for(i=0;i<n1;i++){
        v[i]=v1[i];
    }
    for(int j=0;j<n1;j++){
        v[i]=v2[i+j];
    }
    return v;

}

void* sort(void * args){
    vett_s * s= (vett_s*) args;
    int n=s->n;
    int *v=s->vett;

    if(s->n==1) pthread_exit(NULL);

    pthread_t t1,t2;
    int *v1;
    int *v2;
    int d=0;
    int n1,n2;
    if(n%2==0){
        v1=malloc((n/2)*sizeof(int));
        v2=malloc((n/2)*sizeof(int));
    }
    else{
        d=1;
        v1=malloc((n/2)*sizeof(int));
    
        v2=malloc((1+n/2)*sizeof(int));
    }


   
    int i=0;
    int j=n/2;
    for(i=0;i<n/2;i++){
        v1[i]=v[i];
        v2[i]=v[j+i];
    }
    if(d==1) v2[i]=v[j+i];

    stampa_array(v1,n/2);
    if(d==1)
    stampa_array(v2,1+n/2);
    else
        stampa_array(v2,n/2);

   
    s->vett=v1;
    s->n=n/2;
    pthread_create(&t1,NULL,sort,(void*)&s);
    
    
    s->vett=v2;
    if(d==1) s->n=1+n/2;
    else s->n=n/2;
    
    pthread_create(&t2,NULL,sort,(void*)&s);

    pthread_join(t1,NULL);
    v1=s->vett;  
    n1=s->n;  
    stampa_array(v1,n1);
    pthread_join(t2,NULL);
    v2=s->vett;
    n2=s->n;
    stampa_array(v2,n2);

    s->vett=merge(v1,v2,n1,n2);


    
  

    pthread_exit(NULL);
}


int main(int argc, char** argv)
{   

    int vett[2]={2,4};
    stampa_array(vett,2);

    pthread_t t;
    vett_s st;
    st.n=2;
    st.vett=vett;
    pthread_create(&t,NULL,sort,(void*)&st);

    pthread_join(t,NULL);

    stampa_array(st.vett,st.n);


    return 0;

}