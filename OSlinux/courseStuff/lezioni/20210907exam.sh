#!/bin/bash

if [ $# -lt 1 ];then
    echo "serve almeno un file "
    exit 1
fi

#check existance
#if [ ! -f $i ]

n=0
for i in $*;do
    return=$(find . -name "$i")
    if [ "$return" = "" ];then
        echo "file $1 non esiste"
        exit 1
    fi
    if [ -f $i ];then
        ls -l $i | tr -s " " | cut -d " " -f 9,5,1
        r=$(ls -l $i | tr -s " " | cut -d " " -f 1 | cut -c 2)
        w=$(ls -l $i | tr -s " " | cut -d " " -f 1 | cut -c 3)
        if [ "$r" = "r" -a "$w" = "w" ];then
            echo "possiede le autorizzazioni"
        fi
    elif [ -d $i ];then
    echo "stampo directory"
        for d in $(ls -l $i);do
            if [ -d $d ];then
                let n=n+1
                echo "$d"
            fi
        done
        echo "numero directory= $n"
    fi
done




exit 0