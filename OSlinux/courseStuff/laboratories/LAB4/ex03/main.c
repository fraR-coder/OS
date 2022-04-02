#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <unistd.h>

#include <string.h>


#define N 100

void freeMat(char** mat,int n){
    for(int i=0;i<n;i++){
        if(mat[i]!=NULL)
            free(mat[i]);

    }
    free(mat);
}

char** allocaMat(char** mat,int n){
    mat=(char**)malloc(n*sizeof(char*));
    for(int i=0;i<n;i++){
        mat[i]=malloc(N*sizeof(char));
    }
    return mat;
}

int conta_comandi(FILE* fin,char linea[]){
    int n=0;
    char s[N];
    
    if(fgets(linea,N,fin)==NULL)
        return -1;
    printf("%s\n",linea);

    do{
        sscanf(linea,"%s",s);
        int len=strlen(s);
		linea=&linea[len+1];
        n++;
    }
    while(strcmp(s,"end")!=0);

    return n;

}



int main(int argc,char** argv){
    char fileName[N];
     char s[N];
  //  char comandi[100][N];
    char** mat;
	char* p;
    int num_arg=0;

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

    do{
        num_arg=conta_comandi(fin,s);
        if(num_arg==-1) break;
        p=s;
        printf("ho letto : %s\n",s);
        mat=allocaMat(mat,num_arg);

        for(i=0;i<num_arg;i++){
            sscanf(p,"%s",mat[i]);
            printf("matrice linea %d = %s\n",i,mat[i]);
            int len=strlen(mat[i]);
		    p=&p[len+1];
        }
        mat[i-1]=NULL;
        printf("stampo i comandi nella matrice:\n");
        for(int j=0;j<num_arg;j++){
            printf("%s ",mat[j]);
        }
        printf("\n");  

        int pid=fork();
            if(pid==0){
                execvp(mat[0],mat);
            }
            else{
                
                freeMat(mat,num_arg);
                sleep(5);
                }
    }
    while(num_arg!=-1);
       

       
fclose(fin);


    return 0;
}