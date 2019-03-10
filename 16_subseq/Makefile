VARIABLE = -pedantic -std=gnu99 -Wall -Werror -g
testSeqMax: test-seqMax.o seqMax.o
	gcc -o testSeqMax -pedantic -std=gnu99 -Wall -Werror seqMax.o test-seqMax.o
test-seqMax.o:
	gcc -c $(VARIABLE) test-seqMax.c
seqMax.o:
	gcc -c $(VARIABLE) seqMax.c
.PHONY: clean
clean:
	rm -f *.o *.c~ *.h~
