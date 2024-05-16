/************************************************************************************************************ 
 * Description: 
 *
 * Word count fw header file 
 *
 *
 *
 * *********************************************************************************************************/

/* LIBRARY INCLUSIONS ****************************************************************/ 
#ifndef HEADER_FILE
#define HEADER_FILE
#include <unistd.h> 
#include <stdio.h> 
#include <ctype.h>
#include "hash.h"
/* FUNCTION PROTOTYPES ***************************************************************/

char* getWord(FILE* file);
void printKWords(int k, struct hashTable* myHash);
#endif
