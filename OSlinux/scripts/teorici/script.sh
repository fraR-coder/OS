#!/bin/bash
dir=$1
#shift spsoto a sx argv
if [ $# -le 1 ]
then 
    echo "Run $0 dir .."
    exit 1
fi

#mkdir -p $1
if [ ! -d $1 ]
then
    echo "creo direcory $1"
    mkdir $1
fi 

for i in $* 
do
    if [ $i != $1 ]
    then
        echo -n "$i in $1 si o no ?"
        read choice
        if [ $choice = "si" ] ; then 
        cp $i $1
        if [ $? ]
        then 
            echo "ho copiato $i in $1"
        else
            echo "errrore"
        fi
        fi
    fi
done


exit 0