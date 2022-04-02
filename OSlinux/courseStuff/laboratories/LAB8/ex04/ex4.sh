#!/bin/bash

if [ $# -lt 1 ]
then
    echo "scrivi nome file"
    read name
elif [ $# -gt 1 ]
then
    echo "ma quanta roba hai scritto?"
    exit 1
else
    name=$1
fi

if [ ! -f $name ]
then 
    echo " no file"
fi

#SOLUTION WITH ASSOCIATIVE ARRAY
declare -A vett

for word in $(cat $name)
do
   let vett[$word]=vett[$word]+1
done

for word in ${!vett[*]}
do
    echo "$word: ${vett[$word]}"
done > fout.txt

unset vett
#SOLUTION WITH 2 ARRAYS
i=0

for word in $(cat $name)
do

    j=0
    f=0
    for w in ${vettName[*]}
    do
        
       
        if [ $word = $w ]
        then
            f=1
            let vettFreq[$j]=vettFreq[$j]+1
        fi

        let j=j+1
    done

    if [ $f -eq 1 ];then
    continue
    fi

    
    vettName[$i]=$word
    vettFreq[$i]=1
    let i=i+1
    

done


i=0
while [ $i -lt ${#vettName[*]} ]
do
    echo "${vettName[$i]}: ${vettFreq[$i]}"
    let i=i+1
done


exit 0
