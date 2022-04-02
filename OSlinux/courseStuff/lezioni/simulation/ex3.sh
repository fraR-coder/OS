#!/bin/bash

#check args
if [ $# -ne 2 ];then
    echo "error in args"
    exit 1
fi

if [ ! -d "$2" ];then
    echo "no dir"
    exit 1
fi

string="\*\*\*Da modificare"
echo $string
for i in $(find "$2" -user "$1" -type f);do
    
   
    grep -e "^$string" $i
    if [ "$?" -eq 0 ];then
        touch out.txt
        grep -v "^$string" $i > out.txt
        mv out.txt "$i"_mod
        rm $i
    fi

   
done

    

    


    


exit 0