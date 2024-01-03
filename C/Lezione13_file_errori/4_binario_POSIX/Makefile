main: main.o
	clang -o main main.o
main.o: binario.h main.c
	clang -c main.c
clean:
	rm -f *.o main