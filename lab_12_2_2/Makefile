CC := gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic -ggdb

LIBNAME := libmyarray.so


$(LIBNAME): my_array_lib.o
	ld -shared $< -o $@
	mv ./$@ /usr/lib/

%.o: %.c *.h
	$(CC) $(CFLAGS) $< -c

clean:
	rm *.o -f
	rm *.a -f
	rm *.so -f
	rm *.dll -f
	rm *.gch -f
	rm *.exe -f
	rm *.out -f
