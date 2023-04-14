# Make file for list libary

# Compiler and compiler flags
CC := gcc
CFLAGS := -Wall -ansi 

# Directories
SOURCE := src
INCLUDE := include
BUILD := obj
BIN := bin
LIB := lib


all: $(BIN)/main 


$(BIN)/main: $(SOURCE)/main.c $(LIB)/list_char.a
	$(CC) $(CFLAGS) -I $(INCLUDE) $^ -o $@


$(LIB)/list_char.a:	$(BUILD)/list_char.o $(BUILD)/generic_list.o
	ar rcs $@ $^


$(BUILD)/list_char.o: $(SOURCE)/list_char.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@


$(BUILD)/generic_list.o: $(SOURCE)/generic_list.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@



clean:
	rm -f $(BUILD)/* $(BIN)/* $(LIB)/*

