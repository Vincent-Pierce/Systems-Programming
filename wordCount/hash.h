#ifndef HASH_H
#define HASH_H

/* FILE INCLUSION **************************************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/* MACROS **********************************************************************************************************/

/* FUNCTION PROTOTYPES *********************************************************************************************/
struct tup {
        char* key;
        uint32_t count;
};

struct hashTable {
        uint16_t capacity;
        uint16_t size;
        struct tup* buckets[];          // Struct Hack : malloc(sizeof(struct hashTable) + sizeof(tup*) * size)
};


struct hashTable* reHash(struct hashTable* table);

void hashInsert(char* key, struct hashTable* table);


#endif
