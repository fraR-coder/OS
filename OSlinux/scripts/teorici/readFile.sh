#!/bin/bash
rm in.txt
touch in.txt
echo -e "ciao come\nva\nhola mundo 123 yee 5\n..r" >in.txt

#righe 
while read row;do
    echo $row
done<in.txt

#caratteri
while read -n 1 char;do
    echo $char
done<in.txt

#word
for word in $(cat);do
    echo $word
done<in.txt

echo
#in vettore
i=0
for word in $(cat);do
    
    vett[$i]=$word    
    let i=i+1
done<in.txt

w=0
while [ $w -lt ${#vett[*]} ]
do
    echo $w : ${vett[$w]}
    let w=w+1

done

exit 0