CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -g -O0
MAIN = fw


all : $(MAIN)

$(MAIN) : fw.c hash.c  
	$(CC) $(CFLAGS) -o $(MAIN) fw.c hash.c  

clean :
	rm *.o $(MAIN) core
	
	
