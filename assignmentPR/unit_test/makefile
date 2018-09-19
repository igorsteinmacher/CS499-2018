CC = gcc
DEBUG = -g
CFLAGS = -Wall -std=c99 -pedantic -c $(DEBUG)
LFLAGS = -Wall -std=c99 -pedantic $(DEBUG)
VPATH += ../src

test_driver : test_driver.o test_string_to_int_converter.o string_to_int_converter.o test_parser.o parser.o
	$(CC) $(LFLAGS) test_driver.o test_string_to_int_converter.o string_to_int_converter.o test_parser.o parser.o -o ../test_driver

test_driver.o : test_driver.c
	$(CC) $(CFLAGS) test_driver.c

test_string_to_int_converter.o : test_string_to_int_converter.c test_string_to_int_converter.h
	$(CC) $(CFLAGS) test_string_to_int_converter.c

test_parser.o : test_parser.c test_parser.h
	$(CC) $(CFLAGS) test_parser.c

string_to_int_converter.o : string_to_int_converter.c string_to_int_converter.h
	$(CC) $(CFLAGS) ../src/string_to_int_converter.c

parser.o : parser.c parser.h
	$(CC) $(CFLAGS) ../src/parser.c

clean :
	\rm *.o test_main