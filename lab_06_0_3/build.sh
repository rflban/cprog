#!/bin/sh

gcc -c main.c -std=c99 -Werror -Wall -pedantic
gcc -c array_process.c -std=c99 -Werror -Wall -pedantic
gcc -c exit_control.c -std=c99 -Werror -Wall -pedantic
gcc -c file_control.c -std=c99 -Werror -Wall -pedantic
gcc -o app.exe main.o array_process.o exit_control.o file_control.o
