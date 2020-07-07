# All Targets
BIN=./bin/
SOURCE=./src/
INCLUDE=./include/

CFLAGS=-g -Wall -ansi -pedantic -c
C=-g -Wall -o

all: myLinkedList

myLinkedList: LinkedList.o main.o
	@gcc $(C) myLinkedList $(BIN)/LinkedList.o $(BIN)/main.o

main.o: $(SOURCE)/main.c
	@gcc $(CFLAGS) $(SOURCE)/main.c -o $(BIN)/main.o

LinkedList.o: $(SOURCE)/LinkedList.c $(INCLUDE)/LinkedList.h
	@mkdir -p bin
	@gcc $(CFLAGS) $(SOURCE)/LinkedList.c -o $(BIN)/LinkedList.o

#tell make that "clean" is not a file name!
.PHONY: clean run debug

clean:
	@rm -vf $(BIN)/* myLinkedList

run: myLinkedList
	@./myLinkedList

debug: myLinkedList
	@gdb myLinkedList

memcheck: myLinkedList
	valgrind --leak-check=yes ./myLinkedList
