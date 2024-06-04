fw is a program that counts and prints the top 10 occuring words form the text files input into it. If no input is given than a standard stream is assumed. The option -n [x] option allows the user to determine the number of top occuring words printed. 

The strategy to accomplish this task was create a string from each space delimited character, and insert those strings into a hashtable for ease of counting. Once every word was parsed (EOF reached) the table was sorted by occurence. Words coming later in the alphabet won ties.  

All strings, structures and the hashTable implemented were dynamically allocated. No memory leaks. 

KEY TAKEAWAYS
#Struct Hack
Final and only final field of a struct can be dynamically allocated. Allows for array of unknown size to be created at run-time.
Ex: 
struct tuple {
	int a;
	char word[0];
};
struct tuple *ptr = malloc(sizeof(struct tuple) + sizeof(char)*x);

#Dynamic Memory Allocation
malloc
calloc
realloc
free
Understanding the pointer returned by dynamic allocation is associated with a chunk of memory in the heap that you must free.
Any pointer pointing to that chunk can free the memory for all pointers pointin to it. 

#GDB
gdb <myprog>
r <arg1> <arg2>
b file:line#
disable b
enable b
ignore # <x times>
where

#Valgrind
valgrind --leak-check=yes <myprog> <arg1> <arg2>

