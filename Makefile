CC      := gcc
CFLAGS  := -Wall -Wextra -Werror -pedantic -std=c99 -I./include \
           -Wshadow -Wformat=2 -Wconversion -Wstrict-prototypes  \
           -Wmissing-prototypes -Wnull-dereference                \
           -Wdouble-promotion -Wundef -Wwrite-strings             \
           -Wfloat-equal -Wcast-qual -Wpointer-arith              \
           -fstack-protector-strong -fno-common -ffast-math
LDFLAGS := -lm
VALGRIND := valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --error-exitcode=1

LIB_NAME  := libvds.a

SRC_DIR   := src
TEST_DIR  := tests

SRC_STRING := $(wildcard $(SRC_DIR)/string/str*.c)
SRC_ASSERT := $(SRC_DIR)/assert/assert.c
SRC_LL     := $(SRC_DIR)/data_structures/linkedlist.c
SRC_MEMORY := $(SRC_DIR)/memory/memory.c

SRC_OBJS   := $(SRC_STRING:.c=.o) $(SRC_ASSERT:.c=.o) $(SRC_LL:.c=.o) $(SRC_MEMORY:.c=.o)

TEST_SRCS  := $(wildcard $(TEST_DIR)/string/test_*.c) $(wildcard $(TEST_DIR)/memory/test_*.c) $(wildcard $(TEST_DIR)/data_structures/test_*.c) $(wildcard $(TEST_DIR)/assert/test_*.c) $(wildcard $(TEST_DIR)/test_*.c)
TEST_OBJS  := $(TEST_SRCS:.c=.o)
TESTS      := $(TEST_SRCS:.c=)

.PHONY: all test valgrind clean

all: $(LIB_NAME) test

$(LIB_NAME): $(SRC_OBJS)
	@echo "---- Generating $(LIB_NAME) ----"
	ar rcs $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(LIB_NAME) $(TEST_SRCS)
	@echo "---- Initing tests ----"
	@for src in $(TEST_SRCS); do \
		obj=$${src%.c}.o; \
		exe=$${src%.c}; \
		$(CC) $(CFLAGS) -c "$$src" -o "$$obj"; \
		$(CC) $(CFLAGS) "$$obj" $(LIB_NAME) -o "$$exe" $(LDFLAGS); \
		echo "---- Executing $$exe ----"; \
		"$$exe" || exit $$?; \
	done
	@echo "---- Tests completed  ----"

valgrind: test
	@echo "---- Initing Valgrind ----"
	@for exe in $(TESTS); do \
		echo "---- VALGRIND $$exe ----"; \
		$(VALGRIND) "$$exe" || exit 1; \
	done

clean:
	rm -f $(TESTS) $(TEST_OBJS) $(SRC_OBJS) $(LIB_NAME)