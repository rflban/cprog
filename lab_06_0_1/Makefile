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

clean:
	@rm *.exe -f
	@rm *.o -f

main.o: main.c
	@$(CC) $< $(CFLAGS) -c

array_process.o: array_process.c
	@$(CC) $< $(CFLAGS) -c

exit_control.o: exit_control.c
	@$(CC) $< $(CFLAGS) -c

file_control.o: file_control.c
	@$(CC) $< $(CFLAGS) -c
