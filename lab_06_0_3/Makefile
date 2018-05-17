CC = gcc
CFLAGS = -std=c99 -Werror -Wall -pedantic

ifeq ($(mode), debug)
	CFLAGS += -g3
endif

ifeq ($(mode), release)
	CFLAGS += -g0 -DNDEBUG
endif

app.exe: main.o array_process.o exit_control.o file_control.o
	@$(CC) -o $@ $^

test.exe: test.o array_process.o
	@$(CC) -o $@ $^

clean:
	@rm *.exe -f
	@rm *.o -f

main.o: main.c *.h
	@$(CC) $< $(CFLAGS) -c

test.o: test.c array_process.h
	@$(CC) $< $(CFLAGS) -c

array_process.o: array_process.c array_process.h exit_control.h
	@$(CC) $< $(CFLAGS) -c

exit_control.o: exit_control.c exit_control.h
	@$(CC) $< $(CFLAGS) -c

file_control.o: file_control.c file_control.h exit_control.h
	@$(CC) $< $(CFLAGS) -c
