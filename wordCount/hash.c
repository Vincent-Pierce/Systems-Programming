/*
 * 
 *
 * FILE INCLUSION **********************************************************************************/

#include "hash.h"

/* LOCAL DEFINITIONS ******************************************************************************/

struct hashTable* reHash(struct hashTable* table)
{
        uint16_t newSize = table->size*5;
        struct hashTable* newTable = malloc(sizeof(struct hashTable) + sizeof(struct tup*) * newSize);
        for(int i = 0; i < table->size; i++)
        {
		char* key = (table->buckets[i])->key;
                if(table->buckets[i] != NULL)
                {
                	hashInsert(key, newTable);	        // Re-hash all entries of table
                }
        }
        free(table);
        return newTable;
}

void hashInsert(char* key, struct hashTable* table)
{
        char* ch = key;
        uint16_t ind = 0;
	(table->size)++;
	if((table-> size) <= ((table->capacity) >> 1)) 			// Load factor must be < 0.5
	{
		table = reHash(table);
	}
        while(*ch != '\0') 		// Hash word into int
        {
        	ind += atoi(ch);
		ch++;
	}
	ind = ind % table->capacity;	// Ensure index < array size

	if(table->buckets[ind] == NULL) // Insert tup into empty bucket
	{
		struct tup myTup = {key, 1};
		*(table->buckets[ind]) = myTup;
	}
	else
	{
		while(table->buckets[++ind] != NULL)
		{	
			if(!(strcmp(key, (table->buckets[ind])->key)))
			{
				((table->buckets[ind]) -> count) +=1;  	// Found matching key
				return;	
			}	
		}
		((table->buckets[ind])->count) += 1; 	// Matching key 
	}
}
