#!/bin/bash
if [ $# -ne 1 ]
then
    echo "metti il nome di una directory"
    exit 1
fi


if [ ! -d $1 ]
then
  echo "no dir"
  exit 1

fi



for i in $(ls $1)
do
 
  
  mv $1/$i $1/$(echo $i | tr [:upper:] [:lower:])
  

done 





exit 0