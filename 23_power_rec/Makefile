VARIABLE = -pedantic -std=gnu99 -Wall -Werror -g -ggdb3
test-power: test-power.o power.o
	gcc -o test-power $(VARIABLE) test-power.o power.o
test-power.o: test-power.c
	gcc -c $(VARIABLE) test-power.c
power.o: power.c
	gcc -c $(VARIABLE) power.c