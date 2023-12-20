add: add.o main.o
	clang add.o main.o -o add
add.o: add.h add.c
	clang -c add.c
main.o: add.h main.c
	clang -c main.c
