.PHONY : rule1 all clean build

CC := gcc
CFLAGS := -I.
INC_FILE := hello.h

build1: hello.c 
	gcc -I. -c -o hello.o hello.c
build2: main.c
	gcc -I. -c -o main.o main.c
rule1: hello.o main.o
	$(CC) -o hello hello.o main.o $(CFLAGS)
all:
	$(CC) -o hello hello.c main.c $(CFLAGS)
clean:
	rm -rf hello