#!/bin/bash

for ((i = 1; $i <= 3; i = ($i + 1)))
do
    ./app.exe in_$i.txt > out.txt 2>/dev/null
    diff out_$i.txt out.txt >/dev/null 2>&1
    if [ "$?" == 0 ];
    then
        echo "$i. Success."
    else
        echo "$i. Failure."
    fi
done
