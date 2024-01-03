main: contaModifiche.o main.o
	clang -o main contaModifiche.o main.o
contaModifiche.o: modifiche.h contaModifiche.c
	clang -c contaModifiche.c
main.o: modifiche.h main.c
	clang -c main.c
clean:
	rm -f *.o main