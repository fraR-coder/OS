#!/bin/bash
if [ $# -ne 2 ];then
exit 1
fi

pState=Z
c=0
while [ 0 ]
do
    names=$(ps -el | tr -s " " | cut -d " " -f 14)
    states=$(ps -el | tr -s " " | cut -d " " -f 2)
    pid=$(ps -el | grep -m 1 $1 | tr -s " " | cut -d " " -f 4)
    #creo vettori
    i=0
    for n in $names
    do
        vN[$i]=$n
        let i=i+1
    done 
    i=0
    for s in $states
    do
        vS[$i]=$s
        let i=i+1
    done 

    
    #cerco e guardo lo stato


    i=0
    f=0
    while [ $i -lt ${#vN[*]} ]
    do
        if [ ${vN[$i]} = $1 ]
        then
            if [ ${vS[$i]} = $pState ]
            then
                f=1
                break
            else
                c=0
                break
            fi
        fi
        let i=i+1
    done

    

    if [ $f -eq 1 ]
    then
        let c=c+1
    fi

    if [ $c -gt 5 ]
    then 
        echo "finito"
        kill -9 $pid
        exit 1
    fi

    sleep $2
    unset vN
    unset vS
done

exit 0


