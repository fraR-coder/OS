#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <unistd.h>

#include <string.h>


#define N 100





int main(int argc,char** argv){
    int n[N];
    int i=0;
  
// run >fileOut.txt <fileIn.txt 2>errFile.txt
    while(fscanf(stdin,"%d",&n[i])){
        i++;
        if(n[i-1]==0) break;
       
    }

 


    for(int j=0;j<i;j++){
        if(n[j]%2==0)
        fprintf(stdout,"OUT:%d\n",n[j]);
        else
        fprintf(stderr,"ERR:%d\n",n[j]);
    }

    return 0;
}