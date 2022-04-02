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


void child(int fd, int j){
int a,b;

                lseek(fd,j*sizeof(int),SEEK_SET);
                read (fd, &a, sizeof (int));
                printf("letto %d\n",a);
               // lseek (fd, (j+1)*sizeof (int), SEEK_SET);
                read (fd, &b, sizeof (int));
                printf("letto %d\n",b);
                

                 if(a>b){
                    lseek(fd,j*sizeof(int),SEEK_SET);
                    write(fd,&b,sizeof(int));
                    printf("scritto %d\n",a);
                    //lseek (fd, (j+1)*sizeof (int), SEEK_SET);
                    write(fd,&a,sizeof(int));
                    printf("scritto %d\n",b);
                    
                }
                return;
                

}


int main(int argc, char** argv)
{
    assert(argc==2);
    assert(argv[1]!=NULL);

    int i,j,c,v,a,b;
    int vet[n] = {0, 10, 5, 20, 1, 3};

    char *name=argv[1];
    //printf("%s\n",name);

    int fd=open(name,O_RDWR|O_CREAT);
    //printf("%d",fd);

    printf("nel vettore:\n");
    for (i=0; i<n; i++) {
        write (fd, &vet[i], sizeof (int));

        fprintf (stdout, "%d ", vet[i]);
    }
   
    printf("\n");
    printf("nel file:\n");

    for (i=0; i<n; i++) {
        lseek (fd, i*sizeof (int), SEEK_SET);
        read (fd, &v, sizeof (int));
    
        fprintf (stdout, "%d ", v);
    }
  fprintf (stdout, "\n");

 

    for (i=0; i<n-1; i++) {
        for (j=0; j<n-1-i; j++) {
            pid_t pid=fork();

            if(pid){

                wait(NULL);
                
            }
            else{
               lseek(fd,j*sizeof(int),SEEK_SET);
                read (fd, &a, sizeof (int));
                //printf("letto %d\n",a);
                lseek (fd, (j+1)*sizeof (int), SEEK_SET);
                read (fd, &b, sizeof (int));
                //printf("letto %d\n",b);
                

                 if(a>b){
                    lseek(fd,j*sizeof(int),SEEK_SET);
                    write(fd,&b,sizeof(int));
                    //printf("scritto %d\n",a);
                    lseek (fd, (j+1)*sizeof (int), SEEK_SET);
                    write(fd,&a,sizeof(int));
                    //printf("scritto %d\n",b);
                    
                }
                exit(1);
            }
        }
    }


for (i=0; i<n; i++) {
        lseek (fd, i*sizeof (int), SEEK_SET);
        read (fd, &v, sizeof (int));
    
        fprintf (stdout, "%d ", v);
    }
  fprintf (stdout, "\n");

  
close(fd);
    return 0;

}