#!/bin/sh

gcc -c test.c -std=c99 -Werror -Wall -pedantic
gcc -c array_process.c -std=c99 -Werror -Wall -pedantic
gcc -o test.exe test.o array_process.o
