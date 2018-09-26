CC = gcc
DEBUG = -g
CFLAGS = -Wall -std=c99 -pedantic -c $(DEBUG)
LFLAGS = -Wall -std=c99 -pedantic $(DEBUG)

main : main.o string_to_int_converter.o parser.o
	$(CC) $(LFLAGS) main.o string_to_int_converter.o parser.o -o ../driver

main.o : main.c
	$(CC) $(CFLAGS) main.c

string_to_int_converter.o : string_to_int_converter.c string_to_int_converter.h
	$(CC) $(CFLAGS) string_to_int_converter.c

parser.o : parser.c parser.h
	$(CC) $(CFLAGS) parser.c

clean:
	\rm *.o driver
