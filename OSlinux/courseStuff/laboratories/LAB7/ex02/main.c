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


struct tS {
int tid;
FILE * fin, *fout;
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
	FILE *fin,*fout;
	td=(struct tS*) par;
	id=td->tid;
	fin=td->fin;
	fout=td->fout;

	int N,*vett;

	fscanf(fin,"%d\n",&N);
	fprintf(fout,"%d\n",N);
	printf("N=%d\n",N);
	vett=malloc(N*sizeof(int));
	for(int i=0;i<N;i++){
		fscanf(fin,"%d\n",&vett[i]);
		//printf("ho letto %d\n",vett[i]);
	}
	sort(vett,N);
	for(int i=0;i<N;i++){
		fprintf(fout,"scrivo %d\n",vett[i]);
	}
	free(vett);

fclose(fin);
fclose(fout);

pthread_exit(NULL);
}

int main(int argc, char** argv)
{
    assert(argc>1);
    int n=atoi(argv[1]);
    assert(argc==((n*2)+2));
	int i,j;
    FILE** filesIn, **filesOut;

	filesIn=(FILE**)malloc(n*sizeof(FILE*));
	filesOut=(FILE**)malloc(n*sizeof(FILE*));
	pthread_t *threads=malloc(n*sizeof(pthread_t));
	assert(threads!=NULL);
	struct tS *v=malloc(n*sizeof(struct tS));
	assert(v!=NULL);
	void *exitstatus;

	for(i=0;i<n;i++){
		filesIn[i]=fopen(argv[i+2],"r");
		assert(filesIn[i]!=NULL);
	}
	
	for( j=0;j<n;j++){
		filesOut[j]=fopen(argv[i+2+j],"w");
		assert(filesOut[j]!=NULL);

	}

	for(i=0;i<n;i++){
		printf("entro nel for per i=%d\n",i);
		v[i].tid=i;
		v[i].fin=filesIn[i];
		v[i].fout=filesOut[i];
		assert(v[i].fin!=NULL);
		assert(v[i].fout!=NULL);
		printf("tid=%d\n",v[i].tid);

		pthread_create(&threads[i],NULL,funzione,(void *) &v[i]);


	}


	for(i=0;i<n;i++) {
		pthread_join (threads[i] , &exitstatus ); 
	}
	free(threads);
	free(v);






	
    return 0;

}