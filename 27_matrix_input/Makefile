VARIABLE = -pedantic -std=gnu99 -Wall -Werror -g -ggdb3
rotateMatrix: rotateMatrix.o
	gcc -o rotateMatrix $(VARIABLE) rotateMatrix.o
rotateMatrix.o: rotateMatrix.c
	gcc -c $(VARIABLE) rotateMatrix.c
clean:
	rm -f rotateMatrix rotateMatrix.o *~
