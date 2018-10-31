CC := gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic

test.exe: my_str.h *.c
	$(CC) $^ $(CFLAGS) -o $@

clean:
	rm *.out -f
	rm *.exe -f
	rm *.o -f