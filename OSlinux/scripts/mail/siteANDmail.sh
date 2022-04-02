#!/bin/bash

mail="$2"
oldhash="$(curl $1 | md5sum)"
while [ 1 ]
do
    newhash="$(curl -s $1 | md5sum)"
    if [ "$newhash" != "$oldhash" ]
    then
       # sendmail francesco.mail4.0@gmail.com  < "$mail"
        echo "fatto"
        oldhash=$newhash
    fi
    sleep 1
done

exit 0
