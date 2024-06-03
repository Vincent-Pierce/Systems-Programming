/*******************************************************************************************************************
 * Description: Function counts the number of occurences of all words in given text files
 * Then prints out top occuring words. 
 *
 *
 * Author: Vincent Pierce
 * Date	 : May 2 2024
 *
 * ***************************************************************************************************************
 *
 * FILE INCLUDSION **********************************************************************************************/
#include "fw.h"
#include "hash.h"
/* LOCAL DEFINITIONS *******************************************************************************************/

int main(int argc, char* argv[])
{
	int k = 10;
	int c;
	extern char *optarg; //optarg points to the string following option character in elements of argv 
	extern int optind; //index of argv after option arguments parsed
	while((c = getopt(argc, argv, "n:")) != -1)
	{
		switch(c)
		{
			case 'n':
				k = *optarg-'0';
				break;
			case '?':
				printf(" Usage: %s [-o arg]\n", argv[0]);
				return -1;	// End program
			case ':':
				printf(" Usage: %s [-o arg]\n", argv[0]);
				return -1;
			default:
				printf("Should not be in default\n");	
		}
	}
   
	char* word = NULL;
	struct hashTable* myTable = newHash();		// Initially empty hashTable
	
	if(optind == argc) 	// No files input open stdin
	{
		while((word = getWord(stdin)) != NULL) 
		{
			hashWord(word, myTable);
		}
	}

	else 			// Open files instead
	{
		for(; optind < argc; optind++) { // Opens each file given after option -n 
			word = NULL;			// word is still a null pointer can't assign value 
			FILE* fptr = NULL;
			if((fptr = fopen(argv[optind], "r")) == NULL)
				
			{
				printf(stderr, "Can't open file\n");
				return 1;
			}
			while((word = getWord(fptr)) != NULL) // When EOF reached set word = NULL 
			{
				hashWord(word, myTable);
			} 
			fclose(fptr);
		}
	}
	sortHash(myTable);
	printKWords(k, myTable);
	for(int i = 0; i < myTable->size;i++)
	{
		free(myTable->bucket[i].key);
	}
	free(myTable->bucket);
	free(myTable);
	return 0;
}
/* getWord takes a file pointer and parses the next alphabetical word returning it as a Null byte terminated string */
char* getWord(FILE* file)
{
	int letter = 0; 
	uint8_t buffer = 5;
        char* p_word = 0;	
	uint8_t len = 0;
	do 
	{
		letter = fgetc(file);
		if(letter == EOF)
			return NULL;	// EOF reached before new word
	} while(!isalpha(letter));
	
	p_word = calloc(buffer, sizeof(char)); // Construct string from letters
	do 
	{
		++len;
		if(len == buffer)
		{
			buffer += buffer; 
			p_word = (char*)realloc(p_word, buffer);
		}	
		
		p_word[len-1] = letter;
		letter = fgetc(file);
		if(letter == EOF)
			break;
	} while(isalpha(letter)); 	// End of word 
	p_word[len] = '\0';		// Null byte terminator of string	
	printf("Lost memory: %s      ", p_word);
	return p_word;

}

/* printKWords iterates through an array of tup* and prints out the first k words */
void printKWords(int k, struct hashTable* sortedHash)
{
	if(sortedHash->size < k)
	{
		k = sortedHash->size;
	}	
	printf("The top %i words (out of %i) are:\n", k, sortedHash->size); 
	for(int i = 0; i < k; i++)
	{
		printf("%9d %s\n",sortedHash->bucket[i].count, sortedHash->bucket[i].key);
	}

}



