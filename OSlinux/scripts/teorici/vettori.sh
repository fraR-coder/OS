#!/bin/bash

A[0]=5
A[1]=ciao

A[10]=76

B=(ciao 34 beta 23)
echo ${#A[*]}
echo ${#B[*]}
echo ${A[*]}
echo ${B[*]}

echo ${B[1-2]}

echo ${#B[1]}

unset B[0]
unset A
unset B

#associative
declare -A vett1

vett1[stefano]=3
nome=giulia
vett1[$nome]=pippo
vett1[0]=ciao
vett1[fra]=56
vett1[re43]=weee

echo ${vett1[stefano]}  # Prints 3
echo ${vett1["giulia"]} # Prints pippo
echo ${#vett1[*]}       # Prints 2
echo ${vett1[*]}        # Prints pippo 3
echo ${!vett1[*]}       # Prints giulia stefano

sum=0
for name in ${!vett1[*]}
do
    let sum="${vett1[$name]}+$sum"      #pippo vale 0
done
echo "Sum: $sum"

for i in ${vett1[*]}
do
    elenco="$elenco + $i"
done
echo $elenco

elenco=''

for name in ${!vett1[*]}
do
    elenco="$elenco + $name"
done
echo $elenco

exit 0
