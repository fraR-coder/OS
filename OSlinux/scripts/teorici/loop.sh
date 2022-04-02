#!/bin/bash
clear
for ((i = 0; i < 3; i++));
do
	echo "$i"

done

for i in 5 6 4 ciao hola -
do
    echo $i
done

for i in $(echo {30..40})
do 
    echo $i
done

var=0

while [ $var -lt 5 ];do
    echo $var
    let var="var+1"
done

while read row;do
    echo $row
done


exit 0