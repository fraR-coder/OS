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
#include <pthread.h>

#define N 5
#define FLAG -1

struct tS {
int tid;
char * fin;
int * vett;
};

void sort(int *v,int n){
	int val,i,j;

	for (i=0; i<n-1; i++) {
  		for (j=0; j<n-1-i; j++) {
    		if (v[j] > v[j+1]) {
       			val = v[j];
       			v[j] = v[j+1];
      			v[j+1] = val;
   			}
  		}
	}
}

void* funzione(void *par) {
	int id;
	struct tS *td;
	FILE *fin;
	td=(struct tS*) par;
	id=td->tid;
	fin=fopen(td->fin,"r");
	assert(fin!=NULL);
	
	td->vett=malloc(N*sizeof(int));
	for(int i=0;i<N;i++){
		fscanf(fin,"%d\n",&td->vett[i]);
		//printf("ho letto %d\n",vett[i]);
	}
	sort(td->vett,N);
	

fclose(fin);


pthread_exit(NULL);
}


void unisci(int *a, int* b){
	//b è quello lungo
	//trovo la fine di b
	int i=0;
	while(b[i]!=FLAG) i++;

	for(int j=0;j<N;j++){
		b[i]=a[j];
		i++;
	}


}

int main(int argc, char** argv)
{
    assert(argc==4);
    int n=atoi(argv[1]);
	int i;
    char** filesIn;
	FILE* fileOut;

	filesIn=(char**)malloc(n*sizeof(char*));
	fileOut=fopen(argv[3],"w");

	pthread_t *threads=malloc(n*sizeof(pthread_t));
	assert(threads!=NULL);
	struct tS *vt=malloc(n*sizeof(struct tS));
	assert(vt!=NULL);
	void *exitstatus;


	i=0;
	char *nome=strtok(argv[2],",");
	filesIn[i]=nome;
	do{
		i++;
		nome=strtok(NULL,",");
		if(nome==NULL) break;
		filesIn[i]=nome;
	}while(nome!=NULL);
	
	


	for(i=0;i<n;i++){
		printf("entro nel for per i=%d\n",i);
		vt[i].tid=i;
		vt[i].fin=filesIn[i];
		assert(vt[i].fin!=NULL);
		printf("tid=%d\n",vt[i].tid);

		pthread_create(&threads[i],NULL,funzione,(void *) &vt[i]);


	}
	
	int *sorted=malloc((n*N)*sizeof(int));
	for(i=0;i<n*N;i++){
		sorted[i]=FLAG;
	}
	int *tmp;
	for(i=0;i<n;i++) {
		pthread_join (threads[i] , &exitstatus );
		tmp=vt[i].vett;
		unisci(tmp,sorted);
		sort(sorted,(i+1)*N);
				
				

	}

	for(i=0;i<n*N;i++){
		fprintf(fileOut,"%d\n",sorted[i]);
	}
	free(threads);
	free(vt);
	free(sorted);
	free(tmp);
	fclose(fileOut);





	
    return 0;

}