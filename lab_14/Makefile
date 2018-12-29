CC := gcc
CFLAGS := -std=c99 -ggdb -Wall -Werror -pedantic
LFLAGS :=

TNAME1 := test_1.exe
TNAME2 := test_2.exe

OBJS.$(TNAME1) := test_1.o set_1.o
OBJS.$(TNAME2) := test_2.o set_2.o


$(TNAME1): $(OBJS.$(TNAME1))
	$(CC) $^ $(LFLAGS) -o $@

$(TNAME2): $(OBJS.$(TNAME2))
	$(CC) $^ $(LFLAGS) -o $@

%.o: %.c *.h
	$(CC) $< $(CFLAGS) -c

clean:
	rm $(OBJS.$(TNAME1)) -f
	rm $(OBJS.$(TNAME2)) -f
	rm $(TNAME1) -f
	rm $(TNAME2) -f
