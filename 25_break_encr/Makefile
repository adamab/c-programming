VARIABLE = -pedantic -std=gnu99 -Wall -Werror -g -ggdb3
breaker: breaker.o
	gcc -o breaker $(VARIABLE) breaker.o
breaker.o: breaker.c
	gcc -c $(VARIABLE) breaker.c
encrypt: encrypt.o
	gcc -o encrypt $(VARIABLE) encrypt.o
encrypt.o: encrypt.c
	gcc -c $(VARIABLE) encrypt.c
clean-encrypt:
	rm -f encrypt encrypt.o *~
clean-breaker:
	rm -f breaker breaker.o *~