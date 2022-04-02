#!/bin/bash
clear
x=5
y=5
let z="$x + $y"
echo $x $y $z

dir=/bin
rm a.txt
file=a.txt
echo $file

if [ $x -eq $y ];then
    echo "x==y=$x"
elif [ $x -gt $y ];then
    echo "x>y x=$x y=$y"

elif [ $x -lt $y ];then 
    echo "x<y x=$x y=$y"
fi

if [ -d $dir ];then
    echo "is dir"
fi

if [ ! -f $file ];then
    echo "no file"
fi



exit 0