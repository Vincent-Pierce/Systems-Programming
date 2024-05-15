/*
 * 
 *
 * FILE INCLUSION **********************************************************************************/

#include "hash.h"

/* LOCAL DEFINITIONS ******************************************************************************/

struct hashTable* reHash(struct hashTable* table)
{
        uint16_t newSize = table->size*2;
        table = (struct hashTable*) realloc(table, sizeof(struct hashTable) + sizeof(struct tup*) * table->size * 2); //need re-hashing?
        struct hashTable* newTable = malloc(sizeof(struct hashTable) + sizeof(struct tup*) * newSize);
        for(int i = 0; i < table->size; i++)
        {
                if(table->buckets[i] != NULL)
                {
                        //hashFunction
                }
        }
        free(table);
        return newTable;
}

void hash(char* key, struct hashTable* table)
{
        char* ch = key;
        int ind = 0;
        while(*ch != '\0')
        {
        ind = atoi(ch) % table->size;
                if(table->buckets[ind] == NULL)
                {
                        struct tup myTup = {key, 1};
                        *(table->buckets[ind]) = myTup;
                }
                else
                {
                        (table->buckets[ind])->count += 1;
                }
        }

        // double buckets if load factor > 0.5
        // quadratic probing if collision
}
