C = gcc
CFLAGS = -Wall -std=c99 -pedantic -g 
MAIN = fw


all : $(MAIN)

$(MAIN) : fw.c 
	$(CC) $(CFLAGS) -o $(MAIN) fw.c 

clean :
	rm *.o $(MAIN) core
