CC = gcc
CFLAGS = -Wall -Wextra -I./include

SRC_STRING = src/string/strlen.c src/string/strcmp.c src/string/strcpy.c

all: test

test_types: tests/test_types.c
	$(CC) $(CFLAGS) tests/test_types.c -o test_types

test_strlen: tests/test_strlen.c $(SRC_STRING)
	$(CC) $(CFLAGS) tests/test_strlen.c $(SRC_STRING) -o test_strlen

test_strcmp: tests/test_strcmp.c $(SRC_STRING)
	$(CC) $(CFLAGS) tests/test_strcmp.c $(SRC_STRING) -o test_strcmp

test_strcpy: tests/test_strcpy.c $(SRC_STRING)
	$(CC) $(CFLAGS) tests/test_strcpy.c $(SRC_STRING) -o test_strcpy

test: test_types test_strlen test_strcmp test_strcpy
	@echo "--- Iniciando testes ---"
	./test_types
	./test_strlen
	./test_strcmp
	./test_strcpy
	@echo "--- Testes finalizados ---"

clean:
	rm -f ./test_types ./test_strlen ./test_strcmp ./test_strcpy