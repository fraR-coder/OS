#!/bin/bash
clear

read v
echo $v

read 
echo $REPLY

read a b c #ciao come va io sono francesco
echo $a #ciao
echo $b #come
echo $c #va io mi chiamo francesco
w
read -n 5 -t 3 d #legge 5 char entro 3 secondi
echo $d


exit 0