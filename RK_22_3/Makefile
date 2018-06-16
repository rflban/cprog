app.exe: main.o file.o matrix.o
	@gcc -o $@ main.o file.o matrix.o

clean:
	@rm -f *.o
	@rm -f *.exe

%.o: %.c *.h
	@gcc -c $<
