#ifndef HASH_H
#define HASH_H

/* FILE INCLUSION **************************************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
/* MACROS **********************************************************************************************************/
#define HASHSIZ 4 
/* FUNCTION PROTOTYPES *********************************************************************************************/
struct tup {
        char* key;
        uint32_t count;
};

struct hashTable {
        uint16_t capacity;
        uint16_t size;
		struct tup* bucket;
};

struct hashTable* newHash(void);
void reHash(struct hashTable* table);
void hashWord(char* key, struct hashTable* table);
void sortHash(struct hashTable* table);
void swapTup(struct tup* a, struct tup* b);
#endif
