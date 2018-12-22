CC = gcc
CFLAGS = -std=c99 #-Werror -Wall -ggdb
OBJS := main.o exit_control.o file_control.o
LIBTYPE := 

PNAME := app.exe
TNAME := test.exe

static: LIBTYPE := __STATIC__LIB
static: libarray.a $(OBJS)
	$(CC) -o $(PNAME) $(OBJS) -L. -larray

dynamic-link: LIBTYPE := __DYNAMIC__LINK__LIB
dynamic-link: libarray.so $(OBJS)
	$(CC) -o $(PNAME) $(OBJS) -Wl,-rpath,. -L. -larray

dynamic-load: LIBTYPE := __DYNAMIC__LOAD__LIB
dynamic-load: libarray.so $(OBJS)
	$(CC) -o $(PNAME) $(OBJS) -ldl


$(PNAME): main.o array_process.o exit_control.o file_control.o
	$(CC) -o $@ $^

$(TNAME): test.o array_process.o
	$(CC) -o $@ $^

sort_test.exe: sort_test.o array_process.o
	$(CC) -o $@ $^

qsort_time_test.exe: qsort_time_test.o array_process.o
	$(CC) -o $@ $^

clean:
	rm *.o -f
	rm *.a -f
	rm *.so -f
	rm *.dll -f
	rm *.gch -f
	rm *.exe -f
	rm *.out -f

%.o: %.c *.h
	$(CC) -D $(LIBTYPE) $< $(CFLAGS) -c

libarray.a: array_process.o
	ar rc $@ $<

libarray.so: array_process.o
	ld -shared $< -o $@ 
