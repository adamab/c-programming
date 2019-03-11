VARIABLE = -pedantic -std=gnu99 -g
testSeqMax: test-subseq.o maxSeq.o
	gcc -o $(VARIABLE) testSeqMax  maxSeq.o test-subseq.o
test-subseq.o:
	gcc -c $(VARIABLE) test-subseq.c
maxSeq.o:
	gcc -c $(VARIABLE) maxSeq.c
.PHONY: clean
clean:
	rm -f *.o *.c~ *.h~
