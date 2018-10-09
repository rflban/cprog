CC = gcc
CFLAGS = -std=c99 #-Werror -Wall -pedantic
mode = debug

ifeq ($(mode), debug)
	CFLAGS += -ggdb
endif

ifeq ($(mode), release)
	CFLAGS += -g0 -DNDEBUG -O3
endif

app.exe: main.o matrix.o exit.o fio.o ref.o actions.o matrix_operations.o
	$(CC) -o $@ $^

test.exe: test.o matrix.o
	$(CC) -o $@ $^

clean:
	rm *.exe -f
	rm *.o -f

%.o: %.c *.h
	$(CC) $< $(CFLAGS) -c
