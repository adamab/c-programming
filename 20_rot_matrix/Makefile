VARIABLE = -pedantic -std=gnu99 -Wall -Werror -g -ggdb3
rotate-matrix: read-matrix.o clockwise-matrix.o
	gcc -o rotate-matrix $(VARIABLE) read-matrix.o clockwise-matrix.o
clockwise-matrix.o: clockwise-matrix.c
	gcc -c $(VARIABLE) clockwise-matrix.c