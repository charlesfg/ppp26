CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c99 -g

SRC_DIR = src
TEST_DIR = test
BIN_DIR = bin

TEST_BIN = $(BIN_DIR)/testes
TEST_SRCS = $(TEST_DIR)/testa_aluno.c $(SRC_DIR)/app.c $(SRC_DIR)/db.c $(SRC_DIR)/aluno.c $(SRC_DIR)/despesa.c $(SRC_DIR)/data.c

.PHONY: all clean test

all:
	$(MAKE) -C $(SRC_DIR)

test: $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): $(TEST_SRCS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -I$(SRC_DIR) $(TEST_SRCS) -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	$(MAKE) -C $(SRC_DIR) clean
	rm -f $(TEST_BIN)
