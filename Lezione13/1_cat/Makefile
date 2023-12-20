main: stampaContenuto.o main.o
	clang -o main stampaContenuto.o main.o
stampaContenuto.o: cat.h stampaContenuto.c
	clang -c stampaContenuto.c
main.o: cat.h main.c
	clang -c main.c
clean:
	rm -f *.o main