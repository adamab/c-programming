VARIABLE = -pedantic -std=gnu99 -Wall -Werror -g -ggdb3
rotate-matrix: read-matrix.o rotate.o
	gcc -o rotate-matrix $(VARIABLE) read-matrix.o rotate.o
rotate.o: rotate.c
	gcc -c $(VARIABLE) rotate.c