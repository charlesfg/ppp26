CC ?= gcc
CFLAGS ?= -Wall -Wextra -Wpedantic -std=c99 -g

SRC_DIR := .
BIN_DIR := ../bin
APP_BIN := $(BIN_DIR)/projectoppp_template

APP_SRCS := main.c app.c ui.c db.c aluno.c despesa.c data.c lista.c
APP_OBJS := $(patsubst %.c,$(BIN_DIR)/%.o,$(APP_SRCS))

.PHONY: all clean

all: $(APP_BIN)

$(APP_BIN): $(APP_OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -I$(SRC_DIR) -c $< -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -f $(APP_OBJS) $(APP_BIN)
