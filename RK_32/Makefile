CC := gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic -ggdb
PNAME := app.exe

INPUTF := SPB.csv

build: $(PNAME)

run:
	./$(PNAME) -i $(INPUTF)

$(PNAME): main.o my_lib.o
	$(CC) $^ -o $@

%.o: %.c *.h
	$(CC) $(CFLAGS) $< -c
	
clean:
	rm *.o -f
	rm *.gch -f
	rm *.exe -f
	rm *.out -f