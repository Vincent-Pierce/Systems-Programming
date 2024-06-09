CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -g -O0
MAIN = hencode hdecode

all : $(MAIN)

hencode : linkedList.c hencode.c 
	$(CC) $(CFLAGS) -o hencode linkedList.h hencode.c

hdecode : linkedList.c hdecode.c
	$(CC) $(CFLAGS) -o hdecode linkedList.h hdecode.c

clean :
	rm *.o $(MAIN) core
