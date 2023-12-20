main: confrontaContenuto.o main.o
	clang -o main confrontaContenuto.o main.o
confrontaContenuto.o: cmp.h confrontaContenuto.c
	clang -c confrontaContenuto.c
main.o: cmp.h main.c
	clang -c main.c
clean:
	rm -f *.o main