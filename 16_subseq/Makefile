VARIABLE = -pedantic -std=gnu99 -g
testSeqMax: test-subseq.o seqMax.o
	gcc -o testSeqMax -pedantic -std=gnu99 -Wall -Werror seqMax.o test-seqMax.o
test-subseq.o:
	gcc -c $(VARIABLE) test-subseq.c
seqMax.o:
	gcc -c $(VARIABLE) seqMax.c
.PHONY: clean
clean:
	rm -f *.o *.c~ *.h~
