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

%.o: %.c *.h
	@$(CC) $< $(CFLAGS) -c
