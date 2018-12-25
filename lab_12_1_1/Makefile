CC := gcc
CFLAGS := -std=c99 -Wall -ggdb #-Werror

PNAME := app.exe
TNAME := test.exe
ST1NAME := sort_test.exe
ST2NAME := qsort_time_test.exe

OBJS.$(PNAME) := main.o exit_control.o file_control.o
OBJS.$(TNAME) := test.o array_process.o
OBJS.$(ST1NAME) := sort_test.o array_process.o
OBJS.$(ST2NAME) := qsort_time_test.o array_process.o

LIBTYPE = 
BUILDMODE = static

$(PNAME): $(BUILDMODE).$(PNAME)
$(TNAME): $(BUILDMODE).$(TNAME)
$(ST1NAME): $(BUILDMODE).$(ST1NAME)
$(ST2NAME): $(BUILDMODE).$(ST2NAME)

###

static.$(PNAME): LIBTYPE = __STATIC__LIB
static.$(PNAME): libarray.a $(OBJS.$(PNAME))
	$(CC) -o $(PNAME) $(OBJS.$(PNAME)) -L. -larray

dynamic-link.$(PNAME): LIBTYPE = __DYNAMIC__LINK__LIB
dynamic-link.$(PNAME): libarray.so $(OBJS.$(PNAME))
	$(CC) -o $(PNAME) $(OBJS.$(PNAME)) -L. -larray

dynamic-load.$(PNAME): LIBTYPE = __DYNAMIC__LOAD__LIB
dynamic-load.$(PNAME): libarray.so $(OBJS.$(PNAME))
	$(CC) -o $(PNAME) $(OBJS.$(PNAME)) -ldl

###

static.$(TNAME): LIBTYPE = __STATIC__LIB
static.$(TNAME): libarray.a $(OBJS.$(TNAME))
	$(CC) -o $(TNAME) $(OBJS.$(TNAME)) -L. -larray

dynamic-link.$(TNAME): LIBTYPE = __DYNAMIC__LINK__LIB
dynamic-link.$(TNAME): libarray.so $(OBJS.$(TNAME))
	$(CC) -o $(TNAME) $(OBJS.$(TNAME)) -L. -larray

dynamic-load.$(TNAME): LIBTYPE = __DYNAMIC__LOAD__LIB
dynamic-load.$(TNAME): libarray.so $(OBJS.$(TNAME))
	$(CC) -o $(TNAME) $(OBJS.$(TNAME)) -ldl

###

static.$(ST1NAME): LIBTYPE = __STATIC__LIB
static.$(ST1NAME): libarray.a $(OBJS.$(ST1NAME))
	$(CC) -o $(ST1NAME) $(OBJS.$(ST1NAME)) -L. -larray

dynamic-link.$(ST1NAME): LIBTYPE = __DYNAMIC__LINK__LIB
dynamic-link.$(ST1NAME): libarray.so $(OBJS.$(ST1NAME))
	$(CC) -o $(ST1NAME) $(OBJS.$(ST1NAME)) -L. -larray

dynamic-load.$(ST1NAME): LIBTYPE = __DYNAMIC__LOAD__LIB
dynamic-load.$(ST1NAME): libarray.so $(OBJS.$(ST1NAME))
	$(CC) -o $(ST1NAME) $(OBJS.$(ST1NAME)) -ldl

###

static.$(ST2NAME): LIBTYPE = __STATIC__LIB
static.$(ST2NAME): libarray.a $(OBJS.$(ST2NAME))
	$(CC) -o $(ST2NAME) $(OBJS.$(ST2NAME)) -L. -larray

dynamic-link.$(ST2NAME): LIBTYPE = __DYNAMIC__LINK__LIB
dynamic-link.$(ST2NAME): libarray.so $(OBJS.$(ST2NAME))
	$(CC) -o $(ST2NAME) $(OBJS.$(ST2NAME)) -L. -larray

dynamic-load.$(ST2NAME): LIBTYPE = __DYNAMIC__LOAD__LIB
dynamic-load.$(ST2NAME): libarray.so $(OBJS.$(ST2NAME))
	$(CC) -o $(ST2NAME) $(OBJS.$(ST2NAME)) -ldl

###

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
	mv ./$@ /usr/lib/
