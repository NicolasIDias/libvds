CC = gcc
CFLAGS = -Wall -Wextra -I./include

SRC_STRING = src/string/strlen.c src/string/strcmp.c src/string/strcpy.c src/string/strcat.c

all: test

test_types: tests/test_types.c
	$(CC) $(CFLAGS) tests/test_types.c -o test_types

test_strlen: tests/test_strlen.c $(SRC_STRING)
	$(CC) $(CFLAGS) tests/test_strlen.c $(SRC_STRING) -o test_strlen

test_strcmp: tests/test_strcmp.c $(SRC_STRING)
	$(CC) $(CFLAGS) tests/test_strcmp.c $(SRC_STRING) -o test_strcmp

test_strcpy: tests/test_strcpy.c $(SRC_STRING)
	$(CC) $(CFLAGS) tests/test_strcpy.c $(SRC_STRING) -o test_strcpy

test_strcat: tests/test_strcat.c $(SRC_STRING)
	$(CC) $(CFLAGS) tests/test_strcat.c $(SRC_STRING) -o test_strcat

test: test_types test_strlen test_strcmp test_strcpy test_strcat
	@echo "--- Iniciando testes ---"
	./test_types
	./test_strlen
	./test_strcmp
	./test_strcpy
	./test_strcat
	@echo "--- Testes finalizados ---"

clean:
	rm -f ./test_types ./test_strlen ./test_strcmp ./test_strcpy ./test_strcat