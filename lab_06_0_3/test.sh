#!/bin/sh

gcc -c test.c -std=c99 -Werror -Wall -pedantic
gcc -c l_array_process.c -std=c99 -Werror -Wall -pedantic
gcc -o test.exe test.o l_array_process.o
