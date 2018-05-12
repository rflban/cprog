#!/bin/sh

gcc -c main.c -std=c99 -Werror -Wall -pedantic
gcc -c l_array_process.c -std=c99 -Werror -Wall -pedantic
gcc -c l_exit_control.c -std=c99 -Werror -Wall -pedantic
gcc -c l_file_control.c -std=c99 -Werror -Wall -pedantic
gcc -o app.exe main.o l_array_process.o l_exit_control.o l_file_control.o
