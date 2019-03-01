VARIABLE = -pedantic -std=gnu99 -Wall -Werror -g
test: test.o
	gcc -o test test.o
test.o: test.c
	gcc -c test.o  $(VARIABLE) test.c
.PHONY: clean
clean:
	rm -f test *.o *.c~ *.h~