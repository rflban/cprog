CC = gcc
CFLAGS = -std=c99 -Werror -Wall -pedantic -O3

ifeq ($(mode), debug)
	CFLAGS += -ggdb
endif

ifeq ($(mode), release)
	CFLAGS += -g0 -DNDEBUG
endif

app.exe: main.o array_process.o exit_control.o file_control.o
	@$(CC) -o $@ $^

test.exe: test.o array_process.o
	@$(CC) -o $@ $^

sort_test.exe: sort_test.o array_process.o
	@$(CC) -o $@ $^

clean:
	@rm *.exe -f
	@rm *.o -f

%.o: %.c *.h
	@$(CC) $< $(CFLAGS) -c
