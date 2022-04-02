#!/bin/bash
if [ $# -ne 3 ]
then
    echo "ciao ciao "
    exit 1
fi

if [ ! -d $1 ]
then
    echo "no dir"
    exit 1
fi
if [ ! -f $3 ]
then
    echo "no file"
    exit 1
fi

rm $3
funct="$2"
let i=1

find $1 -type f -exec  grep -nH $2 \{} \; > tmp1.txt
sort -t ':' -k 1 -k 2 tmp1.txt > $3
rm tmp1.txt


#for f in $(ls);
#do
#    if [ -f $f -a $f != "ex1.sh" -a $f != "$3" ]
#    then
#         
#        grep -nH "$funct" "$f" | sort -t ':' -k 1 -k 2
#
#
#    fi
#done >$3



exit 0