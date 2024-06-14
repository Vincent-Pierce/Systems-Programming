CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -g -O0
MAIN = hencode hdecode

all : $(MAIN)

hencode : linkedList.h huffman.h hencode.c 
	$(CC) $(CFLAGS) -o hencode linkedList.h huffman.h hencode.c

hdecode : linkedList.h huffman.h hdecode.c
	$(CC) $(CFLAGS) -o hdecode linkedList.h huffman.h hdecode.c

clean :
	rm *.o $(MAIN) core
