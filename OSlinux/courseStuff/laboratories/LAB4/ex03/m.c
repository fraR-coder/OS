#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <unistd.h>

#include <string.h>


#define N 20
int main(int argc,char** argv){
    char fileName[N];
    char s[100];
  //  char comandi[100][N];
    char** mat;
	char* p;

    mat=malloc(N*sizeof(char*));
     for (int i=0; i<N; i++) {
    mat[i] = (char *) malloc (100 * sizeof (char));
  }


    
    assert(argc==2);
    assert(argv[1]!=NULL);

    sprintf(fileName,"%s",argv[1]);

   /*   int fin;

         fin=open(fileName,O_RDONLY);
        while(read(fin,s,sizeof(s))>0)
        write(1,s,strlen(s));

    close(fin);*/


/*SYSTEM
   FILE* fin=fopen(fileName,"r");
    int i=0;
    while(fgets(s,100,fin)!=NULL){
        sprintf(comandi[i],"%s",s);

        
        i++;
          
    }
    fclose(fin);
SYSTEM
    for(int j=0;j<i;j++){
        system(comandi[j]);
        
    }
    */



  //EXEC
   FILE* fin=fopen("commands.txt","r");
   assert(fin!=NULL);
    int i=0;
    while(fscanf(fin,"%s",s)!=EOF){
        printf("ho letto : %s\n",s);

        if(strcmp(s,"end")==0){
			p=mat[i];
            mat[i]=NULL;
			
            printf("stampo i comandi nella matrice:\n");
            for(int j=0;j<i;j++){
                printf("%s ",mat[j]);
                }
            printf("\n");  
           /* int pid=fork();
            if(pid==0){
                execvp(mat[0],mat);
            }
            else{
				for(int j=0;j<N;j++){
					free(mat[j]);
				}
				free(mat);
				mat=malloc(N*sizeof(char*));
				for(int j=0;j<N;j++){
				mat[i] = (char *) malloc (100 * sizeof (char));
				}
                i=0;
                sleep(5);
                continue;
            }*/
			 /*for(int j=0;j<N;j++){
					free(mat[j]);
				}
				free(mat);
				mat=malloc(N*sizeof(char*));
				for(int j=0;j<N;j++){
				mat[j] = (char *) malloc (100 * sizeof (char));
				}*/
			 mat[i]=p;	
			 i=0;
			 continue;
        }

        strcpy(mat[i],s);
        printf("matrice linea %d = %s\n",i,mat[i]);

        i++;


    }

  fclose(fin);
for(int j=0;j<N;j++){
	free(mat[j]);
		}
free(mat);


    return 1;
}