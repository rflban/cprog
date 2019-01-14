CC := gcc
CFLAGS := -std=c99 -ggdb -Wall -Werror -pedantic -fprofile-arcs -ftest-coverage
LFLAGS := -lgcov --coverage

PNAME := app.exe
TNAME := test.exe
TSCRIPT := test.sh

OBJS.$(PNAME) = main.o mylib.o exit.o
OBJS.$(TNAME) = test.o mylib.o exit.o

$(PNAME): $(OBJS.$(PNAME))
	$(CC) $^ $(LFLAGS) -o $@

$(TNAME): $(OBJS.$(TNAME))
	$(CC) $^ $(LFLAGS) -o $@

%.o: %.c *.h
	$(CC) $< $(CFLAGS) -c

func-tests:
	@chmod +x $(TSCRIPT)
	@./$(TSCRIPT)

call-gcov:
	./$(TNAME) > /dev/null
	gcov mylib.c

clean:
	rm *.gcda -f
	rm *.gcno -f
	rm *.gcov -f
	rm $(PNAME) -f
	rm $(TNAME) -f
	rm $(OBJS.$(PNAME)) -f
	rm $(OBJS.$(TNAME)) -f
