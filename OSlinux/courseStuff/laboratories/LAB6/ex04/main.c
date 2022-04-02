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
    1)sort -n -r file.txt > file1.txt
    2)sort -k 2 file.txt > file2.txt
    3)egrep "2011/2012"
    4)grep "INF1T3" file.txt | sort -n -k 1 >file4.txt
    5)grep -e "^[0-9]*2\> " -e "^[0-9]*4\> " file.txt | sort -k 2,2 >file5.txt
    6)grep -e "TLC1T3" -e "Da frequentare" file.txt | sort -k2,2   >file6.txt
    7)grep "A..A" file.txt >file7.txt
    8)grep -e "A..A" file.txt | grep -v "A\<" | grep -v "A\>"
    9)cut -c 1-6 file.txt | tr -d "0" | tr "8" "1"| sort -n |uniq >file9.txt
    10)cut -d ' ' -f 1 file.txt | tr -d 0 | tr 8 1 | sort -n | uniq -d >file10.txt

*/
    return 0;



}