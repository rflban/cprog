app.exe: main.o l_array_process.o l_exit_control.o l_file_control.o
	@gcc -o app.exe main.o l_array_process.o l_exit_control.o l_file_control.o

test.exe: test.o l_array_process.o
	@gcc -o test.exe test.o l_array_process.o

clean:
	@rm *.exe
	@rm *.o

main.o: main.c l_array_process.h l_exit_control.h l_file_control.h
	@gcc -c main.c -std=c99 -Werror -Wall -pedantic

test.o: test.c l_array_process.h
	@gcc -c test.c -std=c99 -Werror -Wall -pedantic

l_array_process.o: l_array_process.c l_array_process.h
	@gcc -c l_array_process.c -std=c99 -Werror -Wall -pedantic

l_exit_control.o: l_exit_control.c l_exit_control.h
	@gcc -c l_exit_control.c -std=c99 -Werror -Wall -pedantic

l_file_control.o: l_file_control.c l_file_control.h
	@gcc -c l_file_control.c -std=c99 -Werror -Wall -pedantic
