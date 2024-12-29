CC=gcc
CFLAGS=-g -Wall -L -lraylib -lGL -lm -lpthread -ldl -lrt
SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/*.c, $(OBJ)/%.o, $(SRCS))
BIN=bin/main

all:$(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c $(SRC)/%.h $(SRC)/da.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r bin/* obj/*

run:
	./bin/main
test:
	valgrind --leak-check=full --show-leak-kinds=all ./bin/main
