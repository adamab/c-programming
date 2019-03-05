VARIABLE = -pedantic -std=gnu99 -Wall -Werror -g
test: test.o
	gcc -o test test.o
test.o:
	gcc -c $(VARIABLE) test.c
.PHONY: clean
clean:
	rm -f *.o *.c~ *.h~
