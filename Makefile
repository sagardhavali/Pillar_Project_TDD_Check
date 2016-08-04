CFLAGS=-Wall
LIBS=-lcheck -pthread -lcheck_pic -pthread -lrt -lm -lsubunit

roman: roman.o roman_implementation.o
	gcc -o roman roman.o roman_implementation.o

roman.o: roman.c roman.h
	gcc $(CFLAGS) -c roman.c

roman_implementation.o: roman_implementation.c roman.h
	gcc $(CFLAGS) -c roman_implementation.c

test: roman-test
	./roman-test

roman-test: roman_test.o roman_implementation.o
	gcc -o roman-test roman_implementation.o roman_test.o $(LIBS)

roman_test.o: roman_test.c roman.h
	gcc $(CFLAGS) -c roman_test.c

clean:
	rm roman roman.o roman_implementation.o roman-test roman_test.o
