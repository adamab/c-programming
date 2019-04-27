VARIABLE = -pedantic -std=gnu99 -Wall -Werror -g -ggdb3
breaker: breaker.o
	gcc -o test $(VARIABLE) breaker.o
breaker.o: breaker.c
	gcc -c $(VARIABLE) breaker.c