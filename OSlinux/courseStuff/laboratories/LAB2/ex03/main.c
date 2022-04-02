#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>


void copyRecursevly(char *src,char*dest);


int main(int argc, char** argv)
{
    // Directory path to list files
    char src[100];
    char dest[100];

    // Input path from user
    assert(argc==3);
   
   sprintf(src,"%s",argv[1]);
   sprintf(dest,"%s",argv[2]);


    copyRecursevly(src,dest);

    return 0;
}


/**
 * Lists all files and sub-directories recursively 
 * considering path as base path.
 */
void copyRecursevly(char *src,char*dest)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(src);
    

    // Unable to open directory stream
    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            printf("%s\n", dp->d_name); //per la stampa


            // Construct new path from our base path
            strcpy(path, src);
            strcat(path, "/");
            strcat(path, dp->d_name);
            
            listFilesRecursively(path);
        }
    }

    closedir(dir);
}

