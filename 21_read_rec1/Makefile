VARIABLE = -pedantic -std=gnu99 -Wall -Werror -g -ggdb3
test: test.o
	gcc -o test $(VARIABLE) test.o
test.o: test.c
	gcc -c $(VARIABLE) test.c