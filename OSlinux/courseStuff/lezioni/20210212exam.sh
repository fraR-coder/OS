 #!bin/bash/

 
 for i in $(find $1 -name "*.c")
 do
    name=$(basename $i)
    echo $name
    grep -e "$name" "$i">cestino.txt

    if [ $? -eq 0 ];then
        echo "$i"
    fi
 done

 exit 0