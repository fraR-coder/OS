#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

/*Write a program in C language able to:

receive on the command line the path (absolute or relative) of a directory tree
display recursively the contents of this tree (i.e., all files, sub-directories, files in sub-directories, etc.).
Compile the program with gcc and verify its operation comparing the results with the shell command ls -R*/


void print_dir(char* fullName,int* i){
   DIR *dp;
   struct dirent *dirp;
   struct stat buf;
   char path[200];
   
   if (lstat(fullName, &buf) < 0 ) {
      fprintf (stderr, "Error1.\n"); exit (1);
   }

   if ( (dp = opendir(fullName)) == NULL) {
      fprintf (stderr, "Error2.\n"); exit (1);
   }
  
  strcpy(path,fullName);
   
   
   
   while ( (dirp = readdir(dp))!=NULL) { // leggo directory dp
     
     if (strcmp(dirp->d_name, ".") != 0 && strcmp(dirp->d_name, "..") != 0){
     
      strcpy(path,fullName);

      strcat (fullName, dirp->d_name); // aggiorno fullName 
     // fullName[strlen(fullName)]='/';

      lstat(fullName,&buf);

      if (S_ISDIR(buf.st_mode)) {
       fullName[strlen(fullName)]='/';  
      fprintf (stdout, "Dir %d: %s\n", *i, fullName);
      (*i)++;
      print_dir(fullName,i);
      }
      else{
         fprintf (stdout, "File %d: %s\n", *i, fullName);
         strcpy(fullName,path);
         (*i)++;
      }

     }

     

   } 
   closedir(dp);
   print_dir(path,*i);

   return;

}




int main(int argc, char** argv) {
 
   assert(argc==2);
   
   char fullName[200];
  
   strcpy(fullName,argv[1]);

  
   int i=0;

   

   print_dir(fullName,&i);
  
   

   
   
   return 0;
}

