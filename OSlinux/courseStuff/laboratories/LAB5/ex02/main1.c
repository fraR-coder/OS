#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>  
#include <dirent.h>
#include <string.h>

#define n 6
int main(int argc, char** argv)
{
    assert(argc==2);
    assert(argv[1]!=NULL);

    int i,j,val;
    int vet[n] = {1,9,4,2,0,3};

    char *name=argv[1];
    //printf("%s\n",name);

    int fd=open(name,O_RDWR|O_CREAT);
   
    for (i=0; i<n; i++) {
        write (fd, &vet[i], sizeof (int));
        fprintf (stdout, "%2d ", vet[i]);
  }
   
   close(fd);
  fprintf (stdout, "\n");

 fd=open(name,O_RDWR);

    for (i=0; i<n; i++) {
        lseek (fd, i*sizeof (int), SEEK_SET);
        read (fd, &val, sizeof (int));
    
        fprintf (stdout, "%d ", val);
    }
  fprintf (stdout, "\n");

 
    return 0;

}