app.exe: main.o l_array_process.o l_exit_control.o l_file_control.o
	@gcc -o app.exe main.o l_array_process.o l_exit_control.o l_file_control.o

clean:
	@rm *.exe
	@rm *.o

main.o: main.c
	@gcc -c main.c -std=c99 -Werror -Wall -pedantic

l_array_process.o: l_array_process.c
	@gcc -c l_array_process.c -std=c99 -Werror -Wall -pedantic

l_exit_control.o: l_exit_control.c
	@gcc -c l_exit_control.c -std=c99 -Werror -Wall -pedantic

l_file_control.o: l_file_control.c
	@gcc -c l_file_control.c -std=c99 -Werror -Wall -pedantic
