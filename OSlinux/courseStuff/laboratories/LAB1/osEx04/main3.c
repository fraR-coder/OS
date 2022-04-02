#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>



void readAndCopy(int fin,int fout){
    
    char s[1000];
   // printf("Nome file output: \n");
    //scanf("%s",s);
   
    //if(fout==NULL) exit(2);
	while(read(fin,s,sizeof(s))>0)
	    write(fout,s,strlen(s));
        //fprintf(fout,"%s",s);
  

    
    


}





int main(int argc , char** argv) {
    int fin,fout;
    
    //printf("Nome file da copiare: \n");
    //scanf("%s",s);
    assert (argc==3);
    assert(argv[1]!=NULL && argv[2]!=NULL);

    fin=open(argv[1],O_RDONLY);
    fout=open(argv[2],O_RDWR|O_CREAT);
    assert(fin!=-1);
    assert(fout!=-1);
    //if(fin==NULL) exit(1);
    

   readAndCopy(fin,fout);

   return 0;
}