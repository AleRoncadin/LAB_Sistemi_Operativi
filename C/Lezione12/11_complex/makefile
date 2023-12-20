complex: cabs.o angle.o from_polar.o main.o
	clang cabs.o angle.o from_polar.o main.o -o complex

cabs.o: complex.h cabs.c
	clang -c cabs.c

angle.o: complex.h angle.c
	clang -c angle.c

from_polar.o: complex.h from_polar.c
	clang -c from_polar.c

main.o: complex.h main.c
	clang -c main.c

clean:
	rm -f *.o complex