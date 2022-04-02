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

int main(int argc, char** argv)
{
/*
Print the list of the files in the tree with root / that have extension “.exe”, dimension greater than 1024 bytes, and that they are executable.
    find . -regex ".*\.exe" -executable -size +1024

Print the path of all the files with extension “.c”, and with a dimension of 100 bytes.
    find . -regex ".*\.c" -size 100

Print all the files of your user, of regular type, that contain in the name at least one
a and at least one A in an undefined order (i.e., a…A or A…a). Of these files print the last 3 lines.
    find . -type f  -name "*A*a*" -or -name "*a*A*" -exec tail -n 3 '{}' \;
    find . -type f -regextype posix-extended -regex "(.*A.*a.*)|(.*a.*A.*)" -exec tail -n 3 '{}' \;

Print all the files of your user from the level of depth 3 to the level of depth 5, with a dimension of at least 250 bytes, and with the name of
exactly 4 characters. Of these files count the number of characters. Repeat the same operation counting the number of rows.
    find -mindepth 3 -maxdepth 5 -user francesco -size +249c -name "????" -type f -exec wc -c '{}' \;
    find / -mindepth 3 -maxdepth 5 -user francesco -size +249c -regex ".*\/...." -type f -exec wc -c '{}' \;

Print all the files in the system with an extension of 3 characters, with the name beginning with an A and with 3 consecutive z.
Of these files create a compressed version
    find . -name "Azzz.???" -exec gzip '{}' \;
    find / -regex ".*A.*zzz.*\...." -exec tar -zcvf '{}'.tar.gz '{}' \;

Print the content of all the directories, starting from the root of the file system, and with name bin.
    find . -type d -name "bin" -exec ls '{}' \;
    find . -type d -regex ".*\/bin" -exec ls '{}' \;

Find all the files with the extension .c of the other users (excluding your user!), and belonging to your group.
find / -name "?*.c" ! -user francesco 

Modify the permissions of all your files in the first level of the sub-tree of the root of the file system,
so that all users other than the owner have no permission.

    find / -maxdepth 1 -user francesco -exec chmod go-xrw '{}' \; 



*/
    return 0;

}