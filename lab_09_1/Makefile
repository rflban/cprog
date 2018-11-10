CC := gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic

test.exe: my_str.test.o my_str.my_strspn.o 
	$(CC) $^ -o $@

%.o: %.c *.h
	$(CC) $< $(CFLAGS) -c

clean:
	rm *.out -f
	rm *.exe -f
	rm *.o -f
	rm *.gch -f