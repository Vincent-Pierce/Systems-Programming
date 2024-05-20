/*
 * 
 *
 * FILE INCLUSION **********************************************************************************/

#include "hash.h"
#include <stdbool.h>
/* LOCAL DEFINITIONS ******************************************************************************/

struct hashTable* createHash(void)
{
	struct hashTable* newTable = (struct hashTable*) malloc(sizeof(struct hashTable) + sizeof(struct tup*) * HASHSIZ);
	newTable -> size = 0;
	newTable -> capacity = HASHSIZ;
	for(int i = 0; i < HASHSIZ; i++)
	{
		newTable->buckets[i] = NULL;
	}
	return newTable;
}

struct hashTable* reHash(struct hashTable* oldTable)
{
    uint16_t newCapacity = oldTable->capacity*5;
       
	struct hashTable* newTable = (struct hashTable*) malloc(sizeof(struct hashTable) + sizeof(struct tup*) * newCapacity);
	newTable -> size = oldTable->size; 
	newTable -> capacity = newCapacity;
	for(int i = 0; i < newCapacity; i++)
	{	
		newTable->buckets[i] = NULL;
	}
       	
	for(int i = 0; i < oldTable->size; i++)
		{
		char* key = (oldTable->buckets[i])->key;
				if(oldTable->buckets[i] != NULL)
				{
					hashWord(key, newTable);	        // Re-hash all entries of oldTable
					free(oldTable->buckets[i]);
				}
				else
				{
					free(oldTable->buckets[i]);
				}
		}
		free(oldTable);
		return newTable;
}

void hashWord(char* key, struct hashTable* myTable)
{
    char* ch = key;
    uint16_t ind = 0;
	if((myTable -> size) > ((myTable->capacity) >> 1)) 			// Load factor must be < 0.5
	{
		myTable = reHash(myTable);
	}
        while(*ch != '\0') 		// Hash word into int
        {
        	ind += tolower(*ch) - '0';
			ch++;
		}
	ind = ind % (myTable->capacity);	// Ensure index < array size
if(myTable->buckets[ind] == NULL) // Insert tup into empty bucket
	{
	struct tup* hashTup = malloc(sizeof(struct tup)); 		// Lost ability to free hashTup after exiting function... memory leaks will occur
	hashTup->key = key;
	hashTup->count = 1;
	myTable->buckets[ind] = hashTup;
	(myTable->size)++;
	}
	else
	{
		while(myTable->buckets[ind] != NULL)  			// Linear probing
		{	
			if(!(strcmp(key, (myTable->buckets[ind])->key)))
			{
				((myTable->buckets[ind]) -> count) +=1;  	// Found matching key
				return;	
			}
		++ind;	
		}
		((myTable->buckets[ind])->count) += 1; 	// empty bucket after collision found via linear probing 
	}
}

void swapTup(struct tup* a, struct tup* b)  //Swapping NULL & Tup AND Tup & Tup causing sig fault when swap null 
{
	struct tup temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

/* Bubble sort */
void sortHash(struct hashTable* myHash)
{
	uint32_t size = myHash->size;
	for (int i = 0; i < myHash->capacity; i++) 
	{
		if(myHash->buckets[i] == NULL)
		{
			int x = i;
			while(myHash->buckets[x] == NULL)
			{
				++x;
			}
			myHash->buckets[i] = myHash->buckets[x];
			myHash->buckets[x] = (struct tup*)NULL; //	swapTup(myHash->buckets[i], myHash->buckets[x]);
			--size;
			if(!size)
			{
				return;
			}
		}	
	}

	bool swap;
	
	for (int i = 0; i < myHash->size; i++) 
	{
		swap = false;
		for (int j=0; j<myHash->size-i-1; j++) 
		{
			if(myHash->buckets[j]->count > myHash->buckets[j+1]->count)
			{
				swapTup(myHash->buckets[j], myHash->buckets[j+1]);
				swap = true;
			}
		if(swap == false)
		{
			return;
		}
		}
	}		
	return;
}
