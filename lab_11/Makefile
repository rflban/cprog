CC := gcc
CFLAGS := -std=c99 -ggdb -Wall -Werror -pedantic -fprofile-arcs -ftest-coverage
LFLAGS := -lgcov --coverage

TNAME := test.exe
OBJS.$(TNAME) := test.o myio.o


${TNAME}: $(OBJS.$(TNAME))
	$(CC) $^ $(LFLAGS) -o $@

%.o: %.c *.h
	$(CC) $< $(CFLAGS) -c

call-gcov:
	./$(TNAME) > /dev/null
	gcov myio.c

clean:
	rm *.gcda -f
	rm *.gcno -f
	rm *.gcov -f
	rm $(TNAME) -f
	rm $(OBJS.$(TNAME)) -f
