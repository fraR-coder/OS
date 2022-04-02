#!/bin/bash

numArgs=3

#check arguments
if [ $# -ne $numArgs ];then
    echo "numero argomenti richiesto = $numArgs. Numero argomenti inserito = $#"
    exit 1
fi

#check directory
return=$(find . -name "$1")

if [ $? -eq 1 ];then
    echo "error"
    exit 1

elif [ "$return" = '' ];then
    echo "creo directory $1"
    mkdir $1
else
    echo "$1 esiste gia"
fi

#check file
return=$(find . -name "$2")

if [ $? -eq 1 ];then
    echo "error"
    exit 1

elif [ "$return" = '' ];then
    echo "creo file $2"
    touch $2
else
    echo "$2 esiste gia"
fi
directory=$1
file=$2

#check funct in dir

#find $directory -type f -name "*" -exec grep -nH "$3" '{}' ';' > $file



#check funct in file

#grep -nH "$3" $file

#prints (in the screen) the number of characters of the longest line and the number of lines of the file.
echo -n "numero line:"
cat $file | wc -l 
echo "senza spazi nè new line"
while read row
do
    n=$(echo $row | tr -d " " | tr -d "\n" | wc -c) 
    
    echo "$row : $n"
done < $file

echo "trasformo in maiuscolo"
for i in $(cat $2)
do
   echo $i | tr [:lower:] [:upper:] 
done
exit 0