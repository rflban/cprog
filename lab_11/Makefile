CC := gcc
CFLAGS := -std=c99 -ggdb -Wall #-Werror -pedantic

TNAME := test.exe
OBJS.$(TNAME) := test.o myio.o


${TNAME}: $(OBJS.$(TNAME))
	$(CC) $^ -o $@

%.o: %.c *.h
	$(CC) $< $(CFLAGS) -c

clean:
	rm $(TNAME) -f
	rm $(OBJS.$(TNAME)) -f
