CFLAGS := -std=c99 -Wall -Werror -ggdb
input := in.txt

build: rk31.exe test.exe

rk31.exe: main.o matrix.o exit.o
	gcc $^ -o $@

test.exe: test.o matrix.o exit.o
	gcc $^ -o $@

%.o: %.c *.h
	gcc $< $(CFLAGS) -c

run:
	./rk31.exe $(input)

test:
	./test.exe

memory:
	valgrind ./rk31.exe $(input)
	@echo ""
	valgrind ./test.exe
	@echo ""

clean:
	rm *.o -f
	rm *.exe -f