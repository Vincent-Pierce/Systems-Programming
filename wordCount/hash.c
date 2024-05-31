/* * 
 *
 * FILE INCLUSION **********************************************************************************/

#include "hash.h"
#include <stdbool.h>
/* LOCAL DEFINITIONS ******************************************************************************/
/* newHash only used a single time when program starts to allocate the hashTable */
struct hashTable* newHash(void)
{
	struct hashTable* newTable = malloc(sizeof(struct hashTable));
	if(!newTable)
		printf("newTable malloc has failed\n");

	newTable->size = 0;
	newTable->capacity = HASHSIZ;
	newTable->bucket = calloc(HASHSIZ, sizeof(struct tup));
	if(!newTable->bucket)
		printf("new Hash-table failed");
	
	return newTable;
}
/* Once hashtable grows so that load factor is > 0.5 dynamically grow array of tups and rehash entries in hashTable */
void reHash(struct hashTable* myTable)
{
	uint32_t newCap = myTable->capacity*5;

	struct tup* newBucket = calloc(newCap, sizeof(struct tup));		// New hash-table requires every buckets key/count initialized	
	if(!newBucket)
		printf("new hashTable from reHash has failed");
	

	uint32_t oldCap = myTable->capacity;
	struct tup* oldBucket = myTable->bucket;
	myTable->capacity = newCap;								// Set newCap before rehashing each bucket for correct %
	myTable->size = 0;										// When rehashing size needs to be reset b/c hashWord will ++
	myTable->bucket = newBucket;
	for(int i = 0; i < oldCap; ++i)
	{	
		if(oldBucket[i].key)
		{
			hashWord(oldBucket[i].key, myTable);	        // Re-hash all entries of oldTable
		}
	}
	
	
	free(oldBucket);

}

void hashWord(char* key, struct hashTable* myTable)
{
    char* char_p = key;
    uint16_t ind = 0;
	if((myTable -> size) > ((myTable->capacity) >> 1)) 			// Load factor must be < 0.5
	{
		reHash(myTable);
	}
        while(*char_p != '\0') 		// Hash word into int
        {
        	ind += tolower(*char_p) - '0';
			++char_p;
		}
	ind = ind % (myTable->capacity);	// Ensure index < array size
	if(myTable->bucket[ind].key == NULL) // Insert tup into empty bucket
	{
		myTable->bucket[ind].key = key;
		myTable->bucket[ind].count++;
		myTable->size++;
	}
	else
	{
		while(1)   			// Collision handling by linear probing
		{
			if(myTable->bucket[ind].key == NULL)
			{
				myTable->bucket[ind].key=key;				// empty bucket after collision found via linear probing
				myTable->bucket[ind].count++;	
				myTable->size++;
				return;
			}
			
			if(!(strcmp(key, (myTable->bucket[ind]).key)))
			{
				((myTable->bucket[ind]).count)++;  	// Found matching key
				return;	
			}
			
			++ind;
			if(ind == myTable->capacity)
				ind = 0;
		}
	}
}


void swapTup(struct tup* a, struct tup* b)  //Swapping NULL & Tup AND Tup & Tup causing sig fault when swap null 
{
	struct tup temp;
	temp.key = a->key;
	temp.count = a->count;

	a->key=b->key;
	a->count = b->count;

	b->key = temp.key;
	b->count = temp.count;
}

/* Bubble sort */
void sortHash(struct hashTable* myHash)
{
	uint32_t size = myHash->size;
	for (int i = 0; i < myHash->capacity; i++) 			// Slide all entries in hashtable to first size elements 
	{
		if(myHash->bucket[i].key == NULL)
		{
			int x = i;
			while(myHash->bucket[x].key == NULL)
			{
				++x;
			}
			myHash->bucket[i].key = myHash->bucket[x].key;
			myHash->bucket[i].count = myHash->bucket[x].count;
			myHash->bucket[x].key = NULL;
			myHash->bucket[x].count = 0;
			--size;
			if(!size)
			{
				break;	
			}
		}	
	}	

	int i, j, max_idx;

    // One by one move boundary of unsorted subarray
    for(i = 0; i < myHash->size - 1; ++i)
	{
		max_idx = i;
		for(j = i+1; j < myHash->size; ++j)
		{
			if (myHash->bucket[max_idx].count < myHash->bucket[j].count)
			{
				max_idx = j;
			}
		}
        // Swap the found minimum element with the first element
		if(max_idx != i)
			swapTup(&(myHash->bucket[max_idx]), &(myHash->bucket[i]));
	}

	/* Now sort tie-breakers by reverse-alphabetical order */
	char* str1, *str2;
	for(i=0; i<myHash->size -1; ++i)
	{
		max_idx = i;
		str1 = myHash->bucket[i].key;
		for(j = i+1; j < myHash->size; ++j)
		{
			str2 = myHash->bucket[j].key;
			if(myHash->bucket[i].count != myHash->bucket[j].count)
				break;						// If counts don't match go next

			while(*str1 == *str2) 			// First non-matching letter
			{
				str1++;
				str2++;
			}
			if(*str1 > *str2)
			{
				max_idx = j;
				str1 = myHash->bucket[j].key;
			}
		}
		if(max_idx != i)
			swapTup(&(myHash->bucket[max_idx]), &(myHash->bucket[i]));
	}
}

