/*******************************************************************************************************************
 * Description: 
 *
 *
 * Author: Vincent Pierce
 * Date	 : May 2 2024
 *
 * ***************************************************************************************************************
 *
 * FILE INCLUDSION **********************************************************************************************/

//include <stdint.h>
//include <stdlib.h>
//#include <ctype.h>
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
				printf(stderr," Usage: %s [-o arg]\n, argv[0]");
				return -1;	// End program
			case ':':
				printf(stderr," Usage: %s [-o arg]\n, argv[0]");
				return -1;
			default:
				printf("Should not be in default\n");	
		}
	}
//	printf("k: %d optind: %d EOF: %d\n", k, optind, EOF);

	FILE* fptr;
	char letter;
	char* word;
	if(optind == argc) 	// No files input open stdin
	{
		while((letter = getchar()) != EOF)
			putchar(letter);
	}

	else 			// Open files instead
	{
		for(; optind < argc; optind++) // Opens each file given after option -n
		{
			if((fptr = fopen(argv[optind], "r")) == NULL)
			{
				printf(stderr, "Can't open file\n");
				return 1;
			}
			while((letter = fgetc(fptr)) != EOF)
			{
				putchar(letter);	
			}
			fclose(fptr);
		}
	}
	return 0;
}
/* getWord takes a file pointer and parses the next alphabetical word returning it as a Null byte terminated string */
//char* getWord(FILE* stream)
//{
//	
//}
