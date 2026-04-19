CC      := gcc
CFLAGS  := -Wall -Wextra -Werror -pedantic -std=c99 -I./include \
           -Wshadow -Wformat=2 -Wconversion -Wstrict-prototypes  \
           -Wmissing-prototypes -Wnull-dereference                \
           -Wdouble-promotion -Wundef -Wwrite-strings             \
           -Wfloat-equal -Wcast-qual -Wpointer-arith              \
           -fstack-protector-strong -fno-common -ffast-math
LDFLAGS := -lm
VALGRIND := valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --error-exitcode=1

SRC_DIR   := src
TEST_DIR  := tests

SRC_STRING   := $(wildcard $(SRC_DIR)/string/str*.c)
SRC_ASSERT   := $(SRC_DIR)/assert/assert.c
SRC_LL   := $(SRC_DIR)/data_structures/linkedlist.c
SRC_MEMORY   := $(SRC_DIR)/memory/memory.c

SRC_OBJS  := $(SRC_STRING:.c=.o) $(SRC_ASSERT:.c=.o) $(SRC_LL:.c=.o) $(SRC_MEMORY:.c=.o)

TEST_SRCS := $(wildcard $(TEST_DIR)/string/test_*.c) $(wildcard $(TEST_DIR)/memory/test_*.c) $(wildcard $(TEST_DIR)/data_structures/test_*.c) $(wildcard $(TEST_DIR)/assert/test_*.c) $(wildcard $(TEST_DIR)/test_*.c)
TEST_OBJS := $(TEST_SRCS:.c=.o)
TESTS     := $(TEST_SRCS:.c=)

.PHONY: all test valgrind clean

all: test

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(SRC_OBJS)
	@echo "---- Iniciando testes ----"
	@for src in $(TEST_SRCS); do \
		obj=$${src%.c}.o; \
		exe=$${src%.c}; \
		$(CC) $(CFLAGS) -c "$$src" -o "$$obj"; \
		$(CC) $(CFLAGS) "$$obj" $(SRC_OBJS) -o "$$exe" $(LDFLAGS); \
		echo "---- Executando $$exe ----"; \
		"$$exe" || exit $$?; \
	done
	@echo "---- Testes finalizados ----"

valgrind: test
	@echo "---- Iniciando Valgrind ----"
	@for exe in $(TESTS); do \
		echo "---- VALGRIND $$exe ----"; \
		$(VALGRIND) "$$exe"; \
	done

clean:
	rm -f $(TESTS) $(TEST_OBJS) $(SRC_OBJS)

compile:
	$(CC) $(CFLAGS) -c src/string/strlen.c -o src/string/strlen.o
	$(CC) $(CFLAGS) -c src/string/strcmp.c -o src/string/strcmp.o
	$(CC) $(CFLAGS) -c src/string/strcpy.c -o src/string/strcpy.o
	$(CC) $(CFLAGS) -c src/string/strcat.c -o src/string/strcat.o
	$(CC) $(CFLAGS) -c src/memory/memory.c -o src/memory/memory.o
	$(CC) $(CFLAGS) -c src/data_structures/linkedlist.c -o src/data_structures/linkedlist.o
	$(CC) $(CFLAGS) -c src/assert/assert.c -o src/assert/assert.o