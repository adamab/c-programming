VARIABLE = -pedantic -std=gnu99 -Wall -Werror -g
test: test.o
	gcc -o test test.o
test.o: test.c
	gcc test.o  $(VARIABLE) -c
.PHONY: clean
clean:
	rm -f test *.o *.c~ *.h~