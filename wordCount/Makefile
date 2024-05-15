








CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -g 
MAIN = fw


all : $(MAIN)

$(MAIN) : fw.c hash.c fw.h hash.h 
	$(CC) $(CFLAGS) -o $(MAIN) fw.c hash.c 

clean :
	rm *.o $(MAIN) core
	
	
