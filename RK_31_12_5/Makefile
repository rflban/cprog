build: main.o matrix.o
	gcc $^ -o rk31.exe

%.o: %.c *.h
	gcc $< $(CFLAGS) -c

run:
	./rk31.exe in.txt
	
clean:
	rm *.o -f
	rm *.exe -f