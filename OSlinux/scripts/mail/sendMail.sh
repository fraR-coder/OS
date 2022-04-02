#!/bin/bash
if [ $# != 1 ]
then
    echo "devi inserire file testo da inivare"
    exit 1
fi

mail="$1"

i=0
echo "quante mail vuoi inviare?"
read n



while [ $i -lt "$n" ]
do
    
    if [ $i -lt $n ]
    then
        sendmail francesco.mail4.0@gmail.com  < "$mail"
        echo "fatto"
        let i=$i+1
    fi
    sleep 1
done

exit 0
