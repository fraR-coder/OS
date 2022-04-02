#!/bin/bash
if [ $# -ne 1 ]
then
    echo "metti il nome di un file daii "
    exit 1
fi


if [ ! -f $1 ]
then
    echo "no file"
    exit 1
fi

countC=0
max=0
numL=0



#while read -n 1 c
#do
#    
#    
#    if [ -z $c ]
#    then
#        
#        if [ "$countC" -gt "$max" ]
#        then
#            max=$countC
#        fi
#
#        countC=0
#        let numL=numL+1
#        continue
#    fi
#    let countC=countC+1
#
#done < $1
#
#echo -e "numero line =$numL\\nla riga più lunga è di $max caratteri"

max=0
aux=0
i=0
while read var
do
  aux=${#var}
  echo "aux = $aux"
  echo "vettore :     $var"
  if test $aux -gt $max 
  then
    max=$aux		
  fi	
  i=$((i+1))
done < $1 






exit 0