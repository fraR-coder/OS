#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



void readAndCopy(FILE * fin,FILE *fout){
    
    char s[100];
   // printf("Nome file output: \n");
    //scanf("%s",s);
   
    //if(fout==NULL) exit(2);

    while (fgets(s,100,fin)!=NULL)
    {
        //printf("%s \n",s);
        fprintf(fout,"%s",s);

    }
    


}





int main(int argc , char** argv) {
    FILE *fin;
    FILE *fout;
    
    //printf("Nome file da copiare: \n");
    //scanf("%s",s);
    assert (argc==3);
    assert(argv[1]!=NULL && argv[2]!=NULL);

    fin=fopen(argv[1],"r");
    fout=fopen(argv[2],"w");
    assert(fin!=NULL);
    assert(fout!=NULL);
    //if(fin==NULL) exit(1);
    

   readAndCopy(fin,fout);

   return 0;
}