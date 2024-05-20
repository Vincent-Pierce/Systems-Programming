#ifndef HASH_H
#define HASH_H

/* FILE INCLUSION **************************************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
/* MACROS **********************************************************************************************************/
#define HASHSIZ 100
/* FUNCTION PROTOTYPES *********************************************************************************************/
struct tup {
        char* key;
        uint32_t count;
};

struct hashTable {
        uint16_t capacity;
        uint16_t size;
        struct tup* buckets[];          // Struct Hack : malloc(sizeof(struct hashTable) + sizeof(struct tup*) * size)
};

struct hashTable* createHash(void);
struct hashTable* reHash(struct hashTable* table);

void hashWord(char* key, struct hashTable* table);

void sortHash(struct hashTable* table);
#endif
