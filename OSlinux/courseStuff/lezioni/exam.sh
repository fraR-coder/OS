#!/bin/bash
#check args
#parse is $1, if it is $0 would be 6 args ad all shift to left
if [ $# -ne 7 ];then
 echo error
 exit 1
fi

i=0
while read line;do
    i=0
    while [ $i -lt $5 ];do
        echo -n "$6 "
        let i=i+1
    done
        #echo -n "$line "
        echo -n "$line" | tr "$3" "$4" # subsitute strings
        #padding
        i=0
    while [ $i -lt $5 ];do
        echo -n "$6 "
        let "i=i+1"
    done
        echo
done <$2 >>$7 #input da $2 , append output su $7
exit 0
