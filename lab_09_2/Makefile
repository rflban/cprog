CC := gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic
mode := debug

ifeq ($(mode), debug)
	CFLAGS += -ggdb
endif

ifeq ($(mode), release)
	CFLAGS += -g0 -DNDEBUG -O3
endif

app.exe: main.o exit.o file.o my_str.o
	$(CC) $^ -o $@

test.exe: test.o my_str.o
	$(CC) $^ -o $@

clean:
	rm -f *.out
	rm -f *.exe
	rm -f *.o
	rm -f *.gch

%.o: %.c *.h
	$(CC) $(CFLAGS) $< -c